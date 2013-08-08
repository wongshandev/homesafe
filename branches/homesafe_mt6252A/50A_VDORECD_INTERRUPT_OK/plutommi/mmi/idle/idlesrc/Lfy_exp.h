
#ifndef __LFY_EXP_H__
#define __LFY_EXP_H__

#if defined(__LEIFAYU__)
#include "gdi_datatype.h"
#include "app_datetime.h"
#include "SmsSrvGprot.h"
#include "mma_struct.h"
#include "ucsrvgprot.h"
#include "umsrvdefs.h"
#include "GlobalConstants.h"
#include "mdi_datatype.h"
#include "ucmsrvgprot.h"

/* ϵͳĬ��ֵ */
#define MSGCMD_FILE_PATH_LENGTH   127
#define MSGCMD_FILE_NAME_LENGTH   63
#define MAX_PHONENUMBER_LENTH     21

/* �ӳ�ʱ��TICK��һ��TICK��Լ10ms */
#define MSGCMD_CAPTURE_DLY_TICK  (1)
#define MSGCMD_ADORECD_DLY_TICK  (1)
#define MSGCMD_VDORECD_DLY_TICK  (10)


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
    U32           timeCount;
    MMI_BOOL      forever;       //�Ƿ�����ʱ¼��
    MMI_BOOL      append;        //�Ƿ�׷��һ��saveGapʱ����¼��
    MMI_BOOL      stop;
    gdi_handle    dispLayer;    //OSD����
    VdoRecdStatus status;        //��ǰ״̬
}VdoRecdMngr;

/* video record request */
typedef struct {
    LOCAL_PARA_HDR
    MMI_BOOL    record;
    MMI_BOOL    forever;
    U32         saveGap;
    U32         recdTime;
    char        number[MAX_PHONENUMBER_LENTH+1];
}MsgcmdVdoProcReq;

/* capture request */
typedef struct {
    LOCAL_PARA_HDR
    char        number[MAX_PHONENUMBER_LENTH+1];
}MsgcmdCaptureReq;

#define MSGCMD_PHOTOS_FOLDER_NAME   L"Photos"
#define MSGCMD_AUDIOS_FOLDER_NAME   L"Audios"
#define MSGCMD_VIDEOS_FOLDER_NAME   L"Videos"

#define MSGCMD_AUDIO_LIST_FILE_NAME L"AdoFiles.lst"
#define MSGCMD_VIDEO_LIST_FILE_NAME L"VdoFiles.lst"

#define MSGCMD_ADO_LIST_FILE_NAME   L"AdoFiles.lst"
#define MSGCMD_VDO_LIST_FILE_NAME   L"VdoFiles.lst"

//¼��/¼��ÿ�����γɵ��ļ���С�ж���KB
#define MSGCMD_ADO_SIZE_PER_SEC_KB  10
#define MSGCMD_VDO_SIZE_PER_SEC_KB  120



/* AT ��������ö�� */
typedef enum {
    AT_CMD_REBOOT,
    AT_CMD_SHUTDOWN,
    AT_CMD_CATCH,
    AT_CMD_ADORECD,
    AT_CMD_VDORECD,
    AT_CMD_CAPTURE,
    AT_CMD_DISKSIZE,
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
    char   *pos;
    U16     len;
}ArgItem_t;

typedef struct {
    const char  *name;
    U16          argc;
    ArgItem_t    argv[CMD_ARG_ITEM_MAX];
    AtExecMode_e mode;
    AtCmdIdx_e   index;
    AtExecRst_e  result;
}AtParam_t;

typedef void (*AtCbFunc)(AtParam_t *);
typedef struct {
    char      *bodyStr;
    U16        bodyLen;
    AtCmdIdx_e index;
    AtCbFunc   callback;
}AtCmdTab_t;


#define MSGCMD_ADO_RECD_TIME_MIN  (60*1)
#define MSGCMD_VDO_RECD_TIME_MIN  (60*1)

#define MSGCMD_ADO_AUTO_SAVE_GAP  (60*2) // 300S
#define MSGCMD_VDO_AUTO_SAVE_GAP  (60*2) // 300S

#define MSGCMD_ADO_INT_CHECK_TIME (60*1)
#define MSGCMD_VDO_INT_CHECK_TIME (60*1)

