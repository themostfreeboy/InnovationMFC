// WizPg3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyProp.h"
#include "WizPg3.h"
#include "afxdialogex.h"


// CWizPg3 �Ի���

IMPLEMENT_DYNAMIC(CWizPg3, CPropertyPage)

CWizPg3::CWizPg3()
	: CPropertyPage(CWizPg3::IDD)
{

}

CWizPg3::~CWizPg3()
{
}

void CWizPg3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWizPg3, CPropertyPage)
END_MESSAGE_MAP()


// CWizPg3 ��Ϣ�������
BOOL CWizPg3::OnSetActive()
{
	CPropertySheet* pWiz = (CPropertySheet*)GetParent();
	pWiz->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}