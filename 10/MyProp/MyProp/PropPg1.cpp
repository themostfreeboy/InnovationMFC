// PropPg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyProp.h"
#include "PropPg1.h"


// CPropPg1 �Ի���

IMPLEMENT_DYNCREATE(CPropPg1, CPropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CPropPg1, CPropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

// {AF6F8C07-CEBF-4AC7-ACFF-EAC5F2A97F91}
IMPLEMENT_OLECREATE_EX(CPropPg1, "MyProp.PropPg1",
	0xaf6f8c07, 0xcebf, 0x4ac7, 0xac, 0xff, 0xea, 0xc5, 0xf2, 0xa9, 0x7f, 0x91)



// CPropPg1::CPropPg1Factory::UpdateRegistry -
// ��ӻ��Ƴ� CPropPg1 ��ϵͳע�����

BOOL CPropPg1::CPropPg1Factory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ����ҳ���͵��ַ�����Դ���� ID �滻����ġ�0����

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
		m_clsid, 0);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CPropPg1::CPropPg1 - ���캯��

// TODO:  ����ҳ������ַ�����Դ���� ID �滻����ġ�0����

CPropPg1::CPropPg1() :
CPropertyPage(IDD, 0)
{

}



// CPropPg1::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CPropPg1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}



// CPropPg1 ��Ϣ�������
