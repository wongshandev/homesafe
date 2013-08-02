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


#define DTMF_HOT_KEY_VALUE         '#'
#define DTMF_MAX_REPEAT_TIMES      3
#define DTMF_DEF_DETECT_TIME       15000    //ms

// E:\dtmf\1.wav
#define DTMF_VOICE_MAIN_PATH       L"dtmf_voice"

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
    DTMF_VOC_PRESS_TO_ENTRY = 1,
    DTMF_VOC_INPUT_PASSWORD = 2,
    DTMF_VOC_CHOOSE_OPTION  = 3,
    DTMF_VOC_RETRY_INPUT    = 4,
    DTMF_VOC_ERROR_TO_EXIT  = 5,
    DTMF_VOC_ACCEPT_REQUEST = 6,
    DTMF_VOC_INPUT_PARAM    = 7,
    
    DTMF_VOC_NOT_DEFINED    = 0,
}DtmfVoiceIndex;


typedef enum {
    DTMF_CMD_CAPTURE = 0,
    DTMF_CMD_ADORECD,
    DTMF_CMD_VDORECD,
    DTMF_CMD_UNDEFINED
}DtmfCommand;

typedef enum {
    DTMF_STATE_IDLE = 0,
    DTMF_STATE_WAITING_ENTRY,
    DTMF_STATE_INPUT_PWD,
    DTMF_STATE_CHOOSE_CMD,
    DTMF_STATE_INPUT_PARAM,
    DTMF_STATE_GOODBYE,
    DTMF_STATE_UNDEFINED
}DtmfStatus;

typedef struct {
    DtmfVoiceIndex index;
    WCHAR         *name;
}VoiceAttr;


typedef struct {
    WCHAR name[SRV_UCM_MAX_DISP_NAME_LEN + 1]; /* Display name */
    char  number[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
}DtmfCallInfo;



typedef struct {
    DtmfStatus   state;         //当前状态
    DtmfCommand  command;       //选定的命令
    MMI_BOOL     start;
    U8       repeateTimes;      //最大可重复次数
    U8       repeateCount;      //已重复次数
    U8       hotKey;            //热键
    U32      detectTime;       //检测超时时间ms
    DtmfCallInfo call;
    union {
        U8    password[6+1];
        U32   recordTime;
    }param;
}DtmfControl;

typedef struct {
    LOCAL_PARA_HDR
    DtmfCallInfo info;   
}DtmfAutoAnswerReq;

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

