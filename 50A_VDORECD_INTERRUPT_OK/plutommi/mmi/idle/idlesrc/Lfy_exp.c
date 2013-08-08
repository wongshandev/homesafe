
#if defined(__LEIFAYU__)
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "BootupSrvGprot.h"
#include "alarmsrvgprot.h"
#include "bootupsrvgprot.h"
#include "shutdownsrvgprot.h"
#include "uart_sw.h"
#include "nvram_common_defs.h"
#include "nvram_interface.h"
#include "TimerEvents.h"
#include "DateTimeGprot.h"
#include "custom_mmi_default_value.h"
#include "med_api.h"
#include "med_struct.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_camera.h"
#include "mdi_video.h"
#include "fs_gprot.h"
#include "mmi_rp_srv_sms_def.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_idle_def.h"
#include "mmi_rp_srv_reminder_def.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "phbsrvgprot.h"
#include "simctrlsrvgprot.h"
#include "nwinfosrvgprot.h"
#include "charbatsrvgprot.h"
#include "filemgrsrvgprot.h"
#include "shutdownsrvgprot.h"
#include "bootupsrvgprot.h"
#include "modeswitchsrvgprot.h"
#include "alarmsrvgprot.h"
#include "SettingProt.h"
#include "imeisrvgprot.h"
#include "DateTimeGprot.h"
#include "SmsAppGprot.h"
#include "stack_ltlcom.h"
#include "nvram_struct.h"
#include "gpiosrvgprot.h"
#include "fs_func.h"
#include "TimerEvents.h"
#include "med_api.h"
#include "drv_hisr.h"
#if !defined(WIN32)
#include "accdet_hw.h"
#include "accdet_sw.h"
#endif
#include "Eint_internal.h"
#include <ctype.h>
#include <string.h>
#include "app_str.h"
#include "app_ltlcom.h"
#include "app_asyncfile.h"
#include "ucmsrvgprot.h"
#include "kal_trace.h"
#include "GeneralDeviceGprot.h"
#include "CameraApp.h"
#include "UcmGProt.h"
#include "UcmCoreProt.h"
#include "mmssrvgprot.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "nwusabsrvgprot.h"
#include "./lfy_exp.h"


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

static void at_disksize(AtParam_t *vp);


static MsgCmdRecdArg *msgcmd_GetVdoRecdArgs(void);


#define MsgCmd_Malloc(s, v) MsgCmd_MemAlloc(s, v, __FUNCTION__, __LINE__)
#define MsgCmd_Mfree(p) MsgCmd_MemFree(p, __FUNCTION__, __LINE__)

/* 定时器ID定义 */
#define MSGCMD_TIMER_REBOOT       (TIMER_ID_LFY_BASE + 0)
#define MSGCMD_TIMER_SHUTDOWN     (TIMER_ID_LFY_BASE + 1)
#define MSGCMD_TIMER_FACTORY      (TIMER_ID_LFY_BASE + 2)
#define MSGCMD_TIMER_INT_RECHECK  (TIMER_ID_LFY_BASE + 3)
#define MSGCMD_TIMER_VDO_CHECK    (TIMER_ID_LFY_BASE + 4)
#define TIMER_DTMF_KEY_DETECT     (TIMER_ID_LFY_BASE + 5)
#define TIMER_DTMF_DELAY_EXEC     (TIMER_ID_LFY_BASE + 6)

/* 消息ID定义 */
#define MSG_ID_MC_VDORECD_REQ     (MSG_ID_LFY_BASE + 0)
#define MSG_ID_MC_ADORECD_REQ     (MSG_ID_LFY_BASE + 1)
#define MSG_ID_MC_CAPTURE_REQ     (MSG_ID_LFY_BASE + 2)
#define MSG_ID_MC_SEND_MMS_REQ    (MSG_ID_LFY_BASE + 3)
#define MSG_ID_MC_CONT_RECD_VDO   (MSG_ID_LFY_BASE + 4)
#define MSG_ID_MC_EXT_INTERRUPT   (MSG_ID_LFY_BASE + 5)
#define MSG_ID_DTMF_ANSWER_CALL   (MSG_ID_LFY_BASE + 6)
#define MSG_ID_DTMF_EXEC_CMD_REQ  (MSG_ID_LFY_BASE + 7)


#ifndef lfy_trace
#define lfy_trace(fmt, ...)  kal_prompt_trace(0, fmt, ##__VA_ARGS__)
#endif

