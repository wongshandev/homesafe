/*******************************************************************************
 *
 * msgcmd_process.h
 *
 * �����ṩ¼��/¼��/����/�ظ�����/�ظ����ŵĽӿں���
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, ����ԭʼ�汾
 *
 ******************************************************************************/

#ifndef __MSGCMD_PROCESS_H__
#define __MSGCMD_PROCESS_H__


#if defined(__MSGCMD_SUPPORT__)
#include "./ws_main.h"
#include "gdi_datatype.h"
#include "app_datetime.h"
#include "SmsSrvGprot.h"


/* ϵͳĬ��ֵ */
#define MSGCMD_FILE_PATH_LENGTH   127

#define MSGCMD_ADO_AUTO_SAVE_GAP  (60*5) // 300S
#define MSGCMD_VDO_AUTO_SAVE_GAP  (60*5) // 300S
/* �ӳ�ʱ��TICK��һ��TICK��Լ10ms */
#define MSGCMD_CAPTURE_DLY_TICK  (2)
#define MSGCMD_ADORECD_DLY_TICK  (2)
#define MSGCMD_VDORECD_DLY_TICK  (10)

/* ��ʱ��ID���� */
#define MSGCMD_TIMER_REBOOT       (MSGCMD_TIMER_BASE + 0)
#define MSGCMD_TIMER_SHUTDOWN     (MSGCMD_TIMER_BASE + 1)
#define MSGCMD_TIMER_FACTORY      (MSGCMD_TIMER_BASE + 2)

/* ��ϢID���� */
#define MSG_ID_MC_VDORECD_REQ     (MSG_ID_MC_BASE + 0)
#define MSG_ID_MC_ADORECD_REQ     (MSG_ID_MC_BASE + 1)
#define MSG_ID_MC_CAPTURE_REQ     (MSG_ID_MC_BASE + 2)


/* �ַ����� */
typedef enum {
    STR_TYPE_NORMAL = 0,
    STR_TYPE_DIG,
    
    STR_TYPE_2 = 2,  /*<! ǧ��Ҫ�޸����ö�ٵ�ֵ>*/
    STR_TYPE_8 = 8,  /*<! ǧ��Ҫ�޸����ö�ٵ�ֵ>*/
    STR_TYPE_10 = 10,/*<! ǧ��Ҫ�޸����ö�ٵ�ֵ>*/
    STR_TYPE_16 = 16,/*<! ǧ��Ҫ�޸����ö�ٵ�ֵ>*/
    
    STR_TYPE_MAX = STR_TYPE_NORMAL
}StringType_e;

/* ¼��״̬ö�� */
typedef enum {
    VDO_STATUS_IDLE,
    VDO_STATUS_PREVIEW,
    VDO_STATUS_RECODING,
    VDO_STATUS_PAUSE,
    VDO_STATUS_SAVING,
    VDO_STATUS_MAX
}VdoRecdStatus;


/* ¼��״̬���� */
typedef struct {
    WCHAR         filepath[MSGCMD_FILE_PATH_LENGTH+1]; //�ļ�����·��
    char          number[MAX_PHONENUMBER_LENTH+1];
    U32           time;          //unit: second
    U32           saveGap;       //unit: second
    MMI_BOOL      forever;       //�Ƿ�����ʱ¼��
    MMI_BOOL      append;        //�Ƿ�׷��һ��saveGapʱ����¼��
    gdi_handle    dispHandle;    //OSD����
    VdoRecdStatus status;        //��ǰ״̬
}VdoRecdMngr;

/* ¼��״̬ö�� */
typedef enum {
    ADO_STATUS_IDLE,
    ADO_STATUS_RECODING,
    ADO_STATUS_PAUSE,
    ADO_STATUS_SAVING,
    ADO_STATUS_MAX
}AdoRecdStatus;

