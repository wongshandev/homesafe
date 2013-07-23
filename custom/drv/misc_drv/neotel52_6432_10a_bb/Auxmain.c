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
 *    auxmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the AUX task
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __L1_STANDALONE__
#include 	"kal_release.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"task_config.h"
#include 	"stacklib.h"
#include    "stack_timer.h"      /*stack_timer_struct....definitions*/
#include 	"drv_comm.h"
#include    "reg_base.h"
#include    "adc.h"
#include    "drvsignals.h"
#include    "eint.h"
#include    "batvalue.h"
#include     "afe.h"
#include     "intrctrl.h"
#include     "uart_sw.h"
#include     "bmt.h"
#include "kal_non_specific_general_types.h"
#include "task_main_func.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "adc_channel.h"
kal_bool                aux_state = LEVEL_LOW;
extern const kal_uint8 AUX_EINT_NO;
void AUX_EINT_HISR(void);
/*************************************************************************
* Function declaration
 *************************************************************************/
kal_bool 	aux_create(comptask_handler_struct **handle);
static void aux_task_main(task_entry_struct *task_entry_ptr);
static kal_bool	aux_task_reset(task_indx_type task_indx);
static kal_bool 	aux_task_end(task_indx_type task_indx);
stack_timer_struct  aux_timer;
static kal_bool aux_timer_open=0;
static kal_bool poll_timer=KAL_FALSE;
static kal_bool aux_detect_mode=KAL_FALSE;
extern void EINT_Mask(kal_uint8 eintno);
extern void EINT_UnMask(kal_uint8 eintno);
extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);
extern kal_uint8 adc_sche_create_object(module_type ownerid, kal_uint8 adc_channel,kal_uint32 period, kal_uint8 evaluate_count, kal_bool send_primitive);
/*UART Detection*/
extern void   L1SM_SleepEnable( kal_uint8 handle );
extern void   L1SM_SleepDisable( kal_uint8 handle );
extern kal_uint8 L1SM_GetHandle(void);
kal_uint8  aux_PDNhandle;
kal_uint16 check_uart1=KAL_FALSE;
kal_uint16 check_uart2=KAL_FALSE;
kal_uint16 check_uart3=KAL_FALSE;

#define UART_ADC                    9999999
#define NORMAL_EARPHONE_ADC_HIGH    2800000
#define NORMAL_EARPHONE_ADC_LOW      500000/*0.5~2.8*/ 
#define SINGLE_EARPHONE_ADC_HIGH    2800000
#define SINGLE_EARPHONE_ADC_LOW      500000/*0.5~2.8*/
#define SENDKEY_ADC                  300000
#define POLLING_INTERVAL         50 /*polling interval*/
#define TURN_ON_BIAS_INTERVAL    10 /*measure adc interval*/    
#define PLUGIN_DEBOUNCE_TIME     100 /*unit=10ms*/
#define PLUGOUT_DEBOUNCE_TIME    100
#define VOLTAGE_MEASURE_TIME     450      
#undef  AUX_DEBUG
/*************************************************************************
* FUNCTION
*	aux_create
*
* DESCRIPTION
*	This function implements xyz entity's create handler.
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
aux_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct aux_handler_info = 
	{
		aux_task_main,			/* task entry function */
		NULL,		  	/* task initialization function */
		NULL, 	/* task configuration function */
		aux_task_reset,		/* task reset handler */
		aux_task_end			/* task termination handler */
	};

	*handle = (comptask_handler_struct *)&aux_handler_info;
	return KAL_TRUE;
}


