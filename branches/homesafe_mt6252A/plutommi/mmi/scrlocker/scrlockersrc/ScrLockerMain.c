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
 *  ScrLockerMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the main component of the screen locker.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include <limits.h>
#include "MMI_features.h"
#include "ScrLockerProt.h"
#include "IdleGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "ScrSaverGprot.h"
#include "GpioSrvGprot.h"
#include "SmsSrvGprot.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "ScrLockerObject.h"
#include "ScrLockerMain.h"
#include "MMI_common_app_trc.h"
#include "mmi_frm_input_gprot.h"
#include "kal_non_specific_general_types.h"
#include "GlobalConstants.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "ScrLockerGprot.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "GlobalResDef.h"
#include "ScrLockerAdapter.h"
#include "ScrLockerFactory.h"
// auto add by kw_check end 


/****************************************************************************
 * Global Context
 ****************************************************************************/

/* This structure defines the context of the screen locker. */
typedef struct
{
    U8                      suspend_count;
    U8                      pen_block_count;
    U8                      flag;
    U16                     manual_lock_key_code;
    mmi_slk_obj_struct     *obj;
} mmi_slk_cntx_struct;

/* Global context of screen locker. */
static mmi_slk_cntx_struct g_mmi_slk_cntx;


/****************************************************************************
 * Define
 ****************************************************************************/

/* Manual handset lock timeout value in msec. */
#define MMI_SLK_MANUAL_LOCK_TIMEOUT             (2000)

/* Option flag. */
#define MMI_SLK_FLAG_SELF_SUSPEND               (1 << 0)
#define MMI_SLK_FLAG_BACKLIGHT_FIRST_ON         (1 << 1)

/* Set / Clear / Has flag. */
#define MMI_SLK_SET(_f) (g_mmi_slk_cntx.flag |= _f)
#define MMI_SLK_CLR(_f) (g_mmi_slk_cntx.flag &= ~_f)
#define MMI_SLK_HAS(_f) (((g_mmi_slk_cntx.flag & _f) == _f))

#if defined(__MSGCMD_SUPPORT__)
#define __MSGCMD_DISABLE_SCRLOCK__
#endif


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_pen_block
 * DESCRIPTION
 *  This function blocks the pen. This function can only be used by screen
 *  locker module.
 *
 *  TODO: Pen block and unblock API should support a counter by framework.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_pen_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.pen_block_count >= UCHAR_MAX)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_BLOCK, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_PEN_BLOCK, 200));

    if (g_mmi_slk_cntx.pen_block_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_BLOCK, 202));

    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_pen_block();
    #endif
    }

    ++g_mmi_slk_cntx.pen_block_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_pen_unblock
 * DESCRIPTION
 *  This function unblocks the pen. This function can only be used by screen
 *  locker module.
 *
 *  TODO: Pen block and unblock API should support a counter by framework.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_pen_unblock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.pen_block_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_UNBLOCK, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_PEN_UNBLOCK, 200));

    --g_mmi_slk_cntx.pen_block_count;

    if (g_mmi_slk_cntx.pen_block_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_PEN_UNBLOCK, 202));

    #if defined(__MMI_TOUCH_SCREEN__)
        mmi_pen_unblock();
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_is_locked_internal
 * DESCRIPTION
 *  This function checks if the handset is locked. This API ignores the
 *  suspended state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_slk_is_locked_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = (g_mmi_slk_cntx.obj ? MMI_TRUE : MMI_FALSE);

    MMI_SLK_LOG((TRC_MMI_SLK_IS_LOCKED_INTERNAL, 200, ret));

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_is_available
 * DESCRIPTION
 *  This function checks if the manula handset lock is available.
 * PARAMETERS
 *  key                : [IN]      Key code that triggers the manual lock
 * RETURNS
 *  On available, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_slk_manual_lock_is_available(U16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = (mmi_frm_get_key_handler(key, KEY_EVENT_UP) ? MMI_FALSE : MMI_TRUE);

    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_IS_AVAILABLE, 200, ret));

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_is_processing
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_slk_manual_lock_is_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.manual_lock_key_code != KEY_INVALID)
    {
        ret = MMI_TRUE;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_IS_PRCESSING, 200, ret));

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_stop
 * DESCRIPTION
 *  This function stops the manual lock process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_manual_lock_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_STOP, 200));

    g_mmi_slk_cntx.manual_lock_key_code = KEY_INVALID;
    StopTimer(KEYPAD_LOCK_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_manual_lock_hdlr
 * DESCRIPTION
 *  This function locks the handset.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_manual_lock_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_scr_locker_is_locked() == MMI_TRUE ||
        mmi_slk_manual_lock_is_processing() == MMI_FALSE)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_HDLR, 500));
        return; /* fail-safe */
    }

    MMI_SLK_LOG((TRC_MMI_SLK_MANUAL_LOCK_HDLR, 200));

    mmi_slk_manual_lock_stop();

    mmi_idle_display();
    mmi_scr_locker_launch();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_auto_lock_get_time
 * DESCRIPTION
 *  This function gets the auto. lock time in msec.
 * PARAMETERS
 *  void
 * RETURNS
 *  Time in msec.
 *****************************************************************************/