/* ¼��״̬���� */
typedef struct {
    WCHAR         filepath[MSGCMD_FILE_PATH_LENGTH+1]; //�ļ�����·��
    char          number[MAX_PHONENUMBER_LENTH+1];
    U32           time;    //unit: second
    U32           saveGap; //unit: second
    MMI_BOOL      forever; //�Ƿ�����ʱ¼��
    MMI_BOOL      append;  //�Ƿ�׷��һ��saveGapʱ����¼��
    AdoRecdStatus status;  //��ǰ״̬
}AdoRecdMngr;


#define MSGCMD_PHOTOS_FOLDER_NAME   L"Photos"
#define MSGCMD_AUDIOS_FOLDER_NAME   L"Audios"
#define MSGCMD_VIDEOS_FOLDER_NAME   L"Videos"

#define MSGCMD_AUDIO_LIST_FILE_NAME L"AdoFiles.lst"
#define MSGCMD_VIDEO_LIST_FILE_NAME L"VdoFiles.lst"

/* capture request */
typedef struct {
    LOCAL_PARA_HDR
    char        number[MAX_PHONENUMBER_LENTH+1];
}MsgcmdCaptureReq;

/* video record request */
typedef struct {
    LOCAL_PARA_HDR
    MMI_BOOL    record;
    MMI_BOOL    forever;
    U32         saveGap;
    U32         recdTime;
    char        number[MAX_PHONENUMBER_LENTH+1];
}MsgcmdVdoProcReq;

/* audio record request */
typedef struct {
    LOCAL_PARA_HDR
    MMI_BOOL    record;
    MMI_BOOL    forever;
    U32         saveGap;
    U32         recdTime;
    char        number[MAX_PHONENUMBER_LENTH+1];
}MsgcmdAdoProcReq;

/*******************************************************************************
** ����: MsgCmd_GetInteger
** ����: �Ӹ������ȵ��ַ����л�ȡһ��32λ�޷�������
** ����: ps  ��������
**       sl  �ַ�������
**       type  �ַ�������
** ����: ��ȡ�ɹ����ض�Ӧ��ֵ, ʧ�ܷ���-1
** ����: wasfayu
*******/
U32 MsgCmd_GetInteger(const char *ps, U16 sl, StringType_e type);

/*******************************************************************************
** ����: MsgCmd_Atoi
** ����: ϵͳ����atoi�İ�װ
** ����: 
** ����: 
** ����: wasfayu
*******/
S32 MsgCmd_Atoi(const char *nptr);

/*******************************************************************************
** ����: MsgCmd_IsDigStr
** ����: �ж��Ƿ��������ַ���, 0~9���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsDigStr(const char *ps, U32 sl);

/*******************************************************************************
** ����: MsgCmd_IsXdigStr
** ����: �ж��Ƿ���16�����ַ���, 0~9, A~F, a~f���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsXdigStr(const char *ps, U32 sl);

/*******************************************************************************
** ����: MsgCmd_IsXdigFmtStr
** ����: �Ƿ���16���Ƹ�ʽ��ͷ���ַ���, ����0x��ͷ�������ַ���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsXdigFmtStr(const char *ps, U32 sl);

/*******************************************************************************
** ����: MsgCmd_IsAlpNumstr
** ����: �Ƿ�����ĸ�����ַ���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsAlpNumStr(const char *ps, U32 sl);

/*******************************************************************************
** ����: MsgCmd_IsAlphaStr
** ����: �Ƿ�����ĸ�ַ���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsAlphaStr(const char *ps, U32 sl);

/*******************************************************************************
** ����: MsgCmd_IsSpaceStr
** ����: �Ƿ��ǿհ��ַ���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsSpaceStr(const char *ps, U32 sl);

/*******************************************************************************
** ����: MsgCmd_IsLowerStr
** ����: �Ƿ���Сд�ַ���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsLowerStr(const char *ps, U32 sl);

/*******************************************************************************
** ����: MsgCmd_IsUpperStr
** ����: �Ƿ��Ǵ�д�ַ���
** ����: 
** ����: 
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsUpperStr(const char *ps, U32 sl);

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
char *MsgCmd_strsep(char **s, const char *ct);

/*******************************************************************************
** ����: MsgCmd_GetCallCount
** ����: ��ȡ�绰����
** ����: ��
** ����: ���ص绰����
** ����: wasfayu
*******/
S32 MsgCmd_GetCallCount(void);

