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
 *   DataAccountCui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data account Common UI source file.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#if defined(__TCPIP__)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#include "DataAccountCui.h"
#include "WlanCuiGprot.h"
#include "DtcntSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "MMIDataType.h"
#include "DataAccountDef.h"
#include "DataAccountStruct.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "kal_non_specific_general_types.h"
#include "DataAccountCuiGprot.h"
#include "DtcntSrvIprot.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "abm_api.h"
#include "DataAccountGProt.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "wgui_categories_util.h"
#include "wgui_fixed_menus.h"
#include "GlobalConstants.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "DataAccountEnum.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_frm_nvram_gprot.h"

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Global Variable Declaration
*******************************************************************************/
U8 g_cui_dtcnt_sel_index;

MMI_BOOL g_bt_sim_unavailable_flag = MMI_FALSE;
MMI_BOOL g_bt_sim_available_flag = MMI_FALSE;
U32 g_need_restore_highlight_index = 0;
U32 g_need_restore_highlight_index2 = 0;

mmi_id g_wlan_cui_id;
cui_dtcnt_select_account_option_struct  g_cui_dtcnt_sel_acct[CUI_DTCNT_MAX_BEARER_LIST_NUM];

/* this struct array is used to store account name and address for showing list, include CUI and setting */
mmi_dtcnt_comm_disp_name_addr g_comm_disp_name_addr_arr[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM + MAX_DATA_ACCOUN_CUI_FIX_ITEM];

extern mmi_dtcnt_list_disp_struct g_mmi_dtcnt_list_item[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM];

extern U32 g_mmi_dtcnt_acct_num;
extern mmi_dtcnt_csd_acct_node_struct g_data_account_csd_profile;
extern mmi_dtcnt_gprs_acct_node_struct g_data_account_gprs_profile;

extern mmi_dtcnt_app_info_struct g_app_info_nvram;
extern mmi_dtcnt_app_info_nvram_temp_struct g_app_info_nvram_temp;
static cui_dtcnt_select_item_struct g_cui_dtcnt_selection_itmes[] = 
{
    {CUI_DTCNT_ITEM_NONE, STR_GLOBAL_NONE},
    {CUI_DTCNT_ITEM_AUTO, STR_GLOBAL_AUTOMATIC},
    {CUI_DTCNT_ITEM_ALWAYS_ASK, STR_ID_DTCNT_ALWAYS_ASK},


#ifdef __MMI_WLAN_FEATURES__
    {CUI_DTCNT_ITEM_WIFI, SERVICES_DATA_CONNECT_WLAN_STRING_ID},
    {CUI_DTCNT_ITEM_WIFI_LIST, SERVICES_DATA_CONNECT_WLAN_STRING_ID},
#endif /* __MMI_WLAN_FEATURES__ */ 

};
static U8 cui_dtcnt_get_first_entry_highlight_item(U32 acct_id, MMI_BOOL is_dual_acct, MMI_BOOL is_second_acct);
static mmi_ret cui_dtcnt_select_group_proc(mmi_event_struct *evt);
void mmi_dtcnt_cui_select_account(mmi_id cui_id, U16 AppMenuID, U8 bearers, U8 app_id, U32 account_id, cui_dtcnt_select_type_enum option);
mmi_ret cui_dtcnt_leave_callback(mmi_event_struct* evt);
static void cui_dtcnt_csd_viewer_common(void);
static void cui_dtcnt_gprs_viewer_common(void);
static S16 cui_dtcnt_account_view_fill_data(void);
S32 cui_dtcnt_get_cntx_index_by_cui_id(mmi_id cui_id, U8 cntx_type);

extern MMI_BOOL mmi_dtcnt_get_csd_profile(U32 profile_id, mmi_dtcnt_csd_acct_node_struct *g_data_account_csd_profile);
extern MMI_BOOL mmi_dtcnt_get_gprs_profile(U32 profile_id, mmi_dtcnt_gprs_acct_node_struct *g_data_account_gprs_profile);
extern void mmi_dtcnt_write_positive_app_info_nvram_ext(U16 index); 
extern void mmi_dtcnt_reset_invalid_acct_ext(U16 str_id, U16 icon_id); /* sync app info */


void cui_dtcnt_prepare_list_info_single(U8 cntx_index, U8 *num, cui_dtcnt_select_option_enum option, cui_dtcnt_list_disp_struct *list_info);
void cui_dtcnt_prepare_list_info_cbm(U8 cntx_index, U8 *num, cui_dtcnt_select_option_enum option, cui_dtcnt_list_disp_struct *list_info);
void cui_dtcnt_prepare_list_info_dual(U8 cntx_index, U8 *num, cui_dtcnt_select_option_enum option, cui_dtcnt_list_disp_struct *list_info, U8 is_primary);

extern srv_dtcnt_sim_type_enum mmi_dtcnt_query_sim_info(U32 profile_id, srv_dtcnt_bearer_enum bearer);
static void cui_dtcnt_arrange_account_list(cui_dtcnt_list_disp_struct *prof_list, mmi_dtcnt_comm_disp_name_addr *name_addr_arr,S32 start, S32 end);


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_arrange_account_list
 * DESCRIPTION
 *  Arrange the account list in order.
 * PARAMETERS
 *  prof_list    [IN]  profile list
 *  name_addr_arr [IN] account name and address array point which is related to profile list
 *  start        [IN]  start position
 *  end          [IN]  end position
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dtcnt_arrange_account_list(cui_dtcnt_list_disp_struct *prof_list, mmi_dtcnt_comm_disp_name_addr *name_addr_arr,S32 start, S32 end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 size1 = sizeof(cui_dtcnt_list_disp_struct);
    S32 size2 = sizeof(mmi_dtcnt_comm_disp_name_addr);
    cui_dtcnt_list_disp_struct g_account_temp;
    mmi_dtcnt_comm_disp_name_addr name_addr_tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (end <= (start + 1))
    {
        return;
    }

    for (i = start; i < end - 1; i++)
    {    
        for(j = i; j < end; j++)
        {
            if (mmi_ucs2cmp((S8*)name_addr_arr[i].data_account_name, (S8*)name_addr_arr[j].data_account_name) > 0)
            {
                /* the two array is related by the same index */
                memcpy(&g_account_temp, &prof_list[i], size1);
                memcpy(&prof_list[i], &prof_list[j], size1);
                memcpy(&prof_list[j], &g_account_temp, size1);

                memcpy(&name_addr_tmp, &name_addr_arr[i], size2);
                memcpy(&name_addr_arr[i], &name_addr_arr[j], size2);
                memcpy(&name_addr_arr[j], &name_addr_tmp, size2);
            }
        }
    }
}

#define SELECTION_CUI
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_app_select_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_single_select_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_struct evt;
	U8 selected_index = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected;
    U32 acct_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].profile_id;
    U8 app_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id;
    cui_dtcnt_item_type_enum item_type = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].item_type;
    U32 i, j, k;
    S16 error;
    cbm_app_info_struct app_info;
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
    srv_dtcnt_sim_type_enum srv_sim_id = SRV_DTCNT_SIM_TYPE_1;
    srv_dtcnt_bearer_enum srv_bearer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abm_get_registered_app_name(app_id, &app_info);

    switch(item_type)
    {
        case CUI_DTCNT_ITEM_AUTO:
        {
            acct_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, app_id, FALSE);
            break;
        }
        case CUI_DTCNT_ITEM_WIFI:
        {
            cbm_get_valid_account_id(CBM_BEARER_WIFI, &acct_id);
            acct_id = cbm_encode_data_account_id(acct_id, CBM_SIM_ID_SIM1, app_id, FALSE);
            break;
        }
        case CUI_DTCNT_ITEM_ALWAYS_ASK:
       	{
            acct_id = cbm_encode_data_account_id(MMI_DTCNT_DEFAULT_ID, CBM_SIM_ID_SIM1, app_id, TRUE);
            break;
        }
        case CUI_DTCNT_ITEM_CSD:
        case CUI_DTCNT_ITEM_GPRS:
        {
            if (item_type == CUI_DTCNT_ITEM_GPRS)
            {
                srv_bearer = SRV_DTCNT_BEARER_GPRS;
            }
            else
            {
                srv_bearer = SRV_DTCNT_BEARER_CSD;
            }

            srv_sim_id = mmi_dtcnt_query_sim_info(acct_id, srv_bearer);

            switch(srv_sim_id)
            {
                case SRV_DTCNT_SIM_TYPE_1:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
                case SRV_DTCNT_SIM_TYPE_2:
                    cbm_sim_id = CBM_SIM_ID_SIM2;
                    break;
                case SRV_DTCNT_SIM_TYPE_3:
                    cbm_sim_id = CBM_SIM_ID_SIM3;
                    break;
                case SRV_DTCNT_SIM_TYPE_4:
                    cbm_sim_id = CBM_SIM_ID_SIM4;
                    break;
                default:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
            }
//            cbm_sim_id = (srv_sim_id == SRV_DTCNT_SIM_TYPE_1 ? CBM_SIM_ID_SIM1 : CBM_SIM_ID_SIM2);
            
            acct_id = cbm_encode_data_account_id(acct_id, cbm_sim_id, app_id, FALSE);
            break;
        }
    }
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_id = acct_id;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_APP_SELECT_OK, acct_id);

    if (!(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].option & CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT))
    {
        /* To add ap list to dtcnt list*/
        for (i = 0; i < g_mmi_dtcnt_acct_num; i++)
    	{
            if (g_mmi_dtcnt_list_item[i].profile_id == g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].profile_id)
            {
                for (j = 0; j < g_mmi_dtcnt_list_item[i].app_info.ap_num; j++)
                {
    				if (g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_mmi_dtcnt_list_item[i].app_info.ap_num)
                {
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id = app_info.app_str_id;
                    
                    g_mmi_dtcnt_list_item[i].app_info.ap_num++;
                }

            }
            else
            {
                for (j = 0; j < g_mmi_dtcnt_list_item[i].app_info.ap_num; j++)
                {
    				if (g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id == app_info.app_str_id)

                    {
                        for (k = j; k < g_mmi_dtcnt_list_item[i].app_info.ap_num - 1; k++)
                        {
    						g_mmi_dtcnt_list_item[i].app_info.app_info[k] = g_mmi_dtcnt_list_item[i].app_info.app_info[k + 1];
                        }
                        g_mmi_dtcnt_list_item[i].app_info.app_info[k].app_icon_id = 0;
                        g_mmi_dtcnt_list_item[i].app_info.app_info[k].app_str_id = 0;

                        g_mmi_dtcnt_list_item[i].app_info.ap_num--;
                        break;
                    }
                }
            }
        }

        /* To add ap list to app info list nvram*/
        for (i = 0; i < g_app_info_nvram.acct_num; i++)
    	{
            if (g_app_info_nvram.acct_app_list[i].acct_id == g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].profile_id)
            {
                for (j = 0; j < g_app_info_nvram.acct_app_list[i].app_info.ap_num; j++)
                {
    				if (g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_app_info_nvram.acct_app_list[i].app_info.ap_num)
                {
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id = app_info.app_str_id;

                    g_app_info_nvram.acct_app_list[i].app_info.ap_num++;
                    mmi_dtcnt_write_positive_app_info_nvram_ext((U16)i);
                }
                
            }
            else
            {
                for (j = 0; j < g_app_info_nvram.acct_app_list[i].app_info.ap_num; j++)
                {
    				if (g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        for (k = j; k < g_app_info_nvram.acct_app_list[i].app_info.ap_num - 1; k++)
                        {
                            g_app_info_nvram.acct_app_list[i].app_info.app_info[k] = g_app_info_nvram.acct_app_list[i].app_info.app_info[k + 1];
                        }
                        g_app_info_nvram.acct_app_list[i].app_info.app_info[k].app_icon_id = 0;
                        g_app_info_nvram.acct_app_list[i].app_info.app_info[k].app_str_id = 0;

                        g_app_info_nvram.acct_app_list[i].app_info.ap_num--;
                        mmi_dtcnt_write_positive_app_info_nvram_ext((U16)i);
                        break;
                    }
                }
            }
        }


        mmi_dtcnt_reset_invalid_acct_ext(app_info.app_str_id, app_info.app_icon_id);
    }

    MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id);
	evt.account_id = acct_id;
	mmi_frm_group_send_to_parent(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, (mmi_group_event_struct*)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_go_back_history
 * DESCRIPTION
 *  close the current active screen
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_cancel_cui
 * DESCRIPTION
 *  close the current CUI
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_cancel_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acct_id = MMI_DTCNT_INVALID_ID;
    cui_dtcnt_select_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return the encode acct id */
    MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id);
	
    evt.account_id = acct_id;
    mmi_frm_group_send_to_parent(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, (mmi_group_event_struct*)&evt);

}