void AUX_EINT_HISR(void)
{
   ilm_struct *aux_ilm;
   
      if (aux_state == LEVEL_HIGH)
      {
         #ifdef AUX_DEBUG
         dbg_print(" Interrupt: Plugout \n\r");
         #endif 
         aux_timer_open=0;	
         AFE_TurnOffMicBias();
         stack_stop_timer(&aux_timer);
         //GPIO_WriteIO(0,3);/*Turn off UART*/
         DRV_BuildPrimitive(aux_ilm,
                           MOD_EINT_HISR,
                           MOD_AUX,
                           MSG_ID_AUX_PLUGOUT,
                           NULL);
        EINT_SW_Debounce_Modify(AUX_EINT_NO,PLUGIN_DEBOUNCE_TIME);                              
        aux_state = !aux_state;
        EINT_Set_Polarity(AUX_EINT_NO,aux_state); 
      }
      else
      {
         #ifdef AUX_DEBUG
         dbg_print(" Interrupt: Plugin \n\r");
         #endif 
         aux_timer_open=1;		                           
         aux_detect_mode=AFE_TurnOnMicBias();            
         stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL);            
         DRV_BuildPrimitive(aux_ilm,
                           MOD_EINT_HISR,
                           MOD_AUX,
                           MSG_ID_AUX_PLUGIN,
                           NULL);      
         EINT_SW_Debounce_Modify(AUX_EINT_NO,PLUGOUT_DEBOUNCE_TIME);
         aux_state = !aux_state;
         EINT_Set_Polarity(AUX_EINT_NO,aux_state);
      }
      msg_send_ext_queue(aux_ilm);
}



void aux_read_adc_channel(kal_uint8 logic_id)
{
   ilm_struct        *aux_ilm;
   bmt_adc_add_item_req_struct *aux_adc_item;
   aux_adc_item = (bmt_adc_add_item_req_struct*)
				   construct_local_para(sizeof(bmt_adc_add_item_req_struct), TD_CTRL);
				   
   aux_adc_item->adc_sche_id = logic_id;
   
   DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_BMT,
                      MSG_ID_BMT_ADC_ADD_ITEM_REQ,
                      aux_adc_item);
                      
   msg_send_ext_queue(aux_ilm);
}

