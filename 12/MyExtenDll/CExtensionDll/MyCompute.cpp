#include "stdafx.h"
#include "MyCompute.h"
#include "math.h"


CMyCompute::CMyCompute(void)
{
	m_data = 0;
}


CMyCompute::CMyCompute(double data)
{
	m_data = data;
}


CMyCompute::~CMyCompute(void)
{
}


double CMyCompute::MyCube(void)//立方运算
{
	return m_data*m_data*m_data;
}



double CMyCompute::MyCube(double data)
{
	return data*data*data;
}



double CMyCompute::MyLog(void)//取对数运算
{
	if (m_data > 0)
		return log(m_data);
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



double CMyCompute::MyLog(double data)
{
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



double CMyCompute::MySqrt(void)//开根号运算
{
	if (m_data >= 0)
		return sqrt(m_data);
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



double CMyCompute::MySqrt(double data)
{
	if (data >= 0)
		return sqrt(m_data);
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



double CMyCompute::MySquare(void)//平方运算
{
	return m_data*m_data;
}



double CMyCompute::MySquare(double data)
{
	return data*data;
}