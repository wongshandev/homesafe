#ifndef __WS_MAIN__
#define __WS_MAIN__
#include "ws_ps.h"


#define HF_STR_VER  "verson 1.1"
#define STR_CMD_SET "set" 
#define STR_CMD_CLR "clr" 
#define STR_CMD_ADO "ado" 
#define STR_CMD_VDO "vdo" 
#define STR_CMD_MMS "mms" 
#define STR_CMD_PWD "pwd" 
#define STR_CMD_FACT "fact"
#define STR_CMD_CALL "call"
#define STR_CMD_MOS "mos" 
#define STR_CMD_LANG "lang"
#define STR_CMD_TIME "time"
#define STR_CMD_VER "ver" 
#define STR_CMD_Q "q"   
#define STR_CMD_LOCA "loca"
#define STR_CMD_CLEAR "adm"

#define MAX_PHONENUMBER_LENTH          21
#define MAX_ADMIN_NUMBER			   6
#define MIN_PHONENUMBER_LENTH			4	
#define MAX_ADMIN_PSW					6

//���
typedef enum _homesafe_cmd{
 MSG_SMS_CMD_SET, 
 MSG_SMS_CMD_CLR ,
 MSG_SMS_CMD_ADO ,
 MSG_SMS_CMD_VDO ,
 MSG_SMS_CMD_MMS ,
 MSG_SMS_CMD_PWD ,
 MSG_SMS_CMD_FACT,
 MSG_SMS_CMD_CALL ,
 MSG_SMS_CMD_MOS ,
 MSG_SMS_CMD_LANG ,
 MSG_SMS_CMD_TIME,
 MSG_SMS_CMD_VER,
 MSG_SMS_CMD_Q  ,
 MSG_SMS_CMD_LOCA,

 MSG_CMD_END
}homesafe_cmd;

typedef enum _hf_task_msg_id{
/*
   [ 3] "ADO"   -- ����¼��,     ado123456=10 ���� ado123456 ��ʾ����ʱ¼��
   [ 4] "VDO"   -- ����¼��,     vdo123456=10 ���� vdo123456 ��ʾ����ʱ¼��
   [ 5] "MMS"   -- ���ղ��Բ��Żش�, mms123456=13712345678 ���� mms123456 ��ʾ�ش�����һ������������
   [ 6] "PWD"   -- ��������,     pwd123456=newpwd ��ʾ�޸�ԭʼ����123456Ϊ������"newpwd"
   [ 7] "FACT" -- �ָ���������, fact123456
   [ 8] "CALL" -- ����ָ������, call123456=13712345678 ���� call123456 ��ʾ������г�������ֱ���绰����ͨΪֹ
   [ 9] "MOS"   -- ����ϵͳ���, mos123456=0 ��ʾ�رռ��
   [10] "LANG"  -- ����DTMF����, lang123456=1 ��ʾ����DTMF����Ϊ��һ���������������û������������Ĭ��Ӣ�
   [11] "TIME"  -- ����ϵͳʱ��, time123456=20130716185100����ʾ���õ�ǰʱ��Ϊ2013-7-16��18:51:00
   [12] "VER"   -- ��ѯϵͳ����汾, ver123456
   [13] "Q"     -- �˳�¼������¼��, q123456����¼�����˳�¼������¼����˳�¼��û�о�ʲôҲ������
   [14] "LOCA"  -- ��ȡLAC/CI/RSSI/PLMN��Ϣ, loca123456

*/
 HF_MSG_ID_VDO = MSG_ID_MSGCMD_COMMAND_1,
 //HF_MSG_ID_VDO,
 HF_MSG_ID_ADO,
 HF_MSG_ID_MMS,
 HF_MSG_ID_PWD,
 HF_MSG_ID_FACT,
 HF_MSG_ID_CALL,
 HF_MSG_ID_MOS,
 HF_MSG_ID_LANG,
 HF_MSG_ID_TIME,
 HF_MSG_ID_VER,
 HF_MSG_ID_QUIT,
 HF_MSG_ID_LOCA,
 HF_MSG_ID_INCOMING_CALL,
#if defined(__MSGCMD_SUPPORT__)
    MSG_ID_MC_BASE,
    MSG_ID_MC_END = MSG_ID_MC_BASE + 10,
#endif

 HF_MSG_ID_END
}hf_task_msg_id;


typedef MMI_BOOL (*loc_cb)(rr_em_lai_info_struct *pInData);
typedef struct _loc_info_struct
{
	loc_cb		  cb;
	rr_em_lai_info_struct loc;
	
}loc_info_struct;
typedef struct _hf_task_struct{
   LOCAL_PARA_HDR
   U32   id;
   char   string[200];
}hf_task_struct;
typedef struct _homesafe_info
{
	//homesafe_cmd _cmd;
	loc_info_struct      hf_loc;

	hf_task_struct*     hf_task;

	kal_uint8 		signal;
	
}homesafe_info;

typedef struct _hf_nvram{

	char admin_number[MAX_ADMIN_NUMBER][MAX_PHONENUMBER_LENTH];
	
	char admin_passwd[MAX_ADMIN_PSW];
	
}hf_nvram;
#endif