#define MSGCMD_ADO_IGNORE_TIME    (5) //ʱ��(��)С�ڸ�ֵ����Ե�
#define MSGCMD_VDO_IGNORE_TIME    (5) //ʱ��(��)С�ڸ�ֵ����Ե�

#define MSGCMD_ADO_IGNORE_SIZE    (1024*3) //С�ڸ�ֵ(BYTE)���ļ�������ɾ��
#define MSGCMD_VDO_IGNORE_SIZE    (1024*30) //С�ڸ�ֵ(BYTE)���ļ�������ɾ��

typedef struct {
//ʱ�䵥λ������������
    U16    min_time;    //Ĭ�ϵ���Сֵ
    U16    save_gap;    //�Զ������ʱ����
    U16    int_check;   //�ⲿ�ж����¼���ʱ��, ҪС��save_gap��ֵ
    U16    ignore_time; //С�ڸ�ֵ����Ե��������ó�Ĭ�ϵ�min_timeֵ
    U32    ignore_size; //С�ڸ�ֵ(BYTE)���ļ�������ɾ��
}MsgCmdRecdArg;


/* �Զ�����ŷ�������ṹ */
typedef struct {
	char     sendto[MMI_PHB_NUMBER_LENGTH+1];
	WCHAR    xmlpath[MSGCMD_FILE_PATH_LENGTH+1];
	WCHAR    subject[SRV_UC_MAX_SUBJECT_LEN+1];
	WCHAR    picname[MSGCMD_FILE_NAME_LENGTH+1];
	WCHAR    picpath[MSGCMD_FILE_PATH_LENGTH+1];
	
	U8    priority;          /* mma_priority_enum */
	U8    expiry_time;       /* srv_uc_expiry_time_enum */
    U8    delivery_time;     /* srv_uc_delivery_time_enum */
    BOOL  read_report;       /* Read report flag */
    BOOL  delivery_report;   /* Delivery report flag */
    BOOL  hide_sender;       /* Hide sender flag */
}MsgCmdMMSXmlData;

typedef struct {
    WCHAR    xmlpath[MSGCMD_FILE_PATH_LENGTH+1];
    mma_sim_id_enum  sim;
}MsgCmdMMSUserData;

typedef struct {
	LOCAL_PARA_HDR
	char     sendto[MMI_PHB_NUMBER_LENGTH+1];
	WCHAR    subject[SRV_UC_MAX_SUBJECT_LEN+1];
	WCHAR    picpath[MSGCMD_FILE_PATH_LENGTH+1];
    WCHAR   *picname; //���ָ����ʵ����ָ��picpath�����ĳ��Ԫ��    
    mma_sim_id_enum  sim;
}MsgCmdMMSReq;

/* �ⲿ�жϴ������� */
typedef struct {
	LOCAL_PARA_HDR
    MMI_BOOL   level;
}MsgCmdExtIntReq;

/*******************************************************************************
** ����: MsgCmd_GetInteger
** ����: �Ӹ������ȵ��ַ����л�ȡһ��32λ�޷�������
** ����: ps  ��������
**       sl  �ַ�������
**       type  �ַ�������
** ����: ��ȡ�ɹ����ض�Ӧ��ֵ, ʧ�ܷ���-1
** ����: wasfa
*******/
U32 MsgCmd_GetInteger(const char *ps, U16 sl, StringType_e type);

/*******************************************************************************
** ����: MsgCmd_Atoi
** ����: ϵͳ����atoi�İ�װ
** ����: 
** ����: 
** ����: wasfa
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

/*******************************************************************************
** ����: MsgCmd_MemFree
** ����: �ͷ���MsgCmd_MemAlloc���������ڴ�
** ����: memptr   ��ʾ��Ҫ�ͷŵ��ڴ��ַ.
** ����: ��
** ˵��: med_free_ext_mem�Ǹ��ܱ�̬�ĺ���, ��ȻҪȡ��ַ֮�������ַ. ����...
** ����: wasfayu
*******/
void MsgCmd_MemFree(void *p, const char* file, U32 line);

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
** ����: MsgCmd_CheckValidDrive
** ����: ���������̷��Ƿ��ѹ���
** ����: �̷�, C/D/E/F...
** ����: �����̿ɹ�ʹ��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_CheckValidDrive(U32 drive);

/*******************************************************************************
** ����: MsgCmd_GetUsableDrive
** ����: ��ȡϵͳ���õĴ洢�豸�̷�
** ����: ��
** ����: �����̷� 0x43~0x47
** ����: wasfayu
*******/
S32 MsgCmd_GetUsableDrive(void);

/*******************************************************************************
** ����: MsgCmd_GetSystemDrive
** ����: ��ȡϵͳ�̵��̷�
** ����: ��
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
** ����: t  -- 
** ����: �Ƿ���Ч
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t);

/*******************************************************************************
** ����: MsgCmd_DeleteFileFront
** ����: ɾ���ļ���ǰ��
** ���: fullPathName -- �ļ��ľ���·����, UCS��ʽ, �� "D:\\myfile.txt"
**       deletesz     -- ɾ����С, �����ļ�ͷ��ʼɾ��deletesz���ֽڵ�����
** ����: ����ִ���Ƿ�����
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_DeleteFileFront(const WCHAR *fullPathName, U32 deletesz);

/*******************************************************************************
** ����: MsgCmd_DeleteOldFile
** ����: �����ļ��б��еļ�¼ɾ���ļ�
** ���: fullname   -- ¼���ļ��ľ���·���ļ���, UCS��ʽ
**       cmpSzKB    -- ��Ҫɾ�����ܴ�С, KB
** ����: ����ִ���Ƿ�����
** ����: wasfayu
*******/
//S32 MsgCmd_DeleteOldFile(const WCHAR *list_file_name, U32 cmpSzKB);

/*******************************************************************************
** ����: MsgCmd_RecordFileName
** ����: ��ĳ���ļ���UCS��ʽ����pdataд�뵽fname�ļ���ȥ
** ���: fname   -- �ļ���, UCS��ʽ
**       pdata   -- ��д�������
**       datalen -- ��д������ݳ���, �ֽ�Ϊ��λ
** ����: �Ƿ�д��ɹ�
** ����: wasfayu
*******/
//MMI_BOOL MsgCmd_RecordFileName(const WCHAR *fname, void *pdata, U32 datalen);

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
** ����: MsgCmd_AtCmdProc
** ����: �����Զ���AT����
** ����: origStr  -- AT�����в���, 
**                   ��������Զ����ATָ���򲻿��ƻ�cmd_string�е�����
** ����: �Ƿ����Զ���ATָ��
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_AtCmdProc(char *origStr);

/*******************************************************************************
** ����: MsgCmd_CreateAndSendMMS
** ����: �������ҷ���MMS
** ���: xml_path  -- MMS�����ļ�, �����Ѿ������е绰������Щ��
**       sim       -- mma_sim_id_enum
** ����: �Ƿ�ɹ�
** ����: wasfayu
*******/
MMI_BOOL MsgCmd_CreateAndSendMMS(mma_sim_id_enum sim, WCHAR *xml_path);

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
** ����: lfy_WriteFile
** ����: ������д���ļ�
** ����: filepath   -- �ļ��ľ���·��
**       cover      -- �Ƿ񸲸�ԭ��������, �������׷�����ļ�ĩβ
**       data       -- ���ݿ�
**       length     -- ���ݿ�ĳ���
** ����: ʵ��д������ݳ���
** ����: wasfayu
*******/
U32 lfy_WriteFile(const WCHAR *filepath, MMI_BOOL cover, void *data, U32 length);

/*******************************************************************************
** ����: lfy_init
** ����: ��ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void lfy_init(void);

/*******************************************************************************
** ����: lfy_event_handler
** ����: ϵͳ�¼���Ӧ
** ����: �¼�֪ͨ��ַ
** ����: ������
** ����: LeiFaYu
*******/
S32 lfy_event_handler(mmi_event_struct *evt);

#if 1

//macro
#define __NEED_CHECK_PASSWORD__
#define __RECIVE_CMD_PARAMETER__
#define __EXEC_IN_TIMER_CBF__
#define __TEST_PLAY_AUDIO__


#define DTMF_HOT_KEY_VALUE         '#'
#if defined(__TEST_PLAY_AUDIO__)
#define DTMF_TEST_KEY_VALUE        '*'
#endif
#define DTMF_MAX_REPEAT_TIMES      3
#define DTMF_DEF_DETECT_TIME       15000    //ms
#define DTMF_ENTRY_DETECT_TIME     10000

