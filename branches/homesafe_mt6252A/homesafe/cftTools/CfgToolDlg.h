// CfgToolDlg.h : 头文件
//

#pragma once
#include "afxdtctl.h"
#include "CfgToolDataStruct.h"



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

	//点击new password
	afx_msg void OnCheckEnableNewPwdClicked();

	INT32 SaveConfigData2File(CFile &in);
	INT32 LoadConfigData2File(CFile &out);

	void UpdateDisplay(void);
public:
	// 系统日期
	CDateTimeCtrl m_date;
	// 系统时间
	CDateTimeCtrl m_time;
};

//CRC32
UINT32 applib_crc_update(UINT32 CRCAccum, UINT8 *Data_p, UINT16 DataBlkSize);
