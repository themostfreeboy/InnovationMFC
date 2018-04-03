
// AnalysisView.cpp : CAnalysisView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Analysis.h"
#endif

#include "AnalysisDoc.h"
#include "AnalysisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnalysisView

IMPLEMENT_DYNCREATE(CAnalysisView, CListView)

BEGIN_MESSAGE_MAP(CAnalysisView, CListView)
	//ON_WM_PAINT()
	ON_WM_CREATE()
	//ON_COMMAND(ID_FILE_OPEN, &CAnalysisView::OnFileOpen)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CAnalysisView 构造/析构

CAnalysisView::CAnalysisView()
{
	// TODO:  在此处添加构造代码

}

CAnalysisView::~CAnalysisView()
{
}

BOOL CAnalysisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void CAnalysisView::OnInitialUpdate()
{
	MessageBox(_T("OnInitialUpdateBegin"), _T("OnInitialUpdateBegin"), MB_OK);
	CListView::OnInitialUpdate();


	// TODO:  调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
	CListView::OnInitialUpdate();
	//CAnalysisDoc* pDoc = GetDocument();
	//CListCtrl* pListCtrl = &GetListCtrl();
	CListCtrl* pListCtrl = &listCtrl;
	pListCtrl->SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	pListCtrl->InsertColumn(0, _T("error"), LVCFMT_LEFT, 100);

	UpdateData(FALSE);
	MessageBox(_T("OnInitialUpdateEnd"), _T("OnInitialUpdateEnd"), MB_OK);
	
}

void CAnalysisView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAnalysisView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAnalysisView 诊断

#ifdef _DEBUG
void CAnalysisView::AssertValid() const
{
	CListView::AssertValid();
}

void CAnalysisView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CAnalysisDoc* CAnalysisView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnalysisDoc)));
	return (CAnalysisDoc*)m_pDocument;
}
#endif //_DEBUG


// CAnalysisView 消息处理程序
int CAnalysisView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	MessageBox(_T("OnCreateBegin"), _T("OnCreateBegin"), MB_OK);
	CRect rect;
	GetClientRect(&rect);
	listCtrl.CreateEx(LVS_EX_GRIDLINES, WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT, rect, this, 123);
	listCtrl.SetBkColor(RGB(237, 250, 254));
	listCtrl.SetTextBkColor(RGB(0, 255, 0));
	listCtrl.SetTextColor(RGB(0, 0, 255));
	listCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	CreateListColumns();
	
	UpdateData(FALSE);
	MessageBox(_T("OnCreateEnd"), _T("OnCreateEnd"), MB_OK);
	return 0;
}


void CAnalysisView::CreateListColumns(void)
{
	MessageBox(_T("CreateListColumnsBegin"), _T("CreateListColumnsBegin"), MB_OK);
	LV_COLUMN lvColumn;
	//Column 0 
	lvColumn.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT | LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.iSubItem = 0;
	lvColumn.pszText = _T("序号");
	listCtrl.InsertColumn(0, &lvColumn);

	//Column 1 
	lvColumn.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT | LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_RIGHT;
	lvColumn.cx = 200;
	lvColumn.iSubItem = 1;
	lvColumn.pszText = _T("时间/s");
	listCtrl.InsertColumn(1, &lvColumn);

	//Column 2 
	lvColumn.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT | LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_RIGHT;
	lvColumn.cx = 200;
	lvColumn.iSubItem = 2;
	lvColumn.pszText = _T("力量/kgf");
	listCtrl.InsertColumn(2, &lvColumn);

	UpdateData(FALSE);
	MessageBox(_T("CreateListColumnsEnd"), _T("CreateListColumnsEnd"), MB_OK);
}