static U32 mmi_slk_auto_lock_get_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time_msec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_msec = (U32)mmi_slk_set_get_timeout_value_in_msec();

    MMI_SLK_LOG((TRC_MMI_SLK_AUTO_LOCK_GET_TIME, 200, time_msec));

    return time_msec;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_auto_lock_timeout_hdlr
 * DESCRIPTION
 *  This function is the timerout handler for auto. handset lock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_auto_lock_timeout_hdlr(void)
{
#if defined(__MSGCMD_DISABLE_SCRLOCK__)
    return;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_scr_locker_is_locked())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_AUTO_LOCK_TIMEOUT_HDLR, 500));
        return; /* fail-safe */
    }

    MMI_SLK_LOG((TRC_MMI_SLK_AUTO_LOCK_TIMEOUT_HDLR, 200));

    mmi_scr_locker_launch();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_emit_locked
 * DESCRIPTION
 *  This function posts the locked event.
 * PARAMETERS
 *  obj         : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_emit_locked(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scr_locker_locked_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_EMIT_LOCKED, 200));

    MMI_ASSERT(obj);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCR_LOCKER_LOCKED);
    evt.type = obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_emit_unlocked
 * DESCRIPTION
 *  This function posts the unlocked event.
 * PARAMETERS
 *  obj         : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_emit_unlocked(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scr_locker_unlocked_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_EMIT_UNLOCKED, 200));

    MMI_ASSERT(obj);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SCR_LOCKER_UNLOCKED);
    evt.type = obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_bootup_early_init
 * DESCRIPTION
 *  This function initializes the context of the screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_bootup_early_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_mmi_slk_cntx, 0, sizeof(mmi_slk_cntx_struct));

    g_mmi_slk_cntx.manual_lock_key_code = KEY_INVALID;

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_shutdown_deinit
 * DESCRIPTION
 *  This function stops the screen locker when the handset shutdowns.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_shutdown_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_SHUTDOWN_DEINIT, 200));

    mmi_scr_locker_stop_timer();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_idle_launched
 * DESCRIPTION
 *  This function handles the Idle launched event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_idle_launched(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: create a virtual function for this event. */
#if defined(__DM_LAWMO_SUPPORT__)
    if ((ret = mmi_slk_lawmo_handle_idle_launched()) != MMI_RET_OK)
    {
        return ret;
    }
    else
#endif /* defined(__DM_LAWMO_SUPPORT__) */
    {
        return ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_idle_before_group_exit
 * DESCRIPTION
 *  This function stops the screen locker when the handset exits idle group.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_idle_before_group_exit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_IDLE_BEFORE_GROUP_EXIT, 200));

    mmi_scr_locker_stop_timer();

    /*
     * To suspend the locker, it must be done BEFORE the idle group exits. It's
     * for the classic locker. If it is done after the idle group exits, even if
     * we unlock the softkey, the label, image, and handler will not change back
     * to the one that APP want.
     */
    if (mmi_slk_is_locked_internal())
    {
        if (!MMI_SLK_HAS(MMI_SLK_FLAG_SELF_SUSPEND))
        {
            mmi_scr_locker_suspend();
            MMI_SLK_SET(MMI_SLK_FLAG_SELF_SUSPEND);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_idle_before_group_enter
 * DESCRIPTION
 *  This function handles the group enter event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_idle_before_group_enter(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_IDLE_BEFORE_GROUP_ENTER, 200));

    mmi_scr_locker_start_timer();

    if (mmi_slk_is_locked_internal())
    {
        if (MMI_SLK_HAS(MMI_SLK_FLAG_SELF_SUSPEND))
        {
            mmi_scr_locker_resume();
            MMI_SLK_CLR(MMI_SLK_FLAG_SELF_SUSPEND);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_pre_key_routing
 * DESCRIPTION
 *  This function handles the pre-key routing.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_pre_key_routing(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;
    mmi_frm_key_evt_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    evt = (mmi_frm_key_evt_struct *)event;

    /*
     * Only allow key action when backlight is controlled by AP.
     *
     * TODO 1: Discuss with Hua Tian why this part is put on idle screen.
     * TODO 2: Discuss with GPIO that it should block key in this case.
     */
    if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE &&
        evt->key_type == KEY_EVENT_DOWN)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 300));

        mmi_scr_locker_turn_on_backlight();

        /* Block key event until the key is released. */
        MMI_SLK_SET(MMI_SLK_FLAG_BACKLIGHT_FIRST_ON);

        return MMI_RET_STOP_KEY_HANDLE;
    }

    /* Block key event until the key is released. */
    if (MMI_SLK_HAS(MMI_SLK_FLAG_BACKLIGHT_FIRST_ON))
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 301));

        if (evt->key_type == KEY_EVENT_UP)
        {
            MMI_SLK_CLR(MMI_SLK_FLAG_BACKLIGHT_FIRST_ON);
        }

        return MMI_RET_STOP_KEY_HANDLE;
    }

    /*
     * Process key event in the following situation. Close the screen saver
     * actively since the key is blocked by the screen saver in this case.
     *
     *  1) Handset is locked.
     *  2) Screen saver is running and it will suspend the screen locker.
     */
    if ((mmi_scr_locker_is_locked()) ||
        (mmi_slk_is_locked_internal() && mmi_scr_saver_is_active()))
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 200));

        if (evt->key_type == KEY_EVENT_DOWN && mmi_scr_saver_is_active())
        {
            mmi_scr_saver_close();
        }

        MMI_ASSERT(obj && obj->on_key);

        return obj->on_key(obj, evt);
    }
    else
    {
        MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_PRE_KEY_ROUTING, 201));

        if ((mmi_slk_manual_lock_is_processing()) &&
            (g_mmi_slk_cntx.manual_lock_key_code != evt->key_code))
        {
            mmi_slk_manual_lock_stop();
        }

        mmi_scr_locker_restart_timer();

        return MMI_RET_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_post_key_routing
 * DESCRIPTION
 *  This function handles the post-key routing.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_post_key_routing(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Turn on backlight if the handset is not shutdowning.
     */
    if (!srv_shutdown_is_running())
    {
        mmi_scr_locker_turn_on_backlight();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_lcd_sleep_in
 * DESCRIPTION
 *  This function handles the LCD sleep-in event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_lcd_sleep_in(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_LCD_SLEEP_IN, 200));

    mmi_slk_pen_block();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_lcd_sleep_out
 * DESCRIPTION
 *  This function handles the LCD sleep-out event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_lcd_sleep_out(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_LCD_SLEEP_OUT, 200));

    mmi_slk_pen_unblock();

    return MMI_RET_OK;
}


