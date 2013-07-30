/*******************************************************************************
 *
 * msgcmd_dtmf.c
 *
 * 处理DTMF
 *
 * (@_@)
 *
 * wasfayu      -- 20130718, 创建原始版本
 *
 ******************************************************************************/

#if defined(__MSGCMD_DTMF_X__)

#include "./../inc/msgcmd_dtmf.h"

#define dtmf_trace(fmt, ...)


static DtmfControl dtmfContext;

/*******************************************************************************
** 函数: Dtmf_Initialize
** 功能: 初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Initialize(void)
{
    memset(&dtmfContext, 0, sizeof(DtmfControl));
    dtmfContext.hotKey        = DTMF_HOT_KEY_VALUE;
    dtmfContext.repeateTimes  = DTMF_MAX_REPEAT_TIMES;
    dtmfContext.detectTime    = DTMF_DEF_DETECT_TIME;
}

/*******************************************************************************
** 函数: dtmf_KeyDetectTimeoutCb
** 功能: 按键检测超时回调函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_KeyDetectTimeoutCb(void)
{
    Dtmf_StopKeyDetect();
}

/*******************************************************************************
** 函数: dtmf_KeyDetectCallback
** 功能: 按键检测回调函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
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
** 函数: Dtmf_StartKeyDetect
** 功能: 开始DTMF的按键检测
** 参数: 无
** 返回: 无
** 作者: wasfayu
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
** 函数: Dtmf_StopKeyDetect
** 功能: 停止DTMF按键检测
** 参数: 无
** 返回: 无
** 作者: wasfayu
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
** 函数: dtmf_CombineVoiceFilePath
** 功能: 构建语音文件路径
** 参数: output   -- 文件绝对路径输出
**       fileindex-- 文件索引
** 返回: output的地址
** 作者: wasfayu
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
** 函数: dtmf_PlayPromptVoiceCb
** 功能: 播放提示语音的回调函数
** 参数: 播放结果
** 返回: 无
** 作者: wasfayu
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
** 函数: dtmf_PlayPromptVoice
** 功能: 播放提示语音
** 参数: 无
** 返回: 无
** 作者: wasfayu
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

