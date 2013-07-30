/*******************************************************************************
 *
 * msgcmd_dtmf.c
 *
 * ����DTMF
 *
 * (@_@)
 *
 * wasfayu      -- 20130718, ����ԭʼ�汾
 *
 ******************************************************************************/

#if defined(__MSGCMD_DTMF_X__)

#include "./../inc/msgcmd_dtmf.h"

#define dtmf_trace(fmt, ...)


static DtmfControl dtmfContext;

/*******************************************************************************
** ����: Dtmf_Initialize
** ����: ��ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_Initialize(void)
{
    memset(&dtmfContext, 0, sizeof(DtmfControl));
    dtmfContext.hotKey        = DTMF_HOT_KEY_VALUE;
    dtmfContext.repeateTimes  = DTMF_MAX_REPEAT_TIMES;
    dtmfContext.detectTime    = DTMF_DEF_DETECT_TIME;
}

/*******************************************************************************
** ����: dtmf_KeyDetectTimeoutCb
** ����: ������ⳬʱ�ص�����
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_KeyDetectTimeoutCb(void)
{
    Dtmf_StopKeyDetect();
}

/*******************************************************************************
** ����: dtmf_KeyDetectCallback
** ����: �������ص�����
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_KeyDetectCallback(S16 key)
{
	dtmf_trace("%s: key=0x%x, state=%d.\n", __FUCNTION__, key, g_rc_context.state);

    switch (g_rc_context.state)
    {
    default:
        break;
    }
}

/*******************************************************************************
** ����: Dtmf_StartKeyDetect
** ����: ��ʼDTMF�İ������
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_StartKeyDetect(U32 timeout)
{
    if (MDI_AUDIO_SUCCESS == mdi_audio_start_keytone_detect(dtmf_KeyDetectCallback))
    {
        StartTimer(DTMF_TIMER_START_DETECT, timeout, dtmf_KeyDetectTimeoutCb);
        dtmfContext.start = MMI_TRUE;
    }
}

/*******************************************************************************
** ����: Dtmf_StopKeyDetect
** ����: ֹͣDTMF�������
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_StopKeyDetect(void)
{
    StopTimer(DTMF_TIMER_START_DETECT);
    if (dtmfContext.start)
    {
        mdi_audio_stop_keytone_detect();
        dtmfContext.start = MMI_FALSE;
    }
}

/*******************************************************************************
** ����: dtmf_CombineVoiceFilePath
** ����: ���������ļ�·��
** ����: output   -- �ļ�����·�����
**       fileindex-- �ļ�����
** ����: output�ĵ�ַ
** ����: wasfayu
*******/
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, U8 fileindex)
{
    ASSERT(NULL != output);

    kal_wsprintf(
        output, 
        "%c:\\%w\\%d.wav",
        MsgCmd_GetUsableDrive(),
        DTMF_VOICE_MAIN_PATH,
        fileindex);
    
    return output;    
}

/*******************************************************************************
** ����: dtmf_PlayPromptVoiceCb
** ����: ������ʾ�����Ļص�����
** ����: ���Ž��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PlayPromptrVoiceCb(mdi_result result)
{
    dtmf_trace("%s, result=%d.", __FUNCTION__, result);
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        //mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_HINT_TIME);
    }
    else
    {
        /* Play file failed, and try to play string */
        //mmi_autoam_play_prompt();
    }
}

/*******************************************************************************
** ����: dtmf_PlayPromptVoice
** ����: ������ʾ����
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static S32 dtmf_PlayPromptVoice(void)
{
    mdi_result result;
    WCHAR filepath[MSGCMD_FILE_PATH_LENGTH+1];


    memset(filepath, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
    
	switch(dtmfContext.state)
	{
    case DTMF_STATE_IDLE:
        break;
    case DTMF_STATE_WAITING_ENTRY:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_IDX_ENTRY);
        break;
    case DTMF_STATE_INPUT_PWD:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_IDX_PWD);
        break;
    case DTMF_STATE_CHOOSE_CMD:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_IDX_CHOOSE);
        break;
    case DTMF_STATE_INPUT_PARAM:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_IDX_PARAM);
        break;
    case DTMF_STATE_GOODBYE:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_IDX_RECV);
        break;
        
    case DTMF_STATE_UNDEFINED:
        break;

    default:
        ASSERT(0);
        break;
	}

    /* play file */    
    result = mdi_audio_snd_check_file_format((void*)filepath);
    if (MDI_AUDIO_SUCCESS == result)
    {
        result = mdi_audio_snd_play_file_with_vol_path(
                    (void*)filepath,
                    1,
                    NULL,
                    dtmf_PlayPromptrVoiceCb,
                    6,
                    MDI_DEVICE_SPEAKER2);    
    }
    
    return result;
}

#endif/*__MSGCMD_DTMF__*/

