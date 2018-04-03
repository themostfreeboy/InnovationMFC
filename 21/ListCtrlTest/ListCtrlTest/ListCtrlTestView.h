
// ListCtrlTestView.h : CListCtrlTestView ��Ľӿ�
//

#pragma once


class CListCtrlTestView : public CListView
{
protected: // �������л�����
	CListCtrlTestView();
	DECLARE_DYNCREATE(CListCtrlTestView)

// ����
public:
	CListCtrlTestDoc* GetDocument() const;
	afx_msg void OnPaint();
	CListCtrl listCtrl;

// ����
public:
	//CListCtrl listCtrl;

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CListCtrlTestView();
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
	//afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ListCtrlTestView.cpp �еĵ��԰汾
inline CListCtrlTestDoc* CListCtrlTestView::GetDocument() const
   { return reinterpret_cast<CListCtrlTestDoc*>(m_pDocument); }
#endif

