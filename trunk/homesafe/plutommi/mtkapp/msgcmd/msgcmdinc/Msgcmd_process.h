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


#if defined(__MESSAGE_COMMAND_SUPPORT__)
#include "app_datetime.h"
#include "SmsSrvGprot.h"

#include "msgcmd_datatype.h"


#ifndef mc_trace
#define mc_trace(fmt, ...) kal_prompt_trace(0, fmt, __VA_ARGS__)
#endif



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


/*******************************************************************************
** 函数: MsgCmd_GetInteger
** 功能: 从给定长度的字符串中获取一个32位无符号整数
** 参数: ps  操作类型
**       sl  字符串长度
**       type  字符串类型
** 返回: 获取成功返回对应的值, 失败返回-1
** 作者: wasfa
*******/
INT32U MsgCmd_GetInteger(const CHAR *ps, INT16U sl, StringType_e type);

/*******************************************************************************
** 函数: MsgCmd_Atoi
** 功能: 系统函数atoi的包装
** 参数: 
** 返回: 
** 作者: wasfa
*******/
INT32S MsgCmd_Atoi(const CHAR *nptr);

/*******************************************************************************
** 函数: MsgCmd_IsDigStr
** 功能: 判断是否是数字字符串, 0~9组成
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsDigStr(const CHAR *ps, INT32U sl);

/*******************************************************************************
** 函数: MsgCmd_IsXdigStr
** 功能: 判断是否是16进制字符串, 0~9, A~F, a~f组成
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsXdigStr(const CHAR *ps, INT32U sl);

/*******************************************************************************
** 函数: MsgCmd_IsXdigFmtStr
** 功能: 是否是16进制格式开头的字符串, 即以0x开头的数字字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsXdigFmtStr(const CHAR *ps, INT32U sl);

/*******************************************************************************
** 函数: MsgCmd_IsAlpNumstr
** 功能: 是否是字母数字字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsAlpNumStr(const CHAR *ps, INT32U sl);

/*******************************************************************************
** 函数: MsgCmd_IsAlphaStr
** 功能: 是否是字母字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsAlphaStr(const CHAR *ps, INT32U sl);

/*******************************************************************************
** 函数: MsgCmd_IsSpaceStr
** 功能: 是否是空白字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsSpaceStr(const CHAR *ps, INT32U sl);

/*******************************************************************************
** 函数: MsgCmd_IsLowerStr
** 功能: 是否是小写字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsLowerStr(const CHAR *ps, INT32U sl);

/*******************************************************************************
** 函数: MsgCmd_IsUpperStr
** 功能: 是否是大写字符串
** 参数: 
** 返回: 
** 作者: wasfa
*******/
_BOOL MsgCmd_IsUpperStr(const CHAR *ps, INT32U sl);

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
CHAR *MsgCmd_strsep(CHAR **s, const CHAR *ct);

/*******************************************************************************
** 函数: MsgCmd_GetDiskFreeSize
** 功能: 获取磁盘剩余空间
** 参数: drive, 磁盘盘符, 0x43~0x47
** 返回: 剩余空间的大小, byte为单位
** 作者: wasfayu
*******/
INT32U MsgCmd_GetDiskFreeSize(INT32S drive);

/*******************************************************************************
** 函数: MsgCmd_GetUsableDrive
** 功能: 获取系统可用的存储设备盘符
** 参数: 
** 返回: 返回盘符 0x43~0x47
** 作者: wasfayu
*******/
INT32S MsgCmd_GetUsableDrive(void);

/*******************************************************************************
** 函数: MsgCmd_GetSystemDrive
** 功能: 获取系统盘的盘符
** 参数: 
** 返回: Success:                0x43~0x47 (A~G)
**       Error:                  RTF_PARAM_ERROR        (-2)
**                               RTF_DRIVE_NOT_FOUND    (-4)
** 作者: wasfayu
*******/
INT32S MsgCmd_GetSystemDrive(void);

/*******************************************************************************
** 函数: MsgCmd_GetFileSize
** 功能: 获取文件大小
** 参数: path - 文件绝对路径
** 返回: 文件大小
** 作者: wasfayu
*******/
INT32U MsgCmd_GetFileSize(const WCHAR *path);

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
    CHAR *out,
    INT16U length,
    const WCHAR *folder,
    const WCHAR *ext_name);

/*******************************************************************************
** 函数: MsgCmd_GetCurrentTime
** 功能: 获取系统当前的运行时间
** 参数: 无
** 返回: 运行时间
** 作者: wasfayu
*******/
INT32U MsgCmd_GetCurrentTime(void);

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
_BOOL MsgCmd_IsDateTimeValid(applib_time_struct *t);

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
void *MsgCmd_MemAlloc(INT32U s, INT8U v, const CHAR* file, INT32U line);
#define MsgCmd_Malloc(s, v) MsgCmd_MemAlloc(s, v, __FUNCTION__, __LINE__)

/*******************************************************************************
** 函数: MsgCmd_MemFree
** 功能: 释放有MsgCmd_MemAlloc申请来的内存
** 参数: memptr   表示需要释放的内存地址.
** 返回: 无
** 说明: med_free_ext_mem是个很变态的函数, 居然要取地址之后再求地址. 乏克...
** 作者: wasfayu
*******/
void MsgCmd_MemFree(void *p, const CHAR* file, INT32U line);
#define MsgCmd_Mfree(p) MsgCmd_MemFree(p, __FUNCTION__, __LINE__)

/*******************************************************************************
** 函数: MsgCmd_ConstructPara
** 功能: 参数构造buffer
** 参数: sz   表示需要使用的buffer大小.
** 返回: 无
** 作者: wasfayu
*******/
void *MsgCmd_ConstructPara(INT32U sz);

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
** 函数: MsgCmd_RebootExt
** 功能: 延时重启
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_RebootExt(INT16U delayS);

/*******************************************************************************
** 函数: MsgCmd_Shutdown
** 功能: 关机
** 入参: 
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_Shutdown(void);

/*******************************************************************************
** 函数: MsgCmd_ShutdownExt
** 功能: 延时关机
** 入参: delayS - 延时多少秒钟, 最大30分钟延时.
** 返回: 无
** 作者: wasfayu
*******/
void MsgCmd_ShutdownExt(INT16U delayS);

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
void MsgCmd_FactoryExt(INT16U delayS);

/*******************************************************************************
** 函数: MsgCmd_DeleteFileFront
** 功能: 删除文件的前部
** 入参: fname   -- 文件名, UCS格式
**       deletesz -- 删除大小, 即从文件头开始删除deletesz个字节的数据
** 返回: 函数执行是否正常
** 作者: wasfayu
*******/
_BOOL MsgCmd_DeleteFileFront(const WCHAR *fname, INT32U deletesz);

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
_BOOL MsgCmd_WriteImei(CHAR *num, INT16U strl, INT8U sim, INT8U (*rsp)(void*));

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
_BOOL MsgCmd_SendSms(
    CHAR   *to_asc_number,
    INT8S  *ucs_text_ptr,
    INT16U  length_in_byte,
    void   *user_data_ptr,
    srv_sms_sim_enum sim,
    SrvSmsCallbackFunc cb);


#endif/*__MESSAGE_COMMAND_SUPPORT__*/


#endif/*__MSGCMD_PROCESS_H__*/

