#pragma once


// CWizPg3 �Ի���

class CWizPg3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CWizPg3)

public:
	CWizPg3();
	virtual ~CWizPg3();
	virtual BOOL OnSetActive();

// �Ի�������
	enum { IDD = IDD_WIZPAGE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
