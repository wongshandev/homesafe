/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain definition of custom component module configuration variables, and routines
 *
 * Author:
 * -------
 *   system auto generator V1.35 -> p1.38
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "syscomp_config.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "task_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "system_inc.h"    /* include system_inc.h after including above header files */
#include "page.h"
#include "kal_non_specific_general_types.h"
#include "kal_common_defs.h"

//#define CUSTOM1_EXIST
//#define CUSTOM2_EXIST

/*************************************************************************
 * External function declaration
 *************************************************************************/
extern kal_bool custom1_create(comptask_handler_struct **handle);
extern kal_bool custom2_create(comptask_handler_struct **handle);

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
extern kal_bool vs_sys_task_001_create(comptask_handler_struct **handle);
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
extern kal_bool MsgCmd_TaskCreate(comptask_handler_struct **handle);
#endif
/*************************************************************************
* Global
*  custom_mod_task_g
*
* DESCRIPTION
*   module to task index mapping.
*   for example:
*      INDX_CUSTOM1 -> MOD_CUSTOM1
*   means module MOD_CUSTOM1 belongs to INDX_CUSTOM1 task
*
*   Please arrange the mapping according to custom_config.h custom_module_type
*   sequence.
*
* GLOBALS AFFECTED
*
*************************************************************************/
custom_task_indx_type custom_mod_task_g[ MAX_CUSTOM_MODS ] =
{
   INDX_CUSTOM1,        /* MOD_CUSTOM1 */
   INDX_CUSTOM2,        /* MOD_CUSTOM2 */
#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
   INDX_VS,
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
   INDX_MSGCMD,
#endif
   INDX_NIL             /* Please end with INDX_NIL element */
};

/*************************************************************************
* Global
*  custom_comp_config_tbl
*
* DESCRIPTION
*   The array contains system component tasks' configuration information
*
* GLOBALS AFFECTED
*
*************************************************************************/
const comptask_info_struct custom_comp_config_tbl[ MAX_CUSTOM_TASKS ] =
{
   /* INDX_CUSTOM1 */
   {"CUST1", "CUST1 Q", 210, 1024, 
#ifdef CUSTOM1_EXIST
   custom1_create, KAL_FALSE
#else   
   NULL, KAL_FALSE
#endif
    , 10, 0
   },

   /* INDX_CUSTOM2 */
   {"CUST2", "CUST2 Q", 211, 1024, 
#ifdef CUSTOM2_EXIST
   custom2_create, KAL_FALSE
#else
   NULL, KAL_FALSE
#endif
    , 10, 0
   },

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
   /* INDX_VS */
   {"VS", "VS Q", 212, 1024, 
   vs_sys_task_001_create, KAL_FALSE, 10, 0
   },
#endif
#if defined(MSG_CMD_TASK_SUPPORT)
   /*INDX_MSGCMD*/
   {"MSGCMD", "MSGCMD Q", 213, 1024, 
   MsgCmd_TaskCreate, KAL_FALSE, 10, 0
   },
#endif
};

/*************************************************************************
* FUNCTION
*  custom_configmem()
*
* DESCRIPTION
*   This routine configure 
*        
*   a. system total memory usage 
*      Task's stack, external queue, control buffer entries etc.
*      Any one who attempts to create new task or enlarge control
*      buffer size should fine tune the value!
*
*   b. system total debug memory usage 
*      Valid for DEBUG_KAL + DEBUG_[some items, ITC, BUF etc] 
*
* PARAMETERS
*        system_mem_sz       -        system all memory usage
*        debug_mem_sz        -        system all debug memory usage
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

/* SysGen Template Type : GPRS Generic */
#if defined(__OP01__) || defined(__OP11__) || defined(__OP12__)
#define __SYS_MEM_OP_PROJ__
#endif /* __OP01__ || __OP11__ || __OP12__ */