/*******************************************************************************
** ����: MsgCmd_IsSdCardExist
** ����: �жϴ洢���Ƿ����
** ����: ��
** ����: �Ƿ����
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsSdCardExist(void);

/*******************************************************************************
** ����: MsgCmd_GetDiskFreeSize
** ����: ��ȡ����ʣ��ռ�
** ����: drive, �����̷�, 0x43~0x47
** ����: ʣ��ռ�Ĵ�С, byteΪ��λ
** ����: wasfayu
*******/
U32 MsgCmd_GetDiskFreeSize(S32 drive);

/*******************************************************************************
** ����: MsgCmd_GetUsableDrive
** ����: ��ȡϵͳ���õĴ洢�豸�̷�
** ����: 
** ����: �����̷� 0x43~0x47
** ����: wasfayu
*******/
S32 MsgCmd_GetUsableDrive(void);

/*******************************************************************************
** ����: MsgCmd_GetSystemDrive
** ����: ��ȡϵͳ�̵��̷�
** ����: 
** ����: Success:                0x43~0x47 (A~G)
**       Error:                  RTF_PARAM_ERROR        (-2)
**                               RTF_DRIVE_NOT_FOUND    (-4)
** ����: wasfayu
*******/
S32 MsgCmd_GetSystemDrive(void);

/*******************************************************************************
** ����: MsgCmd_GetFileSize
** ����: ��ȡ�ļ���С
** ����: path - �ļ�����·��
** ����: �ļ���С
** ����: wasfayu
*******/
U32 MsgCmd_GetFileSize(WCHAR *path);

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
    char *out,
    U16 length,
    const WCHAR *folder,
    const WCHAR *ext_name);

/*******************************************************************************
** ����: MsgCmd_GetCurrentTime
** ����: ��ȡϵͳ��ǰ������ʱ��
** ����: ��
** ����: ����ʱ��
** ����: wasfayu
*******/
U32 MsgCmd_GetCurrentTime(void);

/*******************************************************************************
** ����: MsgCmd_GetDateTime
** ����: ��ȡϵͳ��ǰ��ʱ��
** ����: ʱ��ṹ��
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_GetDateTime(applib_time_struct *t);

/*******************************************************************************
** ����: MsgCmd_SetDateTime
** ����: ����ϵͳ��ǰ��ʱ��
** ����: ʱ��ṹ��
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_SetDateTime(applib_time_struct *t);

/*******************************************************************************
** ����: MsgCmd_IsDateTimeValid
** ����: �ж�ʱ���Ƿ���Ч
** ����: 
** ����: �Ƿ���Ч
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t);

/*******************************************************************************
** ����: MsgCmd_SendIlm2Mmi
** ����: ������Ϣ��MMIģ��
** ����: msgid  -- ��ϢID
**       msg    -- ��Ϣ
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_SendIlm2Mmi(msg_type msgid, void *msg);

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
    void *msg);

/*******************************************************************************
** ����: MsgCmd_MemAlloc
** ����: �����ڴ�, ���ڴ���ڴ�����, ������host_mfree_ext���ͷ�.
** ����: s ��ʾ��Ҫ������ڴ��ֽڳ���.
**       v ��ʾ�����������ڴ������ʼ��Ϊ��ֵ.
** ����: �������뵽���ڴ��ַ.
** ����: wasfayu
*******/
void *MsgCmd_MemAlloc(U32 s, U8 v, const char* file, U32 line);
#define MsgCmd_Malloc(s, v) MsgCmd_MemAlloc(s, v, __FUNCTION__, __LINE__)

