#include "MMI_features.h" 
#include "custresdef.h"

#if defined(__MSGCMD_SUPPORT__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MSGCMD">

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    //<STRING id="STR_ID_NPPLG_ERROR_TITLE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    //<IMAGE id="IMG_ID_NPPLG_AV_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\NPPlg\\\\Play_normal.png"</IMAGE>
    
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

#ifdef MMS_SUPPORT
	<RECEIVER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" proc="MsgCmd_EvtProcEntry"/>
#endif

    <!--------------------------------------------------Events--------------------------------------------------->
    <EVENT id="EVT_ID_SRV_MC_INCOMING_CALL"/>
    <EVENT id="EVT_ID_SRV_MC_OUTGOING_CALL"/>
    
</APP>

#endif /* defined(__MESSAGE_COMMAND_SUPPORT__) */

