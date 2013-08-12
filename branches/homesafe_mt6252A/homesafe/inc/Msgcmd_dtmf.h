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

#if defined(__MSGCMD_DTMF__)
#include "./msgcmd_process.h"
#include "GlobalConstants.h"
#include "mdi_datatype.h"
#include "ucmsrvgprot.h"

//老版本, 电话接通后, 等待按#键后才进入系统选择录音或者录像, 选择之后播放提示语然后再挂机
#ifndef __MSGCMD_DTMF_OLD_VERSION__
#define __MSGCMD_DTMF_OLD_VERSION__
#endif

//macro
#ifndef __MSGCMD_DTMF_OLD_VERSION__
#define __NEED_CHECK_PASSWORD__
#define __RECIVE_CMD_PARAMETER__
#endif
#define __EXEC_IN_TIMER_CBF__
//#define __TEST_PLAY_AUDIO__

#define DTMF_HOT_KEY_VALUE         '#'
#if defined(__TEST_PLAY_AUDIO__)
#define DTMF_TEST_KEY_VALUE        '*'
#endif
#define DTMF_PWD_STR_LENGTH        6
#define DTMF_DEFAULT_PASSWORD      "123456"
#define DTMF_PARAM_STR_LENGTH      6
#define DTMF_MAX_REPEAT_TIMES      3
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
#define DTMF_ENTRY_DETECT_TIME     65535  //进入无限时接听
#define DTMF_DEF_DETECT_TIME       20000    //ms
#else
#define DTMF_ENTRY_DETECT_TIME     10000
#define DTMF_DEF_DETECT_TIME       15000    //ms
#endif

// E:\dtmf\1.wav
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
#define DTMF_VOICE_MAIN_PATH       L"main"
#else
#define DTMF_VOICE_MAIN_PATH       L"dtmf_voice"
#endif

//1. 请按'#'键进入系统.   "entry.wav"
//#define DTMF_VOC_IDX_ENTRY           1
//2. 请输入密码并按'#'键结束输入.  "pwd.wav"
//#define DTMF_VOC_IDX_PWD             2
//3. 请选择操作: 1为拍照; 2为录音; 3为录像.  "opt.wav"
//#define DTMF_VOC_IDX_CHOOSE          3
//4. 您的输入有误, 请重新输入!  "retry.wav"
//#define DTMF_VOC_IDX_RETRY           4
//5. 您的错误次数过多, 谢谢来电, 再见!   "warn.wav"
//#define DTMF_VOC_IDX_ERROR           5
//6. 您的操作请求已被接收. 谢谢来电, 再见!  "accept.wav"
//#define DTMF_VOC_IDX_RECV            6
//7. 请输入命令参数并按"#"键结束   "param.wav"
//#define DTMF_VOC_IDX_PARAM           7
typedef enum {
    DTMF_VOC_NO_VOICE       = 0,
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
	DTMF_VOC_CHOOSE_OPTION  = 1,
	DTMF_VOC_ACCEPT_CAPTURE = 2,
	DTMF_VOC_ACCEPT_ADORECD = 3,
	DTMF_VOC_ACCEPT_VDORECD = 4,
	DTMF_VOC_COMMAND_ERROR  = 5,
#else
    DTMF_VOC_PRESS_TO_ENTRY = 1,
    DTMF_VOC_INPUT_PASSWORD = 2,
    DTMF_VOC_CHOOSE_OPTION  = 3,
    DTMF_VOC_RETRY_INPUT    = 4,
    DTMF_VOC_ERROR_TO_EXIT  = 5,
    DTMF_VOC_ACCEPT_REQUEST = 6,
    DTMF_VOC_INPUT_PARAM    = 7,
    DTMF_VOC_RETRY_PASSWORD = 8,
    DTMF_VOC_RETRY_OPTIOIN  = 9,
    DTMF_VOC_RETRY_PARAM    = 10,
#endif

    DTMF_VOC_NOT_DEFINED    = 0,
}DtmfVoiceIndex;


typedef enum {
	DTMF_CMD_NONE    = 0,
    DTMF_CMD_CAPTURE,
    DTMF_CMD_ADORECD,
    DTMF_CMD_VDORECD,
    DTMF_CMD_UNDEFINED
}DtmfCommand;

typedef enum {
    DTMF_STATE_IDLE = 0,
    DTMF_STATE_WAITING_ENTRY,
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
	DTMF_STATE_CHOOSE_OPTION,
	DTMF_STATE_ACCPET_PROMPT,
#else
    DTMF_STATE_INPUT_PWD,
    DTMF_STATE_CHOOSE_OPTION,
    DTMF_STATE_INPUT_PARAM,
#endif
    DTMF_STATE_GOODBYE,
    DTMF_STATE_MAX_ENUM
}DtmfStatus;

typedef struct {
    DtmfVoiceIndex index;
    CHAR          *name;
}VoiceAttr;


typedef struct {
    WCHAR name[SRV_UCM_MAX_DISP_NAME_LEN + 1]; /* Display name */
    char  number[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
}DtmfCallInfo;



typedef struct {
    DtmfStatus   state;         //当前状态
    DtmfCommand  command;       //选定的命令
    MMI_BOOL     detecting;     //正在检测按键

	MMI_BOOL     error;    //错误标志
    U8       rptMax;       //最大可重复次数
    U8       rptCount;     //已重复次数
    
    U8       hotKey;            //热键
#if defined(__TEST_PLAY_AUDIO__)
	U8       testKey;
#endif
    U32      detectTime;       //检测超时时间ms
    DtmfCallInfo call;
    union {
        U8    password[DTMF_PWD_STR_LENGTH + 2];
        #define PWD_IDX_VAL (DTMF_PWD_STR_LENGTH+1)
        
        U8    recordTime[DTMF_PARAM_STR_LENGTH + 2];
        #define PARAM_IDX_VAL (DTMF_PARAM_STR_LENGTH+1)
    }param;
}DtmfControl;

typedef struct {
    LOCAL_PARA_HDR
    DtmfCallInfo info;   
}DtmfAutoAnswerReq;

typedef struct {
    LOCAL_PARA_HDR
    DtmfCommand  command;
    char         number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    void        *param;
}DtmfCmdExecReq;


/*******************************************************************************
** 函数: Dtmf_Reset
** 功能: 参数复位
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Reset(void);

/*******************************************************************************
** 函数: Dtmf_Initialize
** 功能: 初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Initialize(void);

/*******************************************************************************
** 函数: Dtmf_AutoAnswerReqSend
** 功能: 发送请求应答来电的消息
** 参数: name  -- 来电号码
**       number-- 显示名字
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_AutoAnswerReqSend(WCHAR *name, char *number);


#endif/*__MSGCMD_DTMF__*/


#endif/*__MSGCMD_DTMF_H__*/

