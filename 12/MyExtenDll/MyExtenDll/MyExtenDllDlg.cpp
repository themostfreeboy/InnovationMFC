
// MyExtenDllDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyExtenDll.h"
#include "MyExtenDllDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyExtenDllDlg 对话框



CMyExtenDllDlg::CMyExtenDllDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyExtenDllDlg::IDD, pParent)
	, m_strInput(_T(""))
	, m_strOutput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyExtenDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EINPUT, m_strInput);
	DDX_Text(pDX, IDC_EOUTPUT, m_strOutput);
}

BEGIN_MESSAGE_MAP(CMyExtenDllDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BZERO, IDC_BDOT, OnBnClickedNumber)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BLOG, IDC_BCLEAR, OnBnClickedOperator)
END_MESSAGE_MAP()


// CMyExtenDllDlg 消息处理程序

BOOL CMyExtenDllDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyExtenDllDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyExtenDllDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyExtenDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyExtenDllDlg::OnBnClickedNumber(UINT nID)
{
	UpdateData(TRUE);
	switch (nID)
	{
	case IDC_BZERO:m_strInput += "0"; break;
	case IDC_BONE:m_strInput += "1"; break;
	case IDC_BTWO:m_strInput += "2"; break;
	case IDC_BTHREE:m_strInput += "3"; break;
	case IDC_BFOUR:m_strInput += "4"; break;
	case IDC_BFIVE:m_strInput += "5"; break;
	case IDC_BSIX:m_strInput += "6"; break;
	case IDC_BSEVEN:m_strInput += "7"; break;
	case IDC_BEIGHT:m_strInput += "8"; break;
	case IDC_BNINE:m_strInput += "9"; break;
	case IDC_BDOT:m_strInput += "."; break;
	default:break;
	}
	UpdateData(FALSE);
}



void CMyExtenDllDlg::OnBnClickedOperator(UINT nID)
{
	UpdateData(TRUE);
	m_nData = _wtof(m_strInput);//CString转double
	CMyCompute* m_pCompute = new CMyCompute(m_nData);
	switch (nID)
	{
	case IDC_BLOG://对数运算
		m_nResult = m_pCompute->MyLog();
		break;
	case IDC_BSQUARE://平方运算
		m_nResult = m_pCompute->MySquare();
		break;
	case IDC_BCUBE://立方运算
		m_nResult = m_pCompute->MyCube();
		break;
	case IDC_BSQRT://开根号运算
		m_nResult = m_pCompute->MySqrt();
		break;
	case IDC_BCLEAR://清除输入
	    m_strInput = m_strOutput=_T("");
		UpdateData(FALSE);
		break;
	}
	//设置输出窗口中的文本
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EOUTPUT);
	char buffer[200];
	sprintf_s(buffer, "%f", m_nResult);//double转char*
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	pEdit->SetWindowText(wszClassName1);
}