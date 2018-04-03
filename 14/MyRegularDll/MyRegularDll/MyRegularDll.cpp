// MyRegularDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MyRegularDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

extern "C" _declspec(dllexport) double MyCube(double data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return data*data*data;
}
extern "C" _declspec(dllexport) double MyLog(double data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (data > 0)
		return log(data);
	else
	{
		char* szStr1 = "�������㲻��ȡ��ֵ!";
		WCHAR wszClassName1[256];
		memset(wszClassName1, 0, sizeof(wszClassName1));
		MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
		AfxMessageBox(wszClassName1);
		return -1;
	}
}
extern "C" _declspec(dllexport) double MySqrt(double data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (data >= 0)
		return sqrt(data);
	else
	{
		char* szStr1 = "���������㲻��ȡ��ֵ!";
		WCHAR wszClassName1[256];
		memset(wszClassName1, 0, sizeof(wszClassName1));
		MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
		AfxMessageBox(wszClassName1);
		return -1;
	}
}
extern "C" _declspec(dllexport) double MySquare(double data)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return data*data;
}



// CMyRegularDllApp

BEGIN_MESSAGE_MAP(CMyRegularDllApp, CWinApp)
END_MESSAGE_MAP()


// CMyRegularDllApp ����

CMyRegularDllApp::CMyRegularDllApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMyRegularDllApp ����

CMyRegularDllApp theApp;


// CMyRegularDllApp ��ʼ��

BOOL CMyRegularDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
