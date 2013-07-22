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
 * DateAndTime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for date/time setting application
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
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : DateAndTime.c

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Gurinder Singh Chhabra

   DATE     : Oct 24, 2003

**************************************************************/
#ifndef _DATEANDTIME_C
#define _DATEANDTIME_C

/*  Include: MMI header file */

#include "AlarmFrameworkProt.h"
#include "wgui_datetime.h"
#include "ProtocolEvents.h"
#include "settingstructs.h"
#include "SettingsGexdcl.h"
#include "settingprot.h"
#include "ProtocolEvents.h"
#include "worldclock.h"
#include "AlarmGprot.h"
#include "IdleAppProt.h"
#include "DateTimeGprot.h"
#include "ProfilesSrvGprot.h"
#include "PhoneSetup.h"
#include "Menucuigprot.h"
#include "Inlinecuigprot.h"
#include "ATHandlerProt.h"
#ifdef __MMI_TDL_NITZ_SUPPORT__
#include "CalendarGprot.h"
#include "ToDoListGprot.h"
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Setting.h"
#endif

#include "WorldClockCuiGprot.h"

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "custom_mmi_default_value.h"
#include "mmi_rp_app_worldclock_def.h"
#include "l4c2uem_struct.h"
#include "GlobalConstants.h"
#include "mmi_frm_scenario_gprot.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "mmi_frm_nvram_gprot.h"
#include "string.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "stack_msgs.h"
#include "mmi_msg_struct.h"
#include "device.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_categories_sublcd.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_inputs.h"
#include "mmi_frm_history_gprot.h"
#include "stack_config.h"
#include "SettingDefs.h"
#include "mmi_rp_app_mainmenu_def.h"
/* auto add by kw_check end */
#include "SettingGprots.h"
#include "PhoneSetupGprots.h"
#include "mmi_rp_srv_nitz_def.h"
/*  Include: PS header file */


/* 
 * Define
 */
#define NUM_CITYS (NUMBER_OF_CITY-1)
#define MAX_CITY_NUM 100
#define DOUBLE_DIGIT 10
#define MMI_DT_YEAR_BOUNDARY		30

typedef enum
{
#ifndef __MMI_HIDE_HOMECITY__
    PHNSET_DT_MNU_HOMECT,
#endif
#ifdef __MMI_DUAL_CLOCK__
	PHNSET_DT_MNU_FOREIGN_CITY,
#endif

#ifndef __MMI_SEPARATE_DT_SETTING__
    PHNSET_DT_MNU_DT,
    PHNSET_DT_MNU_DATEANDFORMAT = PHNSET_DT_MNU_DT,
    PHNSET_DT_MNU_FMT,
    PHNSET_DT_MNU_TIMEANDFORMAT = PHNSET_DT_MNU_FMT,
#else /* __MMI_SEPARATE_DT_SETTING__ */ 
    PHNSET_DT_MNU_DT,
    PHNSET_DT_MNU_FMT,
    PHNSET_DT_MNU_DATEANDFORMAT,
    PHNSET_DT_MNU_TIMEANDFORMAT,
#endif /* __MMI_SEPARATE_DT_SETTING__ */ 
	PHNSET_DT_MNU_SEP,			/* date seperator */
	
#if (defined(__MMI_NITZ__) && defined(__MMI_AUTOTIMEZONE_IN_DATEANDTIME__))
    PHNSET_DT_MNU_NITZ,
#endif 

    PHNSET_DT_MNU_LAST
} phnset_DT_menu_enum;

#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
typedef struct
{
    FLOAT CityTimeZone; /* time difference */
    U16 CityName;       /* city name in English. */
    U8 tzdata_index;
} GMT_TZ_STRUCT;
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */

#ifndef YEARFORMATE
#define YEARFORMATE 2000
#endif 

#ifndef NEGATIVE
#define NEGATIVE 0
#endif 

#ifndef POSITIVE
#define POSITIVE 1
#endif 


/* Set date and time */
#define SET_DATE_AND_TIME_SET_TIME_CAPTION (CUI_INLINE_ITEM_ID_BASE + 1)
#define SET_DATE_AND_TIME_SET_TIME    (CUI_INLINE_ITEM_ID_BASE + 2)
#define SET_DATE_AND_TIME_SET_DATE_CAPTION (CUI_INLINE_ITEM_ID_BASE + 3)
#define SET_DATE_AND_TIME_SET_DATE    (CUI_INLINE_ITEM_ID_BASE + 4)
#define SET_DATE_AND_TIME_DAYLIGHT_SAVING_CAPTION (CUI_INLINE_ITEM_ID_BASE + 5)
#define SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT  (CUI_INLINE_ITEM_ID_BASE + 6)
/* Set date and time format */
#define SET_FORMAT_TIME_FORMAT_CAPTION        (CUI_INLINE_ITEM_ID_BASE + 1)
#define SET_FORMAT_TIME_FORMAT_SELECT         (CUI_INLINE_ITEM_ID_BASE + 2)
#define SET_FORMAT_DATE_FORMAT_CAPTION        (CUI_INLINE_ITEM_ID_BASE + 3)
#define SET_FORMAT_DATE_FORMAT_SELECT         (CUI_INLINE_ITEM_ID_BASE + 4)
#define SET_FORMAT_DATE_SEPARATOR_CAPTION        (CUI_INLINE_ITEM_ID_BASE + 5)
#define SET_FORMAT_DATE_SEPARATOR_SELECT         (CUI_INLINE_ITEM_ID_BASE + 6)
#ifdef __MMI_SEPARATE_DT_SETTING__
/* Set date and format */
#define SET_DATE_AND_FORMAT_DATE_FORMAT_CAPTION (CUI_INLINE_ITEM_ID_BASE + 1)
#define SET_DATE_AND_FORMAT_DATE_FORMAT_SELECT (CUI_INLINE_ITEM_ID_BASE + 2)
#define SET_DATE_AND_FORMAT_SET_DATE_CAPTION (CUI_INLINE_ITEM_ID_BASE + 3)
#define SET_DATE_AND_FORMAT_SET_DATE (CUI_INLINE_ITEM_ID_BASE + 4)
/* Set time and format */
#define SET_TIME_AND_FORMAT_TIME_FORMAT_CAPTION (CUI_INLINE_ITEM_ID_BASE + 1)
#define SET_TIME_AND_FORMAT_TIME_FORMAT_SELECT (CUI_INLINE_ITEM_ID_BASE + 2)
#define SET_TIME_AND_FORMAT_SET_TIME_CAPTION (CUI_INLINE_ITEM_ID_BASE + 3)
#define SET_TIME_AND_FORMAT_SET_TIME (CUI_INLINE_ITEM_ID_BASE + 4)
#define SET_TIME_AND_FORMAT_DAYLIGHT_SAVING_CAPTION (CUI_INLINE_ITEM_ID_BASE + 5)
#define SET_TIME_AND_FORMAT_DAYLIGHT_SAVING_SELECT (CUI_INLINE_ITEM_ID_BASE + 6)
#endif


/* 
 * Typedef 
 */

/* 
 * Local Variable
 */
static U8 *homeCityDataPtr[MAX_CITY_NUM];

#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
static U8 gmt_tz_str_buf[MAX_CITY_NUM][70];
static U8 gmt_tz_table[MAX_CITY_NUM];
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */

static MMI_BOOL g_mmi_phnset_dst_dirty_flag;

