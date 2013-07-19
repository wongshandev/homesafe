/*******************************************************************************
 *
 * msgcmd_process.c
 *
 * 主要处理录像/录音/拍照/回复短信/回复彩信
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, 创建原始版本
 *
 ******************************************************************************/


#if defined(__MSGCMD_SUPPORT__)
#include "./../inc/msgcmd_process.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_camera.h"
#include "mdi_video.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_srv_sms_def.h"
#include "mmi_rp_app_umms_mms_def.h"
#include "mmi_rp_app_idle_def.h"
#include "mmi_rp_srv_reminder_def.h"
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
#include "fs_func.h"
#include "TimerEvents.h"
#include <ctype.h>
#include "app_str.h"
#include "app_ltlcom.h"
#include "app_asyncfile.h"
#include "ucmsrvgprot.h"
#include "kal_trace.h"
#include "GeneralDeviceGprot.h"
#include "CameraApp.h"
#include "UcmGProt.h"
#include "SimDetectionGprot.h"
#include "mmssrvgprot.h"
#include "SimDetectionStruct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"


/*******************************************************************************
** 函数: MsgCmd_isink
** 功能: 控制LCD背光开关
** 入参: open -- 开关
** 返回: 无
** 作者: wasfayu
*******/
extern void MsgCmd_isink(kal_bool open);


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
** 函数: MsgCmd_GetUsableDrive
** 功能: 获取系统可用的存储设备盘符
** 参数: 
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
** 参数: 
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
** 参数: out       -- 装载输出路径的buffer
**       length    -- out的长度, 以字节为单位, 长度应该大于32个字节以上
**       folder    -- 文件夹的名字, 如 L"audio"
**       ext_name  -- 扩展名的名字, 如 L".mp3"
** 返回: 返回out的地址
** 作者: wasfayu
*******/
WCHAR *MsgCmd_CombineFilePath(
    char *out,
    U16   length,
    const WCHAR *folder,
    const WCHAR *ext_name)
{	
	applib_time_struct mt;
	
	applib_dt_get_date_time(&mt);
	memset(out, 0, length);
	
	kal_wsprintf(
		(WCHAR*)out, 
		"%c:\\%w\\%04d%02d%02d%02d%02d%08X%w", 
		MsgCmd_GetUsableDrive(),
		folder,
		mt.nYear,
		mt.nMonth,
		mt.nDay,
		mt.nHour,
		mt.nMin,
		MsgCmd_GetCurrentTime(),
		ext_name);	

	return (WCHAR*)out;
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
    return drv_get_current_time();
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
** 函数: MsgCmd_Reboot
** 功能: 重启
** 入参: 
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_Reboot(void)
{
    srv_alm_pwr_reset(MMI_TRUE, 1);
}

/*******************************************************************************
** 函数: MsgCmd_RebootExt
** 功能: 延时重启
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_RebootExt(U16 delayS)
{
    if(!delayS)
    {
        MsgCmd_Reboot();
        return;
    }

    delayS = delayS > 1800 ? 1800 : delayS;
    StartTimer(MSGCMD_TIMER_REBOOT, delayS*1000, MsgCmd_Reboot);
}

/*******************************************************************************
** 函数: MsgCmd_Shutdown
** 功能: 关机
** 入参: 
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_Shutdown(void)
{
    srv_shutdown_normal_start(SRV_BOOTUP_MODE_NORMAL);
}

/*******************************************************************************
** 函数: MsgCmd_ShutdownExt
** 功能: 延时关机
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_ShutdownExt(U16 delayS)
{
    if(!delayS)
    {
        MsgCmd_Shutdown();
        return;
    }
    
    delayS = delayS > 1800 ? 1800 : delayS;
    StartTimer(MSGCMD_TIMER_SHUTDOWN, delayS*1000, MsgCmd_Shutdown);
}

/*******************************************************************************
** 函数: MsgCmd_Factory
** 功能: 关机
** 入参: 
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_Factory(void)
{
    RstStartRestore();
}

/*******************************************************************************
** 函数: MsgCmd_FactoryExt
** 功能: 延时关机
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_FactoryExt(U16 delayS)
{
    if(!delayS)
    {
        MsgCmd_Factory();
        return;
    }
    
    delayS = delayS > 1800 ? 1800 : delayS;
    StartTimer(MSGCMD_TIMER_FACTORY, delayS*1000, MsgCmd_Factory);
}

/*******************************************************************************
** 函数: MsgCmd_DeleteFileFront
** 功能: 删除文件的前部
** 入参: fname   -- 文件名, UCS格式
**       deletesz -- 删除大小, 即从文件头开始删除deletesz个字节的数据
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_DeleteFileFront(const WCHAR *fname, U32 deletesz)
{
    MMI_BOOL result;
    U8 *buffer;
    const U32 bufsz = 1024*2;
    U32 count;
    S32 writepos = 0;
    FS_HANDLE fd;

    if (NULL == fname || 0 == deletesz)
        return MMI_TRUE;
    
    fd = FS_Open(fname, FS_READ_WRITE);
    if (fd < 0)
        return MMI_FALSE;
    
    buffer = (U8*)MsgCmd_Malloc(bufsz, 0); //med_alloc_ext_mem
    do{
        result = MMI_FALSE;
            
        //定位到读的位置
        if(FS_Seek(fd, deletesz, FS_FILE_BEGIN) < 0)
            return MMI_FALSE;   

        if(FS_Read(fd, buffer, bufsz, &count) < 0)
            break;

        if(!count)
            break;

        deletesz += count;
        
        //定位到写的位置
        if(FS_Seek(fd, writepos, FS_FILE_BEGIN) < 0)
            break;

        if(FS_Write(fd, buffer, count, &count) < 0)
            break;

        if(!count)
            break;

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
** 函数: msgcmd_WriteImeiRsp
** 功能: 拨打指定号码
** 参数: pnumber -- 指定呼叫号码
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_MakeCall(char *pnumber)
{
#ifdef __MMI_DUAL_SIM_MASTER__
	mmi_ucm_make_call_para_struct param;
#endif
	WCHAR Hotline_number[(20+1)*2] = {
				0x31,0x00, // 1
				0x31,0x00, // 1
				0x32,0x00, // 2
				0x00,0x00
				};

    if (NULL == pnumber)
        return;
    
    app_asc_str_to_ucs2_wcs(Hotline_number, pnumber);
	
#ifndef __MMI_DUAL_SIM_MASTER__ 
	MakeCall(Hotline_number);
#else
    if (!mmi_bootup_is_network_service_available() || !srv_mode_switch_is_network_service_available())
    {
        mc_trace("%s, network not available. number=%s.", __FUNCTION__, pnumber);
        return;
    }

    mc_trace("%s, number=%s.", __FUNCTION__, pnumber);
	mmi_ucm_init_call_para_for_sendkey(&param); 
	param.dial_type = SRV_UCM_SIM1_CALL_TYPE_ALL;
	param.ucs2_num_uri = (U16 *)Hotline_number;
    mmi_ucm_call_launch(0, &param);
#endif
}

/*******************************************************************************
** 函数: msgcmd_WriteImeiRsp
** 功能: 写IMEI的结果回应函数
** 参数:
** 返回: 写的结果请参考 nvram_errno_enum 这个枚举.
** 作者: wasfayu
*******/
static U8 msgcmd_WriteImeiRsp(void *p)
{
#if !defined(WIN32)
    nvram_write_imei_cnf_struct *pinfo = (nvram_write_imei_cnf_struct*)p;

    mmi_frm_clear_protocol_event_handler(
        MSG_ID_NVRAM_WRITE_IMEI_CNF,
        msgcmd_WriteImeiRsp);

    if(NVRAM_ERRNO_SUCCESS == pinfo->result)
    {
        //reboot
        MsgCmd_RebootExt(3);
    }
#endif
    return 1;
}

/*******************************************************************************
** 函数: MsgCmd_WriteImei
** 功能: 写入一个IMEI.
** 入参: num   - IMEI号码字符串
**       strl  - IMEI号码字符串长度
**       sim   - 0-SIM1; 1-SIM2; 2-SIM3; 3-SIM4;
**       rsp   - 回调函数
** 返回: 是否执行成功
** 说明: IMSI共有15位, 其结构为: MCC+MNC+MSIN, (MNC+MSIN=NMSI).
**       MCC:Mobile Country Code, 移动国家码, 
**           MCC的资源由国际电联(ITU)统一分配和管理.
**           唯一识别移动用户所属的国家, 共3位. 中国为460;
**       MNC:Mobile Network Code, 移动网络码, 共2位.
**           中国移动TD系统使用00, 中国联通GSM系统使用01, 
**           中国移动GSM系统使用02, 中国电信CDMA系统使用03.
**           一个典型的IMSI号码为460030912121001;
**       MSIN:Mobile Subscriber Identification Number.
**           共10位, 其结构为:09+M0M1M2M3+ABCD
**           其中的 M0M1M2M3 和 MDN 号码中的 H0H1H2H3 可存在对应关系,
**           ABCD四位为自由分配.
**           可以看出IMSI在MSIN号码前加了MCC即NMSI, 
**           可以区别出每个用户的来自的国家, 因此可以实现国际漫游.
**           在同一个国家内, 如果有多个移动网络运营商, 可以通过MNC来进行区别.
**       SVN: Software Version Number. 
**           软件版本号, 区分同型号手机出厂时使用的不同软件版本.
** 引用: http://zhidao.baidu.com/question/271966166.html
** 资料: http://folk.uio.no/runeheg/imei/
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_WriteImei(char *num, U16 strl, U8 sim, U8 (*rsp)(void*))
{
#if defined(WIN32)
    return MMI_FALSE;
#else
    U8 i;
    char ibuf[SRV_IMEI_MAX_LEN+2] = {0};
    module_type src = MOD_MMI;//stack_get_active_module_id();//只能是MOD_MMI
    nvram_write_imei_req_struct *pmsg = (nvram_write_imei_req_struct*)\
        construct_local_para(sizeof(nvram_write_imei_req_struct), TD_CTRL|TD_RESET);
    
    if(strl < SRV_IMEI_MAX_LEN)
    {
        return MMI_FALSE;
    }

    if(sim >= MMI_MAX_SIM_NUM)
    {
        return MMI_FALSE;
    }
    
    for(i=0; i<strl; i++)
    {
        if(!(*(num+i) >= '0' && *(num+i) <= '9'))
        {
            return MMI_FALSE;
        }
    }
        
    memcpy((void*)ibuf, (void*)num, SRV_IMEI_MAX_LEN);
    if(SRV_IMEI_MAX_LEN % 2)
        ibuf[SRV_IMEI_MAX_LEN] = 0xFF;

    //NVRAM_EF_IMEI_IMEISV_LID
    //nvram_ef_imei_imeisv_struct
    for(num=ibuf,i=0; i<(SRV_IMEI_MAX_LEN+1)/2; i++)
    {
        pmsg->imei[i] = (*(num)&0x0F) | (*(num+1)<<4);
        num += 2;
    }
    pmsg->svn = 0x01;
    pmsg->access_id = sim + 1;
    pmsg->record_index = sim + 1;
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_NVRAM_WRITE_IMEI_CNF,
        rsp == NULL ? msgcmd_WriteImeiRsp : rsp,
        MMI_FALSE);

    MsgCmd_SendIlmMsg(src, MOD_NVRAM, MMI_MMI_SAP, MSG_ID_NVRAM_WRITE_IMEI_REQ, pmsg);
    
//    ilm_ptr = allocate_ilm(src);
//    ilm_ptr->src_mod_id = src;
//    ilm_ptr->dest_mod_id = MOD_NVRAM;
//    ilm_ptr->sap_id = MMI_MMI_SAP;
//    ilm_ptr->msg_id = (msg_type)MSG_ID_NVRAM_WRITE_IMEI_REQ;
//    ilm_ptr->local_para_ptr = (local_para_struct *)pmsg;
//    ilm_ptr->peer_buff_ptr = NULL;
//    msg_send_ext_queue(ilm_ptr);

    return MMI_TRUE;
#endif
}

/*******************************************************************************
** 函数: msgcmd_SendSmsCallback
** 功能: 发送text短信的回调函数
** 参数: pcbd  -- 回调函数的参数
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_SendSmsCallback(srv_sms_callback_struct* pcbd)
{
    mc_trace(
        "%s, L:%d, result=%d,cause=%d,usrdata=0x%x.",
        __FUNCTION__, __LINE__,
        pcbd->result,
        pcbd->cause,
        pcbd->user_data);
    
}

/*******************************************************************************
** 函数: MsgCmd_SendSms
** 功能: 发送text短信
** 参数: to_asc_number  -- 目标号码, ASCII格式字符串
**       ucs_text_ptr   -- 短信详情, UCS格式文本
**       length_in_byte -- ucs_text_ptr的长度, 以字节为单位
**       user_data_ptr  -- 用户数据, 可在回调函数中被使用
**       sim            -- 使用哪张SIM卡来发送短信
**       cb             -- 发送短信的回调函数, 如果为NULL则使用默认的回调函数
** 返回: 返回_TRUE表示发送请求处理成功; 返回_FALSE表示发送请求处理失败
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_SendSms(
    char   *to_asc_number,
    S8     *ucs_text_ptr,
    U16     length_in_byte,
    void   *user_data_ptr,
    srv_sms_sim_enum sim,
    SrvSmsCallbackFunc cb)
{
    SMS_HANDLE sms_handle;
    S8 ucs2_number[(SRV_SMS_MAX_ADDR_LEN + 1)*ENCODING_LENGTH] = {0};
    
    mc_trace(
        "%s, L:%d, read=%d,ava=%d,number=%s,length=%d,sim=0x%x.",
        __FUNCTION__, __LINE__,
        mmi_sms_is_sms_ready(),
        srv_mode_switch_is_network_service_available(),
        to_asc_number,
        length_in_byte,
        sim);
    
	if (!mmi_sms_is_sms_ready() ||
        !srv_mode_switch_is_network_service_available() ||
        NULL == to_asc_number ||
        NULL == ucs_text_ptr ||
        0    == length_in_byte)
	{
	    return MMI_FALSE;
    }

        
	mmi_asc_n_to_ucs2((char*)ucs2_number, to_asc_number, SRV_SMS_MAX_ADDR_LEN);
    
    sms_handle = srv_sms_get_send_handle();
    //srv_sms_set_not_allow_empty_sc(sms_handle);
	srv_sms_set_address(sms_handle, (char*)ucs2_number);
    srv_sms_set_content_dcs(sms_handle, SRV_SMS_DCS_UCS2);
    srv_sms_set_sim_id(sms_handle, sim);
    srv_sms_set_send_type(sms_handle, SRV_SMS_BG_SEND);
    //srv_sms_set_counter_without_change(sms_handle);
    srv_sms_set_no_sending_icon(sms_handle);
    srv_sms_set_content(sms_handle, (char*)ucs_text_ptr, length_in_byte);
    
    srv_sms_send_msg(
        sms_handle, 
		cb==NULL ? msgcmd_SendSmsCallback : cb,
		(void*)user_data_ptr);

    return MMI_TRUE;
}

/*
wap_mma_set_profile_req_struct
srv_nw_usab_is_any_network_available
srv_ucm_is_any_call
要好好研究下这个函数, 用来制作XML文件, 然后发送彩信 [srv_uc_create_mms_xml_description_file]

mms.xml文件内容如下(当前测试已经可以发送MMS, 有待后期进一步优化): 
<mms>
<header>
<to type="P">13760106412</to>
<subject>ZgA=</subject>
<rr>0</rr>
<dr>0</dr>
<prio>2</prio>
<expiry>0</expiry>
<delivery>0</delivery>
<visible>1</visible>
</header>
<body bgColor="0xffffff" fgColor="0x000000" slideNum="1" objNum="2" layout="2" imgFit="1" txtFit="2">
<slide index="1" dur="5">
<text bgColor="0xffffff" fgColor="0x000000" id="1" begin="0" end="5"/>
<img id="2" begin="0" end="5"/>
</slide>
<obj id="1" attach="0" vf="0" drm="0" size="64" offset="0" encoding="106">
<name>mms.txt</name>
<filepath>E:\mms.txt</filepath>
</obj>
<obj id="2" attach="0" vf="0" drm="0" size="27313" offset="0" encoding="0">
<name>20110101001600E37AB4.jpg</name>
<filepath>E:\Photos\20110101001600E37AB4.jpg</filepath>
</obj>
</body>
</mms>
*/
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
    S32 user_data)
{
	srv_mms_create_rsp_struct *rsp = (srv_mms_create_rsp_struct*)rsp_data;

	if (SRV_MMS_RESULT_OK == result)
	{
		srv_mms_send_req_struct    req;

		req.msg_id       = rsp->msg_id;
		req.send_setting = SRV_MMS_SETTING_SEND_ONLY;
		req.sim_id       = MMI_SIM_ID_SIM1;
		req.storage_type = MMA_MSG_STORAGE_CARD1;
		req.is_rr        = MMI_TRUE;
		srv_mms_send(&req);
	}
	
	mc_trace("%s, result=%d, msg_id=%d. rsp->result=%d.",
		__FUNCTION__, result, rsp->msg_id, rsp->result);
}

