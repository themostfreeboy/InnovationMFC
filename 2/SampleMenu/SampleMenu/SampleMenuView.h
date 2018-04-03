
// SampleMenuView.h : CSampleMenuView ��Ľӿ�
//

#pragma once


class CSampleMenuView : public CView
{
protected: // �������л�����
	CSampleMenuView();
	DECLARE_DYNCREATE(CSampleMenuView)

// ����
public:
	CSampleMenuDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSampleMenuView();
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
	afx_msg void OnAddDrawing();
	afx_msg void OnAddDialog();
	afx_msg void OnPopupmenuMorning();
	afx_msg void OnPopupmenuEvening();
	int m_nColor;
};

#ifndef _DEBUG  // SampleMenuView.cpp �еĵ��԰汾
inline CSampleMenuDoc* CSampleMenuView::GetDocument() const
   { return reinterpret_cast<CSampleMenuDoc*>(m_pDocument); }
#endif

