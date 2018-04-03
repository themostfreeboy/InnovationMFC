
// ListCtrlTestView.cpp : CListCtrlTestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ListCtrlTest.h"
#endif

#include "ListCtrlTestDoc.h"
#include "ListCtrlTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListCtrlTestView

IMPLEMENT_DYNCREATE(CListCtrlTestView, CListView)

BEGIN_MESSAGE_MAP(CListCtrlTestView, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	//ON_WM_PAINT()
	//ON_WM_CREATE()
END_MESSAGE_MAP()

// CListCtrlTestView ����/����

CListCtrlTestView::CListCtrlTestView()
{
	// TODO:  �ڴ˴���ӹ������

}

CListCtrlTestView::~CListCtrlTestView()
{
}

BOOL CListCtrlTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CListView::PreCreateWindow(cs);
}

void CListCtrlTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO:  ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
	//listCtrl.DeleteAllItems();
	
}

void CListCtrlTestView::OnPaint()
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������

	// TODO: �ڴ˴������Ϣ����������
	CRect   rect;
	GetClientRect(&rect);
	listCtrl.MoveWindow(&rect);

	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
}

void CListCtrlTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CListCtrlTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CListCtrlTestView ���

#ifdef _DEBUG
void CListCtrlTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CListCtrlTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListCtrlTestDoc* CListCtrlTestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListCtrlTestDoc)));
	return (CListCtrlTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CListCtrlTestView ��Ϣ�������
/*
int CListCtrlTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	MessageBox(_T("OnCreateBegin"),NULL,MB_OK);
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	listCtrl.CreateEx(LVS_EX_GRIDLINES, WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT, rect, this, 1);
	//listCtrl.Create(LVS_EX_FLATSB | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES, rect, this, 123);
	listCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	listCtrl.SetBkColor(RGB(237, 250, 254));
	listCtrl.SetTextBkColor(RGB(0, 255, 0));
	listCtrl.SetTextColor(RGB(0, 0, 255));
	listCtrl.InsertColumn(0, _T("error"), LVCFMT_LEFT, 50);
	//UpdateData(FALSE);
	MessageBox(_T("OnCreateEnd"), NULL, MB_OK);
	return 0;
}
*/