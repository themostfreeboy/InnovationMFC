// AccelerationReader.h : AccelerationReader Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CAccelerationReaderApp:
// �йش����ʵ�֣������ AccelerationReader.cpp
//

class CAccelerationReaderApp : public CWinApp
{
public:
	CAccelerationReaderApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAccelerationReaderApp theApp;