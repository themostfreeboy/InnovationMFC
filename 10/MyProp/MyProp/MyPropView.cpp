
// MyPropView.cpp : CMyPropView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMyPropView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_COMMON_PROP, &CMyPropView::OnViewCommonProp)
	ON_COMMAND(ID_WIZ_PROP, &CMyPropView::OnViewWizProp)
END_MESSAGE_MAP()

// CMyPropView ����/����

CMyPropView::CMyPropView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMyPropView::~CMyPropView()
{
}

BOOL CMyPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyPropView ����

void CMyPropView::OnDraw(CDC* /*pDC*/)
{
	CMyPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMyPropView ��ӡ


void CMyPropView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMyPropView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyPropView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyPropView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CMyPropView ���

#ifdef _DEBUG
void CMyPropView::AssertValid() const
{
	CView::AssertValid();
}

void CMyPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyPropDoc* CMyPropView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyPropDoc)));
	return (CMyPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyPropView ��Ϣ�������


void CMyPropView::OnViewCommonProp()
{
	// TODO:  �ڴ���������������
	char* szStr1 = "�������Ա�";
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
	// TODO:  �ڴ���������������
	CPropertySheet wiz;
	CWizPg1 page1;
	CWizPg2 page2;
	CWizPg3 page3;
	wiz.AddPage(&page1);
	wiz.AddPage(&page2);
	wiz.AddPage(&page3);
	wiz.SetWizardMode();//����Ϊ��ģʽ
	wiz.DoModal();
}
