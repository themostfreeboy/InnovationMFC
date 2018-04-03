
// MyExtenDllDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyExtenDll.h"
#include "MyExtenDllDlg.h"
//#include "afxdialogex.h
#pragma comment (lib,"MyRegularDll.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyExtenDllDlg �Ի���



CMyExtenDllDlg::CMyExtenDllDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyExtenDllDlg::IDD, pParent)
	, m_strInput(_T(""))
	, m_strOutput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyExtenDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EINPUT, m_strInput);
	DDX_Text(pDX, IDC_EOUTPUT, m_strOutput);
}

BEGIN_MESSAGE_MAP(CMyExtenDllDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BZERO, IDC_BDOT, OnBnClickedNumber)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BLOG, IDC_BCLEAR, OnBnClickedOperator)
END_MESSAGE_MAP()


// CMyExtenDllDlg ��Ϣ�������

BOOL CMyExtenDllDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyExtenDllDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyExtenDllDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyExtenDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyExtenDllDlg::OnBnClickedNumber(UINT nID)
{
	UpdateData(TRUE);
	switch (nID)
	{
	case IDC_BZERO:m_strInput += "0"; break;
	case IDC_BONE:m_strInput += "1"; break;
	case IDC_BTWO:m_strInput += "2"; break;
	case IDC_BTHREE:m_strInput += "3"; break;
	case IDC_BFOUR:m_strInput += "4"; break;
	case IDC_BFIVE:m_strInput += "5"; break;
	case IDC_BSIX:m_strInput += "6"; break;
	case IDC_BSEVEN:m_strInput += "7"; break;
	case IDC_BEIGHT:m_strInput += "8"; break;
	case IDC_BNINE:m_strInput += "9"; break;
	case IDC_BDOT:m_strInput += "."; break;
	default:break;
	}
	UpdateData(FALSE);
}



void CMyExtenDllDlg::OnBnClickedOperator(UINT nID)
{
	UpdateData(TRUE);
	m_nData = _wtof(m_strInput);//CStringתdouble
	switch (nID)
	{
	case IDC_BLOG://��������
		m_nResult = MyLog(m_nData);
		break;
	case IDC_BSQUARE://ƽ������
		m_nResult = MySquare(m_nData);
		break;
	case IDC_BCUBE://��������
		m_nResult = MyCube(m_nData);
		break;
	case IDC_BSQRT://����������
		m_nResult = MySqrt(m_nData);
		break;
	case IDC_BCLEAR://�������
	    m_strInput = m_strOutput=_T("");
		UpdateData(FALSE);
		break;
	}
	//������������е��ı�
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EOUTPUT);
	char buffer[200];
	sprintf_s(buffer, "%f", m_nResult);//doubleתCString
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	pEdit->SetWindowText(wszClassName1);
}