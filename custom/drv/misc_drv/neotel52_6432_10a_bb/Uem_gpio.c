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
 *   uem_gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CUST_NEW__
#ifndef __L1_STANDALONE__

/*
**   Includes
*/
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#include "device.h"
#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "custom_em.h"
#include "pmu_sw.h"
#include "pwic.h"

#if defined(__RF_DESENSE_TEST__)
#include "rf_desense_test.h"
#endif // __RF_DESENSE_TEST__

#ifdef LQT_SUPPORT/*Please don't remove LQT code segments*/
#include "lcd_lqt.h"
extern kal_uint8 lcd_at_mode;
#endif/*LQT_SUPPORT*/
/*
**   Typedefs
*/

/*
**   Defines
*/

/*
**   Extern Functions
*/
extern void GPIO_WriteIO(char data, char port);
extern void GPIO_WriteIO_FAST(char data, char port);
extern void PWM_level(kal_uint8 level);
extern void PWM2_level(kal_uint8 level);
//extern void PWM3_level(kal_uint8 level); //MT6253 20090123
extern void PWM2_Configure(kal_uint32 freq, kal_uint8 duty);
extern void PWM2_Start(void);
extern void PWM2_Stop(void);
//extern void Alter_level(kal_uint8 level);
#if (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__))
extern void Touchpad_PowerOn(const kal_bool bOn);
#endif

/*
**   Extern Varibales
*/
extern const char gpio_led_mainbl_en_pin;
//extern const char gpio_led_keybl_en_pin;
//extern const char gpio_led_keybl2_en_pin;
//extern const char gpio_vibrator_en_pin;
/*
**   Globol Varibales
*/

/*
**   Local Functions
*/

/*
**   Local Variables
*/
/***********************************************************
  **
  **  GPIO SETTTING
  **
  ***********************************************************/



#if !defined(__FUE__)
/*
*   Function
*      custom_cfg_outward_gpio_port
*   DESCRIPTION
*      The function is used to handle the port number of the outward gpio device.
*     And it will be call by audio manager.
*   PARAMETERS
*     gpio_device_id      IN
*     port_num            IN/OUT
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*/
kal_uint8 custom_cfg_outward_gpio_port(  kal_uint8  gpio_device_id /* gpio_device_enum */)
{
    if( (gpio_device_id < GPIO_LABELID_MAX) && (gpio_map_tbl[gpio_device_id].vaild != GPIO_INVAILD) )
        return gpio_map_tbl[gpio_device_id].port;
    else
        return 0;
}
#endif

#if defined(__MSGCMD_SUPPORT__)
/*******************************************************************************
** 函数: MsgCmd_isink
** 功能: 控制LCD背光开关
** 入参: open -- 开关
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_isink(kal_bool open)
{
	if(!open)
		pmic_adpt2_bl_enable(KAL_FALSE);
	else
		pmic_adpt2_bl_enable(KAL_TRUE);
    
	PWM3_level(LED_LIGHT_LEVEL2);
}
#endif

kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level )
{
    upmu_isink_enable(ISINK0,KAL_TRUE);
    upmu_isink_mode(ISINK0,0x0);
    upmu_isink_step(ISINK0,0x5);

    upmu_isink_enable(ISINK1,KAL_TRUE);
    upmu_isink_mode(ISINK1,0x0);
    upmu_isink_step(ISINK1,0x5);

    upmu_isink_enable(ISINK2,KAL_TRUE);
    upmu_isink_mode(ISINK2,0x0);
    upmu_isink_step(ISINK2,0x5);

    upmu_isink_enable(ISINK3,KAL_TRUE);
    upmu_isink_mode(ISINK3,0x0);
    upmu_isink_step(ISINK3,0x5);

    switch(gpio_dev_type)
    {
    case GPIO_DEV_LED_MAINLCD:
#if defined(__MSGCMD_SUPPORT__)
    /* MSGCMD disable LCD backlight. */
#else

#ifdef LQT_SUPPORT/*Please don't remove LQT code segments*/
        if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
        {
          gpio_dev_level=LED_LIGHT_LEVEL5;
        }
#endif/*LQT_SUPPORT*/
	if(gpio_dev_level == LED_LIGHT_LEVEL0)
		pmic_adpt2_bl_enable(KAL_FALSE);
	else
		pmic_adpt2_bl_enable(KAL_TRUE);		
	PWM3_level(gpio_dev_level);

#if defined(__RF_DESENSE_TEST__)
        if (RF_DESENSE_MODE_VBOOST_OFF == rf_desense_get_curr_mode()) {
            // Vboost mode OFF for backlight
            pmic_adpt2_bl_enable(KAL_FALSE);
        }
        else {
            // VBoost mode ON with worst case
            pmic_adpt2_bl_enable(KAL_TRUE);
        }

        // Output Vboost control register value
        // MT6253 VBOOST control register is 0x8301088C
        {
            kal_uint32 vboost_addr = 0x8301088C;
        
            kal_prompt_trace(MOD_MED,
                "[RF Desense][Vboost mode][0x%x b[1]=1 is ON, 0 is OFF, read value 0x%x]\n",
                vboost_addr, (*(volatile kal_uint16 *)(vboost_addr)));
        }
#endif // __RF_DESENSE_TEST__
#endif
        break;
    
    case GPIO_DEV_VIBRATOR:
        if(gpio_dev_level ==LED_LIGHT_LEVEL0)
            pmic_adpt2_vibr_enable(KAL_FALSE);
        else
            pmic_adpt2_vibr_enable(KAL_TRUE);
        //PWM3_level(gpio_dev_level);  /* Vibrator in 53EL don't have PWM mode */
        break;
    
    case GPIO_DEV_LED_KEY:
        if(gpio_dev_level ==LED_LIGHT_LEVEL0)
            pmic_adpt2_kpled_enable(KAL_FALSE);
        else
            pmic_adpt2_kpled_enable(KAL_TRUE);
        PWM_level(gpio_dev_level);
        break;
    
    default:
        break;
        /* error undefine */
        return KAL_FALSE;
    }

    return KAL_TRUE;

}

void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty)
{
#if defined(LED_ONOFF_SUPPORT) || defined(LED_FLASHLIGHT_SUPPORT)
    extern const char gpio_flashlight_en_pin;
    GPIO_ModeSetup(gpio_flashlight_en_pin, 0);
    GPIO_InitIO(1, gpio_flashlight_en_pin);
    GPIO_WriteIO(1, gpio_flashlight_en_pin);
#endif 

}

void custom_stop_flashlight(void)
{
#if defined(LED_ONOFF_SUPPORT) || defined(LED_FLASHLIGHT_SUPPORT)
    extern const char gpio_flashlight_en_pin;
    GPIO_ModeSetup(gpio_flashlight_en_pin, 0);
    GPIO_InitIO(1, gpio_flashlight_en_pin);
    GPIO_WriteIO(0, gpio_flashlight_en_pin);
#endif    
}

kal_uint8 custom_lamp_auto_cfg(void)
{
    static kal_uint8 lamp_onof = 0; 
#ifdef LAMP_SW
    extern const char gpio_lamp_en_pin;
    GPIO_WriteIO(!lamp_onof, gpio_lamp_en_pin);
    lamp_onof = !lamp_onof;
#endif
    return lamp_onof;
}
#endif /* !__L1_STANDALONE__ */

#endif /* __CUST_NEW__ */