static U16 g_phnset_dt_on_off_str_id[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static U16 g_time_format_str_id[] = {STR_12, STR_24};
static U16 g_date_format_str_id[] = {STR_ID_DD_MM_YYYY_S, STR_ID_MM_DD_YYYY_S, STR_ID_YYYY_MM_DD_S};
static cui_inline_item_time_struct g_phnset_date_and_time_common_inline_time = 
{
    {0, 0, 0, 0, 0, 0},
    0
};
static MYTIME g_time_buffer;
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption1 = {STR_ENTER_TIME_FORMAT_DISP_CAPTION};
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption2 = {STR_ENTER_DATE_FORMAT_DISP_CAPTION};
static const cui_inline_item_caption_struct g_phnset_set_date_time_caption3 = {STR_ID_PHNSET_SET_DST};
static cui_inline_item_select_struct g_phnset_set_date_time_select1 = 
{
    2, /* Power on and Power off */
    0,
    g_phnset_dt_on_off_str_id
};
static cui_inline_set_item_struct g_phnset_set_date_time_data[] =
{
    {SET_DATE_AND_TIME_SET_TIME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_TIME, &g_phnset_set_date_time_caption1},
    {SET_DATE_AND_TIME_SET_TIME, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &g_phnset_date_and_time_common_inline_time},
    {SET_DATE_AND_TIME_SET_DATE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_CAL, &g_phnset_set_date_time_caption2},
    {SET_DATE_AND_TIME_SET_DATE, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &(g_phnset_date_and_time_common_inline_time.date_time)},    
    {SET_DATE_AND_TIME_DAYLIGHT_SAVING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, SUN_ICON, &g_phnset_set_date_time_caption3},
    {SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_date_time_select1}        
};
static const cui_inline_struct g_phnset_set_date_time_inline =
{
    sizeof(g_phnset_set_date_time_data) / sizeof(cui_inline_set_item_struct),
    STR_ID_PHNSET_SET_DT,
    IMG_SCR_SETTING_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_phnset_set_date_time_data
};

/* Set date and time format */
static U16 g_date_sep_str_id[] = {STR_DT_SEP_DOT, STR_DT_SEP_COLON, STR_DT_SEP_SLOPE, STR_DT_SEP_LINE};
static cui_inline_item_caption_struct g_phnset_set_format_caption1 = {STR_GLOBAL_TIME};
static cui_inline_item_select_struct g_phnset_set_format_select1 = 
{
    2, /* 12 and 24 */
    0,
    g_time_format_str_id
};
static cui_inline_item_caption_struct g_phnset_set_format_caption2 ={STR_GLOBAL_DATE};
static cui_inline_item_select_struct g_phnset_set_format_select2 = 
{
    3,  
    0,
    g_date_format_str_id
};
static cui_inline_item_caption_struct g_phnset_set_format_caption3 ={STR_ID_PHNSET_SET_DATE_SEP};
static cui_inline_item_select_struct g_phnset_set_format_select3 = 
{
    4,  
    0,
    g_date_sep_str_id
};
static cui_inline_set_item_struct g_phnset_set_format_data[] =
{
    {SET_FORMAT_TIME_FORMAT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_TIME, &g_phnset_set_format_caption1},
    {SET_FORMAT_TIME_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select1},
    {SET_FORMAT_DATE_FORMAT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_CAL, &g_phnset_set_format_caption2},
    {SET_FORMAT_DATE_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select2},    
    {SET_FORMAT_DATE_SEPARATOR_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_STATUS, &g_phnset_set_format_caption3},
    {SET_FORMAT_DATE_SEPARATOR_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_format_select3}        
};
static const cui_inline_struct g_phnset_set_format_inline =
{
    sizeof(g_phnset_set_format_data) / sizeof(cui_inline_set_item_struct),
    STR_MENU9144_SETTIMEANDDATEFORMAT,
    IMG_SCR_SETTING_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_phnset_set_format_data
};
#ifdef __MMI_SEPARATE_DT_SETTING__
/* Set date and format */
static cui_inline_item_caption_struct g_phnset_set_date_format_caption1 = {STR_DATE_FORMAT_CAPTION};
static cui_inline_item_select_struct g_phnset_set_date_format_select1 = 
{
    3,
    0,
    g_date_format_str_id
};
static cui_inline_item_caption_struct g_phnset_set_date_format_caption2 = {STR_ENTER_DATE_FORMAT_DISP_CAPTION};
static cui_inline_set_item_struct g_phnset_set_date_format_data[] =
{
    {SET_DATE_AND_FORMAT_DATE_FORMAT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_CAL, &g_phnset_set_date_format_caption1},
    {SET_DATE_AND_FORMAT_DATE_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_date_format_select1},
    {SET_DATE_AND_FORMAT_SET_DATE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_CAL, &g_phnset_set_date_format_caption2},
    {SET_DATE_AND_FORMAT_SET_DATE, CUI_INLINE_ITEM_TYPE_DATE | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &(g_phnset_date_and_time_common_inline_time.date_time)}
};
static const cui_inline_struct g_phnset_set_date_format_inline =
{
    sizeof(g_phnset_set_date_format_data) / sizeof(cui_inline_set_item_struct),
    STR_ID_PHNSET_SET_DATEANDFORMAT,
    IMG_SCR_SETTING_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_phnset_set_date_format_data
};
/* Set time and format */
static cui_inline_item_caption_struct g_phnset_set_time_format_caption1 = {STR_TIME_FORMAT_CAPTION};
static cui_inline_item_select_struct g_phnset_set_time_format_select1 =
{
    2,
    0,
    g_time_format_str_id
};
static cui_inline_item_caption_struct g_phnset_set_time_format_caption2 = {STR_ENTER_TIME_FORMAT_DISP_CAPTION};
static cui_inline_item_caption_struct g_phnset_set_time_format_caption3 = {STR_ID_PHNSET_SET_DST};
static cui_inline_item_select_struct g_phnset_set_time_format_select2 = 
{
    2,
    0,
    g_phnset_dt_on_off_str_id
};
static cui_inline_set_item_struct g_phnset_set_time_format_data[] =
{
    {SET_TIME_AND_FORMAT_TIME_FORMAT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_TIME, &g_phnset_set_time_format_caption1},
    {SET_TIME_AND_FORMAT_TIME_FORMAT_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_time_format_select1},
    {SET_TIME_AND_FORMAT_SET_TIME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_TIME, &g_phnset_set_time_format_caption2},
    {SET_TIME_AND_FORMAT_SET_TIME, CUI_INLINE_ITEM_TYPE_TIME | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT, 0, &g_phnset_date_and_time_common_inline_time},
    {SET_TIME_AND_FORMAT_DAYLIGHT_SAVING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, SUN_ICON, &g_phnset_set_time_format_caption3},
    {SET_TIME_AND_FORMAT_DAYLIGHT_SAVING_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_phnset_set_time_format_select2}
};
static const cui_inline_struct g_phnset_set_time_format_inline =
{
    sizeof(g_phnset_set_time_format_data) / sizeof(cui_inline_set_item_struct),
    STR_ID_PHNSET_SET_TIMEANDFORMAT,
    IMG_SCR_SETTING_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT | CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    g_phnset_set_time_format_data
};
#endif

/* 
 * Global Variable
 */
extern MYTIME MyTime;
extern BOOL SetFromAT;
extern rtc_format_struct gclockData;
extern U8 g_dst;

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
extern MMI_BOOL ATFromSIM2;
#endif

/* 
 * Global Function
 */
#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
static void mmi_dt_get_gmt_tz_string(U8 *result, FLOAT timezone);
static void mmi_dt_gmt_tz_list(void);
static S32 mmi_dt_gmt_tz_get_hilite(U8 cityindex);
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
extern void mmi_dt_tz_update_datetime(S16 newTimeZone);
static void EntryPhnsetDateTimeUpdate(MMI_ID parent_gid);
static mmi_ret mmi_phnset_change_date_time_proc(mmi_event_struct *param);
static void mmi_phnset_init_change_date_time_list(void);
#endif

extern void Category53ChangeItemDescription(S32 index, U8 *text);
extern void EntryIdleScreen(void);
extern void DateTimerProc(void);

/* extern void updateSPOFDateChanged(void) ; */
extern void updateAlarmsDateChanged(void);
extern FLOAT GetTimeZone(U8 cityIndex);

#ifdef __MMI_DUAL_CLOCK__
extern U8 PhnsetGetForeignCity(void);
#ifndef __MMI_HIDE_HOMECITY__
extern void PhnsetSetForeignCity(void);
#endif /* __MMI_HIDE_HOMECITY__ */
#endif /* __MMI_DUAL_CLOCK__ */

/* Local Function */

static void EntryPhnsetSetFormat(MMI_ID parent_gid);
static mmi_ret mmi_phnset_set_format_proc(mmi_event_struct *param);
static void PhnsetSetFormat(void);
static void PhnsetSetDT(void);
static void ExitPhnsetSetDT(void);
static void PhnsetSetDTAndFormatFillInlineStruct(void *p);
#ifdef __MMI_SEPARATE_DT_SETTING__
static void mmi_phnset_set_separate_dt_format(void);
static void mmi_phnset_entry_separate_dt_format_setting(MMI_ID parent_gid);
static mmi_ret mmi_phnset_separate_dt_format_proc(mmi_event_struct *param);
#endif 
/* AT handler */
static void ATSetDateandTimeFormat(void *msg, int mod_id); 
static void AtQueryDTFmtIndHdlr(void *msg, int mod_id);
static void ATSetRTC(void *msg, int mod_id);

static void PhnsetConstructCityList(void);

static void PhnsetHCMultiTapHdlr(UI_character_type inp);
static void PhnsetSetTimeResHdlrForAT(void *info, int mod_src);
static void PhnsetSetTimeResHdlr(void *info);
static void mmi_phnset_date_and_time_inline_time_to_mytime(cui_inline_item_time_struct *inline_time);
static void mmi_phnset_date_and_time_mytime_to_inline_time(cui_inline_item_time_struct *inline_time);
static void mmi_phnset_date_and_time_init_format(void);
static void mmi_phnset_date_and_time_dst_changed_handler(U8 select_dst, cui_inline_item_time_struct *inline_time);
static void mmi_phnset_date_and_time_init_dt(cui_inline_item_time_struct *inline_time);
static void mmi_phnset_date_and_time_reset_dt_boundary(void);
static mmi_ret mmi_phnset_time_and_date_sub_menu_select_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
static mmi_ret mmi_phnset_time_and_date_sub_menu_entry_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
static mmi_ret mmi_phnset_time_and_date_sub_menu_highlight_handler(cui_menu_event_struct *param, MMI_ID parent_gid);
static void mmi_phnset_init_time_and_date(void);
static void mmi_phnset_entry_set_date_and_time(MMI_ID parent_gid);
static mmi_ret mmi_phnset_set_date_time_proc(mmi_event_struct *param);
#ifndef __MMI_HIDE_HOMECITY__
static void mmi_phnset_entry_set_home_city(MMI_ID parent_gid);
static void mmi_phnset_entry_set_home_city_int(mmi_scrn_essential_struct *scrn_data);
#ifdef __MMI_WC_TZ_SUPPORT__
static void mmi_phnset_entry_wc_select_city(MMI_ID parent_gid);
#endif
#endif /* __MMI_HIDE_HOMECITY__ */

/*****************************************************************************
 * FUNCTION
 *  HintPhnsetTimeAndDate
 * DESCRIPTION
 *  This function is hint handling function
 *  for Phonesetup -> Time and Data ( Set Home City, Auto Update Date and Time)
 *  Functionality:
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetTimeAndDate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
    U8 hint_timezone[30];
    FLOAT homecity_tz;
#endif
    MMI_ID menucui_id = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_HIDE_HOMECITY__
#ifndef __MMI_TWO_LAYER_HOMECITY__
	 cui_menu_set_item_hint(
	    menucui_id,
	    MENU9142_SETHOMECITY,
	    (WCHAR*)g_phnset_cntx_p->CurHomeCityStrPtr);
 #else /* __MMI_TWO_LAYER_HOMECITY__ */
     memset(hint_timezone, 0x00, 30);
     homecity_tz = GetTimeZone(PhnsetGetHomeCity());
     mmi_dt_get_gmt_tz_string(hint_timezone, homecity_tz);
		 cui_menu_set_item_hint(
		    menucui_id,
		    MENU9142_SETHOMECITY,
		    (WCHAR*)hint_timezone);
 #endif /* __MMI_TWO_LAYER_HOMECITY__ */
#ifdef __MMI_DUAL_CLOCK__
    cui_menu_set_item_hint(            
	    menucui_id,
	    MENU9142_SETFOREIGNCITY,
        (WCHAR*)g_phnset_cntx_p->CurForeignCityStrPtr);
#endif /* __MMI_OP11_HOMESCREEN__ */
#endif /* __MMI_HIDE_HOMECITY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_mytime_to_inline_time
 * DESCRIPTION
 *  Transfer g_time_buffer to inline time struct 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_mytime_to_inline_time(cui_inline_item_time_struct *inline_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_time->date_time.year = g_time_buffer.nYear;
    inline_time->date_time.month = g_time_buffer.nMonth;
    inline_time->date_time.day = g_time_buffer.nDay;
    inline_time->date_time.hour = g_time_buffer.nHour;    
    inline_time->date_time.minute = g_time_buffer.nMin;
    inline_time->date_time.second = g_time_buffer.nSec;
    inline_time->date_format = 0;    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_inline_time_to_mytime
 * DESCRIPTION
 *  Transfer inline time struct data to g_time_buffer 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_inline_time_to_mytime(cui_inline_item_time_struct *inline_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_time_buffer.nYear = (kal_uint16)inline_time->date_time.year;
    g_time_buffer.nMonth = (kal_uint8)inline_time->date_time.month;
    g_time_buffer.nDay = (kal_uint8)inline_time->date_time.day;
    g_time_buffer.nHour = (kal_uint8)inline_time->date_time.hour;    
    g_time_buffer.nMin = (kal_uint8)inline_time->date_time.minute;
    /* Inline cui will not return second */
    g_time_buffer.nSec = 0;

    }


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_init_dt
 * DESCRIPTION
 *  Get current time and save it in g_time_buffer, output a
 *  cui_inline_item_time_struct
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_init_dt(cui_inline_item_time_struct *inline_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&g_time_buffer);

    mmi_phnset_date_and_time_mytime_to_inline_time(inline_time);

    ReadValue(NVRAM_SETTING_DT_DST, &(g_phnset_cntx_p->currentDST), DS_BYTE, &error);     
    set_inline_date_boundary(2030, 2000, 12, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_reset_dt_boundary
 * DESCRIPTION
 *  Reset the date boundary after exit date and time setting 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_reset_dt_boundary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_inline_date_boundary(2030, 1970, 12, 1);
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_init_format
 * DESCRIPTION
 *  Init date and time format 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_init_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->CurTimeFmt = PhnsetGetTimeFormat();
    g_phnset_cntx_p->CurDateFmt = PhnsetGetDateFormat();
	g_phnset_cntx_p->CurDateSep= PhnsetGetDateSeperatorFormat();    
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_dst_changed_handler
 * DESCRIPTION
 *  Handler for change day light saving selection 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_date_and_time_dst_changed_handler(U8 select_dst, cui_inline_item_time_struct *inline_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME inc_time;
    MYTIME result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&inc_time, 0, sizeof(MYTIME));
    inc_time.nHour = 1;

    mmi_phnset_date_and_time_inline_time_to_mytime(inline_time);
    
    if(select_dst != g_phnset_cntx_p->currentDST)
    {
        /* on -> off */
        g_phnset_cntx_p->currentDST = select_dst;
        if (select_dst)
    	{
            /* on -> off */
            IncrementTime(g_time_buffer, inc_time, &result);
            
    	}
        else
        {
            /* off -> on */
            DecrementTime(g_time_buffer, inc_time, &result);
        }

        if (result.nYear > 2030 || result.nYear < 2000)
        {
            srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);
            return;
        }
        
        if (g_time_buffer.nDay != result.nDay)
    	{
            g_time_buffer.nYear = result.nYear;
            g_time_buffer.nMonth = result.nMonth;
            g_time_buffer.nDay = result.nDay;        
    	}
        g_time_buffer.nHour = result.nHour;
        g_time_buffer.nMin = result.nMin;
        g_time_buffer.nSec = result.nSec;    
        mmi_phnset_date_and_time_mytime_to_inline_time(inline_time);
    }    
}
 

/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetSetDT
 * DESCRIPTION
 *  Set Date And Time Entry Function
 *  
 *  This Screen Uses Category 57 and Text Box Edit For Data Entry.
 * PARAMETERS
 *  curr_gid    [IN] Group ID where the set date and time app will be created on
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetSetDT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_entry_set_date_and_time(GRP_ID_ROOT);
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_set_date_and_time
 * DESCRIPTION
 *  Internal entry function 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_set_date_and_time(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID *inlinecui_gid;
    cui_inline_item_time_struct inline_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_DT;

    if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_TIME_AND_DATE))
	{
	    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    if (!parent_gid)
	{
	    parent_gid = GRP_ID_ROOT;
	}
    inlinecui_gid = (MMI_ID*)OslMalloc(sizeof(MMI_ID));
    mmi_frm_group_create(
        parent_gid,
        GRP_ID_PHNSET_SET_TIME_AND_DATE,
        mmi_phnset_set_date_time_proc,
        (void*)inlinecui_gid);
    mmi_frm_group_enter(GRP_ID_PHNSET_SET_TIME_AND_DATE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    *inlinecui_gid = cui_inline_create(
        GRP_ID_PHNSET_SET_TIME_AND_DATE,
        &g_phnset_set_date_time_inline);


    mmi_phnset_date_and_time_init_dt(&inline_time);
	memcpy((void*)&g_phnset_cntx_p->settime.prev_time, (void*)&g_time_buffer, sizeof(MYTIME));
	g_phnset_cntx_p->settime.prev_time.nSec = 0;
        
    cui_inline_set_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);

    cui_inline_set_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));

    cui_inline_set_value(*inlinecui_gid, SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, (void*)g_phnset_cntx_p->currentDST);
    cui_inline_run(*inlinecui_gid);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_date_time_proc
 * DESCRIPTION
 *  Proc function for set date and time 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_set_date_time_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:        
        PhnsetSetDT();
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(mmi_frm_group_get_active_id());
        break;

    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)param;
            if ((notify_event->item_id == SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT) && (notify_event->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED))
        	{
                cui_inline_item_time_struct inline_time;
                U8 highlighted_item;
                MMI_ID *inlinecui_gid = 
                    (MMI_ID*)mmi_frm_group_get_user_data(GRP_ID_PHNSET_SET_TIME_AND_DATE);
                cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);
                cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));
                cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, (void*)&highlighted_item);
                
                mmi_phnset_date_and_time_dst_changed_handler(highlighted_item, &inline_time);
                
                g_mmi_phnset_dst_dirty_flag = MMI_TRUE;
                cui_inline_set_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);
                cui_inline_set_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));
                
        	}
            break;
        }
   
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        set_inline_date_boundary(2030, 2000, 12, 1);
        break;
        
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        mmi_phnset_date_and_time_reset_dt_boundary();   
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
            OslMfree(param->user_data);
            param->user_data = NULL;
    	}
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ExitPhnsetSetDT
 * DESCRIPTION
 *  This function is Exit function for Phonesetup-> Time and Date -> Set Time/Date
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhnsetSetDT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_ERROR);
    mmi_frm_group_close(GRP_ID_PHNSET_SET_TIME_AND_DATE);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetDT
 * DESCRIPTION
 *  This function is to set date and time for Phonesetup-> Time and Date -> Set Time/DAte
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetDT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_time_struct inline_time;
    MMI_ID *inlinecui_gid = (MMI_ID*)mmi_frm_group_get_user_data(GRP_ID_PHNSET_SET_TIME_AND_DATE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_TIME, (void*)&inline_time);
    cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_TIME_SET_DATE, (void*)&(inline_time.date_time));
    cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_TIME_DAYLIGHT_SAVING_SELECT, (void*)&(g_phnset_cntx_p->currentDST));
    
    mmi_phnset_date_and_time_inline_time_to_mytime(&inline_time);
    if ((g_time_buffer.nHour > 23) || (g_time_buffer.nMin > 59)
        || (g_time_buffer.nYear > 2030) || (g_time_buffer.nYear < 2000)
        || (g_time_buffer.nMonth > 12) || (g_time_buffer.nMonth < 1)
        || (g_time_buffer.nDay > 31) || (g_time_buffer.nDay < 1) 
        || (LastDayOfMonth((U8)g_time_buffer.nMonth, (U8)g_time_buffer.nYear) <
         g_time_buffer.nDay))
    {
        mmi_popup_display_simple((WCHAR*)GetString(STR_SETTIME_UNFINISHED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);            
    }
    else
    {
        U8 flag;
        S16 error;

        ReadValue(NVRAM_SETTING_DT_DST, &flag, DS_BYTE, &error);
        if (flag != g_phnset_cntx_p->currentDST)
        {
            mmi_dt_set_dst((U8) g_phnset_cntx_p->currentDST);
        }

        PhnsetSendSetTimeReqMessage();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_date_and_time_init_at_handler
 * DESCRIPTION
 *  Init AT handler for date and time setting 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_date_and_time_init_at_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(ATSetRTC, PRT_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND);
    SetProtocolEventHandler(ATSetDateandTimeFormat, PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND);    
    SetProtocolEventHandler(AtQueryDTFmtIndHdlr, PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND);    
}


/*****************************************************************************
 * FUNCTION
 *  ATSetDateandTimeFormat
 * DESCRIPTION
 *  AT Command set Date Time Format
 * PARAMETERS
 *  msg     [?]     Set date time format request message, specifying time/date
 * RETURNS
 *  void
 *****************************************************************************/
static void ATSetDateandTimeFormat(void *msg, int mod_id)
{
#ifndef __SLIM_AT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 date_time_fmt = 0;
    mmi_eq_set_date_time_format_req_ind_struct *msgReq;
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_date_time_format_req_ind_struct*) msg;

    SetFromAT = TRUE;

    if (msgReq->is_date_set)
    {
		mmi_phnset_dt_set_datefmt(msgReq->mode);
    }
    else
    {
        switch (msgReq->mode)
        {
            case TIME_HH_MM_24:
                date_time_fmt = 1;
                break;
            case TIME_HH_MM_12:
                date_time_fmt = 0;
                break;
            default:
                break;  /* formt not support */
        }

        PhnsetSetTimeFormat(date_time_fmt);
    }

    SetFromAT = FALSE;

    if (mmi_idle_is_active())
    {
        mmi_idle_display();
    }

    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    
    rsp_msg->result = TRUE;
    
    SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, mod_id, (void*)rsp_msg, NULL);