/*******************************************************************************
** 函数: MsgCmd_CreateAndSendMMS
** 功能: 创建并且发送MMS
** 入参: number   -- 指定发送到某个号码
**       filepath -- 待发送的文件(图片或者录音或者文本等)
**       sim      -- 使用哪张SIM卡来发送, 1-SIM1;2-SIM2; 默认为SIM1.
** 返回: 是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CreateAndSendMMS(char *number, const WCHAR *filepath, mma_sim_id_enum sim)
{
	MMI_BOOL result = MMI_FALSE;

    if (mms_is_ready() && srv_nw_usab_is_any_network_available())
    {
        srv_mms_create_req_struct createReq;

        memset(&createReq, 0, sizeof(srv_mms_create_req_struct));
        //createReq.msg_file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
        app_ucs2_strcpy((S8*)createReq.xml_filepath, (const S8*)filepath);
        createReq.user_data = 0xAABB;
        createReq.msg_id    = 0;
        createReq.app_id    = MMA_APP_ID_BGSR;
        createReq.mode      = MMA_MODE_EDIT;
        createReq.sim_id    = sim;
        createReq.xml_size  = applib_get_file_size(createReq.xml_filepath);
        createReq.call_back = msgcmd_CreateAndSendMMSCb;
        
        result = (MMI_BOOL)(SRV_MMS_RESULT_OK == srv_mms_create(&createReq));
    }
	
	mc_trace("%s, num=%s. result=%d.", __FUNCTION__, number, result);
    return result;
}

/*******************************************************************************
** 函数: MsgCmd_DeleteOldFile
** 功能: 根据文件列表中的记录删除文件
** 入参: fullname   -- 录音文件的绝对路径文件名, UCS格式
**       cmpSize    -- 需要删除的总大小
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
S32 MsgCmd_DeleteOldFile(const WCHAR *list_file_name, U64 cmpSize)
{
    U32       bufsz;
    WCHAR    *buffer;
    U32       line_len, tmpSz=0;
    U64       total_size = 0;
    S32       ret = 0;
    FS_HANDLE main_fd, fd;

    if (NULL == list_file_name)
        return 0;

    bufsz  = (MSGCMD_FILE_PATH_LENGTH+1)*sizeof(WCHAR);
	buffer = (WCHAR*)MsgCmd_Malloc(bufsz, 0);
	
    kal_wsprintf(buffer, "%c:\\%w", MsgCmd_GetUsableDrive(), list_file_name);
    
    main_fd = FS_Open((const WCHAR *)buffer, FS_READ_WRITE);
    if(main_fd < FS_NO_ERROR)
    {
    	MsgCmd_Mfree(buffer);
	    return 0;
  	}

	FS_Seek(main_fd, 0, FS_FILE_BEGIN);
    do{
        memset(buffer, 0, bufsz);
		line_len = 0;
        applib_file_read_line(main_fd, (U8 *)buffer, bufsz, &line_len, &ret);

        //mc_trace("%s,L:%d. ret=%d. line_len=%d. tmpSz=%d.", __FUNCTION__, __LINE__, ret,line_len,tmpSz);
		if (line_len == 0)
			break;
		
        tmpSz += line_len;
        if(ret < 0)
            break;
        else
        {     
            U32 fsz;
            
            //去掉尾巴上的回车换行符
            while(line_len)
            {
                if (buffer[line_len-1] == '\r' || 
                    buffer[line_len-1] == '\n')
                    buffer[line_len-1] = 0;
                else
                    break;
                
                line_len --;
            }        
            
            fd = FS_Open((WCHAR*)buffer, FS_READ_ONLY);// FS_OPEN_SHARED|APPLIB_ASYNC_FILE_READ
            if(fd >= FS_NO_ERROR)
            {
                if(FS_GetFileSize(fd, &fsz) >= 0)
                    total_size += (U64)fsz;
                    
                FS_Close(fd);
                FS_Delete((const WCHAR*)buffer);
                
                mc_trace("%s,L:%d, total_size=%d.", __FUNCTION__, __LINE__, total_size);
            }

            if(total_size >= cmpSize)
                ret = 1;
        }
        
    }while(ret == 0);

	FS_Close(main_fd);
	MsgCmd_Mfree(buffer);
    MsgCmd_DeleteFileFront(list_file_name, tmpSz);
    
    return ret;
}

/*******************************************************************************
** 函数: MsgCmd_RecordFileName
** 功能: 将某个文件的UCS格式名字pdata写入到fname文件中去
** 入参: fname   -- 文件名, UCS格式
**       pdata   -- 待写入的数据
**       datalen -- 待写入的数据长度, 字节为单位
** 返回: 是否写入成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_RecordFileName(const WCHAR *fname, void *pdata, U32 datalen)
{
    U32       bufsz;
    MMI_BOOL  result;
    WCHAR    *buffer;
    FS_HANDLE fd;

    if (NULL == fname || NULL == pdata || 0 == datalen)
        return MMI_FALSE;

    bufsz  = (MSGCMD_FILE_PATH_LENGTH+1)*sizeof(WCHAR);
    buffer = (WCHAR*)MsgCmd_Malloc(bufsz, 0);

    kal_wsprintf(buffer, "%c:\\%w", MsgCmd_GetUsableDrive(), fname);
    result = MMI_FALSE;
    
    fd = FS_Open(buffer, FS_READ_WRITE|FS_CREATE);    
    if(fd >= FS_NO_ERROR)
    {
        FS_Seek(fd, 0, FS_FILE_END);
        FS_Write(fd, (void*)pdata, datalen, NULL);
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
** 函数: MsgCmd_EvtProcEntry
** 功能: 响应系统事件
** 参数: evp -- 事件通知数据地址
** 返回: 事件处理结果
** 作者: wasfayu
*******/
mmi_ret MsgCmd_EvtProcEntry(mmi_event_struct *evp)
{
    mmi_ret ret = MMI_RET_OK;

    MMI_ASSERT(evp);

    switch (evp->evt_id)
    {
    case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
        MsgCmd_ProcessInit();
        break;
    case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
        break;
    case EVT_ID_SRV_BOOTUP_COMPLETED:
        break;
    case EVT_ID_SRV_BOOTUP_EARLY_INIT:
        hf_main_init();
        break;
    case EVT_ID_IDLE_ENTER:
    case EVT_ID_IDLE_LAUNCHED:
    case EVT_ID_IDLE_EXIT:
        //mc_trace("%s, L:%d, id=%d.", __FUNCTION__, __LINE__, evp->evt_id);
        break;
    case EVT_ID_SRV_SHUTDOWN_DEINIT:
    case EVT_ID_SRV_SHUTDOWN_NORMAL_START:
    case EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT:
        //mc_trace("%s, L:%d, id=%d.", __FUNCTION__, __LINE__, evp->evt_id);
        break;
    case EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED://SIM usable
    case EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED://copy IMSI
        //mc_trace("%s, L:%d, id=%d.", __FUNCTION__, __LINE__, evp->evt_id);
        break;
    case EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED:
    case EVT_ID_SRV_NW_INFO_STATUS_CHANGED:
        //mc_trace("%s, L:%d, id=%d.", __FUNCTION__, __LINE__, evp->evt_id);
        break;
    case EVT_ID_SRV_NW_INFO_SIM_DN_STATUS_CHANGED:
        //reference: srv_nw_info_update_sim_dn_status
        //PDP active or deactive
        //GPRS attached or detached
        break;
    case EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED:
        break;
    case EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT:
        break;
    case EVT_ID_SRV_CHARBAT_NOTIFY: //charge, batttery
        break;
    case EVT_ID_SRV_SMS_MEM_EXCEED:
    case EVT_ID_SRV_SMS_MEM_FULL:
        break;
    case EVT_ID_SRV_SMS_READY:
    case EVT_ID_SRV_MMS_READY:
    case EVT_ID_SRV_SMS_MEM_AVAILABLE:
        //mc_trace("%s, L:%d, id=%d.", __FUNCTION__, __LINE__, evp->evt_id);
        break;
    case EVT_ID_PHB_READY:
        break;
    case EVT_ID_SRV_REMINDER_NOTIFY:
        break;
#if defined(MMS_SUPPORT)
    case EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED:
        break;
#endif
    default:
        break;
    }

    return ret;
}

