
// ChildFrm.cpp : CChildFrame 类的实现
//

#include "stdafx.h"
#include "ListCtrlTest.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	//ON_WM_PAINT()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CChildFrame 构造/析构

CChildFrame::CChildFrame()
{
	// TODO:  在此添加成员初始化代码
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	//cs.dwExStyle |= WS_EX_CLIENTEDGE;
	//cs.style &= ~WS_BORDER;
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		//::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);
	//cs.cx = 1024;
	//cs.cy = 768;

	return TRUE;
}

// CChildFrame 诊断

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame 消息处理程序
int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	MessageBox(_T("OnCreateBegin"), NULL, MB_OK);
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	//GetWindowRect(&rect);
	listCtrl.CreateEx(LVS_EX_GRIDLINES, WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT, rect, this, 1);
	//listCtrl.Create(LVS_EX_FLATSB | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES, rect, this, 123);
	listCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	listCtrl.SetBkColor(RGB(237, 250, 254));
	listCtrl.SetTextBkColor(RGB(0, 255, 0));
	listCtrl.SetTextColor(RGB(0, 0, 255));
	listCtrl.InsertColumn(0, _T("Hello"), LVCFMT_LEFT, 50);
	UpdateData(FALSE);
	MessageBox(_T("OnCreateEnd"), NULL, MB_OK);
	//listCtrl.Invalidate(TRUE);
	//CChildFrame::UpdateAllViews(this);
	//CChildFrame::Invalidate(TRUE);
	return 0;
}

void CChildFrame::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文

	// TODO: 在此处添加消息处理程序代码
	CRect   rect;
	GetClientRect(&rect);
	listCtrl.MoveWindow(&rect);

	// 不要为绘制消息而调用 CWnd::OnPaint()
}