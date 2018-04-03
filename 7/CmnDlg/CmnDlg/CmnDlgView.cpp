
// CmnDlgView.cpp : CCmnDlgView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "CmnDlg.h"
#endif

#include "CmnDlgDoc.h"
#include "CmnDlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCmnDlgView

IMPLEMENT_DYNCREATE(CCmnDlgView, CView)

BEGIN_MESSAGE_MAP(CCmnDlgView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCmnDlgView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CCmnDlgView ����/����

CCmnDlgView::CCmnDlgView()
{
	// TODO:  �ڴ˴���ӹ������

}

CCmnDlgView::~CCmnDlgView()
{
}

BOOL CCmnDlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCmnDlgView ����

void CCmnDlgView::OnDraw(CDC* /*pDC*/)
{
	CCmnDlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CCmnDlgView ��ӡ


void CCmnDlgView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCmnDlgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCmnDlgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCmnDlgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CCmnDlgView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCmnDlgView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCmnDlgView ���

#ifdef _DEBUG
void CCmnDlgView::AssertValid() const
{
	CView::AssertValid();
}

void CCmnDlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCmnDlgDoc* CCmnDlgView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCmnDlgDoc)));
	return (CCmnDlgDoc*)m_pDocument;
}
#endif //_DEBUG


// CCmnDlgView ��Ϣ�������
