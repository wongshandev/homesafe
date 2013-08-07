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

#if defined(__MSGCMD_DTMF__)

#include "./../inc/msgcmd_dtmf.h"
#include "ucmsrvgprot.h"

/*
 * ��������ʾ���������֮����ܿ����������, �������ɰ�������
 * ����Զ�����ʾ������ʧ��, ��Ҫ����ϵͳ����ʾ��
 * �����ʾ������ʧ��, ��ֱ�ӽ��밴�����
 */

#define dtmf_trace hf_print
#define __NEED_CHECK_PASSWORD__
#define __RECIVE_CMD_PARAMETER__

extern U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen);
static void dtmf_CmdExecRsp(void *p);
static void dtmf_PostCmdExecReq(DtmfCommand cmd, char *number, void *param);
static void dtmf_ReleaseAllActivedCall(MMI_BOOL exec);
static void dtmf_KeyDetectTimeoutCb(void);
static void dtmf_SwitchFSMStatus(void);
static void dtmf_KeyDetectCallback(S16 key);
static void dtmf_StartKeyDetect(U32 timeout);
static void dtmf_StopKeyDetect(void);
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index);
static void dtmf_PlayCustomPromptVoiceFileCb(mdi_result result, void *usd);
static void dtmf_PlaySystemPromptVoiceFileCb(mdi_result result, void *usd);
static MMI_ID_TYPE dtmf_GetSystemVoiceFileId(DtmfVoiceIndex idx);
static MMI_BOOL dtmf_PlayCustomVoiceFile(DtmfVoiceIndex idx, void *usd);
static MMI_BOOL dtmf_PlaySystemVoiceFile(DtmfVoiceIndex idx, void *usd);
static MMI_BOOL dtmf_PlayPromptVoiceFile(DtmfVoiceIndex idx, void *usd);
static void dtmf_AutoAnswerResponse(void *p);

static DtmfControl dtmfCnxt;

const static VoiceAttr voiceTab[] = {
    {DTMF_VOC_NO_VOICE       , "Silence.wav"},
    {DTMF_VOC_PRESS_TO_ENTRY , "Welcome.wav"},
    {DTMF_VOC_INPUT_PASSWORD , "EnterPwd.wav"},
    {DTMF_VOC_CHOOSE_OPTION  , "ChooseOpt.wav"},
    {DTMF_VOC_RETRY_INPUT    , "Retry.wav"},
    {DTMF_VOC_ERROR_TO_EXIT  , "Error.wav"},
    {DTMF_VOC_ACCEPT_REQUEST , "Accept.wav"},
    {DTMF_VOC_INPUT_PARAM    , "EnterParam.wav"},
    {DTMF_VOC_RETRY_PASSWORD , "RetryPwd.wav"},
    {DTMF_VOC_RETRY_OPTIOIN  , "RetryOpt.wav"},
};

/*******************************************************************************
** ����: Dtmf_Reset
** ����: ������λ
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_Reset(void)
{
    memset(&dtmfCnxt, 0, sizeof(DtmfControl));
    dtmfCnxt.hotKey     = DTMF_HOT_KEY_VALUE;
    dtmfCnxt.rptMax     = DTMF_MAX_REPEAT_TIMES;
    dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
}

/*******************************************************************************
** ����: Dtmf_Initialize
** ����: ��ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_Initialize(void)
{
    Dtmf_Reset();
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_DTMF_ANSWER_CALL,
        (PsIntFuncPtr)dtmf_AutoAnswerResponse,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_DTMF_EXEC_CMD_REQ,
        (PsIntFuncPtr)dtmf_CmdExecRsp,
        MMI_FALSE);
}

/*******************************************************************************
** ����: dtmf_CmdExecRsp
** ����: ִ������
** ����: p -- DtmfCmdExecReq
** ����: ��
** ����: wasfayu
*******/
static void dtmf_CmdExecRsp(void *p)
{
    DtmfCmdExecReq *rsp = (DtmfCmdExecReq*)p;

    switch(rsp->command)
    {
    case DTMF_CMD_CAPTURE:
        dtmf_trace("%s, CAPTURE.", __FUNCTION__);
        MsgCmd_CaptureEntry(rsp->number);
        break;
        
    case DTMF_CMD_ADORECD:
        dtmf_trace("%s, AUDIO RECORD.", __FUNCTION__);
        break;
        
    case DTMF_CMD_VDORECD:
        dtmf_trace("%s, VIDEO RECORD.", __FUNCTION__);
        {
            MsgCmdRecdArg *vsp = msgcmd_GetVdoRecdArgs();
            
            if (NULL == rsp->param || (U32)rsp->param == 0)
                MsgCmd_VdoRecdStart(MMI_TRUE, 0, vsp->save_gap, rsp->number);
            else
                MsgCmd_VdoRecdStart(
                    MMI_FALSE,
                    (U32)rsp->param < vsp->min_time ? vsp->min_time : (U32)rsp->param,
                    vsp->save_gap,
                    rsp->number);
        }
        break;
        
    default:
        break;
    }
}