/*****************************************************************************
  * FUNCTION
  *  cui_dtcnt_select_close
  * DESCRIPTION
  *  to close data account select group
  * PARAMETERS
  *  cui_gid
  * RETURNS
  *  void
 *****************************************************************************/
void cui_dtcnt_select_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = cui_dtcnt_get_cntx_index_by_cui_id(cui_gid, 0);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CLOSE_INFO, cui_gid, index);

    if (index != -1)
    {
        g_cui_dtcnt_sel_index = 0;
        if (g_cui_dtcnt_sel_acct[index].curr_cui_id)
        {
            mmi_frm_group_close(g_cui_dtcnt_sel_acct[index].curr_cui_id);
        }
        memset(&g_cui_dtcnt_sel_acct[index], 0, sizeof(cui_dtcnt_select_account_option_struct));
    }

}


/*****************************************************************************
 * FUNCTION
 *	cui_dtcnt_select_create
 * DESCRIPTION
 *	to create data account select group
 * PARAMETERS
 *	group_id
 * RETURNS
 *	cui_gid
*****************************************************************************/
mmi_id cui_dtcnt_select_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* To find a empty CUI context slot to support multi-instance*/

    for (i = 0; i < CUI_DTCNT_MAX_BEARER_LIST_NUM; i++)
    {
        if (!g_cui_dtcnt_sel_acct[i].valid)
        {
            break;
        }
    }
    /* If no CUI context, return error */
    if (i == CUI_DTCNT_MAX_BEARER_LIST_NUM)
    {
       MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CREATE_ERROR);

        return GRP_ID_INVALID;
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CREATE_INFO, parent_gid, i);

    g_cui_dtcnt_sel_index = i;
    memset(&g_cui_dtcnt_sel_acct[i], 0, sizeof(cui_dtcnt_select_account_option_struct));

    g_cui_dtcnt_sel_acct[i].valid = 1;
    g_cui_dtcnt_sel_acct[i].curr_cui_id = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_dtcnt_select_group_proc, (void *)&i);
      
    return g_cui_dtcnt_sel_acct[i].curr_cui_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_account_select_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for single account CUI list
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_single_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_delete_pre_acct_selection_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_delete_pre_acct_selection_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_LIST);
    mmi_frm_scrn_close(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST);
    mmi_frm_scrn_close(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_CBM_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_entry_select_account_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_data [IN] screen data, include group id and screen id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_single(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *gui_buffer;						        /* Buffer holding history data */
    U8 *item_name[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM + 5];
    static U8 *PopUpDescription[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM + 5];
    mmi_id scr_group_id = 0;
    MMI_BOOL ret_val;
    mmi_scenario_state_enum screen_state;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    scr_group_id = scrn_data->group_id;
    if (scr_group_id)
    {
        g_cui_dtcnt_sel_index = cui_dtcnt_get_cntx_index_by_cui_id(scr_group_id, 0);
    }

    /* prepare list info */
    cui_dtcnt_prepare_list_info_single(
        g_cui_dtcnt_sel_index, 
        (U8*)(&g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number), 
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].option, 
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info);
    
    /* get first item */
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected = cui_dtcnt_get_first_entry_highlight_item(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_id, MMI_FALSE, MMI_FALSE);
                
    for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number; i++)
    {
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type != CUI_DTCNT_ITEM_CSD &&
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type != CUI_DTCNT_ITEM_GPRS)
        {
            item_name[i] = (U8 *)GetString(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_name_str_id);
            PopUpDescription[i] = NULL;
        }
        else
        {
            item_name[i] = g_comm_disp_name_addr_arr[i].data_account_name;
            PopUpDescription[i] = g_comm_disp_name_addr_arr[i].data_account_addr;
        }
    }

    ret_val = mmi_frm_scrn_enter(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_LIST, NULL, (FuncPtr)cui_dtcnt_entry_select_account_single, MMI_FRM_FULL_SCRN);
    if (ret_val == MMI_FALSE)
    {
        return;
    }
    screen_state = mmi_frm_scrn_get_state(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_LIST);
	
    if (screen_state == MMI_SCENARIO_STATE_FIRST_ENTRY)
    {
        cui_dtcnt_delete_pre_acct_selection_screen();
    }
    mmi_frm_scrn_set_leave_proc (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_LIST, cui_dtcnt_leave_callback);

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id,  SCR_ID_DTCNT_CUI_NORMAL_LIST);
    
    if (!gui_buffer)
    {
        g_bt_sim_unavailable_flag = MMI_FALSE;
        g_bt_sim_available_flag = MMI_FALSE;
    }
    else
    {
        if (g_bt_sim_available_flag)
        {
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected = g_need_restore_highlight_index;
            gui_buffer = NULL;
            g_bt_sim_unavailable_flag = MMI_FALSE;
            g_bt_sim_available_flag = MMI_FALSE;
        }
    }
    RegisterHighlightHandler(cui_dtcnt_entry_select_account_single_highlight_hdlr);
    
    if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number)
    {
        wgui_list_menu_enable_access_by_shortcut();
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
        {
            ShowCategory89Screen(
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
                gui_buffer);
        }
        else
        {
        ShowCategory89Screen(
            STR_GLOBAL_DATA_ACCOUNT,
                GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
            (U8 **) item_name,
            //(PU16) gIndexIconsImageList,
            PopUpDescription,
            0,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
            gui_buffer);
        }
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetLeftSoftkeyFunction(cui_dtcnt_single_select_ok, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(cui_dtcnt_single_select_ok, KEY_EVENT_UP);
    }
    else
    {
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
        {
            ShowCategory89Screen(
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
                gui_buffer);
        }
        else
        {
        ShowCategory89Screen(
            STR_GLOBAL_DATA_ACCOUNT,
                GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
            (U8 **) item_name,
            //(PU16) gIndexIconsImageList,
            PopUpDescription,
            0,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
            gui_buffer);
        }

        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, 0);
    }
    SetRightSoftkeyFunction(cui_dtcnt_cancel_cui, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_prepare_list_info_cbm
 * DESCRIPTION
 *  To prepare the list info for CUI by passing the context index
 * PARAMETERS
 *  cntx_index  [IN]
 *  num        [OUT]
 *  option     [IN]
 *  list_info   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_prepare_list_info_cbm(U8 cntx_index, U8 *num, cui_dtcnt_select_option_enum option, cui_dtcnt_list_disp_struct *list_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 i = g_cui_dtcnt_sel_acct[cntx_index].list_item_number;
    U32 acct_id;
    U8 list_num = 0;
    U8 selected = 0;
    srv_dtcnt_prof_str_info_qry_struct acct_data;
    S32 start = 0;
		
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    memset(g_comm_disp_name_addr_arr, 0, sizeof(g_comm_disp_name_addr_arr));
    
#ifdef __MMI_WLAN_FEATURES__
    if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_WIFI) &&
        (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY))
    {
        list_info[list_num].item_type = CUI_DTCNT_ITEM_WIFI_LIST;
        list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_WIFI].item_name;
        list_num++;
    }
#endif
	start = list_num;
    /* for GPRS user defined profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {
        #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
        #else
                selected = 1;
        #endif
        
            if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;                 
                }
        
                if (selected)
                {
                    g_cui_dtcnt_sel_acct[cntx_index].list_gprs_userdef_num++;
                    list_info[list_num].item_type = CUI_DTCNT_ITEM_GPRS;
                    list_info[list_num].account_type = DTCNT_USER_CONFIGURED_ACCT;
                    list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;
                    
                    mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, 
                                                (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                                                MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                                MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);

                    acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                    acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;

                    srv_dtcnt_get_apn(g_mmi_dtcnt_list_item[i].profile_id,
                                      &acct_data,
                                      SRV_DTCNT_ACCOUNT_PRIMARY); 
                    list_num++;
                }
            }
        }
        }
        cui_dtcnt_arrange_account_list(list_info, 
            g_comm_disp_name_addr_arr,
            start, 
            list_num);
        start = list_num;

        /* for CSD user defined profile */
        for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
        {
    	#ifdef __MMI_WLAN_FEATURES__
            if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD) &&
                (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY) &&
                g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
                (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
                 g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
        #else /* __MMI_WLAN_FEATURES__ */
            if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD &&
                g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
                (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
                 g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
        #endif /* __MMI_WLAN_FEATURES__ */
        	{
        		selected = 0;
        		/* for wap only http connection type profile filter */
        		if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
        		{
        
            #ifdef __GEMINI__
                    if (option & CUI_DTCNT_SELECT_SIM)
                    {
                        selected = 1;
                    }
                    else
                    {
                        if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                            g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                        {
                            selected = 1;
                        }
                        if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                            g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                        {
                            selected = 1;
                        }
                        if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                        {
                            selected = 1;
                        }
                        if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                            g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                        {
                            selected = 1;
                        }
                        if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                        {
                            selected = 1;
                        }
                        if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                        {
                            selected = 1;
                        }
                    }
            #else
                    selected = 1;
            #endif
                
                    if(!srv_sim_ctrl_any_sim_is_available())
                    {
                        selected = 0;                 
                    }            
                    if (selected)
                    {
                        g_cui_dtcnt_sel_acct[cntx_index].list_csd_userdef_num++;
                        list_info[list_num].item_type = CUI_DTCNT_ITEM_CSD;
                        list_info[list_num].account_type = DTCNT_USER_CONFIGURED_ACCT;
                        list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;

                        mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id,
                                                   (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                                                   MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                                   MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                        
                        acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                        acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                        
                        srv_dtcnt_get_csd_number(g_mmi_dtcnt_list_item[i].profile_id,
                                                 &acct_data,
                                                 SRV_DTCNT_ACCOUNT_PRIMARY); 

                        list_num++;
                    }
                }
            }
        }

        cui_dtcnt_arrange_account_list(list_info, 
            g_comm_disp_name_addr_arr,
            start, 
            list_num);
        start = list_num;
        /* for GPRS SIM default profile */
        for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
        {
    #ifdef __MMI_WLAN_FEATURES__
        if (((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT)
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT)
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {
            #ifdef __GEMINI__
            if (option & CUI_DTCNT_SELECT_SIM)
            {
            	selected = 1;
            }
            else
            {
            	if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
            		g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
            	{
            		selected = 1;
            	}
            	if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
            		g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
            	{
            		selected = 1;
            	}
                if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                {
                    selected = 1;
                }
                if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                    g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                {
                    selected = 1;
                }
                if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                {
                    selected = 1;
                }
            	if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
            	{
            		selected = 1;
            	}
            }
            #else
            selected = 1;
            #endif
            
            if(!srv_sim_ctrl_any_sim_is_available())
            {
            	selected = 0;				 
            }
            
            if (selected)
            {
            	g_cui_dtcnt_sel_acct[cntx_index].list_gprs_default_num++;
            	list_info[list_num].item_type = CUI_DTCNT_ITEM_GPRS;
            	list_info[list_num].account_type = DTCNT_FACTORY_CONFIGURED_ACCT;
            	list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;

                mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, 
                                            (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                                            MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                            MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                
                acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                
                srv_dtcnt_get_apn(g_mmi_dtcnt_list_item[i].profile_id,
                						 &acct_data,
                						 SRV_DTCNT_ACCOUNT_PRIMARY); 

                list_num++;
            }
            }
            
            }
            }
            cui_dtcnt_arrange_account_list(list_info, 
                g_comm_disp_name_addr_arr,
                start, 
                list_num);
            start = list_num;
            /* for CSD SIM default profile */
            for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
            {
        #ifdef __MMI_WLAN_FEATURES__
            if (((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD) &&
                (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)) &&
                g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
                g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT)
        #else /* __MMI_WLAN_FEATURES__ */
            if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD &&
                g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
                g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT)
        #endif /* __MMI_WLAN_FEATURES__ */
            {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {
            
            #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
            #else
                selected = 1;
            #endif
            
                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;                 
                }            
                if (selected)
                {
                    g_cui_dtcnt_sel_acct[cntx_index].list_csd_default_num++;
                    list_info[list_num].item_type = CUI_DTCNT_ITEM_CSD;
                    list_info[list_num].account_type = DTCNT_FACTORY_CONFIGURED_ACCT;
                    list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;
                    
                    mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, 
                                                (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                                                MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                                MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                    
                    acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                    acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                    
                    srv_dtcnt_get_csd_number(g_mmi_dtcnt_list_item[i].profile_id,
                                             &acct_data,
                                             SRV_DTCNT_ACCOUNT_PRIMARY); 
                    list_num++;
                }
            }
            
        }
    }
    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);

    *num = list_num;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_prepare_list_info_single
 * DESCRIPTION
 *  To prepare the list info for CUI by passing the context index
 * PARAMETERS
 *  cntx_index  [IN]
 *  num        [OUT]
 *  list_info   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_prepare_list_info_single(U8 cntx_index, U8 *num, cui_dtcnt_select_option_enum option, cui_dtcnt_list_disp_struct *list_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = g_cui_dtcnt_sel_acct[cntx_index].list_item_number;
    U32 acct_id;
    U8 list_num = 0;
    U8 selected = 0;
    srv_dtcnt_prof_str_info_qry_struct acct_data;
    S32 start = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_comm_disp_name_addr_arr, 0, sizeof(g_comm_disp_name_addr_arr));
    /* Always has auto item */
    list_info[list_num].item_type = CUI_DTCNT_ITEM_AUTO;
    list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_AUTO].item_name;
    list_num++;

