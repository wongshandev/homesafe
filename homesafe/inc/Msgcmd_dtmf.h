/*******************************************************************************
 *
 * msgcmd_dtmf.h
 *
 * 处理DTMF
 *
 * (@_@)
 *
 * wasfayu      -- 20130718, 创建原始版本
 *
 ******************************************************************************/

#ifndef __MSGCMD_DTMF_H__
#define __MSGCMD_DTMF_H__

#if defined(__MSGCMD_SUPPORT__)
#include "./msgcmd_process.h"
#include "GlobalConstants.h"
#include "mdi_datatype.h"
#include "ucmsrvgprot.h"


/*
 * define
 */
#define RMT_CTRL_LOGIN_CMD_TIMEOUT_TIME      30000
#define RMT_CTRL_LOGIN_PWD_TIMEOUT_TIME      30000   /* user input max interval time */
#define RMT_CTRL_PWD_INPUT_MAX_TIMES         3     /* MAX try passwd times */
#define RMT_CTRL_DETECT_TIMEOUT_TIME         30000


#define RMT_CTRL_REMOTE_PASSWD_LEN        4
#define RMT_CTRL_REMOTE_PARA_LEN          4
#define RMT_CTRL_DEFAULT_REMOTE_HOTKEY    '#'
#define RMT_CTRL_CONFIRM_HOT_KEY          '#'
#define RMT_CTRL_CALL_NUMBER_LEN          65  /* 42 */
#define RMT_CTRL_CALL_NAME_LEN            61

#define MSG_RC_PROMPT_FOLDER L"main"

//ADO-录音 VDO-录像 CAP-拍照
#define MC_VOICE_FILE_CAP_START   L"key1.wav" //语音: "指令已收到，请查收短信，再见"
#define MC_VOICE_FILE_VDO_START   L"key2.wav" //语音: "指令已收到，系统将开始录像，再见" 
#define MC_VOICE_FILE_ADO_START   L"key1.wav" //语音: "指令已收到，系统将开始录音，再见" 

#define MC_VOICE_FILE_WELCOME     L"welcome.wav" //提示: 欢迎进入系统
#define MC_VOICE_FILE_GOODBYE     L"" //提示: 指令已收到,即将启动...
#define MC_VOICE_FILE_CMD_ACK     L"" //提示: 指令已收到


/*
 * enum
 */
typedef enum
{
    MMI_RC_OFF,
    MMI_RC_ON,
    MMI_RC_NO_OF_SWITCH
} mmi_rc_switch_enum;

typedef enum
{
    MMI_RC_STATE_IDLE,              /* ---0 */
    MMI_RC_STATE_GREETING,
    MMI_RC_STATE_HINT_TIME,
    MMI_RC_STATE_RECORD,
    MMI_RC_STATE_RECORD_TIMEOUT,
    MMI_RC_STATE_RECORD_DISCFULL,   /* ---5 */

    MMI_RC_STATE_REMOTE_STOP,       /* UCM notify the call is end */
    MMI_RC_STATE_STOP_BY_ANSWER,    /* user select answer */

    MMI_RC_STATE_LOGIN_GREETING,    /* 10 */
    MMI_RC_STATE_LOGIN_DETECT_BEGIN,
    MMI_RC_STATE_LOGIN_PASSWD_RECV,
    MMI_RC_STATE_LOGIN_PASSWD_CHECK,
    MMI_RC_STATE_LOGIN_PASSWD_ERROR,

    MMI_RC_STATE_REMOTE_ENTRY,       /* 15 */

	MMI_RC_STATE_AUDIO_RECORD_PARA_BEGIN,
	MMI_RC_STATE_AUDIO_RECORD_CHECK_END,
	MMI_RC_STATE_AUDIO_RECORD_PARA_RECV,
	MMI_RC_STATE_VEDIO_RECORD,
    MMI_RC_STATE_VIDEO_RECORD_CHECK_END,
	MMI_RC_STATE_REMOTE_CHECK_COMMAND,


    MMI_RC_STATE_GOODBYE,
    MMI_RC_STATE_QUIT,

    MMI_RC_NO_OF_STATE
} mmi_rc_state_enum;


typedef struct
{
    /* for remote access */
    U8 repeat_count;
    U8 passwd_count;
    U8 remote_key;
    U8 passwd_buf[RMT_CTRL_REMOTE_PASSWD_LEN + 1];    /* the last byte is '#' */
    /* for remote play message */
    U8 reset_flag;
    U8 total_play_num;
    U8 curr_play_num;
    U8 curr_play_index;
    U8 message_num_unread;
    /* for all */
    U8 state;
    U8 volume;
    U8 message_num_all;
    U8 isMute;
    U8 number[RMT_CTRL_CALL_NUMBER_LEN];
    S32 lan_index;
	U8 cmd;
 	U8 para_count;
	U8 para_buf[RMT_CTRL_REMOTE_PARA_LEN + 1];

     srv_ucm_id_info_struct uid_info;

} mmi_remote_control_struct;

/***************************************************************************** 
 * structure 
 *****************************************************************************/
typedef struct
{
    U8 turn_on;         /* auto answer machine enable or disable, disable default. */
    U8 remote_allow;    /* allow remote access, disable default. */
    U8 drv_letter;      /* leaving message default storage. */
    U8 rec_storage;     /* greeting file browse storage */
    /* U8 message_drv;     //message file browse storage */
    U8 greeting_default;
    U8 hot_key;
    U8 pickup;
    U8 pwlength;
    U8 password[RMT_CTRL_REMOTE_PASSWD_LEN+1];
    U16 duration;
} mmi_rc_setting_struct;

typedef enum
{
    MMI_RC_CALLBACK_NONE,
    MMI_RC_CALLBACK_END    
}mmi_rc_callback_enum;


#endif/*__MSGCMD_SUPPORT__*/


#endif/*__MSGCMD_DTMF_H__*/

