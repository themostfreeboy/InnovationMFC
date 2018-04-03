
// SampleMenuView.cpp : CSampleMenuView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSampleMenuView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MYMENU_MORNING, &CSampleMenuView::OnMymenuMorning)
	ON_COMMAND(ID_MYMENU_EVENING, &CSampleMenuView::OnMymenuEvening)
	ON_COMMAND(ID_MYMENU_DRAWING, &CSampleMenuView::OnMymenuDrawing)
END_MESSAGE_MAP()

// CSampleMenuView ����/����

CSampleMenuView::CSampleMenuView()
: m_nColor(0)
{
	// TODO:  �ڴ˴���ӹ������

}

CSampleMenuView::~CSampleMenuView()
{
}

BOOL CSampleMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSampleMenuView ����

void CSampleMenuView::OnDraw(CDC* pDC)
{
	CSampleMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->SelectStockObject(m_nColor);
	pDC->Ellipse(CRect(0, 0, 200, 200));
}


// CSampleMenuView ��ӡ


void CSampleMenuView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSampleMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSampleMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSampleMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CSampleMenuView ���

#ifdef _DEBUG
void CSampleMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleMenuDoc* CSampleMenuView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleMenuDoc)));
	return (CSampleMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CSampleMenuView ��Ϣ�������


void CSampleMenuView::OnMymenuMorning()
{
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
	m_nColor = GRAY_BRUSH;
	Invalidate(TRUE);
}