// E:\dtmf\1.wav
#define DTMF_VOICE_MAIN_PATH       L"dtmf_voice"

//1. �밴'#'������ϵͳ.   "entry.wav"
//#define DTMF_VOC_IDX_ENTRY           1
//2. ���������벢��'#'����������.  "pwd.wav"
//#define DTMF_VOC_IDX_PWD             2
//3. ��ѡ�����: 1Ϊ����; 2Ϊ¼��; 3Ϊ¼��.  "opt.wav"
//#define DTMF_VOC_IDX_CHOOSE          3
//4. ������������, ����������!  "retry.wav"
//#define DTMF_VOC_IDX_RETRY           4
//5. ���Ĵ����������, лл����, �ټ�!   "warn.wav"
//#define DTMF_VOC_IDX_ERROR           5
//6. ���Ĳ��������ѱ�����. лл����, �ټ�!  "accept.wav"
//#define DTMF_VOC_IDX_RECV            6
//7. �����������������"#"������   "param.wav"
//#define DTMF_VOC_IDX_PARAM           7
typedef enum {
    DTMF_VOC_NO_VOICE       = 0,
    DTMF_VOC_PRESS_TO_ENTRY = 1,
    DTMF_VOC_INPUT_PASSWORD = 2,
    DTMF_VOC_CHOOSE_OPTION  = 3,
    DTMF_VOC_RETRY_INPUT    = 4,
    DTMF_VOC_ERROR_TO_EXIT  = 5,
    DTMF_VOC_ACCEPT_REQUEST = 6,
    DTMF_VOC_INPUT_PARAM    = 7,
    DTMF_VOC_RETRY_PASSWORD = 8,
    
    DTMF_VOC_NOT_DEFINED    = 0,
}DtmfVoiceIndex;


typedef enum {
    DTMF_CMD_UNDEFINED = 0,
    DTMF_CMD_CAPTURE,
    DTMF_CMD_ADORECD,
    DTMF_CMD_VDORECD,
    DTMF_CMD_MAX_ENUM
}DtmfCommand;

typedef enum {
    DTMF_STATE_IDLE = 0,
    DTMF_STATE_WAITING_ENTRY,
    DTMF_STATE_INPUT_PWD,
    DTMF_STATE_CHOOSE_OPTION,
    DTMF_STATE_INPUT_PARAM,
    DTMF_STATE_GOODBYE,
    DTMF_STATE_MAX_ENUM
}DtmfStatus;

typedef struct {
    DtmfVoiceIndex index;
    CHAR         *name;
}VoiceAttr;


typedef struct {
    WCHAR name[SRV_UCM_MAX_DISP_NAME_LEN + 1]; /* Display name */
    char  number[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
}DtmfCallInfo;



typedef struct {
    DtmfStatus   state;         //��ǰ״̬
    DtmfCommand  command;       //ѡ��������
    MMI_BOOL     start;
    U8           rptMax;      //�����ظ�����
    U8           rptCount;    //���ظ�����
    U8           hotKey;      //�ȼ�
#if defined(__TEST_PLAY_AUDIO__)
    U8           testKey;     //����¼���ļ��Ƿ���Բ���
#endif
    U32          detectTime;  //��ⳬʱʱ��ms
    DtmfCallInfo call;
    union {
        U8    password[6+2];
        U32   recordTime;
    }param;
}DtmfControl;

typedef struct {
    LOCAL_PARA_HDR
    DtmfCallInfo info;   
}DtmfAutoAnswerReq;

typedef struct {
    LOCAL_PARA_HDR
    DtmfCommand  command;
    char         number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    void        *param;
}DtmfCmdExecReq;


/*******************************************************************************
** ����: Dtmf_Reset
** ����: ������λ
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_Reset(void);

/*******************************************************************************
** ����: Dtmf_Initialize
** ����: ��ʼ��
** ����: ��
** ����: ��
** ����: wasfayu
*******/
void Dtmf_Initialize(void);

/*******************************************************************************
** ����: Dtmf_AutoAnswerReqSend
** ����: ��������Ӧ���������Ϣ
** ����: name  -- �������
**       number-- ��ʾ����
** ����: ��
** ����: wasfayu
*******/
void Dtmf_AutoAnswerReqSend(WCHAR *name, char *number);
#endif

#endif/*defined(__LEIFAYU__)*/

#endif/*__LFY_EXP_H__*/

