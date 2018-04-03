#include "MyUtility.h"
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void CMyUtility::MyCreatDirectory()//新建文件夹"D://Boxing"
{
	CString   strFolderPath = CString("D://Boxing");
	if (!PathIsDirectory(strFolderPath))//判断路径是否存在
	{

		//设置属性
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}



CString CMyUtility::MyGetTime()//获取系统时间
{
	CString cstr;
	CTime tm;
	tm = CTime::GetCurrentTime();
	cstr = tm.Format("%Y%m%d%H%M%S");//年月日时分秒
	return cstr;
}