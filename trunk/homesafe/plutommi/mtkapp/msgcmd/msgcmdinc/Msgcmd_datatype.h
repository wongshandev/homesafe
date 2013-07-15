/*******************************************************************************
 *
 * msgcmd_datatype.h
 *
 * 统一数据类型
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, 创建原始版本
 *
 ******************************************************************************/

#ifndef __MSGCMD_DATATYPE_H__
#define __MSGCMD_DATATYPE_H__



#if defined(__MESSAGE_COMMAND_SUPPORT__)

#include "MMIDataType.h"


/* portable character for multichar character set */
typedef char                    CHAR;
/* portable wide character for unicode character set */
typedef unsigned short          WCHAR;

/* portable 8-bit unsigned integer */
typedef unsigned char           INT8U;
/* portable 8-bit signed integer */
typedef signed char             INT8S;
/* portable 16-bit unsigned integer */
typedef unsigned short int      INT16U;
/* portable 16-bit signed integer */
typedef signed short int        INT16S;
/* portable 32-bit unsigned integer */
typedef unsigned int            INT32U;
/* portable 32-bit signed integer */
typedef signed int              INT32S;

#if !defined(GEN_FOR_PC) && !defined(__MTK_TARGET__)
/* portable 64-bit unsigned integer */
   typedef unsigned __int64     INT64U;
/* portable 64-bit signed integer */
   typedef __int64              INT64S;
#else
/* portable 64-bit unsigned integer */
typedef unsigned long long      INT64U;
/* portable 64-bit signed integer */
typedef signed long long        INT64S;
#endif

/* boolean representation */
#define _FALSE        KAL_FALSE
#define _TRUE         KAL_TRUE 
#define _BOOL         kal_bool





#endif/*__MESSAGE_COMMAND_SUPPORT__*/


#endif/*__MSGCMD_DATATYPE_H__*/

