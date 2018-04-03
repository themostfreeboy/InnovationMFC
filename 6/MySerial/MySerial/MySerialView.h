
// MySerialView.h : CMySerialView 类的接口
//

#pragma once

#include "resource.h"


class CMySerialView : public CFormView
{
protected: // 仅从序列化创建
	CMySerialView();
	DECLARE_DYNCREATE(CMySerialView)

public:
	enum{ IDD = IDD_MYSERIAL_FORM };

// 特性
public:
	CMySerialDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMySerialView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MySerialView.cpp 中的调试版本
inline CMySerialDoc* CMySerialView::GetDocument() const
   { return reinterpret_cast<CMySerialDoc*>(m_pDocument); }
#endif

