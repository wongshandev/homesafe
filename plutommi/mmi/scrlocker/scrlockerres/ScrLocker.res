/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrLocker.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the screen locker.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 29 2010 weilun.liu
 * [MAUI_02855915] [SLIM]Unused string removal for SLIM projects
 * wrapped  compile option for unused string.
 *
 * 12 29 2010 weilun.liu
 * [MAUI_02855761] [SLIM] change some images for 32+32 slim projects
 * Slim image.
 *
 * 11 17 2010 weilun.liu
 * [MAUI_02839080] [Idle] new mmi cache mech. modification
 * .
 *
 * 11 02 2010 weilun.liu
 * [MAUI_02833901] [Idle] support SIM Refresh
 * revise callback register event and support sim refresh.
 *
 * 08 31 2010 yiruei.wu
 * [MAUI_02615210] Security setting app/srv check-in
 * Check-in
 *
 * Jun 22 2010 mtk01585
 * [MAUI_02567833] [Idle] Revise codes by using XML resources
 * Check-in XML resources.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_SCR_LOCKER">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>


    <!----- String Resource Area ---------------------------------------------->
#ifdef __MMI_TOUCH_SCREEN__
    <STRING id="STR_ID_SLK_LOCKED"/>
#else
    <STRING id="STR_ID_SLK_UNLOCK"/>
#endif

#if defined(__DM_LAWMO_SUPPORT__)
    <STRING id="STR_ID_SLK_SOS"/>
#endif

#if defined(__MMI_KEYPAD_LOCK_PATTERN_1__)
    <STRING id="STR_ID_SLK_KBD_HELP_MSG"/>
    <STRING id="STR_ID_SLK_KBD_UNLOCK_ME_MSG"/>
#else
    <STRING id="STR_ID_SLK_KBD_HELP_MSG2"/>
    <STRING id="STR_ID_SLK_KBD_UNLOCK_ME_MSG2"/>
#endif /* defined(__MMI_KEYPAD_LOCK_PATTERN_1__) */

#if defined(__MMI_TOUCH_SCREEN__)
    <STRING id="STR_ID_SLK_TOUCH_HELP_MSG"/>
    <STRING id="STR_ID_SLK_TOUCH_UNLOCK_ME_MSG"/>
    <STRING id="STR_ID_SLK_TOUCH_LOCKED_MSG"/>
    <STRING id="STR_ID_SLK_TOUCH_UNLOCKED_MSG"/>
#else
    <STRING id="STR_ID_SLK_KBD_LOCKED_MSG"/>
    <STRING id="STR_ID_SLK_KBD_UNLOCKED_MSG"/>
#endif /* defined(__MMI_TOUCH_SCREEN__) */

#if defined(__MMI_FANCY_SCREEN_LOCK__)
    <STRING id="STR_ID_SLK_MISSED_CALL"/>
    <STRING id="STR_ID_SLK_MISSED_CALLS"/>
    <STRING id="STR_ID_SLK_NEW_SMS_MSG"/>
    <STRING id="STR_ID_SLK_NEW_SMS_MSGS"/>
    <STRING id="STR_ID_SLK_NEW_MMS_MSG"/>
    <STRING id="STR_ID_SLK_NEW_MMS_MSGS"/>
    <STRING id="STR_ID_SLK_FANCY_HELP_MSG"/>
#endif /* defined(__MMI_FANCY_SCREEN_LOCK__) */

#if defined(__DM_LAWMO_SUPPORT__)
    <STRING id="STR_ID_SLK_LAWMO_DEVICE_MANAGEMENT"/>
    <STRING id="STR_ID_SLK_LAWMO_LOCKED"/>
    <STRING id="STR_ID_SLK_LAWMO_WIPING"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_WIPING"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_WIPING_DONE"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_LOCKED"/>
    <STRING id="STR_ID_SLK_LAWMO_POPUP_UNLOCKED"/>
#endif /* defined(__DM_LAWMO_SUPPORT__) */

#if defined(__MMI_AUTO_KEYPAD_LOCK__)
    <STRING id="STR_ID_SLK_TIME_SETTING"/>
    <STRING id="STR_ID_SLK_5_SEC"/>
    <STRING id="STR_ID_SLK_30_SEC"/>
    <STRING id="STR_ID_SLK_1_MIN"/>
    <STRING id="STR_ID_SLK_5_MIN"/>
#endif

    <!----- Image Resource Area ----------------------------------------------->
#if defined(__MMI_MAINLCD_128X128__)
        <IMAGE id="IMG_ID_SLK_UNLOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\notification\\\\N_Unlock.BMP"</IMAGE>
        <IMAGE id="IMG_ID_SLK_LOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\notification\\\\N_KEY.BMP"</IMAGE>
