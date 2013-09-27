/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * MMSAppSrvHdlr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
//#include "MMI_include.h"
  #include "MMI_features.h"
#ifdef __MMI_MMS_2__

 #include "MMIDataType.h"  
// #include "kal_non_specific_general_types.h" 
 #include "MMI_inet_app_trc.h"    
 #include "DebugInitDef_Int.h"  
 #include "kal_trace.h"  
 #include "app_mem.h"  
 //#include "UmSrvStruct.h"    
 #include "CustDataRes.h"  
 #include "GlobalResDef.h"    
 #include "mmi_frm_events_gprot.h"   
 #include "mma_api.h"  
 #include "string.h"   
 #include "UmSrvDefs.h" 
 #include "mmi_frm_scenario_gprot.h"   
 #include "kal_release.h"   
 #include "MmsXMLDefSrv.h"    
 #include "app_usedetails.h"  
 #include "gui_data_types.h"    
 #include "SimDetectionStruct.h"  
 #include "wgui_categories_util.h"    
 #include "gui_typedef.h"    
 #include "WAPProfileType.h"  
 #include "mma_struct.h"    
 #include "mmi_frm_timer_gprot.h"  
 #include "TimerEvents.h"  
 #include "Unicodexdcl.h"   
 #include "gui.h"   
 #include "GeneralDeviceGprot.h"
 #include "app_ltlcom.h" 
 #include "app_mine.h"  
 #include "mmi_frm_mem_gprot.h"  
 //#include "app_buff_alloc.h"
 #include "stack_ltlcom.h" 
 #include "mms_adp.h" 
 #include "stack_config.h"    
 #include "FileMgrSrvGProt.h"
 #include "stack_common.h"   
 #include "fs_errcode.h"
 #include "NotificationGprot.h"
 #include "AlertScreen.h"
 #include "mms_sap_struct.h"
 #include "stack_msgs.h"
//#include "CommonScreens.h"
 #include "MMSAppUICommon.h"
 #include "MmsSrvGprot.h"
 #include "MMSAppInterfaceGprot.h"
 #include "MMSAppInterfaceProt.h"
 #include "MMSAppResDef.h"
 #include "mmi_rp_app_umms_mms_def.h"
//#include "inlineCuiGprot.h"
 #include "MMSAppDataManager.h"
 #include "MMSMemoryManagerSrv.h"
 #include "MMSBGSRGprot.h"
 //#include "MMSBGSRProt.h"
 #include "MMSAppSrvHdlr.h"
 #include "MMSAppUIPlugin.h"
 #include "MMSAppScrHdlrEx.h"
 #include "MMSAppOp.h"
 #include "DLAgentDef.h"
 #include "mmi_rp_app_unifiedmessage_def.h"
 #ifdef __MMI_WAP_PROF__
 //#include "WAPProfileGProt.h"
 #include "Custom_events_notify.h"
 #include "UmSrvGProt.h"
 #endif /* __MMI_WAP_PROF__ */ 
 //#include "UnifiedMessageResDef.h"
 //#include "MessagesResourceData.h"
 #include "SmsGuiInterfaceType.h"
 //#include "gpioInc.h"
 #include "SimDetectionGprot.h"
 //#include "Med_global.h"
 //#include "Resource_audio.h"
 #include "MMSAppUtil.h"
 #include "ProfilesSrvGprot.h"
 //#include "CallManagementGprot.h"
 #include "IdleHomescreenGProt.h"
 //#include "UcAppGprot.h"
 #include "MmsSrvExt.h"
 //#include "MMSAppUICallback.h"
 //#include "UCMGProt.h"
 #ifdef __DM_LAWMO_SUPPORT__
 #include "dmuigprot.h"
 #endif

 #include "MmsSrvSendRcv.h"
 #include "IdleAppResDef.h"
 #include "mmi_rp_app_idle_homescreen_def.h"
 #include "MmsSrvProt.h"
 //#include "MsgViewerCuiGProt.h"
 #include "mmi_rp_app_sms_def.h"
 //#include "wgui_categories_mms_viewer.h"
 #include "ModeSwitchSrvGprot.h"

extern void mmi_umms_app_ui_draw_dummy_screen(void);
extern U8 AlmIsTonePlaying(void);

static MMI_BOOL backgroundaudioresume = MMI_FALSE;

static void mmi_umms_app_core_handle_rr(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mms_app_asm_success_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mms_app_asm_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ummsapp_core_mms_app_asm_stop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ummsapp_core_mms_app_asm_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_MEMORY_APP_STOP_CALLBACK);
    /* Handle stop callback  */
    if (mmi_umms_app_if_is_viewer_init())
    {
        mmi_umms_app_if_deinit_viewer();
    }

    mmi_umms_app_sh_delete_umms_screens();
    mmi_umms_app_sh_delete_umms_use_details_screens();
    mmi_umms_app_sh_delete_umms_save_objects_screens();
	/* Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_UMMS, MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_asm_viewer_success_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_asm_viewer_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_ASM_VIEWER_SUCCESS);
    //mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS); 
    if (info == NULL || info->msg_id == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_ASM_VIEWER_SUCCESS_NOUSE);
        /* Viewer has been deinited by application */
        return;
    }
    mmi_umms_app_if_show_viewer_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_asm_viewer_stop_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_asm_viewer_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_ASM_STOP_VIEWER);

    mmi_umms_app_sh_delete_umms_screens();
    mmi_umms_app_sh_delete_umms_use_details_screens();
    mmi_umms_app_sh_delete_umms_save_objects_screens();
    /* De-initialize this application - free adm mem, asm pool, deinit app cntx */
    mmi_umms_app_if_deinit_viewer();

    /* Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MMS_VIEWER, MMI_TRUE);
    return;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mark_several_rsp_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mark_several_rsp_handle(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_entry_mark_several_rsp_struct *msg = (srv_um_entry_mark_several_rsp_struct*) msgrsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_delete_option_screen(srv_mms_convert_umbox_type_to_mma_folder(msg->msg_box_type));
    mmi_umms_app_if_deinit_viewer();
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_scrn_on_folder_id
 * DESCRIPTION
 *  Deletes option screen on basis of folder id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_UMMS_ERROR mmi_umms_app_core_delete_scrn_on_folder_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_msg_notify_callback(U32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U8 error = 0;
    U8 srv_result = 0;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
	mmi_um_iter_viewer_result_struct other_msg_data;
	U8 folder_id;
	void *um_data = NULL;
	mmi_id parent_id=NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELETE_MSG_NOTIFY_CALLBACK, msg_id, result);

    if ((result != MMI_MMS_BGSR_RESULT_OK) && (result != MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND))
    {
        /* Show Error PopUp */
        mmi_umms_app_dtmgr_set_popup_screen_para(
            (U16*) GetString(STR_GLOBAL_ERROR),
            MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
        mmi_umms_app_sh_delete_umms_screens();
    }
    else
    {
        /* Tell MMS Viewer Not to send any Read report req as all the messages will be deleted */
        
           mmi_umms_app_dtmgr_abort_send_read_report(msg_id);

            srv_result = srv_mms_delete_msg(info->msg_id, &error);

            if(srv_result != SRV_MMS_RESULT_OK)
            {
                mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);
                mmi_umms_app_sh_delete_umms_screens();
                return;
            }
            if (error == MMA_RESULT_OK)
            {
#ifndef __MMI_BACKGROUND_CALL__
                
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_GLOBAL_DELETED),
                        MMI_EVENT_EXPLICITLY_DELETED);
                    mmi_umms_app_if_show_display_popup_screen();
                
#else /* __MMI_BACKGROUND_CALL__ */ 
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_DELETED),
                    MMI_EVENT_EXPLICITLY_DELETED);
                mmi_umms_app_if_show_display_popup_screen();
#endif /* __MMI_BACKGROUND_CALL__ */ 
    #ifdef __MMI_MMS_ITERATOR_VIEWER__
		ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
		parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();
	#endif
                mmi_umms_app_sh_delete_umms_screens();
                srv_mms_show_status_icon();
    #ifdef __MMI_MMS_ITERATOR_VIEWER__
		if(ret_val == MMI_UMMS_TRUE)
		{
			mmi_umms_app_dtmgr_handle_action_on_curr_msg(other_msg_data, folder_id, um_data,parent_id);
		}
	#endif
            }
            else
            {
                mmi_umms_app_if_show_error_pop_up(error);
                mmi_umms_app_sh_delete_umms_screens();
            }
    }
}


#ifdef __MMI_MMS_ITERATOR_VIEWER__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_prepare_data_before_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_prepare_data_before_deinit(mmi_um_iter_viewer_result_struct *other_msg_data, U8 *folder_id, void **user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_um_iter_viewer_result_struct *data = NULL;
	mmi_umms_app_dtmgr_option_scr_data_struct *opt_scr_data = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data = (mmi_um_iter_viewer_result_struct*)mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO);
	if(data != NULL)
	{
		memcpy(other_msg_data, data, sizeof(mmi_um_iter_viewer_result_struct));
	}
	else
	{
		return MMI_UMMS_FALSE;
	}
	opt_scr_data = (mmi_umms_app_dtmgr_option_scr_data_struct*)mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
	*folder_id = opt_scr_data->folder_id;
	*user_data = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA);
    return MMI_UMMS_TRUE;
}

#endif /*__MMI_MMS_ITERATOR_VIEWER__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_all_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_all_msg_notify_callback(U32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_all_ind_struct req;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELETE_ALL_NOTIFY_CALLBACK, msg_id, result);
    if ((result != MMI_MMS_BGSR_RESULT_OK) && (result != MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND))
    {
        /* Show Error PopUp */
        mmi_umms_app_dtmgr_set_popup_screen_para(
            (U16*) GetString(STR_GLOBAL_ERROR),
            MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
        mmi_umms_app_sh_delete_umms_screens();
    }
    else
    {
        /* Tell MMS Viewer Not to send any Read report req as all the messages will be deleted */

        mmi_umms_app_dtmgr_abort_send_read_report(0xffffffff);

        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_DUMMY_SCR);

        memset(&req, 0, sizeof(srv_mms_delete_all_ind_struct));
        req.user_data = 0;
        req.call_back = mmi_umms_app_core_delete_all_msg_callback;
        req.msg_type = SRV_UM_MSG_MMS;
        req.msg_box_type = srv_mms_convert_mma_folder_to_umbox_type(info->folder_id);;
        srv_mms_delete_all(&req);
        /*if (GetActiveScreenId() == SCR_ID_UMMS_PROGRESS)
        {
            mmi_umms_app_ui_draw_dummy_screen();
        }
        mmi_umms_app_sh_delete_progress_screen();*/
        mmi_umms_app_sh_go_to_box_list_screen();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_all_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_all_msg_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_show_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_um_delete_folder_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pid             [IN]        
 *  rsp_data        [?]         
 *  para            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_core_um_delete_folder_callback(S32 pid, srv_um_delete_folder_result *rsp_data, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_result *rsp = (srv_um_delete_folder_result*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->error)
    {
        if (mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
			mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES_OPTIONS);

        }

        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_DELETED), MMI_EVENT_EXPLICITLY_DELETED);
        mmi_umms_app_if_show_display_popup_screen();

        mmi_umms_app_sh_delete_progress_screen();
        srv_mms_show_status_icon();
        
    }
    else
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
        mmi_umms_app_sh_delete_progress_screen();
    }
	return MMI_TRUE;
}

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_move_to_archive_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_move_to_archive_msg_notify_callback(U32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U8 error = 0;
    U8 srv_result = 0;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
	mmi_um_iter_viewer_result_struct other_msg_data;
	U8 folder_id;
	void *um_data = NULL;
	mmi_id parent_id=NULL;

#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MV_ARCHIVE_CALL_BACK, msg_id, result);
    if ((result != MMI_MMS_BGSR_RESULT_OK) && (result != MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND))
    {
        /* Show Error PopUp */
        mmi_umms_app_dtmgr_set_popup_screen_para(
            (U16*) GetString(STR_GLOBAL_ERROR),
            MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
        mmi_umms_app_sh_delete_umms_screens();
    }
    else
    {
        srv_result = srv_mms_save_msg(info->msg_id, MMA_FOLDER_ARCHIVE, &error);
        if(srv_result != SRV_MMS_RESULT_OK)
        {
                mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);
                 mmi_umms_app_sh_go_to_box_list_screen();
                return;
		}
    }
        if (error == MMA_RESULT_OK)
    {
        srv_mms_show_status_icon();
           mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_MOVED), MMI_EVENT_SUCCESS);
            mmi_umms_app_if_show_display_popup_screen();
    #ifdef __MMI_MMS_ITERATOR_VIEWER__
		ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
		parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();		
	#endif
         mmi_umms_app_sh_go_to_box_list_screen();
	#ifdef __MMI_MMS_ITERATOR_VIEWER__
		if(ret_val == MMI_UMMS_TRUE)
		{
			mmi_umms_app_dtmgr_handle_action_on_curr_msg(other_msg_data, folder_id, um_data,parent_id);
		}
	#endif
    }
    else
    {   /* Save Failed */
            mmi_umms_app_if_show_error_pop_up(error);
            mmi_umms_app_sh_go_to_box_list_screen();
    }
}


