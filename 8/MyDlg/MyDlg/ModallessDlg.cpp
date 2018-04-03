// ModallessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDlg.h"
#include "ModallessDlg.h"
#include "afxdialogex.h"


// CModallessDlg �Ի���

IMPLEMENT_DYNAMIC(CModallessDlg, CDialog)

CModallessDlg::CModallessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModallessDlg::IDD, pParent)
	, m_pParent(NULL)
	, m_pModallessDlg(NULL)
	, m_strRed(_T(""))
	, m_strGreen(_T(""))
	, m_strBlue(_T(""))
{
	m_pParent = pParent;
}

CModallessDlg::~CModallessDlg()
{
}

void CModallessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_RED, m_ctlSLRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_ctlSLGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_ctlSLBlue);
	DDX_Control(pDX, IDC_SPIN_RED, m_ctlSpinRed);
	DDX_Control(pDX, IDC_SPIN_GREEN, m_ctlSpinGreen);
	DDX_Control(pDX, IDC_SPIN_BLUE, m_ctlSpinBlue);
	DDX_Control(pDX, IDC_ERED, m_ctlERed);
	DDX_Text(pDX, IDC_ERED, m_strRed);
	DDX_Control(pDX, IDC_EGREEN, m_ctlEGreen);
	DDX_Text(pDX, IDC_EGREEN, m_strGreen);
	DDX_Text(pDX, IDC_EBLUE, m_strBlue);
	DDX_Control(pDX, IDC_EBLUE, m_ctlEBlue);
}


BEGIN_MESSAGE_MAP(CModallessDlg, CDialog)
	ON_WM_HSCROLL()
//	ON_EN_UPDATE(IDC_ERED, &CModallessDlg::OnBuddyUpdate)
//	ON_EN_UPDATE(IDC_EGREEN, &CModallessDlg::OnBuddyupdate)
ON_EN_UPDATE(IDC_ERED, &CModallessDlg::OnEnUpdateEred)
ON_EN_UPDATE(IDC_EGREEN, &CModallessDlg::OnEnUpdateEgreen)
ON_EN_UPDATE(IDC_EBLUE, &CModallessDlg::OnEnUpdateEblue)
ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CModallessDlg ��Ϣ�������


void CModallessDlg::PostNcDestroy()
{
	delete this;
}




BOOL CModallessDlg::OnInitDialog()
{
	//���û���Ĺ�����Χ
	m_ctlSLRed.SetRange(0, 255);
	m_ctlSLGreen.SetRange(0, 255);
	m_ctlSLBlue.SetRange(0, 255);
	//���û���ĵ�ǰλ��
	m_ctlSLRed.SetPos(128);
	m_ctlSLGreen.SetPos(128);
	m_ctlSLBlue.SetPos(128);
	//���û���̶����ӵ�Ƶ��
	m_ctlSLRed.SetTicFreq(8);
	m_ctlSLGreen.SetTicFreq(8);
	m_ctlSLBlue.SetTicFreq(8);
	//�����ƶ����ʱ�ı���ֵ�Ĵ�С
	m_ctlSLRed.SetPageSize(8);
	m_ctlSLGreen.SetPageSize(8);
	m_ctlSLBlue.SetPageSize(8);
	//�����ƶ�һ��ʱ�ı���ֵ�Ĵ�С
	m_ctlSLRed.SetLineSize(1);
	m_ctlSLGreen.SetLineSize(1);
	m_ctlSLBlue.SetLineSize(1);


	//������ֵ����ť�ؼ��Ļ�鴰��
	m_ctlSpinRed.SetBuddy(&m_ctlERed);
	m_ctlSpinGreen.SetBuddy(&m_ctlEGreen);
	m_ctlSpinBlue.SetBuddy(&m_ctlEBlue);
	//������ֵ����ť�ؼ��ĵ�ǰλ��
	m_ctlSpinRed.SetRange(0,255);
	m_ctlSpinGreen.SetRange(0, 255);
	m_ctlSpinBlue.SetRange(0, 255);
	m_ctlSpinRed.SetPos(128);
	m_ctlSpinGreen.SetPos(128);
	m_ctlSpinBlue.SetPos(128);


	//���ù������Ĺ�����Χ
	m_ctlSLRed.SetScrollRange(IDC_SCROLLBAR_RED,0, 255);
	m_ctlSLGreen.SetScrollRange(IDC_SCROLLBAR_GREEN,0, 255);
	m_ctlSLBlue.SetScrollRange(IDC_SCROLLBAR_BLUE,0, 255);
	//���ù������ĵ�ǰλ��
	m_ctlSLRed.SetScrollPos(IDC_SCROLLBAR_RED,128);
	m_ctlSLGreen.SetScrollPos(IDC_SCROLLBAR_GREEN, 128);
	m_ctlSLBlue.SetScrollPos(IDC_SCROLLBAR_BLUE, 128);
}


void CModallessDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	BYTE nRed, nGreen, nBlue;
	//��ȡ����ĵ�ǰλ��
	nRed = m_ctlSLRed.GetPos();
	nGreen = m_ctlSLGreen.GetPos();
	nBlue = m_ctlSLBlue.GetPos();
	//ȷ����Ҫ������ɫ�ĶԻ�������
	CRect rect(195, 35, 275, 105);
	//�������Ի����OnChangeColor�����ı���ɫ
	((CMyDlgDlg*)m_pParent)->ChangeColor(rect, nRed, nGreen, nBlue);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}




void CModallessDlg::OnEnUpdateEred()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// �������Խ� EM_SETEVENTMASK ��Ϣ���͵��ÿؼ���
	// ͬʱ�� ENM_UPDATE ��־�������㵽 lParam �����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnBuddyUpdate();
}


void CModallessDlg::OnEnUpdateEgreen()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// �������Խ� EM_SETEVENTMASK ��Ϣ���͵��ÿؼ���
	// ͬʱ�� ENM_UPDATE ��־�������㵽 lParam �����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnBuddyUpdate();
}


void CModallessDlg::OnEnUpdateEblue()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// �������Խ� EM_SETEVENTMASK ��Ϣ���͵��ÿؼ���
	// ͬʱ�� ENM_UPDATE ��־�������㵽 lParam �����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnBuddyUpdate();
}


void CModallessDlg::OnBuddyUpdate()
{
	//��ȡ�༭�ؼ��е��ı�
	m_ctlERed.GetWindowText(m_strRed);
	m_ctlEGreen.GetWindowText(m_strGreen);
	m_ctlEBlue.GetWindowText(m_strBlue);
	//���ı��ַ�ת��Ϊ����
	INT nRed = StringToInt(&m_strRed);
	INT nGreen = StringToInt(&m_strGreen);
	INT nBlue = StringToInt(&m_strBlue);
	//������ֵȡֵ����Ч��Χ
	if (nRed > 255)        nRed = 255;
	else if (nRed < 0)       nRed = 0;
	if (nGreen > 255)        nGreen = 255;
	else if (nGreen < 0)       nGreen = 0;
	if (nBlue > 255)        nBlue = 255;
	else if (nBlue < 0)       nBlue = 0;
	//ָ��Ҫ�ı���ɫ�ĶԻ�������
	CRect rect(115, 110, 195, 180);
	//�������Ի����ChangeColoe�����ı���ɫ
	((CMyDlgDlg*)m_pParent)->ChangeColor(rect, nRed, nGreen, nBlue);
}


int CModallessDlg::StringToInt(CString* psInt)
{
	return _ttoi(*psInt);
}


void CModallessDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	INT nMax, nMin, nCurPos;
	nCurPos = pScrollBar->GetScrollPos();
	switch (nSBCode)
	{
	        case SB_LINEDOWN://����������¡������
				nCurPos += 1;
				break;
			case SB_LINEUP://����������ϡ������
				nCurPos -= 1;
				break;
			case SB_PAGEDOWN://�������PAGEDOWN����
				nCurPos += 10;
				break;
			case SB_PAGEUP://�������PAGEUP����
				nCurPos -= 10;
				break;
			case SB_THUMBTRACK://���������
				nCurPos = nPos;
				break;
			default:
				break;
	}
	//���ù������ĵ�ǰλ��
	pScrollBar->SetScrollPos(nCurPos);
	BYTE nRed, nGreen, nBlue;
	//����������λ�õ���RGBֵ
	nRed = m_ctlSLRed.GetScrollPos(IDC_SCROLLBAR_RED);
	nGreen = m_ctlSLGreen.GetScrollPos(IDC_SCROLLBAR_GREEN);
	nBlue = m_ctlSLBlue.GetScrollPos(IDC_SCROLLBAR_BLUE);
	//����Ҫ�ı���ɫ������
	CRect rect(275, 110, 355, 180);
	//�������Ի����ChangeColor�����ı���ɫ
	((CMyDlgDlg*)m_pParent)->ChangeColor(rect, nRed, nGreen, nBlue);
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
