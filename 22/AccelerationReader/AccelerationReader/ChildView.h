// ChildView.h : CChildView ��Ľӿ�
//


#pragma once
#include "afxcmn.h"


// CChildView ����

class CChildView : public CWnd
{
// ����
public:
	CChildView();

// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();

	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl listCtrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void CreateListColumns(void);
	afx_msg void OnFileOpen();
	void openDataFile(CString fileName);
};