#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_option_scrn_data_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_option_scrn_data_callback(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx_from_uid(user_data);
    mmi_umms_app_dtmgr_option_scr_data_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!cntx)
	{
		MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
		return;
	}
    data = (mmi_umms_app_dtmgr_option_scr_data_struct*) cntx->data;
	ASSERT(data);
	mmi_umms_app_dtmgr_get_option_scr_info_cb(result, msgrsp, user_data);
    if(!cntx)
	{
		MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
		return;
	}
	switch (cntx->state)
    {
        case MMI_UMMS_APP_DTMGR_GET_MSG_INFO_WAIT:
            switch (data->msg_info->msg_type)
            {
                case MMA_MSG_TYPE_READ_REPORT:
                case MMA_MSG_TYPE_DELIVERY_REPORT:
                    mmi_umms_app_if_show_inbox_read_delivery_option();
                    break;
                case MMA_MSG_TYPE_NOTIFICATION:
                    //mmi_umms_app_if_show_inbox_notification_option();
                    break;
                case MMA_MSG_TYPE_MMS:
            #ifdef __MMI_MMS_POSTCARD__
                case MMA_MSG_TYPE_POSTCARD:
            #endif 
                    break;
                case MMA_MSG_TYPE_TEMPLATE:
                    /* mmi_umms_entry_templates_options_screen(); */
                    break;
                case MMA_MSG_TYPE_JAVA:
                    mmi_umms_app_if_show_java_mms_options();
                    break;
                default:
                    MMI_ASSERT(data->msg_info->msg_type);
                    break;
            }
            break;

    }
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_view_option
 * DESCRIPTION
 *  display option according to various data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_handle_view_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(cntx);
    if (cntx->state == MMI_UMMS_APP_DTMGR_MSG_DATA_READY)
    {
        switch (data->msg_info->msg_type)
        {
            case MMA_MSG_TYPE_READ_REPORT:
            case MMA_MSG_TYPE_DELIVERY_REPORT:
                mmi_umms_app_if_show_inbox_read_delivery_option();
                break;
            case MMA_MSG_TYPE_NOTIFICATION:
                mmi_umms_app_if_show_inbox_notification_option();
                break;
            case MMA_MSG_TYPE_MMS:
        #ifdef __MMI_MMS_POSTCARD__
            case MMA_MSG_TYPE_POSTCARD:
        #endif 
                switch (data->folder_id)
                {
                    case MMA_FOLDER_DRAFT:
                        mmi_umms_app_if_show_draft_option();
                        break;
                    case MMA_FOLDER_INBOX:
                        mmi_umms_app_if_show_inbox_mms_option();
                        break;
                    case MMA_FOLDER_OUTBOX:
                        mmi_umms_app_if_show_outbox_option();
                        break;
                    case MMA_FOLDER_SENT:
                        mmi_umms_app_if_show_sent_option();
                        break;
					#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                    case MMA_FOLDER_TEMPLATE:
                    case MMA_FOLDER_USRDEF_TEMPLATE:
                        mmi_umms_app_if_show_mms_template_option();
                        break;
					#endif /*__MMI_MMS_TEMPLATE_SUPPORT__*/
                #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                    case MMA_FOLDER_ARCHIVE:
                        switch (data->msg_info->from_folder)
                        {
                            case MMA_FOLDER_INBOX:
                                mmi_umms_app_if_show_inbox_mms_option();
                                break;
                            case MMA_FOLDER_DRAFT:
                                mmi_umms_app_if_show_draft_option();
                                break;
                            case MMA_FOLDER_SENT:
                                mmi_umms_app_if_show_sent_option();
                                break;
                        }
                        break;
                #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
                }
                break;
        }
    }
    return MMI_UMMS_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_viewer_info_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_viewer_info_callback(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx_from_uid(user_data);
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    srv_mms_process_drm_rsp_struct *rsp_drm = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!cntx)
	{
		MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
		return;
	}
    if (cntx->state == MMI_UMMS_APP_DTMGR_MSG_PARSE_DRM_WAIT)
    {
        rsp_drm = (srv_mms_process_drm_rsp_struct*) msgrsp;
        if (rsp_drm != SRV_MMS_VIEWER_OK)
        {
            /* show error popup */
        }
    }
    mmi_umms_app_dtmgr_get_viewer_data_ready_cb(result, msgrsp, user_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_view
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_handle_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(cntx);
	MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_START_VIEWER_DECISION, data->msg_info->msg_type);
	data->is_already_viewed = MMI_TRUE;
    /* if(cntx->state == MMI_UMMS_APP_DTMGR_MSG_DATA_READY) *//* There can be situations like sending or downloading where data ready is not required as we will just show popups */
    {
        switch (data->msg_info->msg_type)
        {
            case MMA_MSG_TYPE_READ_REPORT:
            case MMA_MSG_TYPE_DELIVERY_REPORT:
                srv_mms_mem_mgr_app_adm_free(cntx->data);
                cntx->data = NULL;
                mmi_umms_app_dtmgr_free_data(MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO);
                mmi_umms_app_if_show_rr_dr_view_screen();
                break;
            case MMA_MSG_TYPE_NOTIFICATION:
			#ifdef __MMI_MMS_ITERATOR_VIEWER__
				if(mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
				{
					mmi_umms_app_if_show_abnormal_view_screen();
					break;
				}
			#endif
                /* if((data->action == MMI_UMMS_OPEN_MMS_VIEWER) || (data->action == MMI_UMMS_OPEN_MMS_VIEWER)) */
            {
                if (MMI_MMS_BGSR_STATUS_DOWNLOADING == mmi_mms_bgsr_get_msg_status(data->msg_id))
                {
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_ID_UMMS_DOWNLOAD_IN_PROGRESS),
                        MMI_EVENT_INFO);
                    mmi_umms_app_if_show_display_popup_screen();
                    mmi_umms_app_sh_delete_umms_screens();
					mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
                }
                else
                {
                    mmi_umms_app_ui_plug_in_download();
                    /* mmi_umms_entry_download_msg(); */
                }
            }
                /* else
                   {
                   mmi_umms_app_if_show_mms_properties_screen();
                   } */
                break;
            case MMA_MSG_TYPE_MMS:
        #ifdef __MMI_MMS_POSTCARD__
            case MMA_MSG_TYPE_POSTCARD:
        #endif 
                if (mmi_mms_bgsr_get_msg_status(data->msg_id) == MMI_MMS_BGSR_STATUS_SENDING)
                {
            #ifdef __MMI_MMS_ITERATOR_VIEWER__
					if(mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
					{
						mmi_umms_app_if_show_abnormal_view_screen();
						return MMI_UMMS_TRUE;
					}
			#endif
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_ID_UMMS_MESSAGE_IS_IN_SEND),
                        MMI_EVENT_PROPLEM);
                    mmi_umms_app_if_show_display_popup_screen();
                    mmi_umms_app_sh_delete_umms_screens();
                    return MMI_UMMS_TRUE;
                }
                if (!data->msg_info->isRead)
                {
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_DRAFT_OPTION);
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SENT_OPTION);
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_MMS_OPTION);
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_ARCHIVE_OPTION);
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_OUTBOX_OPTION);
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION);
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION);
                    mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION);
                }

                if (
            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                       ((data->folder_id == MMA_FOLDER_ARCHIVE) && (data->msg_info->from_folder != MMA_FOLDER_INBOX)) ||
            #endif 
                       ((data->folder_id != MMA_FOLDER_INBOX)
            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                        && (data->folder_id != MMA_FOLDER_ARCHIVE)
            #endif 
                       ) || !(((applib_is_valid_number_unicode((kal_wchar*) data->msg_info->from_address))
                               && (data->msg_info->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER))
                              || ((applib_is_valid_email_address_unicode((kal_wchar*) data->msg_info->from_address))
                                  && (data->msg_info->from_address_type == MMA_ADDR_TYPE_EMAIL)))
                                  || (E_READ_REPORT_SEND_NEVER == srv_mms_retrieval_settings_read_report()))
                {
                    data->msg_info->need_read_report = 0;
                }
#ifdef __DRM_SUPPORT__
				if(srv_mms_viewer_is_media_with_no_rights())
				{
					mmi_umms_app_dtmgr_set_callback_popup_screen_para(
						(UI_string_type) GetString(STR_ID_UMMS_NO_LCNSE_DRM_MEDIA),
						MMI_EVENT_PROPLEM,
						mmi_umms_app_core_handle_rr,
						mmi_umms_app_if_deinit_viewer);

					mmi_umms_app_if_show_display_callback_popup_screen();
					return;
				}
#endif
                mmi_umms_app_core_handle_rr();
                break;
            case MMA_MSG_TYPE_TEMPLATE:
                /* mmi_umms_entry_templates_options_screen(); */
                break;
            case MMA_MSG_TYPE_JAVA:
			#ifdef __MMI_MMS_ITERATOR_VIEWER__
				if(mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
				{
					mmi_umms_app_dtmgr_set_callback_popup_screen_para(
						(UI_string_type) GetString(STR_ID_UMMS_FAILED_TO_DISPLAY_JSR_MMS),
						MMI_EVENT_PROPLEM,
						mmi_umms_app_if_show_abnormal_view_screen,
						mmi_umms_app_sh_delete_umms_screens);

					mmi_umms_app_if_show_display_callback_popup_screen();
				}
			else
			#endif
			{
                mmi_umms_app_if_show_java_mms_options();
			}
			
                break;
            default:
                MMI_ASSERT(data->msg_info->msg_type);
                break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_rr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_umms_app_core_handle_rr(void)
{
	mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
	if (data->msg_info->need_read_report == 1)
                {
                    umms_read_report_enum rr_status = (umms_read_report_enum) srv_mms_retrieval_settings_read_report();
                    U16 str_id = 0;
					MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_START_VIEWER_RR_STATUS, rr_status, 1);
                #if(MMI_MAX_SIM_NUM >= 2)
                    if (rr_status == E_READ_REPORT_SEND_ALWAYS)
                    {
                        if (MMI_FALSE == srv_mms_is_sim_valid((U8) data->msg_info->msg_sim_info))
                        {
                            str_id = STR_ID_UMMS_SIM_INVALID;
                            data->msg_info->need_read_report = 0;
                            mmi_umms_app_dtmgr_set_callback_popup_screen_para(
                                (U16*) GetString(str_id),
                                MMI_EVENT_FAILURE,
                                mmi_umms_app_if_show_viewer_screen,
                                mmi_umms_app_if_deinit_viewer);

                            mmi_umms_app_if_show_display_callback_popup_screen();
							if (data->set_read_mark)
							{
								srv_mms_um_refresh_ind_struct req;
								mmi_umms_app_dtmgr_set_readmark(data->msg_id, MMI_TRUE);
								data->set_read_mark = 0;
								#ifdef __MMI_MMS_ITERATOR_VIEWER__
										req.msg_box_type = data->folder_id;
										srv_mms_um_refresh_msg_list(&req);
								#endif
							}
                            return;
                        }
                    }
                #endif /* ( defined (__MMI_MMS_DUAL_SIM__) || defined (__GEMINI__) || (GEMINI_PLUS > 2)) */ 
                    if (rr_status == E_READ_REPORT_SEND_ON_REQUEST)
                    {
                        mmi_umms_app_dtmgr_set_confirm_screen_para(
                            STR_GLOBAL_YES,
                            IMG_GLOBAL_YES,
                            STR_GLOBAL_NO,
                            IMG_GLOBAL_NO,
                            (U16*) GetString(STR_ID_MMS_VIEWER_SEND_RR_CONFIRM),
                            MMI_EVENT_QUERY,
                            MMI_TRUE,
                     MMI_TRUE,
                            mmi_umms_app_sh_send_read_report_yes,
                            mmi_umms_app_sh_send_read_report_no,
                            NULL,
                            (mmi_ret) mmi_umms_app_sh_viewer_delete_scr_handler);
                        mmi_umms_app_core_send_rr_confirm_or_replace();
                        data->msg_info->need_read_report = 0;
                        data->set_read_mark = 1;
                        return;
                    }
                    else if (rr_status == E_READ_REPORT_SEND_NEVER)
                    {
                        data->msg_info->need_read_report = 0;
                        if (data->set_read_mark)
                        {
                            srv_mms_um_refresh_ind_struct req;
                            mmi_umms_app_dtmgr_set_readmark(data->msg_id, MMI_TRUE);
                            data->set_read_mark = 0;
						#ifdef __MMI_MMS_ITERATOR_VIEWER__
							req.msg_box_type = data->folder_id;
							srv_mms_um_refresh_msg_list(&req);
						#endif

                        }
                    }
                }
                else
                {
                    if (data->set_read_mark)
                    {
                        srv_mms_um_refresh_ind_struct req;
                        mmi_umms_app_dtmgr_set_readmark(data->msg_id, MMI_TRUE);
                        data->set_read_mark = 0;
					#ifdef __MMI_MMS_ITERATOR_VIEWER__
						req.msg_box_type = data->folder_id;
						srv_mms_um_refresh_msg_list(&req);
					#endif
                    }
                }
	mmi_umms_app_core_view_or_replace();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_use_details_list_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_use_details_list_cb(void *msgrsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_use_details_rsp_struct *rsp = (srv_mms_get_use_details_rsp_struct*) msgrsp;
    mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
    mmi_umms_app_dtmgr_use_details_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cntx);
	data = (mmi_umms_app_dtmgr_use_details_struct*) cntx->data;
	ASSERT(data);
    mmi_umms_app_dtmgr_get_use_details_list_cb(msgrsp);
	if(SRV_MMS_GET_USE_DETAILS_RESULT_SUCCESS != rsp->result && 
		SRV_MMS_GET_USE_DETAILS_RESULT_OUT_OF_MEM != rsp->result)
    {
		ASSERT(0);
    }
    
}