/*******************************************************************************
** ����: dtmf_PostCmdExecReq
** ����: ��������ִ������
** ����: cmd    -- Ԥִ�е�����
**       number -- �ظ���Ϣ�ĺ���
**       param  -- �������
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PostCmdExecReq(DtmfCommand cmd, char *number, void *param)
{
    DtmfCmdExecReq *req = (DtmfCmdExecReq *)MsgCmd_ConstructPara(sizeof(DtmfCmdExecReq));

    req->command = cmd;
    req->param   = param;
    if (NULL != number)
    {
        strcpy(req->number, number);
    }

    dtmf_trace("%s, cmd=%d.", __FUNCTION__, cmd);
    MsgCmd_SendIlm2Mmi(MSG_ID_DTMF_EXEC_CMD_REQ, (void*)req);
}

/*******************************************************************************
** ����: dtmf_ReleaseAllActivedCall
** ����: �Ҷ����е绰
** ����: exec -- �Ƿ�ִ������
** ����: ��
** ����: wasfayu
*******/
static void dtmf_ReleaseAllActivedCall(MMI_BOOL exec)
{    
    //�Ҷϵ绰
    srv_ucm_act_request(SRV_UCM_END_ALL_ACT, NULL, NULL, NULL);
    
    AlmEnableExpiryHandler();

    if (exec)
    {
        //������Ϣȥִ������
        dtmf_PostCmdExecReq(dtmfCnxt.command, dtmfCnxt.call.number, NULL);
    }
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
    MMI_BOOL playOK;

    dtmf_StopKeyDetect();

    //�ﵽ������, ֱ�ӹҶϵ绰
    if (dtmfCnxt.rptCount++ >= dtmfCnxt.rptMax)
    {
        dtmf_ReleaseAllActivedCall(MMI_FALSE);
        Dtmf_Reset();
        return;
    }
    
    //���²�����ʾ��
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
        //���ڵȴ�����, ������ⳬʱ, �ظ�����
        //ϵͳ����, ������ʾ�� 1Entry.wav
        dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
        if (!playOK)
        {
            //����ʧ������밴�����
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
    case DTMF_STATE_INPUT_PWD:
        //�ȴ���������, ��ʱ���ظ�����
        dtmfCnxt.param.password[7] = 0;
        break;
        
    case DTMF_STATE_CHOOSE_OPTION:
        break;
        
    case DTMF_STATE_INPUT_PARAM:
        break;
        
    case DTMF_STATE_IDLE:
    case DTMF_STATE_GOODBYE:
    case DTMF_STATE_MAX_ENUM:
    default:
        break;
    }
    
}