#ifndef at_replay
#define at_replay(stuff, fmt, ...) do {        \
		at_print(stuff, fmt, ##__VA_ARGS__);   \
		lfy_trace(fmt, ##__VA_ARGS__);         \
	}while(0)
#endif 

//自定义AT命令表
static const AtCmdTab_t command_table[AT_CMD_IDX_MAX] = {
    {"$reboot",       7, AT_CMD_REBOOT,       at_reboot      },
    {"$shutdown",     9, AT_CMD_SHUTDOWN,     at_shutdown    },
    {"$catch",        6, AT_CMD_CATCH,        at_catch       },
    {"$adorecd",      8, AT_CMD_ADORECD,      at_adorecd     },
    {"$vdorecd",      8, AT_CMD_VDORECD,      at_vdorecd     },
    {"$capture",      8, AT_CMD_CAPTURE,      at_capture     },
    {"$disksize",     9, AT_CMD_DISKSIZE,     at_disksize    },
};

#if 1
#define CB_LOG_BUFFER_SZ        (256)   //BYTE
#define CB_LOG_FILE_LIMITED     (1024*100)  //BYTE

static U32 logCount = 0;
static FS_HANDLE logFH = -1;
static WCHAR logFile[] = {L"C:\\cb_log.txt"};

/*******************************************************************************
** 函数: cb_close_log_file
** 功能: 关闭日志函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void cb_close_log_file(void)
{
    if (logFH >= FS_NO_ERROR)
        FS_Close(logFH);

    logFH = -1;
}

/*******************************************************************************
** 函数: cb_write_log
** 功能: 日志打印函数, 写入到磁盘的文件上
** 参数: fmt -- 打印格式控制字符串
** 返回: 无
** 作者: wasfayu
*******/
void cb_write_log(const char *fmt, ...)
{
    U32 length, written = 0;
    char buffer[CB_LOG_BUFFER_SZ] = {0};
    va_list list;

#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
        return;
#endif
    
    if (-1 == logFH)
    {
        logFile[0] = SRV_FMGR_CARD_DRV;
        if(!srv_fmgr_drv_is_accessible(SRV_FMGR_CARD_DRV))
            logFile[0] = SRV_FMGR_PUBLIC_DRV;

        logFH = FS_Open(logFile, FS_READ_WRITE|FS_CREATE);
        if (logFH <= FS_NO_ERROR)
            return;
    }

    va_start(list, fmt);
#if defined(WIN32)
    length = _vsnprintf(buffer, CB_LOG_BUFFER_SZ, fmt, list);
#else
    length = vsnprintf(buffer, CB_LOG_BUFFER_SZ, fmt, list);
#endif
    va_end(list);

    if (length)
    {
        U32 tlen;
        applib_time_struct t;
        char tstr[32] = {0};

        if (FS_GetFileSize(logFH, &tlen) >= FS_NO_ERROR)
        {
            if (tlen >= CB_LOG_FILE_LIMITED)
            {
                WCHAR backup[] = {L"C:\\cb_back.log"};
                
                FS_Close(logFH);
                logFile[0] = (WCHAR)SRV_FMGR_PUBLIC_DRV;
                
                backup[0] = logFile[0];
                FS_Delete(backup);
                FS_Rename(logFile, backup);
                
                logFH = FS_Open(logFile, FS_READ_WRITE|FS_CREATE);
                if (logFH <= FS_NO_ERROR)
                    return;
            }
        }
        else
        {
            FS_Close(logFH);
            logFH = -1;
            return;
        }

        applib_dt_get_date_time(&t);
        tlen = sprintf(tstr, "\t<%02d:%02d:%02d,0x%X>\n", t.nHour, t.nMin, t.nSec, ++logCount);
        FS_Seek(logFH, 0, FS_FILE_END);
        FS_Write(logFH, buffer, length, &written);
        FS_Write(logFH, tstr, tlen, &length);
        FS_Commit(logFH);
        written = written + length;
    }

    return;
}

#ifdef lfy_trace
#undef lfy_trace
#endif
#define lfy_trace(fmt, ...) do{cb_write_log(fmt,##__VA_ARGS__);kal_prompt_trace(0,fmt,##__VA_ARGS__);}while(0)
#endif

/*******************************************************************************
** 函数: MsgCmd_GetInteger
** 功能: 从给定长度的字符串中获取一个32位无符号整数
** 参数: ps  操作类型
**       sl  字符串长度
**       type  字符串类型
** 返回: 获取成功返回对应的值, 失败返回-1
** 作者: wasfa
*******/
U32 MsgCmd_GetInteger(const char *ps, U16 sl, StringType_e type)
{
#define INVALID_INT32U_VAL  (0xFFFFFFFF)

    U32 val = 0;

    if(sl == 0)
        return INVALID_INT32U_VAL;
    
    switch(type)
    {
    case STR_TYPE_2:
        while(sl--)
        {
            val *= 2;
            
            if(*ps >= '0' && *ps <= '1')
                val += *ps - '0';
            else
                return INVALID_INT32U_VAL;

            ps++;
        }
        break;
    case STR_TYPE_10:
        while(sl--)
        {
            val *= 10;
            
            if(*ps >= '0' && *ps <= '9')
                val += *ps - '0';
            else
                return INVALID_INT32U_VAL;
            
            ps++;
        }
        break;
    case STR_TYPE_8:
        while(sl--)
        {
            val *= 8;
            
            if(*ps >= '0' && *ps <= '8')
                val += *ps - '0';
            else
                return INVALID_INT32U_VAL;
            
            ps++;
        }
        break;
    case STR_TYPE_16:
        while(sl--)
        {
            val *= 16;
            
            if(*ps >= '0' && *ps <= '9')
                val += *ps - '0';
            else if(*ps >= 'a' && *ps <= 'f')
                val += *ps - 'a' + 10;//a-a?
            else if(*ps >= 'A' && *ps <= 'F')
                val += *ps - 'A' + 10;
            else
                return INVALID_INT32U_VAL;
            
            ps++;
        }
        break;
    default:
        return INVALID_INT32U_VAL;
    }

    return val;
    
#undef INVALID_INT32U_VAL
}

/*******************************************************************************
** 函数: MsgCmd_Atoi
** 功能: 系统函数atoi的包装
** 参数: 
** 返回: 
** 作者: wasfa
*******/
S32 MsgCmd_Atoi(const char *nptr)
{
    if (0 == app_strnicmp((char*)nptr, "0x", 2))
    {
        nptr += 2;
        return (S32)MsgCmd_GetInteger((const char *)nptr, strlen(nptr), STR_TYPE_16);
    }
    
    return atoi(nptr);
}

/*******************************************************************************
** 函数: MsgCmd_IsDigStr
** 功能: 判断是否是数字字符串, 0~9组成
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsDigStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isdigit(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** 函数: MsgCmd_IsXdigStr
** 功能: 判断是否是16进制字符串, 0~9, A~F, a~f组成
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsXdigStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isxdigit(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** 函数: MsgCmd_IsXdigFmtStr
** 功能: 是否是16进制格式开头的字符串, 即以0x开头的数字字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsXdigFmtStr(const char *ps, U32 sl)
{
    if(sl >= 3 && \
        0 == app_strnicmp((char*)ps, "0x", 2) &&
        MsgCmd_IsXdigStr((const char*)(ps+2), sl-2))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*******************************************************************************
** 函数: MsgCmd_IsAlpNumstr
** 功能: 是否是字母数字字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsAlpNumStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isalnum(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** 函数: MsgCmd_IsAlphaStr
** 功能: 是否是字母字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsAlphaStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isalpha(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** 函数: MsgCmd_IsSpaceStr
** 功能: 是否是空白字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsSpaceStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isspace(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** 函数: MsgCmd_IsLowerStr
** 功能: 是否是小写字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsLowerStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!islower(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** 函数: MsgCmd_IsUpperStr
** 功能: 是否是大写字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
MMI_BOOL MsgCmd_IsUpperStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isupper(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/* 复制自 linux V3.2 source code 函数 strpbrk
 *
 * strpbrk - Find the first occurrence of a set of characters
 * @cs: The string to be searched
 * @ct: The characters to search for
 */
static char *msgcmd_strpbrk(const char *cs, const char *ct)
{
	const char *sc1, *sc2;

	for (sc1 = cs; *sc1 != '\0'; ++sc1) {
		for (sc2 = ct; *sc2 != '\0'; ++sc2) {
			if (*sc1 == *sc2)
				return (char *)sc1;
		}
	}
	return NULL;
}

/* 复制自 linux V3.2 source code 函数 strsep
 * 类似早期的strtok函数, 不过strsep更具安全性.
 *
 * strsep - Split a string into tokens
 * @s: The string to be searched
 * @ct: The characters to search for
 *
 * strsep() updates @s to point after the token, ready for the next call.
 *
 * It returns empty tokens, too, behaving exactly like the libc function
 * of that name. In fact, it was stolen from glibc2 and de-fancy-fied.
 * Same semantics, slimmer shape. ;)
*/
char *MsgCmd_strsep(char **s, const char *ct)
{
	char *sbegin = *s;
	char *end;

	if (sbegin == NULL)
		return NULL;

	end = msgcmd_strpbrk(sbegin, ct);
	if (end)
		*end++ = '\0';
	*s = end;
	return sbegin;
}

/*******************************************************************************
** 函数: MsgCmd_SendIlm2Mmi
** 功能: 发送消息到MMI模块
** 参数: msgid  -- 消息ID
**       msg    -- 消息
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SendIlm2Mmi(msg_type msgid, void *msg)
{
    MYQUEUE message;
    
    message.oslMsgId = msgid;
    message.oslDataPtr = (local_para_struct *)msg;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;
    mmi_msg_send_ext_queue(&message);  
}

/*******************************************************************************
** 函数: MsgCmd_SendIlmMsg
** 功能: 从src模块发送消息msgid到dest模块, 经过sap进行中转
** 参数: src    -- 可用stack_get_active_module_id()来获取
**       dest   -- 目的模块
**       sap    -- 中转, 可以填INVALID_SAP
**       msgid  -- 消息ID
**       msg    -- 消息
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SendIlmMsg(
    module_type src,
    module_type dest, 
    sap_type sap, 
    msg_type msgid, 
    void *msg)
{
    ilm_struct *ilm_ptr = NULL;
    //module_type src = MOD_MMI;//stack_get_active_module_id();//只能是MOD_MMI
    
    ilm_ptr = allocate_ilm(src);
    ilm_ptr->src_mod_id = src;
    ilm_ptr->dest_mod_id = dest;
    ilm_ptr->sap_id = sap;
    ilm_ptr->msg_id = msgid;
    ilm_ptr->local_para_ptr = (local_para_struct *)msg;
    ilm_ptr->peer_buff_ptr = NULL;
    
    msg_send_ext_queue(ilm_ptr);
}

/*******************************************************************************
** 函数: MsgCmd_MemAlloc
** 功能: 申请内存, 用于大块内存申请, 必须用host_mfree_ext来释放.
** 参数: s 表示需要申请的内存字节长度.
**       v 表示将申请来的内存区间初始化为该值.
** 返回: 返回申请到的内存地址.
** 作者: wasfayu
*******/
void *MsgCmd_MemAlloc(U32 s, U8 v, const char* file, U32 line)
{
    void *memptr = NULL;

    if (s)
    {
        //memptr = med_alloc_ext_mem(s);
        memptr = OslMalloc(s);
        if (memptr)
        {
            memset(memptr, v, s);            
        }
    }

	return memptr;
}

/*******************************************************************************
** 函数: MsgCmd_MemFree
** 功能: 释放有MsgCmd_MemAlloc申请来的内存
** 参数: memptr   表示需要释放的内存地址.
** 返回: 无
** 说明: med_free_ext_mem是个很变态的函数, 居然要取地址之后再求地址. 乏克...
** 作者: wasfayu
*******/
void MsgCmd_MemFree(void *p, const char* file, U32 line)
{
    //med_free_ext_mem(&p);
    OslMfree(p);
}

/*******************************************************************************
** 函数: MsgCmd_ConstructPara
** 功能: 参数构造buffer
** 参数: sz   表示需要使用的buffer大小.
** 返回: 无
** 作者: wasfayu
*******/
void *MsgCmd_ConstructPara(U32 sz)
{
    return construct_local_para(sz, TD_CTRL | TD_RESET);
}

/*******************************************************************************
** 函数: MsgCmd_DestructPara
** 功能: 参数buffer释放
** 参数: ptr   表示需要释放的参数buffer地址.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_DestructPara(void *ptr)
{
    free_local_para((local_para_struct*)ptr);
}

/*******************************************************************************
** 函数: MsgCmd_GetCallCount
** 功能: 获取电话个数
** 参数: 无
** 返回: 返回电话个数
** 作者: wasfayu
*******/
S32 MsgCmd_GetCallCount(void)
{
    return srv_ucm_query_call_count(
                SRV_UCM_CALL_STATE_ALL,
                SRV_UCM_CALL_TYPE_ALL,
                NULL);
}

/*******************************************************************************
** 函数: MsgCmd_IsSdCardExist
** 功能: 判断存储卡是否存在
** 参数: 无
** 返回: 是否存在
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsSdCardExist(void)
{
    return srv_fmgr_drv_is_accessible(SRV_FMGR_CARD_DRV);
}

/*******************************************************************************
** 函数: MsgCmd_GetDiskFreeSize
** 功能: 获取磁盘剩余空间
** 参数: drive, 磁盘盘符, 0x43~0x47
** 返回: 剩余空间的大小, byte为单位
** 作者: wasfayu
*******/
U32 MsgCmd_GetDiskFreeSize(S32 drive)
{
    FS_DiskInfo disk_info;
    WCHAR path[8] = {0};
    U32 size;

    kal_wsprintf(path, "%c:\\", drive);
    
    if (FS_GetDiskInfo(
            path,
            &disk_info,
            FS_DI_BASIC_INFO | FS_DI_FREE_SPACE) >= FS_NO_ERROR)
    {
        size = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        return size;
    }

    return 0;
}

/*******************************************************************************
** 函数: MsgCmd_CheckValidDrive
** 功能: 检查给定的盘符是否已挂载
** 参数: 盘符, C/D/E/F...
** 返回: 驱动盘可供使用
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CheckValidDrive(U32 drive)
{
    return (MMI_BOOL)(FS_NO_ERROR == FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM));
}

/*******************************************************************************
** 函数: MsgCmd_GetUsableDrive
** 功能: 获取系统可用的存储设备盘符
** 参数: 无
** 返回: 返回盘符 0x43~0x47
** 作者: wasfayu
*******/
S32 MsgCmd_GetUsableDrive(void)
{
    S32 drive = SRV_FMGR_CARD_DRV;

    if(!srv_fmgr_drv_is_accessible(drive))
    {
        drive = SRV_FMGR_PUBLIC_DRV;
    }

    return drive;
}

/*******************************************************************************
** 函数: MsgCmd_GetSystemDrive
** 功能: 获取系统盘的盘符
** 参数: 无
** 返回: Success:                0x43~0x47 (A~G)
**       Error:                  RTF_PARAM_ERROR        (-2)
**                               RTF_DRIVE_NOT_FOUND    (-4)
** 作者: wasfayu
*******/
S32 MsgCmd_GetSystemDrive(void)
{
    return SRV_FMGR_SYSTEM_DRV;
}

/*******************************************************************************
** 函数: MsgCmd_GetFileSize
** 功能: 获取文件大小
** 参数: path - 文件绝对路径
** 返回: 文件大小
** 作者: wasfayu
*******/
U32 MsgCmd_GetFileSize(WCHAR *path)
{
    return applib_get_file_size(path);
}

/*******************************************************************************
** 函数: MsgCmd_CombineFilePath
** 功能: 组成文件的绝对路径, 目录深度为一级
** 参数: pathbuffer     -- 装载输出路径的buffer
**       length_in_byte -- out的长度, 以字节为单位, 长度应该大于32个字节以上
**       folder         -- 文件夹的名字, 如 L"audio"
**       ext_name       -- 扩展名的名字, 如 L".mp3"
** 返回: 返回文件名地址, 即没有前面的path, 指向pathbuffer中某个元素的地址
** 作者: wasfayu
*******/
WCHAR *MsgCmd_CombineFilePath(
    WCHAR *pathbuffer,
    U16   length_in_byte,
    const WCHAR *folder,
    const WCHAR *ext_name)
{	
	applib_time_struct mt;
    WCHAR *filename;

    ASSERT(NULL != pathbuffer);
    
	memset(pathbuffer, 0, length_in_byte);

    //先打印路径
    if (NULL == folder)
        kal_wsprintf(
    		(WCHAR*)pathbuffer, 
    		"%c:\\", 
    		MsgCmd_GetUsableDrive());
    else
    	kal_wsprintf(
    		(WCHAR*)pathbuffer, 
    		"%c:\\%w\\", 
    		MsgCmd_GetUsableDrive(),
    		folder);

    //再打印文件名
    filename = pathbuffer + app_ucs2_strlen((const kal_int8 *)pathbuffer);
    if (NULL != ext_name)
    {
    	applib_dt_get_date_time(&mt);
    
        kal_wsprintf(
            filename,
            "%04d-%02d-%02d %02d%02d%02d %08X%w",
    		mt.nYear,
    		mt.nMonth,
    		mt.nDay,
    		mt.nHour,
    		mt.nMin,
    		mt.nSec,
    		MsgCmd_GetCurrentTime(),
    		ext_name);	
    }

	return filename;
}

/*******************************************************************************
** 函数: MsgCmd_GetCurrentTime
** 功能: 获取系统当前的运行时间
** 参数: 无
** 返回: 运行时间
** 作者: wasfayu
*******/
U32 MsgCmd_GetCurrentTime(void)
{
    return app_getcurrtime();
}

/*******************************************************************************
** 函数: MsgCmd_GetDateTime
** 功能: 获取系统当前的时间
** 参数: 时间结构体
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_GetDateTime(applib_time_struct *t)
{    
    applib_dt_get_date_time(t);
}

/*******************************************************************************
** 函数: MsgCmd_SetDateTime
** 功能: 设置系统当前的时间
** 参数: 时间结构体
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SetDateTime(applib_time_struct *t)
{
    mmi_dt_set_rtc_dt((MYTIME *)t);
}

/*******************************************************************************
** 函数: MsgCmd_IsDateTimeValid
** 功能: 判断时间是否有效
** 参数: t  -- 
** 返回: 是否有效
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t)
{
    return applib_dt_is_valid(t);
}

/*******************************************************************************
** 函数: MsgCmd_DeleteFileFront
** 功能: 删除文件的前部
** 入参: fullPathName -- 文件的绝对路径名, UCS格式, 如 "D:\\myfile.txt"
**       deletesz     -- 删除大小, 即从文件头开始删除deletesz个字节的数据
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_DeleteFileFront(const WCHAR *fullPathName, U32 deletesz)
{
    MMI_BOOL result;
    U8 *buffer;
    const U32 bufsz = 1024*2;
    U32 count;
    S32 writepos = 0;
    FS_HANDLE fd;

    if (NULL == fullPathName || 0 == deletesz)
    {
        lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
        return MMI_TRUE;
    }
    
    fd = FS_Open(fullPathName, FS_READ_WRITE);
    if (fd < FS_NO_ERROR)
    {
        lfy_trace("%s, L:%d.fd=%d.", __FUNCTION__, __LINE__, fd);
        return MMI_FALSE;
    }
    
    buffer = (U8*)MsgCmd_Malloc(bufsz, 0); //med_alloc_ext_mem
    do{
        result = MMI_FALSE;
            
        //定位到读的位置
        if(FS_Seek(fd, deletesz, FS_FILE_BEGIN) < FS_NO_ERROR)
        {
            lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
            return MMI_FALSE;
        }

        if(FS_Read(fd, buffer, bufsz, &count) < FS_NO_ERROR)
        {
            lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
            break;
        }

        if(!count)
        {
            lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
            break;
        }

        deletesz += count;
        lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
        
        //定位到写的位置
        if(FS_Seek(fd, writepos, FS_FILE_BEGIN) < FS_NO_ERROR)
        {
            lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
            break;
        }

        if(FS_Write(fd, buffer, count, &count) < FS_NO_ERROR)
        {
            lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
            break;
        }

        if(!count)
        {
            lfy_trace("%s, L:%d.", __FUNCTION__, __LINE__);
            break;
        }

        writepos += count;

        result = MMI_TRUE;
        
    }while(1);

    MsgCmd_Mfree(buffer);
    
    FS_Seek(fd, writepos, FS_FILE_BEGIN);
    FS_Truncate(fd);
    FS_Commit(fd);
    FS_Close(fd);

    return result;
}

/*******************************************************************************
** 函数: msgcmd_DeleteOldFile
** 功能: 根据文件列表中的记录删除文件
** 入参: fullname   -- 录音文件的绝对路径文件名, UCS格式
**       cmpSzKB    -- 需要删除的总大小, KB
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
static S32 msgcmd_DeleteOldFile(const WCHAR *list_file_name, U32 cmpSzKB)
{
    U32       line_len, tmpSz=0;
    U32       total_size = 0;
    S32       ret = 0, count = 0, drive;
    FS_HANDLE main_fd, fd;
    char     *buffer;
    WCHAR    *wBuffer;
    U32       bufsz, wBufSz;

    if (NULL == list_file_name)
        return 0;

    bufsz  = MSGCMD_FILE_PATH_LENGTH + 1;
    wBufSz = bufsz * sizeof(WCHAR);

    //unicode
    wBuffer= MsgCmd_Malloc(wBufSz, 0);

    //drive
    drive = MsgCmd_GetUsableDrive();
    kal_wsprintf(wBuffer, "%c:\\%w", drive, list_file_name);
    
    main_fd = FS_Open((const WCHAR *)wBuffer, FS_READ_ONLY);
    if(main_fd < FS_NO_ERROR)
    {
    	MsgCmd_Mfree(wBuffer);
        lfy_trace("%s,L:%d. main_fd=%d.", __FUNCTION__, __LINE__, main_fd);
	    return 0;
  	}

	buffer = MsgCmd_Malloc(bufsz, 0);
	FS_Seek(main_fd, 0, FS_FILE_BEGIN);
    do{
        memset(buffer, 0, bufsz);
		line_len = 0;
        applib_file_read_line(main_fd, (U8 *)buffer, bufsz, &line_len, &ret);

		if (line_len == 0)
			break;

        lfy_trace("read: %s. line_len=%d. ret=%d.", buffer, line_len, ret);
        line_len = strlen(buffer);
        
        tmpSz += line_len;
        if(ret < 0)
            break;
        else
        {     
            U32 fsz;
            
            //去掉尾巴上的回车换行符
            while(line_len)
            {
                lfy_trace("line_len=%d. buffer[line_len-1]=0x%x.", line_len, buffer[line_len-1]);

                //UCS--> 0x0A, 0x0D, 0x0A0D, 0x0D0A
                if (buffer[line_len-1] == '\r' || buffer[line_len-1] == '\n')
                    buffer[line_len-1] = '\0';
                else
                    break;
                
                line_len --;
            }

            memset(wBuffer, 0, wBufSz);
            app_asc_str_to_ucs2_str((S8*)wBuffer, buffer);
            fd = FS_Open((const WCHAR*)wBuffer, FS_READ_ONLY);
            lfy_trace("read line: %s. fd=%d.", buffer, fd);
            if(fd >= FS_NO_ERROR)
            {
                if(FS_GetFileSize(fd, &fsz) >= 0)
                    total_size += fsz>>10;
                    
                FS_Close(fd);
                FS_Delete((const WCHAR*)wBuffer);
                count ++;
                lfy_trace("%s,L:%d, total_size=%dKB.cmpSzKB=%dKB.", __FUNCTION__, __LINE__, total_size, cmpSzKB);
                
                if(total_size >= cmpSzKB)
                    ret = 1;
            }
        }
        
    }while(ret == 0);

	FS_Close(main_fd);
	MsgCmd_Mfree(buffer);

    memset(wBuffer, 0, wBufSz);
    kal_wsprintf(wBuffer, "%c:\\%w", drive, list_file_name);
    MsgCmd_DeleteFileFront(wBuffer, tmpSz);
    
    MsgCmd_Mfree(wBuffer);

    lfy_trace("%s,L:%d, tmpSz=%d, count=%d.", __FUNCTION__, __LINE__, tmpSz, count);
    return ret;
}

/*******************************************************************************
** 函数: msgcmd_RecordFileName
** 功能: 将某个文件的UCS格式名字pdata写入到fname文件中去
** 入参: fname   -- 文件名, UCS格式
**       ascname -- 待写入的文件名, ASCII格式
**       asclen  -- 待写入的文件名长度
** 返回: 是否写入成功
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_RecordFileName(const WCHAR *fname, const char *ascname, U32 asclen)
{
    U32       bufsz;
    MMI_BOOL  result;
    WCHAR    *buffer;
    FS_HANDLE fd;

    if (NULL == fname || NULL == ascname || 0 == asclen)
        return MMI_FALSE;

    bufsz  = (MSGCMD_FILE_PATH_LENGTH+1)*sizeof(WCHAR);
    buffer = (WCHAR*)MsgCmd_Malloc(bufsz, 0);

    kal_wsprintf(buffer, "%c:\\%w", MsgCmd_GetUsableDrive(), fname);
    result = MMI_FALSE;
    
    fd = FS_Open(buffer, FS_READ_WRITE|FS_CREATE);    
    if(fd >= FS_NO_ERROR)
    {
        FS_Seek(fd, 0, FS_FILE_END);
        FS_Write(fd, (void*)ascname, asclen, NULL);
        FS_Write(fd, "\r\n", 2, NULL);
        FS_Commit(fd);
        FS_Close(fd);
        
        result = MMI_TRUE;
    }
    
    MsgCmd_Mfree(buffer);
    
    return result;
}

/*******************************************************************************
** 函数: MsgCmd_DelayTick
** 功能: 延时dt个tick
** 参数: dt -- 要延时的tick个数
** 返回: 无
** 说明: 一个tick大概有10ms
** 作者: wasfayu
*******/
void MsgCmd_DelayTick(U32 dt)
{
    U32 tick1, tick2;

	kal_get_time(&tick1);
	dt = dt ? dt : 2;
	do {
		kal_get_time(&tick2);
	}while(tick2 - tick1 < dt);
}

/*******************************************************************************
** 函数: at_print
** 功能: AT命令调试打印函数
** 入参: vp
** 返回: 无
** 作者: wasfayu
*******/
static void at_print(MMI_BOOL stuff, const char *fmt, ...)
{
	va_list list;
	char buffer[512];
	S32 length;

	memset(buffer, 0, 512);
	va_start(list, fmt);
	length = vsprintf(buffer, fmt, list);
	va_end(list);

	rmmi_write_to_uart(buffer, length, stuff);
}

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
        if (0 == vp->argc)
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
        if (1 != vp->argc)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            U32 dly = atoi(vp->argv[0].pos);
            
            srv_shutdown_normal_start(SRV_BOOTUP_MODE_NORMAL);
        }
        break;
        
    case AT_EM_HELP:
        at_replay(
            MMI_TRUE, 
            "%s: (0, %d~%d)",
            vp->name,
            shutdown_delay_min, 
            shutdown_delay_max);
        break;
        
    case AT_EM_READ:
        vp->result = AT_RST_PARAM_ERR;
		break;
		
    case AT_EM_ACTIVE:
		srv_shutdown_normal_start(SRV_BOOTUP_MODE_NORMAL);
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
        if (1 != vp->argc)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            U32 dly = MsgCmd_Atoi((const char *)vp->argv[0].pos);

            srv_alm_pwr_reset(MMI_TRUE, 1);
        }
        break;
        
    case AT_EM_HELP:
        at_replay(
            MMI_TRUE, 
            "%s: (0, %d~%d)", 
            vp->name,
            reboot_delay_min, 
            reboot_delay_max);
        break;
        
    case AT_EM_READ:
		vp->result = AT_RST_PARAM_ERR;
		break;
		
    case AT_EM_ACTIVE:
		srv_alm_pwr_reset(MMI_TRUE, 1);
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
    U8 enableVal[2] = {uart_port_usb, uart_port_null};//open, close
    
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        if (1 != vp->argc)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            U32 val, i;
            port_setting_struct ps;

			val = MsgCmd_Atoi((const char *)vp->argv[0].pos);
            for(i=0; i<sizeof(enableVal)/sizeof(enableVal[0]); i++)
            {
                if(enableVal[i] == (U8)val)
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
                    (U8*)&ps,
                    sizeof(port_setting_struct)))
            {
                at_replay(MMI_TRUE, "read data failed.");
                break;
            }
            
            ps.tst_port_ps = val;
            if (!nvram_external_write_data(
                    NVRAM_EF_PORT_SETTING_LID,
                    1,
                    (U8*)&ps,
                    sizeof(port_setting_struct)))
            {
                at_replay(MMI_TRUE, "save data failed.");
            }
        }
        break;
        
    case AT_EM_HELP:
        {
            char strbuf[64] = {0};
            U32 i, j, k;

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
            
            at_replay(MMI_TRUE, "%s: (%s)", vp->name, strbuf);
        }
        break;
        
    case AT_EM_READ:
        {
            port_setting_struct ps;
            
            memset((void*)&ps, 0, sizeof(port_setting_struct));
            
            if (nvram_external_read_data(
                    NVRAM_EF_PORT_SETTING_LID,
                    1,
                    (U8*)&ps,
                    sizeof(port_setting_struct)))
            {
                at_replay(MMI_TRUE, "0x%02x", ps.tst_port_ps);
            }
            else
            {
                at_replay(MMI_TRUE, "read data failed.");
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
        if (vp->argc > 3)
            vp->result = AT_RST_PARAM_ERR;
        else
        {

        }
        break;
        
    case AT_EM_HELP:
        at_replay(MMI_TRUE, "%s: [<(0,1)>,<time>,<number>]", vp->name);
        break;
        
    case AT_EM_READ:
        break;
        
    case AT_EM_ACTIVE:
        
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
        if (vp->argc > 3)
            vp->result = AT_RST_PARAM_ERR;
        else
        {
            MsgcmdVdoProcReq *req = (MsgcmdVdoProcReq*)\
                MsgCmd_ConstructPara(sizeof(MsgcmdVdoProcReq));

            req->record   = MsgCmd_Atoi((const char *)vp->argv[0].pos) ? MMI_TRUE : MMI_FALSE;

            if (1 < vp->argc)
            {
                req->saveGap = msgcmd_GetVdoRecdArgs()->save_gap;
                req->recdTime = MsgCmd_Atoi((const char *)vp->argv[1].pos) * 60;
            }
                        
            if (3 == vp->argc)
            {
                strcpy(req->number, vp->argv[0].pos);
            }
            
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_VDORECD_REQ, (void *)req);
        }
        break;
        
    case AT_EM_HELP:
        at_replay(MMI_TRUE, "%s: [<(0,1)>,<time>,<number>]", vp->name);
        break;
        
    case AT_EM_READ:
        at_replay(MMI_TRUE, "Video record busy=%d.", MsgCmd_VdoRecdBusy());
		if (MsgCmd_VdoRecdBusy())
		{
			MsgCmd_VdoRecdSetAppend();
		}
        break;
        
    case AT_EM_ACTIVE:  
        {
            MsgcmdVdoProcReq *req = (MsgcmdVdoProcReq*)\
                MsgCmd_ConstructPara(sizeof(MsgcmdVdoProcReq));

            req->saveGap = msgcmd_GetVdoRecdArgs()->save_gap;
            req->number[0] = '\0';
            
            if (MsgCmd_VdoRecdBusy())
            {
                req->record  = MMI_FALSE;
                at_replay(MMI_TRUE, "Stop video record.");
            }
            else
            {
                req->record  = MMI_TRUE;
                req->forever = MMI_TRUE;
                at_replay(MMI_TRUE, "Start video record.");
            }
            
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_VDORECD_REQ, (void *)req);
        }
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
        if (vp->argc > 1 || 
            !(vp->argc == 1 && 
              vp->argv[0].len < MAX_PHONENUMBER_LENTH && 
              MsgCmd_IsDigStr((const char*)vp->argv[0].pos, vp->argv[0].len)))
        {
            vp->result = AT_RST_PARAM_ERR;
        }
        else
        {
            MsgcmdCaptureReq *req = (MsgcmdCaptureReq*)MsgCmd_ConstructPara(sizeof(MsgcmdCaptureReq));

            if (vp->argc)
            {
                strcpy(req->number, vp->argv[0].pos);
            }
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_CAPTURE_REQ, (void *)req);
        }
        break;
        
    case AT_EM_HELP:
        at_replay(MMI_TRUE, "%s: [number]", vp->name);
        break;
        
    case AT_EM_READ:
        vp->result = AT_RST_PARAM_ERR;
        break;
    case AT_EM_ACTIVE:        
        {
            MsgcmdCaptureReq *req = (MsgcmdCaptureReq*)MsgCmd_ConstructPara(sizeof(MsgcmdCaptureReq));

            req->number[0] = '\0';
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_CAPTURE_REQ, (void *)req);
        }
        break;
        
    default:
        vp->result = AT_RST_UNKOWN_ERR;
        break;
    }
}

