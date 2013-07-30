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
#define DTMF_DEF_DETECT_TIME       15000    //s

// E:\dtmf\1.wav
#define DTMF_VOICE_MAIN_PATH       L"dtmf"

//1. 请按'#'键进入系统.   "entry.wav"
#define DTMF_VOC_IDX_ENTRY           1
//2. 请输入密码并按'#'键结束输入.  "pwd.wav"
#define DTMF_VOC_IDX_PWD             2
//3. 请选择操作: 1为拍照; 2为录音; 3为录像.  "opt.wav"
#define DTMF_VOC_IDX_CHOOSE          3
//4. 您的输入有误, 请重新输入!  "retry.wav"
#define DTMF_VOC_IDX_RETRY           4
//5. 您的错误次数过多, 谢谢来电, 再见!   "warn.wav"
#define DTMF_VOC_IDX_ERROR           5
//6. 您的操作请求已被接收. 谢谢来电, 再见!  "recv.wav"
#define DTMF_VOC_IDX_RECV            6
//7. 请输入命令参数并按"#"键结束   "param.wav"
#define DTMF_VOC_IDX_PARAM           7

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
    DtmfStatus   state;         //当前状态
    DtmfCommand  command;       //选定的命令
    MMI_BOOL     start;
    U8       repeateTimes;      //最大可重复次数
    U8       repeateCount;      //已重复次数
    U8       hotKey;            //热键
    U32      detectTime;       //检测超时时间ms
    union {
        U8    password[6+1];
        U32   recordTime;
    }param;
}DtmfControl;


#endif/*__MSGCMD_DTMF__*/


#endif/*__MSGCMD_DTMF_H__*/