#if 1//audio record
static AdoRecdMngr *arm;

/*******************************************************************************
** 函数: msgcmd_AdoRecdDoingCb
** 功能: 保存录音
** 参数: result  -- 结果, 如果是自动结束的话, result为0, 其他都是非0值
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_AdoRecdDoingCb(MDI_RESULT result)
{
    mc_trace("%s, result=%d.", __FUNCTION__, result);
	
	MsgCmd_RecordFileName(
		MSGCMD_AUDIO_LIST_FILE_NAME,
		(void*)arm->filepath, 
		app_ucs2_strlen((const S8 *)arm->filepath) * sizeof(WCHAR));
	
    if (MDI_AUDIO_SUCCESS == result)
    {
        if (arm->forever)
        {
            MsgcmdAdoProcReq *req = (MsgcmdAdoProcReq*)\
                MsgCmd_ConstructPara(sizeof(MsgcmdAdoProcReq));
            
            req->forever = MMI_TRUE;
            req->record  = MMI_TRUE;
            req->saveGap = MSGCMD_ADO_AUTO_SAVE_GAP;
            strcpy(req->number, arm->number);
            MsgCmd_SendIlm2Mmi(MSG_ID_MC_ADORECD_REQ, (void *)req);
        }
        else
        {
            arm->time -= arm->saveGap;
            
            //如果有追加, 则增加一段时间, 时长为默认的保存间隔时长
            if (arm->append)
            {
				mc_trace("%s, time=%dS, add time(%dS).", __FUNCTION__, arm->time, MSGCMD_ADO_AUTO_SAVE_GAP);
                arm->append = MMI_FALSE;
                arm->time  += MSGCMD_ADO_AUTO_SAVE_GAP;
            }

            if (arm->time)
            {
                MsgcmdAdoProcReq *req = (MsgcmdAdoProcReq*)\
                    MsgCmd_ConstructPara(sizeof(MsgcmdAdoProcReq));
                
                req->forever = MMI_FALSE;
                req->record  = MMI_TRUE;
                req->saveGap = arm->saveGap;
                req->recdTime= arm->time;
                strcpy(req->number, arm->number);
                MsgCmd_SendIlm2Mmi(MSG_ID_MC_ADORECD_REQ, (void *)req);
            }
            else
            {
                //notify user by SMS
                mc_trace("%s, record finish.", __FUNCTION__);
            }
        }
        
    }

    if (arm)
    {
    	mc_trace("%s, free resource, stop record.", __FUNCTION__);
        MsgCmd_isink(MMI_FALSE);
        MsgCmd_Mfree(arm);
        arm = NULL;
    }
}

/*******************************************************************************
** 函数: msgcmd_AdoRecdDoing
** 功能: 执行现时录音
** 参数: filename  -- 录音保存文件名
**       time      -- 限时时间, 秒单位
** 返回: 返回设置是否成功
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_AdoRecdDoing(WCHAR *filename, U32 time)
{
    MDI_RESULT error;

    error = mdi_audio_start_record_with_limit(
                (void*)filename,
                MEDIA_WAV_DVI_ADPCM,
                0,
                NULL,
                msgcmd_AdoRecdDoingCb,
                0,
                time);
    mc_trace("%s, error=%d. time=%dS.", __FUNCTION__, error, time);
    
    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == error);
}

/*******************************************************************************
** 函数: msgcmd_AdoRecdResponse
** 功能: 录音启动/停止请求响应函数
** 参数: p -- MsgcmdAdoProcReq
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_AdoRecdResponse(void *p)
{
    MsgcmdAdoProcReq *rsp = (MsgcmdAdoProcReq*)p;

    if (rsp->record)
    {
        MsgCmd_AdoRecdStart(
            rsp->forever, 
            rsp->recdTime, 
            MSGCMD_ADO_AUTO_SAVE_GAP,
            strlen(rsp->number) ? rsp->number : NULL);
    }
    else
    {
        MsgCmd_AdoRecdStop(strlen(rsp->number) ? rsp->number : NULL);
    }
}

/*******************************************************************************
** 函数: MsgCmd_AdoRecdSetAppend
** 功能: 增加一段录音时间
** 参数: 无
** 返回: 返回设置是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdSetAppend(void)
{
    if (arm)
    {
    	mc_trace("%s, set append flag TRUE.", __FUNCTION__);
        arm->append = MMI_TRUE;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*******************************************************************************
** 函数: MsgCmd_AdoRecdBusy
** 功能: 判断是否正在录音
** 参数: 无
** 返回: 返回_TRUE表示正在录音; 返回_FALSE表示没有任何录音
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdBusy(void)
{
    return (MMI_BOOL)(arm && ADO_STATUS_IDLE != arm->status);
}

/*******************************************************************************
** 函数: MsgCmd_AdoRecdStop
** 功能: 停止录像录音
** 参数: replay_number -- 表示回复启动结果到指定号码, 如果为空则表示不回复
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_AdoRecdStop(char *replay_number)
{
    mc_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");
    
    if (arm)
    {
        //这里调用stop函数, 里面会立即调用DoingCb函数
        mdi_audio_stop_record();
    }    
}

/*******************************************************************************
** 函数: MsgCmd_AdoRecdStart
** 功能: 启动录音
** 参数: forever       -- 是否无限时长录音
**       time_in_sec   -- 录音时长, 以秒为单位, 如果forever为真, 则忽略改参数
**       auto_save_gap -- 自动保存的时间间隔, 以秒为单位
**       replay_number -- 表示回复启动结果到指定号码, 如果为空则表示不回复
** 返回: 启动是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdStart(
    MMI_BOOL forever, 
    U32      time_in_sec, 
    U32      auto_save_gap,
    char    *replay_number)
{
    mc_trace(
        "%s, forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

    if (arm)
        return MMI_FALSE;

    MsgCmd_isink(MMI_TRUE);
    arm = (AdoRecdMngr*)MsgCmd_Malloc(sizeof(AdoRecdMngr), 0);
    arm->saveGap = auto_save_gap ? auto_save_gap : MSGCMD_ADO_AUTO_SAVE_GAP;
    arm->time    = time_in_sec;
    arm->forever = forever;
    if (!arm->forever && arm->time < arm->saveGap)
        arm->saveGap = arm->time;
    
    if (replay_number)
        strcpy(arm->number, replay_number);
    else
        arm->number[0] = '\0';

    
    MsgCmd_CombineFilePath(
        (char *)arm->filepath, 
        MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR),
        MSGCMD_AUDIOS_FOLDER_NAME,
        L".wav");
    
    if (!msgcmd_AdoRecdDoing(arm->filepath, arm->saveGap))
    {
        MsgCmd_Mfree(arm);
        arm = NULL;
        MsgCmd_isink(MMI_FALSE);
        return MMI_FALSE;
    }
    else
    {
        arm->status = ADO_STATUS_RECODING;
    }

    return MMI_TRUE;
}
#endif

#if 1 //capture process
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

	error = mdi_camera_preview_stop();
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	
	error = mdi_camera_power_off();
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);

	/* resume alignment timer */
	UI_enable_alignment_timers();

	/* resume LED patten */
	StartLEDPatternBackGround();

	/* let MMI can sleep */
	TurnOffBacklight();

	/* re-enable keypad tone */
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

	/* store camera setting back to NVRAM */
	mmi_camera_store_setting();

	/* resume background audio */
	mdi_audio_resume_background_play();
	