#else
        <IMAGE id="IMG_ID_SLK_UNLOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\notification\\\\N_Unlock.png"</IMAGE>
        <IMAGE id="IMG_ID_SLK_LOCKED">CUST_IMG_PATH"\\\\MainLCD\\\\Warningpage\\\\notification\\\\N_KEY.PNG"</IMAGE>
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    <IMAGE id="IMG_ID_SLK_TOUCH_CLICK_SPOT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Calibration\\\\CALI_popup.gif"</IMAGE>
#endif

#if defined(__MMI_FANCY_SCREEN_LOCK__)
    <IMAGE id="IMG_ID_SLK_MISSED_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\NotificationIcon\\\\Unlock_EventIcon_CALL.png"</IMAGE>
    <IMAGE id="IMG_ID_SLK_NEW_SMS_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\NotificationIcon\\\\Unlock_EventIcon_SMS.png"</IMAGE>
    <IMAGE id="IMG_ID_SLK_NEW_MMS_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\NotificationIcon\\\\Unlock_EventIcon_MMS.png"</IMAGE>
#endif /* defined(__MMI_FANCY_SCREEN_LOCK__) */


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_SLK_MAIN"/>
    <SCREEN id="SCR_ID_SLK_MAIN"/>
    <SCREEN id="SCR_ID_SLK_POPUP"/>
    <SCREEN id="GRP_ID_SLK_SETTING"/>


    <!----- Menu Resource Area ------------------------------------------------>

#if defined(__MMI_AUTO_KEYPAD_LOCK__)
    <MENU id="MENU_ID_SLK_TIME_SETTING_MENU" type="APP_SUB" str="STR_ID_SLK_TIME_SETTING">
        <MENUITEM_ID>MENU_ID_SLK_SETTING_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_5_SEC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_30_SEC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_1_MIN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SLK_SETTING_5_MIN</MENUITEM_ID>
    </MENU>
    
    <MENUITEM id="MENU_ID_SLK_SETTING_ENTRY" str="STR_ID_SLK_TIME_SETTING"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_OFF" str="STR_GLOBAL_OFF"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_5_SEC" str="STR_ID_SLK_5_SEC"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_30_SEC" str="STR_ID_SLK_30_SEC"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_1_MIN" str="STR_ID_SLK_1_MIN"/>
    <MENUITEM id="MENU_ID_SLK_SETTING_5_MIN" str="STR_ID_SLK_5_MIN"/>
#endif /* defined(__MMI_AUTO_KEYPAD_LOCK__) */


    <!------------------------------------------------------MMI Cache Resource---------------------------------------------------------->    
    <CACHEDATA type="byte" id="NVRAM_SETTING_AUTOKEYPADLOCK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto KeyPad Lock Status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SETTING_AUTOKEYPADLOCK_TIME" restore_flag="TRUE">
    #if defined(__MSGCMD_SUPPORT__)
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Auto KeyPad Lock Timer </DESCRIPTION>
    </CACHEDATA>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <RECIEVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_SRV_SMS_READY" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_SRV_SMS_ADD_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="mmi_slk_main_evt_hdlr"/>
#ifdef __MMI_CLAMSHELL__
    <RECIEVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_slk_main_evt_hdlr"/>
#endif
    <RECIEVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_IDLE_BEFORE_GROUP_ENTER" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_IDLE_BEFORE_GROUP_EXIT" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_IDLE_LAUNCHED" proc="mmi_slk_main_evt_hdlr"/>

    /*
     * This event is emitted when the handset is locked.
     *
     * Structure: mmi_scr_locker_locked_evt_struct
     */
    <EVENT id="EVT_ID_SCR_LOCKER_LOCKED" type="SENDER"/>

    /*
     * This event is emitted when the handset is unlocked.
     *
     * Structure: mmi_scr_locker_unlocked_evt_struct
     */
    <EVENT id="EVT_ID_SCR_LOCKER_UNLOCKED" type="SENDER"/>

    <RECIEVER id="EVT_ID_SCR_LOCKER_LOCKED" proc="mmi_slk_main_evt_hdlr"/>
    <RECIEVER id="EVT_ID_SCR_LOCKER_UNLOCKED" proc="mmi_slk_main_evt_hdlr"/>

    <EVENT id="EVT_ID_SLK_OBJ_CLOSE_REQ"/>
    <EVENT id="EVT_ID_SLK_OBJ_CLOSED_IND"/>
    <EVENT id="EVT_ID_SLK_POPUP_CLOSE_REQ"/>
    <EVENT id="EVT_ID_SLK_POPUP_CLOSED_IND"/>
    

</APP>

