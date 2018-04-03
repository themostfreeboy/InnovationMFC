// CMyPropSheet

#include "afxwin.h"
class CMyPropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMyPropSheet)

public:
	CMyPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CMyPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CMyPropSheet();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_ctlEdit;
	CButton m_ctlButton;
	void OnButtonChange();
};