void aux_remove_adc_channel(kal_uint8 logic_id)
{
   ilm_struct        *aux_ilm;
   bmt_adc_remove_item_req_struct *aux_adc_remove_item;
   aux_adc_remove_item = (bmt_adc_remove_item_req_struct*)
	   construct_local_para(sizeof(bmt_adc_remove_item_req_struct), TD_CTRL);
   
   aux_adc_remove_item->adc_sche_id = logic_id;
   DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_BMT,
                      MSG_ID_BMT_ADC_REMOVE_ITEM_REQ,
                      aux_adc_remove_item);

   msg_send_ext_queue(aux_ilm);
}
/*************************************************************************
* FUNCTION
*	aux_read_result
*
* DESCRIPTION
*	This function is to read adc result and send msg to UEM and TST_READER accoding 
*  different adc value
*
* PARAMETERS
*  pre_id   : 
*  logic_id : adc logic channel 
*  buf      : local parameter of ilm 
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void aux_read_result(AUX_ID *pre_id,kal_uint8 aux_adc_logic_id,local_para_struct *buf)
{
   bmt_adc_measure_done_conf_struct *ptr=(bmt_adc_measure_done_conf_struct *)buf;
   kal_int32                       aux_volt_result;
   aux_id_struct                   *aux_id_data;
   ilm_struct                      *aux_ilm;
   AUX_ID                    aux_id_no=AUX_ID_PLUGOUT;
   
  
   if(0==aux_timer_open)
      return;
   aux_volt_result = (kal_int32)ptr->volt;
     
   if ((aux_volt_result > UART_ADC)&&(*pre_id!=AUX_ID_EARPHONE)&&(*pre_id!=AUX_ID_KEY_PRESS)&&(*pre_id!=AUX_ID_KEY_PRESS))
   {         
      #ifdef AUX_DEBUG         
      dbg_print("UART \n\r");
      dbg_print("AUX voltage = %d\n\r",aux_volt_result);
      #endif 
      aux_id_no = AUX_ID_UART;
      //GPIO_WriteIO(1,3);/*Turn on UART*/     
   }  
   if(aux_id_no!=AUX_ID_UART) 
   {
      if(aux_detect_mode==KAL_FALSE)/*normal mode */
      {
         #ifdef AUX_DEBUG
          dbg_print("Normal mode 2.2V \n\r");           
         #endif 
         if(((NORMAL_EARPHONE_ADC_LOW <aux_volt_result)&& (aux_volt_result< NORMAL_EARPHONE_ADC_HIGH) )||(aux_volt_result< SENDKEY_ADC)) 
         {  
            #ifdef AUX_DEBUG
            dbg_print("Earphone  \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            //L1SM_SleepEnable(aux_PDNhandle);
            if(*pre_id==AUX_ID_EARPHONE||*pre_id==AUX_ID_KEY_PRESS||*pre_id==AUX_ID_KEY_RELEASE)     
            {
            	if(aux_volt_result< SENDKEY_ADC)
            	{ 
            	   aux_id_no = AUX_ID_KEY_PRESS;  
            	}
            	else
            	{
            	   aux_id_no = AUX_ID_KEY_RELEASE;
            	}
            }
            else
            	 aux_id_no =AUX_ID_EARPHONE;	
         }
         else
         {
            #ifdef AUX_DEBUG
            dbg_print("Abnormal mode \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            aux_id_no= AUX_ID_PLUGOUT;
         }
      }
      else if(aux_detect_mode==KAL_TRUE) /*Single mode*/
      {
         #ifdef AUX_DEBUG
         dbg_print("Single mode 1.9V \n\r");   
         #endif
         if(((SINGLE_EARPHONE_ADC_LOW <aux_volt_result)&& (aux_volt_result< SINGLE_EARPHONE_ADC_HIGH) )||(aux_volt_result< SENDKEY_ADC)) 
         {           
            #ifdef AUX_DEBUG
            dbg_print("Earphone  \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            if(*pre_id==AUX_ID_EARPHONE||*pre_id==AUX_ID_KEY_PRESS||*pre_id==AUX_ID_KEY_RELEASE)     
            {
            	if(aux_volt_result< SENDKEY_ADC)
            	{ 
            	   aux_id_no = AUX_ID_KEY_PRESS;  
            	}
            	else
            	{
            	   aux_id_no = AUX_ID_KEY_RELEASE;
            	}
            }
            else
            	 aux_id_no =AUX_ID_EARPHONE;	
         }
         else
         {
            #ifdef AUX_DEBUG
            dbg_print("Abnormal mode \n\r");
            dbg_print("AUX voltage = %d\n\r",aux_volt_result);
            #endif
            aux_id_no= AUX_ID_PLUGOUT;
         }
      }                   
   }
   if ((*pre_id != aux_id_no) )
   {      
      if((aux_id_no!=AUX_ID_KEY_RELEASE)&&(aux_id_no!=AUX_ID_PLUGOUT))
      {
         #ifdef AUX_DEBUG
         dbg_print("Send EARPHONE msg to MMI \n\r");
         dbg_print("AUX ID  = %d\n\r",aux_id_no);
         #endif
         aux_id_data = (aux_id_struct*)
		      construct_local_para(sizeof(aux_id_struct), TD_CTRL);	   
         aux_id_data->aux_id = aux_id_no;
                  
            DRV_BuildPrimitive(aux_ilm,
                            MOD_AUX,
                            MOD_UEM,
                            MSG_ID_AUX_ID,
                            aux_id_data);
         
         msg_send_ext_queue(aux_ilm);         
       }
       if(aux_id_no!=AUX_ID_PLUGOUT) 
          *pre_id = aux_id_no;      
   }
   
   /*error state or poll timer on */
   if(aux_id_no==AUX_ID_PLUGOUT)
      stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);/*start polling timer*/ 
   else if(poll_timer==KAL_TRUE)
      stack_start_timer(&aux_timer, 1, POLLING_INTERVAL);/*start polling timer*/           
   
}



/*************************************************************************
* FUNCTION                                                            
*	aux_task_main
*
* DESCRIPTION                                                           
*	This function implements xyz task's entry function
*
* PARAMETERS
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void aux_task_main( task_entry_struct * task_entry_ptr )
{
   ilm_struct	      current_ilm;
   ilm_struct          *aux_ilm ;
   aux_id_struct        *aux_id_data;
   kal_uint8            aux_adc_logic_id;
   AUX_ID              pre_id = AUX_ID_PLUGOUT;              
   /*Engineering mode logic id*/
   kal_uint8            vbat_adc_logic_id;
   kal_uint8            visense_adc_logic_id;
   kal_uint8            vcharger_adc_logic_id;
   kal_uint8            vbattemp_adc_logic_id;
   kal_uint8            vaux_adc_logic_id;   
   /*Engineering mode result*/
   kal_int32           vbat_value=0;
   kal_int32           visense_value=0;
   kal_int32           vcharger_value=0;
   kal_int32           vbattemp_value=0;
   kal_int32           vaux_value=0;
   bmt_adc_measure_done_conf_struct *mea_done_ptr;
   adc_all_channel_struct *adc_all_channel_result;
   kal_uint16            adc_measure_count=0;
   stack_timer_struct               *check_timer_index; 
   static kal_uint8     call_setup_cnt=0;
   
    stack_init_timer(&aux_timer, "AUX_TIMER", MOD_AUX);
   /*40*4.615ms=18ms*/
   aux_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_ACCESSORYID,40,1, KAL_TRUE);
   
   /*Engineering mode*/   
   vbat_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VBAT,40,1, KAL_TRUE);
   visense_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VISENSE,40,1, KAL_TRUE);
   vcharger_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VCHARGER,40,1, KAL_TRUE);
   vbattemp_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_VBATTMP,40,1, KAL_TRUE);
   vaux_adc_logic_id = adc_sche_create_object(MOD_AUX, ADC_ACCESSORYID,40,1, KAL_TRUE);
          
   /*Enable External interrupt*/