/*******************************************************************************
** ����: dtmf_SwitchFSMStatus
** ����: �л�״̬����״̬
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_SwitchFSMStatus(void)
{
    MMI_BOOL playOK;

    dtmf_trace("%s: ENTRY state=%d.", __FUNCTION__,dtmfCnxt.state);
    
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_IDLE:
        //ϵͳ����, ������ʾ�� 1Entry.wav
        dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_WAITING_ENTRY;
        if (!playOK)
        {
            //����ʧ������밴�����
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
    case DTMF_STATE_WAITING_ENTRY:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //ϵͳ�Ѿ�����, ������ʾ�� 2Password.wav
    #if defined(__NEED_CHECK_PASSWORD__)
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PASSWORD, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
    #else
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
    #endif
        if (!playOK)
        {
            //����ʧ������밴�����
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
#if defined(__NEED_CHECK_PASSWORD__)
    case DTMF_STATE_INPUT_PWD:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //��������Ƿ���Ч
        if (dtmfCnxt.param.password[7] == 6 &&
            strncmp(dtmfCnxt.param.password, "123456", 6) == 0)
        {
            //������ʾ�� 3Option.wav
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
            dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
            if (!playOK)
            {
                //����ʧ������밴�����
                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
            }
        }
        else if (dtmfCnxt.rptCount < dtmfCnxt.rptMax)
        {
            //�������
            dtmfCnxt.param.password[7] = 0;
            //������ʾ�� 3Option.wav
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_RETRY_PASSWORD, (void*)dtmfCnxt.detectTime);
            dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
            if (!playOK)
            {
                //����ʧ������밴�����
                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
            }
        }
        else
        {
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ERROR_TO_EXIT, NULL);
            dtmfCnxt.state = DTMF_STATE_GOODBYE;

            if (!playOK)
            {
                dtmf_ReleaseAllActivedCall(MMI_TRUE);
            }
        }
        break;
#endif

    case DTMF_STATE_CHOOSE_OPTION:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //������ʾ�� 7Param.wav
    #if defined(__RECIVE_CMD_PARAMETER__)
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PARAM, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_INPUT_PARAM;
        if (!playOK)
        {
            //����ʧ������밴�����
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
    #else
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_REQUEST, NULL);
        dtmfCnxt.state = DTMF_STATE_GOODBYE;
    #endif
        break;
        
#if defined(__RECIVE_CMD_PARAMETER__)
    case DTMF_STATE_INPUT_PARAM:
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_REQUEST, NULL);
        dtmfCnxt.state = DTMF_STATE_GOODBYE;

        if (!playOK)
        {
            dtmf_ReleaseAllActivedCall(MMI_TRUE);
        }
        break;
#endif

    case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(MMI_TRUE);
        break;
        
    case DTMF_STATE_MAX_ENUM:
    default:
        break;
    }

    dtmf_trace("%s: EXIT state=%d.", __FUNCTION__,dtmfCnxt.state);
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
	dtmf_trace("%s: key=0x%x, state=%d.", __FUNCTION__, key, dtmfCnxt.state);

    if (!mdi_audio_snd_is_idle())
    {
        mdi_audio_snd_stop();
    }
    
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_IDLE:
        break;
    case DTMF_STATE_WAITING_ENTRY:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            //��������״̬
            dtmf_SwitchFSMStatus();
        }
        else
        {
            //��������, ���¼��, ������ʾ��
            dtmfCnxt.rptCount++;
        }
        break;
        
#if defined(__NEED_CHECK_PASSWORD__)
    case DTMF_STATE_INPUT_PWD:
        if (dtmfCnxt.hotKey == (U8)key)
        {
            mdi_audio_stop_keytone_detect();
            dtmf_SwitchFSMStatus();
        }
        else if (('0' <= (char)key && (char)key <= '9') || '*' <= (char)key)
        {
            U32 index = dtmfCnxt.param.password[7];

            if (index < 6)
            {
                dtmfCnxt.param.password[index] = (char)key;
            }
            dtmfCnxt.param.password[7] ++;
        }
        else
        {
            mdi_audio_stop_keytone_detect();
            //��������
        }
        break;
#endif

    case DTMF_STATE_CHOOSE_OPTION:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            dtmf_SwitchFSMStatus();
        }
        else if ('0' <= (char)key && (char)key <= '9')
        {
            dtmfCnxt.command = (char)key - '0';
            dtmf_SwitchFSMStatus();
        }
        else
        {
            //��������, ��������
            dtmfCnxt.rptMax ++;
        }
        break;

#if defined(__RECIVE_CMD_PARAMETER__)
    case DTMF_STATE_INPUT_PARAM:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            dtmf_SwitchFSMStatus();
        }
        else
        {
            //��¼����
        }
        break;
#endif

    case DTMF_STATE_GOODBYE:
        break;
    case DTMF_STATE_MAX_ENUM:
    default:
        break;
    }
}

/*******************************************************************************
** ����: dtmf_StartKeyDetect
** ����: ��ʼDTMF�İ������
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_StartKeyDetect(U32 timeout)
{
    mdi_result ret;

    ret = mdi_audio_start_keytone_detect(dtmf_KeyDetectCallback);
    dtmf_trace("%s: time=%d,ret=%d,curr state=%d.", __FUNCTION__, timeout, ret, dtmfCnxt.state);
    if (MDI_AUDIO_SUCCESS == ret)
    {
        StartTimer(TIMER_DTMF_KEY_DETECT, timeout, dtmf_KeyDetectTimeoutCb);
        dtmfCnxt.start = MMI_TRUE;
    }
    else
    {
        //ʧ����, ������ʾ
    }
}

/*******************************************************************************
** ����: dtmf_StopKeyDetect
** ����: ֹͣDTMF�������
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_StopKeyDetect(void)
{
    StopTimer(TIMER_DTMF_KEY_DETECT);
    if (dtmfCnxt.start)
    {
        mdi_audio_stop_keytone_detect();
        dtmfCnxt.start = MMI_FALSE;
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
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index)
{
    ASSERT(NULL != output);

    kal_wsprintf(output, "%c:\\%w\\%s",
        MsgCmd_GetUsableDrive(),DTMF_VOICE_MAIN_PATH,voiceTab[index].name);
    
    return output;    
}

/*******************************************************************************
** ����: dtmf_PlayCustomPromptVoiceFileCb
** ����: �����û��Զ�����ʾ��Ļص�����
** ����: result -- ���Ž��
**       usd    -- �û�����
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PlayCustomPromptVoiceFileCb(mdi_result result, void *usd)
{
    dtmf_trace("Play custom voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //�����ǰ״̬Ϊxx״̬�򷵻�
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        //�ȴ��������
    }
    else
    {
        //����ʧ��, ���²���ϵͳ�Դ�����Դ
    }

    switch(dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
    case DTMF_STATE_INPUT_PWD:
    case DTMF_STATE_CHOOSE_OPTION:
    case DTMF_STATE_INPUT_PARAM:
        dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        break;
        
    case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(MMI_TRUE);
        break;
        
    case DTMF_STATE_IDLE:
    default:
        break;
    }
}

/*******************************************************************************
** ����: dtmf_PlaySystemPromptVoiceFileCb
** ����: ����ϵͳ��ʾ��Ļص�����
** ����: result -- ���Ž��
**       usd    -- �û�����
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PlaySystemPromptVoiceFileCb(mdi_result result, void *usd)
{
    dtmf_trace("Play system voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //�����ǰ״̬Ϊxx״̬�򷵻�
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        //�ȴ��������
    }
    else
    {
        //����ʧ��, ��������, ֱ�ӽ��а������ʲô��
    }

    switch(dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
    case DTMF_STATE_INPUT_PWD:
    case DTMF_STATE_CHOOSE_OPTION:
    case DTMF_STATE_INPUT_PARAM:
        dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        break;
        
    case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(MMI_TRUE);
        break;
        
    case DTMF_STATE_IDLE:
    default:
        break;
    }
}

///*****************************************************************************
// * FUNCTION
// *  get_audio
// * DESCRIPTION
// *  Wrapper for GetAudio() function
// * PARAMETERS
// *  i           [IN]        Audio id
// *  type        [OUT]       Audio type
// *  filelen     [OUT]       File length
// * RETURNS
// *  pointer to the audio raw data corresponding to the given audio ID
// *****************************************************************************/
//U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    U8 *s = NULL;
//
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    ASSERT(type != NULL && filelen != NULL);
//
//    *type = 0;;
//    *filelen = 0;
//
//    if (i == 0)
//    {
//        return (NULL);
//    }
//
//    s = (U8*) GetAudio((U16) i);
//    if (s == NULL)
//    {
//        return (NULL);
//    }
//    if (s[0] == '\0')
//    {
//        return (NULL);
//    }
//
//    *type = s[0];
//
//    *filelen |= (U32) (s[1]);
//    *filelen |= (U32) ((U32) s[2] << 8);
//    *filelen |= (U32) ((U32) s[3] << 16);
//    *filelen |= (U32) ((U32) s[4] << 24);
//
//    return (s + 8);
//}

