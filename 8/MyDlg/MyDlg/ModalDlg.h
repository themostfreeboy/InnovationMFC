#pragma once
#include "afxtempl.h"
#include "afxwin.h"


// CModalDlg �Ի���

class CModalDlg : public CDialog
{
	DECLARE_DYNAMIC(CModalDlg)

public:
	CModalDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CModalDlg();

// �Ի�������
	enum { IDD = IDD_MODAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strLess;
	CString m_strMore;
	CList m_ctlRecvd;
	CString m_strPgmName;
	CButton m_IconBN;
	CButton m_BmpBN;
	BOOL m_bEnableLeft;
	BOOL m_bEnableRight;
	BOOL m_bIsHide;
	afx_msg void OnEnChangeLess();
	afx_msg void OnBnClickedBadd();
	afx_msg void OnBnClickedBrunprogram();
	afx_msg void OnBnClickedCleft();
	afx_msg void OnBnClickedCright();
	afx_msg void OnBnClickedRshow();
	virtual BOOL OnInitDialog();
};
