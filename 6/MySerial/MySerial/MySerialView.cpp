
// MySerialView.cpp : CMySerialView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMySerialView 构造/析构

CMySerialView::CMySerialView()
	: CFormView(CMySerialView::IDD)
	, m_strName(_T(""))
	, m_strAge(_T(""))
	, m_strEmail(_T(""))
	, m_nGender(0)
{
	// TODO:  在此处添加构造代码

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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMySerialView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	//以下为自己添加的内容
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


// CMySerialView 诊断

#ifdef _DEBUG
void CMySerialView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMySerialView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMySerialDoc* CMySerialView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySerialDoc)));
	return (CMySerialDoc*)m_pDocument;
}
#endif //_DEBUG


// CMySerialView 消息处理程序


void CMySerialView::OnEnChangeEname()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_strDocName = m_strName;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnEnChangeEage()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_strDocAge = m_strAge;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnEnChangeEemail()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_strDocEmail = m_strEmail;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnBnClickedRanonymous()
{
	// TODO:  在此添加控件通知处理程序代码
	m_nGender = 0;
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_nDocGender = m_nGender;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnBnClickedRman()
{
	// TODO:  在此添加控件通知处理程序代码
	m_nGender = 1;
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_nDocGender = m_nGender;
	pDoc->SetModifiedFlag();
}


void CMySerialView::OnBnClickedRwoman()
{
	// TODO:  在此添加控件通知处理程序代码
	m_nGender = 2;
	CMySerialDoc* pDoc = GetDocument();
	UpdateData(TRUE);
	pDoc->m_nDocGender = m_nGender;
	pDoc->SetModifiedFlag();
}
