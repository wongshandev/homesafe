
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
** ����: at_shutdown
** ����: AT����, �ն˹ػ�
** ���: vp
** ����: ��
** ����: wasfayu
*******/
static void at_shutdown(AtParam_t *vp);

/*******************************************************************************
** ����: at_reboot
** ����: AT����, �ն˹ػ�
** ���: vp
** ����: ��
** ����: wasfayu
*******/
static void at_reboot(AtParam_t *vp);

/*******************************************************************************
** ����: at_catch
** ����: AT����, MTK��catch��������
** ���: vp
** ����: ��
** ����: wasfayu
*******/
static void at_catch(AtParam_t *vp);

/*******************************************************************************
** ����: at_adorecd
** ����: AT����, ����¼��
** ���: vp
** ����: ��  at$adorecd=(0,1),time,number
** ����: wasfayu
*******/
static void at_adorecd(AtParam_t *vp);

/*******************************************************************************
** ����: at_vdorecd
** ����: AT����, ����¼��
** ���: vp
** ����: ��  at$vdorecd=(0,1),time,number
** ����: wasfayu
*******/
static void at_vdorecd(AtParam_t *vp);

/*******************************************************************************
** ����: at_capture
** ����: AT����, ��������
** ���: vp
** ����: ��  at$capture[=number]
** ����: wasfayu
*******/
static void at_capture(AtParam_t *vp);

static void at_disksize(AtParam_t *vp);


static MsgCmdRecdArg *msgcmd_GetVdoRecdArgs(void);


#define MsgCmd_Malloc(s, v) MsgCmd_MemAlloc(s, v, __FUNCTION__, __LINE__)
#define MsgCmd_Mfree(p) MsgCmd_MemFree(p, __FUNCTION__, __LINE__)

/* ��ʱ��ID���� */
#define MSGCMD_TIMER_REBOOT       (TIMER_ID_LFY_BASE + 0)
#define MSGCMD_TIMER_SHUTDOWN     (TIMER_ID_LFY_BASE + 1)
#define MSGCMD_TIMER_FACTORY      (TIMER_ID_LFY_BASE + 2)
#define MSGCMD_TIMER_INT_RECHECK  (TIMER_ID_LFY_BASE + 3)
#define MSGCMD_TIMER_VDO_CHECK    (TIMER_ID_LFY_BASE + 4)
#define TIMER_DTMF_KEY_DETECT     (TIMER_ID_LFY_BASE + 5)
#define TIMER_DTMF_DELAY_EXEC     (TIMER_ID_LFY_BASE + 6)

/* ��ϢID���� */
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

//�Զ���AT�����
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
** ����: cb_close_log_file
** ����: �ر���־����
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void cb_close_log_file(void)
{
    if (logFH >= FS_NO_ERROR)
        FS_Close(logFH);

    logFH = -1;
}