#endif /* __SLIM_AT__ */    
}


/*****************************************************************************
 * FUNCTION
 *  AtQueryDTFmtIndHdlr
 * DESCRIPTION
 *  Query date time format setting from AT command
 * PARAMETERS
 *  msg     [?]     Query type (time/date)
 * RETURNS
 *  void
 *****************************************************************************/
static void AtQueryDTFmtIndHdlr(void *msg, int mod_id)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 date_time_fmt;
    mmi_eq_query_date_time_format_req_ind_struct *in_msg = (mmi_eq_query_date_time_format_req_ind_struct*) msg;
    mmi_eq_query_date_time_format_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg = (mmi_eq_query_date_time_format_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_date_time_format_res_req_struct));

    if (in_msg->is_date == MMI_TRUE)
    {   /* Query date format */

        res_msg->is_date = MMI_TRUE;
		res_msg->mode = mmi_phnset_dt_get_datefmt();

    }
    else
    {   /* Query time format */

        res_msg->is_date = MMI_FALSE;
        date_time_fmt = PhnsetGetTimeFormat();

        switch (date_time_fmt)
        {
            case 0:
                res_msg->mode = TIME_HH_MM_12;
                break;
            case 1:
                res_msg->mode = TIME_HH_MM_24;
                break;
            default:
                res_msg->mode = TIME_HH_MM_12;
                break;
        }
    }

    SendMsg2AT(PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ, mod_id, (void*)res_msg, NULL);
#endif /* __SLIM_AT__ */
}


/*****************************************************************************
 * FUNCTION
 *  ATSetRTC
 * DESCRIPTION
 *  AT command set RTC
 * PARAMETERS
 *  msg     [?]     RTC
 * RETURNS
 *  void
 *****************************************************************************/
static void ATSetRTC(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYTIME alarmDateTime;
    mmi_eq_set_rtc_time_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_rtc_time_req_ind_struct*) msg;

    SetFromAT = TRUE;
    if (msgReq->rtc_type == RTC_TIME_CLOCK_IND)
    {
        mmi_at_general_res_req_struct *rsp_msg;

        rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

        alarmDateTime.nSec = msgReq->alarm.data_time.rtc_sec;
        alarmDateTime.nMin = msgReq->alarm.data_time.rtc_min;
        alarmDateTime.nHour = msgReq->alarm.data_time.rtc_hour;
        alarmDateTime.nDay = msgReq->alarm.data_time.rtc_day;
        alarmDateTime.nMonth = msgReq->alarm.data_time.rtc_mon;
        alarmDateTime.nYear = msgReq->alarm.data_time.rtc_year + YEARFORMATE;

        if (PhnsetSetDTFromAT(alarmDateTime))
        {
            rsp_msg->result = TRUE;
        }
        else
        {
            rsp_msg->result = FALSE;
        }

        SendMsg2AT(MSG_ID_MMI_AT_GENERAL_RES_REQ, mod_id, (void*)rsp_msg, NULL);
    }
    SetFromAT = FALSE;

    if (mmi_idle_is_active())
    {
        mmi_idle_display();
    }

}


/* 
 * Set Format
 */

#ifndef __MMI_SEPARATE_DT_SETTING__
/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetSetFormat
 * DESCRIPTION
 *  This function is Entry function for Phonesetup-> Time and Date -> Set Format
 *  Following functions:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetSetFormat(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID *inlinecui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT))
	{
	    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    if (!parent_gid)
	{
	    parent_gid = GRP_ID_ROOT;
	}
    inlinecui_gid = (MMI_ID*)OslMalloc(sizeof(MMI_ID));
    mmi_frm_group_create(
        parent_gid,
        GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT,
        mmi_phnset_set_format_proc,
        (void*)inlinecui_gid);
    mmi_frm_group_enter(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    *inlinecui_gid = cui_inline_create(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT, &g_phnset_set_format_inline);

    mmi_phnset_date_and_time_init_format();
    
    cui_inline_set_value(*inlinecui_gid, SET_FORMAT_TIME_FORMAT_SELECT, (void*)g_phnset_cntx_p->CurTimeFmt);
    cui_inline_set_value(*inlinecui_gid, SET_FORMAT_DATE_FORMAT_SELECT, (void*)g_phnset_cntx_p->CurDateFmt);    
    cui_inline_set_value(*inlinecui_gid, SET_FORMAT_DATE_SEPARATOR_SELECT, (void*)g_phnset_cntx_p->CurDateSep);
    
    cui_inline_run(*inlinecui_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_format_proc
 * DESCRIPTION
 *  Proc function for set date and time format 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_set_format_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        PhnsetSetFormat();
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(mmi_frm_group_get_active_id());
        break;
   
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
            OslMfree(param->user_data);
            param->user_data = NULL;
    	}
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetFormat
 * DESCRIPTION
 *  This function is to set date/time format for PhoneSetup->Time and Date->Set Format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PhnsetSetFormat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID *inlinecui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inlinecui_gid = (MMI_ID*)mmi_frm_group_get_user_data(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT);
    cui_inline_get_value(*inlinecui_gid, SET_FORMAT_TIME_FORMAT_SELECT, (void*)&g_phnset_cntx_p->CurTimeFmt);
    cui_inline_get_value(*inlinecui_gid, SET_FORMAT_DATE_FORMAT_SELECT, (void*)&g_phnset_cntx_p->CurDateFmt);    
    cui_inline_get_value(*inlinecui_gid, SET_FORMAT_DATE_SEPARATOR_SELECT, (void*)&g_phnset_cntx_p->CurDateSep);

    if (((U8) g_phnset_cntx_p->CurTimeFmt != PhnsetGetTimeFormat()) ||
        ((U8) (g_phnset_cntx_p->CurDateFmt) != PhnsetGetDateFormat()) || 
        ((U8) (g_phnset_cntx_p->CurDateSep) != PhnsetGetDateSeperatorFormat()))
    {
        /* Save New Time Format To NVRAM if Value is Changed. */
        PhnsetSetTimeFormat((U8) g_phnset_cntx_p->CurTimeFmt);
        /* Save New Date Format To NVRAM if Value is Changed. */
        PhnsetSetDateFormat((U8) g_phnset_cntx_p->CurDateFmt);
		
		PhnsetSetDateSeperatorFormat((U8) g_phnset_cntx_p->CurDateSep);
    }
    SUBLCD_RedrawCategoryFunction();
    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);        

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_op11_hs32_set_done_flag();
    /* mmi_frm_group_close(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT); */
#endif
    /* DeleteUptoScrID(SCR9041_TIMEANDDATE); */
    mmi_frm_group_close(GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT);
}
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
void mmi_entry_phnset_time_format(void)
{
    EntryPhnsetSetFormat(GRP_ID_ROOT);
}
#endif
// #else // __MMI_SEPARATE_DT_SETTING__


