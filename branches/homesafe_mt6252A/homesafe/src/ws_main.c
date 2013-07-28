#if defined(__WS_HOME_SAFE__)
#include "ws_main.h"
#include "./../inc/Msgcmd_process.h"
#include "UcmProt.h"
#include "FileMgrType.h"
#include "mdi_include.h"
#include "FileMgrType.h"
#include "mmi_rp_app_ucm_def.h"

homesafe_info hf_info = {0};
hf_nvram	  hf_nv = {0};
hf_FuncPtr		hf_call_result_cb;
extern void PhnsetSendSetTimeReqMessage(void);
extern const unsigned char AUX_EINT_NO;
extern void MsgCmd_isink(MMI_BOOL open);
BOOL hf_make_call(char * number, hf_FuncPtr cb);
void hf_hisr_call_result(BOOL result);

void hf_nvram_init(void)
{
	hf_read_nvram();
	if(strlen(hf_nv.admin_passwd) == 0)
	{
		strcpy(hf_nv.admin_passwd,"123456");
    #if defined(__MSGCMD_SUPPORT__)
        MsgCmd_SetAdoRecdDefArgs(&hf_nv.ado);
        MsgCmd_SetVdoRecdDefArgs(&hf_nv.vdo);
    #endif	
	}
	hf_print("hf_nvram_init,admin[%s %s %s %s %s %s ],psw[%s]",hf_nv.admin_number[0],hf_nv.admin_number[1],hf_nv.admin_number[2],
	hf_nv.admin_number[3],hf_nv.admin_number[4],hf_nv.admin_number[5],hf_nv.admin_passwd);
	hf_write_nvram();
}
void hf_start_light(void)
{
	int timer_sec = 0;
	static int count = 0;

	if(++count > 20)
	{
		count = 0;
		MsgCmd_isink(FALSE);
		StopTimer(SH_LIGHT_TIMER_ID);
		return;
	}
	if(mmi_idle_is_active()&&!mmi_bootup_is_network_service_available())
	{
		static int _count = 0;
		
		timer_sec = 1;
		//hf_print("无信号或者无卡。已经进入待机界面");
		if(!((++_count)%5))
		{
			_count = 0;
			MsgCmd_isink(TRUE);
		}
		else
		{
			MsgCmd_isink(FALSE);
		}
	}
	else
	{
		static BOOL _flag = FALSE;
		
		timer_sec = 10;
		if(_flag = ~_flag)
		{
			MsgCmd_isink(TRUE);
		}
		else
		{
			MsgCmd_isink(FALSE);
		}
	}
	StartTimer(SH_LIGHT_TIMER_ID, 100*timer_sec,hf_start_light);
}

void hf_mmi_task_send(msg_type msg_id, hf_task_struct* local_param_ptr)
{
    ilm_struct* ilm = NULL;
    module_type src_mod_id;

    src_mod_id = MOD_MMI;
    ilm = allocate_ilm(src_mod_id);
    ilm->src_mod_id = src_mod_id;
    ilm->sap_id = 0;
    ilm->msg_id = (msg_type) msg_id;
    ilm->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm->peer_buff_ptr = NULL;
    ilm->dest_mod_id = MOD_MMI;

    msg_send_ext_queue(ilm);
}
void hf_set_signal_changed(kal_uint8 signal)
{
	hf_info.signal = signal;
}
kal_uint8 hf_get_signal_changed(void)
{
	return hf_info.signal;
}
void hf_juge_t_card(void)
{
	hf_print("盘符:%c",MsgCmd_GetUsableDrive());
	if('C' ==MsgCmd_GetUsableDrive())
	{
		int v;
		for(v=0;v<MAX_ADMIN_NUMBER;v++)
		{
			if(strlen(hf_nv.admin_number[v]) > MIN_PHONENUMBER_LENTH)
			{
				hf_send_sms_req(hf_nv.admin_number[v],"Waring:Device has no T-card!");
			}
			else
			continue;
		}
	}
}
MYTIME hf_time = {0};

