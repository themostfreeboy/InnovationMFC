
// AnalysisView.h : CAnalysisView 类的接口
//

#pragma once


class CAnalysisView : public CListView
{
protected: // 仅从序列化创建
	CAnalysisView();
	DECLARE_DYNCREATE(CAnalysisView)

// 特性
public:
	CAnalysisDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CListCtrl listCtrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void CreateListColumns(void);

protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	

// 实现
public:
	virtual ~CAnalysisView();
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
};

#ifndef _DEBUG  // AnalysisView.cpp 中的调试版本
inline CAnalysisDoc* CAnalysisView::GetDocument() const
   { return reinterpret_cast<CAnalysisDoc*>(m_pDocument); }
#endif