#if (defined(__WIFI_SUPPORT__) || defined(__VOIP__)) && defined(OBIGO_Q05A)

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 450*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 450*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 445*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 430*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 430*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 425*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 405*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GEMINI__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 430*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 430*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 425*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 405*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 390*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 390*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 385*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 430*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 430*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 426*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 406*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 390*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 390*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 386*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 410*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 406*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 390*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 390*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 386*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif

#elif defined(__WIFI_SUPPORT__) || defined(__VOIP__)

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 420*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 420*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 415*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 400*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 400*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 395*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 375*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GEMINI__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 400*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 400*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 395*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 375*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 365*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 400*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 400*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 396*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 376*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 120*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else /* __GEMINI__ */
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 380*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 376*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 110*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          ( 370*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #else
             #define GLOBAL_MEM_SIZE          ( 366*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  65*1024)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif /* __GEMINI__ */

#elif defined(OBIGO_Q05A)

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 397*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  794*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  775*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
	        #define GLOBAL_MEM_SIZE          ( 357*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  714*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  705*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 394*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  788*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  779*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 354*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  708*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  699*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GEMINI__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 357*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  714*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  705*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 337*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  674*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  665*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 354*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  708*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  699*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 334*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  668*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  659*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 376*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  752*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  744*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 356*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  712*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  704*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 336*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  672*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  664*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else /* __GEMINI__ */
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 356*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  95*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  712*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  704*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 286*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  60*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  572*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  564*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 316*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  95*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  632*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  624*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif /* __GEMINI__ */

#else /* (__WIFI_SUPPORT__ || __VOIP__) && OBIGO_Q05A */

    #if defined(__GEMINI__) && defined(__GADGET_SUPPORT__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 397*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  794*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  785*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 357*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  714*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  705*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 394*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  788*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  779*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 354*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  708*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  699*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GEMINI__)
       #if ( GEMINI_PLUS > 2 )
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 377*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  754*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  745*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 352*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    (  76*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  704*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  695*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 337*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 106*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  674*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  665*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #else  /* GEMINI_PLUS > 2 */
          #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 374*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  748*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  739*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 349*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    (  71*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  698*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  689*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
             #if defined(DEBUG_BUF2)
                #define GLOBAL_MEM_SIZE          ( 334*1024)
                #define GLOBAL_DEBUG_MEM_SIZE    ( 101*1024)
             #elif defined(DEBUG_BUF1)
                #define GLOBAL_MEM_SIZE          (  668*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #else
                #define GLOBAL_MEM_SIZE          (  659*512)
                #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
             #endif
          #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
       #endif  /* GEMINI_PLUS > 2 */
    #elif defined(__GADGET_SUPPORT__)
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 376*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  752*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  744*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 351*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  702*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  694*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 336*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    ( 105*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  672*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  664*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #else /* __GEMINI__ */
       #if defined(__AGPS_SUPPORT__) && defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 326*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  95*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  652*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  644*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #elif defined(__AGPS_SUPPORT__) || defined(__SYS_MEM_OP_PROJ__)
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 336*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  75*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  672*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  664*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #else  /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
          #if defined(DEBUG_BUF2)
             #define GLOBAL_MEM_SIZE          ( 296*1024)
             #define GLOBAL_DEBUG_MEM_SIZE    (  50*1024)
          #elif defined(DEBUG_BUF1)
             #define GLOBAL_MEM_SIZE          (  592*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #else
             #define GLOBAL_MEM_SIZE          (  584*512)
             #define GLOBAL_DEBUG_MEM_SIZE    (   20*512)
          #endif
       #endif /* __AGPS_SUPPORT__ && __SYS_MEM_OP_PROJ__ */
    #endif /* __GEMINI__ */

#endif /* (__WIFI_SUPPORT__ || __VOIP__) && OBIGO_Q05A */



static kal_uint32 System_Mem_Pool[GLOBAL_MEM_SIZE/sizeof(kal_uint32)];

#if defined(DEBUG_KAL)
static kal_uint32 Debug_Mem_Pool[GLOBAL_DEBUG_MEM_SIZE/sizeof(kal_uint32)];
#endif /* DEBUG_KAL */

void
custom_configmem(kal_uint32 *system_mem_sz, kal_uint32** system_mem_addr, 
                 kal_uint32 *debug_mem_sz,  kal_uint32** debug_mem_addr)
{
   *system_mem_sz   = GLOBAL_MEM_SIZE;
   *system_mem_addr = System_Mem_Pool;
   
#if defined(DEBUG_KAL)   
   *debug_mem_addr  = Debug_Mem_Pool;
   *debug_mem_sz    = GLOBAL_DEBUG_MEM_SIZE;
#else
   *debug_mem_addr  = (kal_uint32 *)0;
   *debug_mem_sz    = 0;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_libc_heap()
*
* DESCRIPTION
*   This routine configure libc heap size & location.
*
* PARAMETERS
*
* RETURNS
*  heap size & heap location. if heap_size return 0, then no heap is
*  initialized.
*
* GLOBALS AFFECTED
*
*************************************************************************/
#ifdef __GADGET_SUPPORT__
#define GLOBAL_LIBC_HEAP_SIZE 10240
#else 
#define GLOBAL_LIBC_HEAP_SIZE 0
#endif
#if GLOBAL_LIBC_HEAP_SIZE != 0
/* if we don't define heap, we won't define a symbol call System_Libc_Heap
 * using this method, we can detect whether system allow to use 
 * malloc/free/realloc/calloc
 */
kal_uint32 System_Libc_Heap[GLOBAL_LIBC_HEAP_SIZE/sizeof(kal_uint32)];
#endif
void custom_config_libc_heap(kal_uint32 *heap_size, void **heap_addr)
{
#if GLOBAL_LIBC_HEAP_SIZE == 0
    *heap_size = 0;
    *heap_addr = 0;
#else
    *heap_size = sizeof(System_Libc_Heap);
    *heap_addr = System_Libc_Heap;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_ctrl_buff_info()
*
* DESCRIPTION
*   This routine configure control buffer pool information (run time 
*   memory allocation usage)
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
custom_config_ctrl_buff_info(void)
{
   /* These constants defined in adaptation\include\ctrl_buff_pool.h */
   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE08;
   ctrl_buff_pool_info_g[0].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE08;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE16;
   ctrl_buff_pool_info_g[1].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE16;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[2].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE32;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[3].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE64;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[4].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE128;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[5].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE256;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[6].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE512;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[7].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE1024;

   ctrl_buff_pool_info_g[8].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[8].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE2048;

   ctrl_buff_pool_info_g[9].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[9].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE4096;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[10].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE8192;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[11].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE16384;

   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[12].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE32768;

   ctrl_buff_pool_info_g[13].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[13].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE65536;

   /* GPRS class : ctrl buffer slots adjustment */

        
} 

/*************************************************************************
* FUNCTION
*  custom_config_task_stack_size
*
* DESCRIPTION
*  This function dedicates to specify one task's stack size.
*  Note: Each task's stack size is originally defined in the task 
*        configuration table (in sys_comp_config_tbl[]). When allocating 
*        stack for each task, system will invoke this function. If the 
*        return value is zero, system will use the original stack-size
*        setting for the task. Otherwise, system will use the return value 
*        as the task's stack size IF AND ONLY IF the return value is larger 
*        than the original settting.
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  Task's stack size (in bytes). Zero value implies that system uses
*  the original setting to allocate stack for the task.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_task_stack_size(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return a non-zero value for the task you are interesting.
    * For example,
    *    case INDX_MMI:
    *       // configure MMI's stack size as 8KB
    *       return 8096;
    */

#if defined(OBIGO_Q05A)
   case INDX_MMI:
   // en-large the MMI stack size to 26KB
      return (26 * 1024);
#endif /* OBIGO_Q05A */

   default:
      return 0;
   }

   return 0;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_extq_size
*
* DESCRIPTION
*  This function dedicates to specify one task's external queue size.
*  Note: Each task's external queue size is originally defined in the task 
*        configuration table (in sys_comp_config_tbl[]). When allocating 
*        queue for each task, system will invoke this function. If the 
*        return value is zero, system will use the original queue-size 
*        setting for the task. Otherwise, system will use the return value 
*        as the task's external queue size IF AND ONLY IF the return value 
*        is larger than the original settting.
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  Task's external queue size (number of entries). Zero value implies that
*  system uses the original setting to allocate queue for the task.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_task_extq_size(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return a non-zero value for the task you are interesting.
    * For example,
    *    case INDX_MMI:
    *       // configure MMI's external queue size as 40
    *       return 30;
    */

   default:
      return 0;
   }

   return 0;
}

/*************************************************************************
* FUNCTION
*  custom_config_evshed_pool_size
*
* DESCRIPTION
*  This function dedicates to specify larger pool size on event scheduler.
*
* PARAMETERS
*  void   -   
*
* RETURNS
*  evshed pool size (number of entries). Smaller value than default 
*  implies that system uses the original setting to allocate pool for event.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_config_evshed_pool_size(void)
{
#ifdef __SIP__
   return 160;
#else
   return 0;
#endif
}

/*************************************************************************
* FUNCTION
*  custom_config_task_under_usb_boot
*
* DESCRIPTION
*  This function dedicates custom tasks present or not under usb boot mode
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  KAL_TRUE  : present on usb boot mode
*  KAL_FALSE : otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_config_task_under_usb_boot(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return true value for the custom task you are interesting.
    * For example,
    *    case INDX_CUSTOM1:
    *       return KAL_TRUE;
    */

   default:
      return KAL_FALSE;
   }

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_under_factory_boot
*
* DESCRIPTION
*  This function dedicates custom tasks present or not under factory boot mode
*
* PARAMETERS
*  task_indx   -   task index of task to configure
*
* RETURNS
*  KAL_TRUE  : present on factory boot mode
*  KAL_FALSE : otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool custom_config_task_under_factory_boot(task_indx_type task_indx)
{
   switch (task_indx) {

   /*
    * Return true value for the custom task you are interesting.
    * For example,
    *    case INDX_CUSTOM1:
    *       return KAL_TRUE;
    */

   default:
      return KAL_FALSE;
   }

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  custom_config_task_stack_location
*
* DESCRIPTION
*  This function will re-configure task stack location (INTSRAM/EXTSRAM)
*  Original configuration in config.lib will be overwritten.
*  XXX PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  task_info_g
*
*************************************************************************/
void custom_config_task_stack_location(void)
{
#ifdef __SYS_INTERN_RAM__
   /* DCM_ENABLE feature ON/OFF
    * IDLE task have to put in internal SRAM when DCM_ENABLE ON
    */
   #if defined(DCM_ENABLE)
      task_info_g[ INDX_IDLE ].task_internal_ram_stack = KAL_TRUE;
   #endif /* DCM_ENABLE */
#endif /* __SYS_INTERN_RAM__ */
   return;
}

/*************************************************************************
* FUNCTION
*  custom_get_task_module()
*
* DESCRIPTION
*  This routine returns the number of customer tasks and modules.
*
* PARAMETERS
*  Pointer of 8-bits unsigned integer used to return the value.
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void 
custom_get_task_module(kal_uint8 *custom_task, kal_uint8 *custom_module)
{
   *custom_task = RPS_CUSTOM_TASKS_END - RPS_CUSTOM_TASKS_BEGIN;
   *custom_module = MOD_CUSTOM_END - MOD_CUSTOM_BEGIN;
}

/*************************************************************************
* FUNCTION
*  remap_mod_task_g
*
* DESCRIPTION
*  This function will remap module to new task at initialization stage.
*  Original configuration in config.lib will be overwritten.
*  XXX PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*  mod_task_g
*
*************************************************************************/
void remap_mod_task_g(void)
{
#if defined(JATAAYU_SUPPORT) || defined(OBIGO_Q05A)
   mod_task_g[MOD_WAP] = INDX_MMI;
#endif
#ifndef OBIGO_Q03C_MMS_V02
   mod_task_g[MOD_MMS] = mod_task_g[MOD_WAP];
#endif
   return;
}

/*************************************************************************
* FUNCTION
*  customization_check
*
* DESCRIPTION
*  Checking system customization, including number of tasks, modules,
*  message ID and SAP.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
customization_check(void)
{
   /* Check if customer tasks exceeding limitation */
   if ( (RPS_CUSTOM_TASKS_END - RPS_CUSTOM_TASKS_BEGIN) > MAX_CUSTOM_TASKS )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_TASK_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(RPS_CUSTOM_TASKS_BEGIN-RPS_CUSTOM_TASKS_END)
                             );
                             
   /* Check if customer module ID exceeding limitation */
   if ( (MOD_CUSTOM_END - MOD_CUSTOM_BEGIN) > MAX_CUSTOM_TASKS )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_MOD_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(MOD_CUSTOM_END - MOD_CUSTOM_BEGIN)
                             );
                             
   /* Check if customer message ID exceeding limitation */
   if ( (MSG_ID_END - CUSTOM_MSG_CODE_BEGIN) > MAX_CUSTOM_MESSAGE_ID )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_MEESAGE_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(MSG_ID_END - CUSTOM_MSG_CODE_BEGIN)
                             );
                          
   /* Check if customer tasks exceeding limitation */
   if ( (LAST_SAP_CODE - CUSTOM_SAP_BEGIN - 1) > MAX_CUSTOM_SAP_ID )
      kal_fatal_error_handler(KAL_ERROR_CUSTOMER_SAP_ID_EXCEED_UPPER_BOUND,
                              (kal_uint32)(LAST_SAP_CODE - CUSTOM_SAP_BEGIN - 1)
                             );
}

