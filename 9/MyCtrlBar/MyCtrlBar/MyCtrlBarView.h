
// MyCtrlBarView.h : CMyCtrlBarView ��Ľӿ�
//

#pragma once


class CMyCtrlBarView : public CView
{
protected: // �������л�����
	CMyCtrlBarView();
	DECLARE_DYNCREATE(CMyCtrlBarView)

// ����
public:
	CMyCtrlBarDoc* GetDocument() const;

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
	virtual ~CMyCtrlBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MyCtrlBarView.cpp �еĵ��԰汾
inline CMyCtrlBarDoc* CMyCtrlBarView::GetDocument() const
   { return reinterpret_cast<CMyCtrlBarDoc*>(m_pDocument); }
#endif