#ifdef __MMI_WLAN_FEATURES__
    if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_WIFI) &&
        (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY))
    {
        list_info[list_num].item_type = CUI_DTCNT_ITEM_WIFI;
        list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_WIFI].item_name;
        list_num++;
    }
#endif

#ifdef __MMI_CBM_ALWAYS_ASK__
    if(option & CUI_DTCNT_SELECT_ALWAYS_ASK)
    {
        list_info[list_num].item_type = CUI_DTCNT_ITEM_ALWAYS_ASK;
        list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_ALWAYS_ASK].item_name;
        list_num++;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    start = list_num;
    /* for GPRS user defined profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {
            #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
            #else
                selected = 1;
            #endif

                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;                
                }

                if (selected)
                {
				    g_cui_dtcnt_sel_acct[cntx_index].list_gprs_userdef_num++;
				    list_info[list_num].item_type = CUI_DTCNT_ITEM_GPRS;
				    list_info[list_num].account_type = DTCNT_USER_CONFIGURED_ACCT;
				    list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;

                    mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                    
                    acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                    acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                    
                    srv_dtcnt_get_apn(g_mmi_dtcnt_list_item[i].profile_id,
                                      &acct_data,
                                      SRV_DTCNT_ACCOUNT_PRIMARY); 
                                      list_num++;
                }
            }
        }
    }
    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);
    start = list_num;
    /* for CSD user defined profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {

            #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
            #else
                selected = 1;
            #endif
			
                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;				 
                }			
                if (selected)
                {
                	g_cui_dtcnt_sel_acct[cntx_index].list_csd_userdef_num++;
                	list_info[list_num].item_type = CUI_DTCNT_ITEM_CSD;
                	list_info[list_num].account_type = DTCNT_USER_CONFIGURED_ACCT;
                	list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;

                    mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                    
                    acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                    acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                    
                    srv_dtcnt_get_csd_number(g_mmi_dtcnt_list_item[i].profile_id,
                                             &acct_data,
                                             SRV_DTCNT_ACCOUNT_PRIMARY); 

                	list_num++;
                }
            }
        }
    }
    
	cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);
    start = list_num;
    
    /* for GPRS SIM default profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if (((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {
            #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
            #else
                selected = 1;
            #endif

                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;                
                }

                if (selected)
                {
				    g_cui_dtcnt_sel_acct[cntx_index].list_gprs_default_num++;
				    list_info[list_num].item_type = CUI_DTCNT_ITEM_GPRS;
				    list_info[list_num].account_type = DTCNT_FACTORY_CONFIGURED_ACCT;
				    list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;

                    mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                    
                    acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                    acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                    
                    srv_dtcnt_get_apn(g_mmi_dtcnt_list_item[i].profile_id,
                                      &acct_data,
                                      SRV_DTCNT_ACCOUNT_PRIMARY); 

				    list_num++;
                }
            }

        }
    }
    
    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);
    start = list_num;
    
    /* for CSD SIM default profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
    #ifdef __MMI_WLAN_FEATURES__
        if (((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {

#ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
#else
                selected = 1;
#endif
			
                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;				 
                }			
                if (selected)
                {
                	g_cui_dtcnt_sel_acct[cntx_index].list_csd_default_num++;
                	list_info[list_num].item_type = CUI_DTCNT_ITEM_CSD;
                	list_info[list_num].account_type = DTCNT_FACTORY_CONFIGURED_ACCT;
                	list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;

                    mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                    
                    acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                    acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                    
                    srv_dtcnt_get_csd_number(g_mmi_dtcnt_list_item[i].profile_id,
                                             &acct_data,
                                             SRV_DTCNT_ACCOUNT_PRIMARY); 

                	list_num++;
                }
            }

        }
    }
    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);

    *num = list_num;
}


#ifdef	__MMI_CBM_BEARER_FALLBACK__
/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_bearers_account_option_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void cui_dtcnt_select_bearers_account_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct *acct_info_ptr = OslMalloc(sizeof(cbm_account_info_struct));
    cui_dtcnt_select_event_struct evt;
    S16 error;
    U32 i, j, k;
    cbm_app_info_struct app_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(acct_info_ptr, 0, sizeof(cbm_account_info_struct));
    /* account info */
    acct_info_ptr->acct_num = 0;
    if (!abm_check_app_id(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id))
    {
        acct_info_ptr->app_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id;
    }
    else
    {
        acct_info_ptr->app_id = 0;
    }
    /* primary */
    acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].account_id = 
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id;
    acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].is_always_ask = 
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_is_always_ask;
    acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].sim_id = 
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_sim_info;
    acct_info_ptr->acct_num++;

    /* secondary */
    if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_exist)
    {
        acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT].account_id = 
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id;
        acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT].is_always_ask = 
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_is_always_ask;
        acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT].sim_id = 
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_sim_info;
        acct_info_ptr->acct_num++;
    }
    cbm_encode_data_account_id_ext(0, 
                                &g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_id, 
                                acct_info_ptr);
    if (acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].account_id == 0x3e)
    {
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_id = MMI_DTCNT_INVALID_ID;
        acct_info_ptr->acct_num = 1;
    }

    abm_get_registered_app_name(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id, &app_info);
    if (!(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].option & CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT))
    {
    if (!g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_exist)
    {
        /* To add 1st account ap list to dtcnt list*/
        for (i = 0; i < g_mmi_dtcnt_acct_num; i++)
    	{
            if (g_mmi_dtcnt_list_item[i].profile_id == acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].account_id)
            {
                for (j = 0; j < g_mmi_dtcnt_list_item[i].app_info.ap_num; j++)
                {
    				if (g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_mmi_dtcnt_list_item[i].app_info.ap_num)
                {
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id = app_info.app_str_id;
                    
                    g_mmi_dtcnt_list_item[i].app_info.ap_num++;
                }
    
            }
            else
            {
                for (j = 0; j < g_mmi_dtcnt_list_item[i].app_info.ap_num; j++)
                {
    				if (g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
    
                    {
                        for (k = j; k < g_mmi_dtcnt_list_item[i].app_info.ap_num - 1; k++)
                        {
    						g_mmi_dtcnt_list_item[i].app_info.app_info[k] = g_mmi_dtcnt_list_item[i].app_info.app_info[k + 1];
                        }
                        g_mmi_dtcnt_list_item[i].app_info.app_info[k].app_icon_id = 0;
                        g_mmi_dtcnt_list_item[i].app_info.app_info[k].app_str_id = 0;
    
                        g_mmi_dtcnt_list_item[i].app_info.ap_num--;
                        break;
                    }
                }
            }
        }

        /* To add 1st account ap list to app info list nvram*/
        for (i = 0; i < g_app_info_nvram.acct_num; i++)
    	{
            if (g_app_info_nvram.acct_app_list[i].acct_id == acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].account_id)
            {
                for (j = 0; j < g_app_info_nvram.acct_app_list[i].app_info.ap_num; j++)
                {
    				if (g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_app_info_nvram.acct_app_list[i].app_info.ap_num)
                {
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id = app_info.app_str_id;
    
                    g_app_info_nvram.acct_app_list[i].app_info.ap_num++;
                    mmi_dtcnt_write_positive_app_info_nvram_ext((U16)i);
                }
                
            }
            else
            {
                for (j = 0; j < g_app_info_nvram.acct_app_list[i].app_info.ap_num; j++)
                {
    				if (g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        for (k = j; k < g_app_info_nvram.acct_app_list[i].app_info.ap_num - 1; k++)
                        {
                            g_app_info_nvram.acct_app_list[i].app_info.app_info[k] = g_app_info_nvram.acct_app_list[i].app_info.app_info[k + 1];
                        }
                        g_app_info_nvram.acct_app_list[i].app_info.app_info[k].app_icon_id = 0;
                        g_app_info_nvram.acct_app_list[i].app_info.app_info[k].app_str_id = 0;
    
                        g_app_info_nvram.acct_app_list[i].app_info.ap_num--;
                        mmi_dtcnt_write_positive_app_info_nvram_ext((U16)i);
                        break;
                    }
                }
            }
        }

    }
    else
    {
        /* delete all the previous app info for this app in context*/
        for (i = 0; i < g_mmi_dtcnt_acct_num; i++)
    	{
			for (j = 0; j < g_mmi_dtcnt_list_item[i].app_info.ap_num; j++)
			{
				if (g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
					g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
			
				{
					for (k = j; k < g_mmi_dtcnt_list_item[i].app_info.ap_num - 1; k++)
					{
						g_mmi_dtcnt_list_item[i].app_info.app_info[k] = g_mmi_dtcnt_list_item[i].app_info.app_info[k + 1];
					}
					g_mmi_dtcnt_list_item[i].app_info.app_info[k].app_icon_id = 0;
					g_mmi_dtcnt_list_item[i].app_info.app_info[k].app_str_id = 0;
			
					g_mmi_dtcnt_list_item[i].app_info.ap_num--;
					break;
				}
			}
        }
        /* delete all the previous app info for this app in NVRAM */
        for (i = 0; i < g_app_info_nvram.acct_num; i++)
    	{
            for (j = 0; j < g_app_info_nvram.acct_app_list[i].app_info.ap_num; j++)
            {
            	if (g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
            		g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                {
                    for (k = j; k < g_app_info_nvram.acct_app_list[i].app_info.ap_num - 1; k++)
                    {
                        g_app_info_nvram.acct_app_list[i].app_info.app_info[k] = g_app_info_nvram.acct_app_list[i].app_info.app_info[k + 1];
                    }
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[k].app_icon_id = 0;
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[k].app_str_id = 0;
            
                    g_app_info_nvram.acct_app_list[i].app_info.ap_num--;
                    mmi_dtcnt_write_positive_app_info_nvram_ext((U16)i);
                    break;
                }
            }
        }

        /* To add 1st account ap list to dtcnt list*/
        for (i = 0; i < g_mmi_dtcnt_acct_num; i++)
    	{
            if (g_mmi_dtcnt_list_item[i].profile_id == acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].account_id)
            {
                for (j = 0; j < g_mmi_dtcnt_list_item[i].app_info.ap_num; j++)
                {
    				if (g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_mmi_dtcnt_list_item[i].app_info.ap_num)
                {
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id = app_info.app_str_id;
                    
                    g_mmi_dtcnt_list_item[i].app_info.ap_num++;
                }
            }
        }

        /* To add 1st account ap list to app info list nvram*/
        for (i = 0; i < g_app_info_nvram.acct_num; i++)
    	{
            if (g_app_info_nvram.acct_app_list[i].acct_id == acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT].account_id)
            {
                for (j = 0; j < g_app_info_nvram.acct_app_list[i].app_info.ap_num; j++)
                {
    				if (g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_app_info_nvram.acct_app_list[i].app_info.ap_num)
                {
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id = app_info.app_str_id;
    
                    g_app_info_nvram.acct_app_list[i].app_info.ap_num++;
                    mmi_dtcnt_write_positive_app_info_nvram_ext((U16)i);
                }
                
            }

        }

	    /* To add 2nd account ap list to dtcnt list*/
        for (i = 0; i < g_mmi_dtcnt_acct_num; i++)
    	{
            if (g_mmi_dtcnt_list_item[i].profile_id == acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT].account_id)
            {
                for (j = 0; j < g_mmi_dtcnt_list_item[i].app_info.ap_num; j++)
                {
    				if (g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_mmi_dtcnt_list_item[i].app_info.ap_num)
                {
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_mmi_dtcnt_list_item[i].app_info.app_info[j].app_str_id = app_info.app_str_id;
                    
                    g_mmi_dtcnt_list_item[i].app_info.ap_num++;
                }
    
            }

        }

        /* To add ap list to app info list nvram*/
        for (i = 0; i < g_app_info_nvram.acct_num; i++)
    	{
            if (g_app_info_nvram.acct_app_list[i].acct_id == acct_info_ptr->account[MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT].account_id)
            {
                for (j = 0; j < g_app_info_nvram.acct_app_list[i].app_info.ap_num; j++)
                {
    				if (g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id == app_info.app_icon_id &&
    					g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id == app_info.app_str_id)
                    {
                        break;
                    }
                }
                if (j == g_app_info_nvram.acct_app_list[i].app_info.ap_num)
                {
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_icon_id = app_info.app_icon_id;
                    g_app_info_nvram.acct_app_list[i].app_info.app_info[j].app_str_id = app_info.app_str_id;
    
                    g_app_info_nvram.acct_app_list[i].app_info.ap_num++;
                    mmi_dtcnt_write_positive_app_info_nvram_ext((U16)i);
                }
                
            }
        }
    }

        mmi_dtcnt_reset_invalid_acct_ext(app_info.app_str_id, app_info.app_icon_id);
    }
    OslMfree(acct_info_ptr);
    acct_info_ptr = NULL;

    MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id);
    evt.account_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_id;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_APP_SELECT_OK, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_id);
    mmi_frm_group_send_to_parent(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, (mmi_group_event_struct*)&evt);

}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_entry_select_account_dual_primary_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_dual_primary_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_entry_select_account_dual_secondary_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_dual_secondary_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected2= nIndex;


}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_app_select_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_dual_primary_select_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_struct evt;
	U8 selected_index = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected;
    U32 acct_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].profile_id;
    U8 app_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id;
    cui_dtcnt_item_type_enum item_type = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].item_type;
    srv_dtcnt_prof_str_info_qry_struct acct_data;
    srv_dtcnt_bearer_enum srv_bearer;
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
    srv_dtcnt_sim_type_enum srv_sim_id = SRV_DTCNT_SIM_TYPE_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_is_always_ask = FALSE;
    switch(item_type)
    {
        case CUI_DTCNT_ITEM_AUTO:
        {
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id = CBM_DEFAULT_ACCT_ID;
            break;
        }
        case CUI_DTCNT_ITEM_WIFI:
        {
            cbm_get_valid_account_id(CBM_BEARER_WIFI, &g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id);
            break;
        }
        case CUI_DTCNT_ITEM_ALWAYS_ASK:
       	{
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id = cbm_encode_data_account_id(MMI_DTCNT_DEFAULT_ID, CBM_SIM_ID_SIM1, app_id, TRUE);
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_is_always_ask = TRUE;
            break;
        }
        case CUI_DTCNT_ITEM_CSD:
        case CUI_DTCNT_ITEM_GPRS:
        {
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id = acct_id;
            if (item_type == CUI_DTCNT_ITEM_GPRS)
            {
                srv_bearer = SRV_DTCNT_BEARER_GPRS;
            }
            else
            {
                srv_bearer = SRV_DTCNT_BEARER_CSD;
            }
            srv_sim_id = mmi_dtcnt_query_sim_info(acct_id, srv_bearer);
            
            switch(srv_sim_id)
            {
                case SRV_DTCNT_SIM_TYPE_1:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
                case SRV_DTCNT_SIM_TYPE_2:
                    cbm_sim_id = CBM_SIM_ID_SIM2;
                    break;
                case SRV_DTCNT_SIM_TYPE_3:
                    cbm_sim_id = CBM_SIM_ID_SIM3;
                    break;
                case SRV_DTCNT_SIM_TYPE_4:
                    cbm_sim_id = CBM_SIM_ID_SIM4;
                    break;
                default:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
            }            

            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_sim_info = cbm_sim_id;

            break;
        }
    }

    mmi_dtcnt_get_full_account_name(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id,
                            (PS8)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_name, 
                            MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                            MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);

    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_changed = MMI_TRUE;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_APP_SELECT_OK, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id);
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_dual_secondary_select_ok
 * DESCRIPTION
 *  secondary account select ok
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_dual_secondary_select_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_struct evt;
	U8 selected_index = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected2;
    U32 acct_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2[selected_index].profile_id;
    U8 app_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id;
    cui_dtcnt_item_type_enum item_type = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2[selected_index].item_type;
    srv_dtcnt_prof_str_info_qry_struct acct_data;
    srv_dtcnt_bearer_enum srv_bearer;
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
    srv_dtcnt_sim_type_enum srv_sim_id = SRV_DTCNT_SIM_TYPE_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_is_always_ask = FALSE;
    switch(item_type)
    {
        case CUI_DTCNT_ITEM_NONE:
        {
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id = MMI_DTCNT_INVALID_ID;
            break;
        }
        case CUI_DTCNT_ITEM_AUTO:
        {
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id = CBM_DEFAULT_ACCT_ID;
            break;
        }
        case CUI_DTCNT_ITEM_WIFI:
        {
            cbm_get_valid_account_id(CBM_BEARER_WIFI, &g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id);
            break;
        }
        case CUI_DTCNT_ITEM_ALWAYS_ASK:
       	{
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id = cbm_encode_data_account_id(MMI_DTCNT_DEFAULT_ID, CBM_SIM_ID_SIM1, app_id, TRUE);
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_is_always_ask = TRUE;
            break;
        }
        case CUI_DTCNT_ITEM_CSD:
        case CUI_DTCNT_ITEM_GPRS:
        {
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id = acct_id;
            if (item_type == CUI_DTCNT_ITEM_GPRS)
            {
                srv_bearer = SRV_DTCNT_BEARER_GPRS;
            }
            else
            {
                srv_bearer = SRV_DTCNT_BEARER_CSD;
            }
            srv_sim_id = mmi_dtcnt_query_sim_info(acct_id, srv_bearer);

            switch(srv_sim_id)
            {
                case SRV_DTCNT_SIM_TYPE_1:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
                case SRV_DTCNT_SIM_TYPE_2:
                    cbm_sim_id = CBM_SIM_ID_SIM2;
                    break;
                case SRV_DTCNT_SIM_TYPE_3:
                    cbm_sim_id = CBM_SIM_ID_SIM3;
                    break;
                case SRV_DTCNT_SIM_TYPE_4:
                    cbm_sim_id = CBM_SIM_ID_SIM4;
                    break;
                default:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
            }

            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_sim_info = cbm_sim_id;

            break;
        }
    }

    if (item_type != CUI_DTCNT_ITEM_NONE)
    {
        mmi_dtcnt_get_full_account_name(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id,
                            (PS8)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_name, 
                            MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                            MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);

        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_exist = MMI_TRUE;
    }
    else 
    {
        mmi_ucs2cpy((S8*)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_name, GetString(STR_GLOBAL_NONE));
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_exist = MMI_FALSE;
    }
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_changed = MMI_TRUE;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_APP_SELECT_OK, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_entry_select_account_dual_each
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_data [IN] screen data include group id and screen id 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_dual_each(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *gui_buffer;     /* Buffer holding history data */
    U8 *item_name[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM + 5];
    static U8 *PopUpDescription[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM + 5];

    MMI_BOOL ret_val;
    mmi_scenario_state_enum screen_state;
    mmi_id scr_group_id = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    scr_group_id = scrn_data->group_id;
    if (scr_group_id)
    {
        g_cui_dtcnt_sel_index = cui_dtcnt_get_cntx_index_by_cui_id(scr_group_id, 0);
    }
    if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].is_primary)
    {
        cui_dtcnt_prepare_list_info_dual(
            g_cui_dtcnt_sel_index, 
            (U8*)(&g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number), 
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].option, 
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info, 
            1);
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected = cui_dtcnt_get_first_entry_highlight_item(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id, MMI_TRUE, MMI_FALSE);
    }
    else
    {
        cui_dtcnt_prepare_list_info_dual(
            g_cui_dtcnt_sel_index, 
            (U8*)(&g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number2), 
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].option, 
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2, 
            0);        
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected2 = cui_dtcnt_get_first_entry_highlight_item(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id, MMI_TRUE, MMI_TRUE);
    }
    if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].is_primary)
    {
        for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number; i++)
        {
            if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type != CUI_DTCNT_ITEM_CSD &&
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type != CUI_DTCNT_ITEM_GPRS)
            {
                item_name[i] = (U8 *)GetString(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_name_str_id);
                PopUpDescription[i] = NULL;
            }
            else
            {
                item_name[i] = g_comm_disp_name_addr_arr[i].data_account_name;
                PopUpDescription[i] = g_comm_disp_name_addr_arr[i].data_account_addr;
            }
        }
    }
    else
    {
        for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number2; i++)
        {
            if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2[i].item_type != CUI_DTCNT_ITEM_CSD &&
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2[i].item_type != CUI_DTCNT_ITEM_GPRS)
            {
                item_name[i] = (U8 *)GetString(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2[i].item_name_str_id);
                PopUpDescription[i] = NULL;
            }
            else
            {
                item_name[i] = g_comm_disp_name_addr_arr[i].data_account_name;
                PopUpDescription[i] = g_comm_disp_name_addr_arr[i].data_account_addr;
            }
        }
    }

    ret_val = mmi_frm_scrn_enter(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH, NULL, (FuncPtr)cui_dtcnt_entry_select_account_dual_each, MMI_FRM_FULL_SCRN);
    if (ret_val == MMI_FALSE)
    {
        return;
    }
    screen_state = mmi_frm_scrn_get_state(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH);
	
    if (screen_state == MMI_SCENARIO_STATE_FIRST_ENTRY)
    {
        cui_dtcnt_delete_pre_acct_selection_screen();
    }
    mmi_frm_scrn_set_leave_proc (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH, cui_dtcnt_leave_callback);
    gui_buffer = mmi_frm_scrn_get_gui_buf(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id,  SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH);

    if (!gui_buffer)
    {
        g_bt_sim_unavailable_flag = MMI_FALSE;
        g_bt_sim_available_flag = MMI_FALSE;
    }
    else
    {
        if (g_bt_sim_available_flag)
        {
            if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].is_primary)
            {                    
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected = g_need_restore_highlight_index;
            }
            else
            {                    
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected2 = g_need_restore_highlight_index2;
            }
            gui_buffer = NULL;
            g_bt_sim_unavailable_flag = MMI_FALSE;
            g_bt_sim_available_flag = MMI_FALSE;
        }
    }
    
    if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].is_primary)
    {
        RegisterHighlightHandler(cui_dtcnt_entry_select_account_dual_primary_highlight_hdlr);
    
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number)
        {
            wgui_list_menu_enable_access_by_shortcut();
			if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
			{
				ShowCategory89Screen(
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
					STR_GLOBAL_OK,
					IMG_GLOBAL_OK,
					STR_GLOBAL_BACK,
					IMG_GLOBAL_BACK,
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
					(U8 **) item_name,
					//(PU16) gIndexIconsImageList,
					PopUpDescription,
					0,
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
					gui_buffer);
			}
			else
			{
            ShowCategory89Screen(
                STR_GLOBAL_DATA_ACCOUNT,
					GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
                gui_buffer);
			}

            SetLeftSoftkeyFunction(cui_dtcnt_dual_primary_select_ok, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(cui_dtcnt_dual_primary_select_ok, KEY_EVENT_UP);
        }
        else
        {

			if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
			{
				ShowCategory89Screen(
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
					0,
					0,
					STR_GLOBAL_BACK,
					IMG_GLOBAL_BACK,
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
					(U8 **) item_name,
					//(PU16) gIndexIconsImageList,
					PopUpDescription,
					0,
					g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
					gui_buffer);
			}
			else
			{
            ShowCategory89Screen(
                STR_GLOBAL_DATA_ACCOUNT,
					GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
                gui_buffer);
			}

            SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, 0);
        }
        SetRightSoftkeyFunction(cui_dtcnt_go_back_history, KEY_EVENT_UP);
    }
    else
    {
        RegisterHighlightHandler(cui_dtcnt_entry_select_account_dual_secondary_highlight_hdlr);
	wgui_list_menu_enable_access_by_shortcut();
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
        {
            ShowCategory89Screen(
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number2,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected2,
                gui_buffer);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetLeftSoftkeyFunction(cui_dtcnt_dual_secondary_select_ok, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_dtcnt_dual_secondary_select_ok, KEY_EVENT_UP);
        }
        else
        {
            ShowCategory89Screen(
                STR_GLOBAL_DATA_ACCOUNT,
                GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number2,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected2,
                gui_buffer);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetLeftSoftkeyFunction(cui_dtcnt_dual_secondary_select_ok, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_dtcnt_dual_secondary_select_ok, KEY_EVENT_UP);
        }
        SetRightSoftkeyFunction(cui_dtcnt_go_back_history, KEY_EVENT_UP);
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_account
 * DESCRIPTION
 *  To prepare the list info for CUI by passing the context index
 * PARAMETERS
 *  cntx_index  [IN]
 *  num        [OUT]
 *  list_info   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_prepare_list_info_dual(U8 cntx_index, U8 *num, cui_dtcnt_select_option_enum option, cui_dtcnt_list_disp_struct *list_info, U8 is_primary)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = g_cui_dtcnt_sel_acct[cntx_index].list_item_number;
    U8 list_num = 0;
    U8 selected = 0;	
    srv_dtcnt_prof_str_info_qry_struct acct_data;
    S32 start = 0;
    U32 pure_primary_id, pure_secondary_id, skip_id = CBM_INVALID_NWK_ACCT_ID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_comm_disp_name_addr_arr, 0, sizeof(g_comm_disp_name_addr_arr));
    /* the secondary account must have NONE item */
    if (!is_primary)
    {
        list_info[list_num].item_type = CUI_DTCNT_ITEM_NONE;
        list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_NONE].item_name;
        list_num++;        
    }

    pure_primary_id = cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id);
    pure_secondary_id = cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id);

    /* not Always has auto item */
    if ((is_primary && pure_secondary_id != CBM_DEFAULT_ACCT_ID) ||
        (!is_primary && pure_primary_id != CBM_DEFAULT_ACCT_ID))
    {
        list_info[list_num].item_type = CUI_DTCNT_ITEM_AUTO;
        list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_AUTO].item_name;
        list_num++;
    }