//at$disksize=c
static void at_disksize(AtParam_t *vp)
{   
    switch(vp->mode)
    {
    case AT_EM_SET_OR_EXEC:
        at_replay(MMI_TRUE, "%d", MsgCmd_GetDiskFreeSize((S32)vp->argv[0].pos[0]));
        break;
        
    case AT_EM_HELP:
        at_replay(MMI_TRUE, "%s: (c~z)", vp->name);
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
static U16 msgcmd_AtCmdLineParse(ArgItem_t *argItem, char *cmdStr)
{
    MMI_BOOL dQuote = MMI_FALSE, next = MMI_FALSE;
    U16 argc;
    
    if (NULL == argItem || NULL == cmdStr)
        return 0;

    argc = 0;
    
    do{
        while(isspace(*cmdStr))
            *cmdStr++ = '\0';

        if(*cmdStr == '\0')
            break;
        
        argItem[argc].pos = cmdStr;
        next = MMI_FALSE;
        
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
                next = MMI_TRUE;
                break;
                
            case '\"':
                if(!dQuote)
                {
                    argItem[argc].pos++;
                    dQuote = MMI_TRUE;
                    *cmdStr++ = '\0';
                }
                else
                {
                    dQuote = MMI_FALSE;
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

        lfy_trace(
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
        lfy_trace("[SPLIT] quote error. argc=%d", argc);
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
MMI_BOOL MsgCmd_AtCmdProc(char *origStr)
{        
    if (0 == app_strnicmp(origStr, "AT", 2))
    {
        AtExecMode_e em = AT_EM_WRONG;
        U32 len;
        char ch, *pos;
        
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

		lfy_trace("%s,L:%d, em=%d.", __FUNCTION__, __LINE__, em);
        if(em != AT_EM_WRONG)
        {
            U32 i;
            
            for (i=0; i<sizeof(command_table)/sizeof(command_table[0]); i++)
            {                
                if (len == command_table[i].bodyLen &&
                    0   == app_strnicmp(origStr+2, (char*)command_table[i].bodyStr, len))
                {
                    AtParam_t *ap = (AtParam_t*)MsgCmd_Malloc(sizeof(AtParam_t), 0);

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
                        at_replay(MMI_TRUE, "OK");
                        break;
                    case AT_RST_NO_REPLAY:
                        /* do nothing */
                        break;
                    default:
                        at_replay(MMI_TRUE, "ERROR: %d", ap->result);
                        break;
                    }
                    
                    MsgCmd_Mfree(ap);
                    return MMI_TRUE; //终止for循环
                }
            }
        }
    }

    return MMI_FALSE;
}

#if 1
extern const unsigned char MSGCMD_EINT_NO;

#define MC_EINT_NO         MSGCMD_EINT_NO
#define MSGCMD_INTERRUPT_DIFF_LEVEL  0 //低电平出发外部中断

/*******************************************************************************
** 函数: msgcmd_InterruptProcess
** 功能: 外部中断响应函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_InterruptRespond(void *p)
{
	MsgCmdExtIntReq *rsp = (MsgCmdExtIntReq*)p;

	lfy_trace("%s, level=%d.", __FUNCTION__, rsp->level);
}

/*******************************************************************************
** 函数: msgcmd_InterruptEntrance
** 功能: 外部中断响应入口函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_InterruptEntrance(void)
{
#if defined(WIN32)
    return;
#else

#if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
    MsgCmdExtIntReq *req;
    U32 iA,iB;
    U32 iStatus = 0;

    iStatus = DRV_ACCDET_Reg32(ACCDET_MEMORIZED_IN); // get AB status.
   	iA = (iStatus & 0x2) >> 1;
   	iB = iStatus & 0x1; // we just care the B bit status
        
    req = (MsgCmdExtIntReq*)MsgCmd_ConstructPara(sizeof(MsgCmdExtIntReq));
    if((iA == 0) && (iB == 1))
	    req->level = MMI_TRUE;
	else if ((iA == 0)&&(iB == 0))
		req->level = MMI_FALSE;
    MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_EXT_INTERRUPT, (void *)req);
    
    IRQClearInt(IRQ_ACCDET_CODE);
    IRQUnmask(IRQ_ACCDET_CODE);

#else

    static MMI_BOOL int_status = (MMI_BOOL)MSGCMD_INTERRUPT_DIFF_LEVEL;
	MsgCmdExtIntReq *req;

    EINT_Mask(MC_EINT_NO);
    req = (MsgCmdExtIntReq*)MsgCmd_ConstructPara(sizeof(MsgCmdExtIntReq));
	//EINT_SW_Debounce_Modify(AUX_EINT_NO,PLUGOUT_DEBOUNCE_TIME);
	req->level = int_status;
	int_status = !int_status;
	EINT_Set_Polarity(MC_EINT_NO, int_status); 

	MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_EXT_INTERRUPT, (void *)req);
    EINT_UnMask(MC_EINT_NO);
#endif
#endif
}

/*******************************************************************************
** 函数: MsgCmd_InterruptMask
** 功能: 屏蔽/打开外部中断
** 参数: mask  -- 屏蔽
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_InterruptMask(MMI_BOOL mask)
{
    #if !defined(WIN32)
    if (mask)
    {
    #if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
        IRQMask(IRQ_ACCDET_CODE);
    #else
        EINT_Mask(MC_EINT_NO);
    #endif
    
        mmi_frm_clear_protocol_event_handler(
    		MSG_ID_MC_EXT_INTERRUPT,
    		(PsIntFuncPtr)msgcmd_InterruptRespond);
    }
    else
    {
        mmi_frm_set_protocol_event_handler(
    		MSG_ID_MC_EXT_INTERRUPT,
    		(PsIntFuncPtr)msgcmd_InterruptRespond,
    		MMI_FALSE);

    #if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
        IRQClearInt(IRQ_ACCDET_CODE);
        IRQUnmask(IRQ_ACCDET_CODE);
    #else
        EINT_UnMask(MC_EINT_NO);
    #endif
    }
#endif
    
    lfy_trace("%s, mask=%d.", __FUNCTION__, mask);
}

static void msgcmd_interrupt_lisr(void)
{
#if !defined(WIN32)
   DRV_ACCDET_WriteReg32(ACCDET_IRQ_STS, ACCDET_IRQ_CLR); //pause the IRQ
   IRQMask(IRQ_ACCDET_CODE);
   drv_active_hisr(DRV_ACCDET_HISR_ID);
#endif
}

/*******************************************************************************
** 函数: MsgCmd_InterruptRegister
** 功能: 外部中断注册, 必须在多任务初始化的时候就注册, 
**       否则会在EINT_LISR里面"ASSERT(EINT_FUNC[index].eint_func!=NULL);"
** 参数: void
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_InterruptRegister(void)
{
#if !defined(WIN32)
#if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
    DRV_Register_HISR(DRV_ACCDET_HISR_ID, msgcmd_InterruptEntrance);
    IRQ_Register_LISR(IRQ_ACCDET_CODE, msgcmd_interrupt_lisr, "MSGCMD handler");
    IRQSensitivity(IRQ_ACCDET_CODE, EDGE_SENSITIVE);
    IRQMask(IRQ_ACCDET_CODE);
#else
	EINT_Registration(
		MC_EINT_NO, 
		MMI_TRUE, 
		(MMI_BOOL)MSGCMD_INTERRUPT_DIFF_LEVEL, 
		msgcmd_InterruptEntrance, 
		MMI_TRUE);

    //最开始是屏蔽状态, 待初始化之后再打开
    EINT_Mask(MC_EINT_NO);
#endif
#endif
}

#endif

#if 1//MMS
/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_element_start
 * DESCRIPTION
 *  Create the xml start element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_element_start(FS_HANDLE fh, U8 *element_name, U8 **attr_list);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_element_end
 * DESCRIPTION
 *  Create the xml end element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_element_end(FS_HANDLE fh, U8 *element_name);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_new_line
 * DESCRIPTION
 *  Insert new line
 * PARAMETERS
 *  fh      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_new_line(FS_HANDLE fh);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_data(FS_HANDLE fh, U8 *data);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data_numeric_to_char
 * DESCRIPTION
 *  Add numeric data
 * PARAMETERS
 *  fh          [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_data_numeric_to_char(FS_HANDLE fh, U32 value);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_element_single
 * DESCRIPTION
 *  Create the xml single element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_element_single(FS_HANDLE fh, U8 *element_name, U8 **attr_list);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data_usc2_to_utf8_to_base64
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_data_usc2_to_utf8_to_base64(FS_HANDLE fh, U8 *data);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data_usc2_to_utf8
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_uc_create_xml_data_usc2_to_utf8(FS_HANDLE fh, U8 *data);

/*
wap_mma_set_profile_req_struct
srv_nw_usab_is_any_network_available
srv_ucm_is_any_call
[srv_uc_create_mms_xml_description_file]
*/
/*******************************************************************************
** 函数: msgcmd_CreateMMSXMLFile
** 功能: 创建MMS发送时需要的XML文件
** 入参: MsgCmdMMSXmlData -- 创建XML文件的依据
** 返回: 是否成功
** 说明: 调用srv_uc_create_mms_xml_description_file函数中类似的功能来完成布局
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_CreateMMSXMLFile(MsgCmdMMSXmlData *param)
{
#define FUNC_FAIL_RETURN(exp) if ((exp) < FS_NO_ERROR) { FS_Close(fh); return MMI_FALSE;}
#define MMS_BACKGROUND_COLOR  0xFFFFFF
#define MMS_FOREGROUND_COLOR  0x000000

/* UC xml tag MMS. */
#define SRV_UC_XML_ELEMENT_MMS "mms"
/* UC xml tag header. */
#define SRV_UC_XML_ELEMENT_HEADER "header"
/* UC xml tag to. */
#define SRV_UC_XML_ELEMENT_TO "to"
/* UC xml tag cc. */
#define SRV_UC_XML_ELEMENT_CC "cc"
/* UC xml tag bcc. */
#define SRV_UC_XML_ELEMENT_BCC "bcc"
/* UC xml tag from. */
#define SRV_UC_XML_ELEMENT_FROM "from"
/* UC xml tag type. */
#define SRV_UC_XML_ATTR_TYPE "type"
/* UC xml tag phonenumber. */
#define SRV_UC_XML_ATTR_POHNE_NUMBER "P"
/* UC xml tag email. */
#define SRV_UC_XML_ATTR_EMAIL_ADDR "E"
/* UC xml tag IP4 address. */
#define SRV_UC_XML_ATTR_IP_ADDR "IP4"
/* UC xml tag subject. */
#define SRV_UC_XML_ELEMENT_SUBJECT "subject"
/* UC xml tag read report. */
#define SRV_UC_XML_ELEMENT_READ_REPORT "rr"
/* UC xml tag delivery report. */
#define SRV_UC_XML_ELEMENT_DELIVERY_REPORT "dr"
/* UC xml tag priority. */
#define SRV_UC_XML_ELEMENT_PRIORITY "prio"
/* UC xml tag expiry. */
#define SRV_UC_XML_ELEMENT_EXPIRY "expiry"
/* UC xml tag delivery. */
#define SRV_UC_XML_ELEMENT_DELIVERY_TIME "delivery"
/* UC xml tag visible. */
#define SRV_UC_XML_ELEMENT_VISIBLE "visible"
/* UC xml tag class. */
#define SRV_UC_XML_ELEMENT_CLASS "class"
/* UC xml tag body. */
#define SRV_UC_XML_ELEMENT_BODY "body"
/* UC xml tag bgcolor. */
#define SRV_UC_XML_ATTR_BGCOLOR "bgColor"
/* UC xml tag fgcolor. */
#define SRV_UC_XML_ATTR_FGCOLOR "fgColor"
/* UC xml tag total slide number. */
#define SRV_UC_XML_ATTR_SLIDE_NUM "slideNum"
/* UC xml tag total object number. */
#define SRV_UC_XML_ATTR_OBJ_NUM "objNum"
/* UC xml tag layout. */
#define SRV_UC_XML_ATTR_LAYOUT "layout"
/* UC xml tag text fit. */
#define SRV_UC_XML_ATTR_TXTFIT "txtFit"
/* UC xml tag imagefit. */
#define SRV_UC_XML_ATTR_IMGFIT "imgFit"
/* UC xml tag slide. */
#define SRV_UC_XML_ELEMENT_SLIDE "slide"
/* UC xml tag index. */
#define SRV_UC_XML_ATTR_INDEX "index"
/* UC xml tag duration. */
#define SRV_UC_XML_ATTR_DURATION "dur"
/* UC xml tag id. */
#define SRV_UC_XML_ATTR_ID "id"
/* UC xml tag begin. */
#define SRV_UC_XML_ATTR_BEGIN "begin"
/* UC xml tag end. */
#define SRV_UC_XML_ATTR_END "end"
/* UC xml tag text. */
#define SRV_UC_XML_ELEMENT_TEXT "text"
/* UC xml tag image. */
#define SRV_UC_XML_ELEMENT_IMAGE "img"
/* UC xml tag audio. */
#define SRV_UC_XML_ELEMENT_AUDIO "audio"
/* UC xml tag video. */
#define SRV_UC_XML_ELEMENT_VIDEO "video"
/* UC xml tag ref. */
#define SRV_UC_XML_ELEMENT_REF "ref"
/* UC xml tag attach. */
#define SRV_UC_XML_ATTR_ATTACH "attach"
/* UC xml tag virtual file. */
#define SRV_UC_XML_ATTR_VIRTUAL_FILE "vf"
/* UC xml tag drm. */
#define SRV_UC_XML_ATTR_DRM "drm"
/* UC xml tag size. */
#define SRV_UC_XML_ATTR_SIZE "size"
/* UC xml tag offset. */
#define SRV_UC_XML_ATTR_OFFSET "offset"
/* UC xml tag encoding. */
#define SRV_UC_XML_ATTR_ENCODING "encoding"
/* UC xml tag object. */
#define SRV_UC_XML_ELEMENT_OBJECT "obj"
/* UC xml tag name. */
#define SRV_UC_XML_ELEMENT_NAME "name"
/* UC xml tag filepath. */
#define SRV_UC_XML_ELEMENT_FILE_PATH "filepath"

    FS_HANDLE fh;
    
    if (NULL == param)
        return MMI_FALSE;

    if (0 == strlen(param->sendto))
        return MMI_FALSE;
    
    if (0 == app_ucs2_strlen((const kal_int8 *)param->xmlpath))
        return MMI_FALSE;
    
    if (0 == app_ucs2_strlen((const kal_int8 *)param->picname))
        return MMI_FALSE;

    if (0 == app_ucs2_strlen((const kal_int8 *)param->picpath))
        return MMI_FALSE;

    // ready, go!
    if ((fh = FS_Open(param->xmlpath, FS_READ_WRITE|FS_CREATE_ALWAYS)) < FS_NO_ERROR)
        return MMI_FALSE;

    /* <mms> */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_MMS, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

    /* <header> */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_HEADER, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
    
    /* To address */
    if (MMI_TRUE)
    {
    U8 *attr_list[3] = {SRV_UC_XML_ATTR_TYPE, SRV_UC_XML_ATTR_POHNE_NUMBER, NULL};
    
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, SRV_UC_XML_ELEMENT_TO, attr_list));
    FUNC_FAIL_RETURN(srv_uc_create_xml_data(fh, (U8*)param->sendto));
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, SRV_UC_XML_ELEMENT_TO));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
    }
    
    /* subject */
    if (mmi_ucs2strlen((S8*)param->subject))
    {
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_SUBJECT, NULL));
        FUNC_FAIL_RETURN(srv_uc_create_xml_data_usc2_to_utf8_to_base64(fh,(U8*)param->subject));
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_SUBJECT));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
    }

    /* Read Report */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_READ_REPORT, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_data_numeric_to_char(fh, param->read_report));
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_READ_REPORT));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

    /* Delivery Report */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_REPORT, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_data_numeric_to_char(fh, param->delivery_report));
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_REPORT));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

    /* Priority */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_PRIORITY, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_data_numeric_to_char(fh, param->priority));
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_PRIORITY));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
    
    /* Expiry time */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_EXPIRY, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_data_numeric_to_char(fh,srv_uc_convert_to_mms_expiry_time(param->expiry_time)));
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_EXPIRY));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
    
    /* Delivery time */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_TIME, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_data_numeric_to_char(fh,srv_uc_convert_to_mms_delivery_time(param->delivery_time)));
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_TIME));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

    /* Sender visibility */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_VISIBLE, NULL));
    FUNC_FAIL_RETURN(srv_uc_create_xml_data_numeric_to_char(fh, !param->hide_sender));
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_VISIBLE));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
    
    /* </header> */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_HEADER));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

    if (MMI_TRUE)
    {
        U16 str_len = SRV_UC_XML_STR_LEN;   /* size of slide_num, obj_num, layout, bg_color and fg_color */
        U16 attr_num = 7;                   /* size of arrt_list would be attr_num * 2 + 1 */
        U8 bg_color[SRV_UC_XML_STR_LEN];
        U8 fg_color[SRV_UC_XML_STR_LEN];
        U8 slide_num[SRV_UC_XML_STR_LEN];
        U8 obj_num[SRV_UC_XML_STR_LEN];
        U8 layout[SRV_UC_XML_STR_LEN];
        U8 txt_fit[SRV_UC_XML_STR_LEN];
        U8 img_fit[SRV_UC_XML_STR_LEN];
        U8 *attr_list[7 * 2 + 1];           /* 7= bg_color....img_fit */
        U8 i = 0;

        /* body */
        i = 0;
        /*-----background color-----------------------------------------------*/
        memset(bg_color, 0, str_len);
        sprintf((char*)bg_color, "0x%06x", MMS_BACKGROUND_COLOR);
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_BGCOLOR;
        attr_list[i++] = bg_color;
        /*-----foregrount color----------------------------------------------*/
        memset(fg_color, 0, str_len);
        sprintf((char*)fg_color, "0x%06x", MMS_FOREGROUND_COLOR);
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_FGCOLOR;
        attr_list[i++] = fg_color;
        /*-----slide number---------------------------------------------------*/
        memset(slide_num, 0, str_len);
        slide_num[0] = '1'; //只有一个slide
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_SLIDE_NUM;
        attr_list[i++] = slide_num;
        /*-----object number--------------------------------------------------*/
        memset(obj_num, 0, str_len);
        obj_num[0] = '1'; //只有一个object
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_OBJ_NUM;
        attr_list[i++] = obj_num;
        /*-----layout type----------------------------------------------------*/
        memset(layout, 0, str_len);
        layout[0] = '1'; //布局, 参见mma_slide_layout_enum
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_LAYOUT;
        attr_list[i++] = layout;
        /*-----image fit------------------------------------------------------*/
        memset(img_fit, 0, str_len);
        sprintf((char*)img_fit, "%d", MMA_REGION_FIT_MEET);    /* Always set to MEET for img, because current mms can not support other type */
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_IMGFIT;
        attr_list[i++] = img_fit;
        /*-----text fit-------------------------------------------------------*/
        memset(txt_fit, 0, str_len);
        sprintf((char*)txt_fit, "%d", MMA_REGION_FIT_SCROLL);  /* Always set to SCROLL for text, because current mms can not support other type */
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_TXTFIT;
        attr_list[i++] = txt_fit;
        /*--------------------------------------------------------------------*/
        attr_list[i++] = NULL;
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_BODY, attr_list));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

        /* Slide */
        i = 0;
        /*--------------------------------------------------------------------*/
        memset(bg_color, 0, str_len);
        bg_color[0] = '1'; //只有一张图片, 一个slide
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_INDEX;
        attr_list[i++] = bg_color;
        /*--------------------------------------------------------------------*/
        memset(fg_color, 0, str_len);
        fg_color[0] = '5'; //只有5秒钟
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_DURATION;
        attr_list[i++] = fg_color;
        /*--------------------------------------------------------------------*/
        attr_list[i++] = NULL;
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_SLIDE, attr_list));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
        
        /*--------------------------------------------------------------------*/
        i = 0;
        /*-----slide index----------------------------------------------------*/
        memset(slide_num, 0, str_len);
        sprintf((char*)slide_num, "1"); //只有一张图片, 因此就只有一个slide, 所以直接给定slide index为1
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_ID;
        attr_list[i++] = slide_num;
        /*-----start time-----------------------------------------------------*/
        memset(obj_num, 0, str_len);
        sprintf((char*)obj_num, "0"); //只有一张图片, 从0秒开始
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_BEGIN;
        attr_list[i++] = obj_num;
        /*-----end time-------------------------------------------------------*/
        memset(layout, 0, str_len);
        sprintf((char*)layout, "5"); //只有一张图片, 到5秒种结束
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_END;
        attr_list[i++] = layout;
        /*--------------------------------------------------------------------*/
        attr_list[i] = NULL;
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_single(fh, SRV_UC_XML_ELEMENT_IMAGE, attr_list));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_SLIDE));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

        /* Object */
        i = 0;
        /*-----object index---------------------------------------------------*/
        memset(bg_color, 0, str_len);
        bg_color[0] = '1'; //只有一个object, 强制给定为1
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_ID;
        attr_list[i++] = bg_color;
        /*-----attach---------------------------------------------------------*/
        memset(fg_color, 0, str_len);
        fg_color[0] = '0';
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_ATTACH;
        attr_list[i++] = fg_color;
        /*-----virtual file---------------------------------------------------*/
        memset(slide_num, 0, str_len);
        slide_num[0] = '0';
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_VIRTUAL_FILE;
        attr_list[i++] = slide_num;
        /*-----drm------------------------------------------------------------*/
        memset(obj_num, 0, str_len);
        obj_num[0] = '0';
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_DRM;
        attr_list[i++] = obj_num;
        /*-----size-----------------------------------------------------------*/
        memset(layout, 0, str_len);
        sprintf(layout, "%d", applib_get_file_size(param->picpath));
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_SIZE;
        attr_list[i++] = layout;
        /*-----offset---------------------------------------------------------*/
        memset(txt_fit, 0, str_len);
        txt_fit[0] = '0';
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_OFFSET;
        attr_list[i++] = txt_fit;
        /*-----encoding-------------------------------------------------------*/
        memset(img_fit, 0, str_len);
        img_fit[0] = '0';
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_ENCODING;
        attr_list[i++] = img_fit;
        
        attr_list[i++] = NULL;
        /* <obj> */
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_OBJECT, attr_list));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
        /* name */
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_NAME, NULL));
        FUNC_FAIL_RETURN(srv_uc_create_xml_data_usc2_to_utf8(fh, (U8*)param->picname));
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_NAME));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
        /* file path */
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_FILE_PATH, NULL));
        FUNC_FAIL_RETURN(srv_uc_create_xml_data_usc2_to_utf8(fh, (U8*)param->picpath));
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_FILE_PATH));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
        /* </obj> */
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_OBJECT));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));
    
        /* it possible that the case happens: no object, but user press end key, Uc will save postcard in background, 
           still need to create a empty postcard text object */

        /* </body> */
        FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_BODY));
        FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));        
    }

    /* </mms> */
    FUNC_FAIL_RETURN(srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_MMS));
    FUNC_FAIL_RETURN(srv_uc_create_xml_new_line(fh));

    FS_Close(fh);

    return MMI_TRUE;
