// WizPg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyProp.h"
#include "WizPg1.h"
#include "afxdialogex.h"


// CWizPg1 �Ի���

IMPLEMENT_DYNAMIC(CWizPg1, CPropertyPage)

CWizPg1::CWizPg1()
	: CPropertyPage(CWizPg1::IDD)
{

}

CWizPg1::~CWizPg1()
{
}

void CWizPg1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWizPg1, CPropertyPage)
END_MESSAGE_MAP()


// CWizPg1 ��Ϣ�������
BOOL CWizPg1::OnSetActive()
{
	CPropertySheet* pWiz = (CPropertySheet*)GetParent();
	pWiz->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}

