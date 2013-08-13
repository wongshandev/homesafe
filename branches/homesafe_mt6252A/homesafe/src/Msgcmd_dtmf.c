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
#include "AlarmFrameworkProt.h"

/*
 * ��������ʾ���������֮����ܿ����������, �������ɰ�������
 * ����Զ�����ʾ������ʧ��, ��Ҫ����ϵͳ����ʾ��
 * �����ʾ������ʧ��, ��ֱ�ӽ��밴�����
 */

#define dtmf_trace(fmt, ...) do{lfy_write_log(fmt, ##__VA_ARGS__); kal_prompt_trace(0, fmt, ##__VA_ARGS__);}while(0)


extern U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen);

#if defined(__TEST_PLAY_AUDIO__)
static WCHAR *dtmf_TestPlayVoiceGetFolderPath(WCHAR *buffer);
static void dtmf_TestPlayVoiceTraceName(WCHAR *file);
static void dtmf_TestPlayVoicePlayCb(mdi_result result);
static MMI_BOOL dtmf_TestPlayVoicePlay(WCHAR *filepath);
static void dtmf_TestPlayVoiceEndCall(void);
static void dtmf_TestPlayVoiceTimerCb();
static void dtmf_TestPlayVoice(void);
#endif
static MMI_BOOL dtmf_IsValidCommand(DtmfCommand cmd);
static MMI_BOOL dtmf_CheckPassword(const char *pwdStr);
static void dtmf_CmdExecRsp(void *p);
static void dtmf_PostCmdExecReq(DtmfCommand cmd, char *number, void *param);
static void dtmf_ReleaseAllActivedCall(MMI_BOOL exec);
static void dtmf_KeyDetectTimeoutCb(void);
static void dtmf_SwitchFSMStatus(void);
static void dtmf_KeyDetectCallback(S16 key);
static void dtmf_StartKeyDetect(U32 timeout);
static void dtmf_StopKeyDetect(void);
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index);
static void dtmf_PlayCustomPromptVoiceFileCb(mdi_result result);
static void dtmf_PlaySystemPromptVoiceFileCb(mdi_result result);
static MMI_ID_TYPE dtmf_GetSystemVoiceFileId(DtmfVoiceIndex idx);
static MMI_BOOL dtmf_PlayCustomVoiceFile(DtmfVoiceIndex idx, void *usd);
static MMI_BOOL dtmf_PlaySystemVoiceFile(DtmfVoiceIndex idx, void *usd);
static MMI_BOOL dtmf_PlayPromptVoiceFile(DtmfVoiceIndex idx, void *usd);
static void dtmf_AutoAnswerResponse(void *p);

static DtmfControl dtmfCnxt;

const static VoiceAttr voiceTab[] = {
    {DTMF_VOC_NO_VOICE       , "Silence.wav"},
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
	{DTMF_VOC_CHOOSE_OPTION	 , "welcome_old.wav"},
	{DTMF_VOC_ACCEPT_CAPTURE , "key1.wav"},
	{DTMF_VOC_ACCEPT_ADORECD , "key2.wav"},
	{DTMF_VOC_ACCEPT_VDORECD , "key3.wav"},
	{DTMF_VOC_COMMAND_ERROR  , "di_tone.wav"},
#else
    {DTMF_VOC_PRESS_TO_ENTRY , "Welcome.wav"},
    {DTMF_VOC_INPUT_PASSWORD , "EnterPwd.wav"},
    {DTMF_VOC_CHOOSE_OPTION  , "ChooseOpt.wav"},
    {DTMF_VOC_RETRY_INPUT    , "Retry.wav"},
    {DTMF_VOC_ERROR_TO_EXIT  , "Error.wav"},
    {DTMF_VOC_ACCEPT_REQUEST , "Accept.wav"},
    {DTMF_VOC_INPUT_PARAM    , "EnterParam.wav"},
    {DTMF_VOC_RETRY_PASSWORD , "RetryPwd.wav"},
    {DTMF_VOC_RETRY_OPTIOIN  , "RetryOpt.wav"},
	{DTMF_VOC_RETRY_PARAM    , "RetryParam.wav"},
#endif
};

#if defined(__TEST_PLAY_AUDIO__)
static FS_HANDLE testPlayFh = NULL;
#endif


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
#if defined(__TEST_PLAY_AUDIO__)
	dtmfCnxt.testKey	= DTMF_TEST_KEY_VALUE;
