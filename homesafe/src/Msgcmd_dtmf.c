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

#if defined(__MSGCMD_DTMF__)

#include "./../inc/msgcmd_dtmf.h"

#define dtmf_trace(fmt, ...) hf_print(fmt, ##__VA_ARGS__)

static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index);
static mdi_result dtmf_PlayPromptVoiceFile(DtmfVoiceIndex idx, void (*cbf)(mdi_result));
static void dtmf_AutoAnswerResponse(void *p);

static DtmfControl dtmfContext;

const static VoiceAttr voiceTab[] = {
    {DTMF_VOC_NO_VOICE       , L""},
    {DTMF_VOC_PRESS_TO_ENTRY , L"1Entry"},
    {DTMF_VOC_INPUT_PASSWORD , L"2Password"},
    {DTMF_VOC_CHOOSE_OPTION  , L"3Option"},
    {DTMF_VOC_RETRY_INPUT    , L"4Retry"},
    {DTMF_VOC_ERROR_TO_EXIT  , L"5Warn"},
    {DTMF_VOC_ACCEPT_REQUEST , L"6Accept"},
    {DTMF_VOC_INPUT_PARAM    , L"7Param"},
};

/*******************************************************************************
** 函数: Dtmf_Reset
** 功能: 参数复位
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Reset(void)
{
    memset(&dtmfContext, 0, sizeof(DtmfControl));
    dtmfContext.hotKey        = DTMF_HOT_KEY_VALUE;
    dtmfContext.repeateTimes  = DTMF_MAX_REPEAT_TIMES;
    dtmfContext.detectTime    = DTMF_DEF_DETECT_TIME;
}

/*******************************************************************************
** 函数: Dtmf_Initialize
** 功能: 初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Initialize(void)
{
    Dtmf_Reset();
    mmi_frm_set_protocol_event_handler(
        MSG_ID_DTMF_ANSWER_CALL,
        (PsIntFuncPtr)dtmf_AutoAnswerResponse,
        MMI_FALSE);
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
    dtmf_StopKeyDetect();
}

/*******************************************************************************
** 函数: dtmf_SwitchFSMStatus
** 功能: 切换状态机的状态
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_SwitchFSMStatus(DtmfStatus ns)
{
    switch (dtmfContext.state)
    {
    case DTMF_STATE_IDLE:
        break;
    case DTMF_STATE_WAITING_ENTRY:
        break;
    case DTMF_STATE_INPUT_PWD:
        break;
    case DTMF_STATE_CHOOSE_CMD:
        break;
    case DTMF_STATE_INPUT_PARAM:
        break;
    case DTMF_STATE_GOODBYE:
        break;
    case DTMF_STATE_UNDEFINED:
    default:
        break;
    }
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
	dtmf_trace("%s: key=0x%x, state=%d.\n", __FUCNTION__, key, dtmfContext.state);

    switch (dtmfContext.state)
    {
    case DTMF_STATE_IDLE:
        break;
    case DTMF_STATE_WAITING_ENTRY:
        if (dtmfContext.hotKey == (U8)key)
        {
            //输入密码状态
        }
        else
        {
            //按键错误, 重新检测
            dtmfContext.repeateCount ++;
        }
        break;
    default:
        break;
    }
}

/*******************************************************************************
** 函数: dtmf_StartKeyDetect
** 功能: 开始DTMF的按键检测
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_StartKeyDetect(U32 timeout)
{
    dtmf_trace("%s, L:%d.", __FUNCTION__, __LINE__);
    if (MDI_AUDIO_SUCCESS == mdi_audio_start_keytone_detect(dtmf_KeyDetectCallback))
    {
        dtmf_trace("%s, L:%d.", __FUNCTION__, __LINE__);
        StartTimer(TIMER_DTMF_KEY_DETECT, timeout, dtmf_KeyDetectTimeoutCb);
        dtmfContext.start = MMI_TRUE;
    }
}

/*******************************************************************************
** 函数: dtmf_StopKeyDetect
** 功能: 停止DTMF按键检测
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_StopKeyDetect(void)
{
    StopTimer(TIMER_DTMF_KEY_DETECT);
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
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index)
{
    ASSERT(NULL != output);

    kal_wsprintf(output, "%c:\\%w\\%w.wav",
        MsgCmd_GetUsableDrive(),DTMF_VOICE_MAIN_PATH,voiceTab[index].name);
    
    return output;    
}

/*******************************************************************************
** 函数: dtmf_PlayPromptVoiceCb
** 功能: 播放提示语音的回调函数
** 参数: 播放结果
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_PlayPromptVoiceCb(mdi_result result)
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
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_PRESS_TO_ENTRY);
        break;
    case DTMF_STATE_INPUT_PWD:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_INPUT_PASSWORD);
        break;
    case DTMF_STATE_CHOOSE_CMD:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_CHOOSE_OPTION);
        break;
    case DTMF_STATE_INPUT_PARAM:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_INPUT_PARAM);
        break;
    case DTMF_STATE_GOODBYE:
        dtmf_CombineVoiceFilePath(filepath, DTMF_VOC_ACCEPT_REQUEST);
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
                    dtmf_PlayPromptVoiceCb,
                    6,
                    MDI_DEVICE_SPEAKER2);    
    }
    
    return result;
}

static void dtmf_AutoAnswerPlayVoiceCb(mdi_result result)
{
    dtmf_trace("%s, L:%d, ret=%d. state=%d.", __FUNCTION__, __LINE__, result, dtmfContext.state);

    //如果当前状态为xx状态则返回
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        mmi_autoam_record_state_switch(MMI_AUTOAM_STATE_HINT_TIME);
    }
    else
    {
        /* Play file failed, and try to play string */
        mmi_autoam_play_prompt();
    }
}

