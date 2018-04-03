
// SampleMenuView.h : CSampleMenuView 类的接口
//

#pragma once


class CSampleMenuView : public CView
{
protected: // 仅从序列化创建
	CSampleMenuView();
	DECLARE_DYNCREATE(CSampleMenuView)

// 特性
public:
	CSampleMenuDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSampleMenuView();
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
	afx_msg void OnAddDrawing();
	afx_msg void OnAddDialog();
	afx_msg void OnPopupmenuMorning();
	afx_msg void OnPopupmenuEvening();
	int m_nColor;
};

#ifndef _DEBUG  // SampleMenuView.cpp 中的调试版本
inline CSampleMenuDoc* CSampleMenuView::GetDocument() const
   { return reinterpret_cast<CSampleMenuDoc*>(m_pDocument); }
#endif

