#include "MyConvert.h"


class CMyUtility:public CMyConvert
{
public:
	void MyCreatDirectory();//新建文件夹"D://Boxing"
	CString MyGetTime();//获取系统时间
};