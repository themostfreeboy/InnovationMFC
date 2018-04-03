
// Message_RouteView.cpp : CMessage_RouteView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMessage_RouteView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMessage_RouteView ����/����

CMessage_RouteView::CMessage_RouteView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMessage_RouteView::~CMessage_RouteView()
{
}

BOOL CMessage_RouteView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMessage_RouteView ����

void CMessage_RouteView::OnDraw(CDC* /*pDC*/)
{
	CMessage_RouteDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMessage_RouteView ��ӡ


void CMessage_RouteView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMessage_RouteView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMessage_RouteView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMessage_RouteView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CMessage_RouteView ���

#ifdef _DEBUG
void CMessage_RouteView::AssertValid() const
{
	CView::AssertValid();
}

void CMessage_RouteView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMessage_RouteDoc* CMessage_RouteView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMessage_RouteDoc)));
	return (CMessage_RouteDoc*)m_pDocument;
}
#endif //_DEBUG


// CMessage_RouteView ��Ϣ�������
