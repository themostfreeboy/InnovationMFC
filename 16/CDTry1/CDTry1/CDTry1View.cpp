
// CDTry1View.cpp : CCDTry1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CDTry1.h"
#endif

#include "CDTry1Doc.h"
#include "CDTry1View.h"
#include "chartdir.h"
#pragma comment (lib,"chartdir51.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCDTry1View

IMPLEMENT_DYNCREATE(CCDTry1View, CView)

BEGIN_MESSAGE_MAP(CCDTry1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCDTry1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOWPICTURE, &CCDTry1View::OnShowpicture)
END_MESSAGE_MAP()

// CCDTry1View 构造/析构

CCDTry1View::CCDTry1View()
{
	// TODO:  在此处添加构造代码

}

CCDTry1View::~CCDTry1View()
{
}

BOOL CCDTry1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCDTry1View 绘制

void CCDTry1View::OnDraw(CDC* /*pDC*/)
{
	CCDTry1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CCDTry1View 打印


void CCDTry1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCDTry1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCDTry1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CCDTry1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CCDTry1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCDTry1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCDTry1View 诊断

#ifdef _DEBUG
void CCDTry1View::AssertValid() const
{
	CView::AssertValid();
}

void CCDTry1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCDTry1Doc* CCDTry1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCDTry1Doc)));
	return (CCDTry1Doc*)m_pDocument;
}
#endif //_DEBUG


// CCDTry1View 消息处理程序


void CCDTry1View::OnShowpicture()
{
	// TODO:  在此添加命令处理程序代码
	CCDTry1View::MyPaintPicture();
}



void CCDTry1View::MyPaintPicture ()
{
	// The data for the line chart
	double data0[] = { 42, 49, 33, 38, 51, 46, 29, 41, 44, 57, 59, 52, 37, 34, 51, 56,
		56, 60, 70, 76, 63, 67, 75, 64, 51 };
	double data1[] = { 50, 55, 47, 34, 42, 49, 63, 62, 73, 59, 56, 50, 64, 60, 67, 67,
		58, 59, 73, 77, 84, 82, 80, 84, 98 };
	double data2[] = { 36, 28, 25, 33, 38, 20, 22, 30, 25, 33, 30, 24, 28, 15, 21, 26,
		46, 42, 48, 45, 43, 52, 64, 60, 70 };

	// The labels for the line chart
	const char *labels[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
		"11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23",
		"24" };

	// Create an XYChart object of size 600 x 300 pixels, with a light blue (EEEEFF)
	// background, black border, 1 pxiel 3D border effect and rounded corners
	XYChart *c = new XYChart(600, 300, 0xeeeeff, 0x000000, 1);
	c->setRoundedFrame();

	// Set the plotarea at (55, 58) and of size 520 x 195 pixels, with white
	// background. Turn on both horizontal and vertical grid lines with light grey
	// color (0xcccccc)
	c->setPlotArea(55, 58, 520, 195, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);

	// Add a legend box at (50, 30) (top of the chart) with horizontal layout. Use 9
	// pts Arial Bold font. Set the background and border color to Transparent.
	c->addLegend(50, 30, false, "arialbd.ttf", 9)->setBackground(Chart::Transparent);

	// Add a title box to the chart using 15 pts Times Bold Italic font, on a light
	// blue (CCCCFF) background with glass effect. white (0xffffff) on a dark red
	// (0x800000) background, with a 1 pixel 3D border.
	c->addTitle("Boxing", "timesbi.ttf", 15)->setBackground(
		0xccccff, 0x000000, Chart::glassEffect());

	// Add a title to the y axis
	c->yAxis()->setTitle("Boxing Force");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]
		))));

	// Display 1 out of 3 labels on the x-axis.
	c->xAxis()->setLabelStep(3);

	// Add a title to the x axis
	c->xAxis()->setTitle("Boxing Time");

	// Add a line layer to the chart
	LineLayer *layer = c->addLineLayer();

	// Set the default line width to 2 pixels
	layer->setLineWidth(2);

	// Add the three data sets to the line layer. For demo purpose, we use a dash
	// line color for the last line
	layer->addDataSet(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0xff0000, "The First Boxing");
	layer->addDataSet(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x008800, "The Second Boxing");
	layer->addDataSet(DoubleArray(data2, (int)(sizeof(data2) / sizeof(data2[0]))),
		c->dashLineColor(0x3333ff, Chart::DashLine), "The Third Boxing");

	MyCreatDirectory();//新建文件夹"D://Boxing"
		

    // Output the chart
	CString cstr1 = MyGetTime();
	CString cstr2 = CString("/c ")+ cstr1;
	c->makeChart(MyCStringToConstChar(cstr1));

	//free up resources
	delete c;

	ShellExecute(NULL, MyCharToLPCTSTR("open"), MyCharToLPCTSTR("C://WINDOWS//system32//cmd.exe"), MyCStringToLPCTSTR(cstr2), NULL, SW_HIDE);
}


void CCDTry1View::MyCreatDirectory()//新建文件夹"D://Boxing"
{
	CString   strFolderPath = CString("D://Boxing");
	if (!PathIsDirectory(strFolderPath))//判断路径是否存在
	{

		//设置属性
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}


LPCTSTR CCDTry1View::MyCharToLPCTSTR(char* szStrtemp)//char*转LPCTSTR
{
	char* szStr=new char[512];//为了避免直接对传入的地址进行改动，新申请一个内存并把传入的内容复制
	strcpy_s(szStr, 512, szStrtemp);//复制传入的内容
	WCHAR wszClassName[512];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
	delete szStr;//释放内存
	WCHAR* wszClassNameReturn=new WCHAR[512];//为了避免直接对传出的地址进行改动，新申请一个内存并把传出的内容复制
	wcscpy_s(wszClassNameReturn, 512, wszClassName);//复制传出的内容
	return wszClassNameReturn;
}



const char* CCDTry1View::MyCStringToConstChar(CString cstr)//CString转const char*
{
	char     *pMBBuffer = (char *)malloc(100);
	const wchar_t  *pWCBuffer = (LPCTSTR)cstr;
	size_t   i = wcslen(pWCBuffer);
	wcstombs_s(&i, pMBBuffer, (size_t)(100),pWCBuffer, (size_t)(100));
	return pMBBuffer;
}

LPCTSTR CCDTry1View::MyCStringToLPCTSTR(CString cstr)//CString转LPCTSTR
{
	
	LPCTSTR lpctstr	= (LPCTSTR)cstr;
	return lpctstr;
}

std::string CCDTry1View::MyCStringToString(CString cstr)//CString转string
{
	CT2A xx(cstr);
	std::string str = xx;
	return str;
}

CString CCDTry1View::MyStringToCString(std::string str)//string转CString
{
	CString cstr(str.c_str());
	return cstr;
}

double CCDTry1View::MyCStringToDouble(CString cstr)//CString转double
{
	double dou;
	dou = _wtof(cstr);
	return dou;
}


const char* CCDTry1View::MyDoubleToChar(double dou)//double转char*
{
	char buffer[512];
	sprintf_s(buffer, "%f", dou);
	return buffer;
}




CString CCDTry1View::MyGetTime()//获取系统时间
{
	CString cstr;
	CTime tm;
	tm = CTime::GetCurrentTime();
	cstr = tm.Format("D://Boxing//%Y%m%d%H%M%S.png");
	return cstr;
}