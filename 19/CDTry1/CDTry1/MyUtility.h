#include "MyConvert.h"


class CMyUtility:public CMyConvert
{
public:
	static void MyCreatDirectory();//新建文件夹"D://Boxing"
	static CString MyGetTime();//获取系统时间
};