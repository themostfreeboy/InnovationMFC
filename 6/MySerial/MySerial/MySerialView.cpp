
// MySerialView.cpp : CMySerialView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MySerial.h"
#endif

#include "MySerialDoc.h"
#include "MySerialView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMySerialView

IMPLEMENT_DYNCREATE(CMySerialView, CFormView)

BEGIN_MESSAGE_MAP(CMySerialView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_EN_CHANGE(IDC_ENAME, &CMySerialView::OnEnChangeEname)
	ON_EN_CHANGE(IDC_EAGE, &CMySerialView::OnEnChangeEage)
	ON_EN_CHANGE(IDC_EEMAIL, &CMySerialView::OnEnChangeEemail)
	ON_BN_CLICKED(IDC_RANONYMOUS, &CMySerialView::OnBnClickedRanonymous)
	ON_BN_CLICKED(IDC_RMAN, &CMySerialView::OnBnClickedRman)
	ON_BN_CLICKED(IDC_RWOMAN, &CMySerialView::OnBnClickedRwoman)
END_MESSAGE_MAP()

// CMySerialView ����/����

CMySerialView::CMySerialView()
	: CFormView(CMySerialView::IDD)
	, m_strName(_T(""))
	, m_strAge(_T(""))
	, m_strEmail(_T(""))
	, m_nGender(0)
{
	// TODO:  �ڴ˴���ӹ������

}

CMySerialView::~CMySerialView()
{
}

void CMySerialView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ENAME, m_strName);
	DDX_Text(pDX, IDC_EAGE, m_strAge);
	DDX_Text(pDX, IDC_EEMAIL, m_strEmail);
	DDX_Radio(pDX, IDC_RANONYMOUS, m_nGender);
}

BOOL CMySerialView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMySerialView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	//����Ϊ�Լ���ӵ�����
	CMySerialDoc* pDoc = GetDocument();
	m_strName = pDoc->m_strDocName;
	m_strAge = pDoc->m_strDocAge;
	m_nGender = pDoc->m_nDocGender;
	m_strEmail = pDoc->m_strDocEmail;
	UpdateData(FALSE);
}

void CMySerialView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMySerialView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMySerialView ���

#ifdef _DEBUG
void CMySerialView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMySerialView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMySerialDoc* CMySerialView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySerialDoc)));
	return (CMySerialDoc*)m_pDocument;
}
#endif //_DEBUG


// CMySerialView ��Ϣ�������


void CMySerialView::OnEnChangeEname()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_strDocName = m_strName;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnEnChangeEage()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_strDocAge = m_strAge;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnEnChangeEemail()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_strDocEmail = m_strEmail;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnBnClickedRanonymous()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_nGender = 0;
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_nDocGender = m_nGender;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnBnClickedRman()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_nGender = 1;
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_nDocGender = m_nGender;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnBnClickedRwoman()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_nGender = 2;
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_nDocGender = m_nGender;
	pDoc->SetModifiedFlag();
}
