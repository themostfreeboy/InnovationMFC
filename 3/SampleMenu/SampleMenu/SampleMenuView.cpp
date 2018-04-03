
// SampleMenuView.cpp : CSampleMenuView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "SampleMenu.h"
#endif

#include "SampleMenuDoc.h"
#include "SampleMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleMenuView

IMPLEMENT_DYNCREATE(CSampleMenuView, CView)

BEGIN_MESSAGE_MAP(CSampleMenuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSampleMenuView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MYMENU_MORNING, &CSampleMenuView::OnMymenuMorning)
	ON_COMMAND(ID_MYMENU_EVENING, &CSampleMenuView::OnMymenuEvening)
	ON_COMMAND(ID_MYMENU_DRAWING, &CSampleMenuView::OnMymenuDrawing)
END_MESSAGE_MAP()

// CSampleMenuView 构造/析构

CSampleMenuView::CSampleMenuView()
: m_nColor(0)
{
	// TODO:  在此处添加构造代码

}

CSampleMenuView::~CSampleMenuView()
{
}

BOOL CSampleMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSampleMenuView 绘制

void CSampleMenuView::OnDraw(CDC* pDC)
{
	CSampleMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	pDC->SelectStockObject(m_nColor);
	pDC->Ellipse(CRect(0, 0, 200, 200));
}


// CSampleMenuView 打印


void CSampleMenuView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSampleMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSampleMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CSampleMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CSampleMenuView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSampleMenuView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	CMenu menu;
	menu.LoadMenu(IDR_CONTEXT_MENU);
	GetCursorPos(&point);
	CMenu* pContextMenu = menu.GetSubMenu(0);
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	menu.DestroyMenu();
}


// CSampleMenuView 诊断

#ifdef _DEBUG
void CSampleMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleMenuDoc* CSampleMenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleMenuDoc)));
	return (CSampleMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CSampleMenuView 消息处理程序


void CSampleMenuView::OnMymenuMorning()
{
	// TODO:  在此添加命令处理程序代码
	char* szStr1 = "Good Moring,Sir";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));

	char* szStr2 = "Hey";
	WCHAR wszClassName2[256];
	memset(wszClassName2, 0, sizeof(wszClassName2));
	MultiByteToWideChar(CP_ACP, 0, szStr2, strlen(szStr2) + 1, wszClassName2, sizeof(wszClassName2) / sizeof(wszClassName2[0]));

	MessageBox(wszClassName1, wszClassName2, MB_OKCANCEL);
}


void CSampleMenuView::OnMymenuEvening()
{
	// TODO:  在此添加命令处理程序代码
	char* szStr1 = "Good Evening,Miss Rose";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));

	char* szStr2 = "OH";
	WCHAR wszClassName2[256];
	memset(wszClassName2, 0, sizeof(wszClassName2));
	MultiByteToWideChar(CP_ACP, 0, szStr2, strlen(szStr2) + 1, wszClassName2, sizeof(wszClassName2) / sizeof(wszClassName2[0]));

	MessageBox(wszClassName1, wszClassName2, MB_OKCANCEL);
}


void CSampleMenuView::OnMymenuDrawing()
{
	// TODO:  在此添加命令处理程序代码
	m_nColor = GRAY_BRUSH;
	Invalidate(TRUE);
}