/*******************************************************************************
** ����: MsgCmd_MemFree
** ����: �ͷ���MsgCmd_MemAlloc���������ڴ�
** ����: memptr   ��ʾ��Ҫ�ͷŵ��ڴ��ַ.
** ����: ��
** ˵��: med_free_ext_mem�Ǹ��ܱ�̬�ĺ���, ��ȻҪȡ��ַ֮�������ַ. ����...
** ����: wasfayu
*******/
void MsgCmd_MemFree(void *p, const char* file, U32 line);
#define MsgCmd_Mfree(p) MsgCmd_MemFree(p, __FUNCTION__, __LINE__)

/*******************************************************************************
** ����: MsgCmd_ConstructPara
** ����: ��������buffer
** ����: sz   ��ʾ��Ҫʹ�õ�buffer��С.
** ����: ��
** ����: wasfayu
*******/
void *MsgCmd_ConstructPara(U32 sz);

/*******************************************************************************
** ����: MsgCmd_DestructPara
** ����: ����buffer�ͷ�
** ����: ptr   ��ʾ��Ҫ�ͷŵĲ���buffer��ַ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_DestructPara(void *ptr);

/*******************************************************************************
** ����: MsgCmd_Reboot
** ����: ����
** ���: 
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_Reboot(void);

/*******************************************************************************
** ����: MsgCmd_RebootExt
** ����: ��ʱ����
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_RebootExt(U16 delayS);

/*******************************************************************************
** ����: MsgCmd_Shutdown
** ����: �ػ�
** ���: 
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_Shutdown(void);

/*******************************************************************************
** ����: MsgCmd_ShutdownExt
** ����: ��ʱ�ػ�
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_ShutdownExt(U16 delayS);

/*******************************************************************************
** ����: MsgCmd_Factory
** ����: �ػ�
** ���: 
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_Factory(void);

/*******************************************************************************
** ����: MsgCmd_FactoryExt
** ����: ��ʱ�ػ�
** ���: delayS - ��ʱ��������, ���30������ʱ.
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_FactoryExt(U16 delayS);

/*******************************************************************************
** ����: MsgCmd_DeleteFileFront
** ����: ɾ���ļ���ǰ��
** ���: fname   -- �ļ���, UCS��ʽ
**       deletesz -- ɾ����С, �����ļ�ͷ��ʼɾ��deletesz���ֽڵ�����
** ����: ����ִ���Ƿ�����
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_DeleteFileFront(const WCHAR *fname, U32 deletesz);

/*******************************************************************************
** ����: msgcmd_WriteImeiRsp
** ����: ����ָ������
** ����: pnumber -- ָ�����к���
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_MakeCall(char *pnumber);

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
**           �����汾��, ����ͬ�ͺ��ֻ�����ʱʹ�õĲ�ͬ�����汾.
** ����: http://zhidao.baidu.com/question/271966166.html
** ����: http://folk.uio.no/runeheg/imei/
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_WriteImei(char *num, U16 strl, U8 sim, U8 (*rsp)(void*));

/*******************************************************************************
** ����: MsgCmd_SendSms
** ����: ����text����
** ����: to_asc_number  -- Ŀ�����, ASCII��ʽ�ַ���
**       ucs_text_ptr   -- ��������, UCS��ʽ�ı�
**       length_in_byte -- ucs_text_ptr�ĳ���, ���ֽ�Ϊ��λ
**       user_data_ptr  -- �û�����, ���ڻص������б�ʹ��
**       sim            -- ʹ������SIM�������Ͷ���
**       cb             -- ���Ͷ��ŵĻص�����, ���ΪNULL��ʹ��Ĭ�ϵĻص�����
** ����: ����_TRUE��ʾ�����������ɹ�; ����_FALSE��ʾ����������ʧ��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_SendSms(
    char   *to_asc_number,
    S8     *ucs_text_ptr,
    U16     length_in_byte,
    void   *user_data_ptr,
    srv_sms_sim_enum sim,
    SrvSmsCallbackFunc cb);

/*******************************************************************************
** ����: MsgCmd_DeleteOldFile
** ����: �����ļ��б��еļ�¼ɾ���ļ�
** ���: fullname   -- ¼���ļ��ľ���·���ļ���, UCS��ʽ
**       cmpSize    -- ��Ҫɾ�����ܴ�С
** ����: ����ִ���Ƿ�����
** ����: wasfayu
*******/
S32 MsgCmd_DeleteOldFile(const WCHAR *list_file_name, U64 cmpSize);

