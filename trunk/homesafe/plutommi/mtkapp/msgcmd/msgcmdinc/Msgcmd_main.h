/*******************************************************************************
 *
 * msgcmd_main.h
 *
 * �����ܽӿ�
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, ����ԭʼ�汾
 *
 ******************************************************************************/

#ifndef __MSGCMD_MAIN_H__
#define __MSGCMD_MAIN_H__

#if defined(__MESSAGE_COMMAND_SUPPORT__)
#include "MMIDataType.h"

#ifndef mc_trace
#define mc_trace(fmt, ...) kal_prompt_trace(MOD_NIL, fmt, __VA_ARGS__)
#endif

#endif/*__MESSAGE_COMMAND_SUPPORT__*/

#endif/*__MSGCMD_MAIN_H__*/