#ifdef __MMI_WLAN_FEATURES__
	if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_WIFI) &&
        (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY))
    {
        if ((is_primary && ((pure_secondary_id == CBM_DEFAULT_ACCT_ID) || srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) != SRV_DTCNT_BEARER_WIFI)) ||
            (!is_primary && ((pure_primary_id == CBM_DEFAULT_ACCT_ID) || srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) != SRV_DTCNT_BEARER_WIFI)))
        {
            list_info[list_num].item_type = CUI_DTCNT_ITEM_WIFI;
            list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_WIFI].item_name;
            list_num++;
        }
    }    

#endif

#ifdef __MMI_CBM_ALWAYS_ASK__
    if(option & CUI_DTCNT_SELECT_ALWAYS_ASK)
    {
        if ((is_primary && !g_cui_dtcnt_sel_acct[cntx_index].secondary_is_always_ask) ||
            (!is_primary && !g_cui_dtcnt_sel_acct[cntx_index].primary_is_always_ask))
        {
            list_info[list_num].item_type = CUI_DTCNT_ITEM_ALWAYS_ASK;
            list_info[list_num].item_name_str_id = g_cui_dtcnt_selection_itmes[CUI_DTCNT_ITEM_ALWAYS_ASK].item_name;
            list_num++;
        }
    }
