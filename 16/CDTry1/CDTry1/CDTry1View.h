
// CDTry1View.h : CCDTry1View ��Ľӿ�
//

#pragma once
#include "string"


class CCDTry1View : public CView
{
protected: // �������л�����
	CCDTry1View();
	DECLARE_DYNCREATE(CCDTry1View)

// ����
public:
	CCDTry1Doc* GetDocument() const;

// ����
public:
	void MyPaintPicture();
	void MyCreatDirectory();//�½��ļ���"D://Boxing"
	LPCTSTR CCDTry1View::MyCharToLPCTSTR(char* szStr);//char*תLPCTSTR
	const char* CCDTry1View::MyCStringToConstChar(CString cstr);//CStringתconst char*
	LPCTSTR CCDTry1View::MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
	std::string CCDTry1View::MyCStringToString(CString cstr);//CStringתstring
	CString CCDTry1View::MyStringToCString(std::string str);//stringתCString
	double CCDTry1View::MyCStringToDouble(CString cstr);//CStringתdouble
	const char* CCDTry1View::MyDoubleToChar(double dou);//doubleתconst char*
	CString CCDTry1View::MyGetTime();//��ȡϵͳʱ��

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
	virtual ~CCDTry1View();
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
	afx_msg void OnShowpicture();
};

#ifndef _DEBUG  // CDTry1View.cpp �еĵ��԰汾
inline CCDTry1Doc* CCDTry1View::GetDocument() const
   { return reinterpret_cast<CCDTry1Doc*>(m_pDocument); }
#endif

