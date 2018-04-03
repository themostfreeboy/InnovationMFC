
// MyCtrlBarView.cpp : CMyCtrlBarView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyCtrlBar.h"
#endif

#include "MyCtrlBarDoc.h"
#include "MyCtrlBarView.h"
#include"MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyCtrlBarView

IMPLEMENT_DYNCREATE(CMyCtrlBarView, CView)

BEGIN_MESSAGE_MAP(CMyCtrlBarView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMyCtrlBarView 构造/析构

CMyCtrlBarView::CMyCtrlBarView()
{
	// TODO:  在此处添加构造代码

}

CMyCtrlBarView::~CMyCtrlBarView()
{
}

BOOL CMyCtrlBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyCtrlBarView 绘制

void CMyCtrlBarView::OnDraw(CDC* /*pDC*/)
{
	CMyCtrlBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMyCtrlBarView 打印

BOOL CMyCtrlBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyCtrlBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMyCtrlBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMyCtrlBarView 诊断

#ifdef _DEBUG
void CMyCtrlBarView::AssertValid() const
{
	CView::AssertValid();
}

void CMyCtrlBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyCtrlBarDoc* CMyCtrlBarView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCtrlBarDoc)));
	return (CMyCtrlBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyCtrlBarView 消息处理程序


void CMyCtrlBarView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString str;
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	str.Format("X=%d", point.x);
	pFrame->m_wndStatusBar.SetPaneText(1, str);
	str.Format("Y=%d",point.y);
	pFrame->m_wndStatusBar.SetPaneText(2, str);
	CView::OnMouseMove(nFlags, point);
}