#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
  *  mmi_umms_app_core_get_list_info_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_list_info_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_list_info_rsp_struct *msg = (srv_mms_get_list_info_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->result)
    {
        if (msg->msg_number)
        {
            /* call the dtmgr api to set */
            mmi_umms_app_dtmgr_set_get_list_info_rsp_data(msg);
        }
        else
        {
			#ifdef __MMI_MMS_ITERATOR_VIEWER__
				mmi_umms_app_dtmgr_set_refresh_flag(MMI_FALSE);
			#endif
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();

		mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT);
        }
    }
    else
    {
        mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();

		mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_set_setting_rsp_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_set_setting_rsp_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_set_settings_rsp_struct *response_result;
	MMI_BOOL ota_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    response_result = (srv_mms_mma_set_settings_rsp_struct*) rsp_data;
	ota_result = srv_mms_check_send_ota_mms_settings_rsp_to_profile(rsp_data);
	if(result == MMI_TRUE)
	{
		return;
	}
   /* if ((mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS) && (GRP_ID_UMMS_LIST_SETTINGS == mmi_umms_dtmgr_get_group_id()))
    {
        if (response_result->result == MMA_RESULT_OK)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
            mmi_umms_app_if_show_display_popup_screen();

        }
        else
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();

        }
    }*/
	mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
	mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_COMPOSE_SETTINGS);
	mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_RETRIEVAL_SETTINGS);
	mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_SENDING_SETTINGS);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_MMS_PREFER_STORAGE);
#endif
    return;
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_template_msg_info_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_template_msg_info_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL total_result = KAL_TRUE;

    /* U8 loop = 0; */
    srv_mms_get_msg_info_rsp_struct *msg = (srv_mms_get_msg_info_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* progress screen is in history */

    if (total_result == KAL_TRUE)
    {
        if (msg->msg_number)
        {
            mmi_umms_app_dtmgr_set_template_msg_info(rsp_data);
        }
        else
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();
        }
    }
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	if(mmi_umms_app_dtmgr_get_refresh_flag() == MMI_TRUE)
	{
		mmi_umms_app_dtmgr_set_refresh_flag(MMI_FALSE);
        if(mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER ||
		     mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN  ||
		     mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN)
		{
		    mmi_umms_app_core_um_data_ready_cb(NULL);
        }
		else
		{
			mmi_um_iter_viewer_result_struct *data = (mmi_um_iter_viewer_result_struct *)mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO);
			if(data != NULL)
			{
				mmi_umms_app_core_query_indexing_for_template_iter_view(data);
			}
		}
		return;
	}
#endif
if (((mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_PROGRESS_TMPLT,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))) &&
        (mmi_umms_app_dtmgr_get_current_template_type() == MMI_UMMS_DEFAULT_TYPE))
    {
        mmi_frm_node_struct new_node_info;
        new_node_info.id = SCR_ID_UMMS_FWD_EDIT_CLUBBED;
        new_node_info.entry_proc = (mmi_proc_func)mmi_umms_app_if_show_default_template_list;
	    mmi_frm_scrn_replace(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT, &new_node_info);
        mmi_frm_scrn_set_leave_proc(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES, 
            (mmi_proc_func) mmi_umms_app_dtmgr_reset_template_list_data);
        return;
    }
    if ((mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_PROGRESS_TMPLT,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)) &&
        (mmi_umms_app_dtmgr_get_current_template_type() == MMI_UMMS_USER_DEFINED_TYPE))
    {
        mmi_frm_node_struct new_node_info;
        new_node_info.id = SCR_ID_UMMS_TEMPLATES;
        new_node_info.entry_proc = (mmi_proc_func)mmi_umms_app_if_show_user_template_list;
    	mmi_frm_scrn_replace(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT, &new_node_info);
        mmi_frm_scrn_set_leave_proc(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES, (mmi_proc_func) mmi_umms_app_dtmgr_reset_template_list_data);
        return;

    }

    if (msg->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES)
    {
        mmi_umms_app_if_show_default_template_list();
    }

    if (msg->msg_box_type == SRV_UM_MSG_BOX_USRDEF_TEMPLATES)
    {
        mmi_umms_app_if_show_user_template_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_template_delete_all_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_template_delete_all_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_folder_rsp_struct *delete_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_result = (srv_mms_delete_folder_rsp_struct*) rsp_data;
    if (mmi_umms_app_dtmgr_get_template_delete_and_stop_handling() == 0)
    {
        if (delete_result->result == MMI_TRUE)
        {
            mmi_umm_app_dtmgr_handle_delete_all_response();
        }
        else
        {
            mmi_umms_app_dtmgr_set_template_default_creation_progress_check(FALSE);
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE);
            mmi_umms_app_if_show_display_popup_screen();
			mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT);

        }
    }
    else
    {
        mmi_umms_app_dtmgr_set_template_delete_and_stop_handling(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_create_template_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_create_template_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_rsp_struct *create_rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_rsp_data = (srv_mms_create_rsp_struct*) rsp_data;
    if (create_rsp_data->result == MMA_RESULT_OK)
    {
        if (mmi_umms_app_dtmgr_get_template_default_creation_progress_check() == TRUE)
        {
            mmi_umms_app_dtmgr_handle_template_create_rsp(rsp_data);
        }
        else
        {   /* means creation progress is stopped any how */
            if (create_rsp_data->result != MMA_RESULT_FAIL_IN_USB_MODE)
            {
                U8 error = 0;
                mmi_umms_app_dtmgr_delete_all_default_template();
                mmi_umms_app_dtmgr_set_template_delete_and_stop_handling(1);
                
                srv_mms_delete_msg(create_rsp_data->msg_id, &error);
            }
            mmi_umms_app_dtmgr_reset_template_msg();
            return;
        }
    }
    else    /* create rsp is not Ok so delete all the default template messages */
    {
		if ((create_rsp_data->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) && (create_rsp_data->min_fs_space_required != 0))
        {
            mmi_umms_app_sh_display_working_space_popup(create_rsp_data->min_fs_space_required);
        }
        else
        {
        mmi_umms_app_if_show_error_pop_up(create_rsp_data->result);
        }
        mmi_umms_app_ui_plug_in_close_template_create_file_handle();
		mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS_TMPLT);
        mmi_umms_app_dtmgr_reset_template_msg();
        if (create_rsp_data->result != MMA_RESULT_FAIL_IN_USB_MODE)
        {
            mmi_umms_app_dtmgr_delete_all_default_template();
            mmi_umms_app_dtmgr_set_template_delete_and_stop_handling(1);
        }
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_template_save_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_template_save_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_save_rsp_struct *template_save_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    template_save_rsp = (srv_mms_save_rsp_struct*) rsp_data;
    if (template_save_rsp->result[0] == MMA_RESULT_OK)
    {
		/*srv_mms_get_number_status_icon();*/
        srv_mms_msg_update_count_and_status_icon();
        mmi_umms_app_dtmgr_handle_template_save_rsp(rsp_data);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_TEMPLATE_SAVE_STOP);
        /* umms_mmi_show_template_error_msg((U8) msg_rsp->result[0]); */
        mmi_umms_app_if_show_error_pop_up(template_save_rsp->result[0]);
        if (template_save_rsp->result[0] != MMA_RESULT_FAIL_IN_USB_MODE)
        {
                U8 error = 0;
            mmi_umms_app_dtmgr_delete_all_default_template();
            mmi_umms_app_dtmgr_set_template_delete_and_stop_handling(1);
                srv_mms_delete_msg(template_save_rsp->msg_id[0], &error);
        }
    }
}
#endif /*__MMI_MMS_TEMPLATE_SUPPORT__*/

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_get_recent_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_op_op11_struct* op_data =  mmi_umms_op_get_op11_data();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     return srv_mms_get_hs_event();

}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_get_hs_active(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_umms_op_op11_struct* op_data =  mmi_umms_op_get_op11_data();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     return srv_mms_get_hs_active();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_umms_app_core_set_new_mms_arrived(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL *is_new_mms_arrived = (MMI_BOOL *)(evt->user_data);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_op_set_new_mms_arrived(*is_new_mms_arrived);
}   

#endif


#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_get_hs32_active(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_umms_op_op11_hs32_struct* op_data =  mmi_umms_op_get_op11_hs32_data();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     return op_data->hs_active;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_umms_app_core_set_hs32_new_mms_arrived(MMI_BOOL is_new_mms_arrived)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_op_set_hs32_new_mms_arrived(is_new_mms_arrived);
}   
#endif /* __MMI_OP11_HOMESCREEN_0301__ || __MMI_OP11_HOMESCREEN_0302__*/

#if defined(__MMI_OP11_HOMESCREEN__) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_deinit_viewer_and_globals_and_go_to_box_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_deinit_viewer_and_globals_and_go_to_box_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_reset_data();
    mmi_umms_app_if_deinit_viewer();
    mmi_frm_scrn_close_active_id();
}

/* rajbir nmgr  */


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_msg_entry_new_msg_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_msg_entry_new_msg_popup(U8 type, U8 tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_is_phone_lock())
    {
       return;
    }
