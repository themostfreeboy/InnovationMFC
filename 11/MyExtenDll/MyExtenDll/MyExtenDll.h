// MyExtenDll.h : MyExtenDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyExtenDllApp
// �йش���ʵ�ֵ���Ϣ������� MyExtenDll.cpp
//

class CMyExtenDllApp : public CWinApp
{
public:
	CMyExtenDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
