#include "MyConvert.h"
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


LPCTSTR CMyConvert::MyCharToLPCTSTR(char* szStrtemp)//char*转LPCTSTR
{


     //char*תLPCTSTR
     //typedef LPCWSTR LPCTSTR
     //type const WCHAR *LPCWSTR


	char* szStr = new char[512];//为了避免直接对传入的地址进行改动，新申请一个内存并把传入的内容复制
	strcpy_s(szStr, 512, szStrtemp);//复制传入的内容
	WCHAR wszClassName[512];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
	delete szStr;//释放内存
	WCHAR* wszClassNameReturn = new WCHAR[512];//为了避免直接对传出的地址进行改动，新申请一个内存并把传出的内容复制
	wcscpy_s(wszClassNameReturn, 512, wszClassName);//复制传出的内容
	return wszClassNameReturn;
}



const char* CMyConvert::MyCStringToConstChar(CString cstr)//CString转const char*
{
	char     *pMBBuffer = (char *)malloc(100);
	const wchar_t  *pWCBuffer = (LPCTSTR)cstr;
	size_t   i = wcslen(pWCBuffer);
	wcstombs_s(&i, pMBBuffer, (size_t)(100), pWCBuffer, (size_t)(100));
	return pMBBuffer;
}

LPCTSTR CMyConvert::MyCStringToLPCTSTR(CString cstr)//CString转LPCTSTR
{

	LPCTSTR lpctstr = (LPCTSTR)cstr;
	return lpctstr;
}

std::string CMyConvert::MyCStringToString(CString cstr)//CString转string
{
	CT2A xx(cstr);
	std::string str = xx;
	return str;
}

CString CMyConvert::MyStringToCString(std::string str)//string转CString
{
	CString cstr(str.c_str());
	return cstr;
}

double CMyConvert::MyCStringToDouble(CString cstr)//CString转double
{
	double dou;
	dou = _wtof(cstr);
	return dou;
}


const char* CMyConvert::MyDoubleToChar(double dou)//double转char*
{
	char buffer[512];
	sprintf_s(buffer, "%f", dou);
	return buffer;
}