/*******************************************************************************
** ����: dtmf_GetSystemVoiceFileId
** ����: ��ȡϵͳ��ʾ�����ļ�ID
** ����: idx  -- ������Դ����
** ����: ϵͳ������ԴID
** ����: wasfayu
*******/
static MMI_ID_TYPE dtmf_GetSystemVoiceFileId(DtmfVoiceIndex idx)
{
    switch(idx)
    {
    case DTMF_VOC_PRESS_TO_ENTRY :
        return MC_DTMF_VOC_WELCOME;
        
    case DTMF_VOC_INPUT_PASSWORD :
        return MC_DTMF_VOC_PASSWORD;
        
    case DTMF_VOC_CHOOSE_OPTION  :
        return MC_DTMF_VOC_OPTION;
        
    case DTMF_VOC_RETRY_INPUT    :
        return MC_DTMF_VOC_RETRY;
        
    case DTMF_VOC_ERROR_TO_EXIT  :
        return MC_DTMF_VOC_ERROR;
        
    case DTMF_VOC_ACCEPT_REQUEST :
        return MC_DTMF_VOC_ACCEPT;
        
    case DTMF_VOC_INPUT_PARAM    :
        return MC_DTMF_VOC_PARAM;
        
    case DTMF_VOC_RETRY_PASSWORD:
        return MC_DTMF_VOC_RETRY_PWD;

    case DTMF_VOC_RETRY_OPTIOIN:
        return MC_DTMF_VOC_RETRY_OPT;
        
    case DTMF_VOC_NO_VOICE       :
    default:
        return MC_DTMF_VOC_SILENCE;
    }
}

