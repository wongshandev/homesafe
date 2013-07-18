#if defined(__WS_HOME_SAFE__)
#include "ws_main.h"

homesafe_info hf_info = {0};
hf_nvram	  hf_nv = {0};



void hf_nvram_init(void)
{
	hf_read_nvram();
	if(strlen(hf_nv.admin_passwd) == 0)
	{
		strcpy(hf_nv.admin_passwd,"123456");
	}
	hf_print("hf_nvram_init,admin[%s %s %s %s %s %s ],psw[%s]",hf_nv.admin_number[0],hf_nv.admin_number[1],hf_nv.admin_number[2],
															hf_nv.admin_number[3],hf_nv.admin_number[4],hf_nv.admin_number[5],hf_nv.admin_passwd);
	hf_write_nvram();
}
void hf_start_light(void)
{
	int timer_sec = 0;
	
	if(mmi_idle_is_active()&&!mmi_bootup_is_network_service_available())
	{
		static int _count = 0;
		
		timer_sec = 1;
		//hf_print("无信号或者无卡。已经进入待机界面");
		if(!((++_count)%5))
		{
			_count = 0;
			MsgCmd_isink(FALSE);
		}
		else
		{
			MsgCmd_isink(TRUE);
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
void hf_main_init(void)
{
	hf_sms_init();
	hf_nvram_init();
	hf_start_light();
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
void hf_get_base_loc_rsp(void *info)
{
    mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;
	 
	switch (msg->em_info)
    {
        case RR_EM_LAI_INFO:
        {
            rr_em_lai_info_struct *pack_ptr;
            kal_uint16 mm_pdu_len;

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

void hf_mmi_task_process(ilm_struct *current_ilm)
{
	#define TASK_ID   		((hf_task_struct *)current_ilm->local_para_ptr)->id
	#define TASK_STRING       ((hf_task_struct *)current_ilm->local_para_ptr)->string


	switch(current_ilm->msg_id)
	{
		case HF_MSG_ID_VDO:
		{
			//录音
			U32 time  = TASK_ID;
			hf_print("task vdo :%d",time);
			
		}break;
		case HF_MSG_ID_ADO:
		{
			U16 time =TASK_ID;
			hf_print("task Ado :%d",time);

		}break;
		case HF_MSG_ID_MMS:
		{
			char * _number = TASK_STRING;
			hf_print("task mms :%s",_number);
		
		}break;
		case HF_MSG_ID_FACT:
		{
			hf_print("task factory");
		}break;
		case HF_MSG_ID_CALL:
		{
			char * _number =TASK_STRING;
			hf_print("task call out :%s",_number);
		}break;
		case HF_MSG_ID_MOS:
		{
			U16 _flag = TASK_ID;
			hf_print("task mos :%d",_flag);
			
		}break;
		case HF_MSG_ID_LANG:
		{
			U16 _flag = TASK_ID;
			hf_print("task lang :%d",_flag);
			
		}break;
		case HF_MSG_ID_TIME:
		{
			char *_time = TASK_STRING;
			hf_print("task time :%s",_time);

			
		}break;
		case HF_MSG_ID_VER:
		{
		}break;
		case HF_MSG_ID_QUIT:
		{
			hf_print("task quit ");
		}break;
		case HF_MSG_ID_LOCA:
		{
			loc_info_struct *_loc = &hf_info.hf_loc;
			hf_print("task loc ok!");
		}break;
		case HF_MSG_ID_INCOMING_CALL:
		{
			char * number = TASK_STRING;
			hf_print("task number :%s",number);
			
		}break;
		default:
		break;
	}
}
#endif
