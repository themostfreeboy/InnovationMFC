
// MyPropView.cpp : CMyPropView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyProp.h"
#endif

#include "MyPropDoc.h"
#include "MyPropView.h"
#include "PropPg1.h"
#include "PropPg2.h"
#include "MyPropSheet.h"
#include "WizPg1.h"
#include "WizPg2.h"
#include "WizPg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyPropView

IMPLEMENT_DYNCREATE(CMyPropView, CView)

BEGIN_MESSAGE_MAP(CMyPropView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMyPropView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_COMMON_PROP, &CMyPropView::OnViewCommonProp)
	ON_COMMAND(ID_WIZ_PROP, &CMyPropView::OnViewWizProp)
END_MESSAGE_MAP()

// CMyPropView 构造/析构

CMyPropView::CMyPropView()
{
	// TODO:  在此处添加构造代码

}

CMyPropView::~CMyPropView()
{
}

BOOL CMyPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyPropView 绘制

void CMyPropView::OnDraw(CDC* /*pDC*/)
{
	CMyPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMyPropView 打印


void CMyPropView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMyPropView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyPropView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMyPropView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CMyPropView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMyPropView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMyPropView 诊断

#ifdef _DEBUG
void CMyPropView::AssertValid() const
{
	CView::AssertValid();
}

void CMyPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyPropDoc* CMyPropView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyPropDoc)));
	return (CMyPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyPropView 消息处理程序


void CMyPropView::OnViewCommonProp()
{
	// TODO:  在此添加命令处理程序代码
	char* szStr1 = "定制属性表";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	CMyPropSheet sheet(wszClassName1);
	CPropPg1 page1;
	CPropPg2 page2;
	sheet.AddPage(&page1);
	sheet.AddPage(&page2);
	sheet.DoModal();
}


void CMyPropView::OnViewWizProp()
{
	// TODO:  在此添加命令处理程序代码
	CPropertySheet wiz;
	CWizPg1 page1;
	CWizPg2 page2;
	CWizPg3 page3;
	wiz.AddPage(&page1);
	wiz.AddPage(&page2);
	wiz.AddPage(&page3);
	wiz.SetWizardMode();//设置为向导模式
	wiz.DoModal();
}
