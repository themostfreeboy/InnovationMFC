
// MySerialView.h : CMySerialView ��Ľӿ�
//

#pragma once

#include "resource.h"


class CMySerialView : public CFormView
{
protected: // �������л�����
	CMySerialView();
	DECLARE_DYNCREATE(CMySerialView)

public:
	enum{ IDD = IDD_MYSERIAL_FORM };

// ����
public:
	CMySerialDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMySerialView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strAge;
	CString m_strEmail;
	int m_nGender;
	afx_msg void OnEnChangeEname();
	afx_msg void OnEnChangeEage();
	afx_msg void OnEnChangeEemail();
	afx_msg void OnBnClickedRanonymous();
	afx_msg void OnBnClickedRman();
	afx_msg void OnBnClickedRwoman();
};

#ifndef _DEBUG  // MySerialView.cpp �еĵ��԰汾
inline CMySerialDoc* CMySerialView::GetDocument() const
   { return reinterpret_cast<CMySerialDoc*>(m_pDocument); }
#endif

