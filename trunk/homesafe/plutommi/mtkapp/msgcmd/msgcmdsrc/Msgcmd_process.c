/*******************************************************************************
 *
 * msgcmd_process.c
 *
 * ��Ҫ����¼��/¼��/����/�ظ�����/�ظ�����
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, ����ԭʼ�汾
 *
 ******************************************************************************/


#if defined(__MESSAGE_COMMAND_SUPPORT__)
#include "gdi_datatype.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "filemgrsrvgprot.h"
#include "shutdownsrvgprot.h"
#include "bootupsrvgprot.h"
#include "alarmsrvgprot.h"
#include "SettingProt.h"
#include "imeisrvgprot.h"
#include "DateTimeGprot.h"
#include "SmsAppGprot.h"
#include "stack_ltlcom.h"
#include "nvram_struct.h"
#include "fs_func.h"
#include "TimerEvents.h"
#include "ctype.h"
#include "string.h"
#include "app_str.h"
#include "app_ltlcom.h"
#include "app_asyncfile.h"
#include "kal_trace.h"
#include "msgcmd_process.h"


#define MSGCMD_TIMER_REBOOT      (MSGCMD_TIMER_BASE + 0)
#define MSGCMD_TIMER_SHUTDOWN    (MSGCMD_TIMER_BASE + 1)
#define MSGCMD_TIMER_FACTORY     (MSGCMD_TIMER_BASE + 2)