#if defined(__MMI_CLAMSHELL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_clam_open
 * DESCRIPTION
 *  This function handles the clam open event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_clam_open(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_CLAM_OPEN, 200));

    if (mmi_scr_locker_is_locked())
    {
        mmi_scr_locker_close();
    }
    else
    {
        mmi_scr_locker_restart_timer();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_gpio_clam_close
 * DESCRIPTION
 *  This function handles the clam close event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_gpio_clam_close(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_GPIO_CLAM_CLOSE, 200));

    mmi_scr_locker_restart_timer();

    return MMI_RET_OK;
}
#endif /* defined(__MMI_CLAMSHELL__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_msg_num_changed
 * DESCRIPTION
 *  This function handles the message number changed event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_msg_num_changed(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_scr_locker_is_locked())
    {
        MMI_ASSERT(obj && obj->on_msg_num_changed);
        obj->on_msg_num_changed(obj);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_slk_obj_close_req
 * DESCRIPTION
 *  This function closes the screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_slk_obj_close_req(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_SLK_OBJ_CLOSE_REQ, 200));

    mmi_scr_locker_close();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_handle_slk_obj_closed_ind
 * DESCRIPTION
 *  This function closes the screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_handle_slk_obj_closed_ind(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_HANDLE_SLK_OBJ_CLOSED_IND, 200));

    g_mmi_slk_cntx.obj = NULL;

    /* The lock could be closed when it is still suspended. Reset the
       counter. */
    g_mmi_slk_cntx.suspend_count = 0;
    MMI_SLK_CLR(MMI_SLK_FLAG_SELF_SUSPEND);

    /* When the handset is locked, the backlight will be in the half mode by
       force. Turn on backlight here to make sure the backlight is on after the
       handset is unlocked. */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* Start the screen locker timer for the next shot. */
    mmi_scr_locker_start_timer();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler of screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_slk_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = mmi_slk_handle_bootup_early_init(event);
            break;

        case EVT_ID_SRV_SHUTDOWN_DEINIT:
            ret = mmi_slk_handle_shutdown_deinit(event);
            break;

        case EVT_ID_IDLE_LAUNCHED:
            ret = mmi_slk_handle_idle_launched(event);
            break;

        case EVT_ID_IDLE_BEFORE_GROUP_EXIT:
            ret = mmi_slk_handle_idle_before_group_exit(event);
            break;

        case EVT_ID_IDLE_BEFORE_GROUP_ENTER:
            ret = mmi_slk_handle_idle_before_group_enter(event);
            break;

        case EVT_ID_PRE_KEY_EVT_ROUTING:
            ret = mmi_slk_handle_pre_key_routing(event);
            break;

        case EVT_ID_POST_KEY_EVT_ROUTING:
            ret = mmi_slk_handle_post_key_routing(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_IN:
            ret = mmi_slk_handle_gpio_lcd_sleep_in(event);
            break;

        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            ret = mmi_slk_handle_gpio_lcd_sleep_out(event);
            break;

    #if defined(__MMI_CLAMSHELL__)
        case EVT_ID_GPIO_CLAM_OPEN:
            ret = mmi_slk_handle_gpio_clam_open(event);
            break;

        case EVT_ID_GPIO_CLAM_CLOSE:
            ret = mmi_slk_handle_gpio_clam_close(event);
            break;
    #endif /* defined(__MMI_CLAMSHELL__) */

        case EVT_ID_SRV_SMS_READY:      /* Fall throught. */
        case EVT_ID_SRV_SMS_ADD_MSG:    /* Fall throught. */
        case EVT_ID_SRV_SMS_DEL_MSG:    /* Fall throught. */
        case EVT_ID_SRV_SMS_UPDATE_MSG: /* Fall throught. */
            ret = mmi_slk_handle_msg_num_changed(event);
            break;

        case EVT_ID_SLK_OBJ_CLOSE_REQ:
            ret = mmi_slk_handle_slk_obj_close_req(event);
            break;

        case EVT_ID_SLK_OBJ_CLOSED_IND:
            ret = mmi_slk_handle_slk_obj_closed_ind(event);
            break;

        /*
         * Adapter for screen locker locked / unlocked. (Obsolete)
         */
        case EVT_ID_SCR_LOCKER_LOCKED:
            ret = mmi_slk_handle_scr_locker_locked(event);
            break;

        case EVT_ID_SCR_LOCKER_UNLOCKED:
            ret = mmi_slk_handle_scr_locker_unlocked(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_start_manual_lock(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_START_MANUAL_LOCK, 200));

    if (mmi_slk_manual_lock_is_available(key_code))
    {
        g_mmi_slk_cntx.manual_lock_key_code = key_code;

        StartTimer(
            KEYPAD_LOCK_TIMER,
            MMI_SLK_MANUAL_LOCK_TIMEOUT,
            mmi_slk_manual_lock_stop);

        SetKeyHandler(mmi_slk_manual_lock_hdlr, key_code, KEY_EVENT_UP);
    }
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_start_timer(void)
{
#if defined(__MSGCMD_DISABLE_SCRLOCK__)
    return;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Check error.
     */
    if (IsMyTimerExist(IDLE_APP_AUTO_LOCK_TIMER_ID))
    {
        MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 500));
        return;
    }

    if (g_mmi_slk_cntx.suspend_count > 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 501));
        return;
    }

    if (mmi_scr_locker_is_locked())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 502));
        return;
    }

    /*
     * Start timer.
     */
    MMI_SLK_LOG((TRC_MMI_SLK_START_TIMER, 200));

    time = mmi_slk_auto_lock_get_time();
    if (time)
    {
        StartTimer(IDLE_APP_AUTO_LOCK_TIMER_ID, time, mmi_slk_auto_lock_timeout_hdlr);
    }
