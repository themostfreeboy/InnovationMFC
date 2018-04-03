
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MyCtrlBar.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_SHORT, &CMainFrame::OnViewShort)
	ON_COMMAND(ID_VIEW_LONG, &CMainFrame::OnViewLong)
	ON_WM_TIMER()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           //״̬��ָʾ��
	ID_SEPARATOR,           //��ʾ��������
	ID_SEPARATOR,           //��ʾ���������
	ID_INDICATOR_CLOCK,     //��ʾϵͳʱ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	CMainFrame::OnViewShort();

	SetTimer(1, 1000, NULL);//��װ��ʱ����������ʱ������Ϊ1000����



	m_wndStatusBar.SetPaneInfo(1, ID_SEPARATOR, SBPS_POPOUT, 70);
	m_wndStatusBar.SetPaneInfo(2, ID_SEPARATOR, SBPS_POPOUT, 70);
	m_wndStatusBar.SetPaneInfo(m_wndStatusBar.CommandToIndex(ID_INDICATOR_CLOCK), ID_INDICATOR_CLOCK, SBPS_POPOUT, 100);

	return 0;
}


void CMainFrame::OnClose()
{
	KillTimer(1);
	CMDIFrameWnd::OnClose();
}



BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������
void CMainFrame::OnViewShort(void)
{
	//���ù������а�ť�ĸ���
	m_wndToolBar.SetButtons(NULL, 6);
	//���ù������а�ť����Ϣ
	m_wndToolBar.SetButtonInfo(0, ID_VIEW_LONG, TBBS_BUTTON, 9);
	m_wndToolBar.SetButtonInfo(1, ID_SEPARATOR, TBBS_SEPARATOR, 15);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_OPEN, TBBS_BUTTON, 1);
	m_wndToolBar.SetButtonInfo(3, ID_FILE_SAVE, TBBS_BUTTON, 2);
	m_wndToolBar.SetButtonInfo(4, ID_SEPARATOR, TBBS_SEPARATOR, 15);
	m_wndToolBar.SetButtonInfo(5, ID_APP_ABOUT, TBBS_BUTTON, 7);
	//������ͼ
	m_wndToolBar.Invalidate();
	AfxGetApp()->OnIdle(-1);

}



void CMainFrame::OnViewLong(void)
{
	//���ù������а�ť�ĸ���
	m_wndToolBar.SetButtons(NULL, 11);
	//���ù������а�ť����Ϣ
	m_wndToolBar.SetButtonInfo(0, ID_VIEW_SHORT, TBBS_BUTTON, 8);
	m_wndToolBar.SetButtonInfo(1, ID_SEPARATOR, TBBS_SEPARATOR, 15);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_NEW, TBBS_BUTTON, 0);
	m_wndToolBar.SetButtonInfo(3, ID_FILE_OPEN, TBBS_BUTTON, 1);
	m_wndToolBar.SetButtonInfo(4, ID_FILE_SAVE, TBBS_BUTTON, 2);
	m_wndToolBar.SetButtonInfo(5, ID_SEPARATOR, TBBS_SEPARATOR, 15);
	m_wndToolBar.SetButtonInfo(6, ID_EDIT_CUT, TBBS_BUTTON, 3);
	m_wndToolBar.SetButtonInfo(7, ID_EDIT_COPY, TBBS_BUTTON, 4);
	m_wndToolBar.SetButtonInfo(8, ID_EDIT_PASTE, TBBS_BUTTON, 5);
	m_wndToolBar.SetButtonInfo(9, ID_FILE_PRINT, TBBS_BUTTON, 6);
	m_wndToolBar.SetButtonInfo(10, ID_APP_ABOUT, TBBS_BUTTON, 7);
	//������ͼ
	m_wndToolBar.Invalidate();
	AfxGetApp()->OnIdle(-1);

}




void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime time;
	time = CTime::GetCurrentTime();//��ȡϵͳʱ��
	CString str = time.Format("%Hʱ%M��%S��");//����ʱ���ַ����ĸ�ʽ
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_INDICATOR_CLOCK),str);
	CMDIFrameWnd::OnTimer(nIDEvent);
}

