#ifndef __WS_MAIN__
#define __WS_MAIN__
#include "ws_ps.h"

//标识   __WS_HOME_SAFE__  




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

//命令集
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
   [ 3] "ADO"   -- 启动录音,     ado123456=10 或者 ado123456 表示无限时录音
   [ 4] "VDO"   -- 启动录像,     vdo123456=10 或者 vdo123456 表示无限时录像
   [ 5] "MMS"   -- 拍照并以彩信回传, mms123456=13712345678 或者 mms123456 表示回传到第一个超级号码上
   [ 6] "PWD"   -- 设置密码,     pwd123456=newpwd 表示修改原始密码123456为新密码"newpwd"
   [ 7] "FACT" -- 恢复出厂设置, fact123456
   [ 8] "CALL" -- 呼叫指定号码, call123456=13712345678 或者 call123456 表示按序呼叫超级号码直到电话被接通为止
   [ 9] "MOS"   -- 开启系统监控, mos123456=0 表示关闭监控
   [10] "LANG"  -- 设置DTMF语言, lang123456=1 表示设置DTMF语言为第一种语言索引，如果没有其他语言则默认英语。
   [11] "TIME"  -- 设置系统时间, time123456=20130716185100，表示设置当前时间为2013-7-16，18:51:00
   [12] "VER"   -- 查询系统软件版本, ver123456
   [13] "Q"     -- 退出录音或者录像, q123456，有录音就退出录音，有录像就退出录像，没有就什么也不做。
   [14] "LOCA"  -- 获取LAC/CI/RSSI/PLMN信息, loca123456

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

#if defined(__MSGCMD_SUPPORT__)
#define MSGCMD_ADO_RECD_TIME_MIN  (60*2)
#define MSGCMD_VDO_RECD_TIME_MIN  (60*2)

#define MSGCMD_ADO_AUTO_SAVE_GAP  (60*5) // 300S
#define MSGCMD_VDO_AUTO_SAVE_GAP  (60*5) // 300S

#define MSGCMD_ADO_INT_CHECK_TIME (60*4)
#define MSGCMD_VDO_INT_CHECK_TIME (60*4)

#define MSGCMD_ADO_IGNORE_TIME    (5) //时间(秒)小于该值则忽略掉
#define MSGCMD_VDO_IGNORE_TIME    (5) //时间(秒)小于该值则忽略掉

#define MSGCMD_ADO_IGNORE_SIZE    (1024*3) //小于该值(BYTE)的文件都将被删除
#define MSGCMD_VDO_IGNORE_SIZE    (1024*3) //小于该值(BYTE)的文件都将被删除

typedef struct {
//时间单位都以秒来计算
    U16    min_time;    //默认的最小值
    U16    save_gap;    //自动保存的时间间隔
    U16    int_check;   //外部中断重新检测的时间, 要小于save_gap的值
    U16    ignore_time; //小于该值则忽略掉或者设置成默认的min_time值
    U32    ignore_size; //小于该值(BYTE)的文件都将被删除
}MsgCmdRecdArg;
#endif

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
	
#if defined(__MSGCMD_SUPPORT__)
    MsgCmdRecdArg ado;
    MsgCmdRecdArg vdo;
#endif	
}hf_nvram;

#if defined(__MSGCMD_SUPPORT__)
/*******************************************************************************
** 函数: MsgCmd_SetAdoRecdDefArgs
** 功能: 设置默认的录音参数
** 参数: obj -- 被设置的目标
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SetAdoRecdDefArgs(MsgCmdRecdArg *obj);

/*******************************************************************************
** 函数: MsgCmd_SetVdoRecdDefArgs
** 功能: 设置默认的录音参数
** 参数: obj -- 被设置的目标
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SetVdoRecdDefArgs(MsgCmdRecdArg *obj);

/*******************************************************************************
** 函数: MsgCmd_GetAdoRecdArgs
** 功能: 获取录音的参数地址
** 参数: 无
** 返回: 录音参数地址
** 作者: wasfayu
*******/
MsgCmdRecdArg *MsgCmd_GetAdoRecdArgs(void);

/*******************************************************************************
** 函数: MsgCmd_GetVdoRecdArgs
** 功能: 获取录像的参数地址
** 参数: 无
** 返回: 录像参数地址
** 作者: wasfayu
*******/
MsgCmdRecdArg *MsgCmd_GetVdoRecdArgs(void);
#endif

#endif