#undef FUNC_FAIL_RETURN
}

/*******************************************************************************
** 函数: msgcmd_SendMMSResponse
** 功能: 创建并且发送MMS的回调函数
** 入参: result   -- 
**       rsp_data -- srv_mms_create_rsp_struct
**       user_data-- 
** 返回: 是否成功
** 作者: wasfayu
*******/
static void msgcmd_SendMMSResponse(void *param)
{
    MsgCmdMMSReq     *rsp = (MsgCmdMMSReq*)param;
    
#if 1
    MsgCmd_CreateAndSendMMS(rsp->sim, L"E:\\mc_985680.xml");
#else
    MsgCmdMMSXmlData *xml = (MsgCmdMMSXmlData*)MsgCmd_Malloc(sizeof(MsgCmdMMSXmlData), 0);

    //send to
    memcpy(xml->sendto, rsp->sendto, MMI_PHB_NUMBER_LENGTH+1);
    //subject
    memcpy(xml->subject, rsp->subject, sizeof(WCHAR)*(SRV_UC_MAX_SUBJECT_LEN+1));
    //file name
    memcpy(xml->picname, rsp->picname, sizeof(WCHAR)*(MSGCMD_FILE_NAME_LENGTH+1));
    //file full path
    memcpy(xml->picpath, rsp->picpath, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
    //other
  	xml->priority         = MMA_PRIORITY_MEDIUM;
    xml->expiry_time      = SRV_UC_EXPIRY_NOT_SET;
    xml->delivery_report  = SRV_UC_DELIVERY_IMMEDIATE;
    xml->read_report      = FALSE;
    xml->hide_sender      = FALSE;
    xml->delivery_report  = FALSE;
    //xml file abs path
#if defined(WIN32)
{
    applib_time_struct mt;
	applib_dt_get_date_time(&mt);
    
    kal_wsprintf(xml->xmlpath,
        "%c:\\mc_%d%d%d.xml",
        MsgCmd_GetUsableDrive(),
        mt.nHour,
        mt.nMin,
        mt.nSec);
}
#else
    kal_wsprintf(xml->xmlpath,
        "%c:\\mc_%d.xml",
        MsgCmd_GetUsableDrive(),
        MsgCmd_GetCurrentTime());
#endif

    if (msgcmd_CreateMMSXMLFile(xml))
    {
        MsgCmd_CreateAndSendMMS(rsp->sim, xml->xmlpath);
    }

    MsgCmd_Mfree(xml);
#endif
}

/*******************************************************************************
** 函数: MsgCmd_CreateAndSendMMSCb
** 功能: 创建并且发送MMS的回调函数
** 入参: result   -- 
**       rsp_data -- srv_mms_create_rsp_struct
**       user_data-- 
** 返回: 是否成功
** 作者: wasfayu
*******/
static void msgcmd_CreateAndSendMMSCb(
    srv_mms_result_enum result,
    void *rsp_data,
    void *user_data)
{
	srv_mms_create_rsp_struct *rsp = (srv_mms_create_rsp_struct*)rsp_data;
    MsgCmdMMSUserData         *usd = (MsgCmdMMSUserData*)user_data;

	if (SRV_MMS_RESULT_OK == result)
	{
		srv_mms_send_req_struct req;
        
		req.msg_id       = rsp->msg_id;
		req.send_setting = SRV_MMS_SETTING_SEND_ONLY;
		req.sim_id       = usd->sim;
		req.storage_type = MMA_MSG_STORAGE_CARD1;
		req.is_rr        = MMI_TRUE;
		srv_mms_send(&req);
	}

    FS_Delete(usd->xmlpath);
    MsgCmd_Mfree(usd);
        
	lfy_trace("%s, result=%d, msg_id=%d. rsp->result=%d.",
		__FUNCTION__, result, rsp->msg_id, rsp->result);
}

/*******************************************************************************
** 函数: MsgCmd_CreateAndSendMMS
** 功能: 创建并且发送MMS
** 入参: xml_path  -- MMS布局文件, 里面已经包含有电话号码这些了
**       sim       -- mma_sim_id_enum
** 返回: 是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CreateAndSendMMS(mma_sim_id_enum sim, WCHAR *xml_path)
{
	MMI_BOOL result = MMI_FALSE;

    if (mms_is_ready() && srv_nw_usab_is_any_network_available())
    {
        srv_mms_create_req_struct createReq;
        MsgCmdMMSUserData        *userdata;

        memset(&createReq, 0, sizeof(srv_mms_create_req_struct));
        userdata = (MsgCmdMMSUserData*)MsgCmd_Malloc(sizeof(MsgCmdMMSUserData), 0);
        userdata->sim = sim;
        app_ucs2_strcpy((S8*)userdata->xmlpath, (const S8*)xml_path);
        
        //createReq.msg_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
        app_ucs2_strcpy((S8*)createReq.xml_filepath, (const S8*)xml_path);
        createReq.user_data = (void*)userdata;
        createReq.msg_id    = 0;
        createReq.app_id    = MMA_APP_ID_BGSR;
        createReq.mode      = MMA_MODE_EDIT;
        createReq.sim_id    = sim;
        createReq.xml_size  = applib_get_file_size(createReq.xml_filepath);
        createReq.call_back = msgcmd_CreateAndSendMMSCb;
        
        result = (MMI_BOOL)(SRV_MMS_RESULT_OK == srv_mms_create(&createReq));
    }
	
	lfy_trace("%s, result=%d.", __FUNCTION__, result);
    return result;
}

MMI_BOOL MsgCmd_TestSendMMS(void)
{
    MsgCmdMMSReq *req = (MsgCmdMMSReq*)MsgCmd_ConstructPara(sizeof(MsgCmdMMSReq));

    kal_wsprintf(req->picpath, "%c:\\Photos\\", MsgCmd_GetUsableDrive());
    req->picname = req->picpath + app_ucs2_strlen((const S8*)req->picpath)*sizeof(WCHAR);
    app_ucs2_strcat((S8*)req->picpath, (const S8*)L"20110101000300282986.jpg");
	strcpy(req->sendto, "13760106412");
    req->sim = MMA_SIM_ID_SIM1;
    kal_wsprintf(req->subject, "%w", req->picname);
    MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_SEND_MMS_REQ, (void *)req);
}

#endif

#if 1 //capture process
#define MSGCMD_CAPTURE_IMG_H 480
#define MSGCMD_CAPTURE_IMG_W 640

/*******************************************************************************
** 函数: msgcmd_CaptureFinish
** 功能: 拍照结束
** 参数: 无
** 返回: 是否成功关闭摄像头
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_CaptureFinish(void)
{
	MDI_RESULT error;

#if !defined(WIN32)
	error = mdi_camera_preview_stop();
	lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
#endif

	error = mdi_camera_power_off();
	lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);

	/* resume alignment timer */
	UI_enable_alignment_timers();

	/* re-enable keypad tone */
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

	/* resume background audio */
	mdi_audio_resume_background_play();
	
#if defined(MSGCMD_USE_FLASH_LED_4_CAPTURE)	
	mmi_camera_turn_off_led_highlight();
#endif

	return MMI_TRUE;
}

