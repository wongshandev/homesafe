/*******************************************************************************
 *
 * msgcmd_process.h
 *
 * 对外提供录像/录音/拍照/回复短信/回复彩信的接口函数
 *
 * (@_@)
 *
 * wasfayu      -- 20130716, 创建原始版本
 *
 ******************************************************************************/

#ifndef __MSGCMD_PROCESS_H__
#define __MSGCMD_PROCESS_H__


#if defined(__MSGCMD_SUPPORT__)
#include "./ws_main.h"
#include "gdi_datatype.h"
#include "app_datetime.h"
#include "SmsSrvGprot.h"
#include "mma_struct.h"
#include "ucsrvgprot.h"
#include "umsrvdefs.h"

/* 系统默认值 */
#define MSGCMD_FILE_PATH_LENGTH   127
#define MSGCMD_FILE_NAME_LENGTH   63

/* 延迟时间TICK，一个TICK大约10ms */
#define MSGCMD_CAPTURE_DLY_TICK  (1)
#define MSGCMD_ADORECD_DLY_TICK  (1)
#define MSGCMD_VDORECD_DLY_TICK  (10)

/* 定时器ID定义 */
enum msgcmd_timer_id_enum{
//最大值为 MSGCMD_TIMER_BASE
	MSGCMD_TIMER_REBOOT       = MSGCMD_TIMER_BASE,
	MSGCMD_TIMER_SHUTDOWN     ,
	MSGCMD_TIMER_FACTORY      ,
	MSGCMD_TIMER_INT_RECHECK  ,
};

/* 消息ID定义 */
enum msgcmd_msg_id_enum{
//最大值为 MSG_ID_MC_END
	MSG_ID_MC_VDORECD_REQ     = MSG_ID_MC_BASE,
	MSG_ID_MC_ADORECD_REQ     ,
	MSG_ID_MC_CAPTURE_REQ     ,
	MSG_ID_MC_SEND_MMS_REQ    ,
	MSG_ID_MC_EXT_INTERRUPT   ,
	MSG_ID_MC_CONT_RECD_VDO   ,
};

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
    U32           time;          //unit: second, 总的录制时间
    U32           saveGap;       //unit: second, 自动保存间隔
    U32           timeCount;     //unit: second, 当前已经录制的时间
    MMI_BOOL      forever;       //是否无限时录制
    MMI_BOOL      append;        //是否追加一次saveGap时长的录制
    MMI_BOOL      stop;          //是否停止录制
    gdi_handle    dispLayer;     //OSD层句柄
    VdoRecdStatus status;        //当前状态
}VdoRecdMngr;

/* 录音状态枚举 */
typedef enum {
    ADO_STATUS_IDLE,
    ADO_STATUS_RECODING,
    ADO_STATUS_PAUSE,
    ADO_STATUS_SAVING,
    ADO_STATUS_MAX
}AdoRecdStatus;

/* 录音状态管理 */
typedef struct {
    WCHAR         filepath[MSGCMD_FILE_PATH_LENGTH+1]; //文件绝对路径
    char          number[MAX_PHONENUMBER_LENTH+1];
    U32           time;    //unit: second
    U32           saveGap; //unit: second
    MMI_BOOL      forever; //是否无限时录制
    MMI_BOOL      append;  //是否追加一次saveGap时长的录制
    AdoRecdStatus status;  //当前状态
}AdoRecdMngr;


#define MSGCMD_PHOTOS_FOLDER_NAME   L"Photos"
#define MSGCMD_AUDIOS_FOLDER_NAME   L"Audios"
#define MSGCMD_VIDEOS_FOLDER_NAME   L"Videos"

#define MSGCMD_ADO_LIST_FILE_NAME   L"AdoFiles.lst"
#define MSGCMD_VDO_LIST_FILE_NAME   L"VdoFiles.lst"

//执行录音/录像需要检查磁盘空间的剩余量
#define MSGCMD_ADO_FREE_SPACE_REQUIRE_KB   (1024*5)  //5MB
#define MSGCMD_VDO_FREE_SPACE_REQUIRE_KB   (1024*15) //15MB

//因磁盘空间不足, 需要删除的文件的最低值
#define MSGCMD_ADO_DELETE_SIZE_KB     (1024*1)    //1MB
#define MSGCMD_VDO_DELETE_SIZE_KB     (1024*3)    //3MB


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
** 作者: wasfayu
*******/
U32 MsgCmd_GetInteger(const char *ps, U16 sl, StringType_e type);

/*******************************************************************************
** 函数: MsgCmd_Atoi
** 功能: 系统函数atoi的包装
** 参数: 
** 返回: 
** 作者: wasfayu
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
** 参数: 
** 返回: 返回盘符 0x43~0x47
** 作者: wasfayu
*******/
S32 MsgCmd_GetUsableDrive(void);

/*******************************************************************************
** 函数: MsgCmd_GetTFcardDrive
** 功能: 判断T卡是否存在并返回T卡的盘符
** 参数: litter -- 输出盘符
** 返回: 存在或者不存在
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_GetTFcardDrive(S32 *litter);

/*******************************************************************************
** 函数: MsgCmd_GetSystemDrive
** 功能: 获取系统盘的盘符
** 参数: 
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
** 参数: 
** 返回: 是否有效
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t);

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
** 函数: MsgCmd_GetSimIndex
** 功能: 获取设备使用的SIM卡ID
** 参数: 无
** 返回: 索引值, 仅0或者1
** 作者: wasfayu
*******/
U8 MsgCmd_GetSimIndex(void);

/*******************************************************************************
** 函数: MsgCmd_MemAlloc
** 功能: 申请内存, 用于大块内存申请, 必须用host_mfree_ext来释放.
** 参数: s 表示需要申请的内存字节长度.
**       v 表示将申请来的内存区间初始化为该值.
** 返回: 返回申请到的内存地址.
** 作者: wasfayu
*******/
void *MsgCmd_MemAlloc(U32 s, U8 v, const char* file, U32 line);
#define MsgCmd_Malloc(s, v) MsgCmd_MemAlloc(s, v, __FUNCTION__, __LINE__)

/*******************************************************************************
** 函数: MsgCmd_MemFree
** 功能: 释放有MsgCmd_MemAlloc申请来的内存
** 参数: memptr   表示需要释放的内存地址.
** 返回: 无
** 说明: med_free_ext_mem是个很变态的函数, 居然要取地址之后再求地址. 乏克...
** 作者: wasfayu
*******/
void MsgCmd_MemFree(void *p, const char* file, U32 line);
#define MsgCmd_Mfree(p) MsgCmd_MemFree(p, __FUNCTION__, __LINE__)

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
** 函数: MsgCmd_Reboot
** 功能: 重启
** 入参: 
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_Reboot(void);

/*******************************************************************************
** 函数: MsgCmd_RebootAcitved
** 功能: 判断延时重启的定时器是否已经启动
** 入参: 无
** 返回: 定时器是否已激活
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_RebootAcitved(void);

/*******************************************************************************
** 函数: MsgCmd_RebootExt
** 功能: 延时重启
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_RebootExt(U16 delayS);

/*******************************************************************************
** 函数: MsgCmd_Shutdown
** 功能: 关机
** 入参: 
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_Shutdown(void);

/*******************************************************************************
** 函数: MsgCmd_ShutdownAcitved
** 功能: 判断延时关机的定时器是否已经启动
** 入参: 无
** 返回: 定时器是否已激活
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_ShutdownAcitved(void);

/*******************************************************************************
** 函数: MsgCmd_ShutdownExt
** 功能: 延时关机
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_ShutdownExt(U16 delayS);

/*******************************************************************************
** 函数: MsgCmd_Factory
** 功能: 关机
** 入参: 
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_Factory(void);

/*******************************************************************************
** 函数: MsgCmd_FactoryExt
** 功能: 延时关机
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_FactoryExt(U16 delayS);

/*******************************************************************************
** 函数: MsgCmd_DeleteFileFront
** 功能: 删除文件的前部
** 入参: fname   -- 文件名, UCS格式
**       deletesz -- 删除大小, 即从文件头开始删除deletesz个字节的数据
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_DeleteFileFront(const WCHAR *fname, U32 deletesz);

/*******************************************************************************
** 函数: msgcmd_WriteImeiRsp
** 功能: 拨打指定号码
** 参数: pnumber -- 指定呼叫号码
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_MakeCall(char *pnumber);

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
MMI_BOOL MsgCmd_WriteImei(char *num, U16 strl, U8 sim, U8 (*rsp)(void*));

/*******************************************************************************
** 函数: MsgCmd_CreatePath
** 功能: 创建一级深度的路径
** 参数: drive   -- 盘符
**       folder  -- 文件夹名字
** 返回: 是否创建成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CreatePath(S32 drive, const WCHAR *folder);

/*******************************************************************************
** 函数: MsgCmd_InterruptMask
** 功能: 屏蔽/打开外部中断
** 参数: mask  -- 屏蔽
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_InterruptMask(MMI_BOOL mask);

/*******************************************************************************
** 函数: MsgCmd_InterruptRegister
** 功能: 外部中断注册, 必须在多任务初始化的时候就注册, 
**       否则会在EINT_LISR里面"ASSERT(EINT_FUNC[index].eint_func!=NULL);"
** 参数: void
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_InterruptRegister(void);

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
    SrvSmsCallbackFunc cb);

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
    WCHAR          *xml_path);

/*******************************************************************************
** 函数: MsgCmd_DeleteOldFile
** 功能: 根据文件列表中的记录删除文件
** 入参: fullname   -- 录音文件的绝对路径文件名, UCS格式
**       cmpSzKB    -- 需要删除的总大小, 以KB为单位
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
S32 MsgCmd_DeleteOldFile(const WCHAR *list_file_name, U32 cmpSzKB);

/*******************************************************************************
** 函数: MsgCmd_RecordFileName
** 功能: 将某个文件的UCS格式名字pdata写入到fname文件中去
** 入参: fname   -- 文件名, UCS格式
**       pdata   -- 待写入的数据
**       datalen -- 待写入的数据长度, 字节为单位
** 返回: 是否写入成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_RecordFileName(const WCHAR *fname, void *pdata, U32 datalen);

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
** 函数: MsgCmd_EvtProcEntry
** 功能: 响应系统事件
** 参数: evp -- 事件通知数据地址
** 返回: 事件处理结果
** 作者: wasfayu
*******/
mmi_ret MsgCmd_EvtProcEntry(mmi_event_struct *evp);

/*******************************************************************************
** 函数: MsgCmd_AdoRecdGetContext
** 功能: 获取录音管理变量的地址
** 参数: 无
** 返回: 返回管理变量的地址
** 作者: wasfayu
*******/
AdoRecdMngr *MsgCmd_AdoRecdGetContext(void);

/*******************************************************************************
** 函数: MsgCmd_AdoRecdSetAppend
** 功能: 增加一段录音时间
** 参数: 无
** 返回: 返回设置是否成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdSetAppend(void);

/*******************************************************************************
** 函数: MsgCmd_AdoRecdBusy
** 功能: 判断是否正在录音
** 参数: 无
** 返回: 返回_TRUE表示正在录音; 返回_FALSE表示没有任何录音
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_AdoRecdBusy(void);

/*******************************************************************************
** 函数: MsgCmd_AdoRecdStop
** 功能: 停止录像录音
** 参数: replay_number -- 表示回复启动结果到指定号码, 如果为空则表示不回复
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_AdoRecdStop(char *replay_number);

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
    char    *replay_number);

/*******************************************************************************
** 函数: MsgCmd_CaptureEntry
** 功能: 拍照
** 参数: replay_number -- 拍照后回传照片到指定号码, 否则发送到超级号码.
** 返回: 是否拍照成功
** 作者: wasfayu
*******/
MMI_BOOL MsgCmd_CaptureEntry(char *replay_number);

/*******************************************************************************
** 函数: MsgCmd_VdoRecdGetContext
** 功能: 获取录像管理变量的地址
** 参数: 无
** 返回: 返回管理变量的地址
** 作者: wasfayu
*******/
VdoRecdMngr *MsgCmd_VdoRecdGetContext(void);

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
** 函数: MsgCmd_ProcessInit
** 功能: 开机初始化
** 参数: 无
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_ProcessInit(void);

#endif/*__MSGCMD_SUPPORT__*/


#endif/*__MSGCMD_PROCESS_H__*/