#ifdef __MMI_SEPARATE_DT_SETTING__
 /*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_separate_dt_format_setting
 * DESCRIPTION
 *  Set Date And Time Entry Function
 *  
 *  This Screen Uses Category 57 and Text Box Edit For Data Entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_entry_separate_dt_format_setting(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID *inlinecui_gid;
    cui_inline_item_time_struct inline_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT))
	{
	    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    if (!parent_gid)
	{
	    parent_gid = GRP_ID_ROOT;
	}
    
    inlinecui_gid = (MMI_ID*)OslMalloc(sizeof(MMI_ID));    
    
    mmi_frm_group_create(
        parent_gid,
        GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT,
        mmi_phnset_separate_dt_format_proc,
        (void*)inlinecui_gid);
    mmi_frm_group_enter(GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_phnset_date_and_time_init_dt(&inline_time);
    mmi_phnset_date_and_time_init_format();

    if (g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_DATEANDFORMAT)
    {
        *inlinecui_gid = cui_inline_create(GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT, &g_phnset_set_date_format_inline);

        cui_inline_set_value(*inlinecui_gid, SET_DATE_AND_FORMAT_DATE_FORMAT_SELECT, (void*)g_phnset_cntx_p->CurDateFmt);
        cui_inline_set_value(*inlinecui_gid, SET_DATE_AND_FORMAT_SET_DATE, (void*)&(inline_time.date_time));	
}
    else if(g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_TIMEANDFORMAT)
{
        *inlinecui_gid = cui_inline_create(GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT, &g_phnset_set_time_format_inline);

        cui_inline_set_value(*inlinecui_gid, SET_TIME_AND_FORMAT_TIME_FORMAT_SELECT, (void*)g_phnset_cntx_p->CurTimeFmt);
        cui_inline_set_value(*inlinecui_gid, SET_TIME_AND_FORMAT_SET_TIME, (void*)&inline_time);
        cui_inline_set_value(*inlinecui_gid, SET_TIME_AND_FORMAT_DAYLIGHT_SAVING_SELECT, (void*)g_phnset_cntx_p->currentDST);
	}
    cui_inline_run(*inlinecui_gid);
/*
    mmi_frm_scrn_first_enter(
        GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT,
        SCR_ID_PHNSET_SET_DATEANDFORMAT,
        (FuncPtr)mmi_phnset_entry_set_date_and_format_int,
        NULL);
*/        
 }    


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_separate_dt_format_proc
 * DESCRIPTION
 *  Proc function fro set date and format 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_separate_dt_format_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:        
        mmi_phnset_set_separate_dt_format();
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(mmi_frm_group_get_active_id());
        break;

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        set_inline_date_boundary(2030, 2000, 12, 1);
        break;

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        mmi_phnset_date_and_time_reset_dt_boundary();   
        break;

    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    {
            OslMfree(param->user_data);
            param->user_data = NULL;
    }
        break;

    default:
        break;
}
    return MMI_RET_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_set_separate_dt_format
 * DESCRIPTION
 *  This function is to set date/time format for PhoneSetup->Time and Date->Set Format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_set_separate_dt_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_time_struct inline_time;
    MMI_ID *inlinecui_gid = (MMI_ID*)mmi_frm_group_get_user_data(GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_DATEANDFORMAT)
    {
        cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_FORMAT_DATE_FORMAT_SELECT, (void*)&g_phnset_cntx_p->CurDateFmt);
        cui_inline_get_value(*inlinecui_gid, SET_DATE_AND_FORMAT_SET_DATE, (void*)&(inline_time.date_time));	
        g_time_buffer.nYear = (kal_uint16)inline_time.date_time.year;
        g_time_buffer.nMonth = (kal_uint8)inline_time.date_time.month;
        g_time_buffer.nDay = (kal_uint8)inline_time.date_time.day;        
    }
    else if(g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_TIMEANDFORMAT)
            {
        cui_inline_get_value(*inlinecui_gid, SET_TIME_AND_FORMAT_TIME_FORMAT_SELECT, (void*)&g_phnset_cntx_p->CurTimeFmt);
        cui_inline_get_value(*inlinecui_gid, SET_TIME_AND_FORMAT_SET_TIME, (void*)&inline_time);
        cui_inline_get_value(*inlinecui_gid, SET_TIME_AND_FORMAT_DAYLIGHT_SAVING_SELECT, (void*)&g_phnset_cntx_p->currentDST);
        g_time_buffer.nHour = (kal_uint8)inline_time.date_time.hour;    
        g_time_buffer.nMin = (kal_uint8)inline_time.date_time.minute;        
}

    /* mmi_phnset_date_and_time_inline_time_to_mytime(&inline_time); */

    if (((g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_TIMEANDFORMAT) &&
         ((g_time_buffer.nHour > 23) || (g_time_buffer.nMin > 59)))
        || ((g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_DATEANDFORMAT) &&
            ((g_time_buffer.nYear > 2030) || (g_time_buffer.nYear < 2000)
        || (g_time_buffer.nMonth > 12) || (g_time_buffer.nMonth < 1)
        || (g_time_buffer.nDay > 31) || (g_time_buffer.nDay < 1) 
        || (LastDayOfMonth((U8)g_time_buffer.nMonth, (U8)g_time_buffer.nYear) <
         g_time_buffer.nDay))))
    {
		mmi_popup_display_simple((WCHAR*) GetString(STR_SETTIME_UNFINISHED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    else
    {
        U8 flag;
        S16 error;

        ReadValue(NVRAM_SETTING_DT_DST, &flag, DS_BYTE, &error);
        if (flag != g_phnset_cntx_p->currentDST)
        {
            mmi_dt_set_dst((U8) g_phnset_cntx_p->currentDST);
        }

        PhnsetSendSetTimeReqMessage();
    }

    if (((U8) g_phnset_cntx_p->CurTimeFmt != PhnsetGetTimeFormat()) ||
        ((U8) (g_phnset_cntx_p->CurDateFmt) != PhnsetGetDateFormat()) || 
        ((U8) (g_phnset_cntx_p->CurDateSep) != PhnsetGetDateSeperatorFormat()))
    {
        /* Save New Time Format To NVRAM if Value is Changed. */
        PhnsetSetTimeFormat((U8) g_phnset_cntx_p->CurTimeFmt);
        /* Save New Date Format To NVRAM if Value is Changed. */
        PhnsetSetDateFormat((U8) g_phnset_cntx_p->CurDateFmt);

		PhnsetSetDateSeperatorFormat((U8) g_phnset_cntx_p->CurDateSep);
    }
    SUBLCD_RedrawCategoryFunction();
}
#endif

/* 
 * Home City
 */


/*****************************************************************************
 * FUNCTION
 *  PhnsetInitTimeNDate
 * DESCRIPTION
 *  This function is to
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetInitTimeNDate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * int i =0;
     * for(i =0;i< NUM_CITYS;i++)
     * city_list[i]=STR_WCLOCK_CITY1 +i;
     * 
     * for(i =0;i< NUM_CITYS;i++)
     * city_number_icon[i] = IMG_NONE;
     */
    PhnsetConstructCityList();
    g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];
#ifdef __MMI_DUAL_CLOCK__
	g_phnset_cntx_p->CurForeignCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
#endif

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetReadNvmHomeCityIdxNStoreCityName
 * DESCRIPTION
 *  This function is to (1) Read home city index from nvram
 *  (2) Store city name (digits) in global variable
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReadNvmHomeCityIdxNStoreCityName(void)   /* Used on Language change */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_CLOCK__
	ReadValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
    if (error != NVRAM_READ_SUCCESS)
    {
        g_phnset_cntx_p->foreign_city = 0;
    }
    else if (g_phnset_cntx_p->foreign_city > NUM_CITYS)
    {
        g_phnset_cntx_p->foreign_city = 0;
    }
    g_phnset_cntx_p->CurForeignCityStrID = TimeZoneData[g_phnset_cntx_p->foreign_city + 1].CityName;
		
#endif	/* __MMI_DUAL_CLOCK__ */	
	
    ReadValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
    if (error != NVRAM_READ_SUCCESS)
    {
        g_phnset_cntx_p->currentCity = 0;
    }
    else if (g_phnset_cntx_p->currentCity > NUM_CITYS)
    {
        g_phnset_cntx_p->currentCity = 0;
    }
    g_phnset_cntx_p->CurHomeCityStrID = TimeZoneData[g_phnset_cntx_p->currentCity + 1].CityName;

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetReinitHomeCity
 * DESCRIPTION
 *  This function is to Restore the city index when language change
 *  Functionality: !!!NOTICE!!! the function should use together with PhnsetReadNvmHomeCityIdxNStoreCityName()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetReinitHomeCity(void) /* Used on Language change, together with PhnsetReadNvmHomeCityIdxNStoreCityName()  */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i;
    U8 num_city = NUMBER_OF_CITY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetConstructCityList();
    for (i = 0; i < num_city; i++)
    {
        if (TimeZoneData[i].CityName == g_phnset_cntx_p->CurHomeCityStrID)
        {
            g_phnset_cntx_p->currentCity = i - 1;
            WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
            break;
        }
    }
    g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];

#ifdef __MMI_DUAL_CLOCK__
    for (i = 0; i < num_city; i++)
    {
        if (TimeZoneData[i].CityName == g_phnset_cntx_p->CurForeignCityStrID)
        {
            g_phnset_cntx_p->foreign_city= i - 1;
            WriteValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
            break;
        }
    }
	g_phnset_cntx_p->CurForeignCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
#endif /* __MMI_DUAL_CLOCK__ */

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetInitSetTimeNDateNvram
 * DESCRIPTION
 *  This function is to read global variable from nvram
 *  for Phonesetup -> Time and Date ->Set Home City
 *  ->Set Time/Date
 *  ->Set Format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetInitSetTimeNDateNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PhnsetReadNvmHomeCityIdxNStoreCityName();
    g_phnset_cntx_p->CurTimeFmt = PhnsetGetTimeFormat();
    g_phnset_cntx_p->CurDateFmt = PhnsetGetDateFormat();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetConstructCityList
 * DESCRIPTION
 *  This function is to
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetConstructCityList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_CITYS; i++)
    {
        homeCityDataPtr[i] = (PU8) ((GetString) ((U16) (TimeZoneData[i + 1].CityName)));
    }
}


#ifndef __MMI_HIDE_HOMECITY__
/*****************************************************************************
 * FUNCTION
 *  mmi_setting_home_city_async_callback
 * DESCRIPTION
 *  This function is callback function for generating asynchronous list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_setting_home_city_async_callback(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*img_buff_p = 0;

#ifdef __MMI_TWO_LAYER_HOMECITY__
    mmi_ucs2cpy((S8*)str_buff, (S8*)gmt_tz_str_buf[item_index]);
#else /* __MMI_TWO_LAYER_HOMECITY__ */
    mmi_ucs2cpy(
        (S8*) str_buff,
        (S8*) ((GetString)((U16) (TimeZoneData[item_index + 1].CityName))));
#endif /* __MMI_TWO_LAYER_HOMECITY__ */

#ifdef __MMI_TWO_LAYER_HOMECITY__
#ifdef __MMI_DUAL_CLOCK__
    if (g_phnset_cntx_p->city_flag == 1)
    {
        if (item_index == mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->foreign_city))
        {
            *img_buff_p = get_image(IMG_VICON);
        }
    }
    else if (item_index == mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->currentCity))
    {
        *img_buff_p = get_image(IMG_VICON);
    }
#else /* __MMI_DUAL_CLOCK__ */
    if (item_index == mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->currentCity))
    {
        *img_buff_p = get_image(IMG_VICON);
    }
#endif /* __MMI_DUAL_CLOCK__ */

#else /* __MMI_TWO_LAYER_HOMECITY__ */

#ifdef __MMI_DUAL_CLOCK__
	if (g_phnset_cntx_p->city_flag == 1)
	{
		if (item_index == g_phnset_cntx_p->foreign_city)
		{
			*img_buff_p = get_image(IMG_VICON);
		}
	}
	else if (item_index == g_phnset_cntx_p->currentCity)
	{
		*img_buff_p = get_image(IMG_VICON);
	}
#else /* __MMI_DUAL_CLOCK__ */
	if (item_index == g_phnset_cntx_p->currentCity)
	{
		*img_buff_p = get_image(IMG_VICON);
	}
#endif /* __MMI_DUAL_CLOCK__ */
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetSetHomeCity
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->Time and Date->Set Homecity
 *  Following functions: PhnsetSetHomeCity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnsetSetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_entry_set_home_city(GRP_ID_ROOT);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_set_home_city
 * DESCRIPTION
 *  Entry function fro set homecity 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_set_home_city(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY))
	{
	    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    if (!parent_gid)
	{
	    parent_gid = GRP_ID_ROOT;
	}
    
    mmi_frm_group_create(
        parent_gid,
        GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY,
        NULL,
        NULL);
    mmi_frm_group_enter(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY,
        SETTINGS_SETHOMECITY_SCREENID,
        (FuncPtr)mmi_phnset_entry_set_home_city_int,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_set_home_city_int
 * DESCRIPTION
 *  Internal entry function for set home city 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_set_home_city_int(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 string_id = 0;
    U8 *guiBuffer;
    U8 maxCities = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        scrn_data->group_id,
        scrn_data->scrn_id,
        ExitPhnsetSetHomeCity,
        (FuncPtr)mmi_phnset_entry_set_home_city_int,
        MMI_FRM_UNKNOW_SCRN))	
	{
	    return;
	}

    guiBuffer = mmi_frm_scrn_get_gui_buf(scrn_data->group_id, scrn_data->scrn_id);

    PhnsetReadNvmHomeCityIdxNStoreCityName();
    PhnsetConstructCityList();

    if (guiBuffer == NULL)
    {
    #ifdef __MMI_TWO_LAYER_HOMECITY__   
    #ifdef __MMI_DUAL_CLOCK__
        if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
        {
            g_phnset_cntx_p->curHightlightItem = (U32) mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->foreign_city);	
        }
        else
    #endif
        {
            g_phnset_cntx_p->curHightlightItem = (U32) mmi_dt_gmt_tz_get_hilite(g_phnset_cntx_p->currentCity);
		}

    #else /* __MMI_TWO_LAYER_HOMECITY__ */

    #ifdef __MMI_DUAL_CLOCK__
		if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
		{
			g_phnset_cntx_p->curHightlightItem = (U32) g_phnset_cntx_p->foreign_city;	
		}
		else
	#endif
		{
	        g_phnset_cntx_p->curHightlightItem = (U32) g_phnset_cntx_p->currentCity;
		}
    #endif /* __MMI_TWO_LAYER_HOMECITY__ */

    }
    
