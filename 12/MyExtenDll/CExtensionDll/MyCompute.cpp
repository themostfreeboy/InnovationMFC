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


double CMyCompute::MyCube(void)//��������
{
	return m_data*m_data*m_data;
}



double CMyCompute::MyCube(double data)
{
	return data*data*data;
}



double CMyCompute::MyLog(void)//ȡ��������
{
	if (m_data > 0)
		return log(m_data);
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



double CMyCompute::MyLog(double data)
{
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



double CMyCompute::MySqrt(void)//����������
{
	if (m_data >= 0)
		return sqrt(m_data);
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



double CMyCompute::MySqrt(double data)
{
	if (data >= 0)
		return sqrt(m_data);
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



double CMyCompute::MySquare(void)//ƽ������
{
	return m_data*m_data;
}



double CMyCompute::MySquare(double data)
{
	return data*data;
}