/*******************************************************************************
** ����: MsgCmd_GetInteger
** ����: �Ӹ������ȵ��ַ����л�ȡһ��32λ�޷�������
** ����: ps  ��������
**       sl  �ַ�������
**       type  �ַ�������
** ����: ��ȡ�ɹ����ض�Ӧ��ֵ, ʧ�ܷ���-1
** ����: wasfa
*******/
INT32U MsgCmd_GetInteger(const CHAR *ps, INT16U sl, StringType_e type)
{
#define INVALID_INT32U_VAL  (0xFFFFFFFF)

    INT32U val = 0;

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
** ����: MsgCmd_Atoi
** ����: ϵͳ����atoi�İ�װ
** ����: 
** ����: 
** ����: wasfa
*******/
INT32S MsgCmd_Atoi(const CHAR *nptr)
{
    if (0 == app_strnicmp((CHAR*)nptr, "0x", 2))
    {
        nptr += 2;
        return (INT32S)MsgCmd_GetInteger((const CHAR *)nptr, strlen(nptr), STR_TYPE_16);
    }
    
    return atoi(nptr);
}

/*******************************************************************************
** ����: MsgCmd_IsDigStr
** ����: �ж��Ƿ��������ַ���, 0~9���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsDigStr(const CHAR *ps, INT32U sl)
{
    while(sl--)
        if(!isdigit(*ps++))
            return _FALSE;

    return _TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsXdigStr
** ����: �ж��Ƿ���16�����ַ���, 0~9, A~F, a~f���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsXdigStr(const CHAR *ps, INT32U sl)
{
    while(sl--)
        if(!isxdigit(*ps++))
            return _FALSE;

    return _TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsXdigFmtStr
** ����: �Ƿ���16���Ƹ�ʽ��ͷ���ַ���, ����0x��ͷ�������ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsXdigFmtStr(const CHAR *ps, INT32U sl)
{
    if(sl >= 3 && \
        0 == app_strnicmp((CHAR*)ps, "0x", 2) &&
        MsgCmd_IsXdigStr((const CHAR*)(ps+2), sl-2))
    {
        return _TRUE;
    }

    return _FALSE;
}

/*******************************************************************************
** ����: MsgCmd_IsAlpNumstr
** ����: �Ƿ�����ĸ�����ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsAlpNumStr(const CHAR *ps, INT32U sl)
{
    while(sl--)
        if(!isalnum(*ps++))
            return _FALSE;

    return _TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsAlphaStr
** ����: �Ƿ�����ĸ�ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsAlphaStr(const CHAR *ps, INT32U sl)
{
    while(sl--)
        if(!isalpha(*ps++))
            return _FALSE;

    return _TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsSpaceStr
** ����: �Ƿ��ǿհ��ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsSpaceStr(const CHAR *ps, INT32U sl)
{
    while(sl--)
        if(!isspace(*ps++))
            return _FALSE;

    return _TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsLowerStr
** ����: �Ƿ���Сд�ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsLowerStr(const CHAR *ps, INT32U sl)
{
    while(sl--)
        if(!islower(*ps++))
            return _FALSE;

    return _TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsUpperStr
** ����: �Ƿ��Ǵ�д�ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
_BOOL MsgCmd_IsUpperStr(const CHAR *ps, INT32U sl)
{
    while(sl--)
        if(!isupper(*ps++))
            return _FALSE;

    return _TRUE;
}

/* ������ linux V3.2 source code ���� strpbrk
 *
 * strpbrk - Find the first occurrence of a set of characters
 * @cs: The string to be searched
 * @ct: The characters to search for
 */
static CHAR *msgcmd_strpbrk(const CHAR *cs, const CHAR *ct)
{
	const CHAR *sc1, *sc2;

	for (sc1 = cs; *sc1 != '\0'; ++sc1) {
		for (sc2 = ct; *sc2 != '\0'; ++sc2) {
			if (*sc1 == *sc2)
				return (char *)sc1;
		}
	}
	return NULL;
}

/* ������ linux V3.2 source code ���� strsep
 * �������ڵ�strtok����, ����strsep���߰�ȫ��.
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
CHAR *MsgCmd_strsep(CHAR **s, const CHAR *ct)
{
	CHAR *sbegin = *s;
	CHAR *end;

	if (sbegin == NULL)
		return NULL;

	end = msgcmd_strpbrk(sbegin, ct);
	if (end)
		*end++ = '\0';
	*s = end;
	return sbegin;
}

/*******************************************************************************
** ����: MsgCmd_GetDiskFreeSize
** ����: ��ȡ����ʣ��ռ�
** ����: drive, �����̷�, 0x43~0x47
** ����: ʣ��ռ�Ĵ�С, byteΪ��λ
** ����: wasfayu
*******/
INT32U MsgCmd_GetDiskFreeSize(INT32S drive)
{
    FS_DiskInfo disk_info;
    WCHAR path[8] = {0};
    INT32U size;

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
** ����: MsgCmd_GetUsableDrive
** ����: ��ȡϵͳ���õĴ洢�豸�̷�
** ����: 
** ����: �����̷� 0x43~0x47
** ����: wasfayu
*******/
INT32S MsgCmd_GetUsableDrive(void)
{
    INT32S drive = SRV_FMGR_CARD_DRV;

    if(!srv_fmgr_drv_is_accessible(drive))
    {
        drive = SRV_FMGR_PUBLIC_DRV;
    }

    return drive;
}

/*******************************************************************************
** ����: MsgCmd_GetSystemDrive
** ����: ��ȡϵͳ�̵��̷�
** ����: 
** ����: Success:                0x43~0x47 (A~G)
**       Error:                  RTF_PARAM_ERROR        (-2)
**                               RTF_DRIVE_NOT_FOUND    (-4)
** ����: wasfayu
*******/
INT32S MsgCmd_GetSystemDrive(void)
{
    return SRV_FMGR_SYSTEM_DRV;
}

/*******************************************************************************
** ����: MsgCmd_GetFileSize
** ����: ��ȡ�ļ���С
** ����: path - �ļ�����·��
** ����: �ļ���С
** ����: wasfayu
*******/
INT32U MsgCmd_GetFileSize(const WCHAR *path)
{
    return applib_get_file_size(path);
}

/*******************************************************************************
** ����: MsgCmd_CombineFilePath
** ����: ����ļ��ľ���·��, Ŀ¼���Ϊһ��
** ����: out       -- װ�����·����buffer
**       length    -- out�ĳ���, ���ֽ�Ϊ��λ, ����Ӧ�ô���32���ֽ�����
**       folder    -- �ļ��е�����, �� L"audio"
**       ext_name  -- ��չ��������, �� L".mp3"
** ����: ����out�ĵ�ַ
** ����: wasfayu
*******/
WCHAR *MsgCmd_CombineFilePath(
    CHAR *out,
    INT16U length,
    const WCHAR *folder,
    const WCHAR *ext_name)
{	
	MDI_RESULT ret;
	applib_time_struct mt;
	
	applib_dt_get_date_time(&mt);
	memset(out, 0, length);
	
	kal_wsprintf(
		(WCHAR*)out, 
		"%c:\\%w\\%04d%02d%02d%02d%02d %08X%w", 
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
** ����: MsgCmd_GetCurrentTime
** ����: ��ȡϵͳ��ǰ������ʱ��
** ����: ��
** ����: ����ʱ��
** ����: wasfayu
*******/
INT32U MsgCmd_GetCurrentTime(void)
{
    return drv_get_current_time();
}

/*******************************************************************************
** ����: MsgCmd_GetDateTime
** ����: ��ȡϵͳ��ǰ��ʱ��
** ����: ʱ��ṹ��
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_GetDateTime(applib_time_struct *t)
{    
    applib_dt_get_date_time(t);
}

/*******************************************************************************
** ����: MsgCmd_SetDateTime
** ����: ����ϵͳ��ǰ��ʱ��
** ����: ʱ��ṹ��
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_SetDateTime(applib_time_struct *t)
{
    mmi_dt_set_rtc_dt((MYTIME *)t);
}

/*******************************************************************************
** ����: MsgCmd_IsDateTimeValid
** ����: �ж�ʱ���Ƿ���Ч
** ����: t  -- 
** ����: �Ƿ���Ч
** ����: wasfayu
*******/
_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t)
{
    return applib_dt_is_valid(t);
}

/*******************************************************************************
** ����: MsgCmd_SendIlm2Mmi
** ����: ������Ϣ��MMIģ��
** ����: msgid  -- ��ϢID
**       msg    -- ��Ϣ
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_SendIlmMsg
** ����: ��srcģ�鷢����Ϣmsgid��destģ��, ����sap������ת
** ����: src    -- ����stack_get_active_module_id()����ȡ
**       dest   -- Ŀ��ģ��
**       sap    -- ��ת, ������INVALID_SAP
**       msgid  -- ��ϢID
**       msg    -- ��Ϣ
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_SendIlmMsg(
    module_type src,
    module_type dest, 
    sap_type sap, 
    msg_type msgid, 
    void *msg)
{
    ilm_struct *ilm_ptr = NULL;
    //module_type src = MOD_MMI;//stack_get_active_module_id();//ֻ����MOD_MMI
    
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
** ����: MsgCmd_MemAlloc
** ����: �����ڴ�, ���ڴ���ڴ�����, ������host_mfree_ext���ͷ�.
** ����: s ��ʾ��Ҫ������ڴ��ֽڳ���.
**       v ��ʾ�����������ڴ������ʼ��Ϊ��ֵ.
** ����: �������뵽���ڴ��ַ.
** ����: wasfayu
*******/
void *MsgCmd_MemAlloc(INT32U s, INT8U v, const CHAR* file, INT32U line)
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
** ����: MsgCmd_MemFree
** ����: �ͷ���MsgCmd_MemAlloc���������ڴ�
** ����: memptr   ��ʾ��Ҫ�ͷŵ��ڴ��ַ.
** ����: ��
** ˵��: med_free_ext_mem�Ǹ��ܱ�̬�ĺ���, ��ȻҪȡ��ַ֮�������ַ. ����...
** ����: wasfayu
*******/
void MsgCmd_MemFree(void *p, const CHAR* file, INT32U line)
{
    //med_free_ext_mem(&p);
    OslMfree(p);
}

/*******************************************************************************
** ����: MsgCmd_ConstructPara
** ����: ��������buffer
** ����: sz   ��ʾ��Ҫʹ�õ�buffer��С.
** ����: ��
** ����: wasfayu
*******/
void *MsgCmd_ConstructPara(INT32U sz)
{
    return construct_local_para(sz, TD_CTRL | TD_RESET);
}

/*******************************************************************************
** ����: MsgCmd_DestructPara
** ����: ����buffer�ͷ�
** ����: ptr   ��ʾ��Ҫ�ͷŵĲ���buffer��ַ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_DestructPara(void *ptr)
{
    free_local_para((local_para_struct*)ptr);
}

/*******************************************************************************
** ����: MsgCmd_Reboot
** ����: ����
** ���: 
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_Reboot(void)
{
    srv_alm_pwr_reset(_TRUE, 1);
}

/*******************************************************************************
** ����: MsgCmd_RebootExt
** ����: ��ʱ����
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_RebootExt(INT16U delayS)
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
** ����: MsgCmd_Shutdown
** ����: �ػ�
** ���: 
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_Shutdown(void)
{
    srv_shutdown_normal_start(SRV_BOOTUP_MODE_NORMAL);
}

/*******************************************************************************
** ����: MsgCmd_ShutdownExt
** ����: ��ʱ�ػ�
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_ShutdownExt(INT16U delayS)
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
** ����: MsgCmd_Factory
** ����: �ػ�
** ���: 
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_Factory(void)
{
    RstStartRestore();
}

/*******************************************************************************
** ����: MsgCmd_FactoryExt
** ����: ��ʱ�ػ�
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_FactoryExt(INT16U delayS)
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
** ����: MsgCmd_DeleteFileFront
** ����: ɾ���ļ���ǰ��
** ���: fname   -- �ļ���, UCS��ʽ
**       deletesz -- ɾ����С, �����ļ�ͷ��ʼɾ��deletesz���ֽڵ�����
** ����: ����ִ���Ƿ�����
** ����: wasfayu
*******/
_BOOL MsgCmd_DeleteFileFront(const WCHAR *fname, INT32U deletesz)
{
    _BOOL result;
    INT8U *buffer;
    const INT32U bufsz = 1024*2;
    INT32U count;
    INT32S writepos = 0;
    FS_HANDLE fd;

    if (NULL == fname || 0 == deletesz)
        return _TRUE;
    
    fd = FS_Open(fname, FS_READ_WRITE);
    if (fd < 0)
        return _FALSE;
    
    buffer = (INT8U*)MsgCmd_Malloc(bufsz, 0); //med_alloc_ext_mem
    do{
        result = _FALSE;
            
        //��λ������λ��
        if(FS_Seek(fd, deletesz, FS_FILE_BEGIN) < 0)
            return _FALSE;   

        if(FS_Read(fd, buffer, bufsz, &count) < 0)
            break;

        if(!count)
            break;

        deletesz += count;
        
        //��λ��д��λ��
        if(FS_Seek(fd, writepos, FS_FILE_BEGIN) < 0)
            break;

        if(FS_Write(fd, buffer, count, &count) < 0)
            break;

        if(!count)
            break;

        writepos += count;

        result = _TRUE;
        
    }while(1);

    MsgCmd_Mfree(buffer);
    
    FS_Seek(fd, writepos, FS_FILE_BEGIN);
    FS_Truncate(fd);
    FS_Commit(fd);
    FS_Close(fd);

    return result;
}

/*******************************************************************************
** ����: msgcmd_WriteImeiRsp
** ����: дIMEI�Ľ����Ӧ����
** ����:
** ����: д�Ľ����ο� nvram_errno_enum ���ö��.
** ����: wasfayu
*******/
static INT8U msgcmd_WriteImeiRsp(void *p)
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
** ����: MsgCmd_WriteImei
** ����: д��һ��IMEI.
** ���: num   - IMEI�����ַ���
**       strl  - IMEI�����ַ�������
**       sim   - 0-SIM1; 1-SIM2; 2-SIM3; 3-SIM4;
**       rsp   - �ص�����
** ����: �Ƿ�ִ�гɹ�
** ˵��: IMSI����15λ, ��ṹΪ: MCC+MNC+MSIN, (MNC+MSIN=NMSI).
**       MCC:Mobile Country Code, �ƶ�������, 
**           MCC����Դ�ɹ��ʵ���(ITU)ͳһ����͹���.
**           Ψһʶ���ƶ��û������Ĺ���, ��3λ. �й�Ϊ460;
**       MNC:Mobile Network Code, �ƶ�������, ��2λ.
**           �й��ƶ�TDϵͳʹ��00, �й���ͨGSMϵͳʹ��01, 
**           �й��ƶ�GSMϵͳʹ��02, �й�����CDMAϵͳʹ��03.
**           һ�����͵�IMSI����Ϊ460030912121001;
**       MSIN:Mobile Subscriber Identification Number.
**           ��10λ, ��ṹΪ:09+M0M1M2M3+ABCD
**           ���е� M0M1M2M3 �� MDN �����е� H0H1H2H3 �ɴ��ڶ�Ӧ��ϵ,
**           ABCD��λΪ���ɷ���.
**           ���Կ���IMSI��MSIN����ǰ����MCC��NMSI, 
**           ���������ÿ���û������ԵĹ���, ��˿���ʵ�ֹ�������.
**           ��ͬһ��������, ����ж���ƶ�������Ӫ��, ����ͨ��MNC����������.
**       SVN: Software Version Number. 
**           ����汾��, ����ͬ�ͺ��ֻ�����ʱʹ�õĲ�ͬ����汾.
** ����: http://zhidao.baidu.com/question/271966166.html
** ����: http://folk.uio.no/runeheg/imei/
** ����: wasfayu
*******/
_BOOL MsgCmd_WriteImei(CHAR *num, INT16U strl, INT8U sim, INT8U (*rsp)(void*))
{
#if defined(WIN32)
    return _FALSE;
#else
    INT8U i;
    CHAR ibuf[SRV_IMEI_MAX_LEN+2] = {0};
    ilm_struct *ilm_ptr = NULL;
    module_type src = MOD_MMI;//stack_get_active_module_id();//ֻ����MOD_MMI
    nvram_write_imei_req_struct *pmsg = (nvram_write_imei_req_struct*)\
        construct_local_para(sizeof(nvram_write_imei_req_struct), TD_CTRL|TD_RESET);
    
    if(strl < SRV_IMEI_MAX_LEN)
    {
        return _FALSE;
    }

    if(sim >= MMI_MAX_SIM_NUM)
    {
        return _FALSE;
    }
    
    for(i=0; i<strl; i++)
    {
        if(!(*(num+i) >= '0' && *(num+i) <= '9'))
        {
            return _FALSE;
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
        _FALSE);

    MsgCmd_SendIlmMsg(src, MOD_NVRAM, MMI_MMI_SAP, MSG_ID_NVRAM_WRITE_IMEI_REQ, pmsg);
    
//    ilm_ptr = allocate_ilm(src);
//    ilm_ptr->src_mod_id = src;
//    ilm_ptr->dest_mod_id = MOD_NVRAM;
//    ilm_ptr->sap_id = MMI_MMI_SAP;
//    ilm_ptr->msg_id = (msg_type)MSG_ID_NVRAM_WRITE_IMEI_REQ;
//    ilm_ptr->local_para_ptr = (local_para_struct *)pmsg;
//    ilm_ptr->peer_buff_ptr = NULL;
//    msg_send_ext_queue(ilm_ptr);

    return _TRUE;
#endif
}

/*******************************************************************************
** ����: msgcmd_SendSmsCallback
** ����: ����text���ŵĻص�����
** ����: pcbd  -- �ص������Ĳ���
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_SendSms
** ����: ����text����
** ����: to_asc_number  -- Ŀ�����, ASCII��ʽ�ַ���
**       ucs_text_ptr   -- ��������, UCS��ʽ�ı�
**       length_in_byte -- ucs_text_ptr�ĳ���, ���ֽ�Ϊ��λ
**       user_data_ptr  -- �û�����, ���ڻص������б�ʹ��
**       sim            -- ʹ������SIM�������Ͷ���
**       cb             -- ���Ͷ��ŵĻص�����, ���ΪNULL��ʹ��Ĭ�ϵĻص�����
** ����: ����_TRUE��ʾ����������ɹ�; ����_FALSE��ʾ����������ʧ��
** ����: wasfayu
*******/
_BOOL MsgCmd_SendSms(
    CHAR   *to_asc_number,
    INT8S  *ucs_text_ptr,
    INT16U  length_in_byte,
    void   *user_data_ptr,
    srv_sms_sim_enum sim,
    SrvSmsCallbackFunc cb)
{
    SMS_HANDLE sms_handle;
    INT8S ucs2_number[(SRV_SMS_MAX_ADDR_LEN + 1)*ENCODING_LENGTH] = {0};
    
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
	    return _FALSE;
    }

        
	mmi_asc_n_to_ucs2((CHAR*)ucs2_number, to_asc_number, SRV_SMS_MAX_ADDR_LEN);
    
    sms_handle = srv_sms_get_send_handle();
    //srv_sms_set_not_allow_empty_sc(sms_handle);
	srv_sms_set_address(sms_handle, (CHAR*)ucs2_number);
    srv_sms_set_content_dcs(sms_handle, SRV_SMS_DCS_UCS2);
    srv_sms_set_sim_id(sms_handle, sim);
    srv_sms_set_send_type(sms_handle, SRV_SMS_BG_SEND);
    //srv_sms_set_counter_without_change(sms_handle);
    srv_sms_set_no_sending_icon(sms_handle);
    srv_sms_set_content(sms_handle, (CHAR*)ucs_text_ptr, length_in_byte);
    
    srv_sms_send_msg(
        sms_handle, 
		cb==NULL ? msgcmd_SendSmsCallback : cb,
		(void*)user_data_ptr);

    return _TRUE;
}

#if defined(__MSGCMD_MMS_TEST__)
static mma_mms_addr_list_struct send_to_adr = {NULL, MMA_ADDR_TYPE_PHONE_NUMBER, MMA_ADDRESS_GROUP_TYPE_TO, NULL, NULL};
static mma_mms_description_struct descrp_main = {0};
static mma_mms_description_header_struct dscrp_head = {0};

static MsgCmd_send_mms_cb_cb(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_send_req_struct req;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    mc_trace("MsgCmd_send_mms_cb_cb, rsp_data=0x%x. user_data=0x%x.", rsp_data, user_data);
    
	req.msg_id = msg_rsp->msg_id;
	req.send_setting = SRV_MMS_SETTING_SAVE_AND_SEND;
	req.sim_id = MMI_SIM1;
	req.storage_type = MMA_MSG_STORAGE_PHONE;
	req.is_rr = MMI_TRUE;
	srv_mms_send(&req);
    MsgCmd_Mfree(user_data);
}

static void MsgCmd_send_mms_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
	
	srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;	
	srv_mms_save_req_struct param_mms_1;

    mc_trace("MsgCmd_send_mms_cb, required=%d. rsp_data=0x%x. user_data=0x%x.", msg_rsp->min_fs_space_required,rsp_data, user_data);
	if(msg_rsp->min_fs_space_required <= 0)
	{
		param_mms_1.app_id = msg_rsp->app_id;
		param_mms_1.call_back = MsgCmd_send_mms_cb_cb;//avk_msg_mms_0091_cb;
		param_mms_1.msg_id[0] = msg_rsp->msg_id;
		param_mms_1.no_of_msg = 1;
		param_mms_1.user_data = user_data;
		param_mms_1.box = MMA_FOLDER_OUTBOX;
		if(SRV_MMS_RESULT_OK != srv_mms_save(&param_mms_1))
        {
            MsgCmd_free(user_data);
        }      
	}
}

void MsgCmd_send_mms(WCHAR *file_path, CHAR *tonum, CHAR *tittle)
{
	S32 result_mms = 0;
	srv_mms_create_req_struct param_mms;
    mma_mms_header_struct *head_p = NULL;

    
    if(!mms_is_ready())
        return;
    
    send_to_adr.address = tonum;
    head_p = (mma_mms_header_struct*)MsgCmd_Malloc(sizeof(mma_mms_header_struct), 0);
    mc_trace("MsgCmd_send_mms, head_p=0x%x.", head_p);
    
    memset(&param_mms, 0, sizeof(srv_mms_create_req_struct));
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = MsgCmd_send_mms_cb;//avk_msg_mms_009_cb;
	param_mms.mode = MMA_MODE_SEND;
	param_mms.msg_id = 0;
	param_mms.sim_id = MMA_SIM_ID_SIM1;
	param_mms.user_data = (void*)head_p;
	param_mms.op_type = SRV_MMS_CREATE_MMS;
    param_mms.content_info = &descrp_main;
    param_mms.content_info->header = &dscrp_head;
    param_mms.content_info->header->header = head_p;
    param_mms.content_info->header->header->to = &send_to_adr;//srv_uc_convert_uc_addr_to_mms_addr();
    param_mms.content_info->header->header->subject.text = tittle;
    param_mms.content_info->header->header->subject.charset = MMA_CHARSET_ASCII;
	mmi_wcscpy((WCHAR *)param_mms.xml_filepath, (const WCHAR *)file_path);
	param_mms.xml_size =  applib_get_file_size(param_mms.xml_filepath);
	if(SRV_MMS_RESULT_OK != srv_mms_create(&param_mms))
    {
        MsgCmd_Mfree(head_p);
    }   
    head_p = NULL;
}

/* ʵ�ʲ��Է��ֿ��Է���ͼƬ��ȥ, ���Ǳ���ȷʵ��Ȼ��ʾΪ"��". */
void MsgCmd_send_mms_test(void)
{
    WCHAR filepath[64] = {0};

    mc_trace("%s, ready=%d.", __FUNCTION__, mms_is_ready());
    
    if(mms_is_ready())
    {
        kal_wsprintf(filepath, "%c:\\wmmp.jpg", MsgCmd_GetUsableDrive());
        MsgCmd_send_mms(filepath, "13712345678", "my mms");
    }
}

#endif


/*******************************************************************************
** ����: MsgCmd_AdoRecdBusy
** ����: �ж��Ƿ�����¼��
** ����: ��
** ����: ����_TRUE��ʾ����¼��; ����_FALSE��ʾû���κ�¼��
** ����: wasfayu
*******/
_BOOL MsgCmd_AdoRecdBusy(void)
{
    return _FALSE;
}

/*******************************************************************************
** ����: MsgCmd_AdoRecdStop
** ����: ֹͣ¼��¼��
** ����: replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ִ��ֹͣ¼��ʱ���صĴ�����
** ����: wasfayu
*******/
INT32S MsgCmd_AdoRecdStop(CHAR *replay_number)
{
    mc_trace(
        "%s, replay=%s.",
        __FUNCTION__, 
        replay_number?replay_number:"NULL");

    return 0;
}


/*******************************************************************************
** ����: MsgCmd_AdoRecdStart
** ����: ����¼��
** ����: forever       -- �Ƿ�����ʱ��¼��
**       time_in_sec   -- ¼��ʱ��, ����Ϊ��λ, ���foreverΪ��, ����ԸĲ���
**       replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ִ������¼��ʱ���صĴ�����
** ����: wasfayu
*******/
INT32S MsgCmd_AdoRecdStart(_BOOL forever, INT32U time_in_sec, CHAR *replay_number)
{
    mc_trace(
        "%s, forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

    return 0;
}


/*******************************************************************************
** ����: MsgCmd_AdoRecdStart
** ����: ����¼��
** ����: mms_it        -- �Ƿ����MMS��ʽ����, 
**                        ���replay_number�ǿ����͵�replay_number, 
**                        �����͵���һ��������������
**       replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ִ������¼��ʱ���صĴ�����
** ����: wasfayu
*******/
INT32S MsgCmd_Capture(_BOOL mms_it, CHAR *replay_number)
{
    mc_trace(
        "%s, mms_it=%d, replay=%s.",
        __FUNCTION__, 
        mms_it, 
        replay_number?replay_number:"NULL");

    return 0;
}

gdi_handle disphandle = NULL;

static INT32S msgcmd_VdoRecdPreview(void)
{
    INT32S ret;

    ret = mdi_video_rec_power_on();
	mc_trace("%s,L:%d, ret=%d.", __FUNCTION__, __LINE__, ret);

    if (MDI_RES_VDOREC_SUCCEED == ret)
    {
        mdi_video_setting_struct video_preview_data;		
		gdi_handle basehandle;
		PU8 base_layer_ptr;

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

        gdi_layer_get_base_handle(&basehandle);
		gdi_layer_push_and_set_active(basehandle);
	    gdi_layer_get_buffer_ptr(&base_layer_ptr);
		gdi_layer_create_using_outside_memory(0,0,240,320,&disphandle,base_layer_ptr,240*320*2);

		gdi_layer_set_active(disphandle);
		gdi_layer_clear(GDI_COLOR_BLACK);

		ret = mdi_video_rec_preview_start(
				disphandle,
				GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
				GDI_LAYER_ENABLE_LAYER_1,
				MMI_TRUE,
				&video_preview_data);
		mc_trace("%s,L:%d, ret=%d,disphandle=%d.base_layer_ptr=0x%x.", __FUNCTION__, __LINE__, ret,disphandle,base_layer_ptr);

        if (MDI_RES_VDOREC_SUCCEED == ret)
		{
			//StartTimer(VDOREC_TIMER, 1000, video_record_start);
		}
		else
		{
			mdi_video_rec_preview_stop();
			mdi_video_rec_power_off();
			video_free_gui_layer();
		}
    }
    
    return ret;
}

/*******************************************************************************
** ����: MsgCmd_VdoRecdBusy
** ����: �ж��Ƿ�����¼��
** ����: ��
** ����: ����_TRUE��ʾ����¼��; ����_FALSE��ʾû���κ�¼��
** ����: wasfayu
*******/
_BOOL MsgCmd_VdoRecdBusy(void)
{
    return _FALSE;
}

/*******************************************************************************
** ����: MsgCmd_VdoRecdStop
** ����: ֹͣ¼��¼��
** ����: replay_number -- ��ʾ�ظ�ֹͣ�����ָ������, ���Ϊ�����ʾ���ظ�
** ����: ִ��ֹͣ¼��ʱ���صĴ�����
** ����: wasfayu
*******/
INT32S MsgCmd_VdoRecdStop(CHAR *replay_number)
{
    mc_trace(
        "%s, replay=%s.",
        __FUNCTION__, 
        replay_number?replay_number:"NULL");

    return 0;
}


/*******************************************************************************
** ����: MsgCmd_VdoRecdStart
** ����: ����¼��
** ����: forever       -- �Ƿ�����ʱ��¼��
**       time_in_sec   -- ¼��ʱ��, ����Ϊ��λ, ���foreverΪ��, ����ԸĲ���
**       replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ִ������¼��ʱ���صĴ�����
** ����: wasfayu
*******/
INT32S MsgCmd_VdoRecdStart(_BOOL forever, INT32U time_in_sec, CHAR *replay_number)
{
    mc_trace(
        "%s, forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

    return 0;
}


#endif/*__MESSAGE_COMMAND_SUPPORT__*/

