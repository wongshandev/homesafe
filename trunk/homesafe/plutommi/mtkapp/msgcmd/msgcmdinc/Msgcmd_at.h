/*******************************************************************************
 *
 * msgcmd_at.c
 *
 * ����MSGCMD�Զ����AT����
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, ����ԭʼ�汾
 *
 ******************************************************************************/

#ifndef __MSGCMD_AT_H__
#define __MSGCMD_AT_H__

#if defined(__MESSAGE_COMMAND_SUPPORT__)

#include "msgcmd_datatype.h"

/* AT ��������ö�� */
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

/* AT ����ִ��ģʽ */
typedef enum {
    AT_EM_WRONG,        // ����
    AT_EM_SET_OR_EXEC,  // ���û���ִ��, AT+...=
    AT_EM_READ,         // ��ȡ, AT+...?
    AT_EM_HELP,         // ����, AT+...=?
    AT_EM_ACTIVE,       // Ĭ��ģʽ, ����, AT+...
    AT_EM_MAX
}AtExecMode_e;


/* AT ����ִ�н�� */
typedef enum {
    AT_RST_SUCCESS = 0,
    AT_RST_UNKOWN_ERR,   // ��ʾδ֪����, һ���ǲ�����������Ӷ�
    AT_RST_NO_REPLAY,    // ��ʾ����ظ�"OK"/"ERROR"����Ϣ
    AT_RST_IGNORED,      // ��ʾ�����˵�, δ���д����, û�ж�Ӧ��������
    AT_RST_NOT_SUPPORT,  // ��ʾ��֧�ֵĲ���, ���粻֧�ֶ�ȡģʽ
    AT_RST_PARAM_ERR,    // ��ʾ����Ĳ���������������ķ�Χ������������
}AtExecRst_e;


/* AT �����ַ�����󳤶�, ��׼�涨 */
#define AT_CMD_STRING_MAX     (1056+2) 
#define AT_CMD_NAME_LEN_MAX   (31)

/* �Զ���AT���������Դ�16���ö��Ÿ����Ĳ��� */
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
** ����: MsgCmd_AtCmdProc
** ����: �����Զ���AT����
** ����: origStr  -- AT�����в���, 
**                   ��������Զ����ATָ���򲻿��ƻ�cmd_string�е�����
** ����: �Ƿ����Զ���ATָ��
** ����: wasfayu
*******/
_BOOL MsgCmd_AtCmdProc(CHAR *origStr);


#endif/*__MESSAGE_COMMAND_SUPPORT__*/

#endif/*__MSGCMD_AT_H__*/