void hf_set_time_from_fs(void)
{
	FS_HANDLE file_handle;//文件句柄
	UI_character_type path[20];
	char time_buff[120]={0};
    	U32 nLen;

    kal_wsprintf(path, "%c:\\time.txt", (S8)MsgCmd_GetUsableDrive());
	file_handle = FS_Open(path,FS_READ_ONLY);
	if (file_handle >= FS_NO_ERROR)
	{
   		kal_int32 ret;
		ret=FS_Read(file_handle,time_buff,120,&nLen);
		if(ret >=  FS_NO_ERROR)
		{
			MYTIME * p_t = &hf_time;
			hf_scanf(time_buff,strlen(time_buff),"%d-%d-%d %d:%d:%d",&p_t->nYear,&p_t->nMonth,&p_t->nDay,&p_t->nHour,&p_t->nMin,&p_t->nSec);
			if((p_t->nYear > 2012)&&(p_t->nYear < 2050)&&(p_t->nMonth > 0)&&(p_t->nMonth < 13)&&
			  (p_t->nDay > 0)&&(p_t->nDay < 32)&&(p_t->nHour < 24)&&(p_t->nHour >=0)&&
			  (p_t->nMin >=0)&&(p_t->nMin < 60)&&(p_t->nSec >=0)&&(p_t->nSec < 60))
			  {
			  	hf_print("文件设置时间成功");
				PhnsetSendSetTimeReqMessage();
			  }
			  FS_Close(file_handle);
			  FS_Delete(path);
		}
	}
	 FS_Close(file_handle);
}
void hf_entry_idle(void)
{
	hf_set_time_from_fs();
	hf_juge_t_card();
}
void hf_init_hf_info(void)
{
	hf_info.is_call_out = FALSE;
	hf_info.call_result_is_connet = FALSE;
	hf_info.call_result_time = 0;
	hf_info.call_is_complete = TRUE;
}
void hf_main_init(void)
{
	hf_sms_init();
	hf_nvram_init();
	hf_start_light();
	hf_init_hf_info();
	StartTimer(SH_IN_IDLE_TIMER_ID,1000*20,hf_entry_idle);
}
void hf_get_base_loc_rsp(void *info)
{
    mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;
	 
	switch (msg->em_info)
    {
        case RR_EM_LAI_INFO:
        {
            rr_em_lai_info_struct *pack_ptr;
            kal_uint16 mm_pdu_len;

			SetProtocolEventHandler(NULL, MSG_ID_MMI_EM_UPDATE_RSP);
			ClearProtocolEventHandler(MSG_ID_MMI_EM_STATUS_IND); 
            /* Get the msg->info where MM peer msg will be stored for transmission */
            pack_ptr = (rr_em_lai_info_struct*) get_pdu_ptr(msg->info, &mm_pdu_len);
			memcpy((void*)hf_info.hf_loc.loc.mcc, (void*)pack_ptr->mcc, 3);
			memcpy((void*)hf_info.hf_loc.loc.mnc, (void*)pack_ptr->mnc, 3);
			memcpy((void*)hf_info.hf_loc.loc.lac, (void*)pack_ptr->lac, 2);
			hf_info.hf_loc.loc.cell_id = pack_ptr->cell_id;
			(*(hf_info.hf_loc.cb))((rr_em_lai_info_struct *)& hf_info.hf_loc.loc);
            break;
        }
        default:
            break;
    }
	 free_peer_buff(msg->info);
	 return;
}
void hf_out_call_endkey(void)
{
	hf_print("拨出挂断电话");
	mmi_ucm_outgoing_call_endkey();
}