#endif
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

#if !defined(__EXEC_IN_TIMER_CBF__)
    mmi_frm_set_protocol_event_handler(
        MSG_ID_DTMF_EXEC_CMD_REQ,
        (PsIntFuncPtr)dtmf_CmdExecRsp,
        MMI_FALSE);
#endif
}

#if defined(__TEST_PLAY_AUDIO__)

/*******************************************************************************
** ����: dtmf_TestPlayVoiceGetFolderPath
** ����: ��ȡ�ļ��еľ���·��
** ����: buffer -- ���buffer
** ����: ����buffer�ĵ�ַ
** ����: wasfayu
*******/
static WCHAR *dtmf_TestPlayVoiceGetFolderPath(WCHAR *buffer)
{
    kal_wsprintf(buffer, "%c:\\%w\\", MsgCmd_GetUsableDrive(), DTMF_VOICE_MAIN_PATH);
}

/*******************************************************************************
** ����: dtmf_TestPlayVoiceTraceName
** ����: trace�ļ�����Ϣ, ��Ϊ��wchar��ʽ, ����ר��ASCII��ʽ����ӡ
** ����: file -- �ļ���
** ����: ��
** ����: wasfayu
*******/
static void dtmf_TestPlayVoiceTraceName(WCHAR *file)
{
    if (file)
    {
        char buffer[256];

        memset(buffer, 0, 256);

        app_ucs2_str_to_asc_str(buffer, (S8*)file);
        dtmf_trace("file-\"%s\"", buffer);
    }
}

/*******************************************************************************
** ����: dtmf_TestPlayVoicePlayCb
** ����: ���ŵĻص�����, 52���������ص�����ֻ��һ���β�, 50������һ��void*�͵��β�
** ����: result -- ���Ž��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_TestPlayVoicePlayCb(mdi_result result)
{    
    dtmf_trace("Play voice Callback result is %d.", result);

    StartTimer(TIMER_DTMF_KEY_DETECT, 500, dtmf_TestPlayVoiceTimerCb);
}

/*******************************************************************************
** ����: dtmf_TestPlayVoicePlay
** ����: ִ�в���
** ����: filepath -- �ļ��ľ���·��
** ����: �Ƿ񲥷ųɹ�
** ����: wasfayu
*******/
static MMI_BOOL dtmf_TestPlayVoicePlay(WCHAR *filepath)
{
    mdi_result result;
    WCHAR abspath[128];
    
    if (!mdi_audio_snd_is_idle())
    {
        mdi_audio_snd_stop();
    }

    memset(abspath, 0, 128*sizeof(WCHAR));
    dtmf_TestPlayVoiceGetFolderPath(abspath);
    app_ucs2_strcat((S8*)abspath, (const S8 *)filepath);
    dtmf_TestPlayVoiceTraceName(abspath);
        
    result = mdi_audio_snd_check_file_format(abspath);
    dtmf_trace("Check voice return %d.", result);
    
    if (result == MDI_AUDIO_SUCCESS)
    {
        result = mdi_audio_snd_play_file_with_vol_path(
                    (void*)abspath,
                    1,
                    NULL,
                    dtmf_TestPlayVoicePlayCb,
                    6,
                    MDI_DEVICE_SPEAKER2);
        dtmf_trace("Play voice return %d.", result);
    }
    
    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == result);
}

