#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CModallessDlg 对话框

class CModallessDlg : public CDialog
{
	DECLARE_DYNAMIC(CModallessDlg)

public:
	CModallessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModallessDlg();

// 对话框数据
	enum { IDD = IDD_MODALLESS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWnd* m_pParent;
	CWnd* m_pModallessDlg;
	void PostNcDestroy();
	CSliderCtrl m_ctlSLRed;
	CSliderCtrl m_ctlSLGreen;
	CSliderCtrl m_ctlSLBlue;
	CSpinButtonCtrl m_ctlSpinRed;
	CSpinButtonCtrl m_ctlSpinGreen;
	CSpinButtonCtrl m_ctlSpinBlue;
	CEdit m_ctlERed;
	CString m_strRed;
	CEdit m_ctlEGreen;
	CString m_strGreen;
	CString m_strBlue;
	CEdit m_ctlEBlue;
	BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
//	afx_msg void OnBuddyUpdate();
//	afx_msg void OnBuddyupdate();
	afx_msg void OnEnUpdateEred();
	afx_msg void OnEnUpdateEgreen();
	afx_msg void OnEnUpdateEblue();
	void OnBuddyUpdate();
	int StringToInt(CString* psInt);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