#if !defined(__MSGCMD_SUPPORT__)
   EINT_Registration(AUX_EINT_NO,KAL_TRUE,aux_state,AUX_EINT_HISR, KAL_TRUE);      
#endif   
   
#if (defined(__ACCDET_SUPPORT__) && !defined(__L1_STANDALONE__))
   IRQUnmask(IRQ_ACCDET_CODE);
#endif

while(1)
   {
      receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
      
      switch(current_ilm.msg_id)
      {
         case MSG_ID_AUX_CALL_SETUP_REQ_IND:                        
               poll_timer=KAL_TRUE;  
            if((aux_timer_open==1) && (call_setup_cnt == 0))
            {   
               aux_detect_mode=AFE_TurnOnMicBias();/*voltage source*/  
#if !defined(__ACCDET_SUPPORT__)
               stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL); 
#endif //#if defined(__ACCDET_SUPPORT__)
            }    
            call_setup_cnt++;
            break;
         case MSG_ID_AUX_CALL_DISCONNECT_REQ_IND:
            if (call_setup_cnt>0)
               call_setup_cnt--;
            if (call_setup_cnt==0)
            {
            poll_timer=KAL_FALSE;
            AFE_TurnOffMicBias();/*voltage source*/  
            }
            break;         
         case MSG_ID_AUX_PLUGIN:
            break;
         
         case MSG_ID_AUX_PLUGOUT:   
            /*Notify MMI the aux is plugout*/   
                                                   
               pre_id = AUX_ID_PLUGOUT;            
               aux_id_data = (aux_id_struct*)
				      construct_local_para(sizeof(aux_id_struct), TD_CTRL);
               
               aux_id_data->aux_id = AUX_ID_PLUGOUT;
               
               DRV_BuildPrimitive(aux_ilm,
                         MOD_AUX,
                         MOD_UEM,
                         MSG_ID_AUX_ID,
                         aux_id_data);
                      
            msg_send_ext_queue(aux_ilm);
            
            /*remove the adc item*/
            aux_remove_adc_channel(aux_adc_logic_id);
            break;
         
         case MSG_ID_READ_ALL_ADC_CHANNEL_REQ:
            adc_measure_count=0;
            vbat_value = 0;
            aux_read_adc_channel(vbat_adc_logic_id);
            visense_value = 0;
            aux_read_adc_channel(visense_adc_logic_id);
            vcharger_value = 0;
            aux_read_adc_channel(vcharger_adc_logic_id);
            vbattemp_value = 0;
            aux_read_adc_channel(vbattemp_adc_logic_id);
            vaux_value = 0;
            aux_read_adc_channel(vaux_adc_logic_id);
            break;
            
         case MSG_ID_BMT_ADC_MEASURE_DONE_CONF:
            
            mea_done_ptr = (bmt_adc_measure_done_conf_struct *)current_ilm.local_para_ptr;
            if (mea_done_ptr->adc_sche_id == aux_adc_logic_id) /*normal mode*/
            {
               aux_remove_adc_channel(aux_adc_logic_id);
                if(poll_timer!=KAL_TRUE)  /*not turn off microbias when talking*/
                   AFE_TurnOffMicBias();
               aux_read_result(&pre_id,aux_adc_logic_id,current_ilm.local_para_ptr);
            }
            if (mea_done_ptr->adc_sche_id == vbat_adc_logic_id)
            {
               adc_measure_count++;
               vbat_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vbat_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == visense_adc_logic_id)
            {
               adc_measure_count++;
               visense_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(visense_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == vcharger_adc_logic_id)
            {
               adc_measure_count++;
               vcharger_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vcharger_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == vbattemp_adc_logic_id)
            {
               adc_measure_count++;
               vbattemp_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vbattemp_adc_logic_id);
            }
            else if (mea_done_ptr->adc_sche_id == vaux_adc_logic_id)
            {
               adc_measure_count++;
               vaux_value = (kal_int32)mea_done_ptr->volt;
               aux_remove_adc_channel(vaux_adc_logic_id);
            }
            
           if(adc_measure_count==5)
           {
#if defined(__RF_DESENSE_TEST__)
    kal_prompt_trace(MOD_TP_TASK, "DRIVING: IOA(%x), IOB(%x), IOC(%x), ACIF_CON0(%x)\r\n, EMI CLK: %s",
        *((unsigned int *)0x810000C0),
        *((unsigned int *)0x810000C4),
        *((unsigned int *)0x810000C8),
        *((unsigned int *)0x80010700),
        *((unsigned int *)0x80010120) == 1 ? "EMI_104MHz" : "EMI_52MHz"
        );
#endif
               adc_measure_count=0;
               adc_all_channel_result = (adc_all_channel_struct*)
				      construct_local_para(sizeof(adc_all_channel_struct), TD_CTRL);

               adc_all_channel_result->vbat = vbat_value;
               adc_all_channel_result->bat_temp=volt2temp(vbattemp_value);               
               adc_all_channel_result->vaux = vaux_value;
               adc_all_channel_result->charge_current = (visense_value - vbat_value)*bmt_custom_chr_def.ADC_ISENSE_RESISTANCE_FACTOR;
               adc_all_channel_result->vcharger = vcharger_value;

               DRV_BuildPrimitive(aux_ilm,
                      MOD_AUX,
                      MOD_UEM,
                      MSG_ID_ADC_ALL_CHANNEL_CONF,
                      adc_all_channel_result);
                      
               msg_send_ext_queue(aux_ilm);
            }
            break;
         case MSG_ID_TIMER_EXPIRY:/*Timer*/
            check_timer_index = (stack_timer_struct *) current_ilm.local_para_ptr;
            switch(check_timer_index->timer_indx)
            {
               case 0:/*20ms timer*/
                  if((aux_timer_open==1))            
                     aux_read_adc_channel(aux_adc_logic_id);
                  else
                     aux_remove_adc_channel(aux_adc_logic_id);
                  break;
               case 1:/*500ms timer*/                                    
                  aux_detect_mode=AFE_TurnOnMicBias();/*voltage source*/      
                  stack_start_timer(&aux_timer, 0, TURN_ON_BIAS_INTERVAL);
                  break;            
               default:
                  break;   
            }     
            break; 
         default:
            break;
      }
      free_ilm(&current_ilm);
   }
}

