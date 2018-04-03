
// MyPropView.h : CMyPropView ��Ľӿ�
//

#pragma once


class CMyPropView : public CView
{
protected: // �������л�����
	CMyPropView();
	DECLARE_DYNCREATE(CMyPropView)

// ����
public:
	CMyPropDoc* GetDocument() const;

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
	virtual ~CMyPropView();
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
	afx_msg void OnViewCommonProp();
	afx_msg void OnViewWizProp();
};

#ifndef _DEBUG  // MyPropView.cpp �еĵ��԰汾
inline CMyPropDoc* CMyPropView::GetDocument() const
   { return reinterpret_cast<CMyPropDoc*>(m_pDocument); }
#endif

