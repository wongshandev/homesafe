/*******************************************************************************
 *
 * msgcmd_at.c
 *
 * 处理MSGCMD自定义的AT命令
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, 创建原始版本
 *
 ******************************************************************************/

#ifndef __MSGCMD_AT_H__
#define __MSGCMD_AT_H__

#if defined(__MESSAGE_COMMAND_SUPPORT__)

#include "msgcmd_datatype.h"

/* AT 命令索引枚举 */
typedef enum {
    AT_CMD_REBOOT,
    AT_CMD_SHUTDOWN,
    AT_CMD_CATCH,
    AT_CMD_ISINK,
    AT_CMD_ADORECD,
    AT_CMD_VDORECD,
    AT_CMD_CAPTURE,
    AT_CMD_IDX_MAX,
}AtCmdIdx_e;

/* AT 命令执行模式 */
typedef enum {
    AT_EM_WRONG,        // 错误
    AT_EM_SET_OR_EXEC,  // 设置或者执行, AT+...=
    AT_EM_READ,         // 读取, AT+...?
    AT_EM_HELP,         // 测试, AT+...=?
    AT_EM_ACTIVE,       // 默认模式, 激活, AT+...
    AT_EM_MAX
}AtExecMode_e;


/* AT 命令执行结果 */
typedef enum {
    AT_RST_SUCCESS = 0,
    AT_RST_UNKOWN_ERR,   // 表示未知错误, 一般是参数解析错误居多
    AT_RST_NO_REPLAY,    // 表示无需回复"OK"/"ERROR"等消息
    AT_RST_IGNORED,      // 表示忽略了的, 未进行处理的, 没有对应处理函数的
    AT_RST_NOT_SUPPORT,  // 表示不支持的操作, 比如不支持读取模式
    AT_RST_PARAM_ERR,    // 表示传入的参数不在命令允许的范围或不是命令所需
}AtExecRst_e;


/* AT 命令字符串最大长度, 标准规定 */
#define AT_CMD_STRING_MAX     (1056+2) 
#define AT_CMD_NAME_LEN_MAX   (31)

/* 自定义AT命令最多可以带16个用逗号隔开的参数 */
#define CMD_ARG_ITEM_MAX    (16)


typedef struct {
    CHAR   *pos;
    INT16U  len;
}ArgItem_t;

typedef struct {
    const CHAR  *name;
    INT16U       argc;
    ArgItem_t    argv[CMD_ARG_ITEM_MAX];
    AtExecMode_e mode;
    AtCmdIdx_e   index;
    AtExecRst_e  result;
}AtParam_t;

typedef void (*AtCbFunc)(AtParam_t *);
typedef struct {
    CHAR      *bodyStr;
    INT16U     bodyLen;
    AtCmdIdx_e index;
    AtCbFunc   callback;
}AtCmdTab_t;


/*******************************************************************************
** 函数: MsgCmd_AtCmdProc
** 功能: 处理自定义AT命令
** 参数: origStr  -- AT命令行参数, 
**                   如果不是自定义的AT指令则不可破坏cmd_string中的内容
** 返回: 是否是自定义AT指令
** 作者: wasfayu
*******/
_BOOL MsgCmd_AtCmdProc(CHAR *origStr);


#endif/*__MESSAGE_COMMAND_SUPPORT__*/

#endif/*__MSGCMD_AT_H__*/

