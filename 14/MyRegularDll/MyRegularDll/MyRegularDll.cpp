// MyRegularDll.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "MyRegularDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
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
		char* szStr1 = "对数运算不能取负值!";
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
		char* szStr1 = "开根号运算不能取负值!";
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


// CMyRegularDllApp 构造

CMyRegularDllApp::CMyRegularDllApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMyRegularDllApp 对象

CMyRegularDllApp theApp;


// CMyRegularDllApp 初始化

BOOL CMyRegularDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