#ifdef __MMI_TWO_LAYER_HOMECITY__   
#ifdef __MMI_DUAL_CLOCK__
    if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
    {
		string_id = STR_MENU9142_SETFRNCITY;
    }
    else
#endif
    {
		string_id = STR_MENU9142_SETTIMEZONE;
	}

#else /* __MMI_TWO_LAYER_HOMECITY__ */

#ifdef __MMI_DUAL_CLOCK__
	if (g_phnset_cntx_p->city_flag == 1)    /* foreign city */
	{
		string_id = STR_MENU9142_SETFRNCITY;
	}
	else
#endif
	{
		string_id = STR_MENU9142_SETHOMECITY;
	}
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
    

    maxCities = ((NUM_CITYS > MAX_SUB_MENUS) ? MAX_SUB_MENUS : NUM_CITYS);

#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
	mmi_dt_gmt_tz_list();
#endif

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory184Screen(
        string_id,
        IMG_SCR_SETTING_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NUM_CITYS,
        mmi_setting_home_city_async_callback,
        NULL,
        g_phnset_cntx_p->curHightlightItem,
        guiBuffer);

    RegisterHighlightHandler(PhnsetHomeCityIdxHiliteHandler);

#ifndef __MMI_TWO_LAYER_HOMECITY__
    if (IsEnglishSet())
    {
        wgui_setup_multitap_functions(WGUI_MULTITAP_TYPE_UPPERCASE_ABC_NO_NUMBER, PhnsetHCMultiTapHdlr, PhnsetHCMultiTapCompleteHdlr);
    }
#endif /* __MMI_TWO_LAYER_HOMECITY__ */

    SetLeftSoftkeyFunction(PhnsetSetHomeCity, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(PhnsetSetHomeCity, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_DUAL_CLOCK__
	if (g_phnset_cntx_p->city_flag == 1)
	{
		SetLeftSoftkeyFunction(PhnsetSetForeignCity, KEY_EVENT_UP);
	    SetCenterSoftkeyFunction(PhnsetSetForeignCity, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  ExitPhnsetSetHomeCity
 * DESCRIPTION
 *  This function is Entry function for Phonesetup->Time and Date->Set Homecity
 *  Following functions: PhnsetSetHomeCity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitPhnsetSetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TWO_LAYER_HOMECITY__
	wgui_reset_multitap();
#endif 
}

#ifdef __MMI_WC_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_wc_select_city_proc
 * DESCRIPTION
 *  proc function for select city cui
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static mmi_ret mmi_phnset_wc_select_city_proc(mmi_event_struct *param)
{
	cui_worldclock_event_struct *wc_evt = (cui_worldclock_event_struct *)param;
	U8 ret;

	switch(wc_evt->evt_id)
	{
		case EVT_ID_SCRN_DEINIT:
			break;
			
		case CUI_WC_SELECT_EVENT_OK:
			ret = mmi_wc_entry_from_phnset();
			if (ret == 1)
			{
				PhnsetSetHomeCity();
			}
#ifdef __MMI_DUAL_CLOCK__
			else if (ret == 2)
			{
				PhnsetSetForeignCity();
			}
#endif /* __MMI_DUAL_CLOCK__ */
			break;

		case CUI_WC_SELECT_EVENT_CANCEL:
		case CUI_WC_SELECT_EVENT_CLOSE_REQ:
			cui_worldclock_close(wc_evt->sender_id);
			break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_wc_select_city
 * DESCRIPTION
 *  Entry function fro set homecity 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_wc_select_city(MMI_ID parent_gid)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                               						  */
	/*----------------------------------------------------------------*/
	mmi_id sub_grp;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      						   */
	/*----------------------------------------------------------------*/
	if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY))
	{
		mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
		return;
	}
	
	if (!parent_gid)
	{
	   	 parent_gid = GRP_ID_ROOT;
	}

	mmi_frm_group_create(parent_gid,
						     GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY,
						     mmi_phnset_wc_select_city_proc,
						     NULL);

	mmi_frm_group_enter(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	sub_grp = cui_worldclock_create(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
	if (sub_grp != GRP_ID_INVALID)
	{
		cui_worldclock_run(sub_grp);
	}
	else
	{
		mmi_frm_group_close(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
	}

}
#endif /* __MMI_WC_TZ_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  PhnsetSetHomeCity
 * DESCRIPTION
 *  This function is to set home city for Phonesetup->Time and Date->Set Homecity
 *  Following functions:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S16 tmpCity;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(CURRENT_CITY, &tmpCity, DS_BYTE, &error);

#ifndef __MMI_WC_TZ_SUPPORT__   
#ifdef __MMI_TWO_LAYER_HOMECITY__
    g_phnset_cntx_p->currentCity = gmt_tz_table[g_phnset_cntx_p->curHightlightItem + 1] - 1;
    if (tmpCity != (U8) g_phnset_cntx_p->currentCity)
    {
        g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];
        WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
    }
	tmpCity = (S16)(GetTimeZone(PhnsetGetHomeCity()) * 4);

#else /* __MMI_TWO_LAYER_HOMECITY__ */
	g_phnset_cntx_p->currentCity = (U8) g_phnset_cntx_p->curHightlightItem;
	if (IsEnglishSet())
    {
        wgui_reset_multitap();
    }

    if (tmpCity != (U8) g_phnset_cntx_p->curHightlightItem)
	{
        g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->currentCity];
		WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
	}
	tmpCity = (S16)(GetTimeZone(PhnsetGetHomeCity()) * 4);
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
#else /* __MMI_WC_TZ_SUPPORT__ */
	if ( g_wc_cntx.CurrCityIndex != 0)
    {
        g_phnset_cntx_p->currentCity = g_wc_cntx.CurrCityIndex - 1;
    }
    else
    {
        g_phnset_cntx_p->currentCity = 0xff;
    }

    if (tmpCity != (U8) g_phnset_cntx_p->currentCity)
	{
		g_phnset_cntx_p->CurHomeCityStrPtr = (U8*)GetString(TimeZoneData[g_wc_cntx.CurrCityIndex].CityName);
		WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);
	}
	tmpCity = (S16)(g_wc_cntx.CurrTZ * 4);
    g_wc_cntx.CurrCityIndex= 0xFF;
#endif /* __MMI_WC_TZ_SUPPORT__ */
	
	mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
    mmi_dt_tz_update_datetime(tmpCity);
#endif

    WriteValue(NVRAM_TIMEZONE, &tmpCity, DS_SHORT, &error);
    
/* When time zone changed, TaskList should be updated */
#ifdef __MMI_TDL_NITZ_SUPPORT__
    mmi_clndr_read_nvram();
    mmi_tdl_read_nvram();
#endif


    /* DeleteScreenIfPresent(SETTINGS_SETHOMECITY_SCREENID); */
    /*
    DeleteScreenIfPresent(SCR_ID_WC_BROWSE_CITY);
    */
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY))
	{
    mmi_frm_group_close(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
	}
    SUBLCD_RedrawCategoryFunction();
}

/*****************************************************************************
 * FUNCTION
 *  PhnsetSetForeignCity
 * DESCRIPTION
 *  This function is to set home city for Phonesetup->Time and Date->Set Homecity
 *  Following functions:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DUAL_CLOCK__
void PhnsetSetForeignCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S16 tmpCity;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(FOREIGN_CITY, &tmpCity, DS_BYTE, &error);
           
#ifndef __MMI_WC_TZ_SUPPORT__    
#ifdef __MMI_TWO_LAYER_HOMECITY__
    g_phnset_cntx_p->foreign_city = gmt_tz_table[g_phnset_cntx_p->curHightlightItem + 1] - 1;
    if (tmpCity != (U8) g_phnset_cntx_p->foreign_city)
    {
        g_phnset_cntx_p->CurHomeCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
        WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
    }
    tmpCity = (S16)(GetTimeZone(PhnsetGetForeignCity()) * 4);
    
#else /* __MMI_TWO_LAYER_HOMECITY__ */
	g_phnset_cntx_p->foreign_city = (U8) g_phnset_cntx_p->curHightlightItem;
	if (IsEnglishSet())
    {
        wgui_reset_multitap();
    }

    if (tmpCity != (U8) g_phnset_cntx_p->curHightlightItem)
	{
        g_phnset_cntx_p->CurForeignCityStrPtr = homeCityDataPtr[g_phnset_cntx_p->foreign_city];
		WriteValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
	}
	tmpCity = (S16)(GetTimeZone(PhnsetGetForeignCity()) * 4);
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
#else /* __MMI_WC_TZ_SUPPORT__ */
	g_wc_cntx.FrnCityIdx = g_wc_cntx.CurrCityIndex;
	if ( g_wc_cntx.FrnCityIdx!= 0)
    {
        g_phnset_cntx_p->foreign_city = g_wc_cntx.FrnCityIdx - 1;
    }
    else
    {
        g_phnset_cntx_p->foreign_city = 0xff;
    }

    if (tmpCity != (U8) g_phnset_cntx_p->foreign_city)
	{
		g_phnset_cntx_p->CurForeignCityStrPtr = (U8*)GetString(TimeZoneData[g_wc_cntx.FrnCityIdx].CityName);
		WriteValue(FOREIGN_CITY, &(g_phnset_cntx_p->foreign_city), DS_BYTE, &error);
	}
	tmpCity = (S16)(g_wc_cntx.CurrTZ * 4);
	g_wc_cntx.CurrCityIndex= 0xFF;
#endif  /* __MMI_WC_TZ_SUPPORT__ */      

	mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

    WriteValue(NVRAM_FRN_TIMEZONE, &tmpCity, DS_SHORT, &error);

    /*DeleteScreenIfPresent(SETTINGS_SETHOMECITY_SCREENID);*/
    /*
    DeleteScreenIfPresent(SCR_ID_WC_BROWSE_CITY);
    */
    mmi_frm_group_close(GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY);
    SUBLCD_RedrawCategoryFunction();
}
#endif /* __MMI_DUAL_CLOCK__ */
#endif /* __MMI_HIDE_HOMECITY__ */ 


/*****************************************************************************
 * FUNCTION
 *  PhnsetHomeCityIdxHiliteHandler
 * DESCRIPTION
 *  This function is Highlight handler for Phonesetup->Time and Date->Set Homecity -> (list)
 *  Follow functions: EntryPhnsetMainMenuStyle
 * PARAMETERS
 *  cityIndex       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetHomeCityIdxHiliteHandler(S32 cityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curHightlightItem = (U32) cityIndex;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetHomeCity
 * DESCRIPTION
 *  This function is to get current home city setting
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetHomeCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_phnset_cntx_p->currentCity;
}

#ifdef __MMI_DUAL_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  PhnsetGetHomeCity
 * DESCRIPTION
 *  This function is to get current home city setting
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetForeignCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_phnset_cntx_p->foreign_city;
}
#endif /* __MMI_DUAL_CLOCK__ */

/*****************************************************************************
 * FUNCTION
 *  PhnsetHCGetNearbyIdx
 * DESCRIPTION
 *  This function is to get the nearby city index when multitap presing at browsing home city in english mode
 *  for Phonesetup->Time and Date->Home City
 *  Functionality:
 * PARAMETERS
 *  inp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetHCGetNearbyIdx(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n1 = 0;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((inp >= (UI_character_type) 'A' && inp <= (UI_character_type) 'Z') ||
        (inp >= (UI_character_type) 'a' && inp <= (UI_character_type) 'z'))
    {
        for (i = 0; i < NUM_CITYS; i++)
        {
            memcpy(&n1, homeCityDataPtr[i], ENCODING_LENGTH);
            if (n1 == inp)
            {
                return (U8) (i);
            }
        }

        if (i == NUM_CITYS)
        {
             return i;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetHCMultiTapHdlr
 * DESCRIPTION
 *  This function is multitap handler when browsing home city in english mode
 *  for Phonesetup->Time and Date->Home City
 *  Functionality:
 * PARAMETERS
 *  inp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetHCMultiTapHdlr(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx = (U32)PhnsetHCGetNearbyIdx(inp);
    if ((U8)idx != NUM_CITYS)
    {
        g_phnset_cntx_p->curHightlightItem = idx;
    }
    dynamic_list_goto_item((S32) g_phnset_cntx_p->curHightlightItem);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetHCMultiTapCompleteHdlr
 * DESCRIPTION
 *  This function is to
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetHCMultiTapCompleteHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_list_goto_item((S32) g_phnset_cntx_p->curHightlightItem);
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetDTFromAT
 * DESCRIPTION
 *  This function is to set date and time from AT command
 *  Functionality:
 * PARAMETERS
 *  mytime      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL PhnsetSetDTFromAT(MYTIME mytime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    oslModuleType dest_mod;
#endif 
    RTCTIMEFORMAT *time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mytime.nYear < 1970 || mytime.nYear > 2030
        || mytime.nMonth > 12 || (mytime.nMonth == 0) || (mytime.nDay == 0) ||
        mytime.nDay > LastDayOfMonth(mytime.nMonth, mytime.nYear) || mytime.nHour > 23 || mytime.nMin > 59)
    {
        return MMI_FALSE;
    }
    memcpy((void*)&g_time_buffer, (void*)&mytime, sizeof(MYTIME));
    time = OslAllocDataPtr(RTCTIMEFORMAT);
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;
    time->info.data_time.rtc_sec = mytime.nSec;
    time->info.data_time.rtc_min = mytime.nMin;
    time->info.data_time.rtc_hour = mytime.nHour;

#ifdef __MTK_TARGET__
    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_day = mytime.nDay;         /* gclockData.rtc_hour; */
    time->info.data_time.rtc_mon = mytime.nMonth;       /* gclockData.rtc_mon; */
    /* set correct day index with applib function */

	time->info.data_time.rtc_wday = DOW(mytime.nYear, mytime.nMonth, mytime.nDay);
	if (time->info.data_time.rtc_wday == 0)
	{
		time->info.data_time.rtc_wday = 7;
	}
	
    time->info.data_time.rtc_year = mytime.nYear - YEARFORMATE; /* gclockData.rtc_year; */


