// TempTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "TempTest.h"
#include "stdio.h"
#include "conio.h"
#include "iostream"
#include "stdlib.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO:  ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����:  MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO:  �ڴ˴�ΪӦ�ó������Ϊ��д���롣
		}
	}
	else
	{
		// TODO:  ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����:  GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}

	return nRetCode;
}
void test()
{
	CString m_strInput=CString("3.1415");
	double m_nData=0;
	//m_strInput.Format(_T("%f"), m_nData);
	//m_strInput.Format("%f", m_nData);
	//IStream stream;
	//m_nData = atof(m_strInput);
	//stringstream stringtemp;
	//stringtemp >> m_nData;
	m_nData = _wtof(m_strInput);
	printf("%f", m_nData);
}
int main()
{
	test();
	printf("\n");
	system("pause");
	return 0;
}