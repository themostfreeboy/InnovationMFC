#pragma once


// CWizPg1 �Ի���

class CWizPg1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CWizPg1)

public:
	CWizPg1();
	virtual ~CWizPg1();
	virtual BOOL OnSetActive();

// �Ի�������
	enum { IDD = IDD_WIZPAGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