/*******************************************************************************
** ����: dtmf_TestPlayVoiceEndCall
** ����: ������������
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_TestPlayVoiceEndCall(void)
{
    srv_ucm_act_request(SRV_UCM_END_ALL_ACT, NULL, NULL, NULL);
    dtmf_trace("Release Call");
}

/*******************************************************************************
** ����: dtmf_TestPlayVoiceTimerCb
** ����: ��ʱ���ص�����, ������һ�ײ�����
** ����: inp  -- ���
** ����: ��
** ����: wasfayu
*******/
static void dtmf_TestPlayVoiceTimerCb(void)
{
    WCHAR file[128];
    FS_DOSDirEntry info;

    memset(file, 0, 128*sizeof(WCHAR));
    if (NULL == testPlayFh)
    {
        WCHAR buffer[128];
        
        memset(buffer, 0, 128*sizeof(WCHAR));
        dtmf_TestPlayVoiceGetFolderPath(buffer);
        app_ucs2_strcat((S8*)buffer, (const S8*)L"*.*");
        
        testPlayFh = FS_FindFirst(buffer, 0, FS_ATTR_HIDDEN|FS_ATTR_VOLUME|FS_ATTR_DIR, &info, file, 63);
        if (testPlayFh < FS_NO_ERROR)
        {
        	testPlayFh = NULL;
            dtmf_TestPlayVoiceEndCall();
            return;
        }
    }
    else if (FS_FindNext(testPlayFh, &info, file, 63) < FS_NO_ERROR)
    {
        dtmf_TestPlayVoiceEndCall();
        FS_FindClose(testPlayFh);
		testPlayFh = NULL;
        return;
    }

    //���û�е绰��ͨ����
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        dtmf_TestPlayVoiceEndCall();
        FS_FindClose(testPlayFh);
		testPlayFh = NULL;
        return;
    }
    
    //play voice
    if (!dtmf_TestPlayVoicePlay(file))
    {
        StartTimer(TIMER_DTMF_KEY_DETECT, 300, dtmf_TestPlayVoiceTimerCb);
    }
}

/*******************************************************************************
** ����: dtmf_TestPlayVoice
** ����: ��ʼִ�в���
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_TestPlayVoice(void)
{
    StartTimer(TIMER_DTMF_KEY_DETECT, 200, dtmf_TestPlayVoiceTimerCb);
}
#endif

/*******************************************************************************
** ����: dtmf_IsValidCommand
** ����: �Ƿ�����Ч������
** ����: cmd  -- ����
** ����: �Ƿ���Ч
** ����: wasfayu
*******/
static MMI_BOOL dtmf_IsValidCommand(DtmfCommand cmd)
{
    return (MMI_BOOL)(cmd > DTMF_CMD_NONE && cmd < DTMF_CMD_UNDEFINED);
}

/*******************************************************************************
** ����: dtmf_CheckPassword
** ����: ����������ȷ��
** ����: pwdStr -- �����ַ���
** ����: �����Ƿ���ȷ
** ����: wasfayu
*******/
static MMI_BOOL dtmf_CheckPassword(const char *pwdStr)
{
#if defined(__NEED_CHECK_PASSWORD__)
	if (strlen(pwdStr) != DTMF_PWD_STR_LENGTH)
		return MMI_FALSE;

	return (MMI_BOOL)(strcmp(pwdStr, DTMF_DEFAULT_PASSWORD) == 0);
#else
	return MMI_TRUE;
#endif
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

	//��Ϊ����ʱִ�е�, ���ִ��ʱ, �е绰����, ��ȡ��ִ��
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return;
    }

    //��������Ѿ�ִ��, �򷵻�, Ϊ�˷�ֹ�ظ�����Ϣ���ߺ�������
    if (!dtmf_IsValidCommand(dtmfCnxt.command))
    {
        return;
    }
    
    switch(rsp->command)
    {
    case DTMF_CMD_CAPTURE:
		{
            MsgcmdCaptureReq *req = (MsgcmdCaptureReq*)MsgCmd_ConstructPara(sizeof(MsgcmdCaptureReq));

			dtmf_trace("%s, CAPTURE.", __FUNCTION__);
            strcpy(req->number, rsp->number);
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_CAPTURE_REQ, (void *)req);
        }
        break;
        
    case DTMF_CMD_ADORECD:
		{
            MsgcmdAdoProcReq *req = (MsgcmdAdoProcReq*)\
                MsgCmd_ConstructPara(sizeof(MsgcmdAdoProcReq));

			dtmf_trace("%s, AUDIO RECORD.", __FUNCTION__);
            req->saveGap = MsgCmd_GetAdoRecdArgs()->save_gap;
            strcpy(req->number, rsp->number);
            
            if (MsgCmd_AdoRecdBusy())
            {
                req->record  = MMI_FALSE;
            }
            else
            {
                req->record  = MMI_TRUE;
                req->forever = MMI_TRUE;
            }
            
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_ADORECD_REQ, (void *)req);
        }
        break;
        
    case DTMF_CMD_VDORECD:
        {
            MsgcmdVdoProcReq *req = (MsgcmdVdoProcReq*)\
                MsgCmd_ConstructPara(sizeof(MsgcmdVdoProcReq));

			dtmf_trace("%s, VIDEO RECORD.", __FUNCTION__);
            req->saveGap = MsgCmd_GetVdoRecdArgs()->save_gap;
            strcpy(req->number, rsp->number);
            
            if (MsgCmd_VdoRecdBusy())
            {
                req->record  = MMI_FALSE;
            }
            else
            {
                req->record  = MMI_TRUE;
                req->forever = MMI_TRUE;
            }
            
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_VDORECD_REQ, (void *)req);
        }
        break;
        
    default:
        break;
    }

