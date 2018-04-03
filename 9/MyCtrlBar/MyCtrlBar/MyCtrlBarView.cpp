
// MyCtrlBarView.cpp : CMyCtrlBarView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMyCtrlBarView ����/����

CMyCtrlBarView::CMyCtrlBarView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMyCtrlBarView::~CMyCtrlBarView()
{
}

BOOL CMyCtrlBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyCtrlBarView ����

void CMyCtrlBarView::OnDraw(CDC* /*pDC*/)
{
	CMyCtrlBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMyCtrlBarView ��ӡ

BOOL CMyCtrlBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyCtrlBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyCtrlBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMyCtrlBarView ���

#ifdef _DEBUG
void CMyCtrlBarView::AssertValid() const
{
	CView::AssertValid();
}

void CMyCtrlBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyCtrlBarDoc* CMyCtrlBarView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCtrlBarDoc)));
	return (CMyCtrlBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyCtrlBarView ��Ϣ�������


void CMyCtrlBarView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	str.Format("X=%d", point.x);
	pFrame->m_wndStatusBar.SetPaneText(1, str);
	str.Format("Y=%d",point.y);
	pFrame->m_wndStatusBar.SetPaneText(2, str);
	CView::OnMouseMove(nFlags, point);
}