void hf_hisr_call_result(BOOL result)
{
	static BOOL is_connet = FALSE;
	if(TRUE == result)
	{
		//已经接通了。
		hf_print("接通了。。。");
		is_connet = TRUE;
	}
	else
	{
		//结束了
		if(is_connet)
		{
			hf_print("接通过。。初骀化函数");
			is_connet = FALSE;
			hf_init_hf_info();
			return;
		}
		hf_print("通话结束");
		hf_info.call_is_complete = TRUE;
	}
}
BOOL hf_make_call(char * number, hf_FuncPtr cb)
{
#define IS_IN_CALL	((GetActiveScreenId() >= SCR_ID_UCM_OUTGOING)&&\
					(GetActiveScreenId() <SCR_ID_UCM_DUMMY))
					
	char w_call_out[MAX_PHONENUMBER_LENTH*2] = {0};
	if(number == NULL) return;

	if(IS_IN_CALL)
	{
		hf_print("正在通话中,不拨打电话。");
		return;
	}
	hf_print("拨打电话%s  信号:%d",number,hf_get_signal_changed());
	MsgCmd_MakeCall(number);
	//mmi_asc_to_ucs2(w_call_out, number);
	//MakeCall(w_call_out);
	hf_call_result_cb = cb;
}
#if defined(__MSGCMD_SUPPORT__)
/*******************************************************************************
** 函数: MsgCmd_SetAdoRecdDefArgs
** 功能: 设置默认的录音参数
** 参数: obj -- 被设置的目标
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SetAdoRecdDefArgs(MsgCmdRecdArg *obj)
{
    obj->ignore_time = MSGCMD_ADO_IGNORE_TIME;
    obj->ignore_size = MSGCMD_ADO_IGNORE_SIZE;
    obj->save_gap    = MSGCMD_ADO_AUTO_SAVE_GAP;
    obj->min_time    = MSGCMD_ADO_RECD_TIME_MIN;
    obj->int_check   = MSGCMD_ADO_INT_CHECK_TIME;
}

/*******************************************************************************
** 函数: MsgCmd_SetVdoRecdDefArgs
** 功能: 设置默认的录音参数
** 参数: obj -- 被设置的目标
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SetVdoRecdDefArgs(MsgCmdRecdArg *obj)
{
    obj->ignore_time = MSGCMD_VDO_IGNORE_TIME;
    obj->ignore_size = MSGCMD_VDO_IGNORE_SIZE;
    obj->save_gap    = MSGCMD_VDO_AUTO_SAVE_GAP;
    obj->min_time    = MSGCMD_VDO_RECD_TIME_MIN;
    obj->int_check   = MSGCMD_VDO_INT_CHECK_TIME;
}

/*******************************************************************************
** 函数: MsgCmd_GetAdoRecdArgs
** 功能: 获取录音的参数地址
** 参数: 无
** 返回: 录音参数地址
** 作者: wasfayu
*******/
MsgCmdRecdArg *MsgCmd_GetAdoRecdArgs(void)
{
    return &hf_nv.ado;
}

