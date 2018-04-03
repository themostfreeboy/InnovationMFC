// ModalDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDlg.h"
#include "ModalDlg.h"
#include "afxdialogex.h"


// CModalDlg 对话框

IMPLEMENT_DYNAMIC(CModalDlg, CDialog)

CModalDlg::CModalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModalDlg::IDD, pParent)
	, m_strLess(_T(""))
	, m_strMore(_T(""))
	, m_strPgmName(_T(""))
	, m_bEnableLeft(FALSE)
	, m_bEnableRight(FALSE)
	, m_bIsHide(FALSE)
{

}

CModalDlg::~CModalDlg()
{
}

void CModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LESS, m_strLess);
	DDX_Text(pDX, IDC_MORE, m_strMore);
	DDX_LBIndex(pDX, IDC_LRECVD, m_ctlRecvd);
	DDX_CBString(pDX, IDC_CBPROGRAM, m_strPgmName);
	DDX_Control(pDX, IDC_BNICON, m_IconBN);
	DDX_Control(pDX, IDC_BNBMP, m_BmpBN);
	DDX_Check(pDX, IDC_CLEFT, m_bEnableLeft);
	DDX_Check(pDX, IDC_CRIGHT, m_bEnableRight);
	DDX_Radio(pDX, IDC_RSHOW, m_bIsHide);
}


BEGIN_MESSAGE_MAP(CModalDlg, CDialog)
	ON_EN_CHANGE(IDC_LESS, &CModalDlg::OnEnChangeLess)
	ON_BN_CLICKED(IDC_BADD, &CModalDlg::OnBnClickedBadd)
	ON_BN_CLICKED(IDC_BRUNPROGRAM, &CModalDlg::OnBnClickedBrunprogram)
	ON_BN_CLICKED(IDC_CLEFT, &CModalDlg::OnBnClickedCleft)
	ON_BN_CLICKED(IDC_CRIGHT, &CModalDlg::OnBnClickedCright)
	ON_BN_CLICKED(IDC_RSHOW, &CModalDlg::OnBnClickedRshow)
END_MESSAGE_MAP()


// CModalDlg 消息处理程序


void CModalDlg::OnEnChangeLess()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);//更新代码数据
	m_strMore =(CString) ":)" + m_strLess;
	UpdateData(FALSE);//更新控件信息
}


void CModalDlg::OnBnClickedBadd()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_ctlRecvd.AddString(m_strMore);
	UpdateData(FALSE);
}


void CModalDlg::OnBnClickedBrunprogram()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString strPgmName;
	strPgmName = m_strPgmName;
	if (strPgmName == "画图")
		WinExec("mspaint.exe", SW_SHOW);
	if (strPgmName == "记事本")
		WinExec("notepad.exe", SW_SHOW);
	if (strPgmName == "纸牌")
		WinExec("sol.exe", SW_SHOW);
	if (strPgmName == "扫雷")
		WinExec("winmine.exe", SW_SHOW);
}




void CModalDlg::OnBnClickedCleft()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_bEnableLeft == TRUE)
	{
		GetDlgItem(IDC_LESS)->EnableWindow(TRUE);
		GetDlgItem(IDC_MORE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BADD)->EnableWindow(TRUE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_LESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_MORE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BADD)->EnableWindow(FALSE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(FALSE);
	}
}


void CModalDlg::OnBnClickedCright()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_bEnableRight == TRUE)
	{
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_SICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_SBMP)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_SICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_SBMP)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(FALSE);
	}
}


void CModalDlg::OnBnClickedRshow()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_bIsHide == FALSE)
	{
		//显示模式对话框中的控件
		GetDlgItem(IDC_LESS)->EnableWindow(TRUE);
		GetDlgItem(IDC_MORE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BADD)->EnableWindow(TRUE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(TRUE);
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_SICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_SBMP)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(TRUE);
	}
	else
	{
		//隐藏模式对话框中的控件
		GetDlgItem(IDC_LESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_MORE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BADD)->EnableWindow(FALSE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(FALSE);
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_SICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_SBMP)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(FALSE);
	}
}


BOOL CModalDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//添加图标
	HICON hIcon = AfxGetApp()->LoadIconW(IDR_MAINFRAME);
	m_IconBN.SetIcon(hIcon);
	//添加位图
	HBITMAP hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_BNBMP/*IDB_BITMPBUTTON*/));
	m_BmpBN.SetBitmap(hBitmap);

	m_bEnableLeft = TRUE;
	m_bEnableRight = TRUE;

	return TRUE;
}