/*******************************************************************************
** ����: cb_write_log
** ����: ��־��ӡ����, д�뵽���̵��ļ���
** ����: fmt -- ��ӡ��ʽ�����ַ���
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_GetInteger
** ����: �Ӹ������ȵ��ַ����л�ȡһ��32λ�޷�������
** ����: ps  ��������
**       sl  �ַ�������
**       type  �ַ�������
** ����: ��ȡ�ɹ����ض�Ӧ��ֵ, ʧ�ܷ���-1
** ����: wasfa
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
** ����: MsgCmd_Atoi
** ����: ϵͳ����atoi�İ�װ
** ����: 
** ����: 
** ����: wasfa
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
** ����: MsgCmd_IsDigStr
** ����: �ж��Ƿ��������ַ���, 0~9���
** ����: 
** ����: 
** ����: wasfa
*******/
MMI_BOOL MsgCmd_IsDigStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isdigit(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsXdigStr
** ����: �ж��Ƿ���16�����ַ���, 0~9, A~F, a~f���
** ����: 
** ����: 
** ����: wasfa
*******/
MMI_BOOL MsgCmd_IsXdigStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isxdigit(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsXdigFmtStr
** ����: �Ƿ���16���Ƹ�ʽ��ͷ���ַ���, ����0x��ͷ�������ַ���
** ����: 
** ����: 
** ����: wasfa
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
** ����: MsgCmd_IsAlpNumstr
** ����: �Ƿ�����ĸ�����ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
MMI_BOOL MsgCmd_IsAlpNumStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isalnum(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsAlphaStr
** ����: �Ƿ�����ĸ�ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
MMI_BOOL MsgCmd_IsAlphaStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isalpha(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsSpaceStr
** ����: �Ƿ��ǿհ��ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
MMI_BOOL MsgCmd_IsSpaceStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isspace(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsLowerStr
** ����: �Ƿ���Сд�ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
MMI_BOOL MsgCmd_IsLowerStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!islower(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/*******************************************************************************
** ����: MsgCmd_IsUpperStr
** ����: �Ƿ��Ǵ�д�ַ���
** ����: 
** ����: 
** ����: wasfa
*******/
MMI_BOOL MsgCmd_IsUpperStr(const char *ps, U32 sl)
{
    while(sl--)
        if(!isupper(*ps++))
            return MMI_FALSE;

    return MMI_TRUE;
}

/* ������ linux V3.2 source code ���� strpbrk
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
** ����: MsgCmd_MemFree
** ����: �ͷ���MsgCmd_MemAlloc���������ڴ�
** ����: memptr   ��ʾ��Ҫ�ͷŵ��ڴ��ַ.
** ����: ��
** ˵��: med_free_ext_mem�Ǹ��ܱ�̬�ĺ���, ��ȻҪȡ��ַ֮�������ַ. ����...
** ����: wasfayu
*******/
void MsgCmd_MemFree(void *p, const char* file, U32 line)
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
void *MsgCmd_ConstructPara(U32 sz)
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
** ����: MsgCmd_GetCallCount
** ����: ��ȡ�绰����
** ����: ��
** ����: ���ص绰����
** ����: wasfayu
*******/
S32 MsgCmd_GetCallCount(void)
{
    return srv_ucm_query_call_count(
                SRV_UCM_CALL_STATE_ALL,
                SRV_UCM_CALL_TYPE_ALL,
                NULL);
}

/*******************************************************************************
** ����: MsgCmd_IsSdCardExist
** ����: �жϴ洢���Ƿ����
** ����: ��
** ����: �Ƿ����
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsSdCardExist(void)
{
    return srv_fmgr_drv_is_accessible(SRV_FMGR_CARD_DRV);
}

/*******************************************************************************
** ����: MsgCmd_GetDiskFreeSize
** ����: ��ȡ����ʣ��ռ�
** ����: drive, �����̷�, 0x43~0x47
** ����: ʣ��ռ�Ĵ�С, byteΪ��λ
** ����: wasfayu
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
** ����: MsgCmd_CheckValidDrive
** ����: ���������̷��Ƿ��ѹ���
** ����: �̷�, C/D/E/F...
** ����: �����̿ɹ�ʹ��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_CheckValidDrive(U32 drive)
{
    return (MMI_BOOL)(FS_NO_ERROR == FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM));
}

/*******************************************************************************
** ����: MsgCmd_GetUsableDrive
** ����: ��ȡϵͳ���õĴ洢�豸�̷�
** ����: ��
** ����: �����̷� 0x43~0x47
** ����: wasfayu
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
** ����: MsgCmd_GetSystemDrive
** ����: ��ȡϵͳ�̵��̷�
** ����: ��
** ����: Success:                0x43~0x47 (A~G)
**       Error:                  RTF_PARAM_ERROR        (-2)
**                               RTF_DRIVE_NOT_FOUND    (-4)
** ����: wasfayu
*******/
S32 MsgCmd_GetSystemDrive(void)
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
U32 MsgCmd_GetFileSize(WCHAR *path)
{
    return applib_get_file_size(path);
}

/*******************************************************************************
** ����: MsgCmd_CombineFilePath
** ����: ����ļ��ľ���·��, Ŀ¼���Ϊһ��
** ����: pathbuffer     -- װ�����·����buffer
**       length_in_byte -- out�ĳ���, ���ֽ�Ϊ��λ, ����Ӧ�ô���32���ֽ�����
**       folder         -- �ļ��е�����, �� L"audio"
**       ext_name       -- ��չ��������, �� L".mp3"
** ����: �����ļ�����ַ, ��û��ǰ���path, ָ��pathbuffer��ĳ��Ԫ�صĵ�ַ
** ����: wasfayu
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

    //�ȴ�ӡ·��
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

    //�ٴ�ӡ�ļ���
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
** ����: MsgCmd_GetCurrentTime
** ����: ��ȡϵͳ��ǰ������ʱ��
** ����: ��
** ����: ����ʱ��
** ����: wasfayu
*******/
U32 MsgCmd_GetCurrentTime(void)
{
    return app_getcurrtime();
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
MMI_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t)
{
    return applib_dt_is_valid(t);
}

/*******************************************************************************
** ����: MsgCmd_DeleteFileFront
** ����: ɾ���ļ���ǰ��
** ���: fullPathName -- �ļ��ľ���·����, UCS��ʽ, �� "D:\\myfile.txt"
**       deletesz     -- ɾ����С, �����ļ�ͷ��ʼɾ��deletesz���ֽڵ�����
** ����: ����ִ���Ƿ�����
** ����: wasfayu
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
            
        //��λ������λ��
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
        
        //��λ��д��λ��
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
** ����: msgcmd_DeleteOldFile
** ����: �����ļ��б��еļ�¼ɾ���ļ�
** ���: fullname   -- ¼���ļ��ľ���·���ļ���, UCS��ʽ
**       cmpSzKB    -- ��Ҫɾ�����ܴ�С, KB
** ����: ����ִ���Ƿ�����
** ����: wasfayu
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
            
            //ȥ��β���ϵĻس����з�
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
** ����: msgcmd_RecordFileName
** ����: ��ĳ���ļ���UCS��ʽ����pdataд�뵽fname�ļ���ȥ
** ���: fname   -- �ļ���, UCS��ʽ
**       ascname -- ��д����ļ���, ASCII��ʽ
**       asclen  -- ��д����ļ�������
** ����: �Ƿ�д��ɹ�
** ����: wasfayu
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
** ����: MsgCmd_DelayTick
** ����: ��ʱdt��tick
** ����: dt -- Ҫ��ʱ��tick����
** ����: ��
** ˵��: һ��tick�����10ms
** ����: wasfayu
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
** ����: at_print
** ����: AT������Դ�ӡ����
** ���: vp
** ����: ��
** ����: wasfayu
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
** ����: at_sample
** ����: AT����, ʾ������, ���ƹ�ȥ, ֱ�Ӹ��º�����, 
**       Ȼ���ں������ڶ�Ӧ��CASE���޸��޸ľͺ���.
** ���: vp
** ����: ��
** ����: wasfayu
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
            //������Ҫ�Ĵ����������
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
** ����: at_shutdown
** ����: AT����, �ն˹ػ�
** ���: vp
** ����: ��
** ����: wasfayu
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
** ����: at_reboot
** ����: AT����, �ն˹ػ�
** ���: vp
** ����: ��
** ����: wasfayu
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
** ����: at_catch
** ����: AT����, MTK��catch��������
** ���: vp
** ����: ��
** ����: wasfayu
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
** ����: at_adorecd
** ����: AT����, ����¼��
** ���: vp
** ����: ��  at$adorecd=(0,1),time,number
** ����: wasfayu
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
** ����: at_vdorecd
** ����: AT����, ����¼��
** ���: vp
** ����: ��  at$vdorecd=(0,1),time,number
** ����: wasfayu
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
** ����: at_capture
** ����: AT����, ��������
** ���: vp
** ����: ��  at$capture[=number]
** ����: wasfayu
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
** ����: msgcmd_AtCmdLineParse
** ����: AT�����н���
** ���: argOut �������
**       cmdStr �������ַ�
** ����: ��������
** ����: wasfayu
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

    //�϶��д���
    if(dQuote)
    {
        lfy_trace("[SPLIT] quote error. argc=%d", argc);
        argc = 0;
    }
    
    return argc;
}

/*******************************************************************************
** ����: MsgCmd_AtCmdProc
** ����: �����Զ���AT����
** ����: origStr  -- AT�����в���, 
**                   ��������Զ����ATָ���򲻿��ƻ�cmd_string�е�����
** ����: �Ƿ����Զ���ATָ��
** ����: wasfayu
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
                    return MMI_TRUE; //��ֹforѭ��
                }
            }
        }
    }

    return MMI_FALSE;
}

#if 1
extern const unsigned char MSGCMD_EINT_NO;

#define MC_EINT_NO         MSGCMD_EINT_NO
#define MSGCMD_INTERRUPT_DIFF_LEVEL  0 //�͵�ƽ�����ⲿ�ж�

/*******************************************************************************
** ����: msgcmd_InterruptProcess
** ����: �ⲿ�ж���Ӧ����
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_InterruptRespond(void *p)
{
	MsgCmdExtIntReq *rsp = (MsgCmdExtIntReq*)p;

	lfy_trace("%s, level=%d.", __FUNCTION__, rsp->level);
}

/*******************************************************************************
** ����: msgcmd_InterruptEntrance
** ����: �ⲿ�ж���Ӧ��ں���
** ����: ��
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_InterruptMask
** ����: ����/���ⲿ�ж�
** ����: mask  -- ����
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_InterruptRegister
** ����: �ⲿ�ж�ע��, �����ڶ������ʼ����ʱ���ע��, 
**       �������EINT_LISR����"ASSERT(EINT_FUNC[index].eint_func!=NULL);"
** ����: void
** ����: ��
** ����: wasfayu
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

    //�ʼ������״̬, ����ʼ��֮���ٴ�
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
** ����: msgcmd_CreateMMSXMLFile
** ����: ����MMS����ʱ��Ҫ��XML�ļ�
** ���: MsgCmdMMSXmlData -- ����XML�ļ�������
** ����: �Ƿ�ɹ�
** ˵��: ����srv_uc_create_mms_xml_description_file���������ƵĹ�������ɲ���
** ����: wasfayu
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
        slide_num[0] = '1'; //ֻ��һ��slide
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_SLIDE_NUM;
        attr_list[i++] = slide_num;
        /*-----object number--------------------------------------------------*/
        memset(obj_num, 0, str_len);
        obj_num[0] = '1'; //ֻ��һ��object
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_OBJ_NUM;
        attr_list[i++] = obj_num;
        /*-----layout type----------------------------------------------------*/
        memset(layout, 0, str_len);
        layout[0] = '1'; //����, �μ�mma_slide_layout_enum
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
        bg_color[0] = '1'; //ֻ��һ��ͼƬ, һ��slide
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_INDEX;
        attr_list[i++] = bg_color;
        /*--------------------------------------------------------------------*/
        memset(fg_color, 0, str_len);
        fg_color[0] = '5'; //ֻ��5����
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
        sprintf((char*)slide_num, "1"); //ֻ��һ��ͼƬ, ��˾�ֻ��һ��slide, ����ֱ�Ӹ���slide indexΪ1
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_ID;
        attr_list[i++] = slide_num;
        /*-----start time-----------------------------------------------------*/
        memset(obj_num, 0, str_len);
        sprintf((char*)obj_num, "0"); //ֻ��һ��ͼƬ, ��0�뿪ʼ
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_BEGIN;
        attr_list[i++] = obj_num;
        /*-----end time-------------------------------------------------------*/
        memset(layout, 0, str_len);
        sprintf((char*)layout, "5"); //ֻ��һ��ͼƬ, ��5���ֽ���
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
        bg_color[0] = '1'; //ֻ��һ��object, ǿ�Ƹ���Ϊ1
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
** ����: msgcmd_SendMMSResponse
** ����: �������ҷ���MMS�Ļص�����
** ���: result   -- 
**       rsp_data -- srv_mms_create_rsp_struct
**       user_data-- 
** ����: �Ƿ�ɹ�
** ����: wasfayu
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
** ����: MsgCmd_CreateAndSendMMSCb
** ����: �������ҷ���MMS�Ļص�����
** ���: result   -- 
**       rsp_data -- srv_mms_create_rsp_struct
**       user_data-- 
** ����: �Ƿ�ɹ�
** ����: wasfayu
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
** ����: MsgCmd_CreateAndSendMMS
** ����: �������ҷ���MMS
** ���: xml_path  -- MMS�����ļ�, �����Ѿ������е绰������Щ��
**       sim       -- mma_sim_id_enum
** ����: �Ƿ�ɹ�
** ����: wasfayu
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
** ����: msgcmd_CaptureFinish
** ����: ���ս���
** ����: ��
** ����: �Ƿ�ɹ��ر�����ͷ
** ����: wasfayu
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
** ����: msgcmd_CaptureDoing
** ����: ִ�����ղ�������Ƭ
** ����: filename -- ��Ƭ����
** ����: �Ƿ����ղ�����ɹ�
** ����: wasfayu
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
** ����: msgcmd_CapturePreview
** ����: ��������Ԥ��
** ����: pictureW  -- ��Ƭ���
**       pictureH  -- ��Ƭ�߶�
** ����: �Ƿ�Ԥ���ɹ�
** ����: wasfayu
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
** ����: msgcmd_CaptureResponse
** ����: ����������Ӧ����
** ����: p -- MsgcmdCaptureReq
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_CaptureEntry
** ����: ����
** ����: replay_number -- ���պ�ش���Ƭ��ָ������, �����͵���������.
** ����: �Ƿ����ճɹ�
** ����: wasfayu
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
** ����: msgcmd_VdoRecdGetSavePath
** ����: ��ȡ¼�񱣴��·��
** ����: buffer  -- ·�����
**       length_in_byte -- ·�����buffer�ĳ���, �ֽ�Ϊ��λ
** ����: ·��buffer��ַ
** ����: wasfayu
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
** ����: msgcmd_VdoRecdGetFilePath
** ����: ��ȡ¼���ļ��ľ���·��
** ����: buffer  -- �ļ�����·�����
**       length_in_byte -- �ļ�·�����buffer�ĳ���, �ֽ�Ϊ��λ
** ����: �ļ�����·��buffer��ַ
** ����: wasfayu
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
** ����: msgcmd_VdoRecdFreeSpaceCheck
** ����: �ͷſռ�
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_VdoRecdFreeSpaceCheck(void)
{
	U32 left, need;
    
	//һ���Ӿ���110KB, ���Ҫ����ʣ��ռ�Ļ�, ����Ҫ�������
    //����ʣ��ռ�С��5M��ɾ���͵�¼���ļ�
    left = MsgCmd_GetDiskFreeSize(MsgCmd_GetUsableDrive()) >> 10;
    need = MSGCMD_VDO_SIZE_PER_SEC_KB * msgcmd_GetVdoRecdArgs()->save_gap * 2;
    
	lfy_trace("%s, left=%dKB.need=%dKB.", __FUNCTION__, left, need);

	if (left <= need)
		msgcmd_DeleteOldFile(MSGCMD_VDO_LIST_FILE_NAME, need);
}

/*******************************************************************************
** ����: msgcmd_VdoRecdSaveCb
** ����: ¼�񱣴�Ļص�����
** ����: result  -- ������
** ����: ��
** ����: wasfayu
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
        //ģ�����������д��һЩ���ݳ����
        if (rand()%4==0)
        {
            MsgCmd_ModisCreateAVI(vrm->filepath);
        }
    #endif
    
        //����ļ�С�����ֵ��ɾ������
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
            
            //�����׷��, ������һ��ʱ��, ʱ��ΪĬ�ϵı�����ʱ��
            if (vrm->append)
            {
				lfy_trace("%s, time=%dS, add time(%dS).", __FUNCTION__, vrm->time, msgcmd_GetVdoRecdArgs()->save_gap);
                vrm->time  += msgcmd_GetVdoRecdArgs()->save_gap;
            }

            //ʣ��ʱ��С��xx������Ե�
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
        //����Ϣ��ȥ����¼��
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
** ����: msgcmd_VdoRecdDoingCb
** ����: ¼��������Ļص�����
** ����: result  -- ¼���������
** ����: ��
** ����: wasfayu
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
** ����: msgcmd_VdoRecdLayerMngr
** ����: ¼�����ʾ�����
** ����: create  -- ¼���������
**       layer   -- �����ĵ�ַ
** ����: ��
** ����: wasfayu
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
** ����: msgcmd_VdoRecdPowerMngr
** ����: ¼���Դ����
** ����: on  -- �Ƿ�򿪵�Դ
** ����: ��/�رյ�Դ�Ƿ�ɹ�
** ����: wasfayu
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
** ����: msgcmd_VdoRecdPreview
** ����: ¼��Ԥ��
** ����: start  -- ��ʼ/ֹͣԤ��
** ����: ��ʼ/ֹͣԤ���Ƿ�ɹ�
** ����: wasfayu
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
** ����: msgcmd_VdoRecdDoing
** ����: ��ʼ¼��
** ����: filepath -- �ļ����·��
** ����: �Ƿ�ɹ�ִ��¼��
** ����: wasfayu
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
** ����: msgcmd_VdoRecdDelete
** ����: ɾ��δ������ļ�
** ����: filepath -- �ļ����·��
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_VdoRecdDelete(WCHAR *filepath)
{
    mdi_video_rec_delete_unsaved_file((S8*)filepath);
    lfy_trace("%s.", __FUNCTION__);
}

/*******************************************************************************
** ����: msgcmd_VdoRecdSafe
** ����: ����¼���ļ�
** ����: filepath -- �ļ����·��
** ����: ������
** ����: wasfayu
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
** ����: msgcmd_VdoRecdTimerCyclic
** ����: ��ʱ���Ļص�����
** ����: ��
** ����: ��
** ����: wasfayu
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
** ����: msgcmd_VdoRecdCyclicTimer
** ����: ��ʱ������
** ����: start -- ����/ֹͣ
** ����: ��
** ����: wasfayu
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
** ����: msgcmd_VdoRecdResponse
** ����: ¼������/ֹͣ������Ӧ����
** ����: p -- MsgcmdVdoProcReq
** ����: ��
** ����: wasfayu
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
** ����: msgcmd_VdoRecdContRecdRsp
** ����: ����¼�����Ϣ��Ӧ
** ����: p -- 
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_VdoRecdGetContext
** ����: ��ȡ¼���������ĵ�ַ
** ����: ��
** ����: ���ع�������ĵ�ַ
** ����: wasfayu
*******/
VdoRecdMngr *MsgCmd_VdoRecdGetContext(void)
{
    return vrm;
}

/*******************************************************************************
** ����: MsgCmd_VdoRecdSetAppend
** ����: ����һ��¼��ʱ��
** ����: ��
** ����: ���������Ƿ�ɹ�
** ����: wasfayu
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
** ����: MsgCmd_VdoRecdBusy
** ����: �ж��Ƿ�����¼��
** ����: ��
** ����: ����_TRUE��ʾ����¼��; ����_FALSE��ʾû���κ�¼��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdBusy(void)
{
    return (MMI_BOOL)(NULL != vrm);
}

/*******************************************************************************
** ����: MsgCmd_VdoRecdStop
** ����: ֹͣ¼��¼��
** ����: replay_number -- ��ʾ�ظ�ֹͣ�����ָ������, ���Ϊ�����ʾ���ظ�
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_VdoRecdStart
** ����: ����¼��
** ����: forever       -- �Ƿ�����ʱ��¼��
**       time_in_sec   -- ¼��ʱ��, ����Ϊ��λ, ���foreverΪ��, ����ԸĲ���
**       auto_save_gap -- �Զ�������, ����Ϊ��λ
**       replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: �����Ƿ�ɹ�
** ����: wasfayu
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

    //T�������ھͷ���
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

    //����δ��ȡ��
    if ((drive = MsgCmd_GetUsableDrive()) < 0)
        return MMI_FALSE;

    //��ȡ���̷��Ƿ���ȷ����--�����Ƿ���ڵ�һ����˼
    if (!MsgCmd_CheckValidDrive(drive))
        return MMI_FALSE;
    else
    {
        WCHAR buffer[MSGCMD_FILE_PATH_LENGTH+1];

        msgcmd_VdoRecdGetSavePath(
            buffer, 
            MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR));
        
        //�Ƿ���δ���������Ƶ
        if (mdi_video_rec_has_unsaved_file((S8*)buffer))
        {
            MDI_RESULT ret;
            
            //����֮?ɾ��֮?
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
 * ��������ʾ���������֮����ܿ����������, �������ɰ�������
 * ����Զ�����ʾ������ʧ��, ��Ҫ����ϵͳ����ʾ��
 * �����ʾ������ʧ��, ��ֱ�ӽ��밴�����
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
** ����: Dtmf_Reset
** ����: ������λ
** ����: ��
** ����: ��
** ����: wasfayu
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
** ����: Dtmf_Initialize
** ����: ��ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
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

    //���û�е绰��ͨ����
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
** ����: dtmf_CmdExecRsp
** ����: ִ������
** ����: p -- DtmfCmdExecReq
** ����: ��
** ����: wasfayu
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
** ����: dtmf_PostCmdExecReq
** ����: ��������ִ������
** ����: cmd    -- Ԥִ�е�����
**       number -- �ظ���Ϣ�ĺ���
**       param  -- �������
** ����: ��
** ����: wasfayu
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
    //��ʱ2����ȥִ��, ����������������
#if defined(__EXEC_IN_TIMER_CBF__)
    StartTimerEx(TIMER_DTMF_DELAY_EXEC, 2000, dtmf_CmdExecRsp, (void *)req);
#else
    MsgCmd_SendIlm2Mmi(MSG_ID_DTMF_EXEC_CMD_REQ, (void*)req);
#endif
}

/*******************************************************************************
** ����: dtmf_ReleaseAllActivedCall
** ����: �Ҷ����е绰
** ����: exec -- �Ƿ�ִ������
** ����: ��
** ����: wasfayu
*******/
static void dtmf_ReleaseAllActivedCall(MMI_BOOL exec)
{   
    srv_ucm_result_enum ret;
    
    //�Ҷϵ绰
    ret = mmi_ucm_simple_option(SRV_UCM_END_ALL_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    dtmf_trace("Release Call return %d.", ret);
    
    AlmEnableExpiryHandler();

    if (exec)
    {
        //������Ϣȥִ������
        dtmf_PostCmdExecReq(dtmfCnxt.command, dtmfCnxt.call.number, NULL);
    }
}

/*******************************************************************************
** ����: dtmf_KeyDetectTimeoutCb
** ����: ������ⳬʱ�ص�����
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_KeyDetectTimeoutCb(void)
{
    MMI_BOOL playOK;

    dtmf_StopKeyDetect();

    //�ﵽ������, ֱ�ӹҶϵ绰
    if (dtmfCnxt.rptCount++ >= dtmfCnxt.rptMax)
    {
        dtmf_ReleaseAllActivedCall(MMI_FALSE);
        Dtmf_Reset();
        return;
    }
    
    //���²�����ʾ��
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_WAITING_ENTRY:
        //���ڵȴ�����, ������ⳬʱ, �ظ�����
        //ϵͳ����, ������ʾ�� 1Entry.wav
        dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
        if (!playOK)
        {
            //����ʧ������밴�����
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
    case DTMF_STATE_INPUT_PWD:
        //�ȴ���������, ��ʱ���ظ�����
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
** ����: dtmf_SwitchFSMStatus
** ����: �л�״̬����״̬
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void dtmf_SwitchFSMStatus(void)
{
    MMI_BOOL playOK;

    dtmf_trace("%s: ENTRY state=%d.", __FUNCTION__,dtmfCnxt.state);
    
    switch (dtmfCnxt.state)
    {
    case DTMF_STATE_IDLE:
        //ϵͳ����, ������ʾ�� 1Entry.wav
        dtmfCnxt.detectTime = DTMF_ENTRY_DETECT_TIME;
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_PRESS_TO_ENTRY, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_WAITING_ENTRY;
        if (!playOK)
        {
            //����ʧ������밴�����
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
    case DTMF_STATE_WAITING_ENTRY:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //ϵͳ�Ѿ�����, ������ʾ�� 2Password.wav
    #if defined(__NEED_CHECK_PASSWORD__)
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PASSWORD, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
    #else
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
    #endif
        if (!playOK)
        {
            //����ʧ������밴�����
            dtmf_StartKeyDetect(dtmfCnxt.detectTime);
        }
        break;
        
#if defined(__NEED_CHECK_PASSWORD__)
    case DTMF_STATE_INPUT_PWD:
        dtmfCnxt.detectTime = DTMF_DEF_DETECT_TIME;
        //��������Ƿ���Ч
        if (dtmfCnxt.param.password[7] == 6 &&
            strncmp(dtmfCnxt.param.password, "123456", 6) == 0)
        {
            //������ʾ�� 3Option.wav
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_CHOOSE_OPTION, (void*)dtmfCnxt.detectTime);
            dtmfCnxt.state = DTMF_STATE_CHOOSE_OPTION;
            if (!playOK)
            {
                //����ʧ������밴�����
                dtmf_StartKeyDetect(dtmfCnxt.detectTime);
            }
        }
        else if (dtmfCnxt.rptCount < dtmfCnxt.rptMax)
        {
            //�������
            dtmfCnxt.param.password[7] = 0;
            //������ʾ�� 3Option.wav
            playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_RETRY_PASSWORD, (void*)dtmfCnxt.detectTime);
            dtmfCnxt.state = DTMF_STATE_INPUT_PWD;
            if (!playOK)
            {
                //����ʧ������밴�����
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
        //������ʾ�� 7Param.wav
    #if defined(__RECIVE_CMD_PARAMETER__)
        playOK = dtmf_PlayPromptVoiceFile(DTMF_VOC_INPUT_PARAM, (void*)dtmfCnxt.detectTime);
        dtmfCnxt.state = DTMF_STATE_INPUT_PARAM;
        if (!playOK)
        {
            //����ʧ������밴�����
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
** ����: dtmf_KeyDetectCallback
** ����: �������ص�����
** ����: ��
** ����: ��
** ����: wasfayu
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
            //��������״̬
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
            //��������, ���¼��, ������ʾ��
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
            //��������
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
            //��������, ��������
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
            //��¼����
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
** ����: dtmf_StartKeyDetect
** ����: ��ʼDTMF�İ������
** ����: ��
** ����: ��
** ����: wasfayu
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
        //ʧ����, ������ʾ
    }
}

/*******************************************************************************
** ����: dtmf_StopKeyDetect
** ����: ֹͣDTMF�������
** ����: ��
** ����: ��
** ����: wasfayu
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
** ����: dtmf_CombineVoiceFilePath
** ����: ���������ļ�·��
** ����: output   -- �ļ�����·�����
**       fileindex-- �ļ�����
** ����: output�ĵ�ַ
** ����: wasfayu
*******/
static WCHAR *dtmf_CombineVoiceFilePath(WCHAR *output, DtmfVoiceIndex index)
{
    ASSERT(NULL != output);

    kal_wsprintf(output, "%c:\\%w\\%s",
        MsgCmd_GetUsableDrive(),DTMF_VOICE_MAIN_PATH,voiceTab[index].name);
    
    return output;    
}

/*******************************************************************************
** ����: dtmf_PlayCustomPromptVoiceFileCb
** ����: �����û��Զ�����ʾ��Ļص�����
** ����: result -- ���Ž��
**       usd    -- �û�����
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PlayCustomPromptVoiceFileCb(mdi_result result, void *usd)
{
    dtmf_trace("Play custom voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //�����ǰ״̬Ϊxx״̬�򷵻�
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        //�ȴ��������
    }
    else
    {
        //����ʧ��, ���²���ϵͳ�Դ�����Դ
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
** ����: dtmf_PlaySystemPromptVoiceFileCb
** ����: ����ϵͳ��ʾ��Ļص�����
** ����: result -- ���Ž��
**       usd    -- �û�����
** ����: ��
** ����: wasfayu
*******/
static void dtmf_PlaySystemPromptVoiceFileCb(mdi_result result, void *usd)
{
    dtmf_trace("Play system voice Callback, ret=%d. state=%d.", result, dtmfCnxt.state);

    //�����ǰ״̬Ϊxx״̬�򷵻�
    
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        //�ȴ��������
    }
    else
    {
        //����ʧ��, ��������, ֱ�ӽ��а������ʲô��
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
** ����: dtmf_GetSystemVoiceFileId
** ����: ��ȡϵͳ��ʾ�����ļ�ID
** ����: idx  -- ������Դ����
** ����: ϵͳ������ԴID
** ����: wasfayu
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
** ����: dtmf_PlayCustomVoiceFile
** ����: �����û���ʾ��
** ����: idx  -- ������Դ����
**       cbf  -- �ص�����
** ����: �Ƿ񲥷ųɹ�
** ����: wasfayu
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
** ����: dtmf_PlaySystemVoiceFile
** ����: ����ϵͳ��ʾ��
** ����: idx  -- ������Դ����
**       cbf  -- �ص�����
** ����: �Ƿ񲥷ųɹ�
** ����: wasfayu
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
    
    //����ϵͳ����ʾ��
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
** ����: dtmf_PlayPromptVoiceFile
** ����: ������ʾ��
** ����: idx  -- ������Դ����
**       cbf  -- �ص�����
** ����: �Ƿ񲥷ųɹ�
** ����: wasfayu
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
** ����: dtmf_AutoAnswerResponse
** ����: ����Ӧ���������Ϣ��Ӧ����
** ����: p  -- DtmfAutoAnswerReq
** ����: ��
** ����: wasfayu
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
** ����: Dtmf_AutoAnswerReqSend
** ����: ��������Ӧ���������Ϣ
** ����: name  -- �������
**       number-- ��ʾ����
** ����: ��
** ����: wasfayu
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
** ����: lfy_WriteFile
** ����: ������д���ļ�
** ����: filepath   -- �ļ��ľ���·��
**       cover      -- �Ƿ񸲸�ԭ��������, �������׷�����ļ�ĩβ
**       data       -- ���ݿ�
**       length     -- ���ݿ�ĳ���
** ����: ʵ��д������ݳ���
** ����: wasfayu
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
** ����: lfy_create_path
** ����: ����·��
** ����: dirve     -- �̷�
**       UcsFolder -- �ļ���
** ����: ��
** ����: wasfayu
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
** ����: lfy_normal_init
** ����: ��ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
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
** ����: lfy_event_handler
** ����: ϵͳ�¼���Ӧ
** ����: �¼�֪ͨ��ַ
** ����: ������
** ����: LeiFaYu
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