#endif /*__DM_LAWMO_SUPPORT__*/
    mmi_umms_app_dtmgr_set_infinite_popup_screen_para((U16*)GetString(STR_ID_UMMS_NEW_MMS), IMG_NEW_MESSAGE_NOTIFICATION_MSG, (U16)tone);
    switch (type)
    {
        case MSG_UMMS_NEW_MMS:
            mmi_umms_app_if_show_mms_notification();
            break;
        case MSG_UMMS_NEW_JAVA_MMS:
            mmi_umms_app_if_show_java_mms_notification();
            break;
        default:
            mmi_umms_app_if_show_mms_notification();
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_set_backgroundaudioresume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_set_backgroundaudioresume(MMI_BOOL bgaudioresume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    backgroundaudioresume = bgaudioresume;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_backgroundaudioresume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_get_backgroundaudioresume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return backgroundaudioresume;
}


/*****************************************************************************
 * FUNCTION
  *  mmi_umms_app_core_exit_viewer_application
 * DESCRIPTION
 *  deinit and go back
 * PARAMETERS
 *  result              [IN]        
 *  file_error_type     [IN]        
 *  srv_mms_result_enum(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_exit_viewer_application(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_viewer_event_data_struct *error_type = (srv_mms_viewer_event_data_struct *)(evt->user_data);
	srv_mms_viewer_result_enum result = error_type->result;
	S32 file_error_type = error_type->file_error_type;
    mmi_umms_app_dtmgr_option_scr_data_struct *data = (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data);
    /* Set send RR var to false before exit viewer screen. */
    data->msg_info->need_read_report = MMI_FALSE;
    /*
     * If the category call this fn before calling set readmark
     * * we set readmark to false. This is the scenario when user isn't able
     * * to see a single slide and the viewer aborts, in such a case we don't
     * * want to set msg as read.
     */
    data->set_read_mark = MMI_FALSE;
    /* Warn User and Goback */
    mmi_umms_app_core_viewer_show_error_popup(result, file_error_type);
	mmi_umms_app_sh_delete_option_screen(data->folder_id);
	mmi_umms_app_dtmgr_reset_data();
    mmi_umms_app_if_deinit_viewer();
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_viewer_show_error_popup
 * DESCRIPTION
 *  shows error popup
 * PARAMETERS
 *  result              [IN]        
 *  file_error_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_viewer_show_error_popup(srv_mms_viewer_result_enum result, S32 file_error_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    if (file_error_type)
    {
        mmi_umms_app_dtmgr_set_popup_screen_para(
            (U16*) GetString(srv_fmgr_fs_error_get_string(file_error_type)),
            MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
        return;
    }
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    switch (result)
    {
        case SRV_MMS_VIEWER_PARSER_ERROR:
        case SRV_MMS_VIEWER_FILE_ERROR:
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_MMS_VIEWER_FILE_ERROR),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
            break;
        case SRV_MMS_VIEWER_OUT_OF_MEM:
        case SRV_MMS_VIEWER_OBJ_LIMIT_REACHED:
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_MMS_VIEWER_OUT_OF_MEMORY),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
            break;
		case SRV_MMS_VIEWER_NOT_ENOUGH_MEMORY:
			mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
			break;
        default:
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_ABORTING), MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_mms_status_icon
 * DESCRIPTION
 *  To show MMS indicator icon
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_show_mms_status_icon(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const U32 *status = (U32 *)(evt->user_data);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_SHOW_STATUS_ICON, *status);

    switch (*status)
    {
        case UMMS_STATUS_OFF:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;
        case UMMS_STATUS_NEW_MESSAGE:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            ShowStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;
        case UMMS_STATUS_FULL:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            BlinkStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;

        default:

            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            break;
    }

    /* After calling ShowStatusIcon, HideStatusIcon and AnimateStatusIcon, one can invoke UpdateStatusIcon to refresh the status icon bar,
       but BlinkStatusIcon function will call UpdateStatusIcon internally , one shouldn't call UpdateStatusIcon after it */
    if (*status != UMMS_STATUS_FULL)
    {
        UpdateStatusIcons();
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_check_crnt_selected_msg_for_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_check_crnt_selected_msg_for_update(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 *msg_id = (U32 *)(evt->user_data);
    mma_folder_enum folder_id = 0;
    U16 currScrenID = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info == NULL)
    {
        return MMI_RET_OK;
    }
    folder_id = info->folder_id;
    if ((folder_id == MMA_FOLDER_OUTBOX) || (folder_id == MMA_FOLDER_INBOX) || ((folder_id == MMA_FOLDER_ARCHIVE) &&
                                                                                (info->msg_info->from_folder ==
                                                                                 MMA_FOLDER_INBOX)))
    {
        if (*msg_id == info->msg_id)
        {
            if (mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_MESSAGE_STATUS,MMI_FRM_NODE_ALL_FLAG))
            {
               
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_ID_UMMS_UPDATING_STATUS),
                        MMI_EVENT_INFO);
                    mmi_umms_app_if_show_display_popup_screen();
                mmi_umms_app_sh_delete_umms_screens();
                mmi_umms_app_sh_delete_umms_use_details_screens();
                mmi_umms_app_sh_delete_umms_save_objects_screens();
            }
            else
            {
                if (NULL == info->bgsr_msg_info)
                {
                    info->bgsr_msg_info =
                        (mmi_mms_bgsr_msg_info_struct*)
                        srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_mms_bgsr_msg_info_struct));
					ASSERT(info->bgsr_msg_info);
                    memset(info->bgsr_msg_info, 0, sizeof(mmi_mms_bgsr_msg_info_struct));
                }
            
                mmi_mms_bgsr_get_msg_info(
                    info->msg_id,
                    info->bgsr_msg_info,
                    mmi_umms_app_sh_get_msg_info_from_bgsr_callback_for_update,
                    info->msg_info->storage_location,
                    info->msg_info->msg_type);
             
            }

        }
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_check_crnt_selected_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_check_crnt_selected_msg(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 *msg_id = (U32 *)(evt->user_data);
    mma_folder_enum folder_id = 0;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info == NULL)
    {
        return;
    }
    folder_id = info->folder_id;
    if ((folder_id == MMA_FOLDER_OUTBOX) || (folder_id == MMA_FOLDER_INBOX) || ((folder_id == MMA_FOLDER_ARCHIVE) &&
                                                                                (info->msg_info->from_folder ==
                                                                                 MMA_FOLDER_INBOX)))
    {
        if (*msg_id == info->msg_id)
        {
             {
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_ID_UMMS_UPDATING_STATUS),
                        MMI_EVENT_INFO);
                    mmi_umms_app_if_show_display_popup_screen();
                }
            mmi_umms_app_sh_delete_umms_screens();
            mmi_umms_app_sh_delete_umms_use_details_screens();
            mmi_umms_app_sh_delete_umms_save_objects_screens();
			mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_info_from_bgsr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_msg_info_from_bgsr_callback(U32 msg_id, mmi_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MSG_INFO_CALLBACK, msg_id, msg_info->status, msg_info->ntt);
    info->bgsr_msg_info->status = msg_info->status;
    info->bgsr_msg_info->ntt = msg_info->ntt;
    info->bgsr_msg_info->result = msg_info->result;
    if (info->bgsr_msg_info->result == MMI_MMS_BGSR_RESULT_FAIL_NOT_READY)
    {
        mmi_umms_app_sh_return_to_um_list();
        return;
    }
    if ((info->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION) &&
        (info->action == MMI_UMMS_OPEN_MMS_VIEWER ))
    {
        if (MMI_MMS_BGSR_STATUS_DOWNLOADING == mmi_mms_bgsr_get_msg_status(info->msg_id))
        {
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_DOWNLOAD_IN_PROGRESS),
                MMI_EVENT_INFO);
            mmi_umms_app_if_show_display_popup_screen();
            mmi_umms_app_sh_delete_umms_screens();
			mmi_frm_group_close(mmi_umms_dtmgr_get_group_id());
        }
        else
        {
            mmi_umms_app_ui_plug_in_download();
        }
    }
    else
    {
       
        if ((info->folder_id == MMA_FOLDER_OUTBOX) &&
                 (mmi_mms_bgsr_get_msg_status(info->msg_id) == MMI_MMS_BGSR_STATUS_SENDING)
                  && (info->action == MMI_UMMS_OPEN_MMS_VIEWER))
        {
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_ID_UMMS_MESSAGE_IS_IN_SEND),
                        MMI_EVENT_PROPLEM);
                    mmi_umms_app_if_show_display_popup_screen();
                    mmi_umms_app_sh_delete_umms_screens();
                    return ;
        }
        else
        {
        mmi_umms_app_core_show_option();
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->msg_info->msg_type)
    {
        case MMA_MSG_TYPE_READ_REPORT:
        case MMA_MSG_TYPE_DELIVERY_REPORT:
            mmi_umms_app_if_show_inbox_read_delivery_option();
            break;
        case MMA_MSG_TYPE_NOTIFICATION:
            mmi_umms_app_if_show_inbox_notification_option();
            break;
        case MMA_MSG_TYPE_JAVA:
            mmi_umms_app_if_show_java_mms_options();
            break;
        case MMA_MSG_TYPE_MMS:
    #ifdef __MMI_MMS_POSTCARD__
        case MMA_MSG_TYPE_POSTCARD:
    #endif 
            switch (data->folder_id)
            {
                case MMA_FOLDER_DRAFT:
                    mmi_umms_app_if_show_draft_option();
                    break;
                case MMA_FOLDER_INBOX:
                    mmi_umms_app_if_show_inbox_mms_option();
                    break;
                case MMA_FOLDER_OUTBOX:
                    mmi_umms_app_if_show_outbox_option();
                    break;
                case MMA_FOLDER_SENT:
                    mmi_umms_app_if_show_sent_option();
                    break;
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                case MMA_FOLDER_TEMPLATE:
                case MMA_FOLDER_USRDEF_TEMPLATE:
                    mmi_umms_app_if_show_mms_template_option();
                    break;
#endif
            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                case MMA_FOLDER_ARCHIVE:
                    switch (data->msg_info->from_folder)
                    {
                        case MMA_FOLDER_INBOX:
                            mmi_umms_app_if_show_inbox_mms_option();
                            break;
                        case MMA_FOLDER_DRAFT:
                            mmi_umms_app_if_show_draft_option();
                            break;
                        case MMA_FOLDER_SENT:
                            mmi_umms_app_if_show_sent_option();
                            break;
                    }
                    break;
            #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_csk_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_csk_view(U32 msg_id, mmi_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info = mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MSG_INFO_CALLBACK_CSK_VIEW, msg_id, msg_info->status, msg_info->ntt);
    if (info->bgsr_msg_info->result == MMI_MMS_BGSR_RESULT_FAIL_NOT_READY)
    {
        mmi_umms_app_sh_return_to_um_list();
        return;
    }
    mmi_umms_app_core_handle_view();
}




#ifdef __MMI_MMS_TEMPLATE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_save_template_file_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_save_template_file_callback(S32 copy_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_fmt_copy_rsp_strcut *msgPtr;
    mmi_umms_app_dtmgr_option_scr_data_struct *msg_info =  NULL;
        
    srv_mms_create_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

      msg_info = (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

	if(msg_info == NULL)
	{
			return;
	}
    //msgPtr = (mmi_fmt_copy_rsp_strcut*) info;
    
    if (copy_result >= 0)
    {
        memset(&msg_req, 0, sizeof(srv_mms_create_req_struct));
        msg_req.msg_id = 0;
        msg_req.app_id = MMA_APP_ID_TEMPLATE;
        msg_req.mode = MMA_MODE_UPLOAD;
        mmi_ucs2cpy((PS8) msg_req.msg_file_path, (PS8) msg_info->file_path);
        msg_req.xml_size = 0;
        msg_req.user_data = 0;
        msg_req.call_back = mmi_umms_app_core_create_template_file_callback;
        srv_mms_create(&msg_req);
     }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_TEMPLATE_SAVE_FILE_CALLBACK, copy_result);

        if (copy_result == FS_APP_QUOTA_FULL)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();

        }
        else
        {

            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(srv_fmgr_fs_error_get_string(copy_result)),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();

        }

		mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
    }
	srv_mms_mem_mgr_app_adm_free(msg_info->msg_path);
        msg_info->msg_path = NULL;
	srv_mms_mem_mgr_app_adm_free(msg_info->file_path);
	msg_info->file_path = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_create_template_file_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_create_template_file_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_save_req_struct msg_req;
    srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FS_Close(g_user_defined_create.file_handle); */
    if (msg_rsp->result != MMA_RESULT_OK)
    {

        /* TBD : Delete this file here */
        if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
        {
            if ((msg_rsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) && (msg_rsp->min_fs_space_required != 0))
            {
                mmi_umms_app_sh_display_working_space_popup(msg_rsp->min_fs_space_required);
            }
            else
            {
                mmi_umms_app_if_show_error_pop_up(msg_rsp->result);
            }
			mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
        }
        else
        {
            mmi_umms_app_sh_delete_umms_screens();
            /* mmi_umms_go_to_box_list_screen(); */
        }
        return;
    }
    else
    {

        memset(&msg_req, 0, sizeof(srv_mms_save_req_struct));

        msg_req.msg_id[0] = msg_rsp->msg_id;
        msg_req.no_of_msg = 1;
        msg_req.box = MMA_FOLDER_USRDEF_TEMPLATE;
        msg_req.app_id = MMA_APP_ID_TEMPLATE;
        msg_req.user_data = 0;
        msg_req.call_back = mmi_umms_app_core_save_template_callback;
        srv_mms_save(&msg_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_save_template_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_save_template_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_save_rsp_struct *msg_rsp = (srv_mms_save_rsp_struct*) rsp_data;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
	mmi_um_iter_viewer_result_struct other_msg_data;
	U8 folder_id;
	void *um_data = NULL;
	 mmi_id parent_id=NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
    {
        /* TBD : Delete user defined file here  */
        if (msg_rsp->result[0] == MMA_RESULT_OK)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
            mmi_umms_app_if_show_display_popup_screen();
        }
        else
        {
            mmi_umms_app_if_show_error_pop_up(msg_rsp->result[0]);
        }
		mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);

    }
    if (msg_rsp->result[0] != MMA_RESULT_OK)
    {
        if (msg_rsp->result[0] != MMA_RESULT_FAIL_IN_USB_MODE)
        {
                U8 error = 0;
                mmi_umms_app_dtmgr_delete_all_default_template();
                mmi_umms_app_dtmgr_set_template_delete_and_stop_handling(1);
                srv_mms_delete_msg(msg_rsp->msg_id[0], &error);
        }
    }
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
	parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();
#endif
    mmi_umms_app_sh_delete_umms_screens();
    srv_mms_show_status_icon();
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	if(ret_val == MMI_UMMS_TRUE)
	{
		mmi_umms_app_dtmgr_handle_action_on_curr_msg(other_msg_data, folder_id, um_data,parent_id);
	}
