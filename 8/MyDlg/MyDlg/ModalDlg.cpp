// ModalDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDlg.h"
#include "ModalDlg.h"
#include "afxdialogex.h"


// CModalDlg �Ի���

IMPLEMENT_DYNAMIC(CModalDlg, CDialog)

CModalDlg::CModalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModalDlg::IDD, pParent)
	, m_strLess(_T(""))
	, m_strMore(_T(""))
	, m_strPgmName(_T(""))
	, m_bEnableLeft(FALSE)
	, m_bEnableRight(FALSE)
	, m_bIsHide(FALSE)
{

}

CModalDlg::~CModalDlg()
{
}

void CModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LESS, m_strLess);
	DDX_Text(pDX, IDC_MORE, m_strMore);
	DDX_LBIndex(pDX, IDC_LRECVD, m_ctlRecvd);
	DDX_CBString(pDX, IDC_CBPROGRAM, m_strPgmName);
	DDX_Control(pDX, IDC_BNICON, m_IconBN);
	DDX_Control(pDX, IDC_BNBMP, m_BmpBN);
	DDX_Check(pDX, IDC_CLEFT, m_bEnableLeft);
	DDX_Check(pDX, IDC_CRIGHT, m_bEnableRight);
	DDX_Radio(pDX, IDC_RSHOW, m_bIsHide);
}


BEGIN_MESSAGE_MAP(CModalDlg, CDialog)
	ON_EN_CHANGE(IDC_LESS, &CModalDlg::OnEnChangeLess)
	ON_BN_CLICKED(IDC_BADD, &CModalDlg::OnBnClickedBadd)
	ON_BN_CLICKED(IDC_BRUNPROGRAM, &CModalDlg::OnBnClickedBrunprogram)
	ON_BN_CLICKED(IDC_CLEFT, &CModalDlg::OnBnClickedCleft)
	ON_BN_CLICKED(IDC_CRIGHT, &CModalDlg::OnBnClickedCright)
	ON_BN_CLICKED(IDC_RSHOW, &CModalDlg::OnBnClickedRshow)
END_MESSAGE_MAP()


// CModalDlg ��Ϣ�������


void CModalDlg::OnEnChangeLess()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//���´�������
	m_strMore =(CString) ":)" + m_strLess;
	UpdateData(FALSE);//���¿ؼ���Ϣ
}


void CModalDlg::OnBnClickedBadd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_ctlRecvd.AddString(m_strMore);
	UpdateData(FALSE);
}


void CModalDlg::OnBnClickedBrunprogram()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CString strPgmName;
	strPgmName = m_strPgmName;
	if (strPgmName == "��ͼ")
		WinExec("mspaint.exe", SW_SHOW);
	if (strPgmName == "���±�")
		WinExec("notepad.exe", SW_SHOW);
	if (strPgmName == "ֽ��")
		WinExec("sol.exe", SW_SHOW);
	if (strPgmName == "ɨ��")
		WinExec("winmine.exe", SW_SHOW);
}




void CModalDlg::OnBnClickedCleft()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_bEnableLeft == TRUE)
	{
		GetDlgItem(IDC_LESS)->EnableWindow(TRUE);
		GetDlgItem(IDC_MORE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BADD)->EnableWindow(TRUE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_LESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_MORE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BADD)->EnableWindow(FALSE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(FALSE);
	}
}


void CModalDlg::OnBnClickedCright()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_bEnableRight == TRUE)
	{
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_SICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_SBMP)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_SICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_SBMP)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(FALSE);
	}
}


void CModalDlg::OnBnClickedRshow()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_bIsHide == FALSE)
	{
		//��ʾģʽ�Ի����еĿؼ�
		GetDlgItem(IDC_LESS)->EnableWindow(TRUE);
		GetDlgItem(IDC_MORE)->EnableWindow(TRUE);
		GetDlgItem(IDC_BADD)->EnableWindow(TRUE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(TRUE);
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(TRUE);
		GetDlgItem(IDC_SICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_SBMP)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNICON)->EnableWindow(TRUE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(TRUE);
	}
	else
	{
		//����ģʽ�Ի����еĿؼ�
		GetDlgItem(IDC_LESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_MORE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BADD)->EnableWindow(FALSE);
		GetDlgItem(IDC_LRECVD)->EnableWindow(FALSE);
		GetDlgItem(IDC_CBPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_BRUNPROGRAM)->EnableWindow(FALSE);
		GetDlgItem(IDC_SICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_SBMP)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNICON)->EnableWindow(FALSE);
		GetDlgItem(IDC_BNBMP)->EnableWindow(FALSE);
	}
}


BOOL CModalDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//���ͼ��
	HICON hIcon = AfxGetApp()->LoadIconW(IDR_MAINFRAME);
	m_IconBN.SetIcon(hIcon);
	//���λͼ
	HBITMAP hBitmap = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_BNBMP/*IDB_BITMPBUTTON*/));
	m_BmpBN.SetBitmap(hBitmap);

	m_bEnableLeft = TRUE;
	m_bEnableRight = TRUE;

	return TRUE;
}