#if defined(__EXEC_IN_TIMER_CBF__)
    MsgCmd_DestructPara(p);
#endif

    Dtmf_Reset();
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
		//��ʱ2����ȥִ��, ����������������
#if defined(__EXEC_IN_TIMER_CBF__)
	StartTimerEx(TIMER_DTMF_DELAY_EXEC, 2000, dtmf_CmdExecRsp, (void *)req);
#else
    MsgCmd_SendIlm2Mmi(MSG_ID_DTMF_EXEC_CMD_REQ, (void*)req);
#endif
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

	dtmf_trace("Release call, exec=%d, cmd=%d.", exec, dtmfCnxt.command);
    if (exec && dtmf_IsValidCommand(dtmfCnxt.command))
    {
        //������Ϣȥִ������
    #if defined(__MSGCMD_DTMF_OLD_VERSION__)
		dtmf_PostCmdExecReq(dtmfCnxt.command, dtmfCnxt.call.number, NULL);
	#else
        dtmf_PostCmdExecReq(dtmfCnxt.command, dtmfCnxt.call.number, NULL);
	#endif
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
    if (dtmfCnxt.rptCount >= dtmfCnxt.rptMax)
    {
        dtmf_ReleaseAllActivedCall(MMI_FALSE);
        Dtmf_Reset();
        return;
    }

	//���û�е绰��ͨ����
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        Dtmf_Reset();
        return;
    }
	
	dtmfCnxt.error = MMI_TRUE;
	dtmfCnxt.rptCount ++;
	dtmf_SwitchFSMStatus();    
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
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
    case DTMF_STATE_IDLE:
		//�ϰ汾, �绰��ͨ��, ����ʱ�����Է�, ֱ���Է�����#���ٲ���option��ѡ����ʾ��
		dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
		dtmfCnxt.state      = DTMF_STATE_WAITING_ENTRY;
		dtmf_StartKeyDetect(dtmfCnxt.detectTime);
		break;

	case DTMF_STATE_WAITING_ENTRY:
		if (dtmfCnxt.error)
		{
			dtmfCnxt.error      = MMI_FALSE;
			dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
			dtmfCnxt.rptCount   = 0; //�ϰ汾, ����ʱ����, ֱ������#��
			
			if (dtmfCnxt.rptCount <= dtmfCnxt.rptMax)
			{
		        dtmfCnxt.state = DTMF_STATE_WAITING_ENTRY;
			}
			else
			{
				dtmfCnxt.state = DTMF_STATE_GOODBYE;
                dtmf_ReleaseAllActivedCall(MMI_FALSE);
				break;
			}
			
			dtmf_StartKeyDetect(dtmfCnxt.detectTime);
		}
		else
		{
			dtmfCnxt.rptCount   = 0;
			dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
			playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
	        dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
			if (!playOK)
			{
				dtmf_StartKeyDetect(dtmfCnxt.detectTime);
			}
		}
		break;
	
	case DTMF_STATE_CHOOSE_OPTION:
		dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;

		dtmf_trace("%s, command=%d.", __FUNCTION__, dtmfCnxt.command);
		if (!dtmf_IsValidCommand(dtmfCnxt.command))
		{
			dtmfCnxt.error = MMI_TRUE;
			dtmfCnxt.rptCount ++;
		}
		
		if (dtmfCnxt.error)
		{
			dtmfCnxt.error = MMI_FALSE;
			
			if (dtmfCnxt.rptCount <= dtmfCnxt.rptMax)
			{
		        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
		        dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
				if (!playOK)
	            {
	                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
	            }
			}
			else
			{
				//����������ֱ࣬���˳�
            	dtmfCnxt.state = DTMF_STATE_GOODBYE;
                dtmf_ReleaseAllActivedCall(MMI_FALSE);
				break;
			}
		}
		else
		{
			MMI_BOOL exec = MMI_TRUE;
			dtmfCnxt.rptCount = 0;
			
            //������ʾ�� Accept.wav, Ȼ��Ҷϵ绰
            if (DTMF_CMD_CAPTURE == dtmfCnxt.command)
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_CAPTURE, NULL);
			else if (DTMF_CMD_ADORECD == dtmfCnxt.command)
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_ADORECD, NULL);
			else if (DTMF_CMD_VDORECD == dtmfCnxt.command)
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_VDORECD, NULL);
			else
			{
				playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_COMMAND_ERROR, NULL);
				exec   = MMI_FALSE;
			}
			
            dtmfCnxt.state = DTMF_STATE_GOODBYE;
            if (!playOK)
            {
                dtmf_ReleaseAllActivedCall(exec);
            }
		}
		break;

	case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(dtmf_IsValidCommand(dtmfCnxt.command));
        break;
		