/*******************************************************************************
** ����: dtmf_PlayCustomVoiceFile
** ����: �����û���ʾ��
** ����: idx  -- ������Դ����
**       cbf  -- �ص�����
** ����: �Ƿ񲥷ųɹ�
** ����: wasfayu
*******/
static MMI_BOOL dtmf_PlayCustomVoiceFile(DtmfVoiceIndex idx, void *usd)
{
    WCHAR filepath[MSGCMD_FILE_PATH_LENGTH+1];
    mdi_result result;

    if (!mdi_audio_snd_is_idle())
    {
        mdi_audio_snd_stop();
    }
    
    memset(filepath, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
    dtmf_CombineVoiceFilePath(filepath, idx);
    
    result = mdi_audio_snd_check_file_format(filepath);
    dtmf_trace("Check custom voice \"%s\", ret=%d.", voiceTab[idx].name, result);
    
    if (result == MDI_AUDIO_SUCCESS)
    {
        result = mdi_audio_snd_play_file_with_vol_path(
                    (void*)filepath,
                    1,
                    dtmf_PlayCustomPromptVoiceFileCb,
                    usd,
                    6,
                    MDI_DEVICE_SPEAKER2);
        dtmf_trace("Play custom voice \"%s\", ret=%d.", voiceTab[idx].name, result);
    }

    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == result);
}

/*******************************************************************************
** ����: dtmf_PlaySystemVoiceFile
** ����: ����ϵͳ��ʾ��
** ����: idx  -- ������Դ����
**       cbf  -- �ص�����
** ����: �Ƿ񲥷ųɹ�
** ����: wasfayu
*******/
static MMI_BOOL dtmf_PlaySystemVoiceFile(DtmfVoiceIndex idx, void *usd)
{
    mdi_result result;
    U32 audio_len;
    U8 *audio_data;
    U8  audio_type;
    MMI_ID_TYPE audio_id = 0;

    audio_id = dtmf_GetSystemVoiceFileId(idx);
    audio_data = get_audio(audio_id, &audio_type, &audio_len);
    ASSERT(NULL != audio_data);
    
    //����ϵͳ����ʾ��
    result = mdi_audio_snd_play_string_with_vol_path(
                (void*)audio_data,
                audio_len,
                1,
                dtmf_PlaySystemPromptVoiceFileCb,
                usd,
                6,
                MDI_DEVICE_SPEAKER2);
    dtmf_trace("Play system voice, ret=%d.", result);
    
    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == result);
}

/*******************************************************************************
** ����: dtmf_PlayPromptVoiceFile
** ����: ������ʾ��
** ����: idx  -- ������Դ����
**       cbf  -- �ص�����
** ����: �Ƿ񲥷ųɹ�
** ����: wasfayu
*******/
static MMI_BOOL dtmf_PlayPromptVoiceFile(DtmfVoiceIndex idx, void *usd)
{
    MMI_BOOL ret;
    
    ret = dtmf_PlayCustomVoiceFile(idx, usd);

    if (!ret)
        ret = dtmf_PlaySystemVoiceFile(idx, usd);

    return ret;
}

/*******************************************************************************
** ����: dtmf_AutoAnswerResponse
** ����: ����Ӧ���������Ϣ��Ӧ����
** ����: p  -- DtmfAutoAnswerReq
** ����: ��
** ����: wasfayu
*******/
static void dtmf_AutoAnswerResponse(void *p)
{
    DtmfAutoAnswerReq *rsp = (DtmfAutoAnswerReq*)p;

    AlmDisableExpiryHandler();
    Dtmf_Reset();
    memcpy(&dtmfCnxt.call, &rsp->info, sizeof(DtmfCallInfo));
    dtmf_SwitchFSMStatus();
}

/*******************************************************************************
** ����: Dtmf_AutoAnswerReqSend
** ����: ��������Ӧ���������Ϣ
** ����: name  -- �������
**       number-- ��ʾ����
** ����: ��
** ����: wasfayu
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

