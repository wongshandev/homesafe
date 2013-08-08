
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

/* 系统默认值 */
#define MSGCMD_FILE_PATH_LENGTH   127
#define MSGCMD_FILE_NAME_LENGTH   63
#define MAX_PHONENUMBER_LENTH     21

/* 延迟时间TICK，一个TICK大约10ms */
#define MSGCMD_CAPTURE_DLY_TICK  (1)
#define MSGCMD_ADORECD_DLY_TICK  (1)
#define MSGCMD_VDORECD_DLY_TICK  (10)


/* 字符类型 */
typedef enum {
    STR_TYPE_NORMAL = 0,
    STR_TYPE_DIG,
    
    STR_TYPE_2 = 2,  /*<! 千万不要修改这个枚举的值>*/
    STR_TYPE_8 = 8,  /*<! 千万不要修改这个枚举的值>*/
    STR_TYPE_10 = 10,/*<! 千万不要修改这个枚举的值>*/
    STR_TYPE_16 = 16,/*<! 千万不要修改这个枚举的值>*/
    
    STR_TYPE_MAX = STR_TYPE_NORMAL
}StringType_e;

/* 录像状态枚举 */
typedef enum {
    VDO_STATUS_IDLE,
    VDO_STATUS_PREVIEW,
    VDO_STATUS_RECODING,
    VDO_STATUS_PAUSE,
    VDO_STATUS_SAVING,
    VDO_STATUS_MAX
}VdoRecdStatus;


/* 录像状态管理 */
typedef struct {
    WCHAR         filepath[MSGCMD_FILE_PATH_LENGTH+1]; //文件绝对路径
    char          number[MAX_PHONENUMBER_LENTH+1];
    U32           time;          //unit: second
    U32           saveGap;       //unit: second
    U32           timeCount;
    MMI_BOOL      forever;       //是否无限时录制
    MMI_BOOL      append;        //是否追加一次saveGap时长的录制
    MMI_BOOL      stop;
    gdi_handle    dispLayer;    //OSD层句柄
    VdoRecdStatus status;        //当前状态
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

//录音/录像每秒钟形成的文件大小有多少KB
#define MSGCMD_ADO_SIZE_PER_SEC_KB  10
#define MSGCMD_VDO_SIZE_PER_SEC_KB  120



/* AT 命令索引枚举 */
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

/* AT 命令执行模式 */
typedef enum {
    AT_EM_WRONG,        // 错误
    AT_EM_SET_OR_EXEC,  // 设置或者执行, AT+...=
    AT_EM_READ,         // 读取, AT+...?
    AT_EM_HELP,         // 测试, AT+...=?
    AT_EM_ACTIVE,       // 默认模式, 激活, AT+...
    AT_EM_MAX
}AtExecMode_e;


/* AT 命令执行结果 */
typedef enum {
    AT_RST_SUCCESS = 0,
    AT_RST_UNKOWN_ERR,   // 表示未知错误, 一般是参数解析错误居多
    AT_RST_NO_REPLAY,    // 表示无需回复"OK"/"ERROR"等消息
    AT_RST_IGNORED,      // 表示忽略了的, 未进行处理的, 没有对应处理函数的
    AT_RST_NOT_SUPPORT,  // 表示不支持的操作, 比如不支持读取模式
    AT_RST_PARAM_ERR,    // 表示传入的参数不在命令允许的范围或不是命令所需
}AtExecRst_e;


/* AT 命令字符串最大长度, 标准规定 */
#define AT_CMD_STRING_MAX     (1056+2) 
#define AT_CMD_NAME_LEN_MAX   (31)

/* 自定义AT命令最多可以带16个用逗号隔开的参数 */
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

#define MSGCMD_ADO_IGNORE_TIME    (5) //时间(秒)小于该值则忽略掉
#define MSGCMD_VDO_IGNORE_TIME    (5) //时间(秒)小于该值则忽略掉

#define MSGCMD_ADO_IGNORE_SIZE    (1024*3) //小于该值(BYTE)的文件都将被删除
#define MSGCMD_VDO_IGNORE_SIZE    (1024*30) //小于该值(BYTE)的文件都将被删除

typedef struct {
//时间单位都以秒来计算
    U16    min_time;    //默认的最小值
    U16    save_gap;    //自动保存的时间间隔
    U16    int_check;   //外部中断重新检测的时间, 要小于save_gap的值
    U16    ignore_time; //小于该值则忽略掉或者设置成默认的min_time值
    U32    ignore_size; //小于该值(BYTE)的文件都将被删除
}MsgCmdRecdArg;


/* 自定义彩信发送请求结构 */
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
    WCHAR   *picname; //这个指针其实就是指向picpath里面的某个元素    
    mma_sim_id_enum  sim;
}MsgCmdMMSReq;

