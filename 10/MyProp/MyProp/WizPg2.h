#pragma once


// CWizPg2 �Ի���

class CWizPg2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CWizPg2)

public:
	CWizPg2();
	virtual ~CWizPg2();
	virtual BOOL OnSetActive();

// �Ի�������
	enum { IDD = IDD_WIZPAGE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