/*************************************************************************
* FUNCTION                                                            
*	aux_task_reset
*
* DESCRIPTION
*	This function implements xyz's reset handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
aux_task_reset(task_indx_type task_indx)
{
  	/* Do task's reset here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_reset() will do. */
	return KAL_TRUE;
}

/*************************************************************************
* FUNCTION                                                            
*	aux_task_end
*
* DESCRIPTION
*	This function implements xyz's termination handler
*
* PARAMETERS 
*	task_index	-	task's index
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool 
aux_task_end(task_indx_type task_indx)
{
  	/* Do task's termination here.
	 * Notice that: shouldn't execute modules reset handler since 
	 * stack_task_end() will do. */
	return KAL_TRUE;
}
/*UART Detection*/
void UART_Detection_Enable(UART_PORT port, kal_bool enable_flag)
{
   switch(port)
   {
      case uart_port1:
         check_uart1=enable_flag;
         break;
      case uart_port2:
         check_uart2=enable_flag;
         break;
      default:
         break;
   }
}

kal_bool Get_UART_Detection_Status(UART_PORT port)
{
   switch(port)
   {
      case uart_port1:
         return check_uart1;
         break;
      case uart_port2:
         return check_uart2;
         break;
      default:
         return KAL_FALSE;
         break;
   }
}

#endif /*__L1_STANDALONE__*/
