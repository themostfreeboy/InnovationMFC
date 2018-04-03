
// AnalysisView.h : CAnalysisView ��Ľӿ�
//

#pragma once


class CAnalysisView : public CListView
{
protected: // �������л�����
	CAnalysisView();
	DECLARE_DYNCREATE(CAnalysisView)

// ����
public:
	CAnalysisDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CListCtrl listCtrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void CreateListColumns(void);

protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	

// ʵ��
public:
	virtual ~CAnalysisView();
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
};

#ifndef _DEBUG  // AnalysisView.cpp �еĵ��԰汾
inline CAnalysisDoc* CAnalysisView::GetDocument() const
   { return reinterpret_cast<CAnalysisDoc*>(m_pDocument); }
#endif

