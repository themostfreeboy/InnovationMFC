#pragma once
#include"dlgs.h"

// CFileDialogEx

class CFileDialogEx : public CFileDialog
{
	DECLARE_DYNAMIC(CFileDialogEx)

public:
	CFileDialogEx(BOOL bOpenFileDialog, // ���� FileOpen Ϊ TRUE������ FileSaveAs Ϊ FALSE
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);
	CStatic m_Static;
	CComboBox m_Combo;
	int m_nMyType;
	virtual ~CFileDialogEx();
	virtual BOOL OnInitDialog();
	virtual BOOL OnDestroy();

protected:
	DECLARE_MESSAGE_MAP()
};


