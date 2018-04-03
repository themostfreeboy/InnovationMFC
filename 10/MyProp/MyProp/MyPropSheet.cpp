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


// CMyPropSheet ��Ϣ�������


BOOL CMyPropSheet::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	CRect rectButton;
	CRect rectSheet;
	CRect rectTab;
	GetDlgItem(IDOK)->GetWindowRect(rectButton);//��ȡ���Ա��С�ȷ������ť�Ĵ�С
	GetTabControl()->GetWindowRect(rectTab);//��ȡ���Ա��б�ǩ�Ĵ�С
	GetWindowRect(rectSheet);//��ȡ���Ա��ڵĴ�С
	ScreenToClient(rectButton);//������������תΪ�ͻ�����
	ScreenToClient(rectTab);
	ScreenToClient(rectSheet);
	//�����������Ա��ڵĴ�С���������Ա�Ŀ��
	SetWindowPos(NULL, 0, 0, rectSheet.Width() + 100, rectSheet.Height(), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	//�����༭�ؼ�
	m_ctlEdit.CreateEx(WS_EX_CLIENTEDGE, _T("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_TABSTOP, rectSheet.Width(), 150, 80, 20, m_hWnd, 0, 0);
	m_ctlEdit.SetFont(GetFont());//���ñ༭�ؼ��е�����
	//��������ӵİ�ť�ؼ��ľ�������
	int width, height;
	width = rectButton.Width();
	height = rectButton.Height();
	rectButton.left = rectSheet.Width();
	rectButton.top = rectTab.Height() - height;
	rectButton.right = rectSheet.Width() + width;
	rectButton.bottom = rectTab.Height();
	//������ť�ؼ�
	char* szStr1 = "Change";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	m_ctlButton.Create(wszClassName1, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, rectButton, this, IDC_BUTTON_CHANGE);
	m_ctlButton.SetFont(GetFont());//���ð�ť�ؼ��ϵ�����
	CenterWindow();//ʹ���Ա������ʾ
	return bResult;
}


void CMyPropSheet::OnButtonChange()
{
	CString str;
	m_ctlEdit.GetWindowText(str);//��ȡ�༭�ؼ��е��ַ���
	CString strCaption = str;
	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = (LPTSTR)((LPCTSTR)strCaption);
	GetTabControl()->SetItem(GetActiveIndex(), &tcItem);//��������ҳ�ı���
}

