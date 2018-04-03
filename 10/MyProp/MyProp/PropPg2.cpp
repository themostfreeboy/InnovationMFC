// PropPg2.cpp : 实现文件
//

#include "stdafx.h"
#include "MyProp.h"
#include "PropPg2.h"


// CPropPg2 对话框

IMPLEMENT_DYNCREATE(CPropPg2, CPropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CPropPg2, CPropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

// {8895306F-6D49-4B6B-9F65-1343B8ADCFE0}
IMPLEMENT_OLECREATE_EX(CPropPg2, "MyProp.PropPg2",
	0x8895306f, 0x6d49, 0x4b6b, 0x9f, 0x65, 0x13, 0x43, 0xb8, 0xad, 0xcf, 0xe0)



// CPropPg2::CPropPg2Factory::UpdateRegistry -
// 添加或移除 CPropPg2 的系统注册表项

BOOL CPropPg2::CPropPg2Factory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  定义页类型的字符串资源；用 ID 替换下面的“0”。

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
		m_clsid, 0);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CPropPg2::CPropPg2 - 构造函数

// TODO:  定义页标题的字符串资源；用 ID 替换下面的“0”。

CPropPg2::CPropPg2() :
CPropertyPage(IDD, 0)
{

}



// CPropPg2::DoDataExchange - 在页和属性间移动数据

void CPropPg2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}



// CPropPg2 消息处理程序
