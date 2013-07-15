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
 * Filename:
 * ---------
 * Custom_at_command.c
 *
 * Description:
 * ------------
 *   This file is intends for Customer to implement and parse its own defined AT commands
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*****************************************************************************/
#include "kal_release.h"
#include "kal_non_specific_general_types.h"
#include "stdio.h"
#include "string.h"
//#include "stack_config.h"	

#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif
extern void kal_monitor_buffer(kal_uint32 index);

#if defined(__MESSAGE_COMMAND_SUPPORT__)
extern kal_bool MsgCmd_AtCmdProc(char *cmd_string);
#endif

/*****************************************************************************
* CUSTOM_SYMBOL:
*	customer can modify this symbol.
*     Every command begin with this symbol will be recognized as a customer-defined command
*	and passed to custom_command_hdlr().
*     For example: if CUSTOM_SYMBOL is set to '^', 
*				then AT^AAAA, AT^BBBB will be customer-defined command.
*   	NOTE:  '+'  and '/' and ' \ 'is not allowed since they might be standard command format
*****************************************************************************/
#define CUSTOM_SYMBOL  '^'	 // '+'  and '/' and ' \ 'is NOT allowed   

#define TWO_MIC_NR_COMMAND_MAX_LENGTH 50 
#define SYMBOL_SPACE  32
#define SYMBOL_CR  13
#define SYMBOL_CR_JUDGE  14


/*****************************************************************************
* MAX_UART_LEN = 128 bytes.
*	when you write a lot of data to UART at the same time, 
*	UART's buffer might be full and cannot handle.
*     so the safer way is to seperate the long data, each time only write data length <= 128
*****************************************************************************/
#define MAX_UART_LEN	128  

kal_uint8 custom_get_atcmd_symbol(void);
kal_bool custom_command_hdlr(char *full_cmd_string);

/*****************************************************************************
* FUNCTION
*  	rmmi_write_to_uart()
* DESCRIPTION
*   	This function extern L4C RMMI function,
*     is to write data to UART
* PARAMETERS
*   	kal_uint8 * buffer 	- the data to be written
*	kal_uint16 length 	- the length of data to be written
*     kal_bool stuff 		- KAL_TRUE : <CR><LF> will be added at the beginning and end. (eg.<CR><LF>OK<CR><LF>)
*					   KAL_FALSE: no <CR><LF> is added
* RETURNS
*	none
*****************************************************************************/
extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff); 

#ifdef __GATI_ENABLE__
extern kal_bool gati_command_hdlr(kal_uint8* cmd_string, kal_uint8* full_string);

module_type gati_mod_table[] = 
{
    MOD_PHB,
    MOD_L4C,
    MOD_L4C,
    MOD_L4C, 
    MOD_NIL         /* Need to be the last one */
};

kal_char *gati_cmd_table[] = 
{
    "CPBBA",
    "CPBBR",
    "CPBBS",
    "CPBB"
};

#endif


#define COMMAND_LINE_SIZE    (180)
#define NULL_TERMINATOR_LENGTH (1)

 typedef struct 
{
  short  position;
  short  length;
  char   character[COMMAND_LINE_SIZE + NULL_TERMINATOR_LENGTH];
} custom_cmdLine;

typedef enum
{
    CUSTOM_WRONG_MODE,
    CUSTOM_SET_OR_EXECUTE_MODE,
    CUSTOM_READ_MODE,
    CUSTOM_TEST_MODE,
    CUSTOM_ACTIVE_MODE
} custom_cmd_mode_enum;

typedef enum
{
    CUSTOM_RSP_ERROR = -1,
    CUSTOM_RSP_OK = 0
} custom_rsp_type_enum;

typedef struct
{
	char *commandString;
	custom_rsp_type_enum (*commandFunc)(custom_cmdLine *commandBuffer_p);
} custom_atcmd;

custom_cmd_mode_enum custom_find_cmd_mode(custom_cmdLine *cmd_line);

custom_rsp_type_enum custom_test_func(custom_cmdLine *commandBuffer_p)
{
    custom_cmd_mode_enum result;
    custom_rsp_type_enum ret_value  = CUSTOM_RSP_ERROR;

    result = custom_find_cmd_mode(commandBuffer_p);		
    switch (result)
    {
        case CUSTOM_READ_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_ACTIVE_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_SET_OR_EXECUTE_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_TEST_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;    
        default:
            ret_value = CUSTOM_RSP_ERROR;
            break;
    }
    return ret_value;
}


