// CfgToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CfgTool.h"
#include "CfgToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
//计算CRC32, 参考MTK平台app_crc.c文件中的代码
UINT32 applib_crc_update(UINT32 CRCAccum, UINT8 *Data_p, UINT16 DataBlkSize)
{
	const UINT32 g_applib_crc_table[256] = 
	{
		0x00000000L, 0x04C11DB7L, 0x09823B6EL, 0x0D4326D9L, 0x130476DCL,
		0x17C56B6BL, 0x1A864DB2L, 0x1E475005L, 0x2608EDB8L, 0x22C9F00FL,
		0x2F8AD6D6L, 0x2B4BCB61L, 0x350C9B64L, 0x31CD86D3L, 0x3C8EA00AL,
		0x384FBDBDL, 0x4C11DB70L, 0x48D0C6C7L, 0x4593E01EL, 0x4152FDA9L,
		0x5F15ADACL, 0x5BD4B01BL, 0x569796C2L, 0x52568B75L, 0x6A1936C8L,
		0x6ED82B7FL, 0x639B0DA6L, 0x675A1011L, 0x791D4014L, 0x7DDC5DA3L,
		0x709F7B7AL, 0x745E66CDL, 0x9823B6E0L, 0x9CE2AB57L, 0x91A18D8EL,
		0x95609039L, 0x8B27C03CL, 0x8FE6DD8BL, 0x82A5FB52L, 0x8664E6E5L,
		0xBE2B5B58L, 0xBAEA46EFL, 0xB7A96036L, 0xB3687D81L, 0xAD2F2D84L,
		0xA9EE3033L, 0xA4AD16EAL, 0xA06C0B5DL, 0xD4326D90L, 0xD0F37027L,
		0xDDB056FEL, 0xD9714B49L, 0xC7361B4CL, 0xC3F706FBL, 0xCEB42022L,
		0xCA753D95L, 0xF23A8028L, 0xF6FB9D9FL, 0xFBB8BB46L, 0xFF79A6F1L,
		0xE13EF6F4L, 0xE5FFEB43L, 0xE8BCCD9AL, 0xEC7DD02DL, 0x34867077L,
		0x30476DC0L, 0x3D044B19L, 0x39C556AEL, 0x278206ABL, 0x23431B1CL,
		0x2E003DC5L, 0x2AC12072L, 0x128E9DCFL, 0x164F8078L, 0x1B0CA6A1L,
		0x1FCDBB16L, 0x018AEB13L, 0x054BF6A4L, 0x0808D07DL, 0x0CC9CDCAL,
		0x7897AB07L, 0x7C56B6B0L, 0x71159069L, 0x75D48DDEL, 0x6B93DDDBL,
		0x6F52C06CL, 0x6211E6B5L, 0x66D0FB02L, 0x5E9F46BFL, 0x5A5E5B08L,
		0x571D7DD1L, 0x53DC6066L, 0x4D9B3063L, 0x495A2DD4L, 0x44190B0DL,
		0x40D816BAL, 0xACA5C697L, 0xA864DB20L, 0xA527FDF9L, 0xA1E6E04EL,
		0xBFA1B04BL, 0xBB60ADFCL, 0xB6238B25L, 0xB2E29692L, 0x8AAD2B2FL,
		0x8E6C3698L, 0x832F1041L, 0x87EE0DF6L, 0x99A95DF3L, 0x9D684044L,
		0x902B669DL, 0x94EA7B2AL, 0xE0B41DE7L, 0xE4750050L, 0xE9362689L,
		0xEDF73B3EL, 0xF3B06B3BL, 0xF771768CL, 0xFA325055L, 0xFEF34DE2L,
		0xC6BCF05FL, 0xC27DEDE8L, 0xCF3ECB31L, 0xCBFFD686L, 0xD5B88683L,
		0xD1799B34L, 0xDC3ABDEDL, 0xD8FBA05AL, 0x690CE0EEL, 0x6DCDFD59L,
		0x608EDB80L, 0x644FC637L, 0x7A089632L, 0x7EC98B85L, 0x738AAD5CL,
		0x774BB0EBL, 0x4F040D56L, 0x4BC510E1L, 0x46863638L, 0x42472B8FL,
		0x5C007B8AL, 0x58C1663DL, 0x558240E4L, 0x51435D53L, 0x251D3B9EL,
		0x21DC2629L, 0x2C9F00F0L, 0x285E1D47L, 0x36194D42L, 0x32D850F5L,
		0x3F9B762CL, 0x3B5A6B9BL, 0x0315D626L, 0x07D4CB91L, 0x0A97ED48L,
		0x0E56F0FFL, 0x1011A0FAL, 0x14D0BD4DL, 0x19939B94L, 0x1D528623L,
		0xF12F560EL, 0xF5EE4BB9L, 0xF8AD6D60L, 0xFC6C70D7L, 0xE22B20D2L,
		0xE6EA3D65L, 0xEBA91BBCL, 0xEF68060BL, 0xD727BBB6L, 0xD3E6A601L,
		0xDEA580D8L, 0xDA649D6FL, 0xC423CD6AL, 0xC0E2D0DDL, 0xCDA1F604L,
		0xC960EBB3L, 0xBD3E8D7EL, 0xB9FF90C9L, 0xB4BCB610L, 0xB07DABA7L,
		0xAE3AFBA2L, 0xAAFBE615L, 0xA7B8C0CCL, 0xA379DD7BL, 0x9B3660C6L,
		0x9FF77D71L, 0x92B45BA8L, 0x9675461FL, 0x8832161AL, 0x8CF30BADL,
		0x81B02D74L, 0x857130C3L, 0x5D8A9099L, 0x594B8D2EL, 0x5408ABF7L,
		0x50C9B640L, 0x4E8EE645L, 0x4A4FFBF2L, 0x470CDD2BL, 0x43CDC09CL,
		0x7B827D21L, 0x7F436096L, 0x7200464FL, 0x76C15BF8L, 0x68860BFDL,
		0x6C47164AL, 0x61043093L, 0x65C52D24L, 0x119B4BE9L, 0x155A565EL,
		0x18197087L, 0x1CD86D30L, 0x029F3D35L, 0x065E2082L, 0x0B1D065BL,
		0x0FDC1BECL, 0x3793A651L, 0x3352BBE6L, 0x3E119D3FL, 0x3AD08088L,
		0x2497D08DL, 0x2056CD3AL, 0x2D15EBE3L, 0x29D4F654L, 0xC5A92679L,
		0xC1683BCEL, 0xCC2B1D17L, 0xC8EA00A0L, 0xD6AD50A5L, 0xD26C4D12L,
		0xDF2F6BCBL, 0xDBEE767CL, 0xE3A1CBC1L, 0xE760D676L, 0xEA23F0AFL,
		0xEEE2ED18L, 0xF0A5BD1DL, 0xF464A0AAL, 0xF9278673L, 0xFDE69BC4L,
		0x89B8FD09L, 0x8D79E0BEL, 0x803AC667L, 0x84FBDBD0L, 0x9ABC8BD5L,
		0x9E7D9662L, 0x933EB0BBL, 0x97FFAD0CL, 0xAFB010B1L, 0xAB710D06L,
		0xA6322BDFL, 0xA2F33668L, 0xBCB4666DL, 0xB8757BDAL, 0xB5365D03L,
		0xB1F740B4
	};
	register UINT16 i, j;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (j = 0; j < DataBlkSize; j++)
	{
		i = ((UINT16) (CRCAccum >> 24) ^ *Data_p++) & 0xff;
		CRCAccum = (CRCAccum << 8) ^ g_applib_crc_table[i];
	}
	return ~CRCAccum;
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCfgToolDlg 对话框




CCfgToolDlg::CCfgToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCfgToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCfgToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADO_SAVE_GAP, this->fContent.audio.saveGap);
	DDX_Text(pDX, IDC_EDIT_ADO_SAVE_SIZE, this->fContent.audio.minSaveSize);
	DDX_Text(pDX, IDC_EDIT_VDO_SAVE_GAP, this->fContent.video.saveGap);
	DDX_Text(pDX, IDC_EDIT_VDO_SAVE_SIZE, this->fContent.video.minSaveSize);
	DDX_Control(pDX, IDC_DATE, m_date);
	DDX_Control(pDX, IDC_TIME, m_time);
}

