
// MyExtenDll.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyExtenDllApp: 
// �йش����ʵ�֣������ MyExtenDll.cpp
//

class CMyExtenDllApp : public CWinApp
{
public:
	CMyExtenDllApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyExtenDllApp theApp;