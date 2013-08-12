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

//�ϰ汾, �绰��ͨ��, �ȴ���#����Ž���ϵͳѡ��¼������¼��, ѡ��֮�󲥷���ʾ��Ȼ���ٹһ�
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
#define DTMF_ENTRY_DETECT_TIME     65535  //��������ʱ����
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

//1. �밴'#'������ϵͳ.   "entry.wav"
//#define DTMF_VOC_IDX_ENTRY           1
//2. ���������벢��'#'����������.  "pwd.wav"
//#define DTMF_VOC_IDX_PWD             2
//3. ��ѡ�����: 1Ϊ����; 2Ϊ¼��; 3Ϊ¼��.  "opt.wav"
//#define DTMF_VOC_IDX_CHOOSE          3
//4. ������������, ����������!  "retry.wav"
//#define DTMF_VOC_IDX_RETRY           4
//5. ���Ĵ����������, лл����, �ټ�!   "warn.wav"
//#define DTMF_VOC_IDX_ERROR           5
//6. ���Ĳ��������ѱ�����. лл����, �ټ�!  "accept.wav"
//#define DTMF_VOC_IDX_RECV            6
//7. �����������������"#"������   "param.wav"
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
    DtmfStatus   state;         //��ǰ״̬
    DtmfCommand  command;       //ѡ��������
    MMI_BOOL     detecting;     //���ڼ�ⰴ��

	MMI_BOOL     error;    //�����־
    U8       rptMax;       //�����ظ�����
    U8       rptCount;     //���ظ�����
    
    U8       hotKey;            //�ȼ�
#if defined(__TEST_PLAY_AUDIO__)
	U8       testKey;
#endif
    U32      detectTime;       //��ⳬʱʱ��ms
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
** ����: Dtmf_Reset
** ����: ������λ
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_Reset(void);

/*******************************************************************************
** ����: Dtmf_Initialize
** ����: ��ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_Initialize(void);

/*******************************************************************************
** ����: Dtmf_AutoAnswerReqSend
** ����: ��������Ӧ���������Ϣ
** ����: name  -- �������
**       number-- ��ʾ����
** ����: ��
** ����: wasfayu
*******/
void Dtmf_AutoAnswerReqSend(WCHAR *name, char *number);


#endif/*__MSGCMD_DTMF__*/


#endif/*__MSGCMD_DTMF_H__*/