/*******************************************************************************
** 函数: MsgCmd_GetVdoRecdArgs
** 功能: 获取录像的参数地址
** 参数: 无
** 返回: 录像参数地址
** 作者: wasfayu
*******/
MsgCmdRecdArg *MsgCmd_GetVdoRecdArgs(void)
{
    return &hf_nv.vdo;
}
void MsgCmd_AdoRecdStopTimerEx(void)
{
	hf_print("停止录音");
	hf_init_hf_info();
	if (MsgCmd_AdoRecdBusy())
		MsgCmd_AdoRecdStop(NULL);
}
#endif
void hf_enit_hisr(void)
{
	static BOOL act = FALSE;
	if(mmi_idle_is_active()&&(act == FALSE))
	{
		act = TRUE;
		hf_mmi_task_send(HF_MSG_ID_VER, NULL);
	}
}
void hf_get_base_loc_req(void)
{
	MYQUEUE Message;
	S32 i;
	mmi_em_update_req_struct *em_start_req=NULL;

	em_start_req = (mmi_em_update_req_struct *)OslConstructDataPtr(sizeof(mmi_em_update_req_struct));
	if(em_start_req == NULL)
	{
		return;
	}
	for (i=0;i<EM_INFO_REQ_NUM;i++)
	{
	  em_start_req->info_request[i] = EM_NC;
	}
	em_start_req->info_request[RR_EM_LAI_INFO]=EM_ON;
	Message.oslMsgId = MSG_ID_MMI_EM_UPDATE_REQ;
	Message.oslDataPtr = (oslParaType*) em_start_req;
	Message.oslPeerBuffPtr = NULL;
	Message.oslSrcId = MOD_MMI;
	Message.oslDestId = MOD_L4C;
	SetProtocolEventHandler(NULL, MSG_ID_MMI_EM_UPDATE_RSP);
	SetProtocolEventHandler((PsIntFuncPtr)hf_get_base_loc_rsp, MSG_ID_MMI_EM_STATUS_IND); 
	OslMsgSendExtQueue(&Message);
}
char temp_call[20]={0};
void hf_make_call_out_ex(void)
{
	hf_make_call(temp_call,hf_hisr_call_result);
}
void hf_mmi_task_process(ilm_struct *current_ilm)
{
	#define TASK_ID   		((hf_task_struct *)current_ilm->local_para_ptr)->id
	#define TASK_STRING       ((hf_task_struct *)current_ilm->local_para_ptr)->string


	switch(current_ilm->msg_id)
	{
		case HF_MSG_ID_VDO:
		{
			//录像
			U32 time  = TASK_ID;
			hf_print("task vdo :%d",time);
        #if defined(__MSGCMD_SUPPORT__)
			if (MsgCmd_VdoRecdBusy())
			{
				//replay system busy
				if (time)
                {
                    MsgCmd_VdoRecdGetContext()->forever = MMI_FALSE;
                    MsgCmd_VdoRecdGetContext()->time += time*60;
                }
                else
                    MsgCmd_VdoRecdGetContext()->forever = MMI_TRUE;
			}
			else
			{
				MsgCmd_VdoRecdStart(
                    time ? MMI_FALSE : MMI_TRUE, 
                    time*60, 
                    MsgCmd_GetVdoRecdArgs()->save_gap,
                    NULL);
			}
        #endif
		}break;
		case HF_MSG_ID_ADO:
		{
			U16 time =TASK_ID;
			hf_print("task Ado :%d",time);
			
        #if defined(__MSGCMD_SUPPORT__)
        //中断过来的time 为0xfe吧。
        	if((time == HF_HISR_IN)||(time == HF_HISR_OUT))
        	{
				//中断触发的
				if(hf_is_vaild_service()&&(FALSE==hf_admin_is_null())&&(time == HF_HISR_IN))
				{
					StopTimer(MSGCMD_TIMER_ADO_STOP);
					if((hf_info.is_call_out == FALSE)||('C' ==MsgCmd_GetUsableDrive()))
					{
						//有效的网络，拨打电话。
						int v;
						for(v=0;v<MAX_ADMIN_NUMBER;v++)
						{
							if(strlen(hf_nv.admin_number[v]) > MIN_PHONENUMBER_LENTH)
							{
								hf_info.call_is_complete = FALSE;
								hf_info.is_call_out = TRUE;
								hf_make_call(hf_nv.admin_number[v],hf_hisr_call_result);
								break;
							}
						}
					}
					else
					{
						//已经拨出去过了。
							//拨电话已经结束
						if(hf_info.call_is_complete == TRUE)
						{
							if (!MsgCmd_AdoRecdBusy())
							{
								//空闲时，可以启动。
								hf_print("开始录音。。");
								MsgCmd_AdoRecdStart(time ? MMI_FALSE : MMI_TRUE, 0, 5*60, NULL);
							}
							else
							{
								//直到第4分钟之后，检测如果没有消息过来触发，就停止录音了。
								StartTimer(MSGCMD_TIMER_ADO_STOP,1000*60*4,MsgCmd_AdoRecdStopTimerEx);
							}
						}
					}
						
				}
				else
				{
						//直到第4分钟之后，检测如果没有消息过来触发，就停止录音了。
					if(time == HF_HISR_IN)	
					{
						if (!MsgCmd_AdoRecdBusy())
						{
							//空闲时，可以启动。
							hf_print("开始录音。。");
							MsgCmd_AdoRecdStart(time ? MMI_FALSE : MMI_TRUE, 0, 5*60, NULL);
						}
					}
					else
					StartTimer(MSGCMD_TIMER_ADO_STOP,1000*60*4,MsgCmd_AdoRecdStopTimerEx);
				}
        	}
        	else
        	{
				//短信触发的
				if (!MsgCmd_AdoRecdBusy())
				{
					//空闲时，可以启动。
					hf_print("开始录音。。");
					MsgCmd_AdoRecdStart(time ? MMI_FALSE : MMI_TRUE, time, 5*60, NULL);
				}
				else if(0 != time)
				{
					//短信触发的，有非零参数进来先停止，再启动以新的参数启动。
					hf_print("有参数，再继续录...");
					MsgCmd_AdoRecdGetContext()->forever = MMI_FALSE;
                    MsgCmd_AdoRecdGetContext()->time += time*60;
				}
				else
				{
					//非空闲
					hf_print("无参数。设备正在录，继续录。。");
					MsgCmd_AdoRecdGetContext()->forever = MMI_TRUE;
				}
        	}
        #endif
		}break;
		case HF_MSG_ID_MMS:
		{
			char * _number = TASK_STRING;
			hf_print("task mms:[length=%d] \"%s\".", strlen(_number), _number);

        #if defined(__MSGCMD_SUPPORT__)
			if (strlen(_number))
				MsgCmd_CaptureEntry(_number);
			else
				MsgCmd_CaptureEntry(NULL);
        #endif
		}break;
		case HF_MSG_ID_FACT:
		{
		}break;
		case HF_MSG_ID_CALL:
		{
			char * _number =TASK_STRING;
			hf_print("task call out :%s",_number);
        #if defined(__MSGCMD_SUPPORT__)
			MsgCmd_MakeCall(_number);
        #endif
		}break;
		case HF_MSG_ID_MOS:
		{
			U16 _flag = TASK_ID;
			hf_print("task mos :%d",_flag);

        #if defined(__MSGCMD_SUPPORT__)
            MsgCmd_InterruptMask((MMI_BOOL)_flag);
        #endif
		}break;
		case HF_MSG_ID_LANG:
		{
			U16 _flag = TASK_ID;
			hf_print("task lang :%d",_flag);
			
		}break;
		case HF_MSG_ID_VER:
		{
			hf_print("中断测试");
		}break;
		case HF_MSG_ID_QUIT:
		{
			hf_print("task quit ");
        #if defined(__MSGCMD_SUPPORT__)
			if (MsgCmd_AdoRecdBusy())
				MsgCmd_AdoRecdStop(NULL);
			
			if (MsgCmd_VdoRecdBusy())
				MsgCmd_VdoRecdStop(NULL);
        #endif
		}break;
		case HF_MSG_ID_LOCA:
		{
			loc_info_struct *_loc = &hf_info.hf_loc;
			hf_print("task loc ok!");
		}break;
		case HF_MSG_ID_INCOMING_CALL:
		{
			char * number = TASK_STRING;
			srv_ucm_result_enum result;

        #if defined(__MSGCMD_SUPPORT__)
            //这里肯定是超级号码了, 停止录音和录像
            if (MsgCmd_AdoRecdBusy())
				MsgCmd_AdoRecdStop(NULL);
			
			if (MsgCmd_VdoRecdBusy())
				MsgCmd_VdoRecdStop(NULL);
        #endif
        
			//发送消息过去，直接接听来电
			result = mmi_ucm_answer_option(MMI_UCM_EXEC_IF_PERMIT_PASS);
			hf_print("task number=\"%s\", anser_result=%d.",number, result);
		}break;
		default:
		break;
	}
}
#endif