#endif /* __MMI_CBM_ALWAYS_ASK__ */
    if (is_primary)
    {
        if (!g_cui_dtcnt_sel_acct[cntx_index].secondary_is_always_ask && (pure_secondary_id != CBM_DEFAULT_ACCT_ID)) // always ask will encode account 0
        {
            skip_id = pure_secondary_id;
        }
    }
    else
    {
        if (!g_cui_dtcnt_sel_acct[cntx_index].primary_is_always_ask && (pure_primary_id != CBM_DEFAULT_ACCT_ID)) // always ask will encode account 0
        {
            skip_id = pure_primary_id;
        }
    }
    start = list_num;
    /* for GPRS user defined profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (skip_id == g_mmi_dtcnt_list_item[i].profile_id)
        {
            continue;
        }
    #ifdef __MMI_WLAN_FEATURES__
        if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {
            #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
            #else
                selected = 1;
            #endif

                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;                
                }

                if (selected)
                {
                    if ((is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) != SRV_DTCNT_BEARER_GPRS) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) == SRV_DTCNT_BEARER_GPRS) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))) || 
                        (is_primary && (g_cui_dtcnt_sel_acct[cntx_index].secondary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary && (g_cui_dtcnt_sel_acct[cntx_index].primary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) != SRV_DTCNT_BEARER_GPRS) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) == SRV_DTCNT_BEARER_GPRS) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))))
                    {
				        g_cui_dtcnt_sel_acct[cntx_index].list_gprs_userdef_num++;
				        list_info[list_num].item_type = CUI_DTCNT_ITEM_GPRS;
				        list_info[list_num].account_type = DTCNT_USER_CONFIGURED_ACCT;
				        list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;
                        
                        mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id,
                            (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                            MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                            MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                       
                        acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                        acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
                       
                        srv_dtcnt_get_apn(g_mmi_dtcnt_list_item[i].profile_id,
                       				      &acct_data,
                       				      SRV_DTCNT_ACCOUNT_PRIMARY); 
				        list_num++;
                    }
                }
            }
        }
    }

    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
            start, 
            list_num);
    start = list_num;
    /* for CSD user defined profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (skip_id == g_mmi_dtcnt_list_item[i].profile_id)
        {
            continue;
        }
    #ifdef __MMI_WLAN_FEATURES__
        if ((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_USER_CONFIGURED_ACCT ||
             g_mmi_dtcnt_list_item[i].account_type == DTCNT_OTA_CONFIGURED_ACCT))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {

            #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
            #else
                selected = 1;
            #endif
			
                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;				 
                }			
                if (selected)
                {
                    if ((is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) != SRV_DTCNT_BEARER_CSD) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) == SRV_DTCNT_BEARER_CSD) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))) || 
                        (is_primary && (g_cui_dtcnt_sel_acct[cntx_index].secondary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary && (g_cui_dtcnt_sel_acct[cntx_index].primary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) != SRV_DTCNT_BEARER_CSD) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) == SRV_DTCNT_BEARER_CSD) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))))
                    {
                        g_cui_dtcnt_sel_acct[cntx_index].list_csd_userdef_num++;
                        list_info[list_num].item_type = CUI_DTCNT_ITEM_CSD;
                        list_info[list_num].account_type = DTCNT_USER_CONFIGURED_ACCT;
                        list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;
                        
                        mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id,
                                                    (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                                                    MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                                    MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
						
						acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                        acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
						
						srv_dtcnt_get_csd_number(g_mmi_dtcnt_list_item[i].profile_id,
										         &acct_data,
										         SRV_DTCNT_ACCOUNT_PRIMARY); 

                        list_num++;
                    }
                }
            }
        }
    }
    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);
    start = list_num;
    /* for GPRS SIM default profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (skip_id == g_mmi_dtcnt_list_item[i].profile_id)
        {
            continue;
        }
    #ifdef __MMI_WLAN_FEATURES__
        if (((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_GPRS &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_GPRS && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {
            #ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
            #else
                selected = 1;
            #endif

                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;                
                }

                if (selected)
                {
                    if ((is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) != SRV_DTCNT_BEARER_GPRS) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) == SRV_DTCNT_BEARER_GPRS) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))) || 
                        (is_primary && (g_cui_dtcnt_sel_acct[cntx_index].secondary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary && (g_cui_dtcnt_sel_acct[cntx_index].primary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) != SRV_DTCNT_BEARER_GPRS) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) == SRV_DTCNT_BEARER_GPRS) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))))
                	{
				        g_cui_dtcnt_sel_acct[cntx_index].list_gprs_default_num++;
				        list_info[list_num].item_type = CUI_DTCNT_ITEM_GPRS;
				        list_info[list_num].account_type = DTCNT_FACTORY_CONFIGURED_ACCT;
				        list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;
						
                        mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id, 
                                                    (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                                                    MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                                    MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
						
						acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                        acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
						
						srv_dtcnt_get_apn(g_mmi_dtcnt_list_item[i].profile_id,
												 &acct_data,
												 SRV_DTCNT_ACCOUNT_PRIMARY); 

				        list_num++;
                    }
                }
            }

        }
    }

    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);
    start = list_num;
    
    /* for CSD SIM default profile */
    for (i = 0; i < MMI_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (skip_id == g_mmi_dtcnt_list_item[i].profile_id)
        {
            continue;
        }
    #ifdef __MMI_WLAN_FEATURES__
        if (((g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD) &&
            (mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY)) &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #else /* __MMI_WLAN_FEATURES__ */
        if (g_cui_dtcnt_sel_acct[cntx_index].bearers & DATA_ACCOUNT_BEARER_CSD &&
            g_mmi_dtcnt_list_item[i].bearer_type == DATA_ACCOUNT_BEARER_CSD && 
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_FACTORY_CONFIGURED_ACCT ||
            (g_mmi_dtcnt_list_item[i].account_type == DTCNT_PROF_TYPE_SIM_PROF &&
            option & CUI_DTCNT_SELECT_SIM_PROFILE)))
    #endif /* __MMI_WLAN_FEATURES__ */
        {
            selected = 0;
            /* for wap only http connection type profile filter */
            if (((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) && g_mmi_dtcnt_list_item[i].connection_type == 1) || ((option & CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY) == 0))
            {

#ifdef __GEMINI__
                if (option & CUI_DTCNT_SELECT_SIM)
                {
                    selected = 1;
                }
                else
                {
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM1 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM2 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_2)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM3 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_3)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM4 &&
                        g_mmi_dtcnt_list_item[i].sim_info == SRV_DTCNT_SIM_TYPE_4)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_SIM_ALL)
                    {
                        selected = 1;
                    }
                    if (g_cui_dtcnt_sel_acct[cntx_index].sim_selection == CUI_DTCNT_SELECT_DUAL_SIM)
                    {
                        selected = 1;
                    }
                }
#else
                selected = 1;
#endif
			
                if(!srv_sim_ctrl_any_sim_is_available())
                {
                    selected = 0;				 
                }			
                if (selected)
                {
                    if ((is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) != SRV_DTCNT_BEARER_CSD) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id, 1) == SRV_DTCNT_BEARER_CSD) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))) || 
                        (is_primary && (g_cui_dtcnt_sel_acct[cntx_index].secondary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].secondary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary && (g_cui_dtcnt_sel_acct[cntx_index].primary_is_always_ask || 
                            cbm_get_original_account(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id) == CBM_DEFAULT_ACCT_ID)) ||
                        (!is_primary &&
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) != SRV_DTCNT_BEARER_CSD) ||
                        ((srv_dtcnt_get_bearer_type(g_cui_dtcnt_sel_acct[cntx_index].primary_account_id, 1) == SRV_DTCNT_BEARER_CSD) && 
                        (g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH)))))
                    {
                        g_cui_dtcnt_sel_acct[cntx_index].list_csd_default_num++;
                        list_info[list_num].item_type = CUI_DTCNT_ITEM_CSD;
                        list_info[list_num].account_type = DTCNT_FACTORY_CONFIGURED_ACCT;
                        list_info[list_num].profile_id = g_mmi_dtcnt_list_item[i].profile_id;
                        
                        mmi_dtcnt_get_full_account_name(g_mmi_dtcnt_list_item[i].profile_id,
                                                    (PS8)g_comm_disp_name_addr_arr[list_num].data_account_name, 
                                                    MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                                    MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
						
						acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
                        acct_data.dest = (S8*)g_comm_disp_name_addr_arr[list_num].data_account_addr;
						
						srv_dtcnt_get_csd_number(g_mmi_dtcnt_list_item[i].profile_id,
										         &acct_data,
										         SRV_DTCNT_ACCOUNT_PRIMARY); 

                        list_num++;
                    }
                }
            }

        }
    }
    cui_dtcnt_arrange_account_list(list_info, 
        g_comm_disp_name_addr_arr,
        start, 
        list_num);

    *num = list_num;

}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_primary_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dtcnt_select_primary_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id,
        SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH,
        (FuncPtr) cui_dtcnt_entry_select_account_dual_each,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_secondary_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dtcnt_select_secondary_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id,
        SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH,
        (FuncPtr) cui_dtcnt_entry_select_account_dual_each,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *	cui_dtcnt_select_account_dual_highlight_hdlr
 * DESCRIPTION
 *	for dual account highlight handler
 * PARAMETERS
 *	nIndex		[IN]		
 * RETURNS
 *	void
 *****************************************************************************/
