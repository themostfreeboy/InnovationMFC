#pragma once


// CWizPg1 对话框

class CWizPg1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CWizPg1)

public:
	CWizPg1();
	virtual ~CWizPg1();
	virtual BOOL OnSetActive();

// 对话框数据
	enum { IDD = IDD_WIZPAGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
