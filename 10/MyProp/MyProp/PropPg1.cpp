// PropPg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MyProp.h"
#include "PropPg1.h"


// CPropPg1 对话框

IMPLEMENT_DYNCREATE(CPropPg1, CPropertyPage)



// 消息映射

BEGIN_MESSAGE_MAP(CPropPg1, CPropertyPage)
END_MESSAGE_MAP()



// 初始化类工厂和 guid

// {AF6F8C07-CEBF-4AC7-ACFF-EAC5F2A97F91}
IMPLEMENT_OLECREATE_EX(CPropPg1, "MyProp.PropPg1",
	0xaf6f8c07, 0xcebf, 0x4ac7, 0xac, 0xff, 0xea, 0xc5, 0xf2, 0xa9, 0x7f, 0x91)



// CPropPg1::CPropPg1Factory::UpdateRegistry -
// 添加或移除 CPropPg1 的系统注册表项

BOOL CPropPg1::CPropPg1Factory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  定义页类型的字符串资源；用 ID 替换下面的“0”。

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
		m_clsid, 0);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CPropPg1::CPropPg1 - 构造函数

// TODO:  定义页标题的字符串资源；用 ID 替换下面的“0”。

CPropPg1::CPropPg1() :
CPropertyPage(IDD, 0)
{

}



// CPropPg1::DoDataExchange - 在页和属性间移动数据

void CPropPg1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}



// CPropPg1 消息处理程序
