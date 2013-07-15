/*******************************************************************************
 *
 * msgcmd_main.h
 *
 * 对外框架接口
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, 创建原始版本
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