//power-on --> preview-start --> preview-strop --> capture --> power-off

/*******************************************************************************
** 函数: msgcmd_CaptureDoing
** 功能: 执行拍照并保存照片
** 参数: filename -- 照片名字
** 返回: 是否拍照并保存成功
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_CaptureDoing(S8 *filepath)
{
#if defined(WIN32)
    FS_HANDLE fd;

    fd = FS_Open((const WCHAR*)filepath, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (fd < FS_NO_ERROR)
        return MMI_FALSE;

    FS_Write(fd, "picture", 7, NULL);
    FS_Seek(fd, 64, FS_FILE_BEGIN);
    FS_Commit(fd);
    
    FS_Close(fd);

    return MMI_TRUE;

#else

	MDI_RESULT error;

	error = mdi_camera_capture_to_file(filepath, MMI_FALSE);
	lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
	{		
		FS_Delete((const WCHAR*)filepath);
		return MMI_FALSE;
	}
	
	error = mdi_camera_save_captured_image();
	lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
	{
		FS_Delete((const WCHAR*)filepath);
		return MMI_FALSE;
	}
	
	return MMI_TRUE;
#endif
}

/*******************************************************************************
** 函数: msgcmd_CapturePreview
** 功能: 进入拍照预览
** 参数: pictureW  -- 照片宽度
**       pictureH  -- 照片高度
** 返回: 是否预览成功
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_CapturePreview(U16 pictureW, U16 pictureH)
{
	MDI_RESULT error;
	mdi_camera_setting_struct camera_setting_data;
	mdi_camera_preview_struct camera_preview_data;

	error = mdi_camera_power_on(0);
	lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
		return MMI_FALSE;

#if defined(MSGCMD_USE_FLASH_LED_4_CAPTURE) 	
	mmi_camera_turn_on_preview_led_highlight();
#endif	  

	/* stop bg music */
	mdi_audio_suspend_background_play();

	/* force all playing keypad tone off */
	srv_profiles_stop_tone((srv_prof_tone_enum)GetCurKeypadTone());
	
	/* disable key pad tone */
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
	
	/* disalbe align timer	*/
	UI_disable_alignment_timers();
	
	mdi_camera_load_default_setting(&camera_setting_data);
	camera_setting_data.preview_width  = pictureW;
	camera_setting_data.preview_height = pictureH;
	camera_setting_data.image_width    = pictureW;
	camera_setting_data.image_height   = pictureH;
	camera_setting_data.lcm            = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.preview_format = MM_IMAGE_FORMAT_RGB565;
	//camera_setting_data.preview_rotate = 0;
	//camera_setting_data.lcm_rotate     = MDI_CAMERA_LCM_ROTATE_0;
	camera_setting_data.xenon_flash_status_callback = NULL;
	camera_setting_data.image_qty      = MDI_CAMERA_JPG_QTY_FINE;
	camera_setting_data.ev             = MDI_CAMERA_EV_0;
	camera_setting_data.banding        = MDI_CAMERA_BANDING_50HZ;
	camera_setting_data.wb             = MDI_CAMERA_WB_AUTO;
	//camera_setting_data.manual_wb      = MMI_FALSE;
	camera_setting_data.flash          = MDI_CAMERA_FLASH_AUTO;
	//camera_setting_data.night          = 0;
	camera_setting_data.iso            = MDI_CAMERA_ISO_AUTO;
	camera_setting_data.ae_meter       = MDI_CAMERA_AE_METER_AUTO;
	//camera_setting_data.dsc_mode       = MDI_CAMERA_DSC_MODE_AUTO;	
	camera_setting_data.zoom           = 10; /* 1x */
	//camera_setting_data.af_mode        = MDI_CAMERA_AUTOFOCUS_MODE_AUTO;
	//camera_setting_data.af_metering_mode = MDI_CAMERA_AUTOFOCUS_1_ZONE;
	//camera_setting_data.brightness    = 128;
	camera_setting_data.saturation    = 128;
	camera_setting_data.contrast      = 128;
	//camera_setting_data.shutter_pri   = 0;
	//camera_setting_data.aperture_pri  = 0;

    //gdi_layer_get_base_handle(&camera_preview_data.preview_layer_handle);
	//camera_preview_data.preview_layer_handle = GDI_NULL_HANDLE;
	//camera_preview_data.preview_wnd_offset_x = 0;
	//camera_preview_data.preview_wnd_offset_y = 0;
	//camera_preview_data.preview_wnd_width    = pictureW;
	//camera_preview_data.preview_wnd_height   = pictureH;
	//camera_preview_data.blt_layer_flag       = GDI_LAYER_ENABLE_LAYER_0;
	//camera_preview_data.preview_layer_flag   = GDI_LAYER_ENABLE_LAYER_0;
	//camera_preview_data.is_lcd_update        = MMI_FALSE;
	//camera_preview_data.src_key_color        = GDI_COLOR_TRANSPARENT;
	//camera_preview_data.is_tvout             = MMI_FALSE;

#if defined(WIN32)
    error = MDI_RES_CAMERA_SUCCEED;
#else
	error = mdi_camera_preview_start(&camera_preview_data, &camera_setting_data, NULL);
	lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
#endif

	if (MDI_RES_CAMERA_SUCCEED != error)
	{
		error = mdi_camera_preview_stop();
		lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		
		error = mdi_camera_power_off();
		lfy_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		
		return MMI_FALSE;
	}

	return MMI_TRUE;
}

