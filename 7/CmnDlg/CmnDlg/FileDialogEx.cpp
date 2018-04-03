// FileDialogEx.cpp : 实现文件
//

#include "stdafx.h"
#include "CmnDlg.h"
#include "FileDialogEx.h"


// CFileDialogEx

IMPLEMENT_DYNAMIC(CFileDialogEx, CFileDialog)

CFileDialogEx::CFileDialogEx(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{

}

CFileDialogEx::~CFileDialogEx()
{
}


BEGIN_MESSAGE_MAP(CFileDialogEx, CFileDialog)
END_MESSAGE_MAP()



// CFileDialogEx 消息处理程序
BOOL CFileDialogEx::OnInitDialog()
{
	CFileDialog::OnInitDialog();
	char szText[120];
	const UINT iExtraSize = 50;
	CWnd *wndDlg = GetParent();
	RECT Rect;
	wndDlg->GetWindowRect(&Rect);
	wndDlg->SetWindowPos(NULL, 0, 0,
		                 Rect.right - Rect.left,
		                 Rect.bottom - Rect.top + iExtraSize,
		                 SWP_NOMOVE);
	CWnd *wndComboCtrl = wndDlg->GetDlgItem(cmb1);
	wndComboCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect);
	Rect.top += 60;
	Rect.bottom += 120;
	Rect.left += 50;
	m_Combo.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_SORT | WS_VSCROLL | WS_TABSTOP, Rect, wndDlg, IDC_MYCOMBOBOX);
	m_Combo.SetFont(wndComboCtrl->GetFont(), TRUE);
	m_Combo.SetFocus();
	CWnd *wndStaticCtrl = wndDlg->GetDlgItem(stc2);
	wndStaticCtrl->GetWindowRect(&Rect);
	wndDlg->ScreenToClient(&Rect);
	Rect.top += 60;
	Rect.bottom += 80;
	Rect.right += 40;
	char* szStr1 = "eYas";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	m_Static.Create(wszClassName1, WS_CHILD | WS_VISIBLE, Rect, wndDlg, IDC_MYSTATIC);
	m_Static.SetFont(wndComboCtrl->GetFont(), TRUE);
	for (int i = 0; i < 3; i++)
	{
		sprintf_s(szText, "MyType%d", i);
		wndDlg->SendDlgItemMessageW(IDC_MYCOMBOBOX, CB_INSERTSTRING, (WPARAM)(-1), (LPARAM)(szText));
		char* szStr1 = szText;
		WCHAR wszClassName1[256];
		memset(wszClassName1, 0, sizeof(wszClassName1));
		MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
		if (m_nMyType == i)
			wndDlg->SetDlgItemTextW(IDC_MYCOMBOBOX, wszClassName1);
	}
	sprintf_s(szText, "My File Type");
	szStr1 = szText;
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	wndDlg->SetDlgItemTextW(IDC_MYSTATIC, wszClassName1);
	return TRUE;
}


BOOL CFileDialogEx::OnDestroy()
{
	CFileDialog::OnDestroy();
	char szText[40];
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szText, strlen(szText) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	if (GetParent()->GetDlgItemText(IDC_MYCOMBOBOX, wszClassName1, sizeof(wszClassName1)) > 0)
	{
		m_nMyType = szText[strlen(szText) - 1] - '0';
	}
	return TRUE;
}

