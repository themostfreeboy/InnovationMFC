// PropPg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyProp.h"
#include "PropPg2.h"


// CPropPg2 �Ի���

IMPLEMENT_DYNCREATE(CPropPg2, CPropertyPage)



// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CPropPg2, CPropertyPage)
END_MESSAGE_MAP()



// ��ʼ���๤���� guid

// {8895306F-6D49-4B6B-9F65-1343B8ADCFE0}
IMPLEMENT_OLECREATE_EX(CPropPg2, "MyProp.PropPg2",
	0x8895306f, 0x6d49, 0x4b6b, 0x9f, 0x65, 0x13, 0x43, 0xb8, 0xad, 0xcf, 0xe0)



// CPropPg2::CPropPg2Factory::UpdateRegistry -
// ��ӻ��Ƴ� CPropPg2 ��ϵͳע�����

BOOL CPropPg2::CPropPg2Factory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ����ҳ���͵��ַ�����Դ���� ID �滻����ġ�0����

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
		m_clsid, 0);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CPropPg2::CPropPg2 - ���캯��

// TODO:  ����ҳ������ַ�����Դ���� ID �滻����ġ�0����

CPropPg2::CPropPg2() :
CPropertyPage(IDD, 0)
{

}



// CPropPg2::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CPropPg2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}



// CPropPg2 ��Ϣ�������
