
#ifndef __CFGTOOLDATASTRUCT_H__
#define __CFGTOOLDATASTRUCT_H__

#if defined(__MTK_TARGET__)
#ifndef _TCHAR_DEFINED
#define _TCHAR_DEFINED
#if defined(ENCODING_LENGTH) && (ENCODING_LENGTH == 2)
/*
 * NOTE: This tests UNICODE, which is different from the _UNICODE define
 *       used to differentiate standard C runtime calls.
 */
typedef WCHAR TCHAR;
typedef WCHAR _TCHAR;
#else
typedef CHAR TCHAR;
typedef CHAR _TCHAR;
#endif
#endif
#endif


#ifndef UINT8
#define DEFINED_UINT8
#define UINT8 unsigned char
#endif
#ifndef UINT16
#define DEFINED_UINT16
#define UINT16 unsigned short int
#endif
#ifndef UINT32
#define DEFINED_UINT32
#define UINT32 unsigned int
#endif
#ifndef _TCHAR_DEFINED
#define TCHAR_DEFINED
#define TCHAR unsigned short int
#endif

#define NUMBER_LENGTH         21
#define NUMBER_LENGTH_MIN     4
#define ADMIN_NUM_TOTAL       6
#define PASSWORD_LENGTH       6
#define FILE_HEAD_FLAG        0xFFEE
#define FILE_HEAD_VER_BIG     1
#define FILE_HEAD_VER_SMALL   1
#define MODULE_IMEI_LENGTH    15

#define ADORECD_DEFAULT_AUTO_SAVE_GAP    (60*5) //SECOND
#define ADORECD_DEFAULT_MIN_SAVE_TIME    (   5) //SECOND
#define ADORECD_DEFAULT_MIN_SAVE_SIZE    (  20) //KB

#define VDORECD_DEFAULT_AUTO_SAVE_GAP    (60*5) //SECOND
#define VDORECD_DEFAULT_MIN_SAVE_TIME    (   5) //SECOND
#define VDORECD_DEFAULT_MIN_SAVE_SIZE    ( 200) //KB

typedef enum {
	_ERROR_NONE = 0,
	_HEAD_DATA_LENGTH_ERROR,
	_CONTENT_LENGTH_ERROR,
	_CONTENT_DATA_ERROR,
	_CONTENT_DATA_CRC_ERROR,
	_CONFIG_FILE_DATA_ERROR,
}ErrorCode;

typedef enum {
	PIC_SIZE_1280X960 = 0,
	PIC_SIZE_640X480,
	PIC_SIZE_480X320,
	PIC_SIZE_320X240,
}CaptureSize;

typedef enum {
	VDO_SIZE_480X320 = 0,
	VDO_SIZE_320X240,
}VideoSize;

typedef enum {
	ADO_QUALITY_HIGH = 0,
	ADO_QUALITY_LOW
}AudioQuality;

#pragma pack(1)
typedef struct {
	UINT16   flag; //存储标志, 恒定为0xFFEE, 如果读出来的值为0xEEFF表示要进行大小端转换
	UINT16   ascii; //ascii==0表示ASCII编码, 否则表示UNICODE编码
	UINT16   hVerBig;
	UINT16   hVerSmall;
	UINT32   dataPos;
	UINT32   dataLen;
	UINT32   dataCrc;
}CfgFileHeader;

typedef struct {
	UINT32   saveGap;
	UINT32   minRcrdTime;
	UINT32   minSaveSize;
}RecordSetting;

typedef struct {
	TCHAR number[NUMBER_LENGTH+1];
	UINT16 length;
}AdminNumber;

// 配置数据的结构体
typedef struct {
    UINT8        enableLogFile; //是否记录日志
	UINT8        enableDTMF;    //允许使用DTMF功能
	UINT8        captureSize;
	UINT8        videoSize;
	UINT8        audioQuality;
	UINT8        modifyPwdFlag;//是否是修改新密码
	UINT32       secFrom1970;//子1970年以来经历的秒
	AdminNumber  adminNumber[ADMIN_NUM_TOTAL];//号码列表
    TCHAR        oldPwdStr[PASSWORD_LENGTH+1];
	TCHAR        newPwdStr[PASSWORD_LENGTH+1];
	//audio record
	RecordSetting audio;
	//video record
	RecordSetting video;
	//IMEI
	TCHAR         imei[MODULE_IMEI_LENGTH+1];
}CfgDataStruct;
#pragma pack()

#define CONVER16(v) ((((v)&0xFF00)>>8)|(((v)&0x00FF)<<8)) 
#define CONVER32(v) ((((v)&0xFF000000)>>24)|(((v)&0x00FF0000)>>8)|(((v)&0x0000FF00)<<8)|(((v)&0x000000FF)<<24))


#if defined(DEFINED_UINT8)
#undef DEFINED_UINT8
#undef UINT8
#endif
#if defined(DEFINED_UINT16)
#undef DEFINED_UINT16
#undef UINT16
#endif
#if defined(DEFINED_UINT32)
#undef DEFINED_UINT32
#undef UINT32
#endif
#if defined(TCHAR_DEFINED)
#undef TCHAR
#endif

#endif/*__CFGTOOLDATASTRUCT_H__*/