#if defined(MSGCMD_USE_FLASH_LED_4_CAPTURE)	
	mmi_camera_turn_off_led_highlight();
#endif

    /* close LED */
    MsgCmd_isink(MMI_FALSE);

	return MMI_TRUE;
}

/*******************************************************************************
** 函数: msgcmd_CaptureDoing
** 功能: 执行拍照并保存照片
** 参数: filename -- 照片名字
** 返回: 是否拍照并保存成功
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_CaptureDoing(S8 *filename)
{
	MDI_RESULT error;
	
	error = mdi_camera_capture_to_file(filename, MMI_FALSE);
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
	{		
		FS_Delete((U16*)filename);
		return MMI_FALSE;
	}
	
	error = mdi_camera_save_captured_image();
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
	{
		FS_Delete((U16*)filename);
		return MMI_FALSE;
	}
	
	return MMI_TRUE;
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

	error = mdi_camera_power_on();
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
		return MMI_FALSE;

#if defined(MSGCMD_USE_FLASH_LED_4_CAPTURE) 	
	mmi_camera_turn_on_preview_led_highlight();
#endif	  

    /* open LED */
    MsgCmd_isink(MMI_TRUE);

	/* stop bg music */
	mdi_audio_suspend_background_play();

	/* stop MMI sleep */
	TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
	
	/* force all playing keypad tone off */
	srv_profiles_stop_tone((srv_prof_tone_enum)GetCurKeypadTone());
	
	/* disable key pad tone */
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
	
	/* disalbe align timer	*/
	UI_disable_alignment_timers();
	
	/* stop LED patten */
	StopLEDPatternBackGround();


	mdi_camera_load_default_setting(&camera_setting_data);
	camera_setting_data.preview_width  = pictureW;
	camera_setting_data.preview_height = pictureH;
	camera_setting_data.image_width    = pictureW;
	camera_setting_data.image_height   = pictureH;
	camera_setting_data.lcm            = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
	camera_setting_data.preview_rotate = 0;
	camera_setting_data.lcm_rotate     = MDI_CAMERA_LCM_ROTATE_0;
	camera_setting_data.xenon_flash_status_callback = NULL;
	camera_setting_data.image_qty      = MDI_CAMERA_JPG_QTY_FINE;
	camera_setting_data.ev             = MDI_CAMERA_EV_0;
	camera_setting_data.banding        = MDI_CAMERA_BANDING_50HZ;
	camera_setting_data.wb             = MDI_CAMERA_WB_AUTO;
	camera_setting_data.manual_wb      = MMI_FALSE;
	camera_setting_data.flash          = MDI_CAMERA_FLASH_AUTO;
	camera_setting_data.night          = 0;
	camera_setting_data.iso            = MDI_CAMERA_ISO_AUTO;
	camera_setting_data.ae_meter       = MDI_CAMERA_AE_METER_AUTO;
	camera_setting_data.dsc_mode       = MDI_CAMERA_DSC_MODE_AUTO;	
	camera_setting_data.zoom          = 10; /* 1x */
	camera_setting_data.af_mode       = MDI_CAMERA_AUTOFOCUS_MODE_AUTO;
	camera_setting_data.af_metering_mode = MDI_CAMERA_AUTOFOCUS_1_ZONE;
	camera_setting_data.brightness    = 128;
	camera_setting_data.saturation    = 128;
	camera_setting_data.contrast      = 128;
	camera_setting_data.shutter_pri   = 0;
	camera_setting_data.aperture_pri  = 0;

    //gdi_layer_get_base_handle(&camera_preview_data.preview_layer_handle);
	camera_preview_data.preview_layer_handle = GDI_NULL_HANDLE;
	camera_preview_data.preview_wnd_offset_x = 0;
	camera_preview_data.preview_wnd_offset_y = 0;
	camera_preview_data.preview_wnd_width    = pictureW;
	camera_preview_data.preview_wnd_height   = pictureH;
	camera_preview_data.blt_layer_flag       = GDI_LAYER_ENABLE_LAYER_0;
	camera_preview_data.preview_layer_flag   = GDI_LAYER_ENABLE_LAYER_0;
	camera_preview_data.is_lcd_update        = MMI_FALSE;
	camera_preview_data.src_key_color        = GDI_COLOR_TRANSPARENT;
	camera_preview_data.is_tvout             = MMI_FALSE;

	error = mdi_camera_preview_start(&camera_preview_data, &camera_setting_data);
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
	{
		error = mdi_camera_preview_stop();
		mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		
		error = mdi_camera_power_off();
		mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		
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
	const U16 pictureW = 640;
	const U16 pictureH = 480;
	MMI_BOOL  result = MMI_FALSE;
	
    mc_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");

	if (msgcmd_CapturePreview(pictureW, pictureH))
	{
		WCHAR *filename = MsgCmd_Malloc(sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1), 0);

		MsgCmd_CombineFilePath(
            (char *)filename, 
            MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR), 
            MSGCMD_PHOTOS_FOLDER_NAME, 
            L".jpg");
		
		MsgCmd_DelayTick(MSGCMD_CAPTURE_DLY_TICK);
		result = msgcmd_CaptureDoing((S8 *)filename);
		if (result)
		{
			//send MMS
			if (replay_number)
			{
				MsgCmd_CreateAndSendMMS(replay_number, L"E:\\mms.xml", MMA_SIM_ID_SIM1);
			}
		}

		MsgCmd_Mfree(filename);
	}

	MsgCmd_DelayTick(MSGCMD_CAPTURE_DLY_TICK);
	msgcmd_CaptureFinish();
	
    return result;
}
#endif

