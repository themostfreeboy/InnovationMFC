// ModallessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDlg.h"
#include "ModallessDlg.h"
#include "afxdialogex.h"


// CModallessDlg 对话框

IMPLEMENT_DYNAMIC(CModallessDlg, CDialog)

CModallessDlg::CModallessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModallessDlg::IDD, pParent)
	, m_pParent(NULL)
	, m_pModallessDlg(NULL)
	, m_strRed(_T(""))
	, m_strGreen(_T(""))
	, m_strBlue(_T(""))
{
	m_pParent = pParent;
}

CModallessDlg::~CModallessDlg()
{
}

void CModallessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_RED, m_ctlSLRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_ctlSLGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_ctlSLBlue);
	DDX_Control(pDX, IDC_SPIN_RED, m_ctlSpinRed);
	DDX_Control(pDX, IDC_SPIN_GREEN, m_ctlSpinGreen);
	DDX_Control(pDX, IDC_SPIN_BLUE, m_ctlSpinBlue);
	DDX_Control(pDX, IDC_ERED, m_ctlERed);
	DDX_Text(pDX, IDC_ERED, m_strRed);
	DDX_Control(pDX, IDC_EGREEN, m_ctlEGreen);
	DDX_Text(pDX, IDC_EGREEN, m_strGreen);
	DDX_Text(pDX, IDC_EBLUE, m_strBlue);
	DDX_Control(pDX, IDC_EBLUE, m_ctlEBlue);
}


BEGIN_MESSAGE_MAP(CModallessDlg, CDialog)
	ON_WM_HSCROLL()
//	ON_EN_UPDATE(IDC_ERED, &CModallessDlg::OnBuddyUpdate)
//	ON_EN_UPDATE(IDC_EGREEN, &CModallessDlg::OnBuddyupdate)
ON_EN_UPDATE(IDC_ERED, &CModallessDlg::OnEnUpdateEred)
ON_EN_UPDATE(IDC_EGREEN, &CModallessDlg::OnEnUpdateEgreen)
ON_EN_UPDATE(IDC_EBLUE, &CModallessDlg::OnEnUpdateEblue)
ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CModallessDlg 消息处理程序


void CModallessDlg::PostNcDestroy()
{
	delete this;
}




BOOL CModallessDlg::OnInitDialog()
{
	//设置滑块的滚动范围
	m_ctlSLRed.SetRange(0, 255);
	m_ctlSLGreen.SetRange(0, 255);
	m_ctlSLBlue.SetRange(0, 255);
	//设置滑块的当前位置
	m_ctlSLRed.SetPos(128);
	m_ctlSLGreen.SetPos(128);
	m_ctlSLBlue.SetPos(128);
	//设置滑块刻度增加的频率
	m_ctlSLRed.SetTicFreq(8);
	m_ctlSLGreen.SetTicFreq(8);
	m_ctlSLBlue.SetTicFreq(8);
	//设置移动多格时改变数值的大小
	m_ctlSLRed.SetPageSize(8);
	m_ctlSLGreen.SetPageSize(8);
	m_ctlSLBlue.SetPageSize(8);
	//设置移动一格时改变数值的大小
	m_ctlSLRed.SetLineSize(1);
	m_ctlSLGreen.SetLineSize(1);
	m_ctlSLBlue.SetLineSize(1);


	//设置数值调节钮控件的伙伴窗口
	m_ctlSpinRed.SetBuddy(&m_ctlERed);
	m_ctlSpinGreen.SetBuddy(&m_ctlEGreen);
	m_ctlSpinBlue.SetBuddy(&m_ctlEBlue);
	//设置数值调节钮控件的当前位置
	m_ctlSpinRed.SetRange(0,255);
	m_ctlSpinGreen.SetRange(0, 255);
	m_ctlSpinBlue.SetRange(0, 255);
	m_ctlSpinRed.SetPos(128);
	m_ctlSpinGreen.SetPos(128);
	m_ctlSpinBlue.SetPos(128);


	//设置滚动条的滚动范围
	m_ctlSLRed.SetScrollRange(IDC_SCROLLBAR_RED,0, 255);
	m_ctlSLGreen.SetScrollRange(IDC_SCROLLBAR_GREEN,0, 255);
	m_ctlSLBlue.SetScrollRange(IDC_SCROLLBAR_BLUE,0, 255);
	//设置滚动条的当前位置
	m_ctlSLRed.SetScrollPos(IDC_SCROLLBAR_RED,128);
	m_ctlSLGreen.SetScrollPos(IDC_SCROLLBAR_GREEN, 128);
	m_ctlSLBlue.SetScrollPos(IDC_SCROLLBAR_BLUE, 128);
}


void CModallessDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	BYTE nRed, nGreen, nBlue;
	//获取滑块的当前位置
	nRed = m_ctlSLRed.GetPos();
	nGreen = m_ctlSLGreen.GetPos();
	nBlue = m_ctlSLBlue.GetPos();
	//确定需要更改颜色的对话框区域
	CRect rect(195, 35, 275, 105);
	//调用主对话框的OnChangeColor函数改变颜色
	((CMyDlgDlg*)m_pParent)->ChangeColor(rect, nRed, nGreen, nBlue);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}




void CModallessDlg::OnEnUpdateEred()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

	// TODO:  在此添加控件通知处理程序代码
	OnBuddyUpdate();
}


void CModallessDlg::OnEnUpdateEgreen()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

	// TODO:  在此添加控件通知处理程序代码
	OnBuddyUpdate();
}


void CModallessDlg::OnEnUpdateEblue()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数，以将 EM_SETEVENTMASK 消息发送到该控件，
	// 同时将 ENM_UPDATE 标志“或”运算到 lParam 掩码中。

	// TODO:  在此添加控件通知处理程序代码
	OnBuddyUpdate();
}


void CModallessDlg::OnBuddyUpdate()
{
	//获取编辑控件中的文本
	m_ctlERed.GetWindowText(m_strRed);
	m_ctlEGreen.GetWindowText(m_strGreen);
	m_ctlEBlue.GetWindowText(m_strBlue);
	//将文本字符转换为整数
	INT nRed = StringToInt(&m_strRed);
	INT nGreen = StringToInt(&m_strGreen);
	INT nBlue = StringToInt(&m_strBlue);
	//设置数值取值的有效范围
	if (nRed > 255)        nRed = 255;
	else if (nRed < 0)       nRed = 0;
	if (nGreen > 255)        nGreen = 255;
	else if (nGreen < 0)       nGreen = 0;
	if (nBlue > 255)        nBlue = 255;
	else if (nBlue < 0)       nBlue = 0;
	//指定要改变颜色的对话框区域
	CRect rect(115, 110, 195, 180);
	//调用主对话框的ChangeColoe函数改变颜色
	((CMyDlgDlg*)m_pParent)->ChangeColor(rect, nRed, nGreen, nBlue);
}


int CModallessDlg::StringToInt(CString* psInt)
{
	return _ttoi(*psInt);
}


void CModallessDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	INT nMax, nMin, nCurPos;
	nCurPos = pScrollBar->GetScrollPos();
	switch (nSBCode)
	{
	        case SB_LINEDOWN://如果按“向下”方向键
				nCurPos += 1;
				break;
			case SB_LINEUP://如果按“向上”方向键
				nCurPos -= 1;
				break;
			case SB_PAGEDOWN://如果按“PAGEDOWN”键
				nCurPos += 10;
				break;
			case SB_PAGEUP://如果按“PAGEUP”键
				nCurPos -= 10;
				break;
			case SB_THUMBTRACK://如果点击鼠标
				nCurPos = nPos;
				break;
			default:
				break;
	}
	//设置滚动条的当前位置
	pScrollBar->SetScrollPos(nCurPos);
	BYTE nRed, nGreen, nBlue;
	//将滚动条的位置当作RGB值
	nRed = m_ctlSLRed.GetScrollPos(IDC_SCROLLBAR_RED);
	nGreen = m_ctlSLGreen.GetScrollPos(IDC_SCROLLBAR_GREEN);
	nBlue = m_ctlSLBlue.GetScrollPos(IDC_SCROLLBAR_BLUE);
	//设置要改变颜色的区域
	CRect rect(275, 110, 355, 180);
	//调用主对话框的ChangeColor函数改变颜色
	((CMyDlgDlg*)m_pParent)->ChangeColor(rect, nRed, nGreen, nBlue);
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
