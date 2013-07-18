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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  NwInfoSignal.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Signal icon of network information
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "NwInfoProt.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwInfoProt.h"
#include "CallSetSrvGprot.h"
#include "CphsSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "MMIDataType.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "NwInfoSrvGprot.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "kal_non_specific_general_types.h"
#include "mmi_frm_utility_gprot.h"
#include "GlobalResDef.h"


/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_nw_info_signal_set_icon(
                mmi_sim_enum sim,
                S32 strength_in_percentage);


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_early_init
 * DESCRIPTION
 *  Initialize signal icon on early init
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_early_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
#if (MMI_MAX_SIM_NUM >= 3)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_CLOSED);
#if (MMI_MAX_SIM_NUM >= 4)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_CLOSED);
#endif
#endif
#endif
    
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIGNAL_STRENGTH);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH);
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SLAVE_SIGNAL_STRENGTH);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH);
#if (MMI_MAX_SIM_NUM >= 3)
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM3_SIGNAL_STRENGTH);
#if (MMI_MAX_SIM_NUM >= 4)
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_SIM4_SIGNAL_STRENGTH);
#endif
#endif
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_mode_decided
 * DESCRIPTION
 *  Initialize signal strength icons.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_mode_decided(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_info_is_enabled(MMI_SIM1))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_SIGNAL_STRENGTH);
    }
    
    if (srv_nw_info_is_enabled(MMI_SIM2))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH, IMG_SLSI_SLAVE_SIGNAL_STRENGTH);
    }

#if (MMI_MAX_SIM_NUM >= 3)
    if (srv_nw_info_is_enabled(MMI_SIM3))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_STRENGTH);
    }
#if (MMI_MAX_SIM_NUM >= 4)
    if (srv_nw_info_is_enabled(MMI_SIM4))
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_STRENGTH);
    }
#endif
#endif
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_service_avai_changed
 * DESCRIPTION
 *  Handler for service availability chahnged.
 *  To update signal strength icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_service_availability_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_service_avai_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *availability_evt;
    S32 strength_in_percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED,
        evt->evt_id, 0, 0);
    
    availability_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;

    strength_in_percentage = 0;
    switch (availability_evt->new_status)
    {
        case SRV_NW_INFO_SA_NO_SERVICE:
            strength_in_percentage = 0;
            break;

        case SRV_NW_INFO_SA_FULL_SERVICE:
        case SRV_NW_INFO_SA_LIMITED_SERVICE:
            strength_in_percentage =
                srv_nw_info_get_signal_strength_in_percentage(availability_evt->sim);
            break;
            
        case SRV_NW_INFO_SA_SEARCHING:
            /* Don't change; go through to return */
        default:
            /* Ignore */
            return MMI_RET_OK;
    }

    mmi_nw_info_signal_set_icon(availability_evt->sim, strength_in_percentage);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_get_icon_id
 * DESCRIPTION
 *  Get signal strength icon ID of SIM.
 * PARAMETERS
 *  sim             [IN]  Which SIM
 *  mainlcd_icon_id [OUT] Icon ID of main LCD
 *  sublcd_icon_id  [OUT] Icon ID of sub LCD
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_signal_get_icon_id(
                mmi_sim_enum sim,
                S32 *mainlcd_icon_id,
                S32 *sublcd_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim == MMI_SIM1)
    {
        *mainlcd_icon_id = STATUS_ICON_SIGNAL_STRENGTH;
        *sublcd_icon_id = STATUS_ICON_SUBLCD_SIGNAL_STRENGTH;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (sim == MMI_SIM2)
    {
        *mainlcd_icon_id = STATUS_ICON_SLAVE_SIGNAL_STRENGTH;
        *sublcd_icon_id = STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim == MMI_SIM3)
    {
        *mainlcd_icon_id = STATUS_ICON_SIM3_SIGNAL_STRENGTH;
        *sublcd_icon_id = STATUS_ICON_INVALID_ID;
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim == MMI_SIM4)
    {
        *mainlcd_icon_id = STATUS_ICON_SIM4_SIGNAL_STRENGTH;
        *sublcd_icon_id = STATUS_ICON_INVALID_ID;
    }
#endif
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_get_image_id
 * DESCRIPTION
 *  Get signal strength icon ID of SIM.
 * PARAMETERS
 *  sim                     [IN]  Which SIM
 *  mainlcd_image_normal_id [OUT] IMG ID of main LCD
 *  mainlcd_image_close_id  [OUT] IMG ID of main LCD
 *  mainlcd_image_line1_id  [OUT] IMG ID of main LCD
 *  mainlcd_image_line2_id  [OUT] IMG ID of main LCD
 *  sublcd_image_id         [OUT] IMG ID of sub LCD
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_signal_get_image_id(
                mmi_sim_enum sim,
                S32 *mainlcd_image_normal_id,
                S32 *mainlcd_image_close_id,
                S32 *mainlcd_image_line1_id,
                S32 *mainlcd_image_line2_id,
                S32 *sublcd_image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim == MMI_SIM1)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        *mainlcd_image_normal_id = IMG_SI_MASTER_SIGNAL_STRENGTH;
        *mainlcd_image_close_id = IMG_SI_MASTER_SIGNAL_CLOSED;
        *mainlcd_image_line1_id = IMG_SI_MASTER_SIGNAL_STRENGTH_L1;
        *mainlcd_image_line2_id = IMG_SI_MASTER_SIGNAL_STRENGTH_L2;
#else
        *mainlcd_image_normal_id = IMG_SI_SIGNAL_STRENGTH;
        *mainlcd_image_close_id = IMG_GLOBAL_DEFAULT;
    #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
        *mainlcd_image_line1_id = IMG_SI_SIGNAL_STRENGTH_L1;
        *mainlcd_image_line2_id = IMG_SI_SIGNAL_STRENGTH_L2;
    #else
        *mainlcd_image_line1_id = IMG_GLOBAL_DEFAULT;
        *mainlcd_image_line2_id = IMG_GLOBAL_DEFAULT;
    #endif
#endif
        *sublcd_image_id = IMG_SLSI_SIGNAL_STRENGTH;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (sim == MMI_SIM2)
    {
        *mainlcd_image_normal_id = IMG_SI_SLAVE_SIGNAL_STRENGTH;
        *mainlcd_image_close_id = IMG_SI_SLAVE_SIGNAL_CLOSED;
        *mainlcd_image_line1_id = IMG_SI_SLAVE_SIGNAL_STRENGTH_L1;
        *mainlcd_image_line2_id = IMG_SI_SLAVE_SIGNAL_STRENGTH_L2;
        *sublcd_image_id = IMG_SLSI_SLAVE_SIGNAL_STRENGTH;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim == MMI_SIM3)
    {
        *mainlcd_image_normal_id = IMG_SI_SIM3_SIGNAL_STRENGTH;
        *mainlcd_image_close_id = IMG_SI_SIM3_SIGNAL_CLOSED;
        *mainlcd_image_line1_id = IMG_SI_SIM3_SIGNAL_STRENGTH_L1;
        *mainlcd_image_line2_id = IMG_SI_SIM3_SIGNAL_STRENGTH_L2;
        *sublcd_image_id = IMG_GLOBAL_DEFAULT;
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sim == MMI_SIM4)
    {
        *mainlcd_image_normal_id = IMG_SI_SIM4_SIGNAL_STRENGTH;
        *mainlcd_image_close_id = IMG_SI_SIM4_SIGNAL_CLOSED;
        *mainlcd_image_line1_id = IMG_SI_SIM4_SIGNAL_STRENGTH_L1;
        *mainlcd_image_line2_id = IMG_SI_SIM4_SIGNAL_STRENGTH_L2;
        *sublcd_image_id = IMG_GLOBAL_DEFAULT;
    }
#endif
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_set_icon
 * DESCRIPTION
 *  Set the icon of signal strength by given value
 * PARAMETERS
 *  sim                     [IN] Which SIM
 *  strength_in_percentage  [IN] Signal strength
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nw_info_signal_set_icon(
                mmi_sim_enum sim,
                S32 strength_in_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mainlcd_icon_id;
    S32 sublcd_icon_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: Select icon by line number

    mainlcd_icon_id = STATUS_ICON_INVALID_ID;
    sublcd_icon_id = STATUS_ICON_INVALID_ID;
    
    mmi_nw_info_signal_get_icon_id(
        sim,
        &mainlcd_icon_id,
        &sublcd_icon_id);

    MMI_TRACE(MMI_NW_INFO_TRC_GROUP, TRC_MMI_NW_INFO_SIGNAL_ICON_CHANGED,
        sim, strength_in_percentage);
        
    wgui_status_icon_bar_change_icon_level(mainlcd_icon_id, strength_in_percentage);
    if (sublcd_icon_id != STATUS_ICON_INVALID_ID)
    {
        wgui_status_icon_bar_change_icon_level(sublcd_icon_id, strength_in_percentage);
    }

    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_strength_changed
 * DESCRIPTION
 *  Handler for signal strength changed.
 *  Update signal strength icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_signal_strength_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_strength_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_signal_strength_changed_evt_struct *strength_evt;
    srv_nw_info_service_availability_enum service_availability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED,
        evt->evt_id, 0, 0);

    strength_evt = (srv_nw_info_signal_strength_changed_evt_struct*)evt;

    service_availability = srv_nw_info_get_service_availability(strength_evt->sim);
    if (service_availability != SRV_NW_INFO_SA_NO_SERVICE &&
        service_availability != SRV_NW_INFO_SA_SEARCHING)
    {
#if defined(__WS_HOME_SAFE__)
	{
		extern void hf_set_signal_changed(kal_uint8 signal);
		hf_set_signal_changed(strength_evt->new_percentage);

	}
#endif	
        mmi_nw_info_signal_set_icon(strength_evt->sim, strength_evt->new_percentage);
    }
    else
    {
        /*
         * The strength icon will be updated from NO_SERVICE/SEARCHING to
         * FULL/LIMITED_SERVICE by mmi_nw_info_signal_on_service_avai_changed()
         */
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nw_info_signal_on_mode_switched
 * DESCRIPTION
 *  Update signal right after mode switched
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_nw_info_signal_on_mode_switched(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    U8 line_id;
    S32 mainlcd_image_normal_id = 0, mainlcd_image_close_id = 0, mainlcd_image_line1_id = 0, mainlcd_image_line2_id = 0, sublcd_image_id = 0;
    S32 mainlcd_icon_id, sublcd_icon_id;
    mmi_sim_enum sim_id;
    srv_mode_switch_type_enum mode_id;

    srv_nw_info_service_availability_enum service_availability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim_id = mmi_frm_index_to_sim(i);

        /* update icon */
        line_id = srv_callset_line_switch_get_id(sim_id);
        mode_id = srv_mode_switch_get_current_mode();

        mmi_nw_info_signal_get_icon_id(
            sim_id,
            &mainlcd_icon_id,
            &sublcd_icon_id);
        mmi_nw_info_signal_get_image_id(
            sim_id,
            &mainlcd_image_normal_id,
            &mainlcd_image_close_id,
            &mainlcd_image_line1_id,
            &mainlcd_image_line2_id,
            &sublcd_image_id);

        if (mode_id & sim_id)
        {
            if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_CPHS_TELESERVICES, SRV_CPHS_SERVICE_ALS, sim_id)) // Line is not supported, identified by EF_CSP
            {
                wgui_status_icon_bar_change_icon_image(mainlcd_icon_id, mainlcd_image_normal_id);
            }
            else
            {
            #ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
                if (line_id == SRV_CALLSET_LINE1)
                {
                    wgui_status_icon_bar_change_icon_image(mainlcd_icon_id, mainlcd_image_line1_id);
                }
                else if (line_id == SRV_CALLSET_LINE2)
                {
                    wgui_status_icon_bar_change_icon_image(mainlcd_icon_id, mainlcd_image_line2_id);
                }
                else
            #endif
                {
                    wgui_status_icon_bar_change_icon_image(mainlcd_icon_id, mainlcd_image_normal_id);
                }
            }
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        else
        {
            wgui_status_icon_bar_change_icon_image(mainlcd_icon_id, mainlcd_image_close_id);
        }
    #endif

        /* update level */
        service_availability = srv_nw_info_get_service_availability(sim_id);
        
        if (srv_mode_switch_get_network_mode(sim_id) == SRV_MODE_SWITCH_ON &&
            service_availability != SRV_NW_INFO_SA_NO_SERVICE &&
            service_availability != SRV_NW_INFO_SA_SEARCHING)
        {
            S32 strength;

            strength = srv_nw_info_get_signal_strength_in_percentage(sim_id);
            mmi_nw_info_signal_set_icon(sim_id, strength);
        }
    }

    return MMI_RET_OK;
}

