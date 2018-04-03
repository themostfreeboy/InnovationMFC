
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
	ON_COMMAND(ID_ADD_DRAWING, &CSampleMenuView::OnAddDrawing)
	ON_COMMAND(ID_ADD_DIALOG, &CSampleMenuView::OnAddDialog)
	ON_COMMAND(ID_POPUPMENU_MORNING, &CSampleMenuView::OnPopupmenuMorning)
	ON_COMMAND(ID_POPUPMENU_EVENING, &CSampleMenuView::OnPopupmenuEvening)
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
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
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


void CSampleMenuView::OnAddDrawing()
{
	// TODO:  �ڴ���������������
	m_nColor = GRAY_BRUSH;
	Invalidate(TRUE);
}


void CSampleMenuView::OnAddDialog()
{
	// TODO:  �ڴ���������������
	char* szStr1 = "How do you do!";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));

	char* szStr2 = "Wow";
	WCHAR wszClassName2[256];
	memset(wszClassName2, 0, sizeof(wszClassName2));
	MultiByteToWideChar(CP_ACP, 0, szStr2, strlen(szStr2) + 1, wszClassName2, sizeof(wszClassName2) / sizeof(wszClassName2[0]));

	MessageBox(wszClassName1, wszClassName2, MB_OKCANCEL);
}


void CSampleMenuView::OnPopupmenuMorning()
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


void CSampleMenuView::OnPopupmenuEvening()
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