void cui_dtcnt_select_account_dual_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].is_primary = 1 - nIndex;
    if (nIndex == MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT)
    {
        SetLeftSoftkeyFunction(cui_dtcnt_select_primary_account, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(cui_dtcnt_select_primary_account, KEY_EVENT_UP);
    }
    else if (nIndex == MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT)
    {
        SetLeftSoftkeyFunction(cui_dtcnt_select_secondary_account, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(cui_dtcnt_select_secondary_account, KEY_EVENT_UP);
    }
}



/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_entry_select_account_dual
 * DESCRIPTION
 *  To enter dual account selection screen
 * PARAMETERS
 *  scrn_data [IN] screen data include group id and screen id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_dual(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    static S8 *accts_name[MMI_DTCNT_BEARER_FALLBACK_ACCOUNT_NUMBER_TOTAL];
    static S8 *accts_description[MMI_DTCNT_BEARER_FALLBACK_ACCOUNT_NUMBER_TOTAL];
    MMI_BOOL can_be_done = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_changed;
    MMI_BOOL ret_val = MMI_FALSE;
    mmi_scenario_state_enum screen_state;
    mmi_id scr_group_id = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_group_id = scrn_data->group_id;
    if (scr_group_id)
    {
        g_cui_dtcnt_sel_index = cui_dtcnt_get_cntx_index_by_cui_id(scr_group_id, 0);
    }

    accts_name[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT] = GetString(STR_ID_DTCNT_PRIMARY_ACCT);
    accts_name[MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT] = GetString(STR_ID_DTCNT_SECONDARY_ACCT);

    accts_description[MMI_DTCNT_BEARER_FALLBACK_PRIMARY_ACCTOUNT] = (S8*)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_name;
    accts_description[MMI_DTCNT_BEARER_FALLBACK_SECONDARY_ACCOUNT] = (S8*)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_name; 
    
    ret_val = mmi_frm_scrn_enter(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST, NULL, (FuncPtr)cui_dtcnt_entry_select_account_dual, MMI_FRM_FULL_SCRN);
    if (ret_val == MMI_FALSE)
    {
        return;
    }
    screen_state = mmi_frm_scrn_get_state(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST);
	
    if (screen_state == MMI_SCENARIO_STATE_FIRST_ENTRY)
    {
        cui_dtcnt_delete_pre_acct_selection_screen();
    }
    mmi_frm_scrn_set_leave_proc (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST, cui_dtcnt_leave_callback);
    gui_buffer = mmi_frm_scrn_get_gui_buf(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id,  SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST);

    RegisterHighlightHandler(cui_dtcnt_select_account_dual_highlight_hdlr);

    wgui_list_menu_enable_access_by_shortcut();
	if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
	{
		ShowCategory89Screen(
			g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
			g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
			STR_GLOBAL_EDIT,
			IMG_GLOBAL_OK,
			(U16)(can_be_done ? STR_GLOBAL_DONE : STR_GLOBAL_BACK),
			IMG_GLOBAL_BACK,
			MMI_DTCNT_BEARER_FALLBACK_ACCOUNT_NUMBER_TOTAL,
			(U8**)accts_name,
			//(U16*)gIndexIconsImageList,
			(U8**)accts_description,
			0,
			0,
			gui_buffer);

	}
	else
	{
    ShowCategory89Screen(
        STR_GLOBAL_DATA_ACCOUNT,
            GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        (U16)(can_be_done ? STR_GLOBAL_DONE : STR_GLOBAL_BACK),
        IMG_GLOBAL_BACK,
        MMI_DTCNT_BEARER_FALLBACK_ACCOUNT_NUMBER_TOTAL,
        (U8**)accts_name,
        //(U16*)gIndexIconsImageList,
        (U8**)accts_description,
        0,
        0,
        gui_buffer);
	}

    if (can_be_done)
    {
        SetRightSoftkeyFunction(cui_dtcnt_select_bearers_account_option_done, KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(cui_dtcnt_cancel_cui, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_display_real_acct_name
 * DESCRIPTION
 *  
 *  use this api to check it is valid to display the real account name in current prefer mode
 * PARAMETERS
 *  pure_acct_id    [IN]
 *  is_always_ask  [IN]
 * RETURNS
 *  MMI_TRUE if allow to call get_full_account_name, else return MMI_FALSE
 *****************************************************************************/
MMI_BOOL cui_dtcnt_display_real_acct_name(U32 pure_acct_id, U8 is_always_ask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                     */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                           */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_CBM_ALWAYS_ASK__
    if (is_always_ask)
    {
        return MMI_TRUE;
    }
    #endif
    if (CBM_DEFAULT_ACCT_ID == pure_acct_id)
    {
        return MMI_TRUE;        
    }
    if (CBM_WIFI_ACCT_ID == pure_acct_id)
    {
    
    #ifdef __MMI_WLAN_FEATURES__
        /* check prefer mode for WLAN */
        if ((mmi_netset_get_active_preferred_mode() != P_GSM_ONLY))
        {
            return MMI_TRUE;
        }
    #endif
        return MMI_FALSE;
    }

    /* check account is exist or not */
    for (i = 0; i < g_mmi_dtcnt_acct_num; i++)
    {
        if (g_mmi_dtcnt_list_item[i].profile_id == pure_acct_id)
        {
            break;
        }
    }
    /* check prefer mode for GPRS/CSD account */
    if ((mmi_netset_get_active_preferred_mode() != P_WLAN_ONLY))
    {
        return MMI_TRUE;
    }
    else if (i == g_mmi_dtcnt_acct_num)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_cbm_select_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_cbm_select_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dtcnt_select_event_struct evt;
	U8 selected_index = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected;
    U32 acct_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].profile_id;
    U8 app_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id;
    cui_dtcnt_item_type_enum item_type = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[selected_index].item_type;
    mmi_id wlan_cui_id = 0;
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;
    srv_dtcnt_sim_type_enum srv_sim_id = SRV_DTCNT_SIM_TYPE_1;
    srv_dtcnt_bearer_enum srv_bearer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(item_type)
    {
        case CUI_DTCNT_ITEM_AUTO:
        {
            acct_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, app_id, FALSE);
            break;
        }
        case CUI_DTCNT_ITEM_WIFI_LIST:
        {
#ifdef __MMI_WLAN_FEATURES__
            g_wlan_cui_id = cui_wlan_list_create(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id);
            cui_wlan_list_run(g_wlan_cui_id);
#endif
            return;
        }
        case CUI_DTCNT_ITEM_ALWAYS_ASK:
       	{
            acct_id = cbm_encode_data_account_id(MMI_DTCNT_DEFAULT_ID, CBM_SIM_ID_SIM1, app_id, TRUE);
            break;
        }
        case CUI_DTCNT_ITEM_CSD:
        case CUI_DTCNT_ITEM_GPRS:
        {
            if (item_type == CUI_DTCNT_ITEM_GPRS)
            {
                srv_bearer = SRV_DTCNT_BEARER_GPRS;
            }
            else
            {
                srv_bearer = SRV_DTCNT_BEARER_CSD;
            }

            srv_sim_id = mmi_dtcnt_query_sim_info(acct_id, srv_bearer);

            switch(srv_sim_id)
            {
                case SRV_DTCNT_SIM_TYPE_1:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
                case SRV_DTCNT_SIM_TYPE_2:
                    cbm_sim_id = CBM_SIM_ID_SIM2;
                    break;
                case SRV_DTCNT_SIM_TYPE_3:
                    cbm_sim_id = CBM_SIM_ID_SIM3;
                    break;
                case SRV_DTCNT_SIM_TYPE_4:
                    cbm_sim_id = CBM_SIM_ID_SIM4;
                    break;
                default:
                    cbm_sim_id = CBM_SIM_ID_SIM1;
                    break;
            }
            //cbm_sim_id = (srv_sim_id == SRV_DTCNT_SIM_TYPE_1 ? CBM_SIM_ID_SIM1 : CBM_SIM_ID_SIM2);
            
            acct_id = cbm_encode_data_account_id(acct_id, cbm_sim_id, app_id, FALSE);
            break;

        }
    }
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].account_id = acct_id;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_APP_SELECT_OK, acct_id);
	
    MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id);
	evt.account_id = acct_id;
	mmi_frm_group_send_to_parent(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, (mmi_group_event_struct*)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_entry_select_account_cbm_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_cbm_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_entry_select_account_cbm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_data [IN] screen data include group id and screen id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_entry_select_account_cbm(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *gui_buffer;        /* Buffer holding history data */
    U8 *item_name[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM + 5];
    static U8 *PopUpDescription[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM + 5];
    mmi_id scr_group_id = 0;
    MMI_BOOL ret_val;
    mmi_scenario_state_enum screen_state;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    scr_group_id = scrn_data->group_id;
    if (scr_group_id)
    {
        g_cui_dtcnt_sel_index = cui_dtcnt_get_cntx_index_by_cui_id(scr_group_id, 0);
    }

    cui_dtcnt_prepare_list_info_cbm(
        g_cui_dtcnt_sel_index, 
        (U8*)(&g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number), 
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].option, 
        g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info);
            
    for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number; i++)
    {
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type != CUI_DTCNT_ITEM_CSD &&
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type != CUI_DTCNT_ITEM_GPRS)
        {
            item_name[i] = (U8 *)GetString(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_name_str_id);
            PopUpDescription[i] = NULL;
        }
        else
        {
            item_name[i] = g_comm_disp_name_addr_arr[i].data_account_name;        
            PopUpDescription[i] = g_comm_disp_name_addr_arr[i].data_account_addr;            
        }
    }

    ret_val = mmi_frm_scrn_enter(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_CBM_LIST, NULL, (FuncPtr)cui_dtcnt_entry_select_account_cbm, MMI_FRM_FULL_SCRN);
    if (ret_val == MMI_FALSE)
    {
        return;
    }
    screen_state = mmi_frm_scrn_get_state(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_CBM_LIST);
	
    if (screen_state == MMI_SCENARIO_STATE_FIRST_ENTRY)
    {
        cui_dtcnt_delete_pre_acct_selection_screen();
    }
    mmi_frm_scrn_set_leave_proc (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, SCR_ID_DTCNT_CUI_CBM_LIST, cui_dtcnt_leave_callback);
    gui_buffer = mmi_frm_scrn_get_gui_buf(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id,  SCR_ID_DTCNT_CUI_CBM_LIST);


    RegisterHighlightHandler(cui_dtcnt_entry_select_account_cbm_highlight_hdlr);
    
    if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number)
    {
        wgui_list_menu_enable_access_by_shortcut();
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
        {
            ShowCategory89Screen(
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
                gui_buffer);
        }
        else
        {
        ShowCategory89Screen(
            STR_GLOBAL_DATA_ACCOUNT,
                GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
            (U8 **) item_name,
            //(PU16) gIndexIconsImageList,
            PopUpDescription,
            0,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
            gui_buffer);
        }

        SetLeftSoftkeyFunction(cui_dtcnt_cbm_select_ok, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(cui_dtcnt_cbm_select_ok, KEY_EVENT_UP);
    }
    else
    {
        if (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id && g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id)
        {
            ShowCategory89Screen(
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_str_id,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_icon_id,
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
                (U8 **) item_name,
                //(PU16) gIndexIconsImageList,
                PopUpDescription,
                0,
                g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
                gui_buffer);
        }
        else
        {
        ShowCategory89Screen(
            STR_GLOBAL_DATA_ACCOUNT,
                GetRootTitleIcon(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_menu_id),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number,
            (U8 **) item_name,
            //(PU16) gIndexIconsImageList,
            PopUpDescription,
            0,
            g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected,
            gui_buffer);
        }

        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, 0);
    }
    SetRightSoftkeyFunction(cui_dtcnt_cancel_cui, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_get_first_entry_highlight_item
 * DESCRIPTION
 *  this function is uesd to get the highlihgt item before first entry screen.
 *  Note: need to be called after get list info.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 cui_dtcnt_get_first_entry_highlight_item(U32 acct_id, MMI_BOOL is_dual_acct, MMI_BOOL is_second_acct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct acct_info;
    S32 i;
    S32 acct_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_CBM_BEARER_FALLBACK__
    if (is_dual_acct)
    {
        cbm_decode_data_account_id_ext(acct_id, &acct_info);
        if (!is_second_acct)
        {
            for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number; i++)
            {
                switch (g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type)
                {
                    case CUI_DTCNT_ITEM_AUTO:
                        if (acct_info.account[0].account_id == CBM_DEFAULT_ACCT_ID && 
                            !acct_info.account[0].is_always_ask)
                        {
                            return i;
                        }
                        break;
                        
                    case CUI_DTCNT_ITEM_WIFI:                
                        if (acct_info.account[0].account_id == CBM_WIFI_ACCT_ID && 
                            !acct_info.account[0].is_always_ask)
                        {
                            return i;
                        }
                        break;
                        
                    case CUI_DTCNT_ITEM_ALWAYS_ASK:
                        if (acct_info.account[0].is_always_ask)
                        {
                            return i;
                        }
                        break;
                        
                    case CUI_DTCNT_ITEM_GPRS:
                    case CUI_DTCNT_ITEM_CSD:
                        if (acct_info.account[0].account_id == g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].profile_id)
                        {
                            return i;
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        }/* first account */
        else
        {
            if (!g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_exist)
            {
                return 0;
            }
            for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number2; i++)
            {
                switch(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2[i].item_type)
                {
                    case CUI_DTCNT_ITEM_AUTO:
                        if (acct_info.account[0].account_id == CBM_DEFAULT_ACCT_ID && 
                            !acct_info.account[0].is_always_ask)
                        {
                            return i;
                        }
                        break;
                        
                    case CUI_DTCNT_ITEM_WIFI:                
                        if (acct_info.account[0].account_id == CBM_WIFI_ACCT_ID && 
                            !acct_info.account[0].is_always_ask)
                        {
                            return i;
                        }
                        break;
                        
                    case CUI_DTCNT_ITEM_ALWAYS_ASK:
                        if (acct_info.account[0].is_always_ask)
                        {
                            return i;
                        }
                        break;
                        
                    case CUI_DTCNT_ITEM_GPRS:
                    case CUI_DTCNT_ITEM_CSD:
                        if (acct_info.account[0].account_id == g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info2[i].profile_id)
                        {
                            return i;
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        } /* second account */
    }
    else
    {
    #endif
        cbm_decode_data_account_id_ext(acct_id, &acct_info);
        for (i = 0; i < g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_item_number; i++)
        {
            switch(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].item_type)
            {
                case CUI_DTCNT_ITEM_AUTO:
                    if (acct_info.account[0].account_id == CBM_DEFAULT_ACCT_ID && 
                        !acct_info.account[0].is_always_ask)
                    {
                        return i;
                    }
                    break;
                    
                case CUI_DTCNT_ITEM_WIFI:                
                    if (acct_info.account[0].account_id == CBM_WIFI_ACCT_ID && 
                        !acct_info.account[0].is_always_ask)
                    {
                        return i;
                    }
                    break;
                    
                case CUI_DTCNT_ITEM_ALWAYS_ASK:
                    if (acct_info.account[0].is_always_ask)
                    {
                        return i;
                    }
                    break;
                    
                case CUI_DTCNT_ITEM_GPRS:
                case CUI_DTCNT_ITEM_CSD:
                    if (acct_info.account[0].account_id == g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].list_info[i].profile_id)
                    {
                        return i;
                    }
                    break;
                    
                default:
                    break;
            }
        }
    #ifdef __MMI_CBM_BEARER_FALLBACK__
    }
    #endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_select_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cui_id     [IN]
 *  app_menu_id  [IN]
 *  bearers  [IN]
 *  app_id    [IN]
 *  account_id  [IN]
 *  option   [IN]
 *  select_type   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dtcnt_select_account(U8 cntx_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cui_dtcnt_sel_index = cntx_index;
    switch (g_cui_dtcnt_sel_acct[cntx_index].type)
    {
        case CUI_DTCNT_SELECT_TYPE_NORMAL:
        {
            if ((g_cui_dtcnt_sel_acct[cntx_index].option & CUI_DTCNT_SELECT_BEARER_SWITCH) == 0)
            {
                mmi_frm_group_enter(g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id, 0);
                mmi_frm_scrn_first_enter(
                    g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id,
                    SCR_ID_DTCNT_CUI_NORMAL_LIST,
                    (FuncPtr) cui_dtcnt_entry_select_account_single,
                    NULL);
            }

            else
            {
        #ifdef	__MMI_CBM_BEARER_FALLBACK__
                g_cui_dtcnt_sel_acct[cntx_index].account_changed = MMI_FALSE;
                mmi_frm_group_enter(g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id, 0);
                mmi_frm_scrn_first_enter(
                    g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id,
                    SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST,
                    (FuncPtr) cui_dtcnt_entry_select_account_dual,
                    NULL);
        #else
                mmi_frm_group_enter(g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id, 0);
                mmi_frm_scrn_first_enter(
                    g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id,
                    SCR_ID_DTCNT_CUI_NORMAL_LIST,
                    (FuncPtr) cui_dtcnt_entry_select_account_single,
                    NULL);
        #endif
            }

            break; 

        }
        case CUI_DTCNT_SELECT_TYPE_CBM:
        {
            mmi_frm_group_enter(g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id, 0);
            mmi_frm_scrn_first_enter(
                    g_cui_dtcnt_sel_acct[cntx_index].curr_cui_id,
                    SCR_ID_DTCNT_CUI_CBM_LIST,
                    (FuncPtr) cui_dtcnt_entry_select_account_cbm,
                    NULL);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_get_cntx_index_by_cui_id
 * DESCRIPTION
 *  to get cui display context index by cui ID
 * PARAMETERS
 *  cui_gid
 * RETURNS
 *  S32 index
*****************************************************************************/
S32 cui_dtcnt_get_cntx_index_by_cui_id(mmi_id cui_id, U8 cntx_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (cntx_type == 0)
    {
        for (i = 0; i < CUI_DTCNT_MAX_BEARER_LIST_NUM; i++)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_CUI_CONTEXT_INFO, i, g_cui_dtcnt_sel_acct[i].valid, g_cui_dtcnt_sel_acct[i].curr_cui_id);
					        
            if (g_cui_dtcnt_sel_acct[i].valid && g_cui_dtcnt_sel_acct[i].curr_cui_id == cui_id)
            {
                return i;
            }
        }
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_run
 * DESCRIPTION
 *  to run data account select group
 * PARAMETERS
 *  cui_gid
 * RETURNS
 *  void
*****************************************************************************/
void cui_dtcnt_select_run(mmi_id cui_gid) /*why no parent gid*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 acct_id = MMI_DTCNT_INVALID_ID;
    S32 index = -1;
	cui_dtcnt_select_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/

    index = cui_dtcnt_get_cntx_index_by_cui_id(cui_gid, 0);
    if (index != -1)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_RUN_INFO, cui_gid, index);
        cui_dtcnt_select_account(index);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_RUN_ERROR);

        /* send the failed event ID */
        MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_RESULT_FAILED, cui_gid);
        evt.account_id = MMI_DTCNT_INVALID_ID;
        mmi_frm_group_send_to_parent (cui_gid, (mmi_group_event_struct*)&evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_select_run
 * DESCRIPTION
 *  to run data account select group
 * PARAMETERS
 *  cui_gid
 * RETURNS
 *  void
*****************************************************************************/
void cui_dtcnt_select_set_param(mmi_id cui_gid, cui_dtcnt_select_run_struct *p_args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    cbm_account_info_struct acct_info;
    srv_dtcnt_prof_str_info_qry_struct acct_data;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    index = cui_dtcnt_get_cntx_index_by_cui_id(cui_gid, 0);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_INIT_INFO, cui_gid, index);
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, CUI_DTCNT_SELECTION_INIT_DETAIL, p_args->bearers, p_args->app_id, p_args->account_id, p_args->option, p_args->sim_selection);

    if (index != -1)
    {
        g_cui_dtcnt_sel_acct[index].account_id = p_args->account_id;
    #ifdef __MMI_CBM_BEARER_FALLBACK__ 
        if (p_args->option & CUI_DTCNT_SELECT_BEARER_SWITCH)
        {
            cbm_decode_data_account_id_ext(p_args->account_id, &acct_info);
            g_cui_dtcnt_sel_acct[index].primary_account_id = acct_info.account[0].account_id;
            g_cui_dtcnt_sel_acct[index].primary_sim_info = acct_info.account[0].sim_id;
            g_cui_dtcnt_sel_acct[index].primary_is_always_ask = acct_info.account[0].is_always_ask;

            if (cui_dtcnt_display_real_acct_name(acct_info.account[0].account_id, acct_info.account[0].is_always_ask))
            {
                g_cui_dtcnt_sel_acct[index].primary_account_id = cbm_encode_data_account_id(
                    acct_info.account[0].account_id,
                    acct_info.account[0].sim_id,
                    0,
                    acct_info.account[0].is_always_ask);
                
                mmi_dtcnt_get_full_account_name(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_id,
                                       (PS8)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_name, 
                                       MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                       MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
            }
            else
            {
                mmi_ucs2cpy((S8*)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].primary_account_name, (S8*)GetString(STR_ID_DTCNT_NAME_INVALID));
            }

            g_cui_dtcnt_sel_acct[index].secondary_account_id = acct_info.account[1].account_id;
            g_cui_dtcnt_sel_acct[index].secondary_sim_info = acct_info.account[1].sim_id;
            g_cui_dtcnt_sel_acct[index].secondary_is_always_ask = acct_info.account[1].is_always_ask;

            //if (g_cui_dtcnt_sel_acct[index].secondary_account_id != CBM_INVALID_NWK_ACCT_ID)
            if (acct_info.acct_num > 1)
            {
                g_cui_dtcnt_sel_acct[index].secondary_account_exist = MMI_TRUE;

                if (cui_dtcnt_display_real_acct_name(acct_info.account[1].account_id, acct_info.account[1].is_always_ask))
                {
                    g_cui_dtcnt_sel_acct[index].secondary_account_id = cbm_encode_data_account_id(
                        acct_info.account[1].account_id,
                        acct_info.account[1].sim_id,
                        0,
                        acct_info.account[1].is_always_ask);
                    
                    mmi_dtcnt_get_full_account_name(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_id, 
                                            (PS8)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_name, 
                                            MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1, 
                                            MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE);
                }
                else 
                {
                    mmi_ucs2cpy((S8*)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_name, (S8*)GetString(STR_ID_DTCNT_NAME_INVALID));
                }
            }
            else 
            {
                mmi_ucs2cpy((S8*)g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].secondary_account_name, GetString(STR_GLOBAL_NONE));
            }

        }
    #endif /* __MMI_CBM_BEARER_FALLBACK__ */

        g_cui_dtcnt_sel_acct[index].app_menu_id = p_args->AppMenuID;
        g_cui_dtcnt_sel_acct[index].app_icon_id = p_args->icon_id;
        g_cui_dtcnt_sel_acct[index].app_str_id = p_args->str_id;
        g_cui_dtcnt_sel_acct[index].app_id = p_args->app_id;
        g_cui_dtcnt_sel_acct[index].sim_selection = p_args->sim_selection;
        g_cui_dtcnt_sel_acct[index].bearers = p_args->bearers;
        g_cui_dtcnt_sel_acct[index].option = p_args->option;
        g_cui_dtcnt_sel_acct[index].type = p_args->type;
    }
    else
    {
//        MMI_TRACE();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_leave_callback
 * DESCRIPTION
 *  Account bearer list leave function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_dtcnt_leave_callback(mmi_event_struct* pevt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U32 acct_id = MMI_DTCNT_INVALID_ID;
	cui_dtcnt_select_event_struct evt;
    U8 cui_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    //cui_index = *((U8 *)pevt->user_data);
    switch(pevt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        {
            return MMI_RET_OK;
        }
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            /* return the encode acct id */
            //MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&evt, CUI_DTCNT_SELECT_EVENT_CLOSE, g_cui_dtcnt_sel_acct[cui_index].curr_cui_id);

            //evt.account_id = acct_id;
            //mmi_frm_group_send_to_parent (g_cui_dtcnt_sel_acct[cui_index].curr_cui_id, (mmi_group_event_struct*)&evt);
            for (cui_index = 0; cui_index < CUI_DTCNT_MAX_BEARER_LIST_NUM; cui_index++)
            {
                memset(&g_cui_dtcnt_sel_acct[cui_index], 0, sizeof(cui_dtcnt_select_account_option_struct));
            }
            break;
        }
    }
    return MMI_RET_OK;

}


/*****************************************************************************
  * FUNCTION
  *  cui_dtcnt_select_group_proc
  * DESCRIPTION
  *  The proc fo the screen group
  * PARAMETERS
  *  cui_gid
  * RETURNS
  *  void
 *****************************************************************************/
static mmi_ret cui_dtcnt_select_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id scr_group_id;
    U32 acct_id;
    U8 app_id = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].app_id;
    cui_dtcnt_select_event_struct select_evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 temp;
	temp = EVT_ID_GROUP_FIRST_ENTRY;
	switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:    /* First entry new group */
            break;
        case EVT_ID_GROUP_ACTIVE:    /* active group */
            break;
        case EVT_ID_GROUP_INACTIVE:    /* inactive group */
            break;
        case EVT_ID_GROUP_GOBACK:    /* close the active group; invoke the goback process */
            break;
        case EVT_ID_GROUP_DELETE_REQ:    /* close the inactive group; invoke the deinit process only */
            break;
        case EVT_ID_GROUP_DEINIT:    /* deinint group */
            break;        
        case EVT_ID_SCRN_ACTIVE:    /* active screen */
            break;
        case EVT_ID_SCRN_INACTIVE:    /* inactive screen */
            break;
        case EVT_ID_SCRN_GOBACK:    /* close the active screen; invoke the goback process */
            break;
        case EVT_ID_SCRN_DELETE_REQ:    /* delete the inactive screen; invoke the deinit process only */
            break;
        case EVT_ID_SCRN_DEINIT:    /* deinit the screen */
            break;
        case CUI_WLAN_LIST_EVENT_RESULT_OK:
#ifdef __MMI_WLAN_FEATURES__
           cui_wlan_list_close(g_wlan_cui_id);
           cbm_get_valid_account_id(CBM_BEARER_WIFI, &acct_id);
           acct_id = cbm_encode_data_account_id(acct_id, CBM_SIM_ID_SIM1, app_id, FALSE);
           MMI_FRM_INIT_GROUP_EVENT((mmi_group_event_struct*)&select_evt, CUI_DTCNT_SELECT_EVENT_RESULT_OK, g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id);
           select_evt.account_id = acct_id;
           mmi_frm_group_send_to_parent(g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].curr_cui_id, (mmi_group_event_struct*)&select_evt);            
#endif
           break;
        case CUI_WLAN_LIST_EVENT_RESULT_CANCEL:
        case CUI_WLAN_LIST_EVENT_CLOSE:
#ifdef __MMI_WLAN_FEATURES__
            cui_wlan_list_close(g_wlan_cui_id);
#endif
            break;
    }
    return MMI_OK;
}