#else/*#if defined(__MSGCMD_DTMF_OLD_VERSION__)*/
	
	case DTMF_STATE_IDLE:
        //ϵͳ����, ������ʾ�� Welcome.wav
        dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_WAITING_ENTRY;
        if (!playOK)
        {
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
		
    case DTMF_STATE_WAITING_ENTRY:
		if (dtmfCnxt.error)
		{
			dtmfCnxt.error      = MMI_FALSE;
			dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
			
			if (dtmfCnxt.rptCount <= dtmfCnxt.rptMax)
			{
		        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
		        dtmfCnxt.state = DTMF_STATE_WAITING_ENTRY;
			}
			else
			{
				playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ERROR_TO_EXIT, NULL);
            	dtmfCnxt.state = DTMF_STATE_GOODBYE;
				if (!playOK)
	            {
	                dtmf_ReleaseAllActivedCall(MMI_FALSE);
	            }
				break;
			}
		}
		else
		{
			dtmfCnxt.rptCount = 0;
			dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
			
	    #if defined(__NEED_CHECK_PASSWORD__)
	        //ϵͳ�Ѿ�����, ������ʾ�� password.wav
	        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PASSWORD, (void*)dtmfCnxt.detectTime);
	        dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
	    #else
	        //ϵͳ�Ѿ�����, ������ʾ�� ChooseOpt.wav
	        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
	        dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
	    #endif
		}
		
		if (!playOK)
		{
			dtmf_StartKeyDetect(dtmfCnxt.detectTime);
		}
        break;

#if defined(__NEED_CHECK_PASSWORD__)
    case DTMF_STATE_INPUT_PWD:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;

		dtmf_trace("%s, error=%d. password=%s. %d.", __FUNCTION__, dtmfCnxt.error, dtmfCnxt.param.password, dtmfCnxt.param.password[PWD_IDX_VAL]);
		//����û�д�����������ȷ
		if (!dtmfCnxt.error)
		{
			if (dtmfCnxt.param.password[PWD_IDX_VAL] == DTMF_PWD_STR_LENGTH &&
				dtmf_CheckPassword((const char *)dtmfCnxt.param.password))
	        {
	            dtmfCnxt.rptCount = 0;
				
	            //������Ч, ������ʾ�� ChooseOpt.wav
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
	            dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
	            if (!playOK)
	            {
	                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
	            }
				break;
	        }
			else
			{
				dtmfCnxt.error = MMI_TRUE;
				dtmfCnxt.rptCount ++;
			}
		}

		//����Ҫ����ļ�������ִ�������
		if (dtmfCnxt.error)
		{
			dtmfCnxt.error      = MMI_FALSE;
			
			if (dtmfCnxt.rptCount <= dtmfCnxt.rptMax)
			{
				dtmfCnxt.param.recordTime[PWD_IDX_VAL] = 0;
		        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_RETRY_PASSWORD, (void*)dtmfCnxt.detectTime);
		        dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
			}
			else
			{
				playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ERROR_TO_EXIT, NULL);
            	dtmfCnxt.state = DTMF_STATE_GOODBYE;
				if (!playOK)
	            {
	                dtmf_ReleaseAllActivedCall(MMI_FALSE);
	            }
				break;
			}
		}
        break;
