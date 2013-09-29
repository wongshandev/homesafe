#include "MMI_features.h" 
#include "custresdef.h"

#if defined(__MSGCMD_SUPPORT__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MSGCMD">

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    //<STRING id="STR_ID_NPPLG_ERROR_TITLE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    //<IMAGE id="IMG_ID_NPPLG_AV_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Play_normal.png"</IMAGE>

    <!-----------------------------------------------------Audio Resource Area------------------------------------------------------>
#if defined(__MSGCMD_DTMF_OLD_VERSION__)
	<AUDIO id="MC_DTMF_VOC_CHOOSE_OPTION">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\welcome_old.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_ACCEPT_CAPTURE">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\key1.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_ACCEPT_VDORECD">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\key2.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_ACCEPT_ADORECD">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\key3.wav"</AUDIO>
#else
    <AUDIO id="MC_DTMF_VOC_WELCOME">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\welcome.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_PASSWORD">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\enterPwd.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_OPTION">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\chooseOpt.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_PARAM">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\enterParam.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_ACCEPT">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\accept.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_ERROR">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\error.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_RETRY">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\retry.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_RETRY_PWD">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\RetryPwd.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_RETRY_OPT">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\RetryOpt.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_RETRY_PARAM">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\RetryParam.wav"</AUDIO>
#endif
    <AUDIO id="MC_DTMF_VOC_SILENCE">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\silence.wav"</AUDIO>
    <AUDIO id="MC_DTMF_VOC_DI_TONE">"..\\\\..\\\\..\\\\homesafe\\\\dtmf_voice\\\\di_tone.wav"</AUDIO>
    
    <!-----------------------------------------------------event handler area------------------------------------------------------>
    <RECEIVER id="EVT_ID_IDLE_ENTER" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_IDLE_LAUNCHED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_IDLE_EXIT" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_STATUS_CHANGED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SIM_DN_STATUS_CHANGED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_MMS_READY" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_PHB_READY" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_CHARBAT_NOTIFY" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_EXCEED" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_FULL" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_AVAILABLE" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_BGSR_RESULT" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_SHOW_BGSR_POPUP" proc="MsgCmd_EvtProcEntry"/>
    <RECEIVER id="EVT_ID_SRV_NEW_MMS_MSG" proc="MsgCmd_EvtProcEntry"/>

#ifdef MMS_SUPPORT
	<RECEIVER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" proc="MsgCmd_EvtProcEntry"/>
#endif

    <!--------------------------------------------------Events--------------------------------------------------->
    <EVENT id="EVT_ID_SRV_MC_INCOMING_CALL"/>
    <EVENT id="EVT_ID_SRV_MC_OUTGOING_CALL"/>
    
</APP>

#endif /* defined(__MESSAGE_COMMAND_SUPPORT__) */