/* 外部中断处理请求 */
typedef struct {
	LOCAL_PARA_HDR
    MMI_BOOL   level;
}MsgCmdExtIntReq;

/*******************************************************************************
** 函数: MsgCmd_GetInteger
** 功能: 从给定长度的字符串中获取一个32位无符号整数
** 参数: ps  操作类型
**       sl  字符串长度
**       type  字符串类型
** 返回: 获取成功返回对应的值, 失败返回-1
** 作者: wasfa
*******/
U32 MsgCmd_GetInteger(const char *ps, U16 sl, StringType_e type);

/*******************************************************************************
** 函数: MsgCmd_Atoi
** 功能: 系统函数atoi的包装
** 参数: 
** 返回: 
** 作者: wasfa
*******/
S32 MsgCmd_Atoi(const char *nptr);

/*******************************************************************************
** 函数: MsgCmd_IsDigStr
** 功能: 判断是否是数字字符串, 0~9组成
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsDigStr(const char *ps, U32 sl);

/*******************************************************************************
** 函数: MsgCmd_IsXdigStr
** 功能: 判断是否是16进制字符串, 0~9, A~F, a~f组成
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsXdigStr(const char *ps, U32 sl);

/*******************************************************************************
** 函数: MsgCmd_IsXdigFmtStr
** 功能: 是否是16进制格式开头的字符串, 即以0x开头的数字字符串
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsXdigFmtStr(const char *ps, U32 sl);

/*******************************************************************************
** 函数: MsgCmd_IsAlpNumstr
** 功能: 是否是字母数字字符串
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsAlpNumStr(const char *ps, U32 sl);

/*******************************************************************************
** 函数: MsgCmd_IsAlphaStr
** 功能: 是否是字母字符串
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsAlphaStr(const char *ps, U32 sl);

/*******************************************************************************
** 函数: MsgCmd_IsSpaceStr
** 功能: 是否是空白字符串
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsSpaceStr(const char *ps, U32 sl);

/*******************************************************************************
** 函数: MsgCmd_IsLowerStr
** 功能: 是否是小写字符串
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsLowerStr(const char *ps, U32 sl);

/*******************************************************************************
** 函数: MsgCmd_IsUpperStr
** 功能: 是否是大写字符串
** 参数: 
** 返回: 
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsUpperStr(const char *ps, U32 sl);

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
char *MsgCmd_strsep(char **s, const char *ct);

/*******************************************************************************
** 函数: MsgCmd_SendIlm2Mmi
** 功能: 发送消息到MMI模块
** 参数: msgid  -- 消息ID
**       msg    -- 消息
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SendIlm2Mmi(msg_type msgid, void *msg);

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
    void *msg);

/*******************************************************************************
** 函数: MsgCmd_MemAlloc
** 功能: 申请内存, 用于大块内存申请, 必须用host_mfree_ext来释放.
** 参数: s 表示需要申请的内存字节长度.
**       v 表示将申请来的内存区间初始化为该值.
** 返回: 返回申请到的内存地址.
** 作者: wasfayu
*******/
void *MsgCmd_MemAlloc(U32 s, U8 v, const char* file, U32 line);

/*******************************************************************************
** 函数: MsgCmd_MemFree
** 功能: 释放有MsgCmd_MemAlloc申请来的内存
** 参数: memptr   表示需要释放的内存地址.
** 返回: 无
** 说明: med_free_ext_mem是个很变态的函数, 居然要取地址之后再求地址. 乏克...
** 作者: wasfayu
*******/
void MsgCmd_MemFree(void *p, const char* file, U32 line);

/*******************************************************************************
** 函数: MsgCmd_ConstructPara
** 功能: 参数构造buffer
** 参数: sz   表示需要使用的buffer大小.
** 返回: 无
** 作者: wasfayu
*******/
void *MsgCmd_ConstructPara(U32 sz);