#endif
    return;

}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_pre_display_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_pre_display_message(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (/*(mmi_frm_scrn_get_active_id() != SCR_ID_UMMS_PROGRESS) || !(mmi_mms_bgsr_is_ready()) ||*/
        (mmi_mms_bgsr_get_msg_status(info->msg_id) == MMI_MMS_BGSR_STATUS_SENDING))
    {
        result = MMI_FALSE;
    }

    /*if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
    {*/
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DISPLAY_MESSAGE);
		if(info->bgsr_msg_info == NULL)
        {
        info->bgsr_msg_info =
            (mmi_mms_bgsr_msg_info_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(mmi_mms_bgsr_msg_info_struct));
		ASSERT(info->bgsr_msg_info);
		}
        memset(info->bgsr_msg_info, 0, sizeof(mmi_mms_bgsr_msg_info_struct));
        mmi_mms_bgsr_get_msg_info(
            info->msg_id,
            info->bgsr_msg_info,
            mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_pre_display_msg,
            info->msg_info->storage_location,
            info->msg_info->msg_type);
    /*}
    else
    {
		mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS);
        mmi_umms_app_dtmgr_reset_data();
    }*/

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_pre_display_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_pre_display_msg(
        U32 msg_id,
        mmi_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MSG_INFO_CALLBACK, msg_id, msg_info->status, msg_info->ntt);
    info->bgsr_msg_info->status = msg_info->status;
    info->bgsr_msg_info->ntt = msg_info->ntt;
    info->bgsr_msg_info->result = msg_info->result;

    if (info->bgsr_msg_info->result == MMI_MMS_BGSR_RESULT_FAIL_NOT_READY)
    {
        mmi_umms_app_sh_return_to_um_list();
        return;
    }
    if (info->bgsr_msg_info->status == MMI_MMS_BGSR_STATUS_SENDING)
    {
        mmi_umms_app_ui_draw_dummy_screen();
        mmi_umms_app_sh_delete_progress_screen();

		if(info->action == MMI_UMMS_OPEN_MMS_VIEWER)
        {
            mmi_umms_app_dtmgr_set_popup_screen_para(
                (U16*) GetString(STR_ID_UMMS_READ_REPORT_IS_IN_SEND),
                MMI_EVENT_PROPLEM);
            mmi_umms_app_if_show_display_popup_screen();
            mmi_umms_app_sh_delete_umms_screens();
            return;
        }
        else
        {
            mmi_umms_app_core_show_option();
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_MMS_POSTCARD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* __MMI_MMS_POSTCARD__ */ 
/* under construction !*/
    #endif /* __MMI_MMS_POSTCARD__ */ 
/* under construction !*/
#endif /* 0 */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_display_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_display_message(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_umms_app_sh_show_screen_based_on_msg_status(msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_state_from_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_get_msg_state_from_mma(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    mmi_umms_app_dtmgr_msg_state_enum state_of_msg_in_mma = MMI_UMMS_APP_DTMGR_MSG_STATE_ALL;
    MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->msg_info->result == MMA_RESULT_OK)
    {

    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_GET_MSG_STATE_FRM_MMA);
            if ((data->msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION) &&
                (mmi_mms_bgsr_get_msg_status(data->msg_id) == MMI_MMS_BGSR_STATUS_DOWNLOADING))
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MSG_STATE_FROM_MMA_IS_NOTIFICATION_DWNL_WAITING_DWNLD);
                state_of_msg_in_mma = MMI_UMMS_APP_DTMGR_MSG_STATE_NOTIFICATION_DOWNLOADING;
            }
            if ((data->msg_info->msg_type == MMA_MSG_TYPE_MMS) &&
                ((data->folder_id == MMA_FOLDER_INBOX) ||
                 ((data->folder_id == MMA_FOLDER_ARCHIVE) && (data->msg_info->from_folder == MMA_FOLDER_INBOX))))
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MSG_STATE_FROM_MMA_IS_NORMAL_MMS_INBOX_ARCHIVE);
                state_of_msg_in_mma = MMI_UMMS_APP_DTMGR_MSG_STATE_NORMAL_MMS_IN_INBOX;
            }
            if (((data->msg_info->msg_type == MMA_MSG_TYPE_MMS) &&
                 (data->folder_id == MMA_FOLDER_OUTBOX)) &&
                (mmi_mms_bgsr_get_msg_status(data->msg_id) == MMI_MMS_BGSR_STATUS_SENDING))
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MSG_STATE_FROM_MMA_IS_OUTBOX_SENDING_WAITING_SENDING);
                state_of_msg_in_mma = MMI_UMMS_APP_DTMGR_MSG_STATE_SENDING_OUTBOX;
            }
            switch (state_of_msg_in_mma)
            {
                case MMI_UMMS_APP_DTMGR_MSG_STATE_SENDING_OUTBOX:
                case MMI_UMMS_APP_DTMGR_MSG_STATE_NOTIFICATION_DOWNLOADING:
                    mmi_umms_app_core_display_message(data->msg_id);
                    return MMI_UMMS_FALSE;
                case MMI_UMMS_APP_DTMGR_MSG_STATE_NORMAL_MMS_IN_INBOX:
                    ret_val = mmi_umms_app_core_pre_display_message(data->msg_id);
                    return ret_val;
                default:
                    ret_val = MMI_UMMS_TRUE;
                    break;
            }
       
        
    }
    else
    {
        if (data->msg_info->result == MMA_RESULT_FAIL_FILE_CORRUPTED)
        {
     #ifdef __MMI_MMS_ITERATOR_VIEWER__
			if(mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
			{
				mmi_umms_app_if_show_abnormal_view_screen();
				return;
			}
	 #endif
            mmi_umms_app_sh_show_corrupt_and_delete();
            mmi_umms_app_sh_delete_progress_screen();
        }
		/*need new MMA enum for fail result*/
		else if(data->msg_info->result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE) 
		{
	 #ifdef __MMI_MMS_ITERATOR_VIEWER__
			if(mmi_umms_app_dtmgr_get_iterator_status() == MMI_TRUE)
			{
				mmi_umms_app_if_show_abnormal_view_screen();
				return;
			}
	 #endif
			mmi_umms_app_sh_show_unsupported_and_delete();
            mmi_umms_app_sh_delete_progress_screen();
		}
        else
        {
            mmi_umms_app_if_show_error_pop_up(data->msg_info->result);
            mmi_umms_app_sh_delete_progress_screen();
        }
        return MMI_UMMS_FALSE;
    }
    return ret_val;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_display_invalid_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_display_invalid_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INVALID), MMI_EVENT_FAILURE);
    mmi_umms_app_if_show_display_popup_screen();
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_progress_screen_with_no_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_progress_screen_with_no_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_ui_plug_in_show_progress_screen_with_no_history();
}

#ifdef __MMI_URI_AGENT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mms_display_uri_confirm_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_mms_display_uri_confirm_popup(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_umms_dtmgr_set_group_id( GRP_ID_UMMS_LIST_MMS_OPTIONS);
    mmi_umms_app_dtmgr_set_parent_grp_id(GRP_ID_ROOT);
    mmi_umms_app_dtmgr_set_confirm_screen_para(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U16*) GetString(STR_ID_UMMS_SEND_MMS_CONFIRM),
        MMI_EVENT_QUERY,
        MMI_FALSE,
                     MMI_TRUE,
        srv_mms_launch_write_msg,
        srv_mms_send_call_back_to_uri_agnt,
        srv_mms_uri_exit_hndlr_for_confirm_popup,
         NULL);
        mmi_umms_app_if_show_display_confirm_screen();
        return MMI_RET_OK;

}
#endif /* __MMI_URI_AGENT__ */ 

#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_update_use_details_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_update_use_details_list(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_umms_app_dtmgr_context *cntx = mmi_umms_app_dtmgr_get_current_cntx(MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST);
	mmi_umms_app_dtmgr_use_details_struct *data = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!cntx)
	{
		MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DTMGR_APP_ALREADY_DEINIT);
		return MMI_RET_OK;
	}
	data = (mmi_umms_app_dtmgr_use_details_struct*) cntx->data;
	ASSERT(data);
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_USE_NUMBER
        || mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_USE_EMAIL || mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_USE_URL)
    {
        mmi_umms_app_ui_draw_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
	return MMI_RET_OK;
}
#endif /*__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__*/
#ifdef __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_updated_profile_send_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id                  [IN]        
 *  app_id                  [IN]        
 *  profile_id              [IN]        
 *  configure_dtcnt_rsp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_updated_profile_send_callback(
        mmi_wap_prof_sim_id_enum sim_id,
        mmi_wap_prof_app_id_enum app_id,
        U8 profile_id,
        mmi_wap_prof_result_enum configure_dtcnt_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(data == NULL)
	{
		return;
	}
    if (MMI_WAP_PROF_SUCCESS == configure_dtcnt_rsp)
    {
        mmi_umms_app_plug_in_pre_entry_send_msg();
    }
    /* else
       {
       mmi_frm_scrn_close_active_id();
       } */
}


void mmi_umms_app_core_profile_download_callback(mmi_wap_prof_sim_id_enum sim_id,mmi_wap_prof_app_id_enum app_id,U8 profile_id,mmi_wap_prof_result_enum configure_dtcnt_rsp)
{
	mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

	if(data == NULL)
	{
		return;
	}

	if (MMI_WAP_PROF_SUCCESS == configure_dtcnt_rsp)
    {
        mmi_umms_app_ui_plug_in_download();
    }
}
#endif /* __MMI_WAP_PROF_CFG_DTCNT_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_view_or_replace
 * DESCRIPTION
 *  View message or replace history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_view_or_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS) 
    {
        mmi_umms_app_if_show_viewer_screen();
        return;
    }
    else
    {
        if (MMI_TRUE == mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_PROGRESS,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_ret result;
			mmi_frm_node_struct new_node_info;

			new_node_info.id = SCR_ID_UMMS_MMS_VIEWER;
			new_node_info.entry_proc = (mmi_proc_func)mmi_umms_app_if_show_viewer_screen;
			result = mmi_frm_scrn_replace(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS, &new_node_info);
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_VIEWER_REPLACE_SUCCESS);
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_VIEWER_REPLACE_FAIL);
            mmi_umms_app_if_deinit_viewer();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_send_rr_confirm_or_replace
 * DESCRIPTION
 *  Entry Send RR Confirmation or replace history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_send_rr_confirm_or_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
    {
        mmi_umms_app_if_show_display_confirm_screen();
    }
    else
    {
        if (MMI_TRUE == mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_PROGRESS,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_ret result;
            mmi_frm_node_struct new_node_info;
            new_node_info.id = SCR_ID_UMMS_CONFIRM;
            new_node_info.entry_proc = (mmi_proc_func)mmi_umms_app_if_show_display_confirm_screen;
		    result = mmi_frm_scrn_replace(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_PROGRESS, &new_node_info);
			mmi_frm_scrn_set_attribute(mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_CONFIRM, MMI_SCRN_ATTRIB_SMALL_SCRN);
            /* it will depend upon what user select on LSK/RSK , by default no rr MAUI_01868604 */
            data->msg_info->need_read_report = 0;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_VIEWER_RR_CONFIRM_REPLACE_SUCCESS);
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CORE_VIEWER_RR_CONFIRM_REPLACE_FAILED);
            mmi_umms_app_if_deinit_viewer();
        }
    }
}

/*  memory card */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_change_storage_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_handle_change_storage_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_mma_change_msg_storage_rsp_struct *msg = (wap_mma_change_msg_storage_rsp_struct *)evt->user_data;
    mmi_umms_app_dtmgr_option_scr_data_struct *info =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);
    U16 str_id = 0;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
	mmi_um_iter_viewer_result_struct other_msg_data;
	U8 folder_id;
	void *um_data = NULL;
	mmi_id parent_id=NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_PROGRESS)
    {
        if (msg->result == MMA_RESULT_OK)
        {
            switch (msg->action_type)
            {
                case MMA_MMS_STORAGE_ACTION_COPY_MMS:
                    if (info->msg_info->storage_location == MMA_MSG_STORAGE_PHONE)
                    {
                        str_id = STR_ID_UMMS_COPY_TO_CARD_DONE;
                    }
                    if (info->msg_info->storage_location == MMA_MSG_STORAGE_CARD1)
                    {
                        str_id = STR_ID_UMMS_COPY_TO_PHONE_DONE;
                    }
                    break;

                case MMA_MMS_STORAGE_ACTION_MOVE_MMS:
                    if (info->msg_info->storage_location == MMA_MSG_STORAGE_PHONE)
                    {
                        str_id = STR_ID_UMMS_MOVE_TO_CARD_DONE;
                    }
                    if (info->msg_info->storage_location == MMA_MSG_STORAGE_CARD1)
                    {
                        str_id = STR_ID_UMMS_MOVE_TO_PHONE_DONE;
                    }
                    break;

                default:
                    break;
            }
            mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(str_id), MMI_EVENT_SUCCESS);
            mmi_umms_app_if_show_display_popup_screen();
        }
        else
        {
            mmi_umms_app_if_show_error_pop_up(msg->result);
			srv_mms_msg_update_count_and_status_icon();
			mmi_umms_app_sh_delete_progress_screen();
			mmi_umms_app_sh_go_to_box_list_screen();
			return MMI_RET_OK;
        }
    }
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
	parent_id = mmi_umms_app_dtmgr_get_parent_grp_id();
#endif
    srv_mms_msg_update_count_and_status_icon();
    mmi_umms_app_sh_delete_progress_screen();
    mmi_umms_app_sh_go_to_box_list_screen();
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	if(ret_val == MMI_UMMS_TRUE)
	{
		mmi_umms_app_dtmgr_handle_action_on_curr_msg(other_msg_data, folder_id, um_data,parent_id);
	}
#endif
	return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_sd_card_plug_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_handle_sd_card_plug_out(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 storage_type = mmi_umms_app_dtmgr_get_prefered_storage(); */
    /* api for get_current_msg_storage */
    
    mmi_umms_app_dtmgr_option_scr_data_struct *data =
        (mmi_umms_app_dtmgr_option_scr_data_struct*)
        mmi_umms_app_dtmgr_get_data(MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_reset_mem_card_total_msg();
	if(mmi_frm_scrn_is_present(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD,MMI_FRM_NODE_ALL_FLAG))
	{
        mmi_frm_scrn_close(mmi_umms_dtmgr_get_group_id(),SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD);
	}
    if (data == NULL)
    {
        return MMI_RET_OK;
    }
    if (data->msg_info->storage_location == MMA_MSG_STORAGE_CARD1)
    {

        mmi_umms_app_if_deinit_viewer();
        mmi_umms_app_sh_delete_umms_screens();
        mmi_umms_app_sh_delete_umms_use_details_screens();
        mmi_umms_app_sh_delete_umms_save_objects_screens();
    }
	return MMI_RET_OK;
		
	

}

/* memory card  */
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_update_template_list_after_phone_suite_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_update_template_list_after_phone_suite_delete(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_ITERATOR_VIEWER__
	MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
	mmi_um_iter_viewer_result_struct other_msg_data;
	U8 folder_id;
	void *um_data = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_umms_app_dtmgr_get_userdef_template_del_from_phone_suite_flag() == MMI_TRUE)
    {
        /* userdefined template list is open */
        if ((mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_TEMPLATES))
        {
            mmi_umms_app_ui_draw_dummy_screen();
			mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES);
            mmi_umms_app_if_show_user_template_list();
        }
        /* this is to update the hint */
        else if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED)
        {
            mmi_umms_app_ui_draw_dummy_screen();
			mmi_frm_scrn_close (mmi_umms_dtmgr_get_group_id(), SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED);
            mmi_umms_app_show_template_menu();
        }
        else if (mmi_frm_scrn_is_present(GRP_ID_UMMS_LIST_TEMPLATES, SCR_ID_UMMS_TEMPLATES,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
		#ifdef __MMI_MMS_ITERATOR_VIEWER__
			ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
			if(ret_val == MMI_UMMS_TRUE)
			{
				if(other_msg_data.total_number > 1)/*In case this is last template to be deleted*/
									   /*, dont refresh screen as while goin back it will auto refresh*/
				{
					mmi_umms_app_dtmgr_reset_userdef_template_del_from_phone_suite_flag();
					mmi_umms_app_dtmgr_set_refresh_flag(MMI_TRUE);
					mmi_umms_app_dtmgr_refresh_templates();
				return MMI_RET_OK;
			}
			}
			
		#endif
			mmi_umms_app_dtmgr_reset_template_list_data();
            //mmi_umms_app_if_show_user_template_list();
        }
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_bootup_init_template_folder_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_bootup_init_template_folder_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_umms_app_dtmgr_init_template_folder(MMI_TRUE);
}

