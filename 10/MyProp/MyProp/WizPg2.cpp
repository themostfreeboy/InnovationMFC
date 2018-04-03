// WizPg2.cpp : 实现文件
//

#include "stdafx.h"
#include "MyProp.h"
#include "WizPg2.h"
#include "afxdialogex.h"


// CWizPg2 对话框

IMPLEMENT_DYNAMIC(CWizPg2, CPropertyPage)

CWizPg2::CWizPg2()
	: CPropertyPage(CWizPg2::IDD)
{

}

CWizPg2::~CWizPg2()
{
}

void CWizPg2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWizPg2, CPropertyPage)
END_MESSAGE_MAP()


// CWizPg2 消息处理程序
BOOL CWizPg2::OnSetActive()
{
	CPropertySheet* pWiz = (CPropertySheet*)GetParent();
	pWiz->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}