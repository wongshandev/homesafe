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


#if defined(__MESSAGE_COMMAND_SUPPORT__)
#include "alarmsrvgprot.h"
#include "bootupsrvgprot.h"
#include "shutdownsrvgprot.h"
#include "uart_sw.h"
#include "nvram_common_defs.h"
#include "nvram_interface.h"
#include "app_str.h"
#include "msgcmd_process.h"
#include "msgcmd_at.h"


/*****************************************************************************
* FUNCTION
*  	rmmi_write_to_uart()
* DESCRIPTION
*     This function extern L4C RMMI function,
*     is to write data to UART
* PARAMETERS
*     kal_uint8 * buffer 	- the data to be written
*	  kal_uint16 length 	- the length of data to be written
*     kal_bool stuff 		- KAL_TRUE : <CR><LF> will be added at the beginning and end. (eg.<CR><LF>OK<CR><LF>)
*					          KAL_FALSE: no <CR><LF> is added
* RETURNS
*	none
*****************************************************************************/
extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff); 

/*******************************************************************************
** 函数: MsgCmd_isink
** 功能: 控制LCD背光开关
** 入参: open -- 开关
** 返回: 无
** 作者: wasfayu
*******/
extern void MsgCmd_isink(kal_bool open);


/*******************************************************************************
** 函数: at_shutdown
** 功能: AT命令, 终端关机
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_shutdown(AtParam_t *vp);

/*******************************************************************************
** 函数: at_reboot
** 功能: AT命令, 终端关机
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_reboot(AtParam_t *vp);

/*******************************************************************************
** 函数: at_catch
** 功能: AT命令, MTK的catch开关设置
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_catch(AtParam_t *vp);

/*******************************************************************************
** 函数: at_isink
** 功能: AT命令, 控制4个背光灯
** 入参: vp
** 返回: 无  at$isink=(0, 1)
** 作者: wasfayu
*******/
static void at_isink(AtParam_t *vp);

/*******************************************************************************
** 函数: at_adorecd
** 功能: AT命令, 控制录像
** 入参: vp
** 返回: 无  at$adorecd=(0,1),time,number
** 作者: wasfayu
*******/
static void at_adorecd(AtParam_t *vp);

/*******************************************************************************
** 函数: at_vdorecd
** 功能: AT命令, 控制录像
** 入参: vp
** 返回: 无  at$vdorecd=(0,1),time,number
** 作者: wasfayu
*******/
static void at_vdorecd(AtParam_t *vp);

/*******************************************************************************
** 函数: at_capture
** 功能: AT命令, 控制拍照
** 入参: vp
** 返回: 无  at$capture[=number]
** 作者: wasfayu
*******/
static void at_capture(AtParam_t *vp);


#ifndef mc_at_replay
#define mc_at_replay(stuff, fmt, ...)
#endif 


//自定义AT命令表
static const AtCmdTab_t command_table[AT_CMD_IDX_MAX] = {
    {"$reboot",       7, AT_CMD_REBOOT,       at_reboot      },
    {"$shutdown",     9, AT_CMD_SHUTDOWN,     at_shutdown    },
    {"$catch",        6, AT_CMD_CATCH,        at_catch       },
    {"$isink",        6, AT_CMD_ISINK,        at_isink       },
    {"$adorecd",      7, AT_CMD_ADORECD,      at_adorecd     },
    {"$vdorecd",      7, AT_CMD_VDORECD,      at_vdorecd     },
    {"$capture",      7, AT_CMD_CAPTURE,      at_capture     },
};



