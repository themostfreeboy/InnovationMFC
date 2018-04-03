// ChildView.cpp : CChildView 类的实现
//

#include "stdafx.h"
#include "AccelerationReader.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_OPEN, &CChildView::OnFileOpen)
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	CRect   rect;   
	GetClientRect(&rect);  
	listCtrl.MoveWindow(&rect);

	// 不要为绘制消息而调用 CWnd::OnPaint()
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	listCtrl.CreateEx(LVS_EX_GRIDLINES,WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT,rect,this,1);
	listCtrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	CreateListColumns();
	return 0;
}

void CChildView::CreateListColumns(void)
{
	LV_COLUMN lvColumn;
	//Column 0 
	lvColumn.mask = LVCF_WIDTH|LVCF_TEXT|LVCF_FMT|LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 100;
	lvColumn.iSubItem = 0;
	lvColumn.pszText = _T("序号");
	listCtrl.InsertColumn(0,&lvColumn);

	//Column 1 
	lvColumn.mask = LVCF_WIDTH|LVCF_TEXT|LVCF_FMT|LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_RIGHT;
	lvColumn.cx = 200;
	lvColumn.iSubItem = 1;
	lvColumn.pszText = _T("时间/s");
	listCtrl.InsertColumn(1,&lvColumn);

	//Column 2 
	lvColumn.mask = LVCF_WIDTH|LVCF_TEXT|LVCF_FMT|LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_RIGHT;
	lvColumn.cx = 200;
	lvColumn.iSubItem = 2;
	lvColumn.pszText = _T("力量/kgf");
	listCtrl.InsertColumn(2,&lvColumn);


}

void CChildView::OnFileOpen()
{
	// TODO: Add your command handler code here
	LPCTSTR filters = _T("拳击数据文档(*.dat)|*.dat||");
	CFileDialog fileDlg(TRUE,NULL,NULL,0,filters);
	INT_PTR result = fileDlg.DoModal();
	if(result!=IDOK)
		return;
	//GetFilename & Read
	CString m_openFileName = fileDlg.GetPathName();
	openDataFile(m_openFileName);
}

void CChildView::openDataFile(CString fileName)
{
	CFile file;
	CFileException Error;
	LPCTSTR szFilename = fileName;
	
	//File Open
	file.Open(szFilename,CFile::modeRead,&Error);
	if(file.GetLength()%8!=0)
	{
		//File Length Error
		 MessageBox(_T("Error file format!"),_T("Error"),MB_OK);
		 return;
	}

	listCtrl.DeleteAllItems();
	//Add data
	int numRecords = (int)file.GetLength()/8;
	int index,impactIndex = 0;
	int time,impact;
	wchar_t buf[20];
	int split = 0;
	for(int i=1;i<=numRecords;i++)
	{
		file.Read(&time,4);
		file.Read(&impact,4);

		if(!impact)
		{
			if(!split)
			{
				index = listCtrl.InsertItem(i,_T("---"));
				listCtrl.SetItemText(index,1,_T("--------"));
				listCtrl.SetItemText(index,2,_T("--------"));
				impactIndex = 0;
			}
			split = 1;
		}
		else
		{
			impactIndex++;
			swprintf(buf,20,_T("%d"),impactIndex);
			index = listCtrl.InsertItem(i,buf);
			swprintf(buf,20,_T("%6.2f"),time/100.0);
			listCtrl.SetItemText(index,1,buf);
			swprintf(buf,20,_T("%d"),impact);
			listCtrl.SetItemText(index,2,buf);

			split = 0;
		}
	}



	//File close
	file.Close();
}
