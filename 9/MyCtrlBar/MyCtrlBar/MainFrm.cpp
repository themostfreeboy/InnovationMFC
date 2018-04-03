
// MainFrm.cpp : CMainFrame 类的实现
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
	ID_SEPARATOR,           //状态行指示器
	ID_SEPARATOR,           //显示鼠标横坐标
	ID_SEPARATOR,           //显示鼠标纵坐标
	ID_INDICATOR_CLOCK,     //显示系统时间
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	CMainFrame::OnViewShort();

	SetTimer(1, 1000, NULL);//安装定时器，并将其时间间隔设为1000毫秒



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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序
void CMainFrame::OnViewShort(void)
{
	//设置工具栏中按钮的个数
	m_wndToolBar.SetButtons(NULL, 6);
	//设置工具栏中按钮的信息
	m_wndToolBar.SetButtonInfo(0, ID_VIEW_LONG, TBBS_BUTTON, 9);
	m_wndToolBar.SetButtonInfo(1, ID_SEPARATOR, TBBS_SEPARATOR, 15);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_OPEN, TBBS_BUTTON, 1);
	m_wndToolBar.SetButtonInfo(3, ID_FILE_SAVE, TBBS_BUTTON, 2);
	m_wndToolBar.SetButtonInfo(4, ID_SEPARATOR, TBBS_SEPARATOR, 15);
	m_wndToolBar.SetButtonInfo(5, ID_APP_ABOUT, TBBS_BUTTON, 7);
	//更新视图
	m_wndToolBar.Invalidate();
	AfxGetApp()->OnIdle(-1);

}



void CMainFrame::OnViewLong(void)
{
	//设置工具栏中按钮的个数
	m_wndToolBar.SetButtons(NULL, 11);
	//设置工具栏中按钮的信息
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
	//更新视图
	m_wndToolBar.Invalidate();
	AfxGetApp()->OnIdle(-1);

}




void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime time;
	time = CTime::GetCurrentTime();//获取系统时间
	CString str = time.Format("%H时%M分%S秒");//设置时间字符串的格式
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(ID_INDICATOR_CLOCK),str);
	CMDIFrameWnd::OnTimer(nIDEvent);
}

