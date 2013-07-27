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
#include "mma_sap.h"
#include "ucsrv.h"
#include "nwusabsrvgprot.h"
#include "Eint.h"
#if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
#include "drv_hisr.h"
#include "accdet_hw.h"
#include "accdet_sw.h"
#endif



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

/*******************************************************************************
** 函数: MsgCmd_isink
** 功能: 控制LCD背光开关
** 入参: open -- 开关
** 返回: 无
** 作者: wasfayu
*******/
extern void MsgCmd_isink(kal_bool open);

#if defined(WIN32)
extern void MsgCmd_ModisCreateJPEG(WCHAR *filepath);
extern void MsgCmd_ModisCreateAVI(WCHAR *filepath);
#endif

#if 0
/*******************************************************************************
** 函数: lfy_write_log
** 功能: 日志打印函数, 写入到磁盘的文件上
** 参数: fmt -- 打印格式控制字符串
** 返回: 实际写入的数据长度字节
** 作者: wasfayu
*******/
U32 lfy_write_log(const char *fmt, ...)
{
#define LFY_LOG_BUFFER_SZ        512 //BYTE
#define LFY_LOG_FILE_LIMITED     20  //KB

    static U32 logCount = 0;
    static FS_HANDLE logFH = -1;
    static WCHAR logFile[] = {L"C:\\lfy_log.txt"};
    
    U32 length, written = 0;
    char buffer[LFY_LOG_BUFFER_SZ] = {0};
    va_list list;
    
    if (-1 == logFH)
    {
        logFile[0] = SRV_FMGR_CARD_DRV;
        if(!srv_fmgr_drv_is_accessible(SRV_FMGR_CARD_DRV))
            logFile[0] = SRV_FMGR_PUBLIC_DRV;

        logFH = FS_Open(logFile, FS_READ_WRITE|FS_CREATE);
        if (logFH <= FS_NO_ERROR)
            return 0;
    }

    va_start(list, fmt);
#if defined(WIN32)
    length = _vsnprintf(buffer, LFY_LOG_BUFFER_SZ, fmt, list);
#else
    length = vsnprintf(buffer, LFY_LOG_BUFFER_SZ, fmt, list);
#endif
    va_end(list);

    if (length)
    {
        U32 temp;
        applib_time_struct t;
        char tstr[32] = {0};

        if (FS_GetFileSize(logFH, &temp) >= FS_NO_ERROR)
        {
            if (temp >= LFY_LOG_FILE_LIMITED*1024)
            {
                WCHAR backup[] = {L"C:\\lfy_back.log"};
                
                FS_Close(logFH);
                logFile[0] = (WCHAR)SRV_FMGR_PUBLIC_DRV;
                
                backup[0] = logFile[0];
                FS_Delete(backup);
                FS_Rename(logFile, backup);
                
                logFH = FS_Open(logFile, FS_READ_WRITE|FS_CREATE);
                if (logFH <= FS_NO_ERROR)
                    return 0;
            }
        }
        else
        {
            FS_Close(logFH);
            logFH = -1;
            return 0;
        }

        applib_dt_get_date_time(&t);
        temp = sprintf(tstr, "\t[%02d:%02d:%02d,0x%X]\n", t.nHour, t.nMin, t.nSec, ++logCount);
        FS_Seek(logFH, 0, FS_FILE_END);
        FS_Write(logFH, buffer, length, &written);
        FS_Write(logFH, tstr, temp, &length);
        FS_Commit(logFH);
        written = written + length;
    }

    return written;
}

#ifdef mc_trace
#undef mc_trace
#endif
#define mc_trace lfy_write_log

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
** 函数: MsgCmd_GetCallCount
** 功能: 获取电话个数
** 参数: 无
** 返回: 返回电话个数
** 作者: wasfayu
*******/
S32 MsgCmd_GetCallCount(void)
{
//#ifdef __MMI_UCM__
//    //reference: mmi_vdorec_is_in_bgcall()
//    if (0 != srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
//        return MMI_FALSE;
//#else
//    if (0 != srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
//        return MMI_FALSE;
//#endif

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
** 函数: MsgCmd_GetTFcardDrive
** 功能: 判断T卡是否存在并返回T卡的盘符
** 参数: litter -- 输出盘符
** 返回: 存在或者不存在
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_GetTFcardDrive(S32 *litter)
{
    S32 drive = SRV_FMGR_CARD_DRV;

    if (litter)
        *litter = SRV_FMGR_CARD_DRV;

    return srv_fmgr_drv_is_accessible(drive);
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
    #if defined(WIN32)
        kal_wsprintf(
            filename,
            "%04d-%02d-%02d %02d%02d%02d%w",
    		mt.nYear,
    		mt.nMonth,
    		mt.nDay,
    		mt.nHour,
    		mt.nMin,
    		mt.nSec,
    		ext_name);
    #else
        kal_wsprintf(
            filename,
            "%04d%02d%02d%02d%02d%08X%w",
    		mt.nYear,
    		mt.nMonth,
    		mt.nDay,
    		mt.nHour,
    		mt.nMin,
    		MsgCmd_GetCurrentTime(),
    		ext_name);	
    #endif
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
** 函数: MsgCmd_RebootAcitved
** 功能: 判断延时重启的定时器是否已经启动
** 入参: 无
** 返回: 定时器是否已激活
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_RebootAcitved(void)
{
	return IsMyTimerExist(MSGCMD_TIMER_REBOOT);
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
** 函数: MsgCmd_ShutdownAcitved
** 功能: 判断延时关机的定时器是否已经启动
** 入参: 无
** 返回: 定时器是否已激活
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_ShutdownAcitved(void)
{
	return IsMyTimerExist(MSGCMD_TIMER_SHUTDOWN);
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
** 函数: MsgCmd_IntRecheckTimerCb
** 功能: 外部中断重新检测的定时器操作函数的回调函数
** 入参: 无
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_IntRecheckTimerCb(void)
{
    mc_trace("%s", __FUNCTION__);
    
}

/*******************************************************************************
** 函数: MsgCmd_IntRecheckTimer
** 功能: 外部中断重新检测的定时器操作函数
** 入参: open  -- 打开或者关闭定时器
**       dlyS  -- 打开定时器时传入的定时时间, 秒为单位, 如果为0则默认为3秒钟
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_IntRecheckTimer(MMI_BOOL open, U16 dlyS)
{
    dlyS = dlyS ? dlyS : (MsgCmd_GetAdoRecdArgs()->int_check);
    
    if (open)
        StartTimer(MSGCMD_TIMER_INT_RECHECK, dlyS*1000, msgcmd_IntRecheckTimerCb);
    else
        StopTimer(MSGCMD_TIMER_INT_RECHECK);
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
** 函数: MsgCmd_CreatePath
** 功能: 创建一级深度的路径
** 参数: drive   -- 盘符
**       folder  -- 文件夹名字
** 返回: 是否创建成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CreatePath(S32 drive, const WCHAR *folder)
{
    FS_HANDLE h;
    WCHAR buffer[MSGCMD_FILE_PATH_LENGTH+1] = {0};
    
    kal_wsprintf(buffer, "%c:\\%w\\", drive, folder);
	if ((h = FS_Open((const WCHAR*)buffer, FS_OPEN_DIR|FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        FS_Close(h);
        return MMI_TRUE;
    }
	else
    {
        return (MMI_BOOL)(FS_CreateDir((const WCHAR*)buffer) >= FS_NO_ERROR);
    }
}

#if 1
extern const unsigned char AUX_EINT_NO;

#define MC_EINT_NO         AUX_EINT_NO
#define MSGCMD_INTERRUPT_DIFF_LEVEL  0 //低电平出发外部中断

/*******************************************************************************
** 函数: msgcmd_InterruptRespond
** 功能: 外部中断响应函数
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_InterruptRespond(void *p)
{
	MsgCmdExtIntReq *rsp = (MsgCmdExtIntReq*)p;

	mc_trace("%s, level=%d.", __FUNCTION__, rsp->level);
	MsgCmd_isink(rsp->level);
	//发消息到hf_mmi_task_process() 统一处理。响应的消息ID还是HF_MSG_ID_ADO或者HF_MSG_ID_VDO

	{
	  extern void hf_task_sent_hisr(BOOL level);
	
hf_task_sent_hisr(rsp->level);
	}
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
}

//
void MsgCmd_TestInterrupt(int level)
{
	MsgCmdExtIntReq *req;
	req = (MsgCmdExtIntReq*)MsgCmd_ConstructPara(sizeof(MsgCmdExtIntReq));
	req->level = level;
	MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_EXT_INTERRUPT, (void *)req);
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
    
    mc_trace("%s, mask=%d.", __FUNCTION__, mask);
}

/*******************************************************************************
** 函数: msgcmd_InterruptLISR
** 功能: 快速中断的响应函数, 里面就是激活ACCDET中断
** 参数: void
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_InterruptLISR(void)
{
#if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
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
#if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
    DRV_Register_HISR(DRV_ACCDET_HISR_ID, msgcmd_InterruptEntrance);
    IRQ_Register_LISR(IRQ_ACCDET_CODE, msgcmd_InterruptLISR, "MSGCMD handler");
    IRQSensitivity(IRQ_ACCDET_CODE, EDGE_SENSITIVE);
    IRQMask(IRQ_ACCDET_CODE);
#else
//	EINT_Registration(
//		MC_EINT_NO, 
//		MMI_TRUE, 
//		(MMI_BOOL)MSGCMD_INTERRUPT_DIFF_LEVEL, 
//		msgcmd_InterruptEntrance, 
//		MMI_TRUE);

    //最开始是屏蔽状态, 待初始化之后再打开
    EINT_Mask(MC_EINT_NO);
#endif
}

#endif

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
** 示例: 
**       WCHAR *text = L"Hello!";
**       MsgCmd_SendSms(
**           "13760106789", 
**           text, 
**           app_ucs2_strlen(text)*sizeof(WCHAR), 
**           NULL, 
**           SRV_SMS_SIM_1, 
**           NULL);
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

#if 1//MMS
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
}

/*******************************************************************************
** 函数: msgcmd_SendMMSRespond
** 功能: 发送MMS的结果通知
** 入参: p   -- wap_mma_send_rsp_struct
** 返回: 无
** 作者: wasfayu
*******/
static void msgcmd_SendMMSRespond(void *p)
{
    wap_mma_send_rsp_struct *rsp = (wap_mma_send_rsp_struct*)p;

    mc_trace("%s, result=%d, msg_id=%d.",
		__FUNCTION__, rsp->result, rsp->msg_id);
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
    S32 user_data)
{
	srv_mms_create_rsp_struct *rsp = (srv_mms_create_rsp_struct*)rsp_data;
    MsgCmdMMSUserData         *usd = (MsgCmdMMSUserData*)user_data;

	if (SRV_MMS_RESULT_OK == result)
	{
		srv_mms_send_req_struct req;
        
		req.msg_id       = rsp->msg_id;
		req.send_setting = SRV_MMS_SETTING_SEND_ONLY;
		req.sim_id       = (usd->sim==MMA_SIM_ID_SIM2) ? MMI_SIM_ID_SIM2 : MMI_SIM_ID_SIM1;
		req.storage_type = MMA_MSG_STORAGE_CARD1;
		req.is_rr        = MMI_TRUE;
		srv_mms_send(&req);
	}

    FS_Delete(usd->xmlpath);
    MsgCmd_Mfree(usd);
        
	mc_trace("%s, result=%d, msg_id=%d. rsp->result=%d.",
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
MMI_BOOL MsgCmd_CreateAndSendMMS(
    mma_sim_id_enum sim,
    WCHAR          *xml_path)
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
        createReq.user_data = (S32)userdata;
        createReq.msg_id    = 0;
        createReq.app_id    = MMA_APP_ID_BGSR;
        createReq.mode      = MMA_MODE_EDIT;
        createReq.sim_id    = sim;
        createReq.xml_size  = applib_get_file_size(createReq.xml_filepath);
        createReq.call_back = msgcmd_CreateAndSendMMSCb;
        
        result = (MMI_BOOL)(SRV_MMS_RESULT_OK == srv_mms_create(&createReq));
    }
	
	mc_trace("%s, result=%d.", __FUNCTION__, result);
    return result;
}
#endif

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
    if (dt)
    {
        U32 tick1, tick2;
        
    	kal_get_time(&tick1);
    	dt = dt ? dt : 2;
    	do {
    		kal_get_time(&tick2);
    	}while(tick2 - tick1 < dt);
    }
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
		MsgCmd_InterruptMask(MMI_FALSE);
		MsgCmd_isink(MMI_FALSE);
        break;
    case EVT_ID_SRV_BOOTUP_EARLY_INIT:
        hf_main_init();
        MsgCmd_isink(MMI_TRUE);
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
    if (NULL == arm)
        return;
    
    mc_trace("%s, result=%d.", __FUNCTION__, result);

    //如果文件小于这个值则删除掉他
    if (applib_get_file_size(arm->filepath) >= MsgCmd_GetAdoRecdArgs()->ignore_size)
    {
    	MsgCmd_RecordFileName(
    		MSGCMD_ADO_LIST_FILE_NAME,
    		(void*)arm->filepath, 
    		app_ucs2_strlen((const S8 *)arm->filepath) * sizeof(WCHAR));
    }
    else
    {
        FS_Delete(arm->filepath);
    }
	
    if (MDI_AUDIO_SUCCESS == result)
    {
        if (arm->forever)
        {
            MsgcmdAdoProcReq *req = (MsgcmdAdoProcReq*)\
                MsgCmd_ConstructPara(sizeof(MsgcmdAdoProcReq));
            
            req->forever = MMI_TRUE;
            req->record  = MMI_TRUE;
            req->saveGap = MsgCmd_GetAdoRecdArgs()->save_gap;
            strcpy(req->number, arm->number);
            MsgCmd_SendIlm2Mmi(MSG_ID_MC_ADORECD_REQ, (void *)req);
        }
        else
        {
            arm->time -= arm->saveGap;
            
            //如果有追加, 则增加一段时间, 时长为默认的保存间隔时长
            if (arm->append)
            {
				mc_trace("%s, time=%dS, add time(%dS).", __FUNCTION__, arm->time, MsgCmd_GetAdoRecdArgs()->save_gap);
                arm->append = MMI_FALSE;
                arm->time  += MsgCmd_GetAdoRecdArgs()->save_gap;
            }

            //剩余时间小于xx秒则忽略掉
            if (arm->time && arm->time >= MsgCmd_GetAdoRecdArgs()->ignore_time)
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
            MsgCmd_GetAdoRecdArgs()->save_gap,
            strlen(rsp->number) ? rsp->number : NULL);
    }
    else
    {
        MsgCmd_AdoRecdStop(strlen(rsp->number) ? rsp->number : NULL);
    }
}

/*******************************************************************************
** 函数: MsgCmd_AdoRecdGetContext
** 功能: 获取录音管理变量的地址
** 参数: 无
** 返回: 返回管理变量的地址
** 作者: wasfayu
*******/
AdoRecdMngr *MsgCmd_AdoRecdGetContext(void)
{
    return arm;
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
    S32 drive;
    
    mc_trace(
        "%s, forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

    if (arm)
        return MMI_FALSE;

    //T卡不存在就返回
    if (!MsgCmd_GetTFcardDrive(NULL))
        return MMI_FALSE;

    //有电话在忙
    if (MsgCmd_GetCallCount() > 0)
        return MMI_FALSE;

    //磁盘未获取到
    if ((drive = MsgCmd_GetUsableDrive()) < 0)
        return MMI_FALSE;

    //保证路径存在
    if (!MsgCmd_CreatePath(drive, MSGCMD_AUDIOS_FOLDER_NAME))
        return MMI_FALSE;

    //获取的盘符是否正确挂载--就是是否存在的一个意思
    if (!MsgCmd_CheckValidDrive(drive))
        return MMI_FALSE;

    //正在录像
    if (MsgCmd_VdoRecdBusy())
        return MMI_FALSE;
    
    //磁盘剩余空间小于5M则删除就的录音文件
    if (MsgCmd_GetDiskFreeSize(drive) <= MSGCMD_ADO_FREE_SPACE_REQUIRE)
    {
        MsgCmd_DeleteOldFile(MSGCMD_ADO_LIST_FILE_NAME, MSGCMD_ADO_DELETE_SIZE);
    }
    
    MsgCmd_isink(MMI_TRUE);
    arm = (AdoRecdMngr*)MsgCmd_Malloc(sizeof(AdoRecdMngr), 0);
    arm->saveGap = auto_save_gap ? auto_save_gap : MsgCmd_GetAdoRecdArgs()->save_gap;
    arm->time    = time_in_sec;
    arm->forever = forever;
    if (!arm->forever && arm->time < arm->saveGap)
        arm->saveGap = arm->time;
    
    if (replay_number)
        strcpy(arm->number, replay_number);
    else
        arm->number[0] = '\0';

    
    MsgCmd_CombineFilePath(
        arm->filepath, 
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
        MsgCmd_IntRecheckTimer(MMI_TRUE, MsgCmd_GetAdoRecdArgs()->int_check);
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

#if !defined(WIN32)
	error = mdi_camera_preview_stop();
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
#endif

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
static MMI_BOOL msgcmd_CaptureDoing(S8 *filepath)
{
#if defined(WIN32)

    MsgCmd_ModisCreateJPEG((WCHAR *)filepath);
    return MMI_TRUE;

#else

	MDI_RESULT error;

	error = mdi_camera_capture_to_file(filepath, MMI_FALSE);
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	if (MDI_RES_CAMERA_SUCCEED != error)
	{		
		FS_Delete((const WCHAR*)filepath);
		return MMI_FALSE;
	}
	
	error = mdi_camera_save_captured_image();
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
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

#if defined(WIN32)
    error = MDI_RES_CAMERA_SUCCEED;
#else
	error = mdi_camera_preview_start(&camera_preview_data, &camera_setting_data);
	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
#endif

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

    //T卡不存在就返回
    if (!MsgCmd_GetTFcardDrive(NULL))
        return MMI_FALSE;

    //获取的盘符是否正确挂载--就是是否存在的一个意思
    if (!MsgCmd_CheckValidDrive(MsgCmd_GetUsableDrive()))
        return MMI_FALSE;

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
        
		if (result && NULL != replay_number)
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
static void msgcmd_VdoRecdSaveCb(MDI_RESULT result);
static void msgcmd_VdoRecdDoingCb(MDI_RESULT result);
static void msgcmd_VdoRecdLayerMngr(MMI_BOOL create, gdi_handle *layer);
static MMI_BOOL msgcmd_VdoRecdPowerMngr(MMI_BOOL on);
static MMI_BOOL msgcmd_VdoRecdPreview(MMI_BOOL start, gdi_handle layer);
static MMI_BOOL msgcmd_VdoRecdDoing(WCHAR *filepath);
static MMI_BOOL msgcmd_VdoRecdStop(void);
static void msgcmd_VdoRecdDelete(WCHAR *filepath);
static MMI_BOOL msgcmd_VdoRecdSave(WCHAR *filepath);
static void msgcmd_VdoRecdTimerCyclic(void);
static void msgcmd_VdoRecdCyclicTimer(MMI_BOOL start);
static void msgcmd_VdoRecdResponse(void *p);
static void msgcmd_VdoRecdContRecdRsp(void *p);

static VdoRecdMngr *vrm;

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
    
    mc_trace("%s. result=%d, stop=%d.", __FUNCTION__, result, vrm->stop);
    
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
        if (applib_get_file_size(vrm->filepath) >= MsgCmd_GetVdoRecdArgs()->ignore_size)
        {
        	MsgCmd_RecordFileName(
        		MSGCMD_VDO_LIST_FILE_NAME,
        		(void*)vrm->filepath, 
        		app_ucs2_strlen((const S8 *)vrm->filepath) * sizeof(WCHAR));
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
				mc_trace("%s, time=%dS, add time(%dS).", __FUNCTION__, vrm->time, MsgCmd_GetVdoRecdArgs()->save_gap);
                vrm->time  += MsgCmd_GetVdoRecdArgs()->save_gap;
            }

            //剩余时间小于xx秒则忽略掉
            if (vrm->time < MsgCmd_GetVdoRecdArgs()->ignore_time)
            {
                vrm->stop = MMI_TRUE;
                //notify user by SMS
                mc_trace("%s, record finish.", __FUNCTION__);
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
    	mc_trace("%s, free resource, stop record.", __FUNCTION__);
        msgcmd_VdoRecdPreview(MMI_FALSE, vrm->dispLayer);
        msgcmd_VdoRecdPowerMngr(MMI_FALSE);
        msgcmd_VdoRecdLayerMngr(MMI_FALSE, &vrm->dispLayer);
        MsgCmd_Mfree(vrm);
        vrm = NULL;
    }
    else
    {
        //发消息出去重新录像
        local_para_struct *req = (local_para_struct*)\
            MsgCmd_ConstructPara(sizeof(local_para_struct));

        mc_trace("%s, pose contiue record request.", __FUNCTION__);
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
    mc_trace("%s,L:%d. result=%d.", __FUNCTION__, __LINE__, result);
    if (MDI_RES_VDOREC_SUCCEED != result)
    {
        vrm->stop = MMI_TRUE;
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
    
    if (create)
    {
        U8 *temp;
        S32 h = 320, w = 240;
        
        /* enable multi-layer */
        gdi_layer_multi_layer_enable();
        
        gdi_layer_get_buffer_ptr(&temp);
        ASSERT(temp != NULL);
        gdi_layer_create_using_outside_memory(0, 0, w, h, layer, temp, w*h*2);
        gdi_layer_push_and_set_active(*layer);
        gdi_layer_set_background(GDI_COLOR_BLACK);
        gdi_layer_set_position(0, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_set_blt_layer(*layer, 0, 0, 0);
    }
    else
    {
        //free layer resource
        gdi_layer_free(*layer);
        *layer = GDI_NULL_HANDLE;

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
        /* set main camera id */
        mdi_video_set_camera_id(0);
    
        /* camera power up */
        ret = mdi_video_rec_power_on();
        
        /* open LED */
    	MsgCmd_isink(MMI_TRUE);
        
        /* force all playing keypad tone off */
        srv_profiles_stop_tone(SRV_PROF_TONE_KEYPAD);

        /* disable key pad tone */
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

        /* enable multi_layer */
        gdi_layer_multi_layer_enable();

        /* suspend background play */
        //mdi_audio_suspend_background_play();

        /* disalbe align timer */
        UI_disable_alignment_timers();

        /* stop LED patten */
        StopLEDPatternBackGround();

        /* 
         * This is used to solve a very rare situation. When playing a IMELODY 
         * with backlight on/off, and the screen previous to this screen is a 
         * horizontal screen. Before enter this screen, the IMELODY turn off the
         * backlight. While exit previous screen, the layer rotate back to normal
         * size and the content is not correct. So when calling TurnOnBacklight, 
         * LCD is in sleepin state and draw wrong content to LCD.
         * So we need to clear the buffer first to avoid this situation.
         */
        gdi_layer_clear(GDI_COLOR_BLACK);

        /* stop MMI sleep */
        TurnOnBacklight(0);
    }
    else
    {
        /* shut down camera */
        ret = mdi_video_rec_power_off();
        
        /* disable multi layer */
        gdi_layer_multi_layer_disable();

        /* resume alignment timer */
        //UI_disable_alignment_timers();

        /* resume LED patten */
        StartLEDPatternBackGround();

        /* let MMI can sleep */
        TurnOffBacklight();

        /* resume background audio */
        mdi_audio_resume_background_play();

        /* re-enable keypad tone */
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

        /* close LED */
    	MsgCmd_isink(MMI_FALSE);
    }

    mc_trace("%s, on=%d, ret=%d.", __FUNCTION__, on, ret);
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
        video_preview_data.wb					= MDI_VIDEO_WB_AUTO;
        video_preview_data.ev					= MDI_VIDEO_EV_0;
        video_preview_data.banding				= MDI_VIDEO_BANDING_50HZ;
        video_preview_data.video_qty			= MDI_VIDEO_REC_QTY_HIGH;
    #if defined(MP4_ENCODE)
    	video_preview_data.video_format 		= MDI_VIDEO_VIDEO_FORMAT_3GP;
    #elif defined(MJPG_ENCODE)
    	video_preview_data.video_format 		= MDI_VIDEO_VIDEO_FORMAT_MP4;
    #else
    	MMI_ASSERT(0);
    #endif
        video_preview_data.effect				= MDI_VIDEO_EFFECT_NOMRAL;
        video_preview_data.video_size			= MDI_VIDEO_VIDEO_SIZE_HVGA;//480x320
        video_preview_data.user_def_width		= 0;
        video_preview_data.user_def_height		= 0;
        video_preview_data.zoom 				= 10;
        video_preview_data.night				= 0;
        video_preview_data.brightness			= 128;
        video_preview_data.contrast 			= 128;
        video_preview_data.saturation			= 128;
        video_preview_data.hue					= 0;
        video_preview_data.preview_rotate		= MDI_VIDEO_PREVIEW_ROTATE_90;		
        video_preview_data.overlay_frame_mode	= FALSE;
        video_preview_data.overlay_frame_depth	= 0;
        video_preview_data.overlay_frame_width	= 0;
        video_preview_data.overlay_frame_height = 0;
        video_preview_data.overlay_frame_source_key 	= 0;
        video_preview_data.overlay_frame_buffer_address = 0;
    #if defined(__MMI_MAINLCD_320X240__)||defined(__MMI_MAINLCD_160X128__)||defined(__MMI_MAINLCD_220X176__)&&!defined(__MMI_QTV_OSD_HOLD_5S__)
        video_preview_data.lcm_rotate			= 0;
        video_preview_data.preview_rotate       = 0;
    #else
        video_preview_data.lcm_rotate			= MDI_VIDEO_LCD_ROTATE_270;
        video_preview_data.preview_rotate       = MDI_VIDEO_LCD_ROTATE_270;
    #endif
        video_preview_data.size_limit			= 0;
        video_preview_data.time_limit           = 0;
        video_preview_data.record_aud			= TRUE;

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
    
    mc_trace("%s, start=%d, ret=%d.", __FUNCTION__, start, ret);
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

    //磁盘剩余空间小于15M则删除就的视频文件
    if (MsgCmd_GetDiskFreeSize(MsgCmd_GetUsableDrive()) <= MSGCMD_VDO_FREE_SPACE_REQUIRE)
    {
        MsgCmd_DeleteOldFile(MSGCMD_VDO_LIST_FILE_NAME, MSGCMD_ADO_DELETE_SIZE);
    }
    
    ret = mdi_video_rec_record_start((S8*)filepath, msgcmd_VdoRecdDoingCb);
    mc_trace("%s, ret=%d.", __FUNCTION__, ret);
    if (MDI_RES_VDOREC_SUCCEED == ret)
        msgcmd_VdoRecdCyclicTimer(MMI_TRUE);
    
    return (MMI_BOOL)(MDI_RES_VDOREC_SUCCEED == ret);
}

/*******************************************************************************
** 函数: msgcmd_VdoRecdStop
** 功能: 停止录像录像
** 参数: 无
** 返回: 是否停止
** 作者: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdStop(void)
{
    MDI_RESULT ret;

    ret = mdi_video_rec_record_stop();
    if (MDI_RES_VDOREC_SUCCEED == ret)
        msgcmd_VdoRecdCyclicTimer(MMI_FALSE);

    mc_trace("%s, ret=%d.", __FUNCTION__, ret);
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
    mc_trace("%s.", __FUNCTION__);
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

    msgcmd_VdoRecdStop();
#if defined(WIN32)
    if (MMI_TRUE)
#else
    if (mdi_video_rec_has_unsaved_file((S8*)filepath))
#endif
    {
        ret = mdi_video_rec_save_file((S8*)filepath, msgcmd_VdoRecdSaveCb);
        mc_trace("%s, ret=%d.", __FUNCTION__, ret);
    }
    else
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
    mc_trace("%s, timeCount=%dS. saveGap=%dS.", __FUNCTION__, vrm->timeCount, vrm->saveGap);
    if (vrm->timeCount >= vrm->saveGap)
    {
        //save
        vrm->stop = MMI_FALSE;
        mc_trace("%s, timeCount=%dS, saveGap=%dS, save.", __FUNCTION__, vrm->timeCount, vrm->saveGap);
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
        	mc_trace("%s, free resource, stop record.", __FUNCTION__);
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
    mc_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");

    if (vrm)
    {
        vrm->stop = MMI_TRUE;
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
    
    mc_trace(
        "%s, forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

    if (MsgCmd_VdoRecdBusy())
        return MMI_FALSE;

    //T卡不存在就返回
    if (!MsgCmd_GetTFcardDrive(NULL))
        return MMI_FALSE;
    
    //有电话在忙
    if (MsgCmd_GetCallCount() > 0)
        return MMI_FALSE;

    //磁盘未获取到
    if ((drive = MsgCmd_GetUsableDrive()) < 0)
        return MMI_FALSE;

    //保证路径存在
    if (!MsgCmd_CreatePath(drive, MSGCMD_VIDEOS_FOLDER_NAME))
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
            //保存之?删除之?
            mc_trace("%s, L:%d, has unsaved video, delete.", __FUNCTION__, __LINE__);
            mdi_video_rec_delete_unsaved_file((S8*)buffer);
        }
    }
    
    vrm = (VdoRecdMngr*)MsgCmd_Malloc(sizeof(VdoRecdMngr), 0);
    vrm->forever = forever;
    vrm->time    = time_in_sec;
    vrm->saveGap = auto_save_gap ? auto_save_gap : MsgCmd_GetVdoRecdArgs()->save_gap;
    if (!vrm->forever && vrm->time < vrm->saveGap)
        vrm->saveGap = vrm->time;
    
    if (replay_number)
        strcpy(vrm->number, replay_number);
    else
        vrm->number[0] = '\0';

    msgcmd_VdoRecdGetFilePath(vrm->filepath, MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR));
    msgcmd_VdoRecdLayerMngr(MMI_TRUE, &vrm->dispLayer);
    
    if (msgcmd_VdoRecdPowerMngr(MMI_TRUE) &&
        msgcmd_VdoRecdPreview(MMI_TRUE, vrm->dispLayer))
    {
        vrm->status = VDO_STATUS_PREVIEW;
        
        kal_sleep_task(20);
        if (msgcmd_VdoRecdDoing(vrm->filepath))
        {
            vrm->status = VDO_STATUS_RECODING;
        }
        else
        {
            MsgCmd_VdoRecdStop(vrm->number);
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

/*******************************************************************************
** 函数: MsgCmd_ProcessInit
** 功能: 开机初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_ProcessInit(void)
{
    S32 drive;
    
    if ((drive = MsgCmd_GetUsableDrive()) > 0)
    {
    	MsgCmd_CreatePath(drive, MSGCMD_AUDIOS_FOLDER_NAME);
        MsgCmd_CreatePath(drive, MSGCMD_PHOTOS_FOLDER_NAME);
        MsgCmd_CreatePath(drive, MSGCMD_VIDEOS_FOLDER_NAME);
    }

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

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MC_SEND_MMS_REQ,
        (PsIntFuncPtr)msgcmd_SendMMSResponse,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SEND_RSP, 
        (PsIntFuncPtr)msgcmd_SendMMSRespond,
        MMI_TRUE);

}

#endif/*__MSGCMD_SUPPORT__*/