/*******************************************************************************
** 函数: MsgCmd_DestructPara
** 功能: 参数buffer释放
** 参数: ptr   表示需要释放的参数buffer地址.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_DestructPara(void *ptr);

/*******************************************************************************
** 函数: MsgCmd_GetCallCount
** 功能: 获取电话个数
** 参数: 无
** 返回: 返回电话个数
** 作者: wasfayu
*******/
S32 MsgCmd_GetCallCount(void);

/*******************************************************************************
** 函数: MsgCmd_IsSdCardExist
** 功能: 判断存储卡是否存在
** 参数: 无
** 返回: 是否存在
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsSdCardExist(void);

/*******************************************************************************
** 函数: MsgCmd_GetDiskFreeSize
** 功能: 获取磁盘剩余空间
** 参数: drive, 磁盘盘符, 0x43~0x47
** 返回: 剩余空间的大小, byte为单位
** 作者: wasfayu
*******/
U32 MsgCmd_GetDiskFreeSize(S32 drive);

/*******************************************************************************
** 函数: MsgCmd_CheckValidDrive
** 功能: 检查给定的盘符是否已挂载
** 参数: 盘符, C/D/E/F...
** 返回: 驱动盘可供使用
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CheckValidDrive(U32 drive);

/*******************************************************************************
** 函数: MsgCmd_GetUsableDrive
** 功能: 获取系统可用的存储设备盘符
** 参数: 无
** 返回: 返回盘符 0x43~0x47
** 作者: wasfayu
*******/
S32 MsgCmd_GetUsableDrive(void);

/*******************************************************************************
** 函数: MsgCmd_GetSystemDrive
** 功能: 获取系统盘的盘符
** 参数: 无
** 返回: Success:                0x43~0x47 (A~G)
**       Error:                  RTF_PARAM_ERROR        (-2)
**                               RTF_DRIVE_NOT_FOUND    (-4)
** 作者: wasfayu
*******/
S32 MsgCmd_GetSystemDrive(void);

/*******************************************************************************
** 函数: MsgCmd_GetFileSize
** 功能: 获取文件大小
** 参数: path - 文件绝对路径
** 返回: 文件大小
** 作者: wasfayu
*******/
U32 MsgCmd_GetFileSize(WCHAR *path);

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
    const WCHAR *ext_name);

/*******************************************************************************
** 函数: MsgCmd_GetCurrentTime
** 功能: 获取系统当前的运行时间
** 参数: 无
** 返回: 运行时间
** 作者: wasfayu
*******/
U32 MsgCmd_GetCurrentTime(void);

/*******************************************************************************
** 函数: MsgCmd_GetDateTime
** 功能: 获取系统当前的时间
** 参数: 时间结构体
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_GetDateTime(applib_time_struct *t);

/*******************************************************************************
** 函数: MsgCmd_SetDateTime
** 功能: 设置系统当前的时间
** 参数: 时间结构体
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_SetDateTime(applib_time_struct *t);

/*******************************************************************************
** 函数: MsgCmd_IsDateTimeValid
** 功能: 判断时间是否有效
** 参数: t  -- 
** 返回: 是否有效
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t);

/*******************************************************************************
** 函数: MsgCmd_DeleteFileFront
** 功能: 删除文件的前部
** 入参: fullPathName -- 文件的绝对路径名, UCS格式, 如 "D:\\myfile.txt"
**       deletesz     -- 删除大小, 即从文件头开始删除deletesz个字节的数据
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_DeleteFileFront(const WCHAR *fullPathName, U32 deletesz);

/*******************************************************************************
** 函数: MsgCmd_DeleteOldFile
** 功能: 根据文件列表中的记录删除文件
** 入参: fullname   -- 录音文件的绝对路径文件名, UCS格式
**       cmpSzKB    -- 需要删除的总大小, KB
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
//S32 MsgCmd_DeleteOldFile(const WCHAR *list_file_name, U32 cmpSzKB);

/*******************************************************************************
** 函数: MsgCmd_RecordFileName
** 功能: 将某个文件的UCS格式名字pdata写入到fname文件中去
** 入参: fname   -- 文件名, UCS格式
**       pdata   -- 待写入的数据
**       datalen -- 待写入的数据长度, 字节为单位
** 返回: 是否写入成功
** 作者: wasfayu
*******/
//MMI_BOOL MsgCmd_RecordFileName(const WCHAR *fname, void *pdata, U32 datalen);

/*******************************************************************************
** 函数: MsgCmd_DelayTick
** 功能: 延时dt个tick
** 参数: dt -- 要延时的tick个数
** 返回: 无
** 说明: 一个tick大概有10ms
** 作者: wasfayu
*******/
void MsgCmd_DelayTick(U32 dt);

/*******************************************************************************
** 函数: MsgCmd_AtCmdProc
** 功能: 处理自定义AT命令
** 参数: origStr  -- AT命令行参数, 
**                   如果不是自定义的AT指令则不可破坏cmd_string中的内容
** 返回: 是否是自定义AT指令
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_AtCmdProc(char *origStr);

/*******************************************************************************
** 函数: MsgCmd_CreateAndSendMMS
** 功能: 创建并且发送MMS
** 入参: xml_path  -- MMS布局文件, 里面已经包含有电话号码这些了
**       sim       -- mma_sim_id_enum
** 返回: 是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CreateAndSendMMS(mma_sim_id_enum sim, WCHAR *xml_path);

/*******************************************************************************
** 函数: MsgCmd_CaptureEntry
** 功能: 拍照
** 参数: replay_number -- 拍照后回传照片到指定号码, 否则发送到超级号码.
** 返回: 是否拍照成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CaptureEntry(char *replay_number);

/*******************************************************************************
** 函数: MsgCmd_VdoRecdSetAppend
** 功能: 增加一段录像时间
** 参数: 无
** 返回: 返回设置是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdSetAppend(void);

/*******************************************************************************
** 函数: MsgCmd_VdoRecdBusy
** 功能: 判断是否正在录像
** 参数: 无
** 返回: 返回_TRUE表示正在录像; 返回_FALSE表示没有任何录像
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_VdoRecdBusy(void);

/*******************************************************************************
** 函数: MsgCmd_VdoRecdStop
** 功能: 停止录像录像
** 参数: replay_number -- 表示回复停止结果到指定号码, 如果为空则表示不回复
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_VdoRecdStop(char *replay_number);

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
    char    *replay_number);

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
U32 lfy_WriteFile(const WCHAR *filepath, MMI_BOOL cover, void *data, U32 length);

/*******************************************************************************
** 函数: lfy_init
** 功能: 初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void lfy_init(void);

/*******************************************************************************
** 函数: lfy_event_handler
** 功能: 系统事件响应
** 参数: 事件通知地址
** 返回: 处理结果
** 作者: LeiFaYu
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

//1. 请按'#'键进入系统.   "entry.wav"
//#define DTMF_VOC_IDX_ENTRY           1
//2. 请输入密码并按'#'键结束输入.  "pwd.wav"
//#define DTMF_VOC_IDX_PWD             2
//3. 请选择操作: 1为拍照; 2为录音; 3为录像.  "opt.wav"
//#define DTMF_VOC_IDX_CHOOSE          3
//4. 您的输入有误, 请重新输入!  "retry.wav"
//#define DTMF_VOC_IDX_RETRY           4
//5. 您的错误次数过多, 谢谢来电, 再见!   "warn.wav"
//#define DTMF_VOC_IDX_ERROR           5
//6. 您的操作请求已被接收. 谢谢来电, 再见!  "accept.wav"
//#define DTMF_VOC_IDX_RECV            6
//7. 请输入命令参数并按"#"键结束   "param.wav"
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
    DtmfStatus   state;         //当前状态
    DtmfCommand  command;       //选定的命令
    MMI_BOOL     start;
    U8           rptMax;      //最大可重复次数
    U8           rptCount;    //已重复次数
    U8           hotKey;      //热键
#if defined(__TEST_PLAY_AUDIO__)
    U8           testKey;     //测试录音文件是否可以播放
#endif
    U32          detectTime;  //检测超时时间ms
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
** 函数: Dtmf_Reset
** 功能: 参数复位
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Reset(void);

/*******************************************************************************
** 函数: Dtmf_Initialize
** 功能: 初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_Initialize(void);

/*******************************************************************************
** 函数: Dtmf_AutoAnswerReqSend
** 功能: 发送请求应答来电的消息
** 参数: name  -- 来电号码
**       number-- 显示名字
** 返回: 无
** 作者: wasfayu
*******/
void Dtmf_AutoAnswerReqSend(WCHAR *name, char *number);
#endif

#endif/*defined(__LEIFAYU__)*/

#endif/*__LFY_EXP_H__*/