#ifdef __MMI_DUAL_SIM_MASTER__
	if (ATFromSIM2)
	{
            dest_mod = MOD_L4C_2;
	}
	else
#endif /* __MMI_DUAL_SIM_MASTER__ */
	{
            dest_mod = MOD_L4C;
	}
    mmi_frm_send_ilm(dest_mod, HW_SET_TIME_REQ, (oslParaType*)time, NULL);
    
    PhnsetSendSetTimeReqMessage();

#else /* __MTK_TARGET__ */ 
    time->rtc_type = 0;
    time->set_type = 2;
    time->info.data_time.rtc_day = mytime.nDay;
    time->info.data_time.rtc_mon = mytime.nMonth;
    time->info.data_time.rtc_wday = DOW(mytime.nYear, mytime.nMonth, mytime.nDay);
	if (time->info.data_time.rtc_wday == 0)
	{
		time->info.data_time.rtc_wday = 7;
	}

    time->info.data_time.rtc_year = (U8) (mytime.nYear - 1900);
    {
		mmi_eq_set_rtc_time_rsp_struct resp;

		resp.result = 1;

        PhnsetSetTimeResHdlr(&resp);
    }
#endif /* __MTK_TARGET__ */ 

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSendSetTimeReqMessage
 * DESCRIPTION
 *  This function is to send set time request to L4
 *  for Phonesetup->Time and Date->Set Time/Date
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSendSetTimeReqMessage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTCTIMEFORMAT *time;
	applib_time_struct rtc_time;
	MYTIME *time_ptr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if defined(__WS_HOME_SAFE__)
 {
    extern MYTIME hf_time;
    g_phnset_cntx_p->settime.year = hf_time.nYear;
    g_phnset_cntx_p->settime.month = hf_time.nMonth;
    g_phnset_cntx_p->settime.date = hf_time.nDay;
    g_phnset_cntx_p->settime.hour = hf_time.nHour;
    g_phnset_cntx_p->settime.minutes = hf_time.nMin;
    memcpy(&g_time_buffer,&hf_time,sizeof(MYTIME));
}    

#else   
    g_phnset_cntx_p->settime.year = g_time_buffer.nYear;
    g_phnset_cntx_p->settime.month = g_time_buffer.nMonth;
    g_phnset_cntx_p->settime.date = g_time_buffer.nDay;
    g_phnset_cntx_p->settime.hour = g_time_buffer.nHour;
    g_phnset_cntx_p->settime.minutes = g_time_buffer.nMin;
#endif
	time_ptr = &g_phnset_cntx_p->settime.prev_time;
    /* get vise clock time */
    if (g_mmi_phnset_dst_dirty_flag &&
		g_phnset_cntx_p->settime.minutes == time_ptr->nMin &&
		((g_phnset_cntx_p->settime.hour == time_ptr->nHour) || 
         (g_phnset_cntx_p->settime.hour == time_ptr->nHour + 1) || 
         (g_phnset_cntx_p->settime.hour == time_ptr->nHour - 1)) &&
		g_phnset_cntx_p->settime.date == time_ptr->nDay &&
		g_phnset_cntx_p->settime.month == time_ptr->nMonth &&
		g_phnset_cntx_p->settime.year == time_ptr->nYear)
    {
        applib_dt_get_rtc_time(&rtc_time);
        g_phnset_cntx_p->settime.sec = rtc_time.nSec;
		g_mmi_phnset_dst_dirty_flag = MMI_FALSE;
    }
    else
    {
        g_phnset_cntx_p->settime.sec = 0;
    }
		
    if (SetFromAT == FALSE)
    {
        SetProtocolEventHandler(PhnsetSetTimeResHdlr, HW_SET_TIME_REQ_SUCCESS);
    }
    else
    {
#ifdef __MMI_DUAL_SIM_MASTER__
		if (ATFromSIM2)
		{
			SetProtocolEventHandler(PhnsetSetTimeResHdlrForAT, HW_SET_TIME_REQ_SUCCESS);
		}
		else
#endif /* __MMI_DUAL_SIM_MASTER__ */
		{
			SetProtocolEventHandler(PhnsetSetTimeResHdlrForAT, HW_SET_TIME_REQ_SUCCESS);
		}
        SetFromAT = FALSE;
        return;
    }

    time = OslAllocDataPtr(RTCTIMEFORMAT);
    time->info.alarm_format = 0;
    time->info.alarm_index = 0;
    time->info.type = 0;
    time->info.text[0] = '\0';
    time->info.recurr = 0;
    time->info.data_time.rtc_sec = g_phnset_cntx_p->settime.sec;
    time->info.data_time.rtc_min = g_phnset_cntx_p->settime.minutes;
    time->info.data_time.rtc_hour = g_phnset_cntx_p->settime.hour;

#ifdef __MTK_TARGET__
    time->rtc_type = RTC_TIME_CLOCK_IND;
    time->set_type = RTC_SETTING_TYPE_DATETIME;
    time->info.data_time.rtc_day = g_phnset_cntx_p->settime.date;
    time->info.data_time.rtc_mon = g_phnset_cntx_p->settime.month;
    time->info.data_time.rtc_year = g_phnset_cntx_p->settime.year - YEARFORMATE;

    time->info.data_time.rtc_wday = DOW(g_phnset_cntx_p->settime.year, 
		time->info.data_time.rtc_mon, time->info.data_time.rtc_day);

	if (time->info.data_time.rtc_wday == 0)
	{
		time->info.data_time.rtc_wday = 7;
	}
    mmi_frm_send_ilm(MOD_L4C, HW_SET_TIME_REQ, (oslParaType*)time, NULL);    

