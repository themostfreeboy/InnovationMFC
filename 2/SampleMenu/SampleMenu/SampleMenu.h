
// SampleMenu.h : SampleMenu Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSampleMenuApp:
// �йش����ʵ�֣������ SampleMenu.cpp
//

class CSampleMenuApp : public CWinAppEx
{
public:
	CSampleMenuApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	
// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

};

extern CSampleMenuApp theApp;
