
// ListCtrlTestView.h : CListCtrlTestView 类的接口
//

#pragma once


class CListCtrlTestView : public CListView
{
protected: // 仅从序列化创建
	CListCtrlTestView();
	DECLARE_DYNCREATE(CListCtrlTestView)

// 特性
public:
	CListCtrlTestDoc* GetDocument() const;
	afx_msg void OnPaint();
	CListCtrl listCtrl;

// 操作
public:
	//CListCtrl listCtrl;

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CListCtrlTestView();
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
	//afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ListCtrlTestView.cpp 中的调试版本
inline CListCtrlTestDoc* CListCtrlTestView::GetDocument() const
   { return reinterpret_cast<CListCtrlTestDoc*>(m_pDocument); }
#endif