#else /* __MTK_TARGET__ */ 

	{
    #ifdef __DRM_V02__
		applib_time_struct old_time, new_time;

		applib_dt_get_rtc_time(&old_time);
    #endif

        time->rtc_type = 0;
        time->set_type = 2;
        time->info.data_time.rtc_day = g_phnset_cntx_p->settime.date;
        time->info.data_time.rtc_mon = g_phnset_cntx_p->settime.month;
        time->info.data_time.rtc_year = (U8) (g_phnset_cntx_p->settime.year - 1900);

        time->info.data_time.rtc_wday = DOW(g_phnset_cntx_p->settime.year, 
			time->info.data_time.rtc_mon, time->info.data_time.rtc_day);
		
		if (time->info.data_time.rtc_wday == 0)
		{
			time->info.data_time.rtc_wday = 7;
		}

        {
			mmi_eq_set_rtc_time_rsp_struct resp;

			resp.result = 1;
            PhnsetSetTimeResHdlr(&resp);
        }
    #ifdef __DRM_V02__
        applib_dt_get_rtc_time(&new_time);
        DRM_update_local_time(&old_time, &new_time, KAL_FALSE);
    #endif
    }
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetTimeResHdlr
 * DESCRIPTION
 *  This function is Set time response handler (MSG_ID_MMI_EQ_SET_RTC_TIME_RSP)
 *  for Phonesetup->Time and Date->Set Time/Date
 *  Functionality:
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetTimeResHdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_eq_set_rtc_time_rsp_struct*) (info);
    g_phnset_cntx_p->settime.year = g_time_buffer.nYear;
    g_phnset_cntx_p->settime.month = g_time_buffer.nMonth;
    g_phnset_cntx_p->settime.date = g_time_buffer.nDay;
    g_phnset_cntx_p->settime.hour = g_time_buffer.nHour;
    g_phnset_cntx_p->settime.minutes = g_time_buffer.nMin;

    if (resp->result == 1)
    {
    #ifdef __MTK_TARGET__
        gclockData.rtc_year = g_phnset_cntx_p->settime.year - YEARFORMATE;
        gclockData.rtc_mon = g_phnset_cntx_p->settime.month;
        gclockData.rtc_day = g_phnset_cntx_p->settime.date;
        gclockData.rtc_hour = g_phnset_cntx_p->settime.hour;
        gclockData.rtc_min = g_phnset_cntx_p->settime.minutes;
		gclockData.rtc_sec= g_phnset_cntx_p->settime.sec;
    #else /* __MTK_TARGET__ */ 
        MyTime.nHour = g_phnset_cntx_p->settime.hour;
        MyTime.nMin = g_phnset_cntx_p->settime.minutes;
        MyTime.nYear = g_phnset_cntx_p->settime.year;
        MyTime.nMonth = g_phnset_cntx_p->settime.month;
        MyTime.nDay = g_phnset_cntx_p->settime.date;
		MyTime.nSec = g_phnset_cntx_p->settime.sec;
		
        DateTimerProc();
    #endif /* __MTK_TARGET__ */ 

        /* Lisen0522 */
        update_mainlcd_dt_display();
        update_sublcd_dt_display();
        //              AsyncEvent = FALSE;
        //              oneoccured=1;
#ifndef __MMI_OP11_ALARM_SNOOZE_CONTROL__
        AlmReInitialize();
#endif
		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        /*DeleteScreenIfPresent(SCR_ID_PHNSET_SET_DT);*/
        if (SetFromAT == FALSE)
        {
#ifdef __MMI_SEPARATE_DT_SETTING__            
            if (mmi_frm_group_is_present(GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT))
    	{
            	mmi_frm_group_close(GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT);
    	}
#else            
        if (mmi_frm_group_is_present(GRP_ID_PHNSET_SET_TIME_AND_DATE))
    	{
    	    mmi_frm_group_close(GRP_ID_PHNSET_SET_TIME_AND_DATE);
    	}
#endif            
        }
        //DeleteNHistory(1);
    }
    else
    {
        /* AsyncEvent = FALSE; */
		mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_UNFINISHED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        /* oneoccured = 1; */
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetTimeResHdlrForAT
 * DESCRIPTION
 *  This function is Set time response handler (MSG_ID_MMI_EQ_SET_RTC_TIME_RSP)
 *  for AT command, update idle screen, no popup
 *  Functionality:
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetSetTimeResHdlrForAT(void *info, int src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_rtc_time_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_eq_set_rtc_time_rsp_struct*) (info);
    g_phnset_cntx_p->settime.year = g_time_buffer.nYear;
    g_phnset_cntx_p->settime.month = g_time_buffer.nMonth;
    g_phnset_cntx_p->settime.date = g_time_buffer.nDay;
    g_phnset_cntx_p->settime.hour = g_time_buffer.nHour;
    g_phnset_cntx_p->settime.minutes = g_time_buffer.nMin;

    if (resp->result == 1)
    {
    #ifdef __MTK_TARGET__
        gclockData.rtc_hour = g_phnset_cntx_p->settime.hour;
        gclockData.rtc_min = g_phnset_cntx_p->settime.minutes;
        gclockData.rtc_mon = g_phnset_cntx_p->settime.month;
        gclockData.rtc_day = g_phnset_cntx_p->settime.date;
        gclockData.rtc_year = g_phnset_cntx_p->settime.year - YEARFORMATE;
    #else /* __MTK_TARGET__ */ 
        MyTime.nHour = g_phnset_cntx_p->settime.hour;
        MyTime.nMin = g_phnset_cntx_p->settime.minutes;
        MyTime.nMonth = g_phnset_cntx_p->settime.month;
        MyTime.nDay = g_phnset_cntx_p->settime.date;
        MyTime.nYear = g_phnset_cntx_p->settime.year;
        DateTimerProc();
    #endif /* __MTK_TARGET__ */ 

        update_mainlcd_dt_display();
        update_sublcd_dt_display();
#ifndef __MMI_OP11_ALARM_SNOOZE_CONTROL__
        AlmReInitialize();
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetTimeFormat
 * DESCRIPTION
 *  This function is to get time format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetTimeFormat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;
    U8 output;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(TIME_FORMAT, &output, DS_BYTE, &error);
    /* output = output & 0x0F; */
    if ((error != NVRAM_READ_SUCCESS) || output >= NUM_TIME_FORMATS)
    {
        return 1;   /* default format */
    }
    else
    {
        return output;

    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dt_get_datefmt
 * DESCRIPTION
 *  This function is to get date format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phnset_dt_set_datefmt(U8 date_sep_fmt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 date_fmt;
	U8 sep;
	/*
	 *	 0 -> D-M-Y
	 *	 1 -> M-D-Y
	 *	 2 -> Y-M-D
	 */
	/*
	 *   0 -> .
	 *	 1 -> :
	 *	 2 -> /
	 *	 3 -> -
	 */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(date_sep_fmt)
	{
		case DATE_DD_MMM_YYYY: /* 27-08-2008 */
            date_fmt = 0;
			sep = 3;
			break;
				
		case DATE_DD_MM_YYYY_S: /* 27/08/2008 */
            date_fmt = 0;
			sep = 2;
            break;
				
        case DATE_MM_DD_YYYY_S: /* 08/27/2008 */
            date_fmt = 1;
			sep = 2;
            break;
				
        case DATE_YYYY_MM_DD_S: /* 2008/08/27 */
            date_fmt = 2;
			sep = 2;
            break;
				
        case DATE_YYYY_MM_DD_H: /* 2008-08-27 */
			date_fmt = 2;
            sep = 3;
            break;
				
        case DATE_MMM_DD_YYYY: /* 2008.08.27 */
		default:
			date_fmt = 1;
			sep = 0;
			
			break;
	}
	
	PhnsetSetDateFormat(date_fmt);
	PhnsetSetDateSeperatorFormat(sep);
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dt_get_datefmt
 * DESCRIPTION
 *  This function is to get date seperator format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phnset_dt_get_datefmt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 date_fmt;
	U8 sep_fmt;
	U8 ret;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*
	 *	 0 -> D-M-Y
	 *	 1 -> M-D-Y
	 *	 2 -> Y-M-D
	 */
	date_fmt = PhnsetGetDateFormat();
	/*
	 *   0 -> .
	 *	 1 -> :
	 *	 2 -> /
	 *	 3 -> -
	 */
	sep_fmt = PhnsetGetDateSeperatorFormat();

	switch(date_fmt + sep_fmt)
	{
	    case 1:
            ret = DATE_MMM_DD_YYYY;
            break;
            
		case 2:
			ret = DATE_DD_MM_YYYY_S;
			break;
			
		case 3:
		{
			if (date_fmt == 1)
			{
				ret = DATE_MM_DD_YYYY_S;	
			}
			else 
			{
				ret = DATE_DD_MMM_YYYY;
			}
		}
		break;
			
		case 4:	
			ret = DATE_YYYY_MM_DD_S;
		    break;
            
        case 5:
        default:
            ret = DATE_YYYY_MM_DD_H;
		break;
				
	}

	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetDateFormat
 * DESCRIPTION
 *  This function is to get date format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetDateFormat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;
    U8 output;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(DATE_FORMAT, &output, DS_BYTE, &error);
    /* output = output >> 4; */
    if ((error != NVRAM_READ_SUCCESS || output >= NUM_DATE_FORMATS))
    {
        return 0;   /* default format */
    }
    else
    {
        return output;  /* first four bits */
    }

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetDateSeperatorFormat
 * DESCRIPTION
 *  This function is to get date format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 PhnsetGetDateSeperatorFormat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 output;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DT_SEP_FORMAT, &output, DS_BYTE, &error);
    /* output = output >> 4; */
    if ((error != NVRAM_READ_SUCCESS || output >= NUM_DATE_SEPERATOR))
    {
        return 0;   /* default format */
    }
    else
    {
        return output;  /* first four bits */
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetTimeFormat
 * DESCRIPTION
 *  This function is to set time format
 *  Functionality:
 * PARAMETERS
 *  timeformat      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 PhnsetSetTimeFormat(U8 timeformat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = NVRAM_WRITE_SUCCESS;
    U8 input = timeformat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (timeformat != PhnsetGetTimeFormat())
    {
        WriteValue(TIME_FORMAT, &input, DS_BYTE, &error);
        gCurrentOnOff = input;
        /* chgcnt ++; */
    }
    wgui_status_icon_bar_change_timer_format_callback();
    return error;

}


/*****************************************************************************
 * FUNCTION
 *  PhnsetSetDateFormat
 * DESCRIPTION
 *  This function is to set date format
 *  Functionality:
 * PARAMETERS
 *  dateformat      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 PhnsetSetDateFormat(U8 dateformat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = NVRAM_WRITE_SUCCESS;
    U8 input = dateformat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dateformat != PhnsetGetDateFormat())
    {
        WriteValue(DATE_FORMAT, &input, DS_BYTE, &error);
        gCurrentOnOff = input;
        //SendMessageDateAndShowScreen();
        //chgcnt ++;
    }
    return error;

}



/*****************************************************************************
 * FUNCTION
 *  PhnsetSetDateSeperatorFormat
 * DESCRIPTION
 *  This function is to set date format
 *  Functionality:
 * PARAMETERS
 *  dateformat      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 PhnsetSetDateSeperatorFormat(U8 dateSep)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = NVRAM_WRITE_SUCCESS;
    U8 input = dateSep;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dateSep != PhnsetGetDateSeperatorFormat())
    {
        WriteValue(NVRAM_DT_SEP_FORMAT, &input, DS_BYTE, &error);
    }
	
    return error;
}


/*****************************************************************************
 * FUNCTION
 *  ATSetHomeCity
 * DESCRIPTION
 *  Set home city from AT command
 * PARAMETERS
 *  CityIndex       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL ATSetHomeCity(U8 CityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 PrevCity;
	S16 timezone;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* index exceeds boundary */
    /* remove the 0 (none case), so size of home city table shall minus by 1 */
    if (CityIndex > (NUMBER_OF_CITY - 1) || CityIndex == 0)
    {
        return MMI_FALSE;
    }

    CityIndex -= 1; /* Sync to the index of highlite */

    /* read current city index from NVRAM */
    ReadValue(CURRENT_CITY, &PrevCity, DS_BYTE, &error);

    {
        g_phnset_cntx_p->currentCity = CityIndex;

        /* retrieve string pointer of city name */
        /* The index of menu is bigger than that one of TimeZoneData */
        g_phnset_cntx_p->CurHomeCityStrPtr =
            (PU8) ((GetString) ((U16) (TimeZoneData[g_phnset_cntx_p->currentCity + 1].CityName)));

        /* write city index to NVRAM */
        WriteValue(CURRENT_CITY, &(g_phnset_cntx_p->currentCity), DS_BYTE, &error);

        /* write NITZ setting to NVRAM */
        timezone = (S16) (GetTimeZone(PhnsetGetHomeCity()) * 4);

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
        mmi_dt_tz_update_datetime(timezone);
#endif

		WriteValue(NVRAM_TIMEZONE, &timezone, DS_SHORT, &error);

        /* Update Task List when Timezone is changed */
#ifdef __MMI_TDL_NITZ_SUPPORT__
        mmi_clndr_read_nvram();
        mmi_tdl_read_nvram();
#endif
    }

    return MMI_TRUE;
}

#ifdef __MMI_NITZ__
/*****************************************************************************
 * FUNCTION
 *  PhnsetGetNITZFuncStatus
 * DESCRIPTION
 *  This function is to get NITZ function on/off status
 *  Functionality: Only exist when __MMI_NITZ__
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL PhnsetGetNITZFuncStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_AUTOUPDATE_DT_TIME, &data, DS_BYTE, &error);

    if (data == 1)
    {
        return MMI_TRUE;
    }
    else if (data == 0xff)
    {
        data = RstGetNITZStatusDefault();
        WriteValue(NVRAM_SETTING_AUTOUPDATE_DT_TIME, &data, DS_BYTE, &error);
        return MMI_FALSE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif  /* #ifdef __MMI_NITZ__ */


#ifdef __MMI_WC_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_entry_from_phnset
 * DESCRIPTION
 *  This function is Left softkey handler for Phonesetup-> Auto Update Date and Time
 *  Functionality: Toggle status only
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_wc_entry_from_phnset(void)
{
    /* Modified for apply Menu CUI */
    //if (IsScreenPresent(SCR9041_TIMEANDDATE))
    {
    	if (g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_HOMECT)
		{
			return 1;
		}
#ifdef __MMI_DUAL_CLOCK__
		else if (g_phnset_cntx_p->curHightlightItem == PHNSET_DT_MNU_FOREIGN_CITY)
		{
			return 2;
		}
#endif /* __MMI_DUAL_CLOCK__ */
    }
#ifdef __MMI_VUI_HOMESCREEN_DUALCLOCK__
    else
    {
    	if (g_phnset_cntx_p->city_flag == PHNSET_HOME_CITY)
		{
			return 1;
		}
#ifdef __MMI_DUAL_CLOCK__
		else if (g_phnset_cntx_p->city_flag == PHNSET_FOREIGN_CITY)
		{
			return 2;
		}
#endif /* __MMI_DUAL_CLOCK__ */
    }
#endif 
    
	return 0;
}
#endif /* __MMI_WC_TZ_SUPPORT__ */


#if !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dt_get_gmt_tz_string
 * DESCRIPTION
 *  This function is construct hint of "Set time zone" menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_get_gmt_tz_string(U8 *result, FLOAT timezone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmpBuff[12]; /* "GMT +XX.XX" */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(result);

    memset(tmpBuff, 0x00, 12);

    if (timezone < 0)
    {
        timezone = 0 - timezone;
        sprintf(tmpBuff, "GMT -%3.2f", timezone);
    }
    else
    {
        sprintf(tmpBuff, "GMT +%3.2f", timezone);
    }
    
    mmi_asc_n_to_ucs2((S8*)result, (S8*)tmpBuff, 12);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_gmt_tz_list
 * DESCRIPTION
 *  This function is construct GMT and time zone list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dt_gmt_tz_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gmt_tz_buf[30];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_CITYS + 1; i++)
    {
        if (TimeZoneData[gmt_tz_table[i + 1]].CityName == STR_WCLOCK_CITY_NONE)
            break;
        
        memset(gmt_tz_buf, 0x00, 30);

        mmi_dt_get_gmt_tz_string((U8*)gmt_tz_buf, TimeZoneData[gmt_tz_table[i + 1]].CityTimeZone);
        mmi_ucs2cpy((S8*)gmt_tz_str_buf[i], (S8*)gmt_tz_buf);
        mmi_ucs2cat((S8*)gmt_tz_str_buf[i], (S8*)L" ");
        mmi_ucs2cat((S8*)gmt_tz_str_buf[i], (S8*)GetString((U16)(TimeZoneData[gmt_tz_table[i + 1]].CityName)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_init_gmt_tz_table
 * DESCRIPTION
 *  This function is sort GMT and time zone table with GMT & city name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_init_gmt_tz_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, k;
    static GMT_TZ_STRUCT gmt_tz_map[MAX_CITY_NUM];
    GMT_TZ_STRUCT tmp_gmt_tz;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gmt_tz_map, 0x00, sizeof(GMT_TZ_STRUCT) * MAX_CITY_NUM);

    /* construct all simple city time zone info */
    for (i = 0; i < NUM_CITYS; i++)
    {
        gmt_tz_map[i].CityTimeZone = TimeZoneData[i + 1].CityTimeZone;
        gmt_tz_map[i].CityName = TimeZoneData[i + 1].CityName;
        gmt_tz_map[i].tzdata_index = i + 1;
    }

    for (i = 0; i < NUM_CITYS + 1; i++)
    {
        memcpy(&tmp_gmt_tz, &gmt_tz_map[i + 1], sizeof(GMT_TZ_STRUCT));    /* current compare unit */

        for (j = 0; j < i + 1; j++)
        {
            S16 sub_rst;

            sub_rst = (S16)((tmp_gmt_tz.CityTimeZone - gmt_tz_map[j].CityTimeZone) * 4);

            if (sub_rst > 0)    /* current time zone > j point time zone */
            {
                continue;
            }
            else if (sub_rst < 0)   /* current time zone < j point time zone */
            {
                /* move gmt_tz_map items */    
                for (k = i + 1; k > j; k--)
                {
                    memcpy(&gmt_tz_map[k], &gmt_tz_map[k - 1], sizeof(GMT_TZ_STRUCT)); 
                }
                
                memcpy(&gmt_tz_map[j], &tmp_gmt_tz, sizeof(GMT_TZ_STRUCT));
                break;
            }
            else
            {
                if (tmp_gmt_tz.CityName > gmt_tz_map[j].CityName)   /* same time zone but current city name big */
                {
                    continue;
                }
                else if (tmp_gmt_tz.CityName < gmt_tz_map[j].CityName)
                {
                    /* move gmt_tz_map items */    
                    for (k = i + 1; k > j; k--)
                    {
                        memcpy(&gmt_tz_map[k], &gmt_tz_map[k - 1], sizeof(GMT_TZ_STRUCT)); 
                    }
   
                    memcpy(&gmt_tz_map[j], &tmp_gmt_tz, sizeof(GMT_TZ_STRUCT));
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    
    i = 0;
    gmt_tz_table[0] = 0;

    for (j = 0; j < NUM_CITYS + 2; j++)
    {
        if (gmt_tz_map[j].tzdata_index != 0)
        {
            gmt_tz_table[i + 1] = gmt_tz_map[j].tzdata_index;
        }
        else
        {
            continue;
        }

        i++;
    }

    mmi_dt_gmt_tz_list();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dt_gmt_tz_get_hilite
 * DESCRIPTION
 *  This function is get high light index of city list with index of TimeZoneData
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 high light index
 *****************************************************************************/
static S32 mmi_dt_gmt_tz_get_hilite(U8 cityindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < NUM_CITYS + 1; i++)
    {
        if (gmt_tz_table[i] == (cityindex + 1))
            break;
    }

    return (S32)(i - 1);
}
#endif /* !defined(__MMI_HIDE_HOMECITY__) && defined(__MMI_TWO_LAYER_HOMECITY__) */

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
/*****************************************************************************
 * FUNCTION
 *  PhnsetGetDateTimeUpdateStatus
 * DESCRIPTION
 *  return current date time update status
 * PARAMETERS
 *  void
 * RETURNS
 *  current date time update  status
 *****************************************************************************/
MMI_BOOL PhnsetGetDateTimeUpdateStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->curDTUpdateStatus)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetDateTimeUpdateHiliteHandler
 * DESCRIPTION
 *  return current date and time update status high light
 * PARAMETERS
 *  void
 * RETURNS
 *  current home screen status
 *****************************************************************************/
static void PhnsetDateTimeUpdateHiliteHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->curHightlightItem = index;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetDateTimeUpdateLSKHandler
 * DESCRIPTION
 *  This function is Left soft key handler
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
void PhnsetDateTimeUpdateLSKHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phnset_cntx_p->curDTUpdateStatus != g_phnset_cntx_p->curHightlightItem)
    {
        g_phnset_cntx_p->curDTUpdateStatus = g_phnset_cntx_p->curHightlightItem;
        
        WriteValue(NVRAM_AUTOUPDATE_DT_STATUS, &(g_phnset_cntx_p->curDTUpdateStatus), DS_BYTE, &error);
    }

	mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    
    mmi_frm_group_close(GRP_ID_PHNSET_CHANGE_DATE_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnsetDateTimeUpdate
 * DESCRIPTION
 *  This function is Left soft key handler
 *  for Phone setup->Date and Time-> Date Time Update
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryPhnsetDateTimeUpdate(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_appcreate_menucui_create(
        parent_gid,
        GRP_ID_PHNSET_CHANGE_DATE_TIME,
        MENU_ID_TZ_CHANGE_DATETIME,
        mmi_phnset_change_date_time_proc);
}


/*****************************************************************************
 * FUNCTION
 *  HintPhnsetDateTimeUpdateStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HintPhnsetDateTimeUpdateStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 hint_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhnsetGetDateTimeUpdateStatus())
    {
        g_phnset_cntx_p->curDTUpdateStatus = 1; 
        hint_str = (PS8) GetString(STR_GLOBAL_ON);
    }
    else
    {
        g_phnset_cntx_p->curDTUpdateStatus = 0; 
        hint_str = (PS8) GetString(STR_GLOBAL_OFF);
    }
    cui_menu_set_item_hint(
        mmi_frm_group_get_active_id(),
        MENU_ID_TZ_CHANGE_DATETIME,
        (WCHAR*)hint_str);
}

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

/*****************************************************************************
 * FUNCTION
 *  mmi_dt_tz_update_datetime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void%
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dt_tz_update_datetime(S16 newTimeZone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 increase_flag = 0;
    S16 oldTimeZone;
    S16 error;
    applib_time_struct rtc_time;
    applib_time_struct tz_diff_mytime;
    applib_time_struct currTime;
    FLOAT tz_dif;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PhnsetGetDateTimeUpdateStatus() == MMI_FALSE)
        return;

    /* NITZ message accept to update time zone ignore */
#ifdef __MMI_NITZ_TZ_SUPPORT__
//     if (g_nitz_cntx.IsNITZPending == MMI_TRUE)
//        return; 
#endif /* __MMI_NITZ_TZ_SUPPORT__ */

    ReadValue(NVRAM_TIMEZONE, &oldTimeZone, DS_SHORT, &error);

    if (newTimeZone > oldTimeZone)
    {
        increase_flag = 1;
        tz_dif = (FLOAT)(newTimeZone - oldTimeZone) / 4;
    }
    else if (newTimeZone < oldTimeZone)
    {
        increase_flag = 0;
        tz_dif = (FLOAT)(oldTimeZone - newTimeZone) / 4;
    }
    else
    {
        return;
    }
    
    applib_dt_get_rtc_time(&rtc_time);

    tz_diff_mytime = applib_conv_tz_to_mytime(tz_dif);

    if (increase_flag)
    {
        applib_dt_increase_time(&rtc_time, &tz_diff_mytime, &currTime);
    }
    else
    {
        applib_dt_decrease_time(&rtc_time, &tz_diff_mytime, &currTime);
    }

    if (applib_dt_is_valid(&currTime))
    {
        mmi_dt_set_rtc_dt((MYTIME*)&currTime);
    }
    else
    {
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_change_date_time_proc
 * DESCRIPTION
 *  Menu CUI proc function formmi_phnset_change_date_time 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_change_date_time_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_phnset_init_change_date_time_list();
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        g_phnset_cntx_p->curHightlightItem = (S32)((cui_menu_event_struct*)param)->highlighted_menu_id;
        PhnsetDateTimeUpdateLSKHandler();
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(mmi_frm_group_get_active_id());
        break;
        
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
    	}
        break;
    default:
		break;
    }
    return MMI_RET_OK;
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_change_date_time_list
 * DESCRIPTION
 *  Initialize change date time menu list 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_init_change_date_time_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phnset_radio_button_menu_data_struct radio_button_menu;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    subMenuDataPtrs[0] = (PU8) GetString(STR_GLOBAL_OFF);
    subMenuDataPtrs[1] = (PU8) GetString(STR_GLOBAL_ON);

    radio_button_menu.group_id = GRP_ID_PHNSET_CHANGE_DATE_TIME;
    radio_button_menu.menu_title_str_id = STR_ID_TZ_CHANGE_DATETIME_TITLE;
    radio_button_menu.menu_icon_id = MAIN_MENU_TITLE_SETTINGS_ICON;
    radio_button_menu.menu_item_num = 2;
    radio_button_menu.menu_item_str_list = subMenuDataPtrs;
    radio_button_menu.menu_item_str_id_list = NULL;
    radio_button_menu.highlighted_item_idx = g_phnset_cntx_p->curDTUpdateStatus;

    mmi_phnset_init_radio_button_menu(&radio_button_menu); 
}

#endif /* __MMI_TIMEZONE_CHANGE_DATETIME__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_time_and_date_sub_menu_handler
 * DESCRIPTION
 *  Proc function for time and date group 
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phnset_time_and_date_sub_menu_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch (param->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        return mmi_phnset_time_and_date_sub_menu_entry_handler(param, parent_gid);

    case EVT_ID_CUI_MENU_ITEM_HILITE:
        return mmi_phnset_time_and_date_sub_menu_highlight_handler(param, parent_gid);

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        return mmi_phnset_time_and_date_sub_menu_select_handler(param, parent_gid);

    default:
        break;
    }

    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_init_time_and_date
 * DESCRIPTION
 *  Init menu for time and date setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phnset_init_time_and_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID time_and_date_menu_gid = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hide menu item */
#ifdef __MMI_OP11_HOMESCREEN__
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
#endif /*__MMI_OP11_HOMESCREEN__*/

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__
    HintPhnsetDateTimeUpdateStatus();
#endif
#ifndef __MMI_HIDE_HOMECITY__
    HintPhnsetTimeAndDate();
#endif
    cui_menu_set_currlist_title(time_and_date_menu_gid, (WCHAR*) GetString(STR_MENU9141_TIME_AND_DATE), (UI_image_type)GetImage(MAIN_MENU_TITLE_SETTINGS_ICON));
    
    cui_menu_set_currlist_flags(time_and_date_menu_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    cui_menu_set_currlist_left_softkey(time_and_date_menu_gid, (WCHAR*)GetString(STR_GLOBAL_OK));
    cui_menu_set_currlist_right_softkey(time_and_date_menu_gid, (WCHAR*)GetString(STR_GLOBAL_BACK));  
    /*
    highlight_menu_id = cui_menu_get_currlist_menu_id_from_index(time_and_date_menu_gid, g_phnset_cntx_p->curHightlightItem);
    cui_menu_set_currlist_highlighted_id(time_and_date_menu_gid, highlight_menu_id);
    */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_time_and_date_sub_menu_select_handler
 * DESCRIPTION
 *  Select proc function for time and date
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_time_and_date_sub_menu_select_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->highlighted_menu_id)
    {
    case MENU9142_SETHOMECITY:
#ifdef __MMI_DUAL_CLOCK__
    	g_phnset_cntx_p->city_flag = PHNSET_HOME_CITY; /* home city */
#endif
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_HOMECT;
#ifndef __MMI_WC_TZ_SUPPORT__
    	mmi_phnset_entry_set_home_city(parent_gid);
#else
        mmi_phnset_entry_wc_select_city(parent_gid);
#endif
        return MMI_RET_OK;

#ifdef __MMI_DUAL_CLOCK__
    case MENU9142_SETFOREIGNCITY:
    	g_phnset_cntx_p->city_flag = PHNSET_FOREIGN_CITY; /* foreign city */
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_FOREIGN_CITY;
#ifndef __MMI_WC_TZ_SUPPORT__

    	mmi_phnset_entry_set_home_city(parent_gid);
#else
        mmi_phnset_entry_wc_select_city(parent_gid);
#endif
        return MMI_RET_OK;
#endif

#if defined(__MMI_TIMEZONE_CHANGE_DATETIME__)
    case MENU_ID_TZ_CHANGE_DATETIME:
        EntryPhnsetDateTimeUpdate(parent_gid);
        return MMI_RET_OK;
#endif

#ifndef __MMI_SEPARATE_DT_SETTING__
    case MENU9143_SETTIMEANDDATE:
        mmi_phnset_entry_set_date_and_time(parent_gid);
        return MMI_RET_OK;
        
    case MENU9144_SETTIMEANDDATEFORMAT:
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_FMT;
        EntryPhnsetSetFormat(parent_gid);
        return MMI_RET_OK;
#else 
    case MENU_ID_SETTING_DATEANDFORMAT:
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_DATEANDFORMAT;
        mmi_phnset_entry_separate_dt_format_setting(parent_gid);
        return MMI_RET_OK;
        
    case MENU_ID_SETTING_TIMEANDFORMAT:
        g_phnset_cntx_p->curHightlightItem = PHNSET_DT_MNU_TIMEANDFORMAT;
        mmi_phnset_entry_separate_dt_format_setting(parent_gid);
        return MMI_RET_OK;
#endif 
        
    default:
        break;
    }
    return MMI_RET_DONT_CARE;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_time_and_date_sub_menu_entry_handler
 * DESCRIPTION
 *  Entry proc function for time and date
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_time_and_date_sub_menu_entry_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->parent_menu_id)
    {
    case MENU9141_TIME_AND_DATE: 
        mmi_phnset_init_time_and_date();
        return MMI_RET_OK;
        break;
        
    default:
        break;
    }
    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_time_and_date_sub_menu_highlight_handler
 * DESCRIPTION
 *  Highlight proc function for time and date
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_time_and_date_sub_menu_highlight_handler(cui_menu_event_struct *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lsk_str_id;
    MMI_ID time_and_date_menu_gid = mmi_frm_group_get_active_id();
    U8 lsk_status; /* 0 -- ON, 1 -- OFF */    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->highlighted_menu_id)
    {
    default:
        return MMI_RET_DONT_CARE;
    }
    lsk_str_id = lsk_status == 0 ? STR_GLOBAL_ON : STR_GLOBAL_OFF;
    cui_menu_change_left_softkey_string(time_and_date_menu_gid, (WCHAR*)GetString(lsk_str_id));    
    return MMI_RET_OK;  
}
#endif /* _DATEANDTIME_C */ 