/*******************************************************************************
** 函数: msgcmd_CaptureResponse
** 功能: 拍照请求响应函数
** 参数: p -- MsgcmdCaptureReq
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_CaptureResponse(void *p)
{
    MsgcmdCaptureReq *rsp = (MsgcmdCaptureReq*)p;
    
    if (strlen(rsp->number))
        MsgCmd_CaptureEntry(rsp->number);
    else
        MsgCmd_CaptureEntry(NULL);
}

/*******************************************************************************
** 函数: MsgCmd_CaptureEntry
** 功能: 拍照
** 参数: replay_number -- 拍照后回传照片到指定号码, 否则发送到超级号码.
** 返回: 是否拍照成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CaptureEntry(char *replay_number)
{
	const U16 pictureW = MSGCMD_CAPTURE_IMG_W;
	const U16 pictureH = MSGCMD_CAPTURE_IMG_H;
	MMI_BOOL  result = MMI_FALSE;
	
    lfy_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");

	if (msgcmd_CapturePreview(pictureW, pictureH))
	{
	    MsgCmdMMSReq *req = (MsgCmdMMSReq*)MsgCmd_ConstructPara(sizeof(MsgCmdMMSReq));
        
		req->picname = MsgCmd_CombineFilePath(
                        req->picpath, 
                        MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR), 
                        MSGCMD_PHOTOS_FOLDER_NAME, 
                        L".jpg");
		
		MsgCmd_DelayTick(MSGCMD_CAPTURE_DLY_TICK);
		result = msgcmd_CaptureDoing((S8 *)req->picpath);
        
		if (result && NULL != replay_number && replay_number[0] != '\0')
		{
			//send MMS
            req->sim = MMA_SIM_ID_SIM1;
		    strcpy(req->sendto, replay_number);            
            kal_wsprintf(req->subject, "%w", req->picname);
            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_SEND_MMS_REQ, (void *)req);
		}
        else
        {
            MsgCmd_DestructPara(req);
        }
	}

	MsgCmd_DelayTick(MSGCMD_CAPTURE_DLY_TICK);
	msgcmd_CaptureFinish();
	
    return result;
}
#endif


#if 1//video record

static WCHAR *msgcmd_VdoRecdGetSavePath(WCHAR *buffer, U32 length_in_byte);
static WCHAR *msgcmd_VdoRecdGetFilePath(WCHAR *buffer, U32 length_in_byte);
static void msgcmd_VdoRecdFreeSpaceCheck(void);
static void msgcmd_VdoRecdSaveCb(MDI_RESULT result);
static void msgcmd_VdoRecdDoingCb(MDI_RESULT result);
static void msgcmd_VdoRecdLayerMngr(MMI_BOOL create, gdi_handle *layer);
static MMI_BOOL msgcmd_VdoRecdPowerMngr(MMI_BOOL on);
static MMI_BOOL msgcmd_VdoRecdPreview(MMI_BOOL start, gdi_handle layer);
static MMI_BOOL msgcmd_VdoRecdDoing(WCHAR *filepath);
static void msgcmd_VdoRecdDelete(WCHAR *filepath);
static MMI_BOOL msgcmd_VdoRecdSave(WCHAR *filepath);
static void msgcmd_VdoRecdTimerCyclic(void);
static void msgcmd_VdoRecdCyclicTimer(MMI_BOOL start);
static void msgcmd_VdoRecdResponse(void *p);
static void msgcmd_VdoRecdContRecdRsp(void *p);

static VdoRecdMngr *vrm;

static MsgCmdRecdArg vdoargs = {5, 15, 12, 2, 1024*3};

void MsgCmd_ModisCreateAVI(WCHAR *filepath)
{

}

static MsgCmdRecdArg *msgcmd_GetVdoRecdArgs(void)
{
    return &vdoargs;
}


#define MSGCMD_VDORECD_CYCLIC_TIMER_TIME  1000 //ms
#define MSGCMD_VDORECD_CYCLIC_TIMER_ID   MSGCMD_TIMER_VDO_CHECK

/*******************************************************************************
** 函数: msgcmd_VdoRecdGetSavePath
** 功能: 获取录像保存的路径
** 参数: buffer  -- 路径输出
**       length_in_byte -- 路径输出buffer的长度, 字节为单位
** 返回: 路径buffer地址
** 作者: wasfayu
*******/
static WCHAR *msgcmd_VdoRecdGetSavePath(WCHAR *buffer, U32 length_in_byte)
{
    memset(buffer, 0, length_in_byte);
    MsgCmd_CombineFilePath(
        buffer, 
        MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR),
        MSGCMD_VIDEOS_FOLDER_NAME,
        NULL);

    return buffer;
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdGetFilePath
** 功能: 获取录像文件的绝对路径
** 参数: buffer  -- 文件绝对路径输出
**       length_in_byte -- 文件路径输出buffer的长度, 字节为单位
** 返回: 文件绝对路径buffer地址
** 作者: wasfayu
*******/
static WCHAR *msgcmd_VdoRecdGetFilePath(WCHAR *buffer, U32 length_in_byte)
{
    memset(buffer, 0, length_in_byte);
    MsgCmd_CombineFilePath(
        buffer, 
        MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR),
        MSGCMD_VIDEOS_FOLDER_NAME,
    #if defined(MP4_ENCODE)
    	L".3gp"
    #elif defined(MJPG_ENCODE)
    	L".avi"
    #else
    	MMI_ASSERT(0)  
    #endif
        );

    return buffer;
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdFreeSpaceCheck
** 功能: 释放空间
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdFreeSpaceCheck(void)
{
	U32 left, need;
    
	//一秒钟就是110KB, 如果要计算剩余空间的话, 必须要比这个大
    //磁盘剩余空间小于5M则删除就的录音文件
    left = MsgCmd_GetDiskFreeSize(MsgCmd_GetUsableDrive()) >> 10;
    need = MSGCMD_VDO_SIZE_PER_SEC_KB * msgcmd_GetVdoRecdArgs()->save_gap * 2;
    
	lfy_trace("%s, left=%dKB.need=%dKB.", __FUNCTION__, left, need);

	if (left <= need)
		msgcmd_DeleteOldFile(MSGCMD_VDO_LIST_FILE_NAME, need);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdSaveCb
** 功能: 录像保存的回调函数
** 参数: result  -- 保存结果
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdSaveCb(MDI_RESULT result)
{
    if (NULL == vrm)
        return;
    
    lfy_trace("%s. result=%d, stop=%d.", __FUNCTION__, result, vrm->stop);
    
	//mdi_video_rec_get_cur_record_time
    if (MDI_RES_VDOREC_SUCCEED == result)
    {
    #if defined(WIN32)
        //模拟器就随机的写入一些数据充斥下
        if (rand()%4==0)
        {
            MsgCmd_ModisCreateAVI(vrm->filepath);
        }
    #endif
    
        //如果文件小于这个值则删除掉他
        if (applib_get_file_size(vrm->filepath) >= msgcmd_GetVdoRecdArgs()->ignore_size)
        {
            char temp[MSGCMD_FILE_PATH_LENGTH+1];
            U32 length;

            memset(temp, 0, MSGCMD_FILE_PATH_LENGTH+1);
            length = app_ucs2_str_to_asc_str(temp, (S8*)vrm->filepath);
        	msgcmd_RecordFileName(MSGCMD_VDO_LIST_FILE_NAME, (const char*)temp, length);
        }
        else
        {
            FS_Delete(vrm->filepath);
        }
        
        if (!vrm->forever)
        {
            vrm->time -= vrm->saveGap;
            
            //如果有追加, 则增加一段时间, 时长为默认的保存间隔时长
            if (vrm->append)
            {
				lfy_trace("%s, time=%dS, add time(%dS).", __FUNCTION__, vrm->time, msgcmd_GetVdoRecdArgs()->save_gap);
                vrm->time  += msgcmd_GetVdoRecdArgs()->save_gap;
            }

            //剩余时间小于xx秒则忽略掉
            lfy_trace("%s, time=%d. forever=%d.", __FUNCTION__, vrm->time, vrm->forever);
            if (vrm->time < msgcmd_GetVdoRecdArgs()->ignore_time)
            {
                vrm->stop = MMI_TRUE;
            }    
        }
        
        vrm->append    = MMI_FALSE;
        vrm->timeCount = 0;
    }
    else
    {
        vrm->stop = MMI_TRUE;
        msgcmd_VdoRecdDelete(vrm->filepath);
    }

    if (vrm->stop)
    {
        msgcmd_VdoRecdPreview(MMI_FALSE, vrm->dispLayer);
        msgcmd_VdoRecdPowerMngr(MMI_FALSE);
        msgcmd_VdoRecdLayerMngr(MMI_FALSE, &vrm->dispLayer);
    	lfy_trace("%s, free resource, stop record.", __FUNCTION__);
        MsgCmd_Mfree(vrm);
        vrm = NULL;
    }
    else
    {
        //发消息出去重新录像
        local_para_struct *req = (local_para_struct*)\
            MsgCmd_ConstructPara(sizeof(local_para_struct));

        lfy_trace("%s, pose contiue record request.", __FUNCTION__);
        mmi_frm_set_protocol_event_handler(
            MSG_ID_MC_CONT_RECD_VDO,
            (PsIntFuncPtr)msgcmd_VdoRecdContRecdRsp,
            MMI_FALSE);
        MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_CONT_RECD_VDO, (void *)req);                
    }
    
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdDoingCb
** 功能: 录像启动后的回调函数
** 参数: result  -- 录像启动结果
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdDoingCb(MDI_RESULT result)
{
    lfy_trace("%s,L:%d. result=%d.", __FUNCTION__, __LINE__, result);
    if (MDI_RES_VDOREC_SUCCEED != result)
    {
        vrm->stop = MMI_TRUE;
        msgcmd_VdoRecdCyclicTimer(MMI_FALSE);
        msgcmd_VdoRecdSave(vrm->filepath);
    }
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdLayerMngr
** 功能: 录像的显示层管理
** 参数: create  -- 录像启动结果
**       layer   -- 层句柄的地址
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdLayerMngr(MMI_BOOL create, gdi_handle *layer)
{
    if (NULL == layer)
        return;

    lfy_trace("%s, create=%d.", __FUNCTION__, create);
    if (create)
    {
        U8 *temp;
        S32 h = 240, w = 320;
        
        /* enable multi-layer */
        gdi_layer_multi_layer_enable();
        
        //create layer resource
        gdi_layer_get_buffer_ptr(&temp);
        ASSERT(temp != NULL);
        gdi_layer_create_using_outside_memory(0, 0, w, h, layer, temp, w*h*2);
        gdi_layer_push_and_set_active(*layer);
        gdi_layer_set_background(GDI_COLOR_BLACK);
        gdi_layer_set_position(0, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_set_blt_layer(*layer, 0, 0, 0);
        
//        gdi_layer_get_base_handle(layer);
//        gdi_layer_push_and_set_active(*layer);
//        gdi_layer_get_buffer_ptr(&temp);
//		gdi_layer_create_using_outside_memory(0, 0, w, h, layer, temp, w*h*2);
//		gdi_layer_set_active(*layer);
//        gdi_layer_clear(GDI_COLOR_BLACK);
    }
    else
    {
        gdi_layer_push_and_set_active(*layer);
        //gdi_layer_set_background(GDI_COLOR_RED);
        gdi_layer_clear(GDI_COLOR_RED);
        gdi_layer_pop_and_restore_active();
        
        //free layer resource
        gdi_layer_free(*layer);
        *layer = GDI_NULL_HANDLE;
		//gdi_layer_pop_and_restore_active();

        /* enable multi-layer */
        gdi_layer_multi_layer_disable();
    }
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdPowerMngr
** 功能: 录像电源管理
** 参数: on  -- 是否打开电源
** 返回: 打开/关闭电源是否成功
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdPowerMngr(MMI_BOOL on)
{
    MDI_RESULT ret;
    
    if (on)
    {
        //mdi_video_set_camera_id(0);
        /* camera power up */
        ret = mdi_video_rec_power_on(0);
        /* open LED */
    	//MsgCmd_isink(MMI_TRUE);
        /* stop bg music */
        mdi_audio_suspend_background_play();
        /* 
        * This is used to solve a very rare situation. When playing a IMELODY 
        * with backlight on/off, and the screen previous to this screen is a 
        * horizontal screen. Before enter this screen, the IMELODY turn off the
        * backlight. While exit previous screen, the layer rotate back to normal
        * size and the content is not correct. So when calling TurnOnBacklight, 
        * LCD is in sleepin state and draw wrong content to LCD.
        * So we need to clear the buffer first to avoid this situation.
        */
        /* stop MMI sleep */
        //TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
        /* force all playing keypad tone off */
        srv_profiles_stop_tone((srv_prof_tone_enum)GetCurKeypadTone());
        /* disable key pad tone */
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
        /* disalbe align timer  */
        UI_disable_alignment_timers();
        /* stop LED patten */
        srv_pattern_send_req_to_hw(srv_led_pattern_get_bg_pattern(), 0);
    }
    else
    {
        /* shut down camera */
        ret = mdi_video_rec_power_off();
        /* resume alignment timer */
        UI_enable_alignment_timers();
        /* resume LED patten */
    	//StartLEDPatternBackGround();
        /* resume LED patten */
        srv_pattern_play_req(srv_led_pattern_get_bg_pattern(), 1);
        /* let MMI can sleep */
    	//TurnOffBacklight();
        /* resume background audio */
        mdi_audio_resume_background_play();
        /* re-enable keypad tone */
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
        /* close LED */
    	//MsgCmd_isink(MMI_FALSE);
    }

    lfy_trace("%s, on=%d, ret=%d.", __FUNCTION__, on, ret);
    return (MMI_BOOL)(MDI_RES_VDOREC_SUCCEED == ret);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdPreview
** 功能: 录像预览
** 参数: start  -- 开始/停止预览
** 返回: 开始/停止预览是否成功
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdPreview(MMI_BOOL start, gdi_handle layer)
{
    MDI_RESULT ret;
    
    if (start)
    {
        mdi_video_setting_struct video_preview_data;		

        mdi_video_rec_load_default_setting(&video_preview_data);

        video_preview_data.wb = MDI_VIDEO_WB_AUTO;
        video_preview_data.ev = MDI_VIDEO_EV_0;
        video_preview_data.banding = MDI_VIDEO_BANDING_50HZ;
        video_preview_data.effect  = MDI_VIDEO_EFFECT_NOMRAL;
        video_preview_data.night   = FALSE;
        video_preview_data.hue     = 0;
        video_preview_data.preview_rotate = MDI_VIDEO_PREVIEW_ROTATE_0;
        video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_0;
        video_preview_data.size_limit = 0;
        video_preview_data.time_limit = 0;
        video_preview_data.record_aud = TRUE;
        video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_HVGA;
        video_preview_data.video_qty  = MDI_VIDEO_REC_QTY_FINE;
    #if defined(MP4_ENCODE)
    	video_preview_data.video_format    = MDI_VIDEO_VIDEO_FORMAT_3GP;
    #elif defined(MJPG_ENCODE)
    	video_preview_data.video_format    = MDI_VIDEO_VIDEO_FORMAT_MJPEG;
    #else
    	MMI_ASSERT(0);
    #endif
        video_preview_data.storage         = MDI_VIDEO_REC_STORAGE_SD;

		ret = mdi_video_rec_preview_start(
					layer,
					GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
					GDI_LAYER_ENABLE_LAYER_1,
					MMI_FALSE,
					&video_preview_data);
    }
    else
    {
         ret = mdi_camera_preview_stop();
    }
    
    lfy_trace("%s, start=%d, ret=%d.", __FUNCTION__, start, ret);
    return (MMI_BOOL)(MDI_RES_VDOREC_SUCCEED == ret);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdDoing
** 功能: 开始录像
** 参数: filepath -- 文件存放路径
** 返回: 是否成功执行录像
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdDoing(WCHAR *filepath)
{
    MDI_RESULT ret;

    msgcmd_VdoRecdFreeSpaceCheck();
    
    ret = mdi_video_rec_record_start((S8*)filepath, msgcmd_VdoRecdDoingCb, NULL);
    lfy_trace("%s, ret=%d.", __FUNCTION__, ret);
    if (MDI_RES_VDOREC_SUCCEED == ret)
        msgcmd_VdoRecdCyclicTimer(MMI_TRUE);
    
    return (MMI_BOOL)(MDI_RES_VDOREC_SUCCEED == ret);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdDelete
** 功能: 删除未保存的文件
** 参数: filepath -- 文件存放路径
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdDelete(WCHAR *filepath)
{
    mdi_video_rec_delete_unsaved_file((S8*)filepath);
    lfy_trace("%s.", __FUNCTION__);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdSafe
** 功能: 保存录像文件
** 参数: filepath -- 文件存放路径
** 返回: 保存结果
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdSave(WCHAR *filepath)
{
    MDI_RESULT ret = MDI_RES_VDOREC_SUCCEED;

    ret = mdi_video_rec_record_stop();
    lfy_trace("%s, L:%d. ret=%d.", __FUNCTION__, __LINE__, ret);
    
    ret = mdi_video_rec_save_file((S8*)filepath, msgcmd_VdoRecdSaveCb, NULL);
    lfy_trace("%s, L:%d. ret=%d.", __FUNCTION__, __LINE__, ret);
    
    if (MDI_RES_VDOREC_SUCCEED != ret)
    {
        msgcmd_VdoRecdPreview(MMI_FALSE, vrm->dispLayer);
        msgcmd_VdoRecdPowerMngr(MMI_FALSE);
        msgcmd_VdoRecdLayerMngr(MMI_FALSE, &vrm->dispLayer);
        MsgCmd_Mfree(vrm);
        vrm = NULL;
    }
    
    return (MMI_BOOL)(MDI_RES_VDOREC_SUCCEED == ret);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdTimerCyclic
** 功能: 定时器的回调函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdTimerCyclic(void)
{
    U64 time = 0;
    
    if (NULL == vrm)
        return;

    mdi_video_rec_get_cur_record_time(&time);
#if defined(WIN32)
    vrm->timeCount += (U32)(time/1000);
#else
    vrm->timeCount = (U32)(time/1000);
#endif
    //lfy_trace("%s, timeCount=%dS. saveGap=%dS.", __FUNCTION__, vrm->timeCount, vrm->saveGap);
    if (vrm->timeCount >= vrm->saveGap)
    {
        //save
        vrm->stop = MMI_FALSE;
        lfy_trace("%s, timeCount=%dS,saveGap=%dS,left=%dS,forever=%d.save.",
            __FUNCTION__, vrm->timeCount, vrm->saveGap, vrm->time, vrm->forever);
        msgcmd_VdoRecdSave(vrm->filepath);
    }
    else
    {
        msgcmd_VdoRecdCyclicTimer(MMI_TRUE);
    }
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdCyclicTimer
** 功能: 定时器操作
** 参数: start -- 启动/停止
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdCyclicTimer(MMI_BOOL start)
{
    if (NULL == vrm)
        return;
    
    if (start)
        StartTimer(
            MSGCMD_VDORECD_CYCLIC_TIMER_ID, 
            MSGCMD_VDORECD_CYCLIC_TIMER_TIME,
            msgcmd_VdoRecdTimerCyclic);
    else
        StopTimer(MSGCMD_VDORECD_CYCLIC_TIMER_ID);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdResponse
** 功能: 录像启动/停止请求响应函数
** 参数: p -- MsgcmdVdoProcReq
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdResponse(void *p)
{
    MsgcmdVdoProcReq *rsp = (MsgcmdVdoProcReq*)p;

    if (rsp->record)
    {
        MsgCmd_VdoRecdStart(
            rsp->forever, 
            rsp->recdTime, 
            rsp->saveGap,
            strlen(rsp->number) ? rsp->number : NULL);
    }
    else
    {
        MsgCmd_VdoRecdStop(strlen(rsp->number) ? rsp->number : NULL);
    }
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdContRecdRsp
** 功能: 继续录像的消息响应
** 参数: p -- 
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdContRecdRsp(void *p)
{
    mmi_frm_clear_protocol_event_handler(
        MSG_ID_MC_CONT_RECD_VDO,
        (PsIntFuncPtr)msgcmd_VdoRecdContRecdRsp);

    if (NULL != vrm)
    {
        msgcmd_VdoRecdPreview(MMI_TRUE, vrm->dispLayer);
        msgcmd_VdoRecdGetFilePath(vrm->filepath, (MSGCMD_FILE_PATH_LENGTH+1)*sizeof(WCHAR));
        kal_sleep_task(20);
        
        if (!msgcmd_VdoRecdDoing(vrm->filepath))
        {
            msgcmd_VdoRecdPreview(MMI_FALSE, vrm->dispLayer);
            msgcmd_VdoRecdPowerMngr(MMI_FALSE);
            msgcmd_VdoRecdLayerMngr(MMI_FALSE, &vrm->dispLayer);
        	lfy_trace("%s, free resource, stop record.", __FUNCTION__);
            MsgCmd_Mfree(vrm);
            vrm = NULL;
        }
    }
}

/*******************************************************************************
** 函数: MsgCmd_VdoRecdGetContext
** 功能: 获取录像管理变量的地址
** 参数: 无
** 返回: 返回管理变量的地址
** 作者: wasfayu
*******/
VdoRecdMngr *MsgCmd_VdoRecdGetContext(void)
{
    return vrm;
}

/*******************************************************************************
** 函数: MsgCmd_VdoRecdSetAppend
** 功能: 增加一段录像时间
** 参数: 无
** 返回: 返回设置是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdSetAppend(void)
{
    if (vrm)
    {
    	lfy_trace("%s, set append flag TRUE.", __FUNCTION__);
        vrm->append = MMI_TRUE;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*******************************************************************************
** 函数: MsgCmd_VdoRecdBusy
** 功能: 判断是否正在录像
** 参数: 无
** 返回: 返回_TRUE表示正在录像; 返回_FALSE表示没有任何录像
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdBusy(void)
{
    return (MMI_BOOL)(NULL != vrm);
}

/*******************************************************************************
** 函数: MsgCmd_VdoRecdStop
** 功能: 停止录像录像
** 参数: replay_number -- 表示回复停止结果到指定号码, 如果为空则表示不回复
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_VdoRecdStop(char *replay_number)
{    
    lfy_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");

    if (vrm)
    {
        vrm->stop = MMI_TRUE;
        msgcmd_VdoRecdCyclicTimer(MMI_FALSE);
        msgcmd_VdoRecdSave(vrm->filepath);
    }
}

/*******************************************************************************
** 函数: MsgCmd_VdoRecdStart
** 功能: 启动录像
** 参数: forever       -- 是否无限时长录像
**       time_in_sec   -- 录像时长, 以秒为单位, 如果forever为真, 则忽略改参数
**       auto_save_gap -- 自动保存间隔, 以秒为单位
**       replay_number -- 表示回复启动结果到指定号码, 如果为空则表示不回复
** 返回: 启动是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdStart(
    MMI_BOOL forever, 
    U32      time_in_sec, 
    U32      auto_save_gap,
    char    *replay_number)
{
    S32 drive;
    
    lfy_trace(
        "%s, forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

    if (MsgCmd_VdoRecdBusy())
        return MMI_FALSE;

    if (!forever && time_in_sec <= msgcmd_GetVdoRecdArgs()->ignore_time)
        return MMI_FALSE;

    //T卡不存在就返回
    //if (!MsgCmd_GetTFcardDrive(NULL))
    //    return MMI_FALSE;
    
#ifdef __MMI_UCM__
    //reference: mmi_vdorec_is_in_bgcall()
    if (0 != srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
        return MMI_FALSE;
#else
    if (0 != srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
        return MMI_FALSE;
#endif

    //磁盘未获取到
    if ((drive = MsgCmd_GetUsableDrive()) < 0)
        return MMI_FALSE;

    //获取的盘符是否正确挂载--就是是否存在的一个意思
    if (!MsgCmd_CheckValidDrive(drive))
        return MMI_FALSE;
    else
    {
        WCHAR buffer[MSGCMD_FILE_PATH_LENGTH+1];

        msgcmd_VdoRecdGetSavePath(
            buffer, 
            MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR));
        
        //是否有未保存过的视频
        if (mdi_video_rec_has_unsaved_file((S8*)buffer))
        {
            MDI_RESULT ret;
            
            //保存之?删除之?
            lfy_trace("%s, L:%d, has unsaved video, delete.", __FUNCTION__, __LINE__);
            //mdi_video_rec_delete_unsaved_file((S8*)buffer);
            msgcmd_VdoRecdGetFilePath(buffer, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
            ret = mdi_video_rec_save_file((S8*)buffer, NULL, NULL);
            lfy_trace("%s, L:%d, save ret=%d..", __FUNCTION__, __LINE__, ret);
        }
    }
    
    vrm = (VdoRecdMngr*)MsgCmd_Malloc(sizeof(VdoRecdMngr), 0);
    vrm->forever = forever;
    vrm->saveGap = auto_save_gap ? auto_save_gap : msgcmd_GetVdoRecdArgs()->save_gap;
    vrm->time    = time_in_sec ? time_in_sec : vrm->saveGap;
    if (!vrm->forever && vrm->time < vrm->saveGap)
        vrm->saveGap = vrm->time;
    
    if (replay_number && replay_number[0] != '\0')
        strcpy(vrm->number, replay_number);
    else
        vrm->number[0] = '\0';

    msgcmd_VdoRecdGetFilePath(vrm->filepath, MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR));
    msgcmd_VdoRecdLayerMngr(MMI_TRUE, &vrm->dispLayer);
    
    if (msgcmd_VdoRecdPowerMngr(MMI_TRUE) &&
        msgcmd_VdoRecdPreview(MMI_TRUE, vrm->dispLayer))
    {
        vrm->status = VDO_STATUS_PREVIEW;
        
        //MsgCmd_DelayTick(MSGCMD_VDORECD_DLY_TICK);
        kal_sleep_task(20);
        if (msgcmd_VdoRecdDoing(vrm->filepath))
        {
            vrm->status = VDO_STATUS_RECODING;
        }
        else
        {
            MsgCmd_VdoRecdStop(vrm->number);
            MsgCmd_DelayTick(MSGCMD_VDORECD_DLY_TICK);
        }
    }
    else
    {
        msgcmd_VdoRecdPowerMngr(MMI_FALSE);
        msgcmd_VdoRecdLayerMngr(MMI_FALSE, &vrm->dispLayer);
        MsgCmd_Mfree(vrm);
        vrm = NULL;
    }
    
    return (MMI_BOOL)(vrm != NULL);
}
#endif


#if 1//defined(__MSGCMD_DTMF__)
#if !defined(__KEY_TONE_DETECTION__)
#error "Please define __KEY_TONE_DETECTION__"
#endif

/*
 * 必须在提示音播放完毕之后才能开启按键检测, 否则会造成按键误检测
 * 如果自定义提示音播放失败, 则要播放系统的提示音
 * 如果提示音播放失败, 则直接进入按键检测
 */

#define dtmf_trace lfy_trace

extern U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen);
#if defined(__TEST_PLAY_AUDIO__)
static WCHAR *dtmf_TestPlayVoiceGetFolderPath(WCHAR *buffer);
static void dtmf_TestPlayVoiceTraceName(WCHAR *file);
static void dtmf_TestPlayVoicePlayCb(mdi_result result, void *usd);
static MMI_BOOL dtmf_TestPlayVoicePlay(WCHAR *filepath, void *usd);
static void dtmf_TestPlayVoiceEndCall(void);
static void dtmf_TestPlayVoiceTimerCb(void *inp);
static void dtmf_TestPlayVoice(void);
#endif
static void dtmf_CmdExecRsp(void *p);
static void dtmf_PostCmdExecReq(DtmfCommand cmd, char *number, void *param);
static void dtmf_ReleaseAllActivedCall(MMI_BOOL exec);
static void dtmf_KeyDetectTimeoutCb(void);
static void dtmf_SwitchFSMStatus(void);
static void dtmf_KeyDetectCallback(S16 key);
static void dtmf_StartKeyDetect(U32 timeout);
static void dtmf_StopKeyDetect(void);
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index);
static void dtmf_PlayCustomPromptVoiceFileCb(mdi_result result, void *usd);
static void dtmf_PlaySystemPromptVoiceFileCb(mdi_result result, void *usd);
static MMI_ID_TYPE dtmf_GetSystemVoiceFileId(DtmfVoiceIndex idx);
static MMI_BOOL dtmf_PlayCustomVoiceFile(DtmfVoiceIndex idx, void *usd);
static MMI_BOOL dtmf_PlaySystemVoiceFile(DtmfVoiceIndex idx, void *usd);
static MMI_BOOL dtmf_PlayPromptVoiceFile(DtmfVoiceIndex idx, void *usd);
static void dtmf_AutoAnswerResponse(void *p);

static DtmfControl dtmfCnxt;

const static VoiceAttr voiceTab[] = {
    {DTMF_VOC_NO_VOICE       , "0Silence.wav"},
    {DTMF_VOC_PRESS_TO_ENTRY , "1Entry.wav"},
    {DTMF_VOC_INPUT_PASSWORD , "2Password.wav"},
    {DTMF_VOC_CHOOSE_OPTION  , "3Option.wav"},
    {DTMF_VOC_RETRY_INPUT    , "4Retry.wav"},
    {DTMF_VOC_ERROR_TO_EXIT  , "5Warn.wav"},
    {DTMF_VOC_ACCEPT_REQUEST , "6Accept.wav"},
    {DTMF_VOC_INPUT_PARAM    , "7Param.wav"},
    {DTMF_VOC_RETRY_PASSWORD , "8RetryPwd.wav"},
};

/*******************************************************************************
** 函数: Dtmf_Reset
** 功能: 参数复位
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Reset(void)
{
    memset(&dtmfCnxt, 0, sizeof(DtmfControl));
    dtmfCnxt.hotKey     = DTMF_HOT_KEY_VALUE;
#if defined(__TEST_PLAY_AUDIO__)
    dtmfCnxt.testKey    = DTMF_TEST_KEY_VALUE;
#endif
    dtmfCnxt.rptMax     = DTMF_MAX_REPEAT_TIMES;
    dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
}

/*******************************************************************************
** 函数: Dtmf_Initialize
** 功能: 初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Initialize(void)
{
    Dtmf_Reset();
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_DTMF_ANSWER_CALL,
        (PsIntFuncPtr)dtmf_AutoAnswerResponse,
        MMI_FALSE);

#if !defined(__EXEC_IN_TIMER_CBF__)
    mmi_frm_set_protocol_event_handler(
        MSG_ID_DTMF_EXEC_CMD_REQ,
        (PsIntFuncPtr)dtmf_CmdExecRsp,
        MMI_FALSE);
#endif
}

#if defined(__TEST_PLAY_AUDIO__)

static WCHAR *dtmf_TestPlayVoiceGetFolderPath(WCHAR *buffer)
{
    kal_wsprintf(buffer, "%c:\\%w\\", MsgCmd_GetUsableDrive(), DTMF_VOICE_MAIN_PATH);
}

static void dtmf_TestPlayVoiceTraceName(WCHAR *file)
{
    if (file)
    {
        char buffer[256];

        memset(buffer, 0, 256);

        app_ucs2_str_to_asc_str(buffer, (S8*)file);
        dtmf_trace("file-\"%s\"", buffer);
    }
}

static void dtmf_TestPlayVoicePlayCb(mdi_result result, void *usd)
{    
    dtmf_trace("Play voice Callback result is %d.", result);

    StartTimerEx(TIMER_DTMF_KEY_DETECT, 500, dtmf_TestPlayVoiceTimerCb, usd);
}

static MMI_BOOL dtmf_TestPlayVoicePlay(WCHAR *filepath, void *usd)
{
    mdi_result result;
    WCHAR abspath[128];
    
    if (!mdi_audio_snd_is_idle())
    {
        mdi_audio_snd_stop();
    }

    memset(abspath, 0, 128*sizeof(WCHAR));
    dtmf_TestPlayVoiceGetFolderPath(abspath);
    app_ucs2_strcat((S8*)abspath, (const S8 *)filepath);
    dtmf_TestPlayVoiceTraceName(abspath);
        
    result = mdi_audio_snd_check_file_format(abspath);
    dtmf_trace("Check voice return %d.", result);
    
    if (result == MDI_AUDIO_SUCCESS)
    {
        result = mdi_audio_snd_play_file_with_vol_path(
                    (void*)abspath,
                    1,
                    dtmf_TestPlayVoicePlayCb,
                    usd,
                    6,
                    MDI_DEVICE_SPEAKER2);
        dtmf_trace("Play voice return %d.", result);
    }
    
    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == result);
}

static void dtmf_TestPlayVoiceEndCall(void)
{
    srv_ucm_result_enum ret;
    
    ret = mmi_ucm_simple_option(SRV_UCM_END_ALL_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    dtmf_trace("Release Call return %d.", ret);
}

static void dtmf_TestPlayVoiceTimerCb(void *inp)
{
    FS_HANDLE fd = (FS_HANDLE)inp;
    WCHAR file[128];
    FS_DOSDirEntry info;

    memset(file, 0, 128*sizeof(WCHAR));
    if (NULL == fd)
    {
        WCHAR buffer[128];
        
        memset(buffer, 0, 128*sizeof(WCHAR));
        dtmf_TestPlayVoiceGetFolderPath(buffer);
        app_ucs2_strcat((S8*)buffer, (const S8*)L"*.*");
        
        fd = FS_FindFirst(buffer, 0, FS_ATTR_HIDDEN|FS_ATTR_VOLUME|FS_ATTR_DIR, &info, file, 63);
        if (fd < FS_NO_ERROR)
        {
            dtmf_TestPlayVoiceEndCall();
            return;
        }
    }
    else if (FS_FindNext(fd, &info, file, 63) < FS_NO_ERROR)
    {
        dtmf_TestPlayVoiceEndCall();
        FS_FindClose(fd);
        return;
    }

    //如果没有电话在通话中
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        dtmf_TestPlayVoiceEndCall();
        FS_FindClose(fd);
        return;
    }
    
    //play voice
    if (!dtmf_TestPlayVoicePlay(file, (void*)fd))
    {
        StartTimerEx(TIMER_DTMF_KEY_DETECT, 1000, dtmf_TestPlayVoiceTimerCb, (void*)fd);
    }
}

static void dtmf_TestPlayVoice(void)
{
    StartTimerEx(TIMER_DTMF_KEY_DETECT, 200, dtmf_TestPlayVoiceTimerCb, NULL);
}
#endif

/*******************************************************************************
** 函数: dtmf_CmdExecRsp
** 功能: 执行命令
** 参数: p -- DtmfCmdExecReq
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_CmdExecRsp(void *p)
{
    DtmfCmdExecReq *rsp = (DtmfCmdExecReq*)p;

    switch(rsp->command)
    {
    case DTMF_CMD_CAPTURE:
        dtmf_trace("%s, CAPTURE.", __FUNCTION__);
        MsgCmd_CaptureEntry(rsp->number);
        break;
        
    case DTMF_CMD_ADORECD:
        dtmf_trace("%s, AUDIO RECORD.", __FUNCTION__);
        break;
        
    case DTMF_CMD_VDORECD:
        dtmf_trace("%s, VIDEO RECORD.", __FUNCTION__);
        {
            MsgCmdRecdArg *vsp = msgcmd_GetVdoRecdArgs();
            
            if (NULL == rsp->param || (U32)rsp->param == 0)
                MsgCmd_VdoRecdStart(MMI_TRUE, 0, vsp->save_gap, rsp->number);
            else
                MsgCmd_VdoRecdStart(
                    MMI_FALSE,
                    (U32)rsp->param < vsp->min_time ? vsp->min_time : (U32)rsp->param,
                    vsp->save_gap,
                    rsp->number);
        }
        break;
        
    default:
        break;
    }
    
#if defined(__EXEC_IN_TIMER_CBF__)
    MsgCmd_DestructPara(p);
#endif
}

/*******************************************************************************
** 函数: dtmf_PostCmdExecReq
** 功能: 发送命令执行请求
** 参数: cmd    -- 预执行的命令
**       number -- 回复消息的号码
**       param  -- 具体参数
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_PostCmdExecReq(DtmfCommand cmd, char *number, void *param)
{
    DtmfCmdExecReq *req = (DtmfCmdExecReq *)MsgCmd_ConstructPara(sizeof(DtmfCmdExecReq));

    req->command = cmd;
    req->param   = param;
    if (NULL != number)
    {
        strcpy(req->number, number);
    }

    dtmf_trace("%s, cmd=%d.", __FUNCTION__, cmd);
    //延时2秒钟去执行, 否则容易引起问题
#if defined(__EXEC_IN_TIMER_CBF__)
    StartTimerEx(TIMER_DTMF_DELAY_EXEC, 2000, dtmf_CmdExecRsp, (void *)req);
#else
    MsgCmd_SendIlm2Mmi(MSG_ID_DTMF_EXEC_CMD_REQ, (void*)req);
#endif
}

/*******************************************************************************
** 函数: dtmf_ReleaseAllActivedCall
** 功能: 挂断所有电话
** 参数: exec -- 是否执行命令
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_ReleaseAllActivedCall(MMI_BOOL exec)
{   
    srv_ucm_result_enum ret;
    
    //挂断电话
    ret = mmi_ucm_simple_option(SRV_UCM_END_ALL_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    dtmf_trace("Release Call return %d.", ret);
    
    AlmEnableExpiryHandler();

    if (exec)
    {
        //发送消息去执行命令
        dtmf_PostCmdExecReq(dtmfCnxt.command, dtmfCnxt.call.number, NULL);
    }
}

/*******************************************************************************
** 函数: dtmf_KeyDetectTimeoutCb
** 功能: 按键检测超时回调函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_KeyDetectTimeoutCb(void)
{
    MMI_BOOL playOK;

    dtmf_StopKeyDetect();

    //达到最大次数, 直接挂断电话
    if (dtmfCnxt.rptCount++ >= dtmfCnxt.rptMax)
    {
        dtmf_ReleaseAllActivedCall(MMI_FALSE);
        Dtmf_Reset();
        return;
    }
    
    //重新播放提示语
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
        //正在等待进入, 按键检测超时, 重复播放
        //系统进入, 播放提示语 1Entry.wav
        dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
        if (!playOK)
        {
            //播放失败则进入按键检测
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
    case DTMF_STATE_INPUT_PWD:
        //等待输入密码, 超时则重复播放
        dtmfCnxt.param.password[7] = 0;
        break;
        
    case DTMF_STATE_CHOOSE_OPTION:
        break;
        
    case DTMF_STATE_INPUT_PARAM:
        break;
        
    case DTMF_STATE_IDLE:
    case DTMF_STATE_GOODBYE:
    case DTMF_STATE_MAX_ENUM:
    default:
        break;
    }
    
}

/*******************************************************************************
** 函数: dtmf_SwitchFSMStatus
** 功能: 切换状态机的状态
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_SwitchFSMStatus(void)
{
    MMI_BOOL playOK;

    dtmf_trace("%s: ENTRY state=%d.", __FUNCTION__,dtmfCnxt.state);
    
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_IDLE:
        //系统进入, 播放提示语 1Entry.wav
        dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_WAITING_ENTRY;
        if (!playOK)
        {
            //播放失败则进入按键检测
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
    case DTMF_STATE_WAITING_ENTRY:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //系统已经进入, 播放提示语 2Password.wav
    #if defined(__NEED_CHECK_PASSWORD__)
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PASSWORD, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
    #else
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
    #endif
        if (!playOK)
        {
            //播放失败则进入按键检测
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
#if defined(__NEED_CHECK_PASSWORD__)
    case DTMF_STATE_INPUT_PWD:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //检查密码是否有效
        if (dtmfCnxt.param.password[7] == 6 &&
            strncmp(dtmfCnxt.param.password, "123456", 6) == 0)
        {
            //播放提示语 3Option.wav
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
            dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
            if (!playOK)
            {
                //播放失败则进入按键检测
                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
            }
        }
        else if (dtmfCnxt.rptCount < dtmfCnxt.rptMax)
        {
            //密码错误
            dtmfCnxt.param.password[7] = 0;
            //播放提示语 3Option.wav
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_RETRY_PASSWORD, (void*)dtmfCnxt.detectTime);
            dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
            if (!playOK)
            {
                //播放失败则进入按键检测
                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
            }
        }
        else
        {
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ERROR_TO_EXIT, NULL);
            dtmfCnxt.state = DTMF_STATE_GOODBYE;

            if (!playOK)
            {
                dtmf_ReleaseAllActivedCall(MMI_TRUE);
            }
        }
        break;
#endif

    case DTMF_STATE_CHOOSE_OPTION:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //播放提示语 7Param.wav
    #if defined(__RECIVE_CMD_PARAMETER__)
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PARAM, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_INPUT_PARAM;
        if (!playOK)
        {
            //播放失败则进入按键检测
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
    #else
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_REQUEST, NULL);
        dtmfCnxt.state = DTMF_STATE_GOODBYE;
    #endif
        break;
        
#if defined(__RECIVE_CMD_PARAMETER__)
    case DTMF_STATE_INPUT_PARAM:
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_ACCEPT_REQUEST, NULL);
        dtmfCnxt.state = DTMF_STATE_GOODBYE;

        if (!playOK)
        {
            dtmf_ReleaseAllActivedCall(MMI_TRUE);
        }
        break;
#endif

    case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(MMI_TRUE);
        break;
        
    case DTMF_STATE_MAX_ENUM:
    default:
        break;
    }

    dtmf_trace("%s: EXIT state=%d.", __FUNCTION__,dtmfCnxt.state);
}

/*******************************************************************************
** 函数: dtmf_KeyDetectCallback
** 功能: 按键检测回调函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_KeyDetectCallback(S16 key)
{
	dtmf_trace("%s: key=0x%x, state=%d.", __FUNCTION__, key, dtmfCnxt.state);

    if (!mdi_audio_snd_is_idle())
    {
        mdi_audio_snd_stop();
    }
    
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_IDLE:
        break;
    case DTMF_STATE_WAITING_ENTRY:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            //输入密码状态
            dtmf_SwitchFSMStatus();
        }
    #if defined(__TEST_PLAY_AUDIO__)
        else if(dtmfCnxt.testKey == (U8)key)
        {
            dtmf_TestPlayVoice();
        }
    #endif
        else
        {
            //按键错误, 重新检测, 播放提示语
            dtmfCnxt.rptCount++;
        }
        break;
        
#if defined(__NEED_CHECK_PASSWORD__)
    case DTMF_STATE_INPUT_PWD:
        if (dtmfCnxt.hotKey == (U8)key)
        {
            mdi_audio_stop_keytone_detect();
            dtmf_SwitchFSMStatus();
        }
        else if (('0' <= (char)key && (char)key <= '9') || '*' <= (char)key)
        {
            U32 index = dtmfCnxt.param.password[7];

            if (index < 6)
            {
                dtmfCnxt.param.password[index] = (char)key;
            }
            dtmfCnxt.param.password[7] ++;
        }
        else
        {
            mdi_audio_stop_keytone_detect();
            //按键错误
        }
        break;
#endif

    case DTMF_STATE_CHOOSE_OPTION:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            dtmf_SwitchFSMStatus();
        }
        else if ('0' <= (char)key && (char)key <= '9')
        {
            dtmfCnxt.command = (char)key - '0';
            dtmf_SwitchFSMStatus();
        }
        else
        {
            //输入有误, 重新输入
            dtmfCnxt.rptMax ++;
        }
        break;

#if defined(__RECIVE_CMD_PARAMETER__)
    case DTMF_STATE_INPUT_PARAM:
        mdi_audio_stop_keytone_detect();
        if (dtmfCnxt.hotKey == (U8)key)
        {
            dtmf_SwitchFSMStatus();
        }
        else
        {
            //记录参数
        }
        break;
#endif

    case DTMF_STATE_GOODBYE:
        break;
    case DTMF_STATE_MAX_ENUM:
    default:
        break;
    }
}

/*******************************************************************************
** 函数: dtmf_StartKeyDetect
** 功能: 开始DTMF的按键检测
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_StartKeyDetect(U32 timeout)
{
    mdi_result ret;

    ret = mdi_audio_start_keytone_detect(dtmf_KeyDetectCallback);
    dtmf_trace("%s: time=%d,ret=%d,curr state=%d.", __FUNCTION__, timeout, ret, dtmfCnxt.state);
    if (MDI_AUDIO_SUCCESS == ret)
    {
        StartTimer(TIMER_DTMF_KEY_DETECT, timeout, dtmf_KeyDetectTimeoutCb);
        dtmfCnxt.start = MMI_TRUE;
    }
    else
    {
        //失败了, 重新提示
    }
}

/*******************************************************************************
** 函数: dtmf_StopKeyDetect
** 功能: 停止DTMF按键检测
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_StopKeyDetect(void)
{
    StopTimer(TIMER_DTMF_KEY_DETECT);
    if (dtmfCnxt.start)
    {
        mdi_audio_stop_keytone_detect();
        dtmfCnxt.start = MMI_FALSE;
    }
}

/*******************************************************************************
** 函数: dtmf_CombineVoiceFilePath
** 功能: 构建语音文件路径
** 参数: output   -- 文件绝对路径输出
**       fileindex-- 文件索引
** 返回: output的地址
** 作者: wasfayu
*******/
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index)
{
    ASSERT(NULL != output);

    kal_wsprintf(output, "%c:\\%w\\%s",
        MsgCmd_GetUsableDrive(),DTMF_VOICE_MAIN_PATH,voiceTab[index].name);
    
    return output;    
}

/*******************************************************************************
** 函数: dtmf_PlayCustomPromptVoiceFileCb
** 功能: 播放用户自定义提示语的回调函数
** 参数: result -- 播放结果
**       usd    -- 用户数据
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_PlayCustomPromptVoiceFileCb(mdi_result result, void *usd)
{
    dtmf_trace("Play custom voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //如果当前状态为xx状态则返回
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        //等待按键检测
    }
    else
    {
        //播放失败, 重新播放系统自带的资源
    }

    switch(dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
    case DTMF_STATE_INPUT_PWD:
    case DTMF_STATE_CHOOSE_OPTION:
    case DTMF_STATE_INPUT_PARAM:
        dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        break;
        
    case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(MMI_TRUE);
        break;
        
    case DTMF_STATE_IDLE:
    default:
        break;
    }
}

/*******************************************************************************
** 函数: dtmf_PlaySystemPromptVoiceFileCb
** 功能: 播放系统提示语的回调函数
** 参数: result -- 播放结果
**       usd    -- 用户数据
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_PlaySystemPromptVoiceFileCb(mdi_result result, void *usd)
{
    dtmf_trace("Play system voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //如果当前状态为xx状态则返回
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        //等待按键检测
    }
    else
    {
        //播放失败, 不做处理, 直接进行按键检测什么的
    }

    switch(dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
    case DTMF_STATE_INPUT_PWD:
    case DTMF_STATE_CHOOSE_OPTION:
    case DTMF_STATE_INPUT_PARAM:
        dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        break;
        
    case DTMF_STATE_GOODBYE:
        dtmf_ReleaseAllActivedCall(MMI_TRUE);
        break;
        
    case DTMF_STATE_IDLE:
    default:
        break;
    }
}

///*****************************************************************************
// * FUNCTION
// *  get_audio
// * DESCRIPTION
// *  Wrapper for GetAudio() function
// * PARAMETERS
// *  i           [IN]        Audio id
// *  type        [OUT]       Audio type
// *  filelen     [OUT]       File length
// * RETURNS
// *  pointer to the audio raw data corresponding to the given audio ID
// *****************************************************************************/
//U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen)
//{
//    /*----------------------------------------------------------------*/
//    /* Local Variables                                                */
//    /*----------------------------------------------------------------*/
//    U8 *s = NULL;
//
//    /*----------------------------------------------------------------*/
//    /* Code Body                                                      */
//    /*----------------------------------------------------------------*/
//    ASSERT(type != NULL && filelen != NULL);
//
//    *type = 0;;
//    *filelen = 0;
//
//    if (i == 0)
//    {
//        return (NULL);
//    }
//
//    s = (U8*) GetAudio((U16) i);
//    if (s == NULL)
//    {
//        return (NULL);
//    }
//    if (s[0] == '\0')
//    {
//        return (NULL);
//    }
//
//    *type = s[0];
//
//    *filelen |= (U32) (s[1]);
//    *filelen |= (U32) ((U32) s[2] << 8);
//    *filelen |= (U32) ((U32) s[3] << 16);
//    *filelen |= (U32) ((U32) s[4] << 24);
//
//    return (s + 8);
//}

/*******************************************************************************
** 函数: dtmf_GetSystemVoiceFileId
** 功能: 获取系统提示音的文件ID
** 参数: idx  -- 语音资源索引
** 返回: 系统语音资源ID
** 作者: wasfayu
*******/
static MMI_ID_TYPE dtmf_GetSystemVoiceFileId(DtmfVoiceIndex idx)
{
    switch(idx)
    {
    case DTMF_VOC_PRESS_TO_ENTRY :
        return MC_DTMF_VOC_WELCOME;
        
    case DTMF_VOC_INPUT_PASSWORD :
        return MC_DTMF_VOC_PASSWORD;
        
    case DTMF_VOC_CHOOSE_OPTION  :
        return MC_DTMF_VOC_OPTION;
        
    case DTMF_VOC_RETRY_INPUT    :
        return MC_DTMF_VOC_RETRY;
        
    case DTMF_VOC_ERROR_TO_EXIT  :
        return MC_DTMF_VOC_ERROR;
        
    case DTMF_VOC_ACCEPT_REQUEST :
        return MC_DTMF_VOC_ACCEPT;
        
    case DTMF_VOC_INPUT_PARAM    :
        return MC_DTMF_VOC_PARAM;
        
    case DTMF_VOC_RETRY_PASSWORD:
        
    case DTMF_VOC_NO_VOICE       :
    default:
        return MC_DTMF_VOC_WELCOME;
    }
}

/*******************************************************************************
** 函数: dtmf_PlayCustomVoiceFile
** 功能: 播放用户提示语
** 参数: idx  -- 语音资源索引
**       cbf  -- 回调函数
** 返回: 是否播放成功
** 作者: wasfayu
*******/
static MMI_BOOL dtmf_PlayCustomVoiceFile(DtmfVoiceIndex idx, void *usd)
{
    WCHAR filepath[MSGCMD_FILE_PATH_LENGTH+1];
    mdi_result result;

    if (!mdi_audio_snd_is_idle())
    {
        mdi_audio_snd_stop();
    }
    
    memset(filepath, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
    dtmf_CombineVoiceFilePath(filepath, idx);
    
    result = mdi_audio_snd_check_file_format(filepath);
    dtmf_trace("Check custom voice \"%s\", ret=%d.", voiceTab[idx].name, result);
    
    if (result == MDI_AUDIO_SUCCESS)
    {
        result = mdi_audio_snd_play_file_with_vol_path(
                    (void*)filepath,
                    1,
                    dtmf_PlayCustomPromptVoiceFileCb,
                    usd,
                    6,
                    MDI_DEVICE_SPEAKER2);
        dtmf_trace("Play custom voice \"%s\", ret=%d.", voiceTab[idx].name, result);
    }

    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == result);
}

/*******************************************************************************
** 函数: dtmf_PlaySystemVoiceFile
** 功能: 播放系统提示语
** 参数: idx  -- 语音资源索引
**       cbf  -- 回调函数
** 返回: 是否播放成功
** 作者: wasfayu
*******/
static MMI_BOOL dtmf_PlaySystemVoiceFile(DtmfVoiceIndex idx, void *usd)
{
    mdi_result result;
    U32 audio_len;
    U8 *audio_data;
    U8  audio_type;
    MMI_ID_TYPE audio_id = 0;

    audio_id = dtmf_GetSystemVoiceFileId(idx);
    audio_data = get_audio(audio_id, &audio_type, &audio_len);
    dtmf_trace("get system voice: id=%d,type=%d,length=%d.", audio_id, audio_type, audio_len);
    ASSERT(NULL != audio_data);
    
    //播放系统的提示音
    result = mdi_audio_snd_play_string_with_vol_path(
                (void*)audio_data,
                audio_len,
                1,
                dtmf_PlaySystemPromptVoiceFileCb,
                usd,
                6,
                MDI_DEVICE_SPEAKER2);
    dtmf_trace("Play system voice, ret=%d.", result);
    
    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == result);
}

/*******************************************************************************
** 函数: dtmf_PlayPromptVoiceFile
** 功能: 播放提示语
** 参数: idx  -- 语音资源索引
**       cbf  -- 回调函数
** 返回: 是否播放成功
** 作者: wasfayu
*******/
static MMI_BOOL dtmf_PlayPromptVoiceFile(DtmfVoiceIndex idx, void *usd)
{
    MMI_BOOL ret;
    
    ret = dtmf_PlayCustomVoiceFile(idx, usd);

    if (!ret)
        ret = dtmf_PlaySystemVoiceFile(idx, usd);

    return ret;
}

//static void dtmf_EntrySystem(void)
//{
//    dtmf_trace("%s", __FUNCTION__);
//    dtmf_SwitchFSMStatus();
//}

/*******************************************************************************
** 函数: dtmf_AutoAnswerResponse
** 功能: 请求应答来电的消息响应函数
** 参数: p  -- DtmfAutoAnswerReq
** 返回: 无
** 作者: wasfayu
*******/
static void dtmf_AutoAnswerResponse(void *p)
{
    DtmfAutoAnswerReq *rsp = (DtmfAutoAnswerReq*)p;

    AlmDisableExpiryHandler();
    Dtmf_Reset();
    memcpy(&dtmfCnxt.call, &rsp->info, sizeof(DtmfCallInfo));
    
    //StartTimer(TIMER_DTMF_KEY_DETECT, 1500, dtmf_EntrySystem);
    dtmf_SwitchFSMStatus();
}

/*******************************************************************************
** 函数: Dtmf_AutoAnswerReqSend
** 功能: 发送请求应答来电的消息
** 参数: name  -- 来电号码
**       number-- 显示名字
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_AutoAnswerReqSend(WCHAR *name, char *number)
{
    DtmfAutoAnswerReq *req = (DtmfAutoAnswerReq*)\
            MsgCmd_ConstructPara(sizeof(DtmfAutoAnswerReq));

    app_ucs2_strcpy((S8*)req->info.name, (const S8*)name);
    strcpy(req->info.number, number);
    
    dtmf_trace("%s, number=%s.", __FUNCTION__, number);
        
    MsgCmd_SendIlm2Mmi(MSG_ID_DTMF_ANSWER_CALL, (void*)req);
}

#endif/*__MSGCMD_DTMF__*/

/*******************************************************************************
** 函数: lfy_WriteFile
** 功能: 将数据写入文件
** 参数: filepath   -- 文件的绝对路径
**       cover      -- 是否覆盖原来的数据, 否则就是追加在文件末尾
**       data       -- 数据块
**       length     -- 数据块的长度
** 返回: 实际写入的数据长度
** 作者: wasfayu
*******/
U32 lfy_WriteFile(const WCHAR *filepath, MMI_BOOL cover, void *data, U32 length)
{
    FS_HANDLE fd;
    U32 written;
    
    if (NULL == filepath || NULL == data || 0 == length)
        return 0;

    if (cover)
        fd = FS_Open(filepath, FS_READ_WRITE|FS_CREATE_ALWAYS);
    else
        fd = FS_Open(filepath, FS_READ_WRITE|FS_CREATE);

    if (fd < FS_NO_ERROR)
        return 0;

    FS_Seek(fd, 0, FS_FILE_END);
    if (FS_Write(fd, data, length, &written) >= FS_NO_ERROR)
        FS_Commit(fd);
    
    FS_Close(fd);

    return written;
}

/*******************************************************************************
** 函数: lfy_create_path
** 功能: 创建路径
** 参数: dirve     -- 盘符
**       UcsFolder -- 文件夹
** 返回: 无
** 作者: wasfayu
*******/
MMI_BOOL lfy_create_path(char drive, const WCHAR *UcsFolder)
{
    U32 i, slash;
    WCHAR *path, ch;
    FS_HANDLE fd;
 
    
    if (!isalpha(drive) || 
        !srv_fmgr_drv_is_accessible(drive) ||
        NULL == UcsFolder)
        return MMI_FALSE;

    path    = (WCHAR*)MsgCmd_Malloc(256*sizeof(WCHAR), 0);
    path[0] = (WCHAR)drive;
    path[1] = ':';
    path[2] = '\\';

    i       = 0;
    fd      = FS_NO_ERROR;
    
    do {
        //  d:\a\b\c\d\e
        //  d:\\a\b\c\\

        slash   = 1;
        
        while((ch = *UcsFolder++) != (WCHAR)'\0')
        {
            if (ch == '\\' || ch == '/')
            {
                if (0 == slash)
                {
                    path[3+i] = ch;
                    slash = 2;
                    i ++;
                    break;
                }
                continue;
            }
            else
            {
                if (2 == slash)
                {
                    i ++;
                    break;
                }
                
                path[3+i] = ch;
                slash = 0;
            }

            i ++;
            
            if (3+i >= 254)
                break;
        }

        if (ch != '\\' && ch != '/' && path[3+i-1] != '\\' && path[3+i-1] != '/')
        {
            path[3+i] = '/';
            i ++;
        }
        
        //create
        fd = FS_Open((const WCHAR*)path, FS_OPEN_DIR|FS_READ_ONLY);
        if (fd >= FS_NO_ERROR)
            FS_Close(fd);
    	else if ((fd = FS_CreateDir((const WCHAR*)path)) < FS_NO_ERROR)
            break;
        
        if (ch == (WCHAR)'\0')
            break;
            
    }while(3+i < 254);

    MsgCmd_Mfree(path);
    
    return (MMI_BOOL)(fd >= FS_NO_ERROR);
}

/*******************************************************************************
** 函数: lfy_normal_init
** 功能: 初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void lfy_normal_init(void)
{
    char drive;
    
    if ((drive = MsgCmd_GetUsableDrive()) > 0)
    {
        lfy_create_path(drive, MSGCMD_AUDIOS_FOLDER_NAME);
        lfy_create_path(drive, MSGCMD_PHOTOS_FOLDER_NAME);
        lfy_create_path(drive, MSGCMD_VIDEOS_FOLDER_NAME);
    }

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MC_CAPTURE_REQ,
        (PsIntFuncPtr)msgcmd_CaptureResponse,
        MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MC_VDORECD_REQ,
        (PsIntFuncPtr)msgcmd_VdoRecdResponse,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MC_SEND_MMS_REQ,
        (PsIntFuncPtr)msgcmd_SendMMSResponse,
        MMI_FALSE);

    Dtmf_Initialize();
    
    lfy_trace("%s", __FUNCTION__);
}

/*******************************************************************************
** 函数: lfy_event_handler
** 功能: 系统事件响应
** 参数: 事件通知地址
** 返回: 处理结果
** 作者: LeiFaYu
*******/
mmi_ret lfy_event_handler(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_SRV_BOOTUP_EARLY_INIT:
        break;
    case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
        lfy_normal_init();
        break;
    case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
        break;
    case EVT_ID_SRV_BOOTUP_COMPLETED:
        MsgCmd_InterruptMask(MMI_FALSE);
        break;
    case EVT_ID_USB_ENTER_MS_MODE:
        cb_close_log_file();
        break;
    case EVT_ID_USB_PLUG_IN:
        lfy_trace("%s, EVT_ID_USB_PLUG_IN.", __FUNCTION__);
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        mmi_frm_cb_reg_event(EVT_ID_USB_PLUG_OUT, lfy_event_handler, NULL);
        ASSERT(0);
        break;
    case EVT_ID_USB_PLUG_OUT:
        lfy_trace("%s, EVT_ID_USB_PLUG_OUT.", __FUNCTION__);
        mmi_frm_cb_dereg_event(EVT_ID_USB_PLUG_OUT, lfy_event_handler, NULL);
        break;
    default:
        break;
    }
    
    return MMI_RET_OK;
}


#endif
