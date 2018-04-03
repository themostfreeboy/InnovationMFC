
// ComplexMenuView.cpp : CComplexMenuView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ComplexMenu.h"
#endif

#include "ComplexMenuDoc.h"
#include "ComplexMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComplexMenuView

IMPLEMENT_DYNCREATE(CComplexMenuView, CView)

BEGIN_MESSAGE_MAP(CComplexMenuView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CComplexMenuView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CComplexMenuView ����/����

CComplexMenuView::CComplexMenuView()
{
	// TODO:  �ڴ˴���ӹ������

}

CComplexMenuView::~CComplexMenuView()
{
}

BOOL CComplexMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CComplexMenuView ����

void CComplexMenuView::OnDraw(CDC* /*pDC*/)
{
	CComplexMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CComplexMenuView ��ӡ


void CComplexMenuView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CComplexMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CComplexMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CComplexMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CComplexMenuView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CComplexMenuView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CComplexMenuView ���

#ifdef _DEBUG
void CComplexMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CComplexMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CComplexMenuDoc* CComplexMenuView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CComplexMenuDoc)));
	return (CComplexMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CComplexMenuView ��Ϣ�������
