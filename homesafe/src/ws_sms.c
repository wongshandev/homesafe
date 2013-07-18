#if defined(__WS_HOME_SAFE__)
#include "ws_sms.h"
#include "smssrvgprot.h"


extern hf_nvram	  hf_nv;
extern homesafe_info hf_info;
extern void hf_mmi_task_send(msg_type msg_id, hf_task_struct *local_param_ptr);
void hf_set_send_sms_staute(ENUM_SEND_STATUE _statue);
ENUM_SEND_STATUE hf_get_send_sms_staute(void);


void hf_send_sms_ex(void);
MMI_BOOL hf_get_loc_cb_ex(rr_em_lai_info_struct *pInData);


hf_sms_struct hf_sms = {0};   
//初始化队列
int hf_init_link_queue(void) 
{
	hf_sms_struct *p = &hf_sms; 
	memset(&p->sms_note,0,sizeof(p->sms_note));
    return TRUE;
}
static BOOL loc_prj;
void hf_sms_init(void)
{
	hf_sms_struct *p = &hf_sms; 
	
	hf_init_link_queue();
	hf_set_send_sms_staute(HF_SMS_SEND_IDLE);
	p->sms_note.send_index = -1;
}
//向队尾添加数据
int hf_sms_add_node_tail(const char *e,const char *number) 
{
	hf_sms_struct *p = &hf_sms;

	if(p->sms_note.send_index >= 9)return 0;
	p->sms_note.send_index++;
	strcpy(p->sms_note.send_content[p->sms_note.send_index],e);
	strcpy(p->sms_note.send_number[p->sms_note.send_index],number);
    return TRUE;
}
//得到队列的队头
int hf_sms_get_font_note(char *e,char *number) 
{
	hf_sms_struct *p = &hf_sms; 
	if(p->sms_note.send_index >= 10) return FALSE;
	if(p->sms_note.send_index == -1) return FALSE;
	strcpy(e,p->sms_note.send_content[0]);
	strcpy(number,p->sms_note.send_number[0]);
    return TRUE;
}
//删除队头的数据,并通过e得到删除过的数据的值
int hf_delete_font_note(void) 
{
	int i,v;
	hf_sms_struct *p = &hf_sms;
	if(p->sms_note.send_index < 0) return;

	for(i=0,v=0;i<p->sms_note.send_index;i++)
	{
		memset(p->sms_note.send_content[i],0,HF_MAX_SMS_CONTENT);
		memcpy(p->sms_note.send_content[i],p->sms_note.send_content[++v],HF_MAX_SMS_CONTENT);
		memset(p->sms_note.send_number[i],0,MAX_PHONENUMBER_LENTH);
		memcpy(p->sms_note.send_number[i],p->sms_note.send_number[v],MAX_PHONENUMBER_LENTH);
	}
	p->sms_note.send_index--;
	return TRUE;
}
//删除所有数据,
int hf_delete_all_note(void)
{
	hf_sms_struct *p = &hf_sms;
	memset(&p->sms_note,0,sizeof(p->sms_note));
	p->sms_note.send_index = -1;
}
int hf_msg_deal_cmd(char * _phone, char * _content)
{
	#define VAILD_PSW	strcmp(_psw,hf_nv.admin_passwd)	
	#define STR_LEN        strlen(_content)
	#define MAX_STR_LEN(str)     strlen(str)     

	char * _addr_set = NULL;
	char _psw[MAX_ADMIN_PSW * 10] = {0};
	BOOL _is_null = TRUE;

		
	if((_addr_set = strstr(_content,STR_CMD_SET)) != NULL)
	{
		//set number
		char _temp_number[MAX_ADMIN_NUMBER][MAX_PHONENUMBER_LENTH] = {0};
		int _count = 0;

		hf_print("set advance number.");
		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("set123456=123456789012346578901,123456789012346578901,123456789012346578901,123456789012346578901,123456789012346578901,123456789012346578901"))
		return 0xfe;
		if(hf_scanf(_content, strlen(_content), "set%s=%s,%s,%s,%s,%s,%s",
		_psw,_temp_number[0],_temp_number[1],_temp_number[2],_temp_number[3],_temp_number[4],_temp_number[5]) && (strlen(_temp_number[0])>MIN_PHONENUMBER_LENTH))
		{
			BOOL is_null = FALSE;
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			for(_count=0;_count<MAX_ADMIN_NUMBER;_count++)
			{
				if(strlen(_temp_number[_count]) > MIN_PHONENUMBER_LENTH)
				{
					int v = 0;
					for(v=0;v<MAX_ADMIN_NUMBER;v++)
					{
						if((!strcmp(hf_nv.admin_number[v],_temp_number[_count]))|| (strlen(hf_nv.admin_number[v]) == 0))
						{
							is_null = TRUE;
							strcpy(hf_nv.admin_number[v],_temp_number[_count]);
							break;
						}
					}
				}
			}
			if(TRUE==is_null)
			{
				hf_write_nvram();
				hf_send_sms_req(_phone,"Number list:%s %s %s %s %s %s",hf_nv.admin_number[0],hf_nv.admin_number[1],hf_nv.admin_number[2],
																	    hf_nv.admin_number[3],hf_nv.admin_number[4],hf_nv.admin_number[5]);
			}
			else
			{
				//已满
				hf_send_sms_req(_phone,"Set faild,admin number is full ,Pls delete some phone number!");
			}
		}
		else
		{
			hf_print("set advance number error.");
			hf_send_sms_req(_phone,"Set error!");
			return;
		}
		
	}
	if((_addr_set = strstr(_content,STR_CMD_CLR)) != NULL)
	{
		//清除管理员
		char _temp_number[MAX_ADMIN_NUMBER][MAX_PHONENUMBER_LENTH] = {0};


		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("clr123456=123456789012346578901,123456789012346578901,123456789012346578901,123456789012346578901,123456789012346578901,123456789012346578901"))
		return 0xfe;
		if(hf_scanf(_content, strlen(_content), "clr%s=%s,%s,%s,%s,%s,%s",_psw,
		_temp_number[0],_temp_number[1],_temp_number[2],_temp_number[3],_temp_number[4],_temp_number[5]))
		{
			int _count = 0;
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			for(_count=0;_count<MAX_ADMIN_NUMBER;_count++)
			{
				if(strlen(_temp_number[_count]) > MIN_PHONENUMBER_LENTH)
				{
					int v = 0;
					for(v=0;v<MAX_ADMIN_NUMBER;v++)
					{
						if(!strcmp(_temp_number[_count],hf_nv.admin_number[v]))
						{
							strcpy(hf_nv.admin_number[v],"");
							break;
						}
					}
				}
			}
			hf_write_nvram();
			hf_send_sms_req(_phone,"Clear succeed!");

		}
		else
		{
			hf_print("clear advance number error.");
			hf_send_sms_req(_phone,"Clear error!");
			return;
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_ADO)) != NULL)
	{
    		hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);


		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("ado123456=100"))
		return 0xfe;
		if(hf_scanf(_content, strlen(_content), "ado%s=%d",_psw,&p->id))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,"Video recording!");
			hf_mmi_task_send(HF_MSG_ID_ADO, p);
		}
		else
		{
			hf_print("set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_VDO)) != NULL)
	{
    		hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);

		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("vdo123456=100"))
		return 0xfe;		
		if(hf_scanf(_content, strlen(_content), "vdo%s=%d",_psw,&p->id))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,"voice recording!");
			hf_mmi_task_send(HF_MSG_ID_VDO, p);
		}
		else
		{
			hf_print("set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_MMS)) != NULL)
	{
    		hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);

    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("mms123456=123456789012346587900"))
		return 0xfe;	
		if(hf_scanf(_content, strlen(_content), "mms%s=%s",_psw,p->string))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			//hf_send_sms_req(_phone,"voice recording!");
			hf_mmi_task_send(HF_MSG_ID_MMS, p);
		}
		else
		{
			hf_print("set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_PWD)) != NULL)
	{
		char _psw_v[MAX_ADMIN_PSW*4] = {0};

    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("pwd123456=123456"))
		return 0xfe;	
		if(hf_scanf(_content, strlen(_content), "pwd%s=%s",_psw,_psw_v))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			//hf_send_sms_req(_phone,"voice recording!");
			if(strlen(_psw_v) == 6 )
			{
				//hf_mmi_task_send(HF_MSG_ID_PWD, (void *)_number);
				strcpy(hf_nv.admin_passwd,_psw_v);
				hf_write_nvram();
				hf_send_sms_req(_phone,"Set password successfully!");	
			}
			else
			{
				hf_print("set error.");
				hf_send_sms_req(_phone,"Set error!Pls retry!");				
			}
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_FACT)) != NULL)
	{
	    	_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("fact123456"))
		return 0xfe;	
		if(hf_scanf(_content, strlen(_content), "fact%s",_psw))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,"Restore factory mode successfully!");
			hf_mmi_task_send(HF_MSG_ID_FACT, NULL);
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_CALL)) != NULL)
	{
    		hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);

    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("call123456=012345678901234567891"))
		return 0xfe;	
		if(hf_scanf(_content, strlen(_content), "call%s=%s",_psw,p->string))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			//hf_send_sms_req(_phone,"Restore factory mode OK!");
			hf_mmi_task_send(HF_MSG_ID_CALL, p);
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}	
	if((_addr_set = strstr(_content,STR_CMD_MOS)) != NULL)
	{
    		hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);

    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("mos123456=01"))
		return 0xfe;	
		if(hf_scanf(_content, strlen(_content), "mos%s=%d",_psw,&p->id))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,"set monitor successfully!");
			hf_mmi_task_send(HF_MSG_ID_MOS, p);
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_LANG)) != NULL)
	{
    		hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);

    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("lang123456=12"))
		return 0xfe;	
		if(hf_scanf(_content, strlen(_content), "lang%s=%d",_psw,&p->id))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,"set language successfully!");
			hf_mmi_task_send(HF_MSG_ID_LANG, p);
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_TIME)) != NULL)
	{
    		hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);

    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("time123456=1234567890123456"))
		return 0xfe;	    		
		if(hf_scanf(_content, strlen(_content), "time%s=%s",_psw,p->string))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,"set time successfully!");
			hf_mmi_task_send(HF_MSG_ID_TIME, p);
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_VER)) != NULL)
	{
    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("ver123456=1234567890123456"))
		return 0xfe;	   
		if(hf_scanf(_content, strlen(_content), "ver%s",_psw))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,HF_STR_VER);
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_Q)) != NULL)
	{
    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("q123456"))
		return 0xfe;	   
		if(hf_scanf(_content, strlen(_content), "q%s",_psw))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_send_sms_req(_phone,"Set quit successfully!");
			hf_mmi_task_send(HF_MSG_ID_QUIT, NULL);
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_LOCA)) != NULL)
	{
    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("loca123456"))
		return 0xfe;	   	
		if(hf_scanf(_content, strlen(_content), "loca%s",_psw))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			hf_info.hf_loc.cb = hf_get_loc_cb_ex;
			hf_get_base_loc_req();
			
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if((_addr_set = strstr(_content,STR_CMD_CLEAR)) != NULL)
	{
    		_is_null = FALSE;
		if(STR_LEN > MAX_STR_LEN("loca123456"))
		return 0xfe;	   	
		if(hf_scanf(_content, strlen(_content), "adm%s",_psw))
		{
			if(VAILD_PSW)
			{
				hf_print("password  error.");
				hf_send_sms_req(_phone,"Set error,password error!");
				return;
			}
			memset(hf_nv.admin_number,0,sizeof(hf_nv.admin_number));
			memset(hf_nv.admin_passwd,0,sizeof(hf_nv.admin_passwd));
			hf_write_nvram();
			hf_send_sms_req(_phone,"All data clean");
		}
		else
		{
			hf_print("Set error.");
			hf_send_sms_req(_phone,"Set error!Pls retry!");
		}
	}
	if(_is_null)
	{
		return 0xfe;
	}
	else
	return 1;
}
 MMI_BOOL hf_get_loc_cb_ex(rr_em_lai_info_struct *pInData)
 {
	hf_print("get loc success");
	hf_mmi_task_send(HF_MSG_ID_LOCA,NULL);
 }
 BOOL hf_is_admin_number(char *_number)
{
	int _count = 0;
	for(_count = 0;_count < MAX_ADMIN_NUMBER;_count ++)
	{
		if(strlen(hf_nv.admin_number[_count]) > MIN_PHONENUMBER_LENTH)
		{
			if(NULL != strstr(_number,hf_nv.admin_number[_count]))
			{
				hf_print("is admin number!");
				return TRUE;
			}
		}
	}
	return FALSE;
}
BOOL hf_admin_is_null(void)
{
	int _count = 0;
	for(_count = 0;_count < MAX_ADMIN_NUMBER;_count ++)
	{
		if(strlen(hf_nv.admin_number[_count])>MIN_PHONENUMBER_LENTH)
		{
			return FALSE;
		}
	}
	return TRUE;
}

BOOL hf_new_call_ind(char * number)
{
    	hf_task_struct * p = (hf_task_struct*) construct_local_para(sizeof(hf_task_struct), TD_CTRL);

	if(number == NULL) return FALSE;;
	if(FALSE==hf_is_admin_number(number))
	{
		hf_print("isn't admin ,not allow!");
		return FALSE;
	}
	strcpy(p->string,number);
	hf_print("new call ind:%s",number);
	hf_mmi_task_send(HF_MSG_ID_INCOMING_CALL, p);
	return TRUE;
}
/*New messege incoming*/
void hf_new_msg_ind(char * rev_num,char * rev_content)
{
	char * low_msg_content = NULL;
	char * msg_num      = rev_num;
	char * addr = NULL;
	
	hf_print("New msg[phone:%s content:%s]",rev_num,rev_content);
	if((rev_num == NULL)||(rev_content == NULL))
	{
		hf_print("Msg is Vaild! return.");
		return;
	}
	low_msg_content = str_big_to_low(rev_content);
	if((FALSE == hf_admin_is_null()&&((addr=strstr(rev_content,STR_CMD_SET))!=NULL))||(hf_is_admin_number(rev_num)))
	{
		if(0xfe==hf_msg_deal_cmd(msg_num,low_msg_content))
		{
			hf_send_sms_req(rev_num,"Command wrong,Pls retry!");
		}
	}
	else
	{
		
		hf_print("number is not allow,admin[%s %s %s %s %s %s ]",hf_nv.admin_number[0],hf_nv.admin_number[1],hf_nv.admin_number[2],
															hf_nv.admin_number[3],hf_nv.admin_number[4],hf_nv.admin_number[5]);
	}

}
//void hf_DeleteAllSmsCB(srv_sms_callback_struct *cb){}
void hf_DeleteAllSms(void)
{
	srv_sms_delete_msg_list(
	SRV_SMS_BOX_INBOX|SRV_SMS_BOX_OUTBOX|SRV_SMS_BOX_DRAFTS|SRV_SMS_BOX_UNSENT|SRV_SMS_BOX_SIM,
	SRV_SMS_SIM_1,
	NULL,
	NULL);
}
void hf_set_send_sms_staute(ENUM_SEND_STATUE _statue)
{
	hf_sms.sms_send_statue = _statue;
}
ENUM_SEND_STATUE hf_get_send_sms_staute(void)
{
	return hf_sms.sms_send_statue;
}
void SendSmsResult(srv_sms_callback_struct *cb)
{	
	static int send_count = 0;
	char content[400] = {0};
	char number[20] = {0};

	if(cb->result == MMI_TRUE)
	{
		int ret;
		hf_DeleteAllSms();
		hf_set_send_sms_staute(HF_SMS_SEND_IDLE);
		ret = hf_delete_font_note();
		hf_print("send message success congratulation........delete quque result");
	}
#if !defined(WIN32)	
	else
	{	
		if(++send_count > 5)
		{//连续5次没发出去。删除全部。
			send_count = 0;
			hf_delete_all_note();
		}
		hf_set_send_sms_staute(HF_SMS_SEND_IDLE);
		hf_print("send faild!!!!");
	}
#endif	
	#if defined(WIN32)
	 hf_DeleteAllSms();
	 hf_delete_font_note();
	 hf_send_sms_ex();//重新发送
	#else
	  hf_send_sms_ex();//重新发送
	#endif
}
void hf_srv_sms_send_text_message(
        S8 *ucs2_content,
        S8 *ucs2_number,
        srv_sms_sim_enum sim_id)
{	

	srv_sms_send_ucs2_text_msg(
			(S8*)ucs2_content,
			(S8*)ucs2_number,
			sim_id,
			SendSmsResult,
			NULL);
}
void win_debug_result(void)
{
	hf_set_send_sms_staute(HF_SMS_SEND_IDLE);
	 hf_DeleteAllSms();
	 hf_delete_font_note();
	 hf_send_sms_ex();//重新发送
}
void hf_send_sms_ex(void)
{
	char u_number[40] = {0};
	kal_uint8 u_SendBuff[600] = {0};
	char szContent[500] = {0};
	char szNumber[20] = {0};

	if((TRUE==hf_sms_get_font_note(szContent,szNumber))&&(HF_SMS_SENDING != hf_get_send_sms_staute()))
	{
		if(strlen(szContent)>HF_MAX_SMS_CONTENT)return;
		if(strlen(szNumber)>MAX_PHONENUMBER_LENTH)return;
		hf_print("send sms:[%s->%s] signal[%s]",szNumber,szContent,hf_get_signal_changed());
		mmi_chset_convert(MMI_CHSET_GB2312,MMI_CHSET_UCS2,(char *)szContent,(char *)u_SendBuff,sizeof(szContent));
		mmi_asc_to_ucs2((char *)u_number, (char *)szNumber);
		hf_set_send_sms_staute(HF_SMS_SENDING);
		#if defined(WIN32)
		StartTimer(SH_LIGHT_TIMER_ID, 1000*3, (FuncPtr)win_debug_result);
		#endif
		hf_srv_sms_send_text_message(
		    (char*)u_SendBuff,
		    (char*)u_number,
		    SRV_SMS_SIM_1);
	}

}
void hf_send_sms_req(const char * _number, const char* content)
{
	if (!mmi_bootup_is_network_service_available())
	{
		hf_print("No simcard,don't send sms!");
		return;
	}
	if(strlen(_number) > 0 && NULL != content)
	{
		if(TRUE==hf_sms_add_node_tail(content,_number))
		{
			hf_send_sms_ex();
		}
	}
}
#endif

