
// MyDlgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDlg.h"
#include "MyDlgDlg.h"
#include "ModalDlg.h"
#include "ModallessDlg.h"
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


// CMyDlgDlg 对话框



CMyDlgDlg::CMyDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDlgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BMODAL, &CMyDlgDlg::OnBnClickedBmodal)
	ON_BN_CLICKED(IDC_BMODALLESS, &CMyDlgDlg::OnBnClickedBmodalless)
	ON_BN_CLICKED(IDOK, &CMyDlgDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMyDlgDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMyDlgDlg 消息处理程序

BOOL CMyDlgDlg::OnInitDialog()
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

void CMyDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlgDlg::OnPaint()
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
HCURSOR CMyDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMyDlgDlg::OnBnClickedBmodal()
{
	// TODO:  在此添加控件通知处理程序代码
	CModalDlg dlg;
	dlg.DoModal();
}


void CMyDlgDlg::OnBnClickedBmodalless()
{
	// TODO:  在此添加控件通知处理程序代码
	if (!m_pModallessDlg)                                    //测试无模式对话框是否被销毁
	{                                                       //如果没有无模式对话框的指针，则创建一个
		m_pModallessDlg = new CModallessDlg(this);
		if (m_pModallessDlg->Creat(IDD_MODALLESS_DIALOG, NULL) == TRUE)
			GetDlgItem(IDC_BMODALLESS)->EnableWindow(FALSE);//禁用“无模式对话框按钮”
	}
	m_pModallessDlg->ShowWindow(SW_SHOW);
}


void CMyDlgDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	((CMyDlgDlg*)m_pParent)->BoxDone();
	DestroyWindow();
}


void CMyDlgDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnCancel();
	((CMyDlgDlg*)m_pParent)->BoxDone();
	DestroyWindow();
}




void CMyDlgDlg::BoxDone()
{
	m_pModallessDlg = NULL;                        //注意，这里没有删除无模式对话框的指针
	GetDlgItem(IDC_BMODALLESS)->EnableWindow(TRUE);//激活按钮
}


void CMyDlgDlg::ChangeColor(CRect rect, int red, int blue, int green)
{
	int nRed, nGreen, nBlue;
	nRed = red;
	nGreen = green;
	nBlue = blue;
	CBrush br(RGB(nRed, nGreen, nBlue));
	CRect rectNow = rect;
	GetDC()->FillRect(&rectNow, &br);//使用指定画刷填充指定区域
}