/*************************************************************************
* FUNCTION
*  custom_config_mod_task_g()
*
* DESCRIPTION
*   This routine process custom module to global module to task mapping 
*   relation. XXX. PLEASE DON'T EDIT THE FUNCTION.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void 
custom_config_mod_task_g(void)
{
   kal_uint32 i;

   for (i = 0; i < MAX_CUSTOM_MODS; i++) {
      if ((task_indx_type)custom_mod_task_g[i] == INDX_NIL)
         break;

      mod_task_g[i + MOD_CUSTOM_BEGIN] = (task_indx_type)custom_mod_task_g[i];
   }
}

/*************************************************************************
* FUNCTION
*  custom_config_demp_page
*
* DESCRIPTION
*  This routine configures pages for demand paging.
*
* PARAMETERS
*  page        -   returned pointer to control blocks
*  pool        -   returned pointer to page pool
*  pool_size   -   returned pointer to page pool size
*
* RETURNS
*  0 fo success; -1 for failure.
*
************************************************************************/
#define DEMP_PAGE_POOL_SIZE (800 * 1024)

#if defined(__NFB_ON_DEMAND_PAGE_IN__)

/* define page pool */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "NONCACHEDZI"
static __align((2 << PAGE_CLUSTER) * 1024) kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
#pragma arm section zidata
#else
static kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
#endif /* MTK_TARGET */

/* define the control block for pages */
static demp_page_t DEMP_PAGE_LIST[DEMP_PAGE_POOL_SIZE >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1))];
#endif  /* __NFB_ON_DEMAND_PAGE_IN__ */

kal_int32
custom_config_demp_page(kal_uint32 **list, kal_uint32 **pool, kal_uint32 *pool_size)
{
#if defined(__NFB_ON_DEMAND_PAGE_IN__)

   if (list != NULL) {
      *list = (kal_uint32 *)DEMP_PAGE_LIST;
   } else {
      return -1;
   }

   if (pool != NULL) {
      *pool = (kal_uint32 *)DEMP_PAGE_POOL;
   } else {
      return -1;
   }

   if (pool_size != NULL) {
      *pool_size = DEMP_PAGE_POOL_SIZE;
   } else {
      return -1;
   }

   return 0;

#else   /* __NFB_ON_DEMAND_PAGE_IN__ */

   return -1;

#endif  /* __NFB_ON_DEMAND_PAGE_IN__ */
}