#if 1 //video record
static VdoRecdMngr *vrm;

/*******************************************************************************
** 函数: msgcmd_VdoRecdSaveCb
** 功能: 录像保存的回调函数
** 参数: result  -- 保存结果
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_VdoRecdSaveCb(MDI_RESULT result)
{
    mc_trace("%s,L:%d. result=%d.", __FUNCTION__, __LINE__, result);
	
	/* resume alignment timer */
	UI_enable_alignment_timers();

	/* resume LED patten */
	StartLEDPatternBackGround();

	/* let MMI can sleep */
	TurnOffBacklight();

	/* re-enable keypad tone */
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

	/* store camera setting back to NVRAM */
	mmi_camera_store_setting();

	/* resume background audio */
	mdi_audio_resume_background_play();
	
#if defined(MSGCMD_USE_FLASH_LED_4_CAPTURE)	
	mmi_camera_turn_off_led_highlight();
#endif

	/* close LED */
	MsgCmd_isink(MMI_FALSE);
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
    mc_trace("%s,L:%d. result=%d.", __FUNCTION__, __LINE__, result);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdDoing
** 功能: 开始录像
** 参数: vrm  -- 录像管理变量
** 返回: 执行录像时返回的错误码
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdDoing(VdoRecdMngr *vrm)
{
    MDI_RESULT error;
    MMI_BOOL   recdOk;
    
    ASSERT(NULL != vrm);
    
    if (vrm->status != VDO_STATUS_PREVIEW && vrm->status != VDO_STATUS_PAUSE)
    {
        mc_trace("%s,L:%d. status=%d. return.", __FUNCTION__, __LINE__, vrm->status);
        return MMI_FALSE;
    }

    recdOk = MMI_FALSE;
    error = mdi_video_rec_record_start((S8*)vrm->filepath, msgcmd_VdoRecdDoingCb);
    mc_trace("%s,L:%d. error=%d.", __FUNCTION__, __LINE__, error);

    if (MDI_RES_VDOREC_SUCCEED == error)
    {
        recdOk = MMI_TRUE;
    }
    
    return recdOk;
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdPreview
** 功能: 进入录像预览
** 参数: 无
** 返回: 执行预览成功否
** 参考: mmi_fm_camera_test_entry_preview_screen [FactoryModeSrc.c]
**       mmi_fm_camera_test_start_avr_preview [FactoryModeSrc.c]
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdPreview(void)
{
    MDI_RESULT error;
    MMI_BOOL   previewOk;

    ASSERT(NULL != vrm);

	/* stop bg music */
	mdi_audio_suspend_background_play();

	/* stop MMI sleep */
	TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
	
	/* force all playing keypad tone off */
	srv_profiles_stop_tone((srv_prof_tone_enum)GetCurKeypadTone());
	
	/* disable key pad tone */
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
	
	/* disalbe align timer	*/
	UI_disable_alignment_timers();
	
	/* stop LED patten */
	StopLEDPatternBackGround();

    previewOk = MMI_FALSE;
    error = mdi_video_rec_power_on();
    mc_trace("%s,L:%d, error=%d.", __FUNCTION__, __LINE__, error);

    if (MDI_RES_VDOREC_SUCCEED == error)
    {
        mdi_video_setting_struct video_preview_data;		

        mdi_video_rec_load_default_setting(&video_preview_data);
        video_preview_data.wb					= MDI_VIDEO_WB_AUTO;
        video_preview_data.ev					= MDI_VIDEO_EV_0;
        video_preview_data.banding				= MDI_VIDEO_BANDING_50HZ;
        video_preview_data.video_qty			= VID_REC_QTY_HIGH;
        video_preview_data.video_format 		= 1;
        video_preview_data.effect				= MDI_VIDEO_EFFECT_NOMRAL;
        video_preview_data.video_size			= MDI_VIDEO_VIDEO_SIZE_QVGA;
        video_preview_data.user_def_width		= 0;
        video_preview_data.user_def_height		= 0;
        video_preview_data.zoom 				= 10;
        video_preview_data.night				= 0;
        video_preview_data.brightness			= 128;
        video_preview_data.contrast 			= 128;
        video_preview_data.saturation			= 128;
        video_preview_data.hue					= 0;
        video_preview_data.preview_rotate		= MDI_VIDEO_PREVIEW_ROTATE_0;		
        video_preview_data.overlay_frame_mode	= FALSE;
        video_preview_data.overlay_frame_depth	= 0;
        video_preview_data.overlay_frame_width	= 0;
        video_preview_data.overlay_frame_height = 0;
        video_preview_data.overlay_frame_source_key 	= 0;
        video_preview_data.overlay_frame_buffer_address = 0;
    #if defined(__MMI_MAINLCD_320X240__)||defined(__MMI_MAINLCD_160X128__)||defined(__MMI_MAINLCD_220X176__)&&!defined(__MMI_QTV_OSD_HOLD_5S__)
        video_preview_data.lcm_rotate			= 0;
    #else
        video_preview_data.lcm_rotate			= MDI_VIDEO_LCD_ROTATE_270;
    #endif
        video_preview_data.size_limit			= 0;
        video_preview_data.record_aud			= TRUE;

        error = mdi_video_rec_preview_start(
                    GDI_LAYER_EMPTY_HANDLE,
                    GDI_LAYER_ENABLE_LAYER_0,
                    GDI_LAYER_ENABLE_LAYER_0,
                    MMI_FALSE,
                    &video_preview_data);
        mc_trace("%s,L:%d, error=%d.", __FUNCTION__, __LINE__, error);

        if (MDI_RES_VDOREC_SUCCEED != error)
        {
            mdi_video_rec_preview_stop();
            mdi_video_rec_power_off();
        }
        else
        {
            previewOk = MMI_TRUE;
        }
    }
    else
    {
        error = mdi_video_rec_power_off();
    }
    
    return previewOk;
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
            MSGCMD_VDO_AUTO_SAVE_GAP,
            strlen(rsp->number) ? rsp->number : NULL);
    }
    else
    {
        MsgCmd_VdoRecdStop(strlen(rsp->number) ? rsp->number : NULL);
    }
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
    	mc_trace("%s, set append flag TRUE.", __FUNCTION__);
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
    return (MMI_BOOL)(vrm && VDO_STATUS_IDLE != vrm->status);
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
    mc_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");

    if (vrm)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_save_file((S8*)vrm->filepath, msgcmd_VdoRecdSaveCb);
        mdi_video_rec_preview_stop();
        mdi_video_rec_power_off();
    }

    MsgCmd_DelayTick(MSGCMD_VDORECD_DLY_TICK);
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
    mc_trace(
        "%s, forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

    if (vrm)
        return MMI_FALSE;
    
    vrm = (VdoRecdMngr*)MsgCmd_Malloc(sizeof(VdoRecdMngr), 0);
    vrm->forever = forever;
    vrm->time    = time_in_sec;
    vrm->saveGap = auto_save_gap ? auto_save_gap : MSGCMD_VDO_AUTO_SAVE_GAP;
    if (!vrm->forever && vrm->time < vrm->saveGap)
        vrm->saveGap = vrm->time;
    
    if (replay_number)
        strcpy(vrm->number, replay_number);
    else
        vrm->number[0] = '\0';

    
    MsgCmd_CombineFilePath(
        (char *)vrm->filepath, 
        MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR),
        MSGCMD_VIDEOS_FOLDER_NAME,
        L".avi");
    
    if (msgcmd_VdoRecdPreview())
    {
        vrm->status = VDO_STATUS_PREVIEW;
        
        MsgCmd_DelayTick(MSGCMD_VDORECD_DLY_TICK);
        
        if (!msgcmd_VdoRecdDoing(vrm))
        {
            mdi_video_rec_preview_stop();
            mdi_video_rec_power_off();
            MsgCmd_Mfree(vrm);
            vrm = NULL;

            MsgCmd_DelayTick(MSGCMD_VDORECD_DLY_TICK);
        }
    }
    else
    {
        MsgCmd_Mfree(vrm);
        vrm = NULL;
    }
    
    return (MMI_BOOL)(vrm != NULL);
}
#endif

/*******************************************************************************
** 函数: MsgCmd_ProcessInit
** 功能: 开机初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_ProcessInit(void)
{
    do {
        S32 h, i;
        WCHAR  buffer[MSGCMD_FILE_PATH_LENGTH+1];
        WCHAR *folder[] = {
            MSGCMD_AUDIOS_FOLDER_NAME,
            MSGCMD_PHOTOS_FOLDER_NAME,
            MSGCMD_VIDEOS_FOLDER_NAME,
        };
        
    	//用户盘路径
    	for (i=0; i<sizeof(folder)/sizeof(folder[0]); i++)
        {   
        	memset(buffer, 0, sizeof(WCHAR));
            kal_wsprintf(buffer, "%c:\\%w\\", MsgCmd_GetUsableDrive(), folder[i]);
        	if ((h = FS_Open((const WCHAR*)buffer, FS_OPEN_DIR|FS_READ_ONLY)) >= FS_NO_ERROR)
                FS_Close(h);
        	else
                FS_CreateDir((const WCHAR*)buffer);
        }
    
    }while(0);


    //注册消息响应
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MC_CAPTURE_REQ,
        (PsIntFuncPtr)msgcmd_CaptureResponse,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MC_ADORECD_REQ,
        (PsIntFuncPtr)msgcmd_AdoRecdResponse,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MC_VDORECD_REQ,
        (PsIntFuncPtr)msgcmd_VdoRecdResponse,
        MMI_FALSE);
}

#endif/*__MSGCMD_SUPPORT__*/

