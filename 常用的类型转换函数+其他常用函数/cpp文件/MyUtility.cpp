#include "MyUtility.h"
#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void CMyUtility::MyCreatDirectory()//�½��ļ���"D://Boxing"
{
	CString   strFolderPath = CString("D://Boxing");
	if (!PathIsDirectory(strFolderPath))//�ж�·���Ƿ����
	{

		//��������
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}



CString CMyUtility::MyGetTime()//��ȡϵͳʱ��
{
	CString cstr;
	CTime tm;
	tm = CTime::GetCurrentTime();
	cstr = tm.Format("%Y%m%d%H%M%S");//������ʱ����
	return cstr;
}