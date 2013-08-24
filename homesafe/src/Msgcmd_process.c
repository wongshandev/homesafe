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
#include "mma_struct.h"
#include "ucsrv.h"
#include "nwusabsrvgprot.h"
#include "as2l4c_struct.h"
#include "Eint.h"
#include "lcd_sw_inc.h"
#include "usbsrvgprot.h"
#include "verno.h"
#if defined(__ACCDET_SUPPORT__) || defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
#include "drv_hisr.h"
#include "accdet_hw.h"
#include "accdet_sw.h"
#endif
#if defined(__MSGCMD_DTMF__)
#include "./../inc/msgcmd_dtmf.h"
#endif


extern MMI_BOOL hf_admin_is_null(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_protocol_event_handler
 * DESCRIPTION
 *  This is used to get protocal event handler(only support MSG_ID_MMI_EQ_KEYPAD_DETECT_IND)
 * PARAMETERS
 *  eventID     :[IN] event ID
 *  funcPtr     :[IN] protocol event handler of eventID
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_get_protocol_event_handler(U16 eventID, PsFuncPtr* pFuncPtr);

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
** ����: MsgCmd_isink
** ����: ����LCD���⿪��
** ���: open -- ����
** ����: ��
** ����: wasfayu
*******/
extern void MsgCmd_isink(kal_bool open);

/*******************************************************************************
** ����: msgcmd_GetGciInfoRsp
** ����: ��ȡ��վ��Ϣ�Ļص�����
** ���: msg_ptr -- l4c_nbr_cell_info_reg_cnf_struct
** ����: ��
** �ο�: vs_misc_cell_id_001 / vm_sal_stub_cell_reg_req
** ����: LeiFaYu
*******/
static void msgcmd_GetGciInfoRsp(void * msg_ptr);

#if defined(WIN32)
extern void MsgCmd_ModisCreateJPEG(WCHAR *filepath);
extern void MsgCmd_ModisCreateAVI(WCHAR *filepath);
extern void MsgCmd_ModisCreateWAV(WCHAR *filepath);
#endif

#if defined(__GET_LOCATION_INFO__)
static global_cell_id_struct msgcmd_gci_info;
#endif

#if 1
/*******************************************************************************
** ����: lfy_write_log
** ����: ��־��ӡ����, д�뵽���̵��ļ���
** ����: fmt -- ��ӡ��ʽ�����ַ���
** ����: ʵ��д������ݳ����ֽ�
** ����: wasfayu
*******/
U32 lfy_write_log(const char *fmt, ...)
{
#define LFY_LOG_BUFFER_SZ        512 //BYTE
#if defined(WIN32)
#define LFY_LOG_FILE_LIMITED     1024  //KB
#else
#define LFY_LOG_FILE_LIMITED     100  //KB
#endif

    static U32 logCount = 0;
    static FS_HANDLE logFH = -1;
    static WCHAR logFile[] = {L"C:\\lfy_log.txt"};
    
    U32 length, written = 0;
    char buffer[LFY_LOG_BUFFER_SZ] = {0};
    va_list list;

#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
        return 0;
#endif

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
                //���̿ռ䲻����, ��Ҫ��־��back�ļ���
                if ((MsgCmd_GetDiskFreeSize((S32)logFile[0])>>10) <= ((LFY_LOG_FILE_LIMITED*3)>>1))
                {
                    FS_Rename(logFile, backup);
                }
                    
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

        if (0 == logCount)
        {
            #define splitStr "\r\n==NEW LOG==>>"##BUILD_DATE_TIME_STR##"<<==\r\n"
            FS_Write(logFH, (void*)splitStr, strlen(splitStr), &written);
			#undef splitStr
        }
        
        applib_dt_get_rtc_time(&t);
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
#define mc_trace(fmt, ...) do{lfy_write_log(fmt, ##__VA_ARGS__); kal_prompt_trace(MOD_NIL, fmt, ##__VA_ARGS__);}while(0)

#else
U32 lfy_write_log(const char *fmt, ...)
{
    return 0;//do nothing.
}
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
** ����: MsgCmd_GetCallCount
** ����: ��ȡ�绰����
** ����: ��
** ����: ���ص绰����
** ����: wasfayu
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
** ����: MsgCmd_GetCallCountEx
** ����: ��ȡ����/����ĵ绰����
** ����: ����/����
** ����: ���ص绰����
** ����: wasfayu
*******/
S32 MsgCmd_GetCallCountEx(MMI_BOOL out)
{
	srv_ucm_call_state_enum state = SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE;

	if (out)
		state |= SRV_UCM_OUTGOING_STATE;
	else
		state |= SRV_UCM_INCOMING_STATE;
	
	return srv_ucm_query_call_count(state, SRV_UCM_CALL_TYPE_ALL, NULL);
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
	MMI_BOOL exist;
    
    if (MMI_FALSE == (exist = srv_fmgr_drv_is_accessible(SRV_FMGR_CARD_DRV)))
    {
    	mc_trace("%s, not detected T-card.", __FUNCTION__);
    }
    
	return exist;
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
** ����: MsgCmd_GetTFcardDrive
** ����: �ж�T���Ƿ���ڲ�����T�����̷�
** ����: litter -- ����̷�
** ����: ���ڻ��߲�����
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_GetTFcardDrive(S32 *litter)
{
    S32 drive = SRV_FMGR_CARD_DRV;

    if (litter)
        *litter = SRV_FMGR_CARD_DRV;

    return srv_fmgr_drv_is_accessible(drive);
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
            "%04d-%02d-%02d %02d%02d-%08X%w",
    		mt.nYear,
    		mt.nMonth,
    		mt.nDay,
    		mt.nHour,
    		mt.nMin,
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
** ����: MsgCmd_GetDefinedSim
** ����: ��ȡ�豸ʹ�õ�SIM��ID
** ����: ��
** ����: mmi_sim_enum
** ����: wasfayu
*******/
mmi_sim_enum MsgCmd_GetDefinedSim(void)
{
	return MMI_SIM2;
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
** ����: MsgCmd_Reboot
** ����: ����
** ���: 
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_Reboot(void)
{
    srv_alm_pwr_reset(MMI_TRUE, 1);
}

/*******************************************************************************
** ����: MsgCmd_RebootAcitved
** ����: �ж���ʱ�����Ķ�ʱ���Ƿ��Ѿ�����
** ���: ��
** ����: ��ʱ���Ƿ��Ѽ���
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_RebootAcitved(void)
{
	return IsMyTimerExist(MSGCMD_TIMER_REBOOT);
}

/*******************************************************************************
** ����: MsgCmd_RebootExt
** ����: ��ʱ����
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_ShutdownAcitved
** ����: �ж���ʱ�ػ��Ķ�ʱ���Ƿ��Ѿ�����
** ���: ��
** ����: ��ʱ���Ƿ��Ѽ���
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_ShutdownAcitved(void)
{
	return IsMyTimerExist(MSGCMD_TIMER_SHUTDOWN);
}

/*******************************************************************************
** ����: MsgCmd_ShutdownExt
** ����: ��ʱ�ػ�
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_DeleteFileFront
** ����: ɾ���ļ���ǰ��
** ���: fname   -- �ļ���, UCS��ʽ, �� L"E:\\videos\\test.avi"
**       deletesz -- ɾ����С, �����ļ�ͷ��ʼɾ��deletesz���ֽڵ�����
** ����: ����ִ���Ƿ�����
** ����: wasfayu
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
            
        //��λ������λ��
        if(FS_Seek(fd, deletesz, FS_FILE_BEGIN) < 0)
            return MMI_FALSE;   

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
** ����: msgcmd_WriteImeiRsp
** ����: ����ָ������
** ����: pnumber -- ָ�����к���
** ����: ��
** ����: wasfayu
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

	if (MsgCmd_AdoRecdBusy())
		MsgCmd_AdoRecdStop(NULL);
	if (MsgCmd_VdoRecdBusy())
		MsgCmd_VdoRecdStop(NULL);

	MakeCall(Hotline_number);
#else
    if (!mmi_bootup_is_network_service_available() || !srv_mode_switch_is_network_service_available())
    {
        mc_trace("%s, network not available. number=%s.", __FUNCTION__, pnumber);
        return;
    }

	if (MsgCmd_AdoRecdBusy())
		MsgCmd_AdoRecdStop(NULL);
	if (MsgCmd_VdoRecdBusy())
		MsgCmd_VdoRecdStop(NULL);

    mc_trace("%s, number=%s.", __FUNCTION__, pnumber);
	mmi_ucm_init_call_para_for_sendkey(&param); 
	
	if (MMI_SIM1 == MsgCmd_GetDefinedSim())
		param.dial_type = SRV_UCM_SIM1_CALL_TYPE_ALL;
	else if (MMI_SIM2 == MsgCmd_GetDefinedSim())
		param.dial_type = SRV_UCM_SIM2_CALL_TYPE_ALL;
	else
		ASSERT(0);
	
	param.ucs2_num_uri = (U16 *)Hotline_number;
    mmi_ucm_call_launch(0, &param);
#endif
}

/*******************************************************************************
** ����: msgcmd_WriteImeiRsp
** ����: дIMEI�Ľ����Ӧ����
** ����:
** ����: д�Ľ����ο� nvram_errno_enum ���ö��.
** ����: wasfayu
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
MMI_BOOL MsgCmd_WriteImei(char *num, U16 strl, U8 sim, U8 (*rsp)(void*))
{
#if defined(WIN32)
    return MMI_FALSE;
#else
    U8 i;
    char ibuf[SRV_IMEI_MAX_LEN+2] = {0};
    module_type src = MOD_MMI;//stack_get_active_module_id();//ֻ����MOD_MMI
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
** ����: MsgCmd_CreatePath
** ����: ����һ����ȵ�·��
** ����: drive   -- �̷�
**       folder  -- �ļ�������
** ����: �Ƿ񴴽��ɹ�
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_CreatePath(S32 drive, const WCHAR *folder)
{
    FS_HANDLE h;
    WCHAR buffer[MSGCMD_FILE_PATH_LENGTH+1] = {0};

    if (!isalpha(drive) || 
        !srv_fmgr_drv_is_accessible(drive) ||
        NULL == folder)
        return MMI_FALSE;
    
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

/*******************************************************************************
** ����: MsgCmd_CreateMultiPath
** ����: ����·��, �����Ƕ���·��
** ����: dirve     -- �̷�
**       UcsFolder -- �ļ���
** ����: ��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_CreateMultiPath(char drive, const WCHAR *UcsFolder)
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
** ����: MsgCmd_IsSimUsable
** ����: �ж�SIM���Ƿ����ʹ��, ����SIM����ȡ������У�鶼ͨ���˲������ʹ��.
** ����: sim  -- SIM������
** ����: �Ƿ����ʹ��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsSimUsable(mmi_sim_enum sim)
{
	MMI_BOOL exist;
	
	if (MMI_FALSE == (exist = srv_sim_ctrl_is_available(sim)))
    {   
	    mc_trace("%s, sim=0x%x. not detected.", __FUNCTION__, sim);
    }
    
	return exist;
}

#if 1
extern const unsigned char AUX_EINT_NO;
extern void hf_task_sent_hisr(BOOL level);

#define MC_EINT_NO         AUX_EINT_NO
#define MSGCMD_INTERRUPT_DIFF_LEVEL  0 //�͵�ƽ�����ⲿ�ж�

/*******************************************************************************
** ����: msgcmd_InterruptRespond
** ����: �ⲿ�ж���Ӧ����
** ����: ��
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_InterruptRespond(void *p)
{
	MsgCmdExtIntReq *rsp = (MsgCmdExtIntReq*)p;

	mc_trace("%s, level=%d.", __FUNCTION__, rsp->level);

#if defined(__VDORECD_VERSION_FEATRUE__)
	if (!rsp->level)
	{
		//�͵�ƽ�����ж�, Ȼ������֮
		MsgCmd_InterruptMask(MMI_TRUE, __FILE__, __LINE__);
	}
#endif

	//����Ϣ��hf_mmi_task_process() ͳһ������Ӧ����ϢID����HF_MSG_ID_ADO����HF_MSG_ID_VDO		
	hf_task_sent_hisr(rsp->level);
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
** ����: MsgCmd_InterruptMask
** ����: ����/���ⲿ�ж�
** ����: mask  -- ����
**       file  -- ����ʱ��ӡ���ļ���
**       line  -- ����ʱ��ӡ���к�
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_InterruptMask(MMI_BOOL mask, char *file, U32 line)
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
	
		mc_trace("interrupt masked by %s,L:%d",file, line);
    }
    else
    {
    	// T�������ڻ���SIM�������޳�������, ��ֹ�����ж�
    	if (!MsgCmd_IsSdCardExist() || hf_admin_is_null())
			return;

		//��ؽ�ֹ
		if (hf_monitor_disabled())
			return;

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
		mc_trace("interrupt opened by %s,L:%d",file, line);
    }
}

/*******************************************************************************
** ����: msgcmd_InterruptLISR
** ����: �����жϵ���Ӧ����, ������Ǽ���ACCDET�ж�
** ����: void
** ����: ��
** ����: wasfayu
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
** ����: MsgCmd_InterruptRegister
** ����: �ⲿ�ж�ע��, �����ڶ������ʼ����ʱ���ע��, 
**       �������EINT_LISR����"ASSERT(EINT_FUNC[index].eint_func!=NULL);"
** ����: void
** ����: ��
** ����: wasfayu
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

    //�ʼ������״̬, ����ʼ��֮���ٴ�
    EINT_Mask(MC_EINT_NO);
#endif
}

#endif

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
** ʾ��: 
**       WCHAR *text = L"Hello!";
**       MsgCmd_SendSms(
**           "13760106789", 
**           text, 
**           app_ucs2_strlen(text)*sizeof(WCHAR), 
**           NULL, 
**           SRV_SMS_SIM_1, 
**           NULL);
** ����: wasfayu
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

/*******************************************************************************
** ����: msgcmd_DeleteSMSFolderCb
** ����: ɾ��SMS�ļ��еĻص�����
** ���: type     -- �ļ�������
**       sim      -- SIM��
**       callback -- �ص�����
**       usd      -- �û�����
** ����: ������, srv_um_result_enum
** ����: wasfayu
*******/
static S32 msgcmd_DeleteSMSFolderCb(S32 pid, srv_um_delete_folder_result* rsp, S32 user_data)
{
	mc_trace("%s, error=%d.", __FUNCTION__, rsp->error);
	return SRV_UM_RESULT_OK;
}

/*******************************************************************************
** ����: MsgCmd_DeleteSMSFolder
** ����: ɾ��SMS�ļ���
** ���: type     -- �ļ�������
**       sim      -- SIM��
**       callback -- �ص�����
**       usd      -- �û�����
** ����: ������, srv_um_result_enum
** ����: wasfayu
*******/
S32 MsgCmd_DeleteSMSFolder(
    srv_um_msg_box_enum type, 
    srv_um_sim_enum sim, 
    srv_um_delete_folder_cb callback,
    void *usd)
{
    S32 result;
    srv_um_box_identity_struct msg_box;

	msg_box.msg_box_type = type;
	msg_box.msg_type = SRV_UM_MSG_ALL;
	msg_box.sim_id = sim;
	
    result = srv_um_delete_folder(
		msg_box, 
		callback ? callback : msgcmd_DeleteSMSFolderCb, 
		(S32)usd);

    mc_trace("%s, type=0x%x, result=%d.",__FUNCTION__,type,result);
    return result;
} 

/*******************************************************************************
** ����: msgcmd_CleanSmsBoxCb
** ����: ɾ��SMS�ļ��еĻص�����
** ���: cb -- srv_sms_callback_struct
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_CleanSmsBoxCb(srv_sms_callback_struct *cb)
{
	mc_trace("%s, result=%d.", __FUNCTION__, cb->result);
}

/*******************************************************************************
** ����: MsgCmd_CleanSmsBox
** ����: ɾ��SMS�ļ���
** ���: msg_box_type -- ��������
**       sim          -- SIM������
**       usd          -- �û�����
** ����: ��
** �ο�: vs_appser_sms_cb_001
** ����: wasfayu
*******/
void MsgCmd_CleanSmsBox(srv_sms_box_enum msg_box_type, srv_sms_sim_enum sim, void *usd)
{
	srv_sms_delete_msg_list(
            msg_box_type,
            sim,
            msgcmd_CleanSmsBoxCb,
            NULL);
}

/*******************************************************************************
** ����: MsgCmd_GetSmsBoxCount
** ����: ��ȡSMS�����������Ϣ����
** ���: msg_box_type -- ��������
** ����: ����
** ����: wasfayu
*******/
U16 MsgCmd_GetSmsBoxCount(srv_sms_box_enum msg_box_type)
{
	return srv_sms_get_list_size(msg_box_type);
}

/*******************************************************************************
** ����: MsgCmd_GetUnreadSmsCount
** ����: ��ȡSMS���������δ����Ϣ����
** ���: ��
** ����: δ����Ϣ����
** ����: wasfayu
*******/
U16 MsgCmd_GetUnreadSmsCount(void)
{
	return srv_sms_get_unread_sms_num();
}


#if 1//MMS
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
** ����: msgcmd_SendMMSRequestResponse
** ����: �������ҷ���MMS�Ļص�����
** ���: result   -- 
**       rsp_data -- srv_mms_create_rsp_struct
**       user_data-- 
** ����: �Ƿ�ɹ�
** ����: wasfayu
*******/
static void msgcmd_SendMMSRequestResponse(void *param)
{
    MsgCmdMMSReq     *rsp = (MsgCmdMMSReq*)param;
    MsgCmdMMSXmlData *xml;

	if (!MsgCmd_IsSimUsable(rsp->sim))
	{
		mc_trace("%s, SIM NOT USABLE.", __FUNCTION__);
		return;
	}

	xml = (MsgCmdMMSXmlData*)MsgCmd_Malloc(sizeof(MsgCmdMMSXmlData), 0);
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
    else
    {
    	mc_trace("%s, sim=0x%x. sendto=\"%s\".",__FUNCTION__,rsp->sim,rsp->sendto);
    }

    MsgCmd_Mfree(xml);
}

/*******************************************************************************
** ����: msgcmd_SendMMSResultRespond
** ����: ����MMS�Ľ��֪ͨ
** ���: p   -- wap_mma_send_rsp_struct
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_SendMMSResultRespond(void *p)
{
    wap_mma_send_rsp_struct *rsp = (wap_mma_send_rsp_struct*)p;

    mc_trace("%s, result=%d, msg_id=%d.",__FUNCTION__, rsp->result, rsp->msg_id);
}

/*******************************************************************************
** ����: msgcmd_MMSBgSendRstEvtCb
** ����: ��̨����MMS�Ľ���¼�֪ͨ����
** ���: p   -- mmi_event_struct
** ����: ��
** ����: wasfayu
*******/
static mmi_ret msgcmd_MMSBgSendRstEvtCb(mmi_event_struct *p)
{
    srv_mms_bgsr_result_struct *rst = (srv_mms_bgsr_result_struct*)p;

    mc_trace("%s, result=%d.", rst->result);
    return MMI_RET_OK;   
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
		if (MsgCmd_IsSdCardExist())
			req.storage_type = MMA_MSG_STORAGE_CARD1;
		else
			req.storage_type = MMA_MSG_STORAGE_PHONE;
		req.is_rr        = MMI_TRUE;
		srv_mms_send(&req);
	}

    FS_Delete(usd->xmlpath);
    MsgCmd_Mfree(usd);
        
	mc_trace("%s, result=%d, msg_id=%d. rsp->result=%d. usd->sim=0x%x.",
		__FUNCTION__, result, rsp->msg_id, rsp->result,usd->sim);
}

/*******************************************************************************
** ����: MsgCmd_CreateAndSendMMS
** ����: �������ҷ���MMS
** ���: xml_path  -- MMS�����ļ�, �����Ѿ������е绰������Щ��
**       sim       -- mma_sim_id_enum
** ����: ����ִ�д�����
** ����: wasfayu
*******/
MCErrCode MsgCmd_CreateAndSendMMS(
    mma_sim_id_enum sim,
    WCHAR          *xml_path)
{
	MCErrCode error;

	do {
	    if (!mms_is_ready())
		{
			error = MC_ERR_MMS_NOT_READY;
			break;
    	}
		
		if (!srv_nw_usab_is_any_network_available())
		{
			error = MC_ERR_NW_NOT_AVALIABLE;
			break;
		}
		
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
	        
	        error = (SRV_MMS_RESULT_OK == srv_mms_create(&createReq) ? MC_ERR_NONE : MC_ERR_UNKOWN);
	    }
	}while(0);
	
	mc_trace("%s, error=%d. sim=0x%x.", __FUNCTION__, error, sim);
	
    return error;
}

/*******************************************************************************
** ����: MsgCmd_DeleteMMSFolder
** ����: ɾ�������ļ��еĻص�����
** ���: xml_path  -- MMS�����ļ�, �����Ѿ������е绰������Щ��
**       sim       -- mma_sim_id_enum
** ����: ����ִ�д�����
** ����: wasfayu
*******/
void MsgCmd_DeleteMMSFolderCb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
	mc_trace("%s, error=%d.", __FUNCTION__, result);
}

/*******************************************************************************
** ����: MsgCmd_DeleteMMSFolder
** ����: ɾ�������ļ���
** ���: folder -- �ļ�������
**       usd    -- �û�����, �ڻص��������潫��ʹ��
**       callback  -- �ص�����, ���Ϊ�������Ĭ�ϵĻص�����
** ����: ������
** ����: wasfayu
*******/
S32 MsgCmd_DeleteMMSFolder(
	srv_um_msg_box_enum folder,
	void *usd,
	void (*callback)(srv_mms_result_enum, void *, S32))
{
    S32 result;
	srv_mms_delete_folder_req_struct req;
	
	req.app_id = MMA_APP_ID_MMS_APP;
	req.call_back = callback ? callback : MsgCmd_DeleteMMSFolderCb;
	//srv_mms_convert_mma_folder_to_umbox_type(MMA_FOLDER_DRAFT);
	req.msg_box_type = folder;
	req.msg_type = SRV_UM_MSG_MMS;
	req.user_data = (S32)usd;
	result = srv_mms_delete_folder(&req);

	//mc_trace("%s, folder=%d. result=%d.", __FUNCTION__, folder, result);
    return result;
}

/*******************************************************************************
** ����: MsgCmd_GetMMSCounterCb
** ����: ��ȡ����ָ�����͵������Ļص�����
** ���: result   -- �ļ�������
**       rsp_data -- �ص��������������
**       usr_data -- �û�����, �ڻص��������潫��ʹ��
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_GetMMSCounterCb(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
	srv_mms_get_msg_num_rsp_struct *rsp= (srv_mms_get_msg_num_rsp_struct*) rsp_data;
	GetMMSCounterParam *param = (GetMMSCounterParam*)user_data;
	U32 total;
	
	for (total=0; param->count>0; param->count--)
		total += rsp->rsp_tb[param->count-1];
	
	
	if (total > 0 && param->clean)
	{
    	mc_trace("%s, result=%d. total=%d, clean=%d.", __FUNCTION__, result, total, param->clean);
		MsgCmd_DeleteMMSFolder(SRV_UM_MSG_BOX_ALL, NULL, NULL);
	}
}

/*******************************************************************************
** ����: MsgCmd_GetMMSCounter
** ����: ��ȡ����ָ�����͵�����
** ���: reqTab -- ָ������
**       tabCt  -- ����������
**       callback  -- �ص�����, ���Ϊ�������Ĭ�ϵĻص�����
**       usd       -- �Ƿ�����������������
** ����: ������, srv_mms_result_enum
** ����: wasfayu
*******/
S32 MsgCmd_GetMMSCounter(
	mma_query_option_enum reqTab[], 
	U32 tabCt, 
	void *usd,
	void (*callback)(srv_mms_result_enum, void *, S32))
{
	S32 error;
	srv_mms_get_msg_num_req_struct param_mms; 
	
	if (tabCt == 0 || NULL == reqTab)
		return SRV_MMS_RESULT_INVALID_PARA;

	if (tabCt >= MMA_MAX_MSG_NUM_QUERY_NUM)
		tabCt = MMA_MAX_MSG_NUM_QUERY_NUM - 1;
	
	param_mms.app_id = MMA_APP_ID_MMS_APP;
	param_mms.call_back = callback ? callback : MsgCmd_GetMMSCounterCb;
	for ( ; tabCt>0; tabCt--)
	{
		param_mms.req_tb[tabCt-1] = reqTab[tabCt-1];
	}
	param_mms.user_data = (S32)usd;
	
	error = srv_mms_get_msg_num(&param_mms);
	//mc_trace("%s, tabCt=%d. error=%d.", __FUNCTION__, tabCt, error);

	return error;
}
#endif

/*******************************************************************************
** ����: msgcmd_DeleteOldFile
** ����: �����ļ��б��еļ�¼ɾ���ļ�
** ���: filepath   -- �ļ��ľ���·����, UCS��ʽ, �� L"E:\\videos\\test.avi"
**       cmpSzKB    -- ��Ҫɾ�����ܴ�С, ��KBΪ��λ
** ����: ����ִ���Ƿ�����
** ����: wasfayu
*******/
static S32 msgcmd_DeleteOldFile(const WCHAR *filepath, U32 cmpSzKB)
{
    U32       bufsz;
    WCHAR    *buffer;
    U32       line_len, tmpSz=0;
    U32       total_size = 0;
    S32       ret = 0;
    FS_HANDLE main_fd, fd;

    if (NULL == filepath)
        return 0;
	    
    main_fd = FS_Open(filepath, FS_READ_ONLY);
    if(main_fd < FS_NO_ERROR)
	    return 0;

    bufsz  = MSGCMD_FILE_PATH_LENGTH * sizeof(WCHAR);
	buffer = (WCHAR*)MsgCmd_Malloc(bufsz + sizeof(WCHAR), 0);
    
	FS_Seek(main_fd, 0, FS_FILE_BEGIN);
    do{
        U32 fsz;
        
        memset(buffer, 0, bufsz);
		line_len = 0;
        applib_file_read_line(main_fd, (U8 *)buffer, bufsz, &line_len, &ret);

        if(ret < FS_NO_ERROR)
            break;
        
		if (line_len == 0 || line_len == 1)
			break;
		        
        tmpSz += line_len;
        
        //ȥ��β���ϵĻس����з�
        line_len = app_ucs2_strlen((const S8 *)buffer);
        while(line_len)
        {
            if (buffer[line_len-1] == (WCHAR)'\r' || 
                buffer[line_len-1] == (WCHAR)'\n' ||
                buffer[line_len-1] == (WCHAR)('\r'<<8|'\n') ||
                buffer[line_len-1] == (WCHAR)('\n'<<8|'\r'))
                buffer[line_len-1] = (WCHAR)'\0';
            else
                break;
            
            line_len --;
        }        
        
        fd = FS_Open((WCHAR*)buffer, FS_READ_ONLY);
        if(fd >= FS_NO_ERROR)
        {
            if(FS_GetFileSize(fd, &fsz) >= FS_NO_ERROR)
                total_size += fsz>>10;
                
            FS_Close(fd);
            FS_Delete((const WCHAR*)buffer);
            
            mc_trace("%s,L:%d, total_size=%d.", __FUNCTION__, __LINE__, total_size);
        }

        if(total_size >= cmpSzKB)
            ret = 1;

        
    }while(ret == 0);

	FS_Close(main_fd);
	MsgCmd_Mfree(buffer);


    MsgCmd_DeleteFileFront(filepath, tmpSz);
    
    return ret;
}

/*******************************************************************************
** ����: msgcmd_RecordFileName
** ����: ��ĳ���ļ���UCS��ʽ����pdataд�뵽fname�ļ���ȥ
** ���: fpath   -- �ļ�����·����, UCS��ʽ, �� L"D:\\Videos\\video.lst"
**       wfname  -- ��д�������
**       nlen    -- ��д������ݳ���, �ֽ�Ϊ��λ
** ����: �Ƿ�д��ɹ�
** ����: wasfayu
*******/
static MMI_BOOL msgcmd_RecordFileName(const WCHAR *fpath, const WCHAR *wfname, U32 nlen)
{
    MMI_BOOL  result = MMI_FALSE;
    FS_HANDLE fd;

    if (NULL == fpath || NULL == wfname || 0 == nlen)
        return MMI_FALSE;
    
    fd = FS_Open(fpath, FS_READ_WRITE|FS_CREATE);    
    if(fd >= FS_NO_ERROR)
    {
        FS_Seek(fd, 0, FS_FILE_END);
        FS_Write(fd, (void*)wfname, nlen, NULL);
        FS_Write(fd, "\r\n", 2, NULL);
        FS_Commit(fd);
        FS_Close(fd);
        result = MMI_TRUE;
    }
    
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
** ����: msgcmd_NetworkAttachedEventHdlr
** ����: ��������¼��������
** ˵��: �������ڴ��ж��Ƿ����������, Ȼ������ϵͳ.
** �ο�: [1] DmSelfRegister.c, mmi_dm_sr_nw_availability_changed_notify
** ����: LeiFaYu
*******/
static mmi_ret msgcmd_NetworkAttachedEventHdlr(mmi_event_struct *evt)
{
    srv_nw_info_service_availability_changed_evt_struct *pevt;
    
    pevt = (srv_nw_info_service_availability_changed_evt_struct*)evt;	

#if defined(__GET_LOCATION_INFO__)
    MsgCmd_GciInfoEvtProcSetOrClr(MMI_TRUE);
#endif

    switch (pevt->new_status)
    {
    case SRV_NW_INFO_SA_FULL_SERVICE:
        mc_trace("network attached!");
	#if defined(__VDORECD_VERSION_FEATRUE__)
		//��ЧSIM�����, �����������Ϊ����T����������Ӧ�ж�
		if (MsgCmd_IsSdCardExist())
			MsgCmd_InterruptMask(MMI_FALSE, __FILE__, __LINE__);
		else
			MsgCmd_InterruptMask(MMI_TRUE, __FILE__, __LINE__);
	#endif
	
        //����Ŀֻ��һ��SIM��, ����ע�������
        //mmi_frm_cb_dereg_event( \
        //    EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED, \
        //    msgcmd_NetworkAttachedEventHdlr, \
        //    NULL);
        
        break;
    case SRV_NW_INFO_SA_NO_SERVICE:
        mc_trace("network no service!");
	#if defined(__VDORECD_VERSION_FEATRUE__)
		MsgCmd_InterruptMask(MMI_FALSE, __FILE__, __LINE__);
	#endif
        break;
    case SRV_NW_INFO_SA_LIMITED_SERVICE:
        mc_trace("network limited service!");
	#if defined(__VDORECD_VERSION_FEATRUE__)
		MsgCmd_InterruptMask(MMI_FALSE, __FILE__, __LINE__);
	#endif
        break;
        
    case SRV_NW_INFO_SA_SEARCHING:
    default:
        break;
    }

    return MMI_RET_OK;
}

#if defined(__GET_LOCATION_INFO__)
/*******************************************************************************
** ����: msgcmd_GetGciInfoRsp
** ����: ��ȡ��վ��Ϣ�Ļص�����
** ���: msg_ptr -- l4c_nbr_cell_info_reg_cnf_struct
** ����: ��
** �ο�: vs_misc_cell_id_001 / vm_sal_stub_cell_reg_req
** ����: LeiFaYu
*******/
static void msgcmd_GetGciInfoRsp(void * msg_ptr)
{
	static U32 count = 0;
    l4c_nbr_cell_info_reg_cnf_struct *info = \
        (l4c_nbr_cell_info_reg_cnf_struct *)msg_ptr;
	
    if (info->is_nbr_info_valid)
    {
    	if (count++%60 == 0)
		{
			mc_trace("%s, mnc=%d.mcc=%d.lac=%d.ci=%d. ",
				__FUNCTION__,
				info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.mnc,
				info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.mcc,
		        info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.lac,
				info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.ci);
		}
		
		memcpy(&msgcmd_gci_info, 
			&info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci, 
			sizeof(global_cell_id_struct));
    }
	else
	{
		memset(&msgcmd_gci_info, 0, sizeof(global_cell_id_struct));
	}
}

/*******************************************************************************
** ����: MsgCmd_GciInfoEvtProcSetOrClr
** ����: ע�ỹ��ע��
** ���: reg -- ע�ỹ��ע��
** ����: ��
** ����: LeiFaYu
*******/
void MsgCmd_GciInfoEvtProcSetOrClr(MMI_BOOL reg)
{
	ilm_struct *ilm_ptr = NULL;

	ilm_ptr = allocate_ilm(MOD_MMI);
	ilm_ptr->src_mod_id  = MOD_MMI;
    ilm_ptr->dest_mod_id = (MMI_SIM2==MsgCmd_GetDefinedSim()) ? MOD_L4C_2 : MOD_L4C;
    ilm_ptr->sap_id = MMI_L4C_SAP;
    ilm_ptr->local_para_ptr = (local_para_struct *) NULL;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct *) NULL;
	
	if (reg)
	{
		mmi_frm_set_protocol_event_handler(
			MSG_ID_L4C_NBR_CELL_INFO_REG_CNF, 
			(PsIntFuncPtr)msgcmd_GetGciInfoRsp, 
			MMI_FALSE);
	    mmi_frm_set_protocol_event_handler(
			MSG_ID_L4C_NBR_CELL_INFO_IND, 
			(PsIntFuncPtr)msgcmd_GetGciInfoRsp,
			MMI_FALSE);
		
		ilm_ptr->msg_id = MSG_ID_L4C_NBR_CELL_INFO_REG_REQ;
	}
	else
	{
		mmi_frm_clear_protocol_event_handler(
			MSG_ID_L4C_NBR_CELL_INFO_IND, 
			(PsIntFuncPtr)msgcmd_GetGciInfoRsp);
		mmi_frm_clear_protocol_event_handler(
			MSG_ID_L4C_NBR_CELL_INFO_REG_CNF, 
			(PsIntFuncPtr)msgcmd_GetGciInfoRsp);

		ilm_ptr->msg_id = MSG_ID_L4C_NBR_CELL_INFO_DEREG_REQ;
	}

	msg_send_ext_queue(ilm_ptr);
}
#endif

/*******************************************************************************
** ����: MsgCmd_EvtProcEntry
** ����: ��Ӧϵͳ�¼�
** ����: evp -- �¼�֪ͨ���ݵ�ַ
** ����: �¼�������
** ����: wasfayu
*******/
mmi_ret MsgCmd_EvtProcEntry(mmi_event_struct *evp)
{
    mmi_ret ret = MMI_RET_OK;

    MMI_ASSERT(evp);

    switch (evp->evt_id)
    {
    case EVT_ID_SRV_NW_INFO_LOCATION_CHANGED:
		{
			srv_nw_info_location_changed_evt_struct *inp = \
				(srv_nw_info_location_changed_evt_struct*)evp;
						
			mc_trace("%s, L:%d. plmn=%s,lac=%d,ci=%d.",
				__FUNCTION__,__LINE__,
				inp->new_location.plmn,
				inp->new_location.lac,
				inp->new_location.cell_id);
		}
		break;
		
    case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
        MsgCmd_ProcessInit();
        break;
		
    case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
		//mc_trace("%s, L:%d, id=%d. EVT_ID_SRV_BOOTUP_BEFORE_IDLE", __FUNCTION__, __LINE__, evp->evt_id);
        break;
	
    case EVT_ID_SRV_BOOTUP_COMPLETED:
    #if defined(__GET_LOCATION_INFO__)
		MsgCmd_GciInfoEvtProcSetOrClr(MMI_TRUE);
	#endif
        break;
    case EVT_ID_SRV_BOOTUP_EARLY_INIT:
        hf_main_init();
        mmi_frm_cb_reg_event(\
            EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED, \
            msgcmd_NetworkAttachedEventHdlr, \
            NULL);
        break;
		
    case EVT_ID_IDLE_ENTER:
		//mc_trace("%s, L:%d, id=%d. EVT_ID_IDLE_ENTER", __FUNCTION__, __LINE__, evp->evt_id);
		break;
    case EVT_ID_IDLE_LAUNCHED:
		//mc_trace("%s, L:%d, id=%d. EVT_ID_IDLE_LAUNCHED", __FUNCTION__, __LINE__, evp->evt_id);
	#if defined(__VDORECD_VERSION_FEATRUE__)
		/* �ж������¼�������У�����Ӧ��
			1����T����
			2����ЧSIM������δ�󶨺��룻
			�Ѿ���T�����жϺ��Ƿ�󶨺����Ū���ж����κ�������ȥ��, ����ֻ�ж�SIM���Ƿ���Ч.
			�����ж�SIM���Ƿ���Ч, �����Ч���������ж�, �����Ч�Ϳ�����������������Ƿ���ж�.
		*/
		if (!MsgCmd_IsSimUsable(MsgCmd_GetDefinedSim()))
			MsgCmd_InterruptMask(MMI_FALSE, __FILE__, __LINE__);
	#else
		MsgCmd_InterruptMask(MMI_FALSE, __FILE__, __LINE__);
	#endif
		break;

    case EVT_ID_IDLE_EXIT:
        //mc_trace("%s, L:%d, id=%d. EVT_ID_IDLE_EXIT", __FUNCTION__, __LINE__, evp->evt_id);
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
        mc_trace("%s, L:%d, id=%d. SMS BOX full. clean BOX.", __FUNCTION__, __LINE__, evp->evt_id);
		MsgCmd_DeleteSMSFolder(SRV_UM_MSG_BOX_ALL, SRV_UM_SIM_ALL, NULL, NULL);
        break;
    case EVT_ID_SRV_SMS_READY:
        {
            U32 count = 0;
            count += MsgCmd_GetSmsBoxCount(SRV_SMS_BOX_INBOX);
            count += MsgCmd_GetSmsBoxCount(SRV_SMS_BOX_OUTBOX);
            count += MsgCmd_GetSmsBoxCount(SRV_SMS_BOX_DRAFTS);
        #ifdef __SRV_SMS_UNSENT_LIST__
            count += MsgCmd_GetSmsBoxCount(SRV_SMS_BOX_UNSENT);
            if (count)
                MsgCmd_CleanSmsBox(SRV_SMS_BOX_UNSENT, SRV_SMS_SIM_2, NULL);
        #endif
        #ifdef __SRV_SMS_SIMBOX_SUPPORT__
            count += MsgCmd_GetSmsBoxCount(SRV_SMS_BOX_SIM);
        #endif
        #ifdef __SRV_SMS_ARCHIVE__
            count += MsgCmd_GetSmsBoxCount(SRV_SMS_BOX_ARCHIVE);
        #endif            

            // ���е�SMS�����ܺͷ����ִ��ɾ������
    		if (count > 0)
    		{
    			mc_trace("%s, L:%d, id=%d. SMS is ready. clean BOX.", __FUNCTION__, __LINE__, evp->evt_id);
    			MsgCmd_DeleteSMSFolder(
    				SRV_UM_MSG_BOX_ALL, 
    				SRV_UM_SIM_ALL,
    				NULL,
    				NULL);
    		}
    		else
    		{
    			mc_trace("%s, L:%d, id=%d. SMS is ready.", __FUNCTION__, __LINE__, evp->evt_id);
    		}
        }
		break;
    case EVT_ID_SRV_MMS_READY:
		{
			GetMMSCounterParam *param = (GetMMSCounterParam*)MsgCmd_Malloc(sizeof(GetMMSCounterParam), 0);
			
			param->table[param->count++] = MMA_QUERY_OPTION_NUM_TOTAL_INBOX_MSG;
			param->table[param->count++] = MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG;
			param->table[param->count++] = MMA_QUERY_OPTION_NUM_TOTAL_SENT_MSG;
			param->table[param->count++] = MMA_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG;
			param->clean = MMI_TRUE; //�����������͵������ܺʹ���0��ִ�����
			
			if (MsgCmd_GetMMSCounter(param->table, param->count, (void*)param, NULL) == SRV_MMS_RESULT_OK)
			{
				mc_trace("%s, L:%d, id=%d. MMS is ready. clean BOX.", __FUNCTION__, __LINE__, evp->evt_id);
			}
			else
			{
				mc_trace("%s, L:%d, id=%d. MMS is ready.", __FUNCTION__, __LINE__, evp->evt_id);
			}
	        mmi_frm_cb_reg_event(EVT_ID_SRV_BGSR_RESULT, msgcmd_MMSBgSendRstEvtCb , NULL);
    	}
		break;
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
** ����: msgcmd_AdoRecdCheckFreeSpace
** ����: ���ʣ��ռ�
** ����: drive  -- �̷�
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_AdoRecdCheckFreeSpace(S32 drive)
{
#if defined(WIN32)
    //ģ������ɾ��100KB
    if (app_getcurrtime() % 5 == 0)
    {
        WCHAR file[MSGCMD_FILE_PATH_LENGTH+1];

        memset(file, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
        kal_wsprintf(
            file, "%c:\\%w\\%w",
            drive, MSGCMD_AUDIOS_FOLDER_NAME, MSGCMD_ADO_LIST_FILE_NAME);
        
        msgcmd_DeleteOldFile(file, 100);
    }
    
#else

	U32 left, need;
    
    //����ʣ��ռ�С��5M��ɾ���͵�¼���ļ�
    left = MsgCmd_GetDiskFreeSize(MsgCmd_GetUsableDrive()) >> 10;
    need = MSGCMD_ADO_SIZE_PER_SEC_KB * MsgCmd_GetAdoRecdArgs()->save_gap * 2;
    
	mc_trace("%s, left=%dKB. need=%dKB.", __FUNCTION__, left, need);

	if (left <= need)
	{
	    WCHAR file[MSGCMD_FILE_PATH_LENGTH+1];

        memset(file, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
        kal_wsprintf(
            file, "%c:\\%w\\%w",
            drive, MSGCMD_AUDIOS_FOLDER_NAME, MSGCMD_ADO_LIST_FILE_NAME);
        
	    msgcmd_DeleteOldFile(file, need);
    }
#endif
}

/*******************************************************************************
** ����: msgcmd_AdoRecdDoingCb
** ����: ����¼��
** ����: result  -- ���, ������Զ������Ļ�, resultΪ0, �������Ƿ�0ֵ
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_AdoRecdDoingCb(MDI_RESULT result)
{
    if (NULL == arm)
        return;
    
    mc_trace("%s, result=%d.", __FUNCTION__, result);

#if defined(WIN32)
    if (MsgCmd_GetCurrentTime() % 5 == 0 &&
        applib_get_file_size(arm->filepath) == 0)
    {
        MsgCmd_ModisCreateWAV(arm->filepath);
    }
#endif

    //����ļ�С�����ֵ��ɾ������
    if (applib_get_file_size(arm->filepath) >= MsgCmd_GetAdoRecdArgs()->ignore_size)
    {
        WCHAR file[MSGCMD_FILE_PATH_LENGTH+1];

        memset(file, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
        kal_wsprintf(file, "E:\\%w\\%w", MSGCMD_AUDIOS_FOLDER_NAME, MSGCMD_ADO_LIST_FILE_NAME);
        file[0] = arm->filepath[0];
        
    	msgcmd_RecordFileName(
    		file,
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
            
            //�����׷��, ������һ��ʱ��, ʱ��ΪĬ�ϵı�����ʱ��
            if (arm->append)
            {
				mc_trace("%s, time=%dS, add time(%dS).", __FUNCTION__, arm->time, MsgCmd_GetAdoRecdArgs()->save_gap);
                arm->append = MMI_FALSE;
                arm->time  += MsgCmd_GetAdoRecdArgs()->save_gap;
            }

            //ʣ��ʱ��С��xx������Ե�
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
        //MsgCmd_isink(MMI_FALSE);
        MsgCmd_Mfree(arm);
        arm = NULL;
    }
}

/*******************************************************************************
** ����: msgcmd_AdoRecdDoing
** ����: ִ����ʱ¼��
** ����: filename  -- ¼�������ļ���
**       time      -- ��ʱʱ��, �뵥λ
** ����: ���������Ƿ�ɹ�
** ����: wasfayu
*******/
static MMI_BOOL msgcmd_AdoRecdDoing(WCHAR *filename, U32 time)
{
    MDI_RESULT error;

    //����ʣ��ռ�С��5M��ɾ���͵�¼���ļ�
    msgcmd_AdoRecdCheckFreeSpace((S32)filename[0]);
    
    error = mdi_audio_start_record_with_limit(
                (void*)filename,
                MEDIA_WAV_DVI_ADPCM,
                1, //0-low, >0-high
                NULL,
                msgcmd_AdoRecdDoingCb,
                0,
                time);
    mc_trace("%s, error=%d. time=%dS.", __FUNCTION__, error, time);
    
    return (MMI_BOOL)(MDI_AUDIO_SUCCESS == error);
}

/*******************************************************************************
** ����: msgcmd_AdoRecdResponse
** ����: ¼������/ֹͣ������Ӧ����
** ����: p -- MsgcmdAdoProcReq
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_AdoRecdResponse(void *p)
{
	MCErrCode error = MC_ERR_NONE;
    MsgcmdAdoProcReq *rsp = (MsgcmdAdoProcReq*)p;

    if (rsp->record)
    {
        error = MsgCmd_AdoRecdStart(
	            rsp->forever, 
	            rsp->recdTime, 
	            MsgCmd_GetAdoRecdArgs()->save_gap,
	            strlen(rsp->number) ? rsp->number : NULL);
    }
    else
    {
        MsgCmd_AdoRecdStop(strlen(rsp->number) ? rsp->number : NULL);
    }

	mc_trace("%s, error=%d.",__FUNCTION__, error);
}

/*******************************************************************************
** ����: MsgCmd_AdoRecdGetContext
** ����: ��ȡ¼����������ĵ�ַ
** ����: ��
** ����: ���ع�������ĵ�ַ
** ����: wasfayu
*******/
AdoRecdMngr *MsgCmd_AdoRecdGetContext(void)
{
    return arm;
}

/*******************************************************************************
** ����: MsgCmd_AdoRecdSetAppend
** ����: ����һ��¼��ʱ��
** ����: ��
** ����: ���������Ƿ�ɹ�
** ����: wasfayu
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
** ����: MsgCmd_AdoRecdBusy
** ����: �ж��Ƿ�����¼��
** ����: ��
** ����: ����_TRUE��ʾ����¼��; ����_FALSE��ʾû���κ�¼��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdBusy(void)
{
    return (MMI_BOOL)(arm && ADO_STATUS_IDLE != arm->status);
}

/*******************************************************************************
** ����: MsgCmd_AdoRecdStop
** ����: ֹͣ¼��¼��
** ����: replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_AdoRecdStop(char *replay_number)
{
    mc_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");
    
    if (arm)
    {
        //�������stop����, �������������DoingCb����
        mdi_audio_stop_record();
    }    
}

/*******************************************************************************
** ����: MsgCmd_AdoRecdStart
** ����: ����¼��
** ����: forever       -- �Ƿ�����ʱ��¼��
**       time_in_sec   -- ¼��ʱ��, ����Ϊ��λ, ���foreverΪ��, ����ԸĲ���
**       auto_save_gap -- �Զ������ʱ����, ����Ϊ��λ
**       replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ����ִ�д�����
** ����: wasfayu
*******/
MCErrCode MsgCmd_AdoRecdStart(
    MMI_BOOL forever, 
    U32      time_in_sec, 
    U32      auto_save_gap,
    char    *replay_number)
{
    S32 drive;
    MCErrCode error = MC_ERR_NONE;
	
    mc_trace(
        "%s, ENTRY. forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

	do {
	    if (arm)
	    {
	    	error = MC_ERR_ADORECD_BUSY;
			break;
    	}

	    //T�������ھͷ���
	    if (!MsgCmd_GetTFcardDrive(NULL))
	    {    
	    	error = MC_ERR_NO_TCARD;
			break;
    	}

	    if (!forever && time_in_sec <= MsgCmd_GetAdoRecdArgs()->ignore_time)
	    {
	    	error = MC_ERR_IGNORE_TIME;
			break;
    	}


	    //�е绰��æ
	    if (MsgCmd_GetCallCount() > 0)
	    {
	    	error = MC_ERR_CALL_BUSY;
			break;
    	}

	    //����δ��ȡ��
	    if ((drive = MsgCmd_GetUsableDrive()) <= 0)
	    {
	    	error = MC_ERR_DRIVE_ERROR;
			break;
    	}

	    //��֤·������
	    if (!MsgCmd_CreatePath(drive, MSGCMD_AUDIOS_FOLDER_NAME))
	    {
	    	error = MC_ERR_PATH_NOT_EXIST;
			break;
    	}

	    //��ȡ���̷��Ƿ���ȷ����--�����Ƿ���ڵ�һ����˼
	    if (!MsgCmd_CheckValidDrive(drive))
	    {
	    	error = MC_ERR_DRIVE_ERROR;
			break;
    	}
		
	    //����¼��
	    if (MsgCmd_VdoRecdBusy())
	    {
	    	error = MC_ERR_VDORECD_BUSY;
			break;
    	}
	    
	    arm = (AdoRecdMngr*)MsgCmd_Malloc(sizeof(AdoRecdMngr), 0);
	    arm->saveGap = auto_save_gap ? auto_save_gap : MsgCmd_GetAdoRecdArgs()->save_gap;
	    arm->time    = time_in_sec ? time_in_sec : arm->saveGap;
	    arm->forever = forever;
	    if (!arm->forever && arm->time < arm->saveGap)
	        arm->saveGap = arm->time;
	    
	    if (replay_number && replay_number[0] != '\0')
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
	        error = MC_ERR_DOING_FAILED;
			break;
	    }
		
        arm->status = ADO_STATUS_RECODING;
	}while(0);

	mc_trace("%s, EXIT, error=%d.", __FUNCTION__, error);
    return error;
}
#endif

#if 1 //capture process
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
    //MsgCmd_isink(MMI_FALSE);

	return MMI_TRUE;
}

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

    MsgCmd_ModisCreateJPEG((WCHAR *)filepath);
    return MMI_TRUE;

#else

	MDI_RESULT error;

	error = mdi_camera_capture_to_file(filepath, MMI_FALSE);
	if (MDI_RES_CAMERA_SUCCEED != error)
	{		
    	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		FS_Delete((const WCHAR*)filepath);
		return MMI_FALSE;
	}
	
	error = mdi_camera_save_captured_image();
	if (MDI_RES_CAMERA_SUCCEED != error)
	{
    	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
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

	error = mdi_camera_power_on();
	if (MDI_RES_CAMERA_SUCCEED != error)
	{
    	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
	    return MMI_FALSE;
    }

#if defined(MSGCMD_USE_FLASH_LED_4_CAPTURE) 	
	mmi_camera_turn_on_preview_led_highlight();
#endif	  

    /* open LED */
    //MsgCmd_isink(MMI_TRUE);

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
#endif

	if (MDI_RES_CAMERA_SUCCEED != error)
	{
    	mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		error = mdi_camera_preview_stop();
		mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		
		error = mdi_camera_power_off();
		mc_trace("%s, L:%d, error=%d.", __FUNCTION__, __LINE__, error);
		
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
	MCErrCode error;
    MsgcmdCaptureReq *rsp = (MsgcmdCaptureReq*)p;
    
    if (strlen(rsp->number))
        error = MsgCmd_CaptureEntry(rsp->number, rsp->user);
    else
        error = MsgCmd_CaptureEntry(NULL, rsp->user);
}

/*******************************************************************************
** ����: MsgCmd_CaptureEntry
** ����: ����
** ����: replay_number -- ���պ�ش���Ƭ��ָ������, �����͵���������.
**       user_name     -- �û���, ���ڱ�ʶ��˭�������������
** ����: ����ִ��ʱ�Ĵ�����
** ����: wasfayu
*******/
MCErrCode MsgCmd_CaptureEntry(char *replay_number, char *user_name)
{
	const U16 pictureW = 640;
	const U16 pictureH = 480;
    S32       drive;
	MCErrCode error = MC_ERR_NONE;
	
    mc_trace("%s, ENTRY. replay=%s.user=%s.",
        __FUNCTION__,
        replay_number?replay_number:"NULL",
        user_name?user_name:"NULL");

	do {
	    //T�������ھͷ���
	    if (!MsgCmd_GetTFcardDrive(NULL))
	    {
	    	error = MC_ERR_NO_TCARD;
			break;
    	}

	    if ((drive = MsgCmd_GetUsableDrive()) <= 0)
	    {
	    	error = MC_ERR_DRIVE_ERROR;
			break;
    	}
	    
	    //��ȡ���̷��Ƿ���ȷ����--�����Ƿ���ڵ�һ����˼
	    if (!MsgCmd_CheckValidDrive(drive))
	    {
	    	error = MC_ERR_DRIVE_ERROR;
			break;
    	}

	    //��֤·������
	    if (!MsgCmd_CreatePath(drive, MSGCMD_VIDEOS_FOLDER_NAME))
	    {
	    	error = MC_ERR_PATH_NOT_EXIST;
			break;
    	}
	    
		if (msgcmd_CapturePreview(pictureW, pictureH))
		{
			MMI_BOOL  result = MMI_FALSE;

		    MsgCmdMMSReq *req = (MsgCmdMMSReq*)MsgCmd_ConstructPara(sizeof(MsgCmdMMSReq));
	        
			req->picname = MsgCmd_CombineFilePath(
	                        req->picpath, 
	                        MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR), 
	                        MSGCMD_PHOTOS_FOLDER_NAME, 
	                        L".jpg");
			
			result = msgcmd_CaptureDoing((S8 *)req->picpath);
	        error = result ? MC_ERR_NONE : MC_ERR_DOING_FAILED;
			
			if (result && NULL != replay_number && replay_number[0] != '\0')
			{
				//send MMS
	            req->sim = (mma_sim_id_enum)MsgCmd_GetDefinedSim();
			    strcpy(req->sendto, replay_number);            
	            kal_wsprintf(req->subject, "%w", req->picname);
	            MsgCmd_SendIlm2Mmi((msg_type)MSG_ID_MC_SEND_MMS_REQ, (void *)req);
			}
	        else
	        {
	            MsgCmd_DestructPara(req);
	        }
		}

		msgcmd_CaptureFinish();
	}while(0);

	mc_trace("%s, EXIT. error=%s.", __FUNCTION__, error);
        
    return error;
}
#endif

#if 1//video record

static WCHAR *msgcmd_VdoRecdGetSavePath(WCHAR *buffer, U32 length_in_byte);
static WCHAR *msgcmd_VdoRecdGetFilePath(WCHAR *buffer, U32 length_in_byte);
static void msgcmd_VdoRecdCheckFreeSpace(S32 drive);
static void msgcmd_VdoRecdSaveCb(MDI_RESULT result);
static void msgcmd_VdoRecdDoingCb(MDI_RESULT result);
static void msgcmd_VdoRecdLayerMngr(MMI_BOOL create, gdi_handle *layer);
static MMI_BOOL msgcmd_VdoRecdPowerMngr(MMI_BOOL on);
static MMI_BOOL msgcmd_VdoRecdPreview(MMI_BOOL start, gdi_handle layer);
static MMI_BOOL msgcmd_VdoRecdDoing(WCHAR *filepath);
//static MMI_BOOL msgcmd_VdoRecdStop(void);
static void msgcmd_VdoRecdDelete(WCHAR *filepath);
static MMI_BOOL msgcmd_VdoRecdSave(WCHAR *filepath);
static void msgcmd_VdoRecdTimerCyclic(void);
static void msgcmd_VdoRecdCyclicTimer(MMI_BOOL start);
static void msgcmd_VdoRecdResponse(void *p);
static void msgcmd_VdoRecdContRecdRsp(void *p);

static VdoRecdMngr *vrm;

#define MSGCMD_VDORECD_CYCLIC_TIMER_TIME  1000 //ms
#define MSGCMD_VDORECD_CYCLIC_TIMER_ID   MSGCMD_TIMER_VDO_CHECK

#define MSGCMD_VDORECD_PREVIEW_HEIGHT    LCD_HEIGHT
#define MSGCMD_VDORECD_PREVIEW_WIDTH     LCD_WIDTH

//MTK52�ϲ�֧��HQVGA����Ƶ��? �ĳ�HQVGAϵͳֱ�ӹ��� //MDI_VIDEO_VIDEO_SIZE_HVGA   //480x320
#define MSGCMD_VDORECD_VIDEO_SIZE        MDI_VIDEO_VIDEO_SIZE_QVGA //320x240

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
    MsgCmd_CombineFilePath(
        buffer, 
        length_in_byte,
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
** ����: msgcmd_VdoRecdCheckFreeSpace
** ����: ���ʣ��ռ�
** ����: drive  -- �̷�
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_VdoRecdCheckFreeSpace(S32 drive)
{
#if defined(WIN32)
    //ģ������ɾ��100KB
    if (app_getcurrtime() % 5 == 0)
    {
        WCHAR file[MSGCMD_FILE_PATH_LENGTH+1];

        memset(file, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
        kal_wsprintf(
            file, "%c:\\%w\\%w",
            drive, MSGCMD_VIDEOS_FOLDER_NAME, MSGCMD_VDO_LIST_FILE_NAME);
        
        msgcmd_DeleteOldFile(file, 100);
    }
    
#else

	U32 left, need;
    
	//һ���Ӿ���110KB, ���Ҫ����ʣ��ռ�Ļ�, ����Ҫ�������
    //����ʣ��ռ�С��5M��ɾ���͵�¼���ļ�
    left = MsgCmd_GetDiskFreeSize(MsgCmd_GetUsableDrive()) >> 10;
    need = MSGCMD_VDO_SIZE_PER_SEC_KB * MsgCmd_GetVdoRecdArgs()->save_gap * 2;
    
	mc_trace("%s, left=%dKB. need=%dKB.", __FUNCTION__, left, need);

	if (left <= need)
	{
	    WCHAR file[MSGCMD_FILE_PATH_LENGTH+1];

        memset(file, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
        kal_wsprintf(
            file, "%c:\\%w\\%w",
            drive, MSGCMD_VIDEOS_FOLDER_NAME, MSGCMD_VDO_LIST_FILE_NAME);
        
	    msgcmd_DeleteOldFile(file, need*2);
    }
#endif

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
    
    mc_trace("%s. result=%d, stop=%d.", __FUNCTION__, result, vrm->stop);
    
	//mdi_video_rec_get_cur_record_time
    if (MDI_RES_VDOREC_SUCCEED == result)
    {
    #if defined(WIN32)
        //ģ�����������д��һЩ���ݳ����
        if (MsgCmd_GetCurrentTime()%5==0)
        {
            MsgCmd_ModisCreateAVI(vrm->filepath);
        }
    #endif
    
        //����ļ�С�����ֵ��ɾ������
        if (applib_get_file_size(vrm->filepath) >= MsgCmd_GetVdoRecdArgs()->ignore_size)
        {
            WCHAR file[MSGCMD_FILE_PATH_LENGTH+1];

            memset(file, 0, sizeof(WCHAR)*(MSGCMD_FILE_PATH_LENGTH+1));
            kal_wsprintf(file, "E:\\%w\\%w", MSGCMD_VIDEOS_FOLDER_NAME, MSGCMD_VDO_LIST_FILE_NAME);
            file[0] = vrm->filepath[0];
        
        	msgcmd_RecordFileName(
        		file,
        		(void*)vrm->filepath, 
        		app_ucs2_strlen((const S8 *)vrm->filepath) * sizeof(WCHAR));
        }
        else
        {
            FS_Delete(vrm->filepath);
        }
        
        if (!vrm->forever)
        {
            
            //���û��׷�ӱ�־, ���ȥһ��savegap��ʱ��
            if (!vrm->append)
            {
				mc_trace("%s, time=%dS, gap=%d.", __FUNCTION__, vrm->time, vrm->saveGap);
				vrm->time -= vrm->saveGap;
            }

            //ʣ��ʱ��С��xx������Ե�
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
        //����Ϣ��ȥ����¼��
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
** ����: msgcmd_VdoRecdDoingCb
** ����: ¼��������Ļص�����
** ����: result  -- ¼���������
** ����: ��
** ����: wasfayu
*******/
static void msgcmd_VdoRecdDoingCb(MDI_RESULT result)
{
    mc_trace("%s,L:%d. result=%d.", __FUNCTION__, __LINE__, result);
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
    
    if (create)
    {
        U8 *temp;
        S32 h = MSGCMD_VDORECD_PREVIEW_HEIGHT, w = MSGCMD_VDORECD_PREVIEW_WIDTH;
        
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
        /* set main camera id */
        mdi_video_set_camera_id(0);
    
        /* camera power up */
        ret = mdi_video_rec_power_on();
        
        /* open LED */
    	//MsgCmd_isink(MMI_TRUE);
        
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
    	//MsgCmd_isink(MMI_FALSE);
    }

    mc_trace("%s, on=%d, ret=%d.", __FUNCTION__, on, ret);
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
        video_preview_data.video_size			= MSGCMD_VDORECD_VIDEO_SIZE;
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
** ����: msgcmd_VdoRecdDoing
** ����: ��ʼ¼��
** ����: filepath -- �ļ����·��
** ����: �Ƿ�ɹ�ִ��¼��
** ����: wasfayu
*******/
static MMI_BOOL msgcmd_VdoRecdDoing(WCHAR *filepath)
{
    MDI_RESULT ret;

    //����ʣ��ռ�С��15M��ɾ���͵���Ƶ�ļ�
    msgcmd_VdoRecdCheckFreeSpace((S32)filepath[0]);
    
    ret = mdi_video_rec_record_start((S8*)filepath, msgcmd_VdoRecdDoingCb);
    mc_trace("%s, ret=%d.", __FUNCTION__, ret);
    if (MDI_RES_VDOREC_SUCCEED == ret)
        msgcmd_VdoRecdCyclicTimer(MMI_TRUE);
    
    return (MMI_BOOL)(MDI_RES_VDOREC_SUCCEED == ret);
}

///*******************************************************************************
//** ����: msgcmd_VdoRecdStop
//** ����: ֹͣ¼��¼��
//** ����: ��
//** ����: �Ƿ�ֹͣ
//** ����: wasfayu
//*******/
//static MMI_BOOL msgcmd_VdoRecdStop(void)
//{
//    MDI_RESULT ret;
//
//    ret = mdi_video_rec_record_stop();
//    if (MDI_RES_VDOREC_SUCCEED == ret)
//        msgcmd_VdoRecdCyclicTimer(MMI_FALSE);
//
//    mc_trace("%s, ret=%d.", __FUNCTION__, ret);
//    return (MMI_BOOL)(MDI_RES_VDOREC_SUCCEED == ret);
//}

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
    mc_trace("%s.", __FUNCTION__);
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
	mc_trace("%s, L:%d, ret=%d.", __FUNCTION__, __LINE__, ret);

	ret = mdi_video_rec_save_file((S8*)filepath, msgcmd_VdoRecdSaveCb);
	mc_trace("%s, L:%d, ret=%d.", __FUNCTION__, __LINE__, ret);
	
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

{
	//static U32 ct = 0;
	//MsgCmd_isink(++ct%2);
}

#if defined(__VDORECD_VERSION_FEATRUE__)
	//¼�����ĵ�4/5��ʱ���, �����жϼ��
	if (vrm->timeCount == ((vrm->saveGap<<2)/5)/* && MsgCmd_GetExtIntMaskFlag()*/)
	{
		MsgCmd_InterruptMask(MMI_FALSE, __FILE__, __LINE__);
	}
#endif

    //mc_trace("%s, timeCount=%dS. saveGap=%dS.", __FUNCTION__, vrm->timeCount, vrm->saveGap);
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
	MCErrCode error = MC_ERR_NONE;
    MsgcmdVdoProcReq *rsp = (MsgcmdVdoProcReq*)p;

    if (rsp->record)
    {
        error = MsgCmd_VdoRecdStart(
	            rsp->forever, 
	            rsp->recdTime, 
	            rsp->saveGap,
	            strlen(rsp->number) ? rsp->number : NULL);
    }
    else
    {
        MsgCmd_VdoRecdStop(strlen(rsp->number) ? rsp->number : NULL);
    }

	mc_trace("%s, error=%d.",__FUNCTION__, error);
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
    #if defined(__VDORECD_VERSION_FEATRUE__)
		/* ¼��汾������, ��T��ֱ���˳���¼�� */
		if (!MsgCmd_IsSdCardExist())
		{
			mc_trace("%s, not detected T-card. stop.", __FUNCTION__);
			goto stopflag___;
		}
	#endif
		
        msgcmd_VdoRecdPreview(MMI_TRUE, vrm->dispLayer);
        msgcmd_VdoRecdGetFilePath(vrm->filepath, (MSGCMD_FILE_PATH_LENGTH+1)*sizeof(WCHAR));
        kal_sleep_task(20);		
        if (!msgcmd_VdoRecdDoing(vrm->filepath))
        {
        stopflag___:
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
    	mc_trace("%s, set append flag TRUE.", __FUNCTION__);
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
    mc_trace("%s, replay=%s.", __FUNCTION__, replay_number?replay_number:"NULL");

    if (vrm)
    {
        vrm->stop = MMI_TRUE;
        msgcmd_VdoRecdSave(vrm->filepath);

	#if defined(__VDORECD_VERSION_FEATRUE__)
			MsgCmd_InterruptMask(
				(MMI_BOOL)(MsgCmd_IsSimUsable(MsgCmd_GetDefinedSim()) && hf_admin_is_null() && MsgCmd_IsSdCardExist()), 
				__FILE__, __LINE__);
	#endif
    }
}

/*******************************************************************************
** ����: MsgCmd_VdoRecdStart
** ����: ����¼��
** ����: forever       -- �Ƿ�����ʱ��¼��
**       time_in_sec   -- ¼��ʱ��, ����Ϊ��λ, ���foreverΪ��, ����ԸĲ���
**       auto_save_gap -- �Զ�������, ����Ϊ��λ
**       replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ����ִ�д�����
** ����: wasfayu
*******/
MCErrCode MsgCmd_VdoRecdStart(
    MMI_BOOL forever, 
    U32      time_in_sec, 
    U32      auto_save_gap,
    char    *replay_number)
{
    S32 drive;
	MCErrCode error = MC_ERR_NONE;
    
    mc_trace(
        "%s, ENTRY. forever=%d, time=%d, replay=%s.",
        __FUNCTION__, 
        forever, 
        time_in_sec, 
        replay_number?replay_number:"NULL");

	do {
	    if (MsgCmd_VdoRecdBusy())
	    {
	    #if defined(__VDORECD_VERSION_FEATRUE__)
			//¼�������, ׷��ʱ��
	    	if (vrm->timeCount >= ((vrm->saveGap<<2)/5))
			{
				MsgCmd_VdoRecdSetAppend();
				mc_trace("%s, append time. timeCount=%dS.", __FUNCTION__, vrm->timeCount);
				error = MC_ERR_RECD_BUSY_APPEND;
				break;
			}
		#endif
		
	    	error = MC_ERR_VDORECD_BUSY;
			break;
    	}

		if (MsgCmd_AdoRecdBusy())
		{
			error = MC_ERR_ADORECD_BUSY;
			break;
    	}
		
	    if (!forever && time_in_sec <= MsgCmd_GetVdoRecdArgs()->ignore_time)
	    {
	    	error = MC_ERR_IGNORE_TIME;
			break;
    	}
	    
	    //T�������ھͷ���
	    if (!MsgCmd_GetTFcardDrive(NULL))
	    {
	    	error = MC_ERR_NO_TCARD;
			break;
    	}
	    
	    //�е绰��æ
	    if (MsgCmd_GetCallCount() > 0)
	    {
	    	error = MC_ERR_CALL_BUSY;
			break;
    	}

	    //����δ��ȡ��
	    if ((drive = MsgCmd_GetUsableDrive()) <= 0)
	    {
	    	error = MC_ERR_DRIVE_ERROR;
			break;
    	}

	    //��֤·������
	    if (!MsgCmd_CreatePath(drive, MSGCMD_VIDEOS_FOLDER_NAME))
	    {
	    	error = MC_ERR_PATH_NOT_EXIST;
			break;
    	}
	    
	    //��ȡ���̷��Ƿ���ȷ����--�����Ƿ���ڵ�һ����˼
	    if (!MsgCmd_CheckValidDrive(drive))
	    {
	    	error = MC_ERR_DRIVE_ERROR;
			break;
    	}
	    else
	    {
	        WCHAR buffer[MSGCMD_FILE_PATH_LENGTH+1];

	        msgcmd_VdoRecdGetSavePath(
	            buffer, 
	            MSGCMD_FILE_PATH_LENGTH*sizeof(WCHAR));
	        
	        //�Ƿ���δ���������Ƶ
	        if (mdi_video_rec_has_unsaved_file((S8*)buffer))
	        {
	            //����֮?ɾ��֮?
	            mc_trace("%s, L:%d, has unsaved video, delete.", __FUNCTION__, __LINE__);
	            msgcmd_VdoRecdDelete(buffer);
	        }
	    }
	    
	    vrm = (VdoRecdMngr*)MsgCmd_Malloc(sizeof(VdoRecdMngr), 0);
	    vrm->forever = forever;
	    vrm->saveGap = auto_save_gap ? auto_save_gap : MsgCmd_GetVdoRecdArgs()->save_gap;
	    vrm->time    = time_in_sec ? time_in_sec : vrm->saveGap;
	    
	    if (!vrm->forever && vrm->time < vrm->saveGap)
	        vrm->saveGap = vrm->time;
	    
	    if (replay_number && replay_number[0] != '\0')
	        strcpy(vrm->number, replay_number);
	    else
	        vrm->number[0] = '\0';

	    msgcmd_VdoRecdGetFilePath(vrm->filepath, (MSGCMD_FILE_PATH_LENGTH+1)*sizeof(WCHAR));
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
				error = MC_ERR_DOING_FAILED;
	        }
	    }
	    else
	    {
	        msgcmd_VdoRecdPowerMngr(MMI_FALSE);
	        msgcmd_VdoRecdLayerMngr(MMI_FALSE, &vrm->dispLayer);
	        MsgCmd_Mfree(vrm);
	        vrm = NULL;
			error = MC_ERR_PREVIEW_FAILED;
	    }
	}while(0);

	mc_trace("%s, EXIT. error=%d.", __FUNCTION__, error);
    return error;
}
#endif


/*******************************************************************************
** ����: MsgCmd_ProcessInit
** ����: ������ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
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

    //ע����Ϣ��Ӧ
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
        (PsIntFuncPtr)msgcmd_SendMMSRequestResponse,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SEND_RSP, 
        (PsIntFuncPtr)msgcmd_SendMMSResultRespond,
        MMI_TRUE);

#if defined(__MSGCMD_DTMF__)
	Dtmf_Initialize();
#endif
}

#endif/*__MSGCMD_SUPPORT__*/