/********************************
* The following table is used for the customer
* They can defined their own command and 
* corresponding handler function here
* Note that the last line {NULL, NULL} should not be removed
* since it is the terminator indicator
*********************************/
const custom_atcmd custom_cmd_table[ ] =
{    
    {"AT%CUSTOM",custom_test_func},
    {NULL, NULL}  // this lind should not be removed, it will be treat as 
};

/*****************************************************************************
* FUNCTION
*     custom_find_cmd_mode()
* DESCRIPTION
*     This function is used to parsing the command mode for the customer
*     The input position of the cmd_line should stay at the character right after the command name
* PARAMETERS
*     cmd_line      the custom_cmdLine which contains the command string and its current parsing position
* RETURNS
*     custom_cmd_mode_enum
*****************************************************************************/
custom_cmd_mode_enum custom_find_cmd_mode(custom_cmdLine *cmd_line)
{
    custom_cmd_mode_enum result;

    if (cmd_line->position < cmd_line->length - 1)
    {
        switch (cmd_line->character[cmd_line->position])
        {
            case '?':  /* AT+...? */
            {
                cmd_line->position++;
                result = CUSTOM_READ_MODE;
                break;
            }
            case '=':  /* AT+...= */
            {
                cmd_line->position++;
                if ((cmd_line->position < cmd_line->length - 1 ) &&
                    (cmd_line->character[cmd_line->position] == '?'))
                {
                    cmd_line->position++;
                    result = CUSTOM_TEST_MODE;
                }
                else
                {
                    result = CUSTOM_SET_OR_EXECUTE_MODE;
                }
                break;
            }
            default:  /* AT+... */
            {
                result = CUSTOM_ACTIVE_MODE;
                break;
            }
        }
    }
    else
    {
        result = CUSTOM_ACTIVE_MODE;
    }
    return (result);
}


/*****************************************************************************
* FUNCTION
*  	custom_command_hdlr()
* DESCRIPTION
*   	This function should parse the custom AT command and do correspondent action.
*     Customer should maintain and modify the code.
* PARAMETERS
*   	kal_uint8 * cmd_string
* RETURNS
*    KAL_TRUE : the command is handled by the customer
*    KAL_FALSE: the command is not handled by the customer
*****************************************************************************/
#ifdef __TWOMICNR_SUPPORT__
kal_bool custom_command_hdlr(char *full_cmd_string)
{
#if defined(__MESSAGE_COMMAND_SUPPORT__)
    if (MsgCmd_AtCmdProc(full_cmd_string))
    {
        return KAL_TRUE;
    }
    else
#endif
{
    char buffer[MAX_UART_LEN];
    char buffer_temp;
    char buffer_low;
    char buffer_high;
    char cmd_name[5];
    unsigned char data_byte[5];
    kal_uint8 index = 3; // we start parsing index after the CUSTOM_SYMBOL 
    kal_uint8 tmp_idx = 0;
    kal_uint16 length_of_at_command_content;
    kal_uint16 content_counter;
    kal_uint16 temp_counter;
    kal_uint16 Length_from_command;
    kal_uint16 command_data_length;
    kal_uint16 One_command_data_length;
    kal_uint16 data_byte_length;
    kal_uint16 length;
    unsigned short GPIO_pin_name;
    unsigned short GPIO_pin_voltage;
    kal_bool   operation_success;
    unsigned char parameter_data_from_PC[TWO_MIC_NR_COMMAND_MAX_LENGTH];
    unsigned char Command_data_to_be_sent[TWO_MIC_NR_COMMAND_MAX_LENGTH];

              kal_prompt_trace(MOD_L1SP,"two_mic_NR: enter custom_command_handler: %d", 0);

    length = strlen(full_cmd_string);
    length = length > TWO_MIC_NR_COMMAND_MAX_LENGTH ? TWO_MIC_NR_COMMAND_MAX_LENGTH : length;


    while ( (full_cmd_string[index] != SYMBOL_SPACE ) && (full_cmd_string[index] > 64 ) )
    {
        cmd_name[tmp_idx] = full_cmd_string[index] ;
        tmp_idx ++;
        index ++;
    }
    cmd_name[tmp_idx] = 0 ;  // 0 ?

              kal_prompt_trace(MOD_L1SP,"two_mic_NR: enter macro_TWOMICNR_SUPPORT: %d", 0);
    if (strcmp(cmd_name, "DATA") == 0) // Transferring command data from PC tool to FM2018x through UART port
    {		
              kal_prompt_trace(MOD_L1SP,"two_mic_NR: enter data processing: %d", 0);
    	content_counter = 0;
	while (full_cmd_string[index] == SYMBOL_SPACE) // omit all of the blanks before the data byte
	{
		index ++;
	}
              kal_prompt_trace(MOD_L1SP,"two_mic_NR: first para: %d", full_cmd_string[index]);
    	while (full_cmd_string[index] > SYMBOL_CR_JUDGE )  //carriage return
	{
		data_byte_length = 0;
		while (full_cmd_string[index] > SYMBOL_SPACE) // fetch the data byte
		{
			if (full_cmd_string[index] > 64)  // 'A' ~ 'Z'
			{
				data_byte[data_byte_length] = (unsigned char)(full_cmd_string[index]-65+10);
			}
			else  // '0' ~ '9'
			{
				data_byte[data_byte_length] = (unsigned char)(full_cmd_string[index]-48);
			}
			data_byte_length++;
			index ++;
		}
		if (data_byte_length > 1)
		{
			parameter_data_from_PC[content_counter] = 16*data_byte[0] + data_byte[1];
			content_counter ++;
		}
		else
		{
			parameter_data_from_PC[content_counter] = data_byte[0];
			content_counter ++;
		}
		while (full_cmd_string[index] == SYMBOL_SPACE) // omit all of the blanks before the data byte
		{
			index ++;
		}
	}
	command_data_length = content_counter;
  kal_prompt_trace(MOD_L1SP,"two_mic_NR: command_data_length= %d", command_data_length);
		
	/* the command data is kept in the array parameter_data_from_PC[] */
	/* parsing the command data according to Two-microphone design proposal between MTK and FM V092.doc */
	content_counter = 0;
 

	while (content_counter < command_data_length)
	{
		One_command_data_length = 0;
		content_counter++; // START_TOKEN
		if (parameter_data_from_PC[content_counter] == 2)	//DW_TOKEN  --- download
		{
			content_counter ++;
			Command_data_to_be_sent[One_command_data_length] = parameter_data_from_PC[content_counter];  // ID
			One_command_data_length ++;
			content_counter ++;
			Length_from_command = (kal_uint16)parameter_data_from_PC[content_counter];
			content_counter ++;
			Length_from_command += (256*(kal_uint16)parameter_data_from_PC[content_counter]);
			Length_from_command ++;
			content_counter ++;
  kal_prompt_trace(MOD_L1SP,"two_mic_NR: download command_data_length=%d Length_from_command=%d", command_data_length,Length_from_command);
			for (temp_counter = 0; temp_counter < Length_from_command; temp_counter++)
			{
				Command_data_to_be_sent[One_command_data_length] = parameter_data_from_PC[content_counter];
				One_command_data_length ++;
				content_counter ++;
			}
			content_counter++; // STOP_TOKEN
			Two_mic_NR_I2C_download_data((unsigned char*)Command_data_to_be_sent,One_command_data_length);
		}
		else	//DR_N_TOKEN  --- readback
		{
			content_counter ++;
			Command_data_to_be_sent[One_command_data_length] = parameter_data_from_PC[content_counter] + 1;  // ID
			One_command_data_length ++;
			content_counter ++;
			Length_from_command = parameter_data_from_PC[content_counter];
			content_counter ++;
			Length_from_command += (256*parameter_data_from_PC[content_counter]);
			Length_from_command ++;
			content_counter ++;
			content_counter++; // STOP_TOKEN
			buffer_temp = (char)Two_mic_NR_I2C_readback_data(Command_data_to_be_sent[0]);
			buffer_high = buffer_temp & 0xf0;
			buffer_high = buffer_high/16;
			buffer_high = buffer_high & 0x0f;
			if (buffer_high < 10)  // '0' ~ '9'
			{
				buffer[0] = buffer_high + 48;
			}
			else  // 'A' ~ 'Z'
			{
				buffer[0] = buffer_high + 55;
			}
			buffer_low = buffer_temp & 0x0f;
			if (buffer_low < 10)  // '0' ~ '9'
			{
				buffer[1] = buffer_low + 48;
			}
			else  // 'A' ~ 'Z'
			{
				buffer[1] = buffer_low + 55;
			}
  kal_prompt_trace(MOD_L1SP,"two_mic_NR: readback %d", buffer_temp);
			buffer[2] = SYMBOL_CR;
			buffer[3] = 0 ;
			rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		}
	}


        return KAL_TRUE;
    }
    else if (strcmp(cmd_name, "CON") == 0) // GPIO control coming from PC tool through UART port
    {		
              kal_prompt_trace(MOD_L1SP,"two_mic_NR: enter GPIO: %d", 0);
	while (full_cmd_string[index] == SYMBOL_SPACE) // omit all of the blanks before the data byte
	{
		index ++;
	}
              kal_prompt_trace(MOD_L1SP,"two_mic_NR: first para: %d", full_cmd_string[index]);

	if (full_cmd_string[index] > 64)  // 'A' ~ 'Z'
	{
		GPIO_pin_name = (unsigned short)(full_cmd_string[index])-65+10;
	}
	else  // '0' ~ '9'
	{
		GPIO_pin_name = (unsigned short)(full_cmd_string[index])-48;
	}
	index ++;

	while (full_cmd_string[index] == SYMBOL_SPACE) // omit all of the blanks before the data byte
	{
		index ++;
	}

	if (full_cmd_string[index] > 64)  // 'A' ~ 'Z'
	{
		GPIO_pin_voltage = (unsigned short)(full_cmd_string[index])-65+10;
	}
	else  // '0' ~ '9'
	{
		GPIO_pin_voltage = (unsigned short)(full_cmd_string[index])-48;
	}
	index ++;
	
              kal_prompt_trace(MOD_L1SP,"two_mic_NR: GPIO_pin_name= %d; GPIO_pin_voltage= %d", GPIO_pin_name,GPIO_pin_voltage);
              
	operation_success = KAL_TRUE;

	while (full_cmd_string[index] == SYMBOL_SPACE) // omit all of the blanks after the last data byte
	{
		index ++;
	}
	if (full_cmd_string[index] == SYMBOL_CR) // the last data byte is carriage return
	{
		Two_Mic_NR_GPIO_con(GPIO_pin_name,GPIO_pin_voltage);
		operation_success = KAL_TRUE;
	}
	else
	{
		operation_success = KAL_FALSE;
	}

/*
        if(operation_success == KAL_TRUE)    // if operation is success
        {
                sprintf(buffer, "OK");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        else // if operation is fail
        {
            sprintf(buffer, "ERROR");
            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
*/        
        return KAL_TRUE;
    }
    #ifndef __MMI_FMI__	
    else if (strcmp(cmd_name, "buffer") == 0)
    {		
        kal_print("Buffer Monitor enabled!");
        kal_monitor_buffer(0xffffffff);		
        sprintf(buffer, "OK");
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

        return KAL_TRUE;
    }	
    #endif	
    else
    {

    #ifdef __GATI_ENABLE__		 
        /* Judge if the command string is a GATI command*/
        if( gati_command_hdlr( (kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string)==KAL_TRUE )
        {
            // it is a gati command and we will send the command to the appropriate module
            return KAL_TRUE;
        }		 	
    #endif
    }	
		 
    /* unrecognized command */
    /* we should return KAL_FALSE to let ATCI judge if the it can handle the command */
    return KAL_FALSE;
}	
}

#else
kal_bool custom_command_hdlr(char *full_cmd_string)
{
#if defined(__MESSAGE_COMMAND_SUPPORT__)
    if (MsgCmd_AtCmdProc(full_cmd_string))
    {
        return KAL_TRUE;
    }
    else
#endif
{
    char buffer[MAX_UART_LEN+1]; //MAUI_02377056
    char *cmd_name, *cmdString;
    kal_uint8 index = 0; 
    kal_uint16 length;
    kal_uint16 i;
    custom_cmdLine command_line;

    cmd_name = buffer;

    length = strlen(full_cmd_string);
    length = length > MAX_UART_LEN ? MAX_UART_LEN : length;    
    while ((full_cmd_string[index] != '=' ) &&  //might be TEST command or EXE command
        (full_cmd_string[index] != '?' ) && // might be READ command
        (full_cmd_string[index] != 13 ) && //carriage return
        index < length)  
    {
        cmd_name[index] = full_cmd_string[index] ;
        index ++;
    }
    cmd_name[index] = '\0' ;    
    
    for (i = 0 ; custom_cmd_table[i].commandString != NULL; i++ )
    {
        cmdString = custom_cmd_table[i].commandString;
        if (strcmp(cmd_name, cmdString) == 0 )
        {
            strncpy(command_line.character, full_cmd_string, COMMAND_LINE_SIZE + NULL_TERMINATOR_LENGTH);
            command_line.length = strlen(command_line.character);
            command_line.position = index;
            if (custom_cmd_table[i].commandFunc(&command_line) == CUSTOM_RSP_OK) 
            {
                sprintf(buffer, "OK");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            else
            {
                sprintf(buffer, "ERROR");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            return KAL_TRUE;
        }
    }    

    if (index <= 2)
        return KAL_FALSE;
	
    /* just a very basic example : customer can implement their own */
    cmd_name += 3;
    if (strcmp(cmd_name, "EXAMPLE") == 0)
    {		
        /* BEGIN: do the following parsing and correspondent action */
        /*  												    */
        /*  												    */
        /*  												    */
        /* END: do the following parsing and correspondent action    */

        /* generate final result code: "OK" or "ERROR" */
        if(KAL_TRUE)    // if operation is success
        {
                sprintf(buffer, "OK");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        else if (KAL_FALSE) // if operation is fail
        {
            sprintf(buffer, "ERROR");
            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        return KAL_TRUE;
    }
    #if !defined(__MMI_FMI__) || defined(WISDOM_MMI)
    else if (strcmp(cmd_name, "buffer") == 0)
    {		
        kal_print("Buffer Monitor enabled!");
        kal_monitor_buffer(0xffffffff);		
        sprintf(buffer, "OK");
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

        return KAL_TRUE;
    }	
    #endif	
    else
    {

    #ifdef __GATI_ENABLE__		 
        /* Judge if the command string is a GATI command*/
        if( gati_command_hdlr( (kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string)==KAL_TRUE )
        {
            // it is a gati command and we will send the command to the appropriate module
            return KAL_TRUE;
        }		 	
    #endif
    }	
		 
    /* unrecognized command */
    /* we should return KAL_FALSE to let ATCI judge if the it can handle the command */
    return KAL_FALSE;
}
}
#endif

/*****************************************************************************
* FUNCTION
*  	custom_get_atcmd_symbol()
* DESCRIPTION
*   	This function returns special symbol for customer-defined AT command, 
*   	so AT parser can recognize its a custom command and forward the string to custom_command_handler().
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_atcmd_symbol(void)
{
   return (CUSTOM_SYMBOL);
}

/*****************************************************************************
* USER DEFINE CONSTANT
*  	RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE
* DESCRIPTION
* 	1. This value defines the control DCD value for data mode (CSD/GPRS dialup)
*   2. CUSTOMER CAN modify this value accroding to its TE requirement
*****************************************************************************/
#define RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE (1)

/*****************************************************************************
* USER DEFINE CONSTANT
*  	RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE
* DESCRIPTION
* 	1. This value defines the control DCD value for AT command mode (Normal/Escaped AT)
*   2. CUSTOMER CAN modify this value accroding to its TE requirement
*****************************************************************************/
#define RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE (0)

/*****************************************************************************
* FUNCTION
*  	custom_get_dcd_value_for_data_state()
* DESCRIPTION
*   	This function returns the user-defined DCD value for data state
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_dcd_value_for_data_state(void)
{
    return (kal_uint8) RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE;
}

/*****************************************************************************
* FUNCTION
*  	custom_get_dcd_value_for_cmd_state()
* DESCRIPTION
*   	This function returns the user-defined DCD value for command state
*       It shall be inverted value of custom_get_dcd_value_for_data_state()
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_dcd_value_for_cmd_state(void)
{
    return (kal_uint8)RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE;
}

#ifdef __MOD_TCM__
/*****************************************************************************
* FUNCTION
*  	custom_get_gprs_dialup_connect_post_string()
* DESCRIPTION
*   This function returns the post string right after CONNECT in gprs dialup.
*
*   The return string length must be less than 64
*
*   If post_string is XXXXXX, 
*   then MS sends "<cr><lf>CONNECT XXXXXX<cr><lf>" when GPRS dialup
*   Ex.1 if post_string=" 230400", 
*        then entire output string is "<cr><lf>CONNECT 230400<cr><lf>"
*   Ex.2 if post_string=" 56000 V42bis", 
*        then entire output string is "<cr><lf>CONNECT 56000 V42bis<cr><lf>"
*    
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8* post_string
*****************************************************************************/
const kal_uint8* custom_get_gprs_dialup_connect_post_string(void)
{
    /* Note: The return string length must be less than 64!!! */
#ifdef __TC01__
  #if defined(__HSDPA_SUPPORT__)
/* under construction !*/
	#elif defined(__EGPRS_MODE__)
/* under construction !*/
	#else
/* under construction !*/
	#endif
#else
    static const kal_uint8 post_string[] = ""; //for "CONNECT" only
#endif

    return (const kal_uint8*) post_string;
} // MAUI_02386357, mtk02285, MAUI_02825172
#endif /* __MOD_TCM__ */
