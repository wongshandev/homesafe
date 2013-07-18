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
 * nvram_user_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for customers to config/customize their parameters to NVRAM Layer and
 *    Driver Layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MAUI_BASIC__
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_release.h"

#include "nvram_defs.h"

#include "nvram_user_defs.h"
#include "nvram_editor_data_item.h"
#include "nvram_default_audio.h"
#include "custom_hw_default.h"
#include "custom_mmi_default_value.h"
#include "custom_nvram_editor_data_item.h"
#include "camera_para.h"

#if defined (OBIGO_Q05A) || defined (__MMI_WAP_PROF__)
#include "custom_wap_config.h"
#endif /* defined (OBIGO_Q05A) || defined (__MMI_WAP_PROF__) */

#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
#include "nvram_default_value.h"
#endif

/* DO NOT MODIFY THIS */
ltable_entry_struct* logical_data_item_table[NVRAM_EF_LAST_LID_CUST];

/* The pattern that defiines a LOCKED status. Choose one.*/
/* kal_uint8* CODED_LOCK_PATTERN = (kal_uint8*)NVRAM_LOCK_PATTERN_LOCKED; */
kal_uint8* CODED_LOCK_PATTERN = (kal_uint8*)NVRAM_LOCK_PATTERN_UNLOCKED;

kal_uint32 const NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT[] = {

                  200, 20,  /* PWM 1  Level 1 */
                  200, 40,  /* PWM 1  Level 2*/
                  200, 60,  /* PWM 1  Level 3*/
                  200, 80,  /* PWM 1  Level 4*/
                  200, 100, /* PWM 1 Level 5 */
                  200, 20,  /* PWM 2  Level 1 */
                  200, 40,  /* PWM 2  Level 2*/
                  200, 60,  /* PWM 2  Level 3*/
                  200, 80,  /* PWM 2  Level 4*/
                  200, 100, /* PWM 2 Level 5 */
                  200, 20,  /* PWM 3  Level 1 */
                  200, 40,  /* PWM 3  Level 2*/
                  200, 60,  /* PWM 3  Level 3*/
                  200, 80,  /* PWM 3  Level 4*/
                  200, 100, /* PWM 3 Level 5 */

#if (defined MTKLCM)
		  34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
		  44, 45, 46, 47, 48,
#elif (defined MTKLCM_COLOR)
                  /* Main LCD contrast level 1 ~ 15 */
                  148, 149, 150, 151, 152, 153, 154, 155, 156, 158, 
                  160, 162, 164, 166, 168,    
#else
                   /* Main LCD contrast level 1 ~ 15 */
                  120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 
                  140, 142, 144, 146, 148,    
#endif

                   /* Main LCD Bias Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Main LCD Linerate Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Main LCD Temperature Param (Reserved) */
                  0, 0, 0, 0, 0,    

                   /* Sub LCD contrast level 1 ~ 15 */
                  20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 
                  40, 42, 44, 46, 48,    
                   /* Sub LCD Bias Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Sub LCD Linerate Param (Reserved) */
                  0, 0, 0, 0, 0,    
                   /* Sub LCD Temperature Param (Reserved) */
                  0, 0, 0, 0, 0,    

                  /* Battery voltage Level */
                  3350000, /* Low Battery Power off */
                  3400000, /* Low Battery */
                  /* battery level 1 ~ 8 */
                  3550000, 3640000, 3740000, 3870000, 
                  9999999, 9999999, 9999999, 9999999,
                  200, 20,  /* PMIC6318 PWM Level 1 */
                  200, 40,  /* PMIC6318 PWM Level 2*/
                  200, 60,  /* PMIC6318 PWM Level 3*/
                  200, 80,  /* PMIC6318 PWM Level 4*/
                  200, 100 /* PMIC6318 PWM Level 5 */                  
};

ltable_entry_struct logical_data_item_table_cust[] = 
{
    {
        NVRAM_EF_PHONY_LID,
        NVRAM_PHONY_SIZE,
        NVRAM_PHONY_TOTAL,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "CT00",
        VER(NVRAM_EF_PHONY_LID),
        "Phony lid for example",
        NVRAM_APP_RESERVED
    }
#if defined(__WS_HOME_SAFE__)
		 ,{ 
		 NVRAM_HF_DATA_LID,
		 NVRAM_EF_HF_DATA_SIZE,
		 NVRAM_EF_HF_DATA_TOTAL,
		 NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		 NVRAM_ATTR_AVERAGE,
		 NVRAM_CATEGORY_USER,
		 "CT02",								
		 VER(NVRAM_HF_DATA_LID), 		
		 "HF NVRAM DATA\0",					
		 NVRAM_APP_RESERVED
		}
	
#endif
    /* Watch out! There is no comma after last element! */
    ,{ NVRAM_EF_LAST_LID_CUST }
};

#endif /*!__MAUI_BASIC__*/


