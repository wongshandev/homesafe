// CfgToolDlg.h : 头文件
//

#pragma once

#define NUMBER_LENGTH         21
#define ADMIN_NUM_TOTAL       6
#define PASSWORD_LENGTH       6
#define FILE_HEAD_FLAG        0xFFEE
#define FILE_HEAD_VER_BIG     1
#define FILE_HEAD_VER_SMALL   1

#define ADORECD_DEFAULT_AUTO_SAVE_GAP    (60*5) //SECOND
#define ADORECD_DEFAULT_MIN_SAVE_TIME    (   5) //SECOND
#define ADORECD_DEFAULT_MIN_SAVE_SIZE    (  20) //KB

#define VDORECD_DEFAULT_AUTO_SAVE_GAP    (60*5) //SECOND
#define VDORECD_DEFAULT_MIN_SAVE_TIME    (   5) //SECOND
#define VDORECD_DEFAULT_MIN_SAVE_SIZE    ( 200) //KB


// 系统具有的功能
typedef enum {
	MODULE_ADO_VDO_RECD = 0,
    MODULE_ONLY_ADORECD,
	MODULE_ONLY_VDORECD,
	MODULE_UNDEFINED,
}ModuleFeature;

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
	UINT8        modFunction; //模块功能定义
	AdminNumber  adminNumber[ADMIN_NUM_TOTAL];//号码列表
    TCHAR        oldPwdStr[PASSWORD_LENGTH+1];
	TCHAR        newPwdStr[PASSWORD_LENGTH+1];
	//audio record
	RecordSetting audio;
	//video record
	RecordSetting video;
}CfgDataStruct;
#pragma pack()

// CCfgToolDlg 对话框
class CCfgToolDlg : public CDialog
{
// 构造
public:
	CCfgToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CFGTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	BOOL PreTranslateMessage(MSG* pMsg);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	CfgFileHeader fHead;
    CfgDataStruct fContent;
	int numNidSet[ADMIN_NUM_TOTAL];

	afx_msg void OnBtnLoadClicked();
	afx_msg void OnBtnSaveClicked();

	afx_msg void OnRadioBothAdoVdoClicked(){this->fContent.modFunction = MODULE_ADO_VDO_RECD;};
	afx_msg void OnRadioOnlyAdoClicked(){this->fContent.modFunction = MODULE_ONLY_ADORECD;};
	afx_msg void OnRadioOnlyVdoClicked(){this->fContent.modFunction = MODULE_ONLY_VDORECD;};

	afx_msg void OnCheckEnableLogFileClicked(){this->fContent.enableLogFile = !this->fContent.enableLogFile;};
	afx_msg void OnCheckEnableDtmfClicked(){this->fContent.enableDTMF = !this->fContent.enableDTMF;};

	afx_msg void OnRadioCaptureSize1280x960Clicked(){this->fContent.captureSize = PIC_SIZE_1280X960;};
	afx_msg void OnRadioCaptureSize640x480Clicked(){this->fContent.captureSize = PIC_SIZE_640X480;};
	afx_msg void OnRadioCaptureSize480x320Clicked(){this->fContent.captureSize = PIC_SIZE_480X320;};
	afx_msg void OnRadioCaptureSize320x240Clicked(){this->fContent.captureSize = PIC_SIZE_320X240;};

	afx_msg void OnRadioVideoSize480x320Clicked(){this->fContent.videoSize = VDO_SIZE_480X320;};
	afx_msg void OnRadioVideoSize320x240Clicked(){this->fContent.videoSize = VDO_SIZE_320X240;};

	afx_msg void OnRadioAudioQualityHighClicked(){this->fContent.audioQuality = ADO_QUALITY_HIGH;};
	afx_msg void OnRadioAudioQualityLowClicked(){this->fContent.audioQuality = ADO_QUALITY_LOW;};

	BOOL SaveConfigData2File(CFile &in);
	BOOL LoadConfigData2File(CFile &out);

	void UpdateDisplay(void);
};

UINT32 applib_crc_update(UINT32 CRCAccum, UINT8 *Data_p, UINT16 DataBlkSize);
#define CONVER16(v) ((((v)&0xFF00)>>8)|(((v)&0x00FF)<<8)) 
#define CONVER32(v) ((((v)&0xFF000000)>>24)|(((v)&0x00FF0000)>>8)|(((v)&0x0000FF00)<<8)|(((v)&0x000000FF)<<24))