#endif
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_restart_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_RESTART_TIMER, 200));

    if (IsMyTimerExist(IDLE_APP_AUTO_LOCK_TIMER_ID))
    {
        StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
        mmi_scr_locker_start_timer();
    }
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_STOP_TIMER, 200));

    StopTimer(IDLE_APP_AUTO_LOCK_TIMER_ID);
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_suspend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.suspend_count >= UCHAR_MAX)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_SUSPEND, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_SUSPEND, 200));

    /*
     * Suspend at the first time. Stop the timer.
     */
    if (g_mmi_slk_cntx.suspend_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_SUSPEND, 202));

        mmi_scr_locker_stop_timer();

        /* Notify locker. Note that locker might be absent at present. */
        if (obj && obj->on_suspend)
        {
            obj->on_suspend(obj, MMI_FALSE);   /* on before suspend */
        }
    }

    ++g_mmi_slk_cntx.suspend_count;
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.suspend_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_RESUME, 400));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_RESUME, 200));

    --g_mmi_slk_cntx.suspend_count;

    /*
     * No one suspends the timer. Restart it.
     */
    if (g_mmi_slk_cntx.suspend_count == 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_RESUME, 202));

        mmi_scr_locker_start_timer();

        /* Notify locker. Note that locker might be absent at present. */
        if (obj && obj->on_resume)
        {
            obj->on_resume(obj, MMI_FALSE);    /* on after resume */
        }
    }
}