#endif

    case DTMF_STATE_CHOOSE_OPTION:
		dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;

		dtmf_trace("%s, command=%d.", __FUNCTION__, dtmfCnxt.command);
		if (!dtmf_IsValidCommand(dtmfCnxt.command))
		{
			dtmfCnxt.error = MMI_TRUE;
			dtmfCnxt.rptCount ++;
		}
		
		if (dtmfCnxt.error)
		{
			dtmfCnxt.error      = MMI_FALSE;
			
			if (dtmfCnxt.rptCount <= dtmfCnxt.rptMax)
			{
		        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_RETRY_OPTIOIN, (void*)dtmfCnxt.detectTime);
		        dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
				if (!playOK)
	            {
	                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
	            }
			}
			else
			{
				playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ERROR_TO_EXIT, NULL);
            	dtmfCnxt.state = DTMF_STATE_GOODBYE;
				if (!playOK)
	            {
	                dtmf_ReleaseAllActivedCall(MMI_FALSE);
	            }
				break;
			}
		}
		else
		{
			dtmfCnxt.rptCount = 0;
			
	    #if defined(__RECIVE_CMD_PARAMETER__)
	        if (DTMF_CMD_CAPTURE != dtmfCnxt.command)
	        {
	            //����������, ������ʾ�� Param.wav
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PARAM, (void*)dtmfCnxt.detectTime);
	            dtmfCnxt.state = DTMF_STATE_INPUT_PARAM;
	            if (!playOK)
	            {
	                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
	            }
	        }
	        else
	    #endif
	        {
	            //ѡ������������, ������ʾ�� Accept.wav, Ȼ��Ҷϵ绰
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_REQUEST, NULL);
	            dtmfCnxt.state = DTMF_STATE_GOODBYE;
	            if (!playOK)
	            {
	                dtmf_ReleaseAllActivedCall(MMI_TRUE);
	            }
	        }
		}
        break;
        
#if defined(__RECIVE_CMD_PARAMETER__)
    case DTMF_STATE_INPUT_PARAM:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;

		dtmf_trace("%s, error=%d. recordTime=%s. %d.", __FUNCTION__, dtmfCnxt.error, dtmfCnxt.param.recordTime, dtmfCnxt.param.recordTime[PARAM_IDX_VAL]);
		
		//����û�д�����������ȷ
		if (!dtmfCnxt.error)
		{
			if (dtmfCnxt.param.recordTime[PARAM_IDX_VAL] > DTMF_PARAM_STR_LENGTH)
	        {
	            dtmfCnxt.rptCount = 0;
				
	            //������Ч, ������ʾ�� ChooseOpt.wav
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_REQUEST, (void*)dtmfCnxt.detectTime);
	            dtmfCnxt.state = DTMF_STATE_GOODBYE;
	            if (!playOK)
	            {
	                dtmf_ReleaseAllActivedCall(MMI_TRUE);
	            }
				break;
	        }
			else
			{
				dtmfCnxt.error = MMI_TRUE;
				dtmfCnxt.rptCount ++;
			}
		}

		if (dtmfCnxt.error)
		{		
	        if (dtmfCnxt.rptCount < dtmfCnxt.rptMax)
	        {
	            //�������, ������ʾ�� RetryOpt.wav
	            dtmfCnxt.param.recordTime[PARAM_IDX_VAL] = 0;
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_RETRY_PARAM, (void*)dtmfCnxt.detectTime);
	            dtmfCnxt.state = DTMF_STATE_INPUT_PARAM;
	            if (!playOK)
	            {
	                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
	            }
	        }
	        else
	        {
	            //��������������, ������ʾ�� Error.wav, Ȼ��Ҷϵ绰
	            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ERROR_TO_EXIT, NULL);
	            dtmfCnxt.state = DTMF_STATE_GOODBYE;

	            if (!playOK)
	            {
	                dtmf_ReleaseAllActivedCall(MMI_TRUE);
	            }
	        }
		}
        break;
#endif

    case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(MMI_TRUE);
        break;
#endif/*#if defined(__MSGCMD_DTMF_OLD_VERSION__)*/
        
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

	StopTimer(TIMER_DTMF_KEY_DETECT);
	dtmfCnxt.error = MMI_FALSE;
	
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            //��������״̬
            dtmf_SwitchFSMStatus();
        }
	#if defined(__TEST_PLAY_AUDIO__)
		else if(dtmfCnxt.testKey == (U8)key)
		{
			dtmfCnxt.rptCount = 0;
			dtmf_TestPlayVoice();
		}
	#endif
        else
        {
            //��������, ���¼��, ������ʾ��
            dtmfCnxt.error = MMI_TRUE;
            dtmfCnxt.rptCount++;
            dtmf_SwitchFSMStatus();
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
            U32 index = dtmfCnxt.param.password[PWD_IDX_VAL];

            if (index < DTMF_PWD_STR_LENGTH)
            {
                dtmfCnxt.param.password[index] = (char)key;
            }
            dtmfCnxt.param.password[PWD_IDX_VAL] ++;
        }
        else
        {
            mdi_audio_stop_keytone_detect();
            //��������
            dtmfCnxt.error = MMI_TRUE;
            dtmfCnxt.rptCount++;
            memset(dtmfCnxt.param.password, 0, DTMF_PWD_STR_LENGTH);
            dtmfCnxt.param.password[PWD_IDX_VAL] = 0;
            dtmf_SwitchFSMStatus();
        }
        break;
#endif

	//ֻ����һ�ΰ���
    case DTMF_STATE_CHOOSE_OPTION:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            //ʲôҲ����, �����л�״̬
        }
        else if ('1' <= (char)key && (char)key <= '9')
        {
        	//ֻ����1~9�İ�������
            dtmfCnxt.command = (char)key - '0';
        }
        else
        {
            //��������, ��������
            dtmfCnxt.rptMax ++;
			dtmfCnxt.error = MMI_TRUE;
        }
		dtmf_SwitchFSMStatus();
        break;

#if defined(__RECIVE_CMD_PARAMETER__)
    case DTMF_STATE_INPUT_PARAM:
        if (dtmfCnxt.hotKey == (U8)key)
        {
            mdi_audio_stop_keytone_detect();
            dtmf_SwitchFSMStatus();
        }
        else if ('0' <= (char)key && (char)key <= '9')
        {
            U32 index = dtmfCnxt.param.recordTime[PARAM_IDX_VAL];

            if (index < DTMF_PARAM_STR_LENGTH)
            {
                dtmfCnxt.param.recordTime[index] = (char)key;
            }
            dtmfCnxt.param.recordTime[PARAM_IDX_VAL] ++;
        }
        else
        {
            mdi_audio_stop_keytone_detect();
            dtmfCnxt.rptCount ++;
			dtmfCnxt.error = MMI_TRUE;
            memset(dtmfCnxt.param.recordTime, 0, DTMF_PARAM_STR_LENGTH);
            dtmfCnxt.param.recordTime[PARAM_IDX_VAL] = 0;
            dtmf_SwitchFSMStatus();
        }
        break;
#endif

    case DTMF_STATE_IDLE:
    case DTMF_STATE_GOODBYE:
    case DTMF_STATE_MAX_ENUM:
    default:
		mdi_audio_stop_keytone_detect();
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
    //dtmf_trace("%s: time=%d,ret=%d,curr state=%d.", __FUNCTION__, timeout, ret, dtmfCnxt.state);
    if (MDI_AUDIO_SUCCESS == ret)
    {
        StartTimer(TIMER_DTMF_KEY_DETECT, timeout, dtmf_KeyDetectTimeoutCb);
        dtmfCnxt.detecting = MMI_TRUE;
    }
    else
    {
	#if defined(WIN32)
		//ģ������������ʲôҲ����
	#else
        //ʧ����, ֱ�ӹҶϵ绰
        dtmf_ReleaseAllActivedCall(MMI_FALSE);
		Dtmf_Reset();
	#endif
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
    if (dtmfCnxt.detecting)
    {
        mdi_audio_stop_keytone_detect();
        dtmfCnxt.detecting = MMI_FALSE;
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
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PlayCustomPromptVoiceFileCb(mdi_result result)
{
    //dtmf_trace("Play custom voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //�����ǰ״̬Ϊxx״̬�򷵻�
    
//    if (result == MDI_AUDIO_END_OF_FILE)
//    {
//        //�ȴ��������
//    }
//    else
//    {
//        //����ʧ��, ���²���ϵͳ�Դ�����Դ
//    }

    switch(dtmfCnxt.state)
    {
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
	case DTMF_STATE_WAITING_ENTRY:
	case DTMF_STATE_CHOOSE_OPTION:
	case DTMF_STATE_ACCPET_PROMPT:
		dtmf_StartKeyDetect(dtmfCnxt.detectTime);
		break;

#else
	
    case DTMF_STATE_WAITING_ENTRY:
    case DTMF_STATE_INPUT_PWD:
    case DTMF_STATE_CHOOSE_OPTION:
    case DTMF_STATE_INPUT_PARAM:
        dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        break;
#endif
	
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
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PlaySystemPromptVoiceFileCb(mdi_result result)
{
    //dtmf_trace("Play system voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //�����ǰ״̬Ϊxx״̬�򷵻�
    
//    if (result == MDI_AUDIO_END_OF_FILE)
//    {
//        //�ȴ��������
//    }
//    else
//    {
//        //����ʧ��, ��������, ֱ�ӽ��а������ʲô��
//    }

    switch(dtmfCnxt.state)
    {
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
	case DTMF_STATE_WAITING_ENTRY:
	case DTMF_STATE_CHOOSE_OPTION:
	case DTMF_STATE_ACCPET_PROMPT:
		dtmf_StartKeyDetect(dtmfCnxt.detectTime);
		break;
#else

    case DTMF_STATE_WAITING_ENTRY:
    case DTMF_STATE_INPUT_PWD:
    case DTMF_STATE_CHOOSE_OPTION:
    case DTMF_STATE_INPUT_PARAM:
        dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        break;
#endif

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
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
	switch(idx)
	{
	case DTMF_VOC_CHOOSE_OPTION	 :
		return MC_DTMF_VOC_CHOOSE_OPTION;
		
	case DTMF_VOC_ACCEPT_CAPTURE :
		return MC_DTMF_VOC_ACCEPT_CAPTURE;
		
	case DTMF_VOC_ACCEPT_ADORECD :
		return MC_DTMF_VOC_ACCEPT_ADORECD;
		
	case DTMF_VOC_ACCEPT_VDORECD :
		return MC_DTMF_VOC_ACCEPT_VDORECD;
		
	case DTMF_VOC_COMMAND_ERROR	 :
		return MC_DTMF_VOC_DI_TONE;

	default:
		return MC_DTMF_VOC_SILENCE;
	}
#else
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

	case DTMF_VOC_RETRY_PARAM:
		return MC_DTMF_VOC_RETRY_PARAM;
		
    case DTMF_VOC_NO_VOICE       :
    default:
        return MC_DTMF_VOC_SILENCE;
    }
#endif
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
    //dtmf_trace("Check custom voice \"%s\", ret=%d.", voiceTab[idx].name, result);
    
    if (result == MDI_AUDIO_SUCCESS)
    {
        result = mdi_audio_snd_play_file_with_vol_path(
                    (void*)filepath,
                    1,
                    NULL,
                    dtmf_PlayCustomPromptVoiceFileCb,
                    6,
                    MDI_DEVICE_SPEAKER2);
        //dtmf_trace("Play custom voice \"%s\", ret=%d.", voiceTab[idx].name, result);
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
                NULL,
                dtmf_PlaySystemPromptVoiceFileCb,
                6,
                MDI_DEVICE_SPEAKER2);
    //dtmf_trace("Play system voice, ret=%d.", result);
    
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

	dtmf_trace("Play Voice: idx=%d. ret=%d.", idx, ret);
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

    if (name)
        app_ucs2_strcpy((S8*)req->info.name, (const S8*)name);

    if (number)
        strcpy(req->info.number, number);
    
    dtmf_trace("%s, number=%s.", __FUNCTION__, number);
        
    MsgCmd_SendIlm2Mmi(MSG_ID_DTMF_ANSWER_CALL, (void*)req);
}

/*******************************************************************************
** ����: Dtmf_CallReleasedBySide
** ����: �Է��Ҷϵ绰
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_CallReleasedBySide(void)
{
    if (mdi_audio_snd_is_idle())
    {
        mdi_audio_snd_stop();
    }
    
    dtmf_StopKeyDetect();
    dtmf_ReleaseAllActivedCall(dtmf_IsValidCommand(dtmfCnxt.command));
}

#else

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
	/* �պ��� */
}

/*******************************************************************************
** ����: Dtmf_CallReleasedBySide
** ����: �Է��Ҷϵ绰
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_CallReleasedBySide(void)
{
    /* �պ��� */
}

#endif/*__MSGCMD_DTMF__*/

