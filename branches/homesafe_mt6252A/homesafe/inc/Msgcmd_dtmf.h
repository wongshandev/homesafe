/*******************************************************************************
 *
 * msgcmd_dtmf.h
 *
 * ����DTMF
 *
 * (@_@)
 *
 * wasfayu      -- 20130718, ����ԭʼ�汾
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

//1. �밴'#'������ϵͳ.   "entry.wav"
#define DTMF_VOC_IDX_ENTRY           1
//2. ���������벢��'#'����������.  "pwd.wav"
#define DTMF_VOC_IDX_PWD             2
//3. ��ѡ�����: 1Ϊ����; 2Ϊ¼��; 3Ϊ¼��.  "opt.wav"
#define DTMF_VOC_IDX_CHOOSE          3
//4. ������������, ����������!  "retry.wav"
#define DTMF_VOC_IDX_RETRY           4
//5. ���Ĵ����������, лл����, �ټ�!   "warn.wav"
#define DTMF_VOC_IDX_ERROR           5
//6. ���Ĳ��������ѱ�����. лл����, �ټ�!  "recv.wav"
#define DTMF_VOC_IDX_RECV            6
//7. �����������������"#"������   "param.wav"
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
    DtmfStatus   state;         //��ǰ״̬
    DtmfCommand  command;       //ѡ��������
    MMI_BOOL     start;
    U8       repeateTimes;      //�����ظ�����
    U8       repeateCount;      //���ظ�����
    U8       hotKey;            //�ȼ�
    U32      detectTime;       //��ⳬʱʱ��ms
    union {
        U8    password[6+1];
        U32   recordTime;
    }param;
}DtmfControl;


#endif/*__MSGCMD_DTMF__*/


#endif/*__MSGCMD_DTMF_H__*/