/* For the detail information, please refer to the ScrLockerGprot.h */
MMI_BOOL mmi_scr_locker_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Someone suspends the locker temporarily.
     */
    if (g_mmi_slk_cntx.suspend_count > 0)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_IS_LOCKED, 201, 0));
        return MMI_FALSE;
    }

    ret = mmi_slk_is_locked_internal();

    MMI_SLK_LOG((TRC_MMI_SLK_IS_LOCKED, 200, ret));

    return ret;
}


/* For the detail information, please refer to the ScrLockerGprot.h */
mmi_scr_locker_type_enum mmi_scr_locker_get_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_slk_cntx.obj)
    {
        return g_mmi_slk_cntx.obj->type;
    }

    return MMI_SCR_LOCKER_TYPE_INVALID;
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_launch(void)
{
#if defined(__MSGCMD_DISABLE_SCRLOCK__)
    return;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH, 200));

    mmi_scr_locker_launch_ex(MMI_SCR_LOCKER_TYPE_UNSPECIFIED);
#endif
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_launch_ex(mmi_scr_locker_type_enum type)
{
#if defined(__MSGCMD_DISABLE_SCRLOCK__)
    return;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Do not lock when it is already locked.
     */
    if (mmi_slk_is_locked_internal())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH_EX, 500, type));
        return; /* fail-safe */
    }

    /*
     * No screen locker wants to run.
     */
    obj = mmi_slk_new_obj_ex(type);
    if (!obj)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH_EX, 501, type));
        return;
    }

    /*
     * Lock the handset.
     */
    MMI_SLK_LOG((TRC_MMI_SLK_LAUNCH_EX, 200, type));

    MMI_ASSERT(obj->on_create);
    obj->on_create(obj, mmi_slk_main_evt_hdlr);

    MMI_ASSERT(obj->on_run);
    obj->on_run(obj);

    MMI_ASSERT(g_mmi_slk_cntx.obj == NULL);
    g_mmi_slk_cntx.obj = obj;

    /* APP can call this API to launch the locker directly. Always stop timer
       to avoid the complications. */
    mmi_scr_locker_stop_timer();

    /*
     * At present the screen locker will only display on the idle group. If the
     * idle group is not active, suspend it; otherwise, the lock icon will be
     * shown and the keypad tone will be stopped on other APP. (MAUI_02221788)
     */
    if (!mmi_idle_is_group_active())
    {
        mmi_scr_locker_suspend();
        MMI_SLK_SET(MMI_SLK_FLAG_SELF_SUSPEND);
    }
#endif
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj = g_mmi_slk_cntx.obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_CLOSE, 200));

    if (mmi_slk_is_locked_internal())
    {
        MMI_ASSERT(obj && obj->on_close);
        obj->on_close(obj);
    }
}


/* For the detail information, please refer to the ScrLockerGprot.h */
void mmi_scr_locker_turn_on_backlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * The backlight should keep half bright to save power if
     *
     *  1) Handset is locked.
     *  2) Screen saver is running and it will suspend the screen locker.
     *
     */
    if ((mmi_scr_locker_is_locked()) ||
        (mmi_slk_is_locked_internal() && mmi_scr_saver_is_active()))
    {
        MMI_SLK_LOG((TRC_MMI_SLK_TURN_ON_BACKLIGHT, 201));
        srv_backlight_half_mode();
    }
    else
    {
        MMI_SLK_LOG((TRC_MMI_SLK_TURN_ON_BACKLIGHT, 200));
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
}