/*******************************************************************************
** ����: MsgCmd_RecordFileName
** ����: ��ĳ���ļ���UCS��ʽ����pdataд�뵽fname�ļ���ȥ
** ���: fname   -- �ļ���, UCS��ʽ
**       pdata   -- ��д�������
**       datalen -- ��д������ݳ���, �ֽ�Ϊ��λ
** ����: �Ƿ�д��ɹ�
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_RecordFileName(const WCHAR *fname, void *pdata, U32 datalen);

/*******************************************************************************
** ����: MsgCmd_DelayTick
** ����: ��ʱdt��tick
** ����: dt -- Ҫ��ʱ��tick����
** ����: ��
** ˵��: һ��tick�����10ms
** ����: wasfayu
*******/
void MsgCmd_DelayTick(U32 dt);

/*******************************************************************************
** ����: MsgCmd_EvtProcEntry
** ����: ��Ӧϵͳ�¼�
** ����: evp -- �¼�֪ͨ���ݵ�ַ
** ����: �¼��������
** ����: wasfayu
*******/
mmi_ret MsgCmd_EvtProcEntry(mmi_event_struct *evp);

/*******************************************************************************
** ����: MsgCmd_AdoRecdSetAppend
** ����: ����һ��¼��ʱ��
** ����: ��
** ����: ���������Ƿ�ɹ�
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdSetAppend(void);

/*******************************************************************************
** ����: MsgCmd_AdoRecdBusy
** ����: �ж��Ƿ�����¼��
** ����: ��
** ����: ����_TRUE��ʾ����¼��; ����_FALSE��ʾû���κ�¼��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdBusy(void);

/*******************************************************************************
** ����: MsgCmd_AdoRecdStop
** ����: ֹͣ¼��¼��
** ����: replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_AdoRecdStop(char *replay_number);

/*******************************************************************************
** ����: MsgCmd_AdoRecdStart
** ����: ����¼��
** ����: forever       -- �Ƿ�����ʱ��¼��
**       time_in_sec   -- ¼��ʱ��, ����Ϊ��λ, ���foreverΪ��, ����ԸĲ���
**       auto_save_gap -- �Զ������ʱ����, ����Ϊ��λ
**       replay_number -- ��ʾ�ظ����������ָ������, ���Ϊ�����ʾ���ظ�
** ����: �����Ƿ�ɹ�
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdStart(
    MMI_BOOL forever, 
    U32      time_in_sec, 
    U32      auto_save_gap,
    char    *replay_number);

/*******************************************************************************
** ����: MsgCmd_CaptureEntry
** ����: ����
** ����: replay_number -- ���պ�ش���Ƭ��ָ������, �����͵���������.
** ����: �Ƿ����ճɹ�
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_CaptureEntry(char *replay_number);

/*******************************************************************************
** ����: MsgCmd_VdoRecdSetAppend
** ����: ����һ��¼��ʱ��
** ����: ��
** ����: ���������Ƿ�ɹ�
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdSetAppend(void);

/*******************************************************************************
** ����: MsgCmd_VdoRecdBusy
** ����: �ж��Ƿ�����¼��
** ����: ��
** ����: ����_TRUE��ʾ����¼��; ����_FALSE��ʾû���κ�¼��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdBusy(void);

/*******************************************************************************
** ����: MsgCmd_VdoRecdStop
** ����: ֹͣ¼��¼��
** ����: replay_number -- ��ʾ�ظ�ֹͣ�����ָ������, ���Ϊ�����ʾ���ظ�
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_VdoRecdStop(char *replay_number);

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
    char    *replay_number);

/*******************************************************************************
** ����: MsgCmd_ProcessInit
** ����: ������ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void MsgCmd_ProcessInit(void);

#endif/*__MSGCMD_SUPPORT__*/


#endif/*__MSGCMD_PROCESS_H__*/