BEGIN_MESSAGE_MAP(CCfgToolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOAD, &CCfgToolDlg::OnBtnLoadClicked)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CCfgToolDlg::OnBtnSaveClicked)


	ON_BN_CLICKED(IDC_CHECK_ENABLE_LOG,   &CCfgToolDlg::OnCheckEnableLogFileClicked)
	ON_BN_CLICKED(IDC_CHECK_ENABLE_DTMF,   &CCfgToolDlg::OnCheckEnableDtmfClicked)
	ON_BN_CLICKED(IDC_CHECK_NEW_PWD, &CCfgToolDlg::OnCheckEnableNewPwdClicked)

	ON_BN_CLICKED(IDC_RDO_PIC_1280X960,  &CCfgToolDlg::OnRadioCaptureSize1280x960Clicked)
	ON_BN_CLICKED(IDC_RDO_PIC_640X480,  &CCfgToolDlg::OnRadioCaptureSize640x480Clicked)
	ON_BN_CLICKED(IDC_RDO_PIC_480X320,  &CCfgToolDlg::OnRadioCaptureSize480x320Clicked)
	ON_BN_CLICKED(IDC_RDO_PIC_320X240,  &CCfgToolDlg::OnRadioCaptureSize320x240Clicked)

	ON_BN_CLICKED(IDC_RDO_VDO_480X320,  &CCfgToolDlg::OnRadioVideoSize480x320Clicked)
	ON_BN_CLICKED(IDC_RDO_VDO_320X240,  &CCfgToolDlg::OnRadioVideoSize320x240Clicked)

	ON_BN_CLICKED(IDC_RDO_ADO_HIGH,  &CCfgToolDlg::OnRadioAudioQualityHighClicked)
	ON_BN_CLICKED(IDC_RDO_ADO_LOW,  &CCfgToolDlg::OnRadioAudioQualityLowClicked)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CCfgToolDlg 消息处理程序