#endif

MMI_RET mmi_umms_app_core_bootup_init(mmi_event_struct *evt)
{
	#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
	mmi_umms_app_core_bootup_init_template_folder_data();
	#endif

	#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
    #endif

    #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_umms_op_init_hs32_context();
    mmi_umms_op_reset_op11_hs32_data();
	#endif

	#ifdef __MMI_OP12_TOOLBAR__
		mmi_umms_op_init_tb_context();
        mmi_umms_op_reset_op12_data();
	#endif
#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_MMS, MMI_DMUI_MO_TYPE_LAWMO_LOCK, mmi_umms_app_core_mo_type_lawmo_lock_callback_hdlr) < 0)
    {
	/* error handling or assert */
    }
    if (mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_MMS, MMI_DMUI_MO_TYPE_LAWMO_WIPE, mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr) < 0)
    {
	/* error handling or assert */
    }
#endif /*__DM_LAWMO_SUPPORT__*/
	srv_mms_mem_mgr_init_app_asm_pool(
        APPLIB_MEM_AP_ID_UMMS,
        mmi_ummsapp_core_mms_app_asm_stop_callback,
        mmi_umms_app_core_mms_app_asm_success_callback);

    srv_mms_mem_mgr_init_viewer_asm_pool(
        APPLIB_MEM_AP_ID_MMS_VIEWER,
        mmi_umms_app_core_asm_viewer_stop_callback,
        mmi_umms_app_core_asm_viewer_success_callback);
	return MMI_RET_OK;

}

MMI_RET mmi_umms_app_core_wap_ready_hdlr(mmi_event_struct *evt)
{
	mmi_umms_op_wap_ready_hdlr();
	return MMI_RET_OK;
}

#ifdef __DM_LAWMO_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr
 * DESCRIPTION
 *  Call Back from DM to wipe all MMS Data
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mo_type_lawmo_lock_callback_hdlr(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (app_id == MMI_DMUI_APP_ID_MMS)
    {

        if(!srv_mms_is_ready())
        {
            switch (cmd)
            {
                case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
                 {
                    mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK, MMI_DMUI_RESULT_SUCCESS);
                 }
                 break;
                case MMI_DMUI_CMD_LAWMO_UNLOCK:
                 {
                     mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_UNLOCK, MMI_DMUI_RESULT_SUCCESS);
                 }
                 break;

                default:
                     break;
            }
            return;
        }


        switch (cmd)
        {
            case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
                 {
                    
                     srv_mms_stop_object_indication_timer();
                     srv_mms_refresh_profile_settings(MMI_SIM1);
          #if(MMI_MAX_SIM_NUM >= 2)
			srv_mms_refresh_profile_settings(MMI_SIM2);
	    #endif /* defined (__MMI_MMS_DUAL_SIM__) || (defined (__GEMINI__) */  
			#if(MMI_MAX_SIM_NUM >= 3)
			srv_mms_refresh_profile_settings(MMI_SIM3);
			#endif /* (defined(GEMINI_PLUS) && (GEMINI_PLUS > 2)) */
			
			#if(MMI_MAX_SIM_NUM >= 4)
			srv_mms_refresh_profile_settings(MMI_SIM4);
			#endif /* (defined(GEMINI_PLUS) && (GEMINI_PLUS > 3)) */
          
                     mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK, MMI_DMUI_RESULT_SUCCESS);
                     break;
                 }
            case MMI_DMUI_CMD_LAWMO_UNLOCK:
                 {
                     srv_mms_start_object_indication_timer();
                     mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_UNLOCK, MMI_DMUI_RESULT_SUCCESS);
                 }
                 break;

             default:
                     break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr
 * DESCRIPTION
 *  Call Back from DM to wipe all MMS Data
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id == MMI_DMUI_APP_ID_MMS)
    {
        switch (cmd)
        {
            case MMI_DMUI_CMD_LAWMO_WIPE:
                 {
                     if(!srv_mms_is_ready())
                     {
#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
                         srv_mms_delete_all_obj_ind_msg();
#endif /*__MMI_MMS_MMA_MMS_OBJECT_IND__*/
                         mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_SUCCESS);
                         return;
                     }
                    /*Call BGSR API with callback*/
                     srv_mms_refresh_profile_settings(MMI_SIM1);
          #if(MMI_MAX_SIM_NUM >= 2)
			srv_mms_refresh_profile_settings(MMI_SIM2);
	    #endif /* defined (__MMI_MMS_DUAL_SIM__) || (defined (__GEMINI__) */  
			#if(MMI_MAX_SIM_NUM >= 3)
			srv_mms_refresh_profile_settings(MMI_SIM3);
			#endif /* (defined(GEMINI_PLUS) && (GEMINI_PLUS > 2)) */
			
			#if(MMI_MAX_SIM_NUM >= 4)
			srv_mms_refresh_profile_settings(MMI_SIM4);
			#endif /* (defined(GEMINI_PLUS) && (GEMINI_PLUS > 3)) */

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
                     srv_mms_delete_all_obj_ind_msg();
#endif /*__MMI_MMS_MMA_MMS_OBJECT_IND__*/
                     mmi_mms_bgsr_law_mo_wipe_notify();
                     break;
                 }
             default:
                     break;
         }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_bgsr_free_mms_data_for_wipe_callback
 * DESCRIPTION
 *  Call Back from BGSR after trying cancelling any send receive MMS and  
 *  resetting read report flag at MMA end
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_bgsr_free_mms_data_for_wipe_callback(U8 result)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 folder_id = 0;
    srv_mms_delete_folder_req_struct req;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder_id = 
    SRV_UM_MSG_BOX_INBOX |
    SRV_UM_MSG_BOX_UNSENT |
    SRV_UM_MSG_BOX_SENT |
    SRV_UM_MSG_BOX_DRAFT |
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SRV_UM_MSG_BOX_ARCHIVE |
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    SRV_UM_MSG_BOX_PREDEF_TEMPLATES |
    SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
    
    
    req.user_data = 0;
    req.msg_type = SRV_UM_MSG_MMS;
    req.msg_box_type = folder_id;
    req.app_id = MMA_APP_ID_MMS_LAWMO;
    req.call_back = mmi_umms_app_core_remove_all_mms_rsp;
    srv_mms_delete_folder(&req);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_remove_all_mms_rsp
 * DESCRIPTION
 *  This is the response handler for Delete Request.
 * PARAMETERS
 *  inMsg      response structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_remove_all_mms_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_folder_rsp_struct *msg = (srv_mms_delete_folder_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result != SRV_MMS_RESULT_OK)
    {
         mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_FAILURE);
         return;
    }

    if(msg->result == MMI_TRUE  )
    {
         mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_SUCCESS);
    }
    else
    {
         mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_FAILURE);
    }
}
#endif /*__DM_LAWMO_SUPPORT__*/


MMI_RET mmi_umms_app_core_get_storage_full_ind_data(mmi_event_struct *evt)
{

   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Start For CR ID MAUI_00786032 */
    srv_mms_storage_full_ind_struct *full_ind = (srv_mms_storage_full_ind_struct *)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_is_phone_lock())
    {
       return MMI_RET_OK;
    }
#endif /*__DM_LAWMO_SUPPORT__*/

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
   // MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_FULL_INDICATION, g_full_ind_counter, g_obj_ind_flag);

    /* For Object indication interaction between MMS Application and send-receive core, after every 60th Full Ind, 
       MMS Application will show full popup to user.*/
    if((srv_mms_get_obj_ind_flag() == MMI_TRUE) && (((srv_mms_get_full_ind_counter() - 1)%SRV_MMS_SHOW_FULL_POPUP_COUNT) != 0))
    {
        srv_mms_set_obj_ind_flag(MMI_FALSE);
        return MMI_RET_OK;
    }
    srv_mms_set_obj_ind_flag(MMI_FALSE);
#endif

    if (full_ind->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE)
    {
        StartTimer(UMMS_DOWNLOAD_TIMER, MMI_UMMS_DOWNLOAD_TIMER, mmi_umms_app_core_handle_download_timer_expiry);
        return MMI_RET_OK;
    }
    /*if (ind->is_no_fs_space)
    {
        if (ind->min_fs_space_required > 0)
        {
            mmi_umms_app_core_show_memory_full_pop_up(ind->min_fs_space_required, MMI_TRUE);
        }
        else
        {
            mmi_umms_app_core_show_memory_full_pop_up(ind->min_fs_space_required, MMI_FALSE);
        }
    }*/
    if (full_ind->result == MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED)
    {
        mmi_umms_app_core_show_memory_full_pop_up(0, MMI_TRUE);
    }
    /* End For CR ID MAUI_00786032 */

    if (full_ind->result == MMA_RESULT_FAIL_ROOT_DIR_FULL)
    {
        mmi_umms_app_core_no_duration_popup((U8*)GetString(STR_ID_UMMS_ROOT_DIR_FULL), (U8)MMI_EVENT_FAILURE);
    }
}

void mmi_umms_app_core_handle_download_timer_expiry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U16 image_id = 0;
     U16 tone_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_core_no_duration_popup((U8*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), (U8)MMI_EVENT_FAILURE);
    
    StopTimer(UMMS_DOWNLOAD_TIMER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_use_details_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_use_details_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_if_show_progress_screen();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_memory_full_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  min_sapce_required      [IN]        
 *  flag                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_memory_full_pop_up(U32 min_sapce_required, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_str[UMMS_CONVERT_INDEX] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SHOW_MEM_FULL_POP_UP);
        if (min_sapce_required > 0)
        {
            memset(subMenuData, 0, sizeof(subMenuData));
            mmi_ucs2cpy((S8*) subMenuData, (S8*) GetString(STR_UMMS_NO_ENOUGH_WORKING_SPACE_ID));
            mmi_ucs2cat((S8*) subMenuData, (S8*) " ");
            gui_itoa(min_sapce_required, (UI_string_type) tmp_str, UMMS_CONVERT_INDEX);
            mmi_ucs2cat((S8*) subMenuData, (S8*) tmp_str);
            mmi_ucs2cat((S8*) subMenuData, (S8*) " ");
            mmi_ucs2cat((S8*) subMenuData, (S8*) GetString(STR_ID_UMMS_KB));
            mmi_umms_app_core_no_duration_popup((U8*)subMenuData, (U8)MMI_EVENT_FAILURE);
        }
        else
        {
            if (flag == MMI_TRUE)
            {
                 mmi_umms_app_core_no_duration_popup((U8*)GetString(STR_ID_UMMS_MEMORY_FULL_CLEAN), (U8)MMI_EVENT_FAILURE);
            }
            else
            {
                mmi_umms_app_core_no_duration_popup((U8*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), (U8)MMI_EVENT_FAILURE);
            }
        }
    
   }


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_no_duration_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_no_duration_popup(U8* str, U8 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = 0;
    srv_prof_tone_enum tone_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_DEFAULT_POPUP);
    
    
    image_id = (U16)mmi_get_event_based_image((mmi_event_notify_enum)event_type);
    tone_id = mmi_get_event_based_sound((mmi_event_notify_enum)event_type);
    
       mmi_umms_app_core_interrupt_behavior_backlight();
    
    if(mmi_frm_scrn_get_active_id() != SCR_ID_UMMS_DISPLAY_INFINITE_POPUP)
    {
    mmi_umms_app_dtmgr_set_infinite_popup_screen_para((U16*)str, image_id, (U16)tone_id);
    mmi_umms_app_if_show_mms_full_popup();
}
}

mmi_frm_behavior_type mmi_umms_app_core_interrupt_behavior_backlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scenario_enum scenario;
    mmi_frm_int_behavior_struct behavior;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    scenario = mmi_frm_query_interrupt_behavior(
                MMI_INT_NEW_MSG_ARRIVES,
                &behavior);

    switch (behavior.backlight)
    {
        case MMI_FRM_BEHAVIOR_BL_SHORT_ON:
            /* The backlight is turned on for a short time. */
            TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
            break;
            
        case MMI_FRM_BEHAVIOR_BL_ALWAYS_ON:
            /* The backlight is always on. */
            TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
            break;

        case MMI_FRM_BEHAVIOR_BL_TWINKLE:
            /* The backlight is periodically on and off. Not support yet. */
            break;
            
        case MMI_FRM_BEHAVIOR_BL_NO_CHANGE:
        default:
            /* No action required. */
            break;
    }

    return behavior.backlight;
}

MMI_RET mmi_umms_app_core_show_error_popup(mmi_event_struct *evt)
{
	U8 *error = (U8 *)(evt->user_data);
	mmi_umms_app_if_show_error_pop_up(*error);	
    return MMI_RET_OK;
}

#ifdef __MMI_MMS_ITERATOR_VIEWER__

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_query_indexing_for_template_iter_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_um_iter_viewer_result_struct     [OUT]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_query_indexing_for_template_iter_view(mmi_um_iter_viewer_result_struct *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 hilited_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(data, 0, sizeof(mmi_um_iter_viewer_result_struct));
	data->index_number =  hilited_index 
        #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        = mmi_umms_app_dtmgr_get_current_message_index()
        #endif
         ;
	data->index_number++;/*this index is displayable index*/
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
	data->total_number = mmi_umms_app_dtmgr_get_template_count();
    #endif
	if(hilited_index >= 1)
	{
		data->prev_msg_id = mmi_umms_app_dtmgr_get_msg_id_by_index(hilited_index - 1);
	}
	if(data->index_number < data->total_number)
	{
		data->next_msg_id = mmi_umms_app_dtmgr_get_msg_id_by_index(hilited_index + 1);
	}
	data->prev_msg_type = MMA_MSG_TYPE_MMS;
	data->next_msg_type = MMA_MSG_TYPE_MMS;
	data->prev_launch_func_ptr = (cui_msg_viewer_launch_ptr)mmi_umms_app_if_start_viewer;
	data->next_launch_func_ptr = (cui_msg_viewer_launch_ptr)mmi_umms_app_if_start_viewer;
	if(data->index_number == 1)
	{
		data->prev_launch_func_ptr = NULL;
	}
	if(data->index_number == data->total_number)
	{
		data->next_launch_func_ptr = NULL;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_um_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_um_data_ready_cb(void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_umms_app_dtmgr_option_scr_data_struct *option_scr_data = (mmi_umms_app_dtmgr_option_scr_data_struct *)user_data;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER ||
		mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN  ||
		mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN)
    {
        if(mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_VIEWER)
		{
			if(mmi_umms_app_ui_plug_in_check_viewer_playing() == MMI_UMMS_TRUE)
			{
				return;
			}
			else
			{
				wgui_mv_update_info_ext();
				return;
			}
		}
        mmi_umms_app_ui_draw_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
	else if(option_scr_data->is_already_viewed == MMI_FALSE)
	{
		mmi_umms_app_if_show_viewer_screen();
	}
	else
	{
		mmi_umms_app_dtmgr_update_indexing_data_from_um(NULL);
	}

}
#endif /*__MMI_MMS_ITERATOR_VIEWER__*/
#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_msg_notify_for_msg_list_callback(U32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();
     U8 error = 0;
     U8 srv_result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELETE_MSG_NOTIFY_CALLBACK, msg_id, result);

    if ((result != MMI_MMS_BGSR_RESULT_OK) && (result != MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND))
    {
        /* Show Error PopUp */
        mmi_umms_app_dtmgr_set_popup_screen_para(
            (U16*) GetString(STR_GLOBAL_ERROR),
            MMI_EVENT_FAILURE);
        mmi_umms_app_if_show_display_popup_screen();
        mmi_umms_app_sh_delete_umms_screens();
    }
    else
    {
            srv_result = srv_mms_delete_msg(sync_info->msg_id, &error);

            if(srv_result != SRV_MMS_RESULT_OK)
            {
                mmi_umms_app_if_show_error_pop_up(MMA_RESULT_FAIL);
                mmi_umms_app_sh_delete_umms_screens();
                return;
            }
            if (error == MMA_RESULT_OK)
            {
#ifndef __MMI_BACKGROUND_CALL__
                if (!mmi_umms_is_in_call())
                {
                    mmi_umms_app_dtmgr_set_popup_screen_para(
                        (U16*) GetString(STR_GLOBAL_DELETED),
                        MMI_EVENT_EXPLICITLY_DELETED);
                    mmi_umms_app_if_show_display_popup_screen();
                }
#else /* __MMI_BACKGROUND_CALL__ */ 
                mmi_umms_app_dtmgr_set_popup_screen_para(
                    (U16*) GetString(STR_GLOBAL_DELETED),
                    MMI_EVENT_EXPLICITLY_DELETED);
                mmi_umms_app_if_show_display_popup_screen();
#endif /* __MMI_BACKGROUND_CALL__ */ 
                mmi_umms_app_sh_delete_umms_screens();
                srv_mms_show_status_icon();
            }
            else
            {
                mmi_umms_app_if_show_error_pop_up(error);
                mmi_umms_app_sh_delete_umms_screens();
            }
    }
}
#endif


MMI_RET mmi_umms_app_core_memory_status_screen_update(mmi_event_struct *evt)
{
	#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	if ((mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD)||(mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE))
	{
		mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_UPDATING_STATUS), MMI_EVENT_INFO);
        mmi_umms_app_if_show_display_popup_screen();
	}
	#else
	if(mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MMS_MESSAGE_STATUS)
	{
		mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_ID_UMMS_UPDATING_STATUS), MMI_EVENT_INFO);
        mmi_umms_app_if_show_display_popup_screen();
	}
	#endif
   	return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_check_card_plug_out_handling(mmi_event_struct *evt)
{
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION)
    {
        #if(MMI_MAX_SIM_NUM == 2)
        if (!((srv_mms_get_sim1_context()) && (srv_mms_get_sim2_context)))
        #endif
        {
            mmi_frm_scrn_close_active_id();
        }
    }
	return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_save_rsp_from_uc(mmi_event_struct *evt)
{
    if (mmi_frm_scrn_is_present(GRP_ID_UMMS_LIST_TEMPLATES, SCR_ID_UMMS_TEMPLATES, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
	{
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
		mmi_umms_app_dtmgr_reset_template_list_data();
#endif
	}
	return MMI_RET_OK;
}

#ifdef __MMI_MMS_USE_ASM__
mmi_ret mmi_umms_app_core_asm_success(mmi_event_struct *param)
{
	return MMI_RET_OK;
}
mmi_ret mmi_umms_app_core_asm_stop(mmi_event_struct *param)
{
	return MMI_RET_OK;
}
mmi_ret mmi_umms_app_core_asm_cancel(mmi_event_struct *param)
{
	return MMI_RET_OK;
}
#endif /*__MMI_MMS_USE_ASM__*/

mmi_ret mmi_umms_app_core_mma_insuf_mem(mmi_event_struct *param)
{
		mmi_umms_app_dtmgr_set_popup_screen_para((U16*) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), MMI_EVENT_PROPLEM);
        mmi_umms_app_if_show_display_popup_screen();
		return MMI_RET_OK;
}


MMI_RET mmi_umms_app_core_mms_display_popup_for_bgsr(mmi_event_struct *evt)
{
     U16 str = 0;
     U16 event = 0;
	 srv_mms_bgsr_result_struct *bgsr_result;
	 U8 result ;
	 U8 bgsr_req_type;
	bgsr_result = (srv_mms_bgsr_result_struct *)evt->user_data;
	result = bgsr_result->result;
	bgsr_req_type = bgsr_result->bgsr_req_type;
    switch (result)
    {
        
                case MMI_MMS_BGSR_RESULT_CANCELLED:
                   str = STR_ID_UMMS_CANCELED;
                   event = MMI_EVENT_SUCCESS;
                   break;
                case MMI_MMS_BGSR_RESULT_FAIL_NOT_READY:
                    str = STR_GLOBAL_NOT_AVAILABLE;
                    event = MMI_EVENT_FAILURE;
                    break;
                case MMI_MMS_BGSR_RESULT_OK:
                    {
                        switch (bgsr_req_type)
                        {
                            case MMS_BGSR_REQ_TYPE_SEND:
                                {
                                    mmi_popup_property_struct arg;
	                                mmi_popup_property_init(&arg);
	                                arg.msg_icon = IMG_NEW_SMS_SEND;
                                    arg.parent_id = GRP_ID_ROOT/*mmi_frm_group_get_active_id()*/;
	                                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENDING)), MMI_EVENT_PROGRESS, &arg); 
                                }
							#if defined(__MSGCMD_SUPPORT__)
                                return MMI_RET_OK;
							#else
								return;
							#endif
						
                            case MMS_BGSR_REQ_TYPE_CANCEL_SEND:
                                str = STR_GLOBAL_CANCELLING;
                                event = MMI_EVENT_PROGRESS;
                                break;
                            case MMS_BGSR_REQ_TYPE_DOWNLOADING:
                                str = STR_GLOBAL_DOWNLOADING;
                                event = MMI_EVENT_PROGRESS;
                                break;
                            case  MMS_BGSR_REQ_TYPE_CANCEL_DOWNLOADING:
                                str = STR_GLOBAL_CANCELLING;
                                event = MMI_EVENT_PROGRESS;
                                break;
                        }

                     }
                    break;
                default:
                    break;
   }

    if(str)
    {
         mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, event, (WCHAR *)GetString(str));

    }

#if defined(__MSGCMD_SUPPORT__)
	return MMI_RET_OK;
#endif
}

MMI_RET mmi_umms_app_core_handle_template_error_event(mmi_event_struct *evt)
{
	S32 *result = (S32 *)evt->user_data;
	mmi_umms_app_ui_plug_in_template_error_popup_handling(*result);
	return MMI_RET_OK;
}

MMI_RET mmi_umms_app_core_hanlde_save_objects_copy_result(mmi_event_struct *evt)
{
	S32 *copy_result = (S32 *)(evt->user_data);
	S8 *temp_url = NULL;
	mmi_da_dispatch_file_req_struct *mmi_da_dispatch_file_req = NULL;
    ilm_struct *ilm_ptr = NULL;
	S8 *url = NULL;
    U32 len = 0;
	applib_mime_type_struct *srv_mms_applib_mime_type = NULL;
    S8 *mime_type_string = NULL;
    U16 *object_vf = NULL;
    U16 *media_file_path = NULL;
    PU16 src_file_name;
    U8 drm_type;
	media_file_path = srv_mms_get_media_file_path();
    src_file_name = srv_mms_get_src_file_name();
	if (mmi_umms_app_ui_plug_in_check_progress_is_active() == MMI_FALSE)
    {
        if (srv_mms_is_usb_mode())
        {
            goto END;
        }
        else
        {
            mmi_umms_app_ui_plug_in_check_and_delete_progress_screen(NULL);
            goto END;
        }
    }
	if (*copy_result >= 0)
    {
        temp_url = (S8*) srv_mms_mem_mgr_app_adm_alloc((strlen((S8*) "mms://") + 1) * ENCODING_LENGTH);
        if (temp_url != NULL)
        {
            mmi_asc_to_ucs2((S8*) temp_url, (S8*) ("mms://"));
        }
        else
        {
			   srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, 0);
            goto END;
        }
        mmi_da_dispatch_file_req =
            (mmi_da_dispatch_file_req_struct*) construct_local_para(sizeof(mmi_da_dispatch_file_req_struct), TD_CTRL);
        
        mmi_da_dispatch_file_req->url[0] = '\0';
        mmi_da_dispatch_file_req->mime_type_string[0] = '\0';
        mmi_da_dispatch_file_req->filepath[0] = '\0';
        mmi_da_dispatch_file_req->action = MMI_DA_DOWNLOAD;
        mmi_da_dispatch_file_req->mime_type = 0;
        mmi_da_dispatch_file_req->mime_subtype = 0;

        mmi_ucs2ncpy(
            (S8*) mmi_da_dispatch_file_req->filename,
            (S8*) src_file_name,
            (sizeof(mmi_da_dispatch_file_req->filename) / ENCODING_LENGTH) - 1);

        drm_type = srv_mms_get_drm_type();

        if (drm_type == MMA_DRM_FL_CD)
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, "application/vnd.oma.drm.message");
        }
        else if (drm_type != 0)
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, "application/vnd.oma.drm.content");
        }
        else if (srv_fmgr_path_get_extension_ptr((WCHAR*) src_file_name) != NULL)
        {
            srv_mms_applib_mime_type = applib_mime_get_file_type(src_file_name);
            if (NULL == srv_mms_applib_mime_type)
            {
                mime_type_string = NULL;
            }
            else
            {
                mime_type_string = srv_mms_applib_mime_type->mime_string;
            }
            if (mime_type_string != NULL)
            {
                strcpy(mmi_da_dispatch_file_req->mime_type_string, mime_type_string);
            }
            else
            {
                U16 *str_ptr = NULL;
                U8 str_temp[SRV_FMGR_PATH_MAX_FILE_EXT_LEN  + 1] = {0};

                str_ptr = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) src_file_name);
				ASSERT(str_ptr);
                mmi_ucs2_n_to_asc((S8*) str_temp, (S8*) str_ptr, SRV_FMGR_PATH_MAX_FILE_EXT_LEN  * ENCODING_LENGTH);
                strcpy(mmi_da_dispatch_file_req->mime_type_string, (S8*) "application/");
                strcat(mmi_da_dispatch_file_req->mime_type_string, (S8*) str_temp);
            }
        }
        else
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, (S8*) "application/octet-stream");
        }

        len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (temp_url)) + 1);
        url = (S8*) srv_mms_mem_mgr_app_adm_alloc(len);
        if (NULL == url)
        {
            srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, 0);            
			OslMfree(mmi_da_dispatch_file_req);
            goto END;
        }
        mmi_chset_ucs2_to_utf8_string((U8*) url, len, (U8*) temp_url);
        memset((void*)mmi_da_dispatch_file_req->url, 0, sizeof(mmi_da_dispatch_file_req->url));
        strncpy(mmi_da_dispatch_file_req->url, url, (sizeof(mmi_da_dispatch_file_req->url) - 1));
        srv_mms_mem_mgr_app_adm_free(url);

        memset((void*)mmi_da_dispatch_file_req->filepath, 0, sizeof(mmi_da_dispatch_file_req->filepath));
        mmi_ucs2ncpy(
            (S8*) mmi_da_dispatch_file_req->filepath,
            (S8*) media_file_path,
            ((sizeof(mmi_da_dispatch_file_req->filepath) / ENCODING_LENGTH) - 1));

        mmi_da_dispatch_file_req->extra_info.size = 0;
        mmi_da_dispatch_file_req->extra_info.data[0] = '\0';
        mmi_da_dispatch_file_req->ui_setting.title_string_id = STR_MMS_MENUENTRY;
        mmi_da_dispatch_file_req->ui_setting.title_icon_id = GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
        mmi_umms_app_core_show_progress_screen_with_no_history();
        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->src_mod_id = MOD_MMI;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = WAP_MMI_SAP;
        ilm_ptr->msg_id = MSG_ID_MMI_DA_DISPATCH_FILE_REQ;
        ilm_ptr->local_para_ptr = (local_para_struct*) mmi_da_dispatch_file_req;
        ilm_ptr->peer_buff_ptr = NULL;
        msg_send_ext_queue(ilm_ptr);
    }
    else
    {
        srv_mms_send_events(EVT_ID_SRV_TEMPLATE_ERROR, (void *)copy_result);
        mmi_umms_app_ui_plug_in_check_and_delete_progress_screen(NULL);
    }

  END:
    if (temp_url != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(temp_url);
        temp_url = NULL;
    }
    if (media_file_path != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(media_file_path);
        media_file_path = NULL;
    }

    if (src_file_name != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(src_file_name);
        srv_mms_set_src_file_name(NULL);
    }
    srv_mms_set_file_handle(FS_NO_ERROR);
    srv_mms_set_media_info(NULL);
    srv_mms_set_media_file_path(NULL);
    srv_mms_set_virtual_file_name(NULL);
}


mmi_ret mmi_umms_app_core_mms_deinit(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 mmi_umms_app_sh_delete_umms_screens();
     mmi_umms_app_sh_delete_umms_use_details_screens();
     mmi_umms_app_sh_delete_umms_save_objects_screens();
	 return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_idle_hdlr
 * DESCRIPTION
 *  This is called when Idle screen group is entered
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_core_idle_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_umms_app_if_deinit_viewer();
    mmi_umms_app_dtmgr_reset_data();
#ifdef __MMI_URI_AGENT__
    srv_mms_de_init_uri();
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 * mmi_umms_app_core_display_bgsr_popup
 *
 * DESCRIPTION
 *  To display BGSR popup
 * PARAMETERS
 *  in_msg              [IN]
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
MMI_RET mmi_umms_app_core_display_bgsr_popup (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    S8 *fail_cause = NULL;
    U8 *fail_string = NULL;
	srv_mms_bgsr_popup_data *popup_info = (srv_mms_bgsr_popup_data *)evt->user_data;
	U16 current_sim_id_string = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_BGSR_POPUP_INFO, popup_info->msg_id, popup_info->response_txt, popup_info->result, popup_info->quota, popup_info->sim_id, popup_info->rsp_type);
	
#ifdef __DM_LAWMO_SUPPORT__
        if(mmi_dmui_is_phone_lock())
        {
        #if defined(__MSGCMD_SUPPORT__)
			return MMI_RET_OK;
		#else
            return;
		#endif
        }
#endif /*__DM_LAWMO_SUPPORT__*/

		if(popup_info->result == MMI_MMS_BGSR_RESULT_OK)
		{
            switch(popup_info->rsp_type)
			{
				case SRV_MMS_BGSR_RSP_TYPE_DOWNLOAD:
					break;

				case SRV_MMS_BGSR_RSP_TYPE_CANCEL_DOWNLOAD:
					mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_SUCCESS, ((WCHAR *)GetString(STR_ID_UMMS_BGSR_CANCELED)));
					break;

				case SRV_MMS_BGSR_RSP_TYPE_SEND:

#ifndef __MMI_SLIM_MMS_2__
					mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_SUCCESS, ((WCHAR *)GetString(STR_ID_UMMS_BGSR_MESSAGE_SENT)));
#else
                   mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_SUCCESS, ((WCHAR *)GetString(STR_GLOBAL_SENT)));
#endif /* __MMI_SLIM_MMS_2__ */  

					break;

				case SRV_MMS_BGSR_RSP_TYPE_CANCEL_SEND:
					mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_SUCCESS, ((WCHAR *)GetString(STR_ID_UMMS_BGSR_CANCELED)));
					break;

                default:
					break;
            
            }

        }
		else
		{

#ifndef __MMI_SLIM_MMS_2__
			if(popup_info->sim_id == MMA_SIM_ID_SIM1)
			{
				current_sim_id_string = STR_ID_UMMS_BGSR_SIM1;
			}
			else if(popup_info->sim_id == MMA_SIM_ID_SIM2)
			{
				current_sim_id_string = STR_ID_UMMS_BGSR_SIM2;
			}

			if (mmi_ucs2strlen((S8*)popup_info->response_txt))
			{
            
				U32 str_len =
#if(MMI_MAX_SIM_NUM == 2)
                mmi_ucs2strlen((S8 *) L" ")+
                mmi_ucs2strlen(GetString(current_sim_id_string))+
#endif      
                mmi_ucs2strlen(GetString(STR_ID_UMMS_BGSR_RESULT_FAIL)) +
                mmi_ucs2strlen(GetString(STR_ID_UMMS_BGSR_COLON)) + 
                mmi_ucs2strlen((S8 *) L" ") +
                mmi_ucs2strlen((S8 *)popup_info->response_txt);
            
				fail_cause = srv_mms_mem_mgr_app_adm_alloc((str_len + 1) * ENCODING_LENGTH);
				if (fail_cause != NULL)
				{
					memset(fail_cause , 0, (str_len + 1) * ENCODING_LENGTH);
                
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  GetString(STR_ID_UMMS_BGSR_RESULT_FAIL));
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  GetString(STR_ID_UMMS_BGSR_COLON));
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  (S8 *) L" ");
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  (S8 *)popup_info->response_txt);
#if(MMI_MAX_SIM_NUM == 2)
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  (S8 *) L" ");
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  GetString(current_sim_id_string));
#endif  
					fail_string = (U8 *)fail_cause;
				}
				else
				{
					//MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_MMS_BGSR_MEMORY_NOT_ALLOCATED,__LINE__);
				} 
			}
			else
			{
				U32 str_len =  
#if(MMI_MAX_SIM_NUM == 2)
                mmi_ucs2strlen((S8 *) L" ") +
                mmi_ucs2strlen(GetString(current_sim_id_string)) +
#endif /* __MMI_MMS_DUAL_SIM__ */
                mmi_ucs2strlen (GetString 
                (mmi_umms_app_core_bgsr_translate_result_to_strid(popup_info->result)));
				fail_cause = srv_mms_mem_mgr_app_adm_alloc((str_len + 1) * ENCODING_LENGTH);
				if (fail_cause != NULL)
				{
					 memset(fail_cause , 0, (str_len + 1) * ENCODING_LENGTH);
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  GetString (mmi_umms_app_core_bgsr_translate_result_to_strid(popup_info->result)));
#if(MMI_MAX_SIM_NUM == 2)
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  (S8 *) L" ");
					fail_cause = (S8 *)mmi_ucs2cat((S8 *)fail_cause,  GetString(current_sim_id_string));
#endif
					fail_string = (U8 *)fail_cause;
				}
				else
				{
					//MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_MMS_BGSR_MEMORY_NOT_ALLOCATED,__LINE__);
				} 
            
			}    
   			mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_FAILURE, (WCHAR *)fail_string);
    
			if( fail_cause != NULL)
			{
				srv_mms_mem_mgr_app_adm_free(fail_cause);
			}  
#else
			switch(popup_info->rsp_type)
			{
				case SRV_MMS_BGSR_RSP_TYPE_DOWNLOAD:
					mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_FAILURE, (WCHAR *)GetString(mmi_umms_app_core_bgsr_translate_result_to_strid(popup_info->result, 0)));
					break;

				case SRV_MMS_BGSR_RSP_TYPE_CANCEL_DOWNLOAD:
					mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_FAILURE, (WCHAR *)GetString(mmi_umms_app_core_bgsr_translate_result_to_strid(popup_info->result, 0)));
					break;

				case SRV_MMS_BGSR_RSP_TYPE_SEND:
                    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_FAILURE, (WCHAR *)GetString(mmi_umms_app_core_bgsr_translate_result_to_strid(popup_info->result, 1)));
					break;

				case SRV_MMS_BGSR_RSP_TYPE_CANCEL_SEND:
					mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MMS_INFO, MMI_EVENT_FAILURE, (WCHAR *)GetString(mmi_umms_app_core_bgsr_translate_result_to_strid(popup_info->result, 1)));
					break;

                default:
					break;
            
            }
#endif /* __MMI_SLIM_MMS_2__ */ 
		}

#if defined(__MSGCMD_SUPPORT__)
	return MMI_RET_OK;
#endif
}



#ifdef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_bgsr_translate_result_to_strid
 * DESCRIPTION
 *  translate bgsr result to string ID
 * PARAMETERS
 *  bgsr_result          [IN]    BGSR result
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_app_core_bgsr_translate_result_to_strid(mmi_mms_bgsr_result_enum bgsr_result, U8 send_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

   // MMI_TRACE(MMI_INET_TRC_G6_MMS,MMI_MMS_BGSR_TRANSLATE_RESULT_TO_STRID,bgsr_result,__LINE__);

    switch( bgsr_result )
    {
        case    MMI_MMS_BGSR_RESULT_OK:
            return  STR_GLOBAL_OK;
        case    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY:        
            return  STR_GLOBAL_INSUFFICIENT_MEMORY;
        case    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE:       
            return  STR_GLOBAL_NOT_ENOUGH_MEMORY;
        case    MMI_MMS_BGSR_RESULT_FAIL_BUSY:                 
            return  STR_GLOBAL_BUSY_TRY_LATER;        
        case    MMI_MMS_BGSR_RESULT_FAIL_NOT_READY:                  
            return  STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND:  
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED:  
            return  STR_GLOBAL_FILE_NOT_FOUND;
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:              
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR:                             
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR:                  
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT:                             
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED:                                             
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED:                    
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR:         
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR; 
        case MMI_MMS_BGSR_RESULT_READ_REPORT_FAIL: 
        case    MMI_MMS_BGSR_RESULT_FAIL:                            
        default:
            if(send_flag)
            {
                return  STR_ID_UMMS_BGSR_RESULT_SEND_FAIL;   
            }
            else
            {
                return  STR_ID_UMMS_BGSR_RESULT_DOWNLOAD_FAIL;   
            }
    }

}
#else /*__MMI_SLIM_MMS_2__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_bgsr_translate_result_to_strid
 * DESCRIPTION
 *  translate bgsr result to string ID
 * PARAMETERS
 *  bgsr_result          [IN]    BGSR result
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_app_core_bgsr_translate_result_to_strid(mmi_mms_bgsr_result_enum bgsr_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

   // MMI_TRACE(MMI_INET_TRC_G6_MMS,MMI_MMS_BGSR_TRANSLATE_RESULT_TO_STRID,bgsr_result,__LINE__);

    switch( bgsr_result )
    {
        case    MMI_MMS_BGSR_RESULT_OK:
            return  STR_ID_UMMS_BGSR_RESULT_OK;
        case    MMI_MMS_BGSR_RESULT_FAIL_INCALL:                    
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_INCALL;
        case    MMI_MMS_BGSR_RESULT_FAIL_NOT_READY:                  
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_NOT_READY;
        case    MMI_MMS_BGSR_RESULT_FAIL_BUSY:                 
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_BUSY;
        case    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY:        
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY;
        case    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE:       
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND:             
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;     
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED:            
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_FILE_CORRUPTED;            
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_IN_USE:               
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_FILE_IN_USE;            
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_IO:                
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_FILE_IO;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT:          
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT;
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:     
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR:          
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR:         
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR:          
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT:        
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED:        
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED:          
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_USER_CANCEL:                
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_USER_CANCEL;
        case    MMI_MMS_BGSR_RESULT_FAIL_INVALID_MSGID:              
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_INVALID_MSGID;
        case    MMI_MMS_BGSR_RESULT_FAIL_MSGID_IS_USING:        
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_MSGID_IS_USING;            
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:    
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;   
        case    MMI_MMS_BGSR_RESULT_FAIL_MAX_MSG_SIZE_REACHED:    
            return  STR_ID_UMMS_BGSR_RESULT_FAIL_MAX_MSG_SIZE_REACHED; 
		case MMI_MMS_BGSR_RESULT_FAIL_RESEND:
            return STR_ID_UMMS_BGSR_SEND_FAIL_RESEND;
        case MMI_MMS_BGSR_RESULT_READ_REPORT_FAIL: 
			return  STR_ID_UMMS_BGSR_READ_REPORT_SEND_FAIL; 
        case MMI_MMS_BGSR_RESULT_FAIL:
		default:
            return  STR_ID_UMMS_BGSR_RESULT_FAIL;   
    }

}
#endif /*__MMI_SLIM_MMS_2__*/

mmi_ret mmi_umms_app_core_show_hide_status_icon(mmi_event_struct *evt)
{
	srv_mms_base_event_struct* param =  (srv_mms_base_event_struct*) evt;
	 srv_mms_show_hide_icon_struct *info = (srv_mms_show_hide_icon_struct *)param->user_data;

    if(info->icon_state == SRV_MMS_ICON_STATE_ACTION_HIDE)
	{

        HideStatusIcon(STATUS_ICON_MMS_BUSY);
	    UpdateStatusIcons();
 
	}
	else
	{

        BlinkStatusIcon(STATUS_ICON_MMS_BUSY);

	}
	return MMI_RET_OK;
}


mmi_ret mmi_umms_app_core_dummy_listener(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


#endif /* __MMI_MMS_2__ */ 