/*******************************************************************************
** 函数: dtmf_PlayPromptVoiceFile
** 功能: 播放提示语
** 参数: idx  -- 语音资源索引
**       cbf  -- 回调函数
** 返回: 无
** 作者: wasfayu
*******/
static mdi_result dtmf_PlayPromptVoiceFile(DtmfVoiceIndex idx, void (*cbf)(mdi_result))
{
    WCHAR filepath[MSGCMD_FILE_PATH_LENGTH+1];
    mdi_result result;

    /* end bg sound */
    mdi_audio_snd_stop();
    
    memset(filepath, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
    dtmf_CombineVoiceFilePath(filepath, idx);
    result = mdi_audio_snd_check_file_format(filepath);

    dtmf_trace("%s, 1, index=%d. ret=%d.", __FUNCTION__, idx, result);

    if (result == MDI_AUDIO_SUCCESS)
    {
        result = mdi_audio_snd_play_file_with_vol_path(
                (void*)filepath,
                1,
                NULL,
                cbf,
                6,
                MDI_DEVICE_SPEAKER2);
        
        dtmf_trace("%s, 2, ret=%d.", __FUNCTION__, result);
    }

    return result;
}

/*******************************************************************************
** 函数: dtmf_AutoAnswerResponse
** 功能: 请求应答来电的消息响应函数
** 参数: p  -- DtmfAutoAnswerReq
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_AutoAnswerResponse(void *p)
{
    DtmfAutoAnswerReq *rsp = (DtmfAutoAnswerReq*)p;
    mdi_result result;

    dtmf_trace("%s", __FUNCTION__);
    
    //播放提示语 1 press # to entry system
    result = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, dtmf_AutoAnswerPlayVoiceCb);

    //行不行都进入到下一个模式即按键检测模式
    dtmf_StartKeyDetect(dtmfContext.detectTime);
}

/*******************************************************************************
** 函数: Dtmf_AutoAnswerReqSend
** 功能: 发送请求应答来电的消息
** 参数: name  -- 来电号码
**       number-- 显示名字
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_AutoAnswerReqSend(WCHAR *name, char *number)
{
    DtmfAutoAnswerReq *req = (DtmfAutoAnswerReq*)\
            MsgCmd_ConstructPara(sizeof(DtmfAutoAnswerReq));

    app_ucs2_strcpy((S8*)req->info.name, (const S8*)name);
    strcpy(req->info.number, number);
    
    dtmf_trace("%s, number=%s.", __FUNCTION__, number);
        
    MsgCmd_SendIlm2Mmi(MSG_ID_DTMF_ANSWER_CALL, (void*)req);
}

#endif/*__MSGCMD_DTMF__*/

