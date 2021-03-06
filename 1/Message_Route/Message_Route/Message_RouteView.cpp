
// Message_RouteView.cpp : CMessage_RouteView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Message_Route.h"
#endif

#include "Message_RouteDoc.h"
#include "Message_RouteView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMessage_RouteView

IMPLEMENT_DYNCREATE(CMessage_RouteView, CView)

BEGIN_MESSAGE_MAP(CMessage_RouteView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMessage_RouteView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMessage_RouteView 构造/析构

CMessage_RouteView::CMessage_RouteView()
{
	// TODO:  在此处添加构造代码

}

CMessage_RouteView::~CMessage_RouteView()
{
}

BOOL CMessage_RouteView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMessage_RouteView 绘制

void CMessage_RouteView::OnDraw(CDC* /*pDC*/)
{
	CMessage_RouteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMessage_RouteView 打印


void CMessage_RouteView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMessage_RouteView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMessage_RouteView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMessage_RouteView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CMessage_RouteView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMessage_RouteView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMessage_RouteView 诊断

#ifdef _DEBUG
void CMessage_RouteView::AssertValid() const
{
	CView::AssertValid();
}

void CMessage_RouteView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessage_RouteDoc* CMessage_RouteView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessage_RouteDoc)));
	return (CMessage_RouteDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessage_RouteView 消息处理程序
