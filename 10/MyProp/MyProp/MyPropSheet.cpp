#include "stdafx.h"
#include "MyProp.h"
#include "MyPropSheet.h"


// CMyPropSheet

IMPLEMENT_DYNAMIC(CMyPropSheet, CPropertySheet)

CMyPropSheet::CMyPropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CMyPropSheet::CMyPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CMyPropSheet::~CMyPropSheet()
{
}


BEGIN_MESSAGE_MAP(CMyPropSheet, CPropertySheet)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE,OnButtonChange)
END_MESSAGE_MAP()


// CMyPropSheet 消息处理程序


BOOL CMyPropSheet::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	CRect rectButton;
	CRect rectSheet;
	CRect rectTab;
	GetDlgItem(IDOK)->GetWindowRect(rectButton);//获取属性表中“确定”按钮的大小
	GetTabControl()->GetWindowRect(rectTab);//获取属性表中标签的大小
	GetWindowRect(rectSheet);//获取属性表窗口的大小
	ScreenToClient(rectButton);//将这三个区域转为客户坐标
	ScreenToClient(rectTab);
	ScreenToClient(rectSheet);
	//重新设置属性表窗口的大小，增加属性表的宽度
	SetWindowPos(NULL, 0, 0, rectSheet.Width() + 100, rectSheet.Height(), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	//创建编辑控件
	m_ctlEdit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_TABSTOP, rectSheet.Width(), 150, 80, 20, m_hWnd, 0, 0);
	m_ctlEdit.SetFont(GetFont());//设置编辑控件中的字体
	//设置新添加的按钮控件的矩形区域
	int width, height;
	width = rectButton.Width();
	height = rectButton.Height();
	rectButton.left = rectSheet.Width();
	rectButton.top = rectTab.Height() - height;
	rectButton.right = rectSheet.Width() + width;
	rectButton.bottom = rectTab.Height();
	//创建按钮控件
	char* szStr1 = "Change";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	m_ctlButton.Create(wszClassName1, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, rectButton, this, IDC_BUTTON_CHANGE);
	m_ctlButton.SetFont(GetFont());//设置按钮控件上的字体
	CenterWindow();//使属性表居中显示
	return bResult;
}


void CMyPropSheet::OnButtonChange()
{
	CString str;
	m_ctlEdit.GetWindowText(str);//获取编辑控件中的字符串
	CString strCaption = str;
	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = (LPTSTR)((LPCTSTR)strCaption);
	GetTabControl()->SetItem(GetActiveIndex(), &tcItem);//设置属性页的标题
}

