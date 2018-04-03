
// Message_RouteView.h : CMessage_RouteView ��Ľӿ�
//

#pragma once


class CMessage_RouteView : public CView
{
protected: // �������л�����
	CMessage_RouteView();
	DECLARE_DYNCREATE(CMessage_RouteView)

// ����
public:
	CMessage_RouteDoc* GetDocument() const;

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
	virtual ~CMessage_RouteView();
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

#ifndef _DEBUG  // Message_RouteView.cpp �еĵ��԰汾
inline CMessage_RouteDoc* CMessage_RouteView::GetDocument() const
   { return reinterpret_cast<CMessage_RouteDoc*>(m_pDocument); }
#endif

