
// MyDlgDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDlg.h"
#include "MyDlgDlg.h"
#include "ModalDlg.h"
#include "ModallessDlg.h"
#include "afxdialogex.h"

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


// CMyDlgDlg �Ի���



CMyDlgDlg::CMyDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDlgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BMODAL, &CMyDlgDlg::OnBnClickedBmodal)
	ON_BN_CLICKED(IDC_BMODALLESS, &CMyDlgDlg::OnBnClickedBmodalless)
	ON_BN_CLICKED(IDOK, &CMyDlgDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMyDlgDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMyDlgDlg ��Ϣ�������

BOOL CMyDlgDlg::OnInitDialog()
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

void CMyDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlgDlg::OnPaint()
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
HCURSOR CMyDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMyDlgDlg::OnBnClickedBmodal()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CModalDlg dlg;
	dlg.DoModal();
}


void CMyDlgDlg::OnBnClickedBmodalless()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_pModallessDlg)                                    //������ģʽ�Ի����Ƿ�����
	{                                                       //���û����ģʽ�Ի����ָ�룬�򴴽�һ��
		m_pModallessDlg = new CModallessDlg(this);
		if (m_pModallessDlg->Creat(IDD_MODALLESS_DIALOG, NULL) == TRUE)
			GetDlgItem(IDC_BMODALLESS)->EnableWindow(FALSE);//���á���ģʽ�Ի���ť��
	}
	m_pModallessDlg->ShowWindow(SW_SHOW);
}


void CMyDlgDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	((CMyDlgDlg*)m_pParent)->BoxDone();
	DestroyWindow();
}


void CMyDlgDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
	((CMyDlgDlg*)m_pParent)->BoxDone();
	DestroyWindow();
}




void CMyDlgDlg::BoxDone()
{
	m_pModallessDlg = NULL;                        //ע�⣬����û��ɾ����ģʽ�Ի����ָ��
	GetDlgItem(IDC_BMODALLESS)->EnableWindow(TRUE);//���ť
}


void CMyDlgDlg::ChangeColor(CRect rect, int red, int blue, int green)
{
	int nRed, nGreen, nBlue;
	nRed = red;
	nGreen = green;
	nBlue = blue;
	CBrush br(RGB(nRed, nGreen, nBlue));
	CRect rectNow = rect;
	GetDC()->FillRect(&rectNow, &br);//ʹ��ָ����ˢ���ָ������
}