/*******************************************************************************
** 函数: at_sample
** 功能: AT命令, 示例函数, 复制过去, 直接改下函数名, 
**       然后在函数体内对应的CASE下修改修改就好了.
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_sample(AtParam_t *vp)
{
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (0 == vp->argc || NULL == vp->argv[0].pos)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            //将你需要的代码放在这里
        }
        break;
        
    case AT_EM_HELP:
        //vp->result = AT_RST_SUCCESS;
        break;
        
    case AT_EM_READ:
        vp->result = AT_RST_NOT_SUPPORT;
        break;
        
    case AT_EM_ACTIVE:
        //vp->result = AT_RST_SUCCESS;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
}

/*******************************************************************************
** 函数: at_shutdown
** 功能: AT命令, 终端关机
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_shutdown(AtParam_t *vp)
{
#define shutdown_delay_min  3
#define shutdown_delay_max  180

    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (1 != vp->argc || NULL == vp->argv[0].pos)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            INT32U dly = atoi(vp->argv[0].pos);
            
            srv_shutdown_normal_start(SRV_BOOTUP_MODE_NORMAL);
        }
        break;
        
    case AT_EM_HELP:
        mc_at_replay(
            _TRUE, 
            "%s: (0, %d~%d)",
            vp->name,
            shutdown_delay_min, 
            shutdown_delay_max);
        break;
        
    case AT_EM_READ:
    case AT_EM_ACTIVE:
        vp->result = AT_RST_NOT_SUPPORT;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
    
#undef shutdown_delay_min
#undef shutdown_delay_max
}

/*******************************************************************************
** 函数: at_reboot
** 功能: AT命令, 终端关机
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_reboot(AtParam_t *vp)
{
#define reboot_delay_min  3
#define reboot_delay_max  180

    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (1 != vp->argc || NULL == vp->argv[0].pos)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            INT32U dly = MsgCmd_Atoi((const CHAR *)vp->argv[0].pos);

            MsgCmd_RebootExt(dly);
        }
        break;
        
    case AT_EM_HELP:
        mc_at_replay(
            _TRUE, 
            "%s: (0, %d~%d)", 
            vp->name,
            reboot_delay_min, 
            reboot_delay_max);
        break;
        
    case AT_EM_READ:
    case AT_EM_ACTIVE:
        vp->result = AT_RST_NOT_SUPPORT;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
    
#undef reboot_delay_min
#undef reboot_delay_max
}

/*******************************************************************************
** 函数: at_catch
** 功能: AT命令, MTK的catch开关设置
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_catch(AtParam_t *vp)
{
    INT8U enableVal[2] = {uart_port_usb, uart_port_null};//open, close
    
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (1 != vp->argc || NULL == vp->argv[0].pos)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            INT32U val, i;
            port_setting_struct ps;

            for(i=0; i<sizeof(enableVal)/sizeof(enableVal[0]); i++)
            {
                if(enableVal[i] == (INT8U)val)
                    break;
            }
            
            if(i >= sizeof(enableVal)/sizeof(enableVal[0]))
            {
                vp->result = AT_RST_PARAM_ERR;
                break;
            }
            
            memset((void*)&ps, 0, sizeof(port_setting_struct));
            if (!nvram_external_read_data(
                    NVRAM_EF_PORT_SETTING_LID,
                    1,
                    (INT8U*)&ps,
                    sizeof(port_setting_struct)))
            {
                mc_at_replay(_TRUE, "read data failed.");
                break;
            }
            
            if (!nvram_external_write_data(
                    NVRAM_EF_PORT_SETTING_LID,
                    1,
                    (INT8U*)&ps,
                    sizeof(port_setting_struct)))
            {
                mc_at_replay(_TRUE, "save data failed.");
            }
        }
        break;
        
    case AT_EM_HELP:
        {
            CHAR strbuf[64] = {0};
            INT32U i, j, k;

            k = sizeof(enableVal)/sizeof(enableVal[0]);
        #if defined(WIN32)
            for(i=0, j=0; i<k; i++)
                j += _snprintf(
                        strbuf+j,
                        63-j,
                        "0x%02x%s",
                        enableVal[i], 
                        (i==(k-1)) ? "" : ", ");
        #else
            for(i=0, j=0; i<k; i++)
                j += snprintf(
                        strbuf+j,
                        63-j,
                        "0x%02x%s",
                        enableVal[i], 
                        (i==(k-1)) ? "" : ", ");
        #endif
            
            mc_at_replay(_TRUE, "%s: (%s)", vp->name, strbuf);
        }
        break;
        
    case AT_EM_READ:
        {
            port_setting_struct ps;
            
            memset((void*)&ps, 0, sizeof(port_setting_struct));
            
            if (nvram_external_read_data(
                    NVRAM_EF_PORT_SETTING_LID,
                    1,
                    (INT8U*)&ps,
                    sizeof(port_setting_struct)))
            {
                mc_at_replay(_TRUE, "0x%02x", ps.tst_port_ps);
            }
            else
            {
                mc_at_replay(_TRUE, "read data failed.");
            }
        }
        break;
        
    case AT_EM_ACTIVE:
        vp->result = AT_RST_PARAM_ERR;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
}

/*******************************************************************************
** 函数: at_isink
** 功能: AT命令, 控制4个背光灯
** 入参: vp
** 返回: 无  at$isink=(0,1)
** 作者: wasfayu
*******/
static void at_isink(AtParam_t *vp)
{
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (2 != vp->argc || NULL == vp->argv[0].pos || NULL == vp->argv[1].pos)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            INT32U command;
            
            if (vp->argv[0].len == 1 &&
                vp->argv[0].pos[0] >= '0' &&
                vp->argv[0].pos[0] <= '9')
                command = atoi(vp->argv[0].pos);
            else
                command = 0xFFFF;

            if (command >= 2)
                vp->result = AT_RST_PARAM_ERR;
            else
                MsgCmd_isink((kal_bool)command);
        }
        break;
        
    case AT_EM_HELP:
        mc_at_replay(_TRUE, "%s: (0,1)", vp->name);
        break;
        
    case AT_EM_READ:
    case AT_EM_ACTIVE:        
        vp->result = AT_RST_PARAM_ERR;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
}

/*******************************************************************************
** 函数: at_adorecd
** 功能: AT命令, 控制录像
** 入参: vp
** 返回: 无  at$adorecd=(0,1),time,number
** 作者: wasfayu
*******/
static void at_adorecd(AtParam_t *vp)
{
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (2 > vp->argc || 3 < vp->argc)
            vp->result = AT_RST_PARAM_ERR;
        else
        {

        }
        break;
        
    case AT_EM_HELP:
        mc_at_replay(_TRUE, "%s: (0,1),time,number", vp->name);
        break;
        
    case AT_EM_READ:
    case AT_EM_ACTIVE:        
        vp->result = AT_RST_PARAM_ERR;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
}

/*******************************************************************************
** 函数: at_vdorecd
** 功能: AT命令, 控制录像
** 入参: vp
** 返回: 无  at$vdorecd=(0,1),time,number
** 作者: wasfayu
*******/
static void at_vdorecd(AtParam_t *vp)
{
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (2 > vp->argc || 3 < vp->argc)
            vp->result = AT_RST_PARAM_ERR;
        else
        {

        }
        break;
        
    case AT_EM_HELP:
        mc_at_replay(_TRUE, "%s: (0,1),time,number", vp->name);
        break;
        
    case AT_EM_READ:
    case AT_EM_ACTIVE:        
        vp->result = AT_RST_PARAM_ERR;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
}

/*******************************************************************************
** 函数: at_capture
** 功能: AT命令, 控制拍照
** 入参: vp
** 返回: 无  at$capture[=number]
** 作者: wasfayu
*******/
static void at_capture(AtParam_t *vp)
{
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (1 != vp->argc || NULL == vp->argv[0].pos)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            
        }
        break;
        
    case AT_EM_HELP:
        mc_at_replay(_TRUE, "%s: (mms number)", vp->name);
        break;
        
    case AT_EM_READ:
    case AT_EM_ACTIVE:        
        vp->result = AT_RST_PARAM_ERR;
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
}

/*******************************************************************************
** 函数: msgcmd_AtCmdLineParse
** 功能: AT命令行解析
** 入参: argOut 解析输出
**       cmdStr 命令行字符
** 返回: 参数个数
** 作者: wasfayu
*******/
static INT16U msgcmd_AtCmdLineParse(ArgItem_t *argItem, CHAR *cmdStr)
{
    _BOOL dQuote = _FALSE, next = _FALSE;
    INT16U argc;
    
    if (NULL != argItem || NULL == cmdStr)
        return 0;

    argc = 0;
    
    do{
        while(isspace(*cmdStr))
            *cmdStr++ = '\0';

        if(*cmdStr == '\0')
            break;
        
        argItem[argc].pos = cmdStr;
        next = _FALSE;
        
        while(*cmdStr && !next)
        {
            if('\"' != *cmdStr && dQuote)
            {
                argItem[argc].len ++;
                cmdStr ++;
                continue;
            }
            
            switch(*cmdStr)
            {
            case ',':
                *cmdStr++ = '\0';
                next = _TRUE;
                break;
                
            case '\"':
                if(!dQuote)
                {
                    argItem[argc].pos++;
                    dQuote = _TRUE;
                    *cmdStr++ = '\0';
                }
                else
                {
                    dQuote = _FALSE;
                    *cmdStr++ = '\0';
                    
                    while(isspace(*cmdStr))
                        *cmdStr++ = '\0';
                }
                break;
                
            case '\r':
            case '\n':
                *cmdStr++ = '\0';
                break;
                
            default:
                if(*cmdStr == ' ' && !dQuote)
                {
                    *cmdStr = '\0';
                }
                else
                {
                    argItem[argc].len ++;                        
                }
                
                cmdStr ++;
                break;
            }
        }

        mc_trace(
            "[SPLIT] [%d, len=%d] %s", 
            argc, 
            argItem[argc].len,
            argItem[argc].pos);

        argc++;
        if(argc >= CMD_ARG_ITEM_MAX)
            break;
        
    }while(*cmdStr);

    //肯定有错误
    if(dQuote)
    {
        mc_trace("[SPLIT] quote error. argc=%d", argc);
        argc = 0;
    }
    
    return argc;
}

/*******************************************************************************
** 函数: MsgCmd_AtCmdProc
** 功能: 处理自定义AT命令
** 参数: origStr  -- AT命令行参数, 
**                   如果不是自定义的AT指令则不可破坏cmd_string中的内容
** 返回: 是否是自定义AT指令
** 作者: wasfayu
*******/
_BOOL MsgCmd_AtCmdProc(CHAR *origStr)
{        
    if (0 == app_strnicmp(origStr, "AT", 2))
    {
        AtExecMode_e em = AT_EM_WRONG;
        INT32U len;
        CHAR ch, *pos;
        
        pos = origStr + 2;
        len = 0;
        
        while(len < AT_CMD_STRING_MAX)
        {
            ch = *pos++;
            if (ch == '?')
            {
                if(*pos++ == '\r' && *pos++ == '\0')
                    em = AT_EM_READ;
                
                break;
            }
            else if (ch == '=')
            {
                if (*pos == '?' && *(pos+1) == '\r' && *(pos+2) == '\0')
                    em = AT_EM_HELP;
                else if(*pos != '\0' && *pos != '\r' && *pos != '\n')
                    em = AT_EM_SET_OR_EXEC ;
                
                break;
            }
            else if (ch == '\r' || ch == '\n')
            {
                if(*pos++ == '\0')
                    em = AT_EM_ACTIVE;
                
                break;
            }
            else if (ch == '\0')
                break;
            else
                len ++;
        }
        
        if(em != AT_EM_WRONG)
        {
            INT32U i;
            
            for (i=0; i<sizeof(command_table)/sizeof(command_table[0]); i++)
            {                
                if (len == command_table[i].bodyLen &&
                    0   == app_strnicmp(origStr+2, (CHAR*)command_table[i].bodyStr, len))
                {
                    AtParam_t *ap = (AtParam_t*)OslMalloc(sizeof(AtParam_t));

                    memset(ap, 0, sizeof(AtParam_t));
                    ap->name  = command_table[i].bodyStr;
                    ap->index = command_table[i].index;
                    ap->mode  = em;
                    ap->result= AT_RST_SUCCESS;

                    //parse
                    if (AT_EM_SET_OR_EXEC == em)
                        ap->argc = msgcmd_AtCmdLineParse(ap->argv, pos);


                    //execute
                    if ((AT_EM_SET_OR_EXEC == em && 0 == ap->argc) ||
                        (AT_EM_SET_OR_EXEC != em && 0 != ap->argc))
                        ap->result = AT_RST_PARAM_ERR;
                    else if(command_table[i].callback)
                        command_table[i].callback(ap);

            
                    //replay
                    switch(ap->result)
                    {
                    case AT_RST_SUCCESS:
                        mc_at_replay(_TRUE, "OK");
                        break;
                    case AT_RST_NO_REPLAY:
                        /* do nothing */
                        break;
                    default:
                        mc_at_replay(_TRUE, "ERROR: %d", ap->result);
                        break;
                    }
                    
                    OslMfree(ap);
                    return _TRUE; //终止for循环
                }
            }
        }
    }

    return _FALSE;
}


#endif/*__MESSAGE_COMMAND_SUPPORT__*/

