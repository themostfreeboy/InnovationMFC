#pragma once


// CWizPg3 对话框

class CWizPg3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CWizPg3)

public:
	CWizPg3();
	virtual ~CWizPg3();
	virtual BOOL OnSetActive();

// 对话框数据
	enum { IDD = IDD_WIZPAGE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
