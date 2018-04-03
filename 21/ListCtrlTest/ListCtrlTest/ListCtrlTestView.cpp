
// ListCtrlTestView.cpp : CListCtrlTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ListCtrlTest.h"
#endif

#include "ListCtrlTestDoc.h"
#include "ListCtrlTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListCtrlTestView

IMPLEMENT_DYNCREATE(CListCtrlTestView, CListView)

BEGIN_MESSAGE_MAP(CListCtrlTestView, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//ON_WM_PAINT()
	//ON_WM_CREATE()
END_MESSAGE_MAP()

// CListCtrlTestView 构造/析构

CListCtrlTestView::CListCtrlTestView()
{
	// TODO:  在此处添加构造代码

}

CListCtrlTestView::~CListCtrlTestView()
{
}

BOOL CListCtrlTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void CListCtrlTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO:  调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
	//listCtrl.DeleteAllItems();
	
}

void CListCtrlTestView::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文

	// TODO: 在此处添加消息处理程序代码
	CRect   rect;
	GetClientRect(&rect);
	listCtrl.MoveWindow(&rect);

	// 不要为绘制消息而调用 CWnd::OnPaint()
}

void CListCtrlTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CListCtrlTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CListCtrlTestView 诊断

#ifdef _DEBUG
void CListCtrlTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CListCtrlTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListCtrlTestDoc* CListCtrlTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListCtrlTestDoc)));
	return (CListCtrlTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CListCtrlTestView 消息处理程序
/*
int CListCtrlTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	MessageBox(_T("OnCreateBegin"),NULL,MB_OK);
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	listCtrl.CreateEx(LVS_EX_GRIDLINES, WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT, rect, this, 1);
	//listCtrl.Create(LVS_EX_FLATSB | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES, rect, this, 123);
	listCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	listCtrl.SetBkColor(RGB(237, 250, 254));
	listCtrl.SetTextBkColor(RGB(0, 255, 0));
	listCtrl.SetTextColor(RGB(0, 0, 255));
	listCtrl.InsertColumn(0, _T("error"), LVCFMT_LEFT, 50);
	//UpdateData(FALSE);
	MessageBox(_T("OnCreateEnd"), NULL, MB_OK);
	return 0;
}
*/