/*****************************************************************************
  * FUNCTION
  *  cui_dtcnt_bt_sim_unavailable_proc
  * DESCRIPTION
  *  dtcnt cui proc function for sim unavailable
  * PARAMETERS
  *  void
  * RETURNS
  *  void
 *****************************************************************************/
void cui_dtcnt_bt_sim_unavailable_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_need_restore_highlight_index = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected;

    #ifdef  __MMI_CBM_BEARER_FALLBACK__
    g_need_restore_highlight_index2 = g_cui_dtcnt_sel_acct[g_cui_dtcnt_sel_index].current_item_selected2;
    #endif

    g_bt_sim_unavailable_flag = MMI_TRUE;
}


/*****************************************************************************
  * FUNCTION
  *  cui_dtcnt_bt_sim_available_proc
  * DESCRIPTION
  *  dtcnt cui proc function for sim available
  * PARAMETERS
  *  void
  * RETURNS
  *  void
 *****************************************************************************/
void cui_dtcnt_bt_sim_available_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_bt_sim_unavailable_flag)
    {
        return;
    }
    g_bt_sim_unavailable_flag = MMI_FALSE;
    g_bt_sim_available_flag = MMI_TRUE;
}


#ifdef __WS_HOME_SAFE__
#define __MMI_GPRS_APN_SETTING__

typedef struct 
{
	U8 apn[SRV_DTCNT_PROF_MAX_APN_LEN];
	U8 HomePage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];
	U8 px_addr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];
	U8 UserName[SRV_DTCNT_PROF_MAX_USER_LEN+1];
    U8 Passwd[SRV_DTCNT_PROF_MAX_PW_LEN+1];
	U16 px_port;
	
}apn_para_struct;

#define ACCOUNT_NAME_UCS2 L"FUCK_APN"
#include "TimerEvents.h"

/*APN设置*/
apn_para_struct g_apn_struct;
srv_dtcnt_prof_gprs_struct g_account_gprs_profile_srv;
void AddOrUpdataApn(void);
extern 	void mmi_um_ui_sh_setting_entry_mms_setting(void);

void set_key_handler_evt(void)
{
	static int key_cout = 0;
	if(++key_cout == 1)
	{
		left_softkey_down();
		left_softkey_up();	
	}
	else if(key_cout == 2)
	{
		//fixed_list_goto_next_item();
		cui_dtcnt_entry_select_account_single_highlight_hdlr(1);
	}
	else if(key_cout == 3)
	{
		cui_dtcnt_single_select_ok();

	}
	else
	{
		right_softkey_down();
		right_softkey_up();
		key_cout = 0;
		StopTimer(HF_MMS_APN_TIMER_ID);
		return;
	}
	
	StartTimer(HF_MMS_APN_TIMER_ID, 100,set_key_handler_evt);
}
void szl_set_highlight_mms_apn(void)
{
	mmi_um_ui_sh_setting_entry_mms_setting();
	set_key_handler_evt();
	return;
	
}

int szl_set_apn_data(char * val)
{
	#define LEN_VAILD(v,l) if(strlen(v)>l) return 0
	#define CPY_STR(d,s)    do{strcpy(g_apn_struct.##d,s);}while(0)
	
	char apn[50] = {0};
	char HomePage[50] = {0};
	char px_addr[50] = {0};
	char UserName[20] = {0};
	char Passwd[30] = {0};
	int int_port[6] = {0};
	U32   px_port = 0;
	int i = 0;

	if(NULL == val)
        return 0;
    
    //必须匹配头部
    if(0!=memcmp(val, "#888#", 5))
        return 0;
    
	i = sscanf(val,"#888#%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%d#",apn,HomePage,px_addr,UserName,Passwd,&px_port);

    //匹配的个数至少有个保证
    if(i<=2)
        return 0;
    
	LEN_VAILD(apn,50);
	LEN_VAILD(HomePage,50);
	LEN_VAILD(px_addr,50);
	LEN_VAILD(UserName,20);
	LEN_VAILD(Passwd,30);
	sscanf(px_addr,"%d.%d.%d.%d",&int_port[0],&int_port[1],&int_port[2],&int_port[3]);
	
	for(i=0;i<4;i++)
	{
		if(int_port[i] > 255 || int_port[i] < 0) return 0;
		g_apn_struct.px_addr[i] = int_port[i];
	}
	CPY_STR(apn,apn);
	CPY_STR(HomePage,HomePage);
	//CPY_STR(px_addr,px_addr);
	CPY_STR(UserName,UserName);
	CPY_STR(Passwd,Passwd);
	g_apn_struct.px_port=px_port;

	AddOrUpdataApn();
	szl_set_highlight_mms_apn();
	return 1;
}
void SaveApnPara(U8 *acctname_ucs2, srv_dtcnt_prof_gprs_struct* acct_struct)
{

	//g_account_gprs_profile_srv.sim_info = g_data_account_display_cntx.sim_info + 1;


	acct_struct->prof_common_header.AccountName = acctname_ucs2;
	acct_struct->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_USER_CONF; 
	//acct_struct->prof_common_header.acc_id = g_account_gprs_profile_srv.org_acct_id;
	acct_struct->APN = g_apn_struct.apn;
	acct_struct->prof_common_header.Auth_info.AuthType = 0;

	acct_struct->prof_common_header.use_proxy = 1;
	acct_struct->prof_common_header.px_port = g_apn_struct.px_port;
	strcpy((PS8)acct_struct->prof_common_header.Auth_info.UserName, g_apn_struct.UserName);
	strcpy((PS8)acct_struct->prof_common_header.Auth_info.Passwd, g_apn_struct.Passwd);
	strcpy((PS8)acct_struct->prof_common_header.px_authid, g_apn_struct.UserName);
	strcpy((PS8)acct_struct->prof_common_header.px_authpw, g_apn_struct.Passwd);
	strcpy((PS8)acct_struct->prof_common_header.HomePage, g_apn_struct.HomePage);

	acct_struct->prof_common_header.sim_info = SRV_DTCNT_SIM_TYPE_1;
	acct_struct->prof_common_header.read_only = 0;

	acct_struct->prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;

	acct_struct->prof_common_header.NetMask[0] = 0;
	acct_struct->prof_common_header.NetMask[1] = 0;
	acct_struct->prof_common_header.NetMask[2] = 0;
	acct_struct->prof_common_header.NetMask[3] = 0;

	acct_struct->prof_common_header.StaicIPAddr[0] = 0;
	acct_struct->prof_common_header.StaicIPAddr[1] = 0;
	acct_struct->prof_common_header.StaicIPAddr[2] = 0;
	acct_struct->prof_common_header.StaicIPAddr[3] = 0;

	acct_struct->prof_common_header.PrimaryAddr[0] = 0;
	acct_struct->prof_common_header.PrimaryAddr[1] = 0;
	acct_struct->prof_common_header.PrimaryAddr[2] = 0;
	acct_struct->prof_common_header.PrimaryAddr[3] = 0;

	acct_struct->prof_common_header.SecondaryAddr[0] = 0;
	acct_struct->prof_common_header.SecondaryAddr[1] = 0;
	acct_struct->prof_common_header.SecondaryAddr[2] = 0;
	acct_struct->prof_common_header.SecondaryAddr[3] = 0;

	acct_struct->prof_common_header.px_addr[0] = g_apn_struct.px_addr[0];
	acct_struct->prof_common_header.px_addr[1] = g_apn_struct.px_addr[1];
	acct_struct->prof_common_header.px_addr[2] = g_apn_struct.px_addr[2];
	acct_struct->prof_common_header.px_addr[3] = g_apn_struct.px_addr[3];

}

srv_dtcnt_result_enum ApnQuery(U8 *acctname_ucs2, srv_dtcnt_prof_gprs_struct* acct_struct)
{
	int i=0;
	srv_dtcnt_store_prof_qry_struct acct_id_query;
	srv_dtcnt_store_prof_data_struct prof_info;
	srv_dtcnt_result_enum result;
	U8 temp[100]={0};

	acct_id_query.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE;
	acct_id_query.qry_info.acc_type_info = SRV_DTCNT_PROF_TYPE_USER_CONF;

	prof_info.prof_type = SRV_DTCNT_BEARER_GPRS;
	prof_info.prof_data = acct_struct;
	prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;

	result = srv_dtcnt_store_qry_ids(&acct_id_query);

	if(SRV_DTCNT_RESULT_SUCCESS == result)
	{
		for(i=0; i < acct_id_query.num_ids; i++)
		{
			if(SRV_DTCNT_RESULT_SUCCESS == srv_dtcnt_store_qry_prof(acct_id_query.ids[i], &prof_info))
			{
				if(0 == mmi_ucs2cmp(acct_struct->prof_common_header.AccountName, acctname_ucs2))
				{
					return SRV_DTCNT_RESULT_SUCCESS;
				}
			}
		}
	}
	return SRV_DTCNT_RESULT_FAILED;
	

}

void AddOrUpdataApn(void)
{
	srv_dtcnt_store_prof_data_struct prof_info;
	U32 acct_id;
	srv_dtcnt_result_enum result;
	srv_dtcnt_prof_gprs_struct account_gprs_profile_srv;

	prof_info.prof_type = SRV_DTCNT_BEARER_GPRS;
	prof_info.prof_data = &account_gprs_profile_srv;
	prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
	memset(&account_gprs_profile_srv,0,sizeof(account_gprs_profile_srv));
	
	result = ApnQuery((U8*)ACCOUNT_NAME_UCS2, &account_gprs_profile_srv);
	SaveApnPara((U8*)ACCOUNT_NAME_UCS2, &account_gprs_profile_srv);
	
	if(SRV_DTCNT_RESULT_SUCCESS == result)
	{
		result = srv_dtcnt_store_update_prof(account_gprs_profile_srv.prof_common_header.acc_id, &prof_info);
		if (result == SRV_DTCNT_RESULT_SUCCESS)
		{
			mmi_dtcnt_update_disp_list(account_gprs_profile_srv.prof_common_header.acc_id,
								   DATA_ACCOUNT_BEARER_GPRS,
								   DTCNT_USER_CONFIGURED_ACCT,
								   1,
								   account_gprs_profile_srv.prof_common_header.sim_info,
								   account_gprs_profile_srv.prof_common_header.read_only);
		}
	}
	else 
	{
		result = srv_dtcnt_store_add_prof(&prof_info, &acct_id);
		if (result == SRV_DTCNT_RESULT_SUCCESS)
		{
			mmi_dtcnt_add_disp_list(acct_id,
									DATA_ACCOUNT_BEARER_GPRS,
									DTCNT_USER_CONFIGURED_ACCT,
									1,
									account_gprs_profile_srv.prof_common_header.sim_info,
									account_gprs_profile_srv.prof_common_header.read_only);
			mmi_dtcnt_set_account_default_app_type(acct_id, MMI_FALSE);
		}
	}
}

#endif

#endif /* __TCPIP__ */ 