BOOL CCfgToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	memset((void*)&this->fContent, 0, sizeof(CfgDataStruct));
	memset((void*)&this->fHead,    0, sizeof(CfgFileHeader));
	// 初始化号码输入框
	this->numNidSet[0] = IDC_EDIT_NUM_1;
	this->numNidSet[1] = IDC_EDIT_NUM_2;
	this->numNidSet[2] = IDC_EDIT_NUM_3;
	this->numNidSet[3] = IDC_EDIT_NUM_4;
	this->numNidSet[4] = IDC_EDIT_NUM_5;
	this->numNidSet[5] = IDC_EDIT_NUM_6;
	for (UINT32 i=0; i<ADMIN_NUM_TOTAL; i++)
	{
		((CEdit*)this->GetDlgItem(this->numNidSet[i]))->SetLimitText(NUMBER_LENGTH);
	}

	//IMEI是15位数字
	((CEdit*)this->GetDlgItem(IDC_EDIT_IMEI))->SetLimitText(MODULE_IMEI_LENGTH);
	//密码是6位可见ASCII字符
	((CEdit*)this->GetDlgItem(IDC_EDIT_OLD_PWD))->SetLimitText(PASSWORD_LENGTH);
	((CEdit*)this->GetDlgItem(IDC_EDIT_NEW_PWD))->SetLimitText(PASSWORD_LENGTH);

	// enable log file
	this->fContent.enableLogFile = FALSE;
	// enable DTMF
	this->fContent.enableDTMF = TRUE;
	// audio quality
	this->fContent.audioQuality = ADO_QUALITY_HIGH;
	// video size
	this->fContent.videoSize    = VDO_SIZE_480X320;
	// capture size
	this->fContent.captureSize  = PIC_SIZE_640X480;
	//禁止使用新密码
	this->fContent.modifyPwdFlag = FALSE;

	//CString cs;
	//audio save gap
	this->fContent.audio.saveGap = ADORECD_DEFAULT_AUTO_SAVE_GAP;
	//audio save size
	this->fContent.audio.minSaveSize = ADORECD_DEFAULT_MIN_SAVE_SIZE;
	//video save gap
	this->fContent.video.saveGap = VDORECD_DEFAULT_AUTO_SAVE_GAP;
	//video save size
	this->fContent.video.minSaveSize = VDORECD_DEFAULT_MIN_SAVE_SIZE;

	this->UpdateDisplay();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCfgToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCfgToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCfgToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCfgToolDlg::UpdateDisplay(void)
{
	// 更新号码输入框
	CString cs;

	for (int i=0; i<ADMIN_NUM_TOTAL; i++)
	{
		if (this->fContent.adminNumber[i].length)
		{
			this->SetDlgItemText(this->numNidSet[i], this->fContent.adminNumber[i].number);
		}
	}

	// enable log file
	this->CheckDlgButton(IDC_CHECK_ENABLE_LOG, this->fContent.enableLogFile);
	// enable DTMF
	this->CheckDlgButton(IDC_CHECK_ENABLE_DTMF, this->fContent.enableDTMF);
	//old password
	this->SetDlgItemText(IDC_EDIT_OLD_PWD, this->fContent.oldPwdStr);
	// new password
	if (this->fContent.modifyPwdFlag)
	{
		this->CheckDlgButton(IDC_CHECK_NEW_PWD, TRUE);
		(this->GetDlgItem(IDC_EDIT_NEW_PWD))->EnableWindow(TRUE);
		this->SetDlgItemText(IDC_EDIT_NEW_PWD, this->fContent.newPwdStr);
	}
	else
	{
		this->SetDlgItemText(IDC_EDIT_NEW_PWD, _T(""));
		this->CheckDlgButton(IDC_CHECK_NEW_PWD, FALSE);
		(this->GetDlgItem(IDC_EDIT_NEW_PWD))->EnableWindow(FALSE);
	}

	//IMEI
	this->SetDlgItemText(IDC_EDIT_IMEI, this->fContent.imei);

	// audio quality
	this->CheckDlgButton(IDC_RDO_ADO_HIGH, this->fContent.audioQuality==ADO_QUALITY_HIGH);
	this->CheckDlgButton(IDC_RDO_ADO_LOW, this->fContent.audioQuality==ADO_QUALITY_LOW);
	// video size
	this->CheckDlgButton(IDC_RDO_VDO_480X320, this->fContent.videoSize==VDO_SIZE_480X320);
	this->CheckDlgButton(IDC_RDO_VDO_320X240, this->fContent.videoSize==VDO_SIZE_320X240);
	// capture size
	this->CheckDlgButton(IDC_RDO_PIC_1280X960, this->fContent.captureSize==PIC_SIZE_1280X960);
	this->CheckDlgButton(IDC_RDO_PIC_640X480, this->fContent.captureSize==PIC_SIZE_640X480);
	this->CheckDlgButton(IDC_RDO_PIC_480X320, this->fContent.captureSize==PIC_SIZE_480X320);
	this->CheckDlgButton(IDC_RDO_PIC_320X240, this->fContent.captureSize==PIC_SIZE_320X240);
	//audio save gap
	cs.Format(_T("%d"), this->fContent.audio.saveGap);
	this->SetDlgItemText(IDC_EDIT_ADO_SAVE_GAP, cs);
	//audio save size
	cs.Format(_T("%d"), this->fContent.audio.minSaveSize);
	this->SetDlgItemText(IDC_EDIT_ADO_SAVE_SIZE, cs);
	//video save gap
	cs.Format(_T("%d"), this->fContent.video.saveGap);
	this->SetDlgItemText(IDC_EDIT_VDO_SAVE_GAP, cs);
	//video save size
	cs.Format(_T("%d"), this->fContent.video.minSaveSize);
	this->SetDlgItemText(IDC_EDIT_VDO_SAVE_SIZE, cs);
}

void CCfgToolDlg::OnBtnLoadClicked()
{
	TCHAR *fileFilter = _T("config file (*.bin)|*.bin");

	CFileDialog fileDlg(TRUE, _T("bin"), NULL, 0, fileFilter, this);
	CString filepath;

	if (IDOK == fileDlg.DoModal())   
	{   
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		filepath = fileDlg.GetPathName();

		CFile loadf(filepath, CFile::shareDenyRead);

		//弹出选择预加载文件的对话框
		if (0 == this->LoadConfigData2File(loadf))
		{
			UpdateData(FALSE);
			this->UpdateDisplay();
		}
		else
		{
			AfxMessageBox(_T("Load data file failed!"));
		}

		loadf.Close();
	}
}

void CCfgToolDlg::OnBtnSaveClicked()
{
	UpdateData(TRUE);
	if (this->fContent.audio.saveGap < 10 ||
		this->fContent.audio.saveGap > (60*20) ||
		this->fContent.audio.minSaveSize < 5 ||
		this->fContent.audio.minSaveSize > (1024*5))
	{
		AfxMessageBox(_T("Value error!\r\n10S < Audio save gap <= 1200S\r\n5KB < Audio min save size <= 5120KB"));
		return;
	}

	if (this->fContent.video.saveGap < 10 ||
		this->fContent.video.saveGap > (60*20) ||
		this->fContent.video.minSaveSize < 100 ||
		this->fContent.video.minSaveSize > (1024*50))
	{
		AfxMessageBox(_T("Value error!\r\n10S < Video save gap <= 1200S\r\n100KB < Video min save size <= 51200KB"));
		return;
	}

	TCHAR *fileFilter = _T("config file (*.bin)|*.bin");

	CFileDialog fileDlg(FALSE, _T("bin"), _T("config"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, fileFilter, this);
	CString filepath;

	if (IDOK == fileDlg.DoModal())   
	{ 
        CString cs;

		//超级号码
		for (int i=0; i<ADMIN_NUM_TOTAL; i++)
		{
			this->GetDlgItemText(this->numNidSet[i], cs);
			this->fContent.adminNumber[i].length = cs.GetLength();
			if (cs.GetLength())
			{
				if (NUMBER_LENGTH_MIN > cs.GetLength() || NUMBER_LENGTH < cs.GetLength())
				{
					cs.Format(_T("Admin NO.%d length error!"), i+1);
					AfxMessageBox(cs);
					break;
				}

				memcpy(this->fContent.adminNumber[i].number, cs.GetBuffer(), sizeof(TCHAR)*cs.GetLength());
			}
		}

		//date
		CTime time;
		m_date.GetTime(time);
		//time
		m_time.GetTime(time);
		//转换成秒


		//密码
		this->GetDlgItemText(IDC_EDIT_OLD_PWD, cs);
		if (cs.GetLength() && cs.GetLength() <= PASSWORD_LENGTH)
		{
			memcpy(this->fContent.oldPwdStr, cs.GetBuffer(), sizeof(TCHAR)*cs.GetLength());
		}
		else
		{
			AfxMessageBox(_T("System password length error!"));
		}
		//新密码
		if (this->fContent.modifyPwdFlag)
		{
			this->GetDlgItemText(IDC_EDIT_NEW_PWD, cs);
			if (cs.GetLength() && cs.GetLength() <= PASSWORD_LENGTH)
			{
				memcpy(this->fContent.newPwdStr, cs.GetBuffer(), sizeof(TCHAR)*cs.GetLength());
			}
			else
			{
				AfxMessageBox(_T("New password length error!"));
			}
		}

		//IMEI
		this->GetDlgItemText(IDC_EDIT_IMEI, cs);
		if (cs.GetLength() && cs.GetLength() != MODULE_IMEI_LENGTH)
		{
			AfxMessageBox(_T("IMEI length error!"));
		}
		else if (cs.GetLength() == MODULE_IMEI_LENGTH)
		{
			memcpy(this->fContent.imei, cs.GetBuffer(), sizeof(TCHAR)*cs.GetLength());
		}
		
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		filepath = fileDlg.GetPathName();

		CFile savef(filepath, CFile::modeCreate|CFile::modeWrite);

		if (0 != this->SaveConfigData2File(savef))
		{
			AfxMessageBox(_T("Save data failed!"));
		}

		savef.Close();
	}
}

void CCfgToolDlg::OnCheckEnableNewPwdClicked()
{
	this->fContent.modifyPwdFlag = !this->fContent.modifyPwdFlag;
	this->CheckDlgButton(IDC_CHECK_NEW_PWD, this->fContent.modifyPwdFlag);
	(this->GetDlgItem(IDC_EDIT_NEW_PWD))->EnableWindow(this->fContent.modifyPwdFlag);
}

BOOL CCfgToolDlg::PreTranslateMessage(MSG* pMsg)
{
	if( pMsg->message == WM_CHAR)
	{
		CWnd *pcwnd = FromHandle(pMsg->hwnd);

		for (int i=0; i<ADMIN_NUM_TOTAL; i++)
		if (this->GetDlgItem(this->numNidSet[i]) == pcwnd)
		{
			//如果当前输入框为号码编辑框且光标定位在第一个字符位置,
			if (pMsg->wParam == '+' || (pMsg->wParam <= '9' && pMsg->wParam >= '0'))
				return FALSE;
			else if (pMsg->wParam >= ' ' && pMsg->wParam <= '~' || pMsg->wParam == '\t' || pMsg->wParam == '\r' || pMsg->wParam == '\n')
				return TRUE;
			//else
			//	return TRUE;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);;
}

INT32 CCfgToolDlg::SaveConfigData2File(CFile &recdf)
{
	//获取号码输入框里面的数据，判断是否正常
	this->fHead.flag = FILE_HEAD_FLAG;
	this->fHead.hVerBig = FILE_HEAD_VER_BIG;
	this->fHead.hVerSmall = FILE_HEAD_VER_SMALL;

	this->fHead.dataLen = sizeof(CfgDataStruct);
	this->fHead.dataPos = sizeof(CfgFileHeader);
	this->fHead.dataCrc = applib_crc_update(0, (UINT8*)&this->fContent, this->fHead.dataLen);

#if define (_TCHAR_DEFINED) && defined(UNICODE)
	this->fHead.ascii = 1;
#else
	this->fHead.ascii = 0;
#endif

	recdf.SeekToBegin();
	recdf.Write((const void*)&this->fHead, sizeof(CfgFileHeader));

	recdf.Seek((LONGLONG)this->fHead.dataPos, CFile::begin);
	recdf.Write((const void *)&this->fContent, this->fHead.dataLen);
	
	return 0;
}

INT32 CCfgToolDlg::LoadConfigData2File(CFile &out)
{
	BOOL conver;

	out.SeekToBegin();
	if (sizeof(CfgFileHeader) != out.Read((void*)&this->fHead, sizeof(CfgFileHeader)))
	{
		return _HEAD_DATA_LENGTH_ERROR;
	}

	if (this->fHead.flag == CONVER16(FILE_HEAD_FLAG) ||
		this->fHead.flag == FILE_HEAD_FLAG)
	{
		conver = (BOOL)(this->fHead.flag != FILE_HEAD_FLAG);

		if (conver)
		{
			/* 将数据头中中的数据进行转换 */
			CONVER32(this->fHead.dataLen);
			CONVER16(this->fHead.flag);
			CONVER16(this->fHead.hVerBig);
			CONVER16(this->fHead.hVerSmall);
			CONVER32(this->fHead.dataPos);
			CONVER32(this->fHead.dataCrc);	
		}

		if (this->fHead.dataLen != sizeof(CfgDataStruct))
		{
			return _CONTENT_DATA_ERROR;
		}

		if (this->fHead.dataPos + sizeof(CfgDataStruct) > out.GetLength())
		{
			return _CONTENT_DATA_ERROR;
		}

		out.Seek((LONGLONG)this->fHead.dataPos, CFile::begin);
		if (this->fHead.dataLen != out.Read((void*)&this->fContent, this->fHead.dataLen))
		{
			return _CONTENT_LENGTH_ERROR;
		}

		if (conver)
		{
			CfgDataStruct *cntx = &this->fContent;

			/* 将数据进行转换 */
			CONVER32(cntx->audio.minRcrdTime);
			CONVER32(cntx->audio.minSaveSize);
			CONVER32(cntx->audio.saveGap);
			CONVER32(cntx->video.minRcrdTime);
			CONVER32(cntx->video.minSaveSize);
			CONVER32(cntx->video.saveGap);
		}

		//检查CRC错误没
		UINT32 crc = applib_crc_update(0, (UINT8*)&this->fContent, this->fHead.dataLen);
		if (crc != this->fHead.dataCrc)
		{
			return _CONTENT_DATA_CRC_ERROR;
		}
	} 
	else
	{
		/* 文件异常报错 */
		return _CONFIG_FILE_DATA_ERROR;
	}

	return 0;
}

