#pragma once


// CWizPg2 对话框

class CWizPg2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CWizPg2)

public:
	CWizPg2();
	virtual ~CWizPg2();
	virtual BOOL OnSetActive();

// 对话框数据
	enum { IDD = IDD_WIZPAGE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
