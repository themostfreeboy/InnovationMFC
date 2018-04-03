
// CmnDlgDoc.cpp : CCmnDlgDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CmnDlg.h"
#endif

#include "CmnDlgDoc.h"

#include <propkey.h>


#include "FileDialogEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCmnDlgDoc

IMPLEMENT_DYNCREATE(CCmnDlgDoc, CDocument)

BEGIN_MESSAGE_MAP(CCmnDlgDoc, CDocument)
END_MESSAGE_MAP()


// CCmnDlgDoc 构造/析构

CCmnDlgDoc::CCmnDlgDoc()
{
	// TODO:  在此添加一次性构造代码

}

CCmnDlgDoc::~CCmnDlgDoc()
{
}

BOOL CCmnDlgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CCmnDlgDoc 序列化

void CCmnDlgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CCmnDlgDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CCmnDlgDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CCmnDlgDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CCmnDlgDoc 诊断

#ifdef _DEBUG
void CCmnDlgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCmnDlgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCmnDlgDoc 命令
void CCmnDlgDoc::OnFileOpen()
{
	CString sFilter = CString("MyType(*.mine)|*.mine|YourType(*.yours)|*.yours|");
	CFileDialogEx dlg(FALSE, NULL, GetTitle(), OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCTSTR)sFilter, NULL);
	char* szStr1 = "Mine-Open File";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	dlg.m_ofn.lpstrTitle = wszClassName1;
	dlg.DoModal();
}


void CCmnDlgDoc::OnFileSave()
{
	CString sFilter = CString("MyType(*.mine)|*.mine|YourType(*.yours)|*.yours|");
	CFileDialogEx dlg(FALSE, NULL, GetTitle(), OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, (LPCTSTR)sFilter, NULL);
	char* szStr1 = "Mine-Save File";
	WCHAR wszClassName1[256];
	memset(wszClassName1, 0, sizeof(wszClassName1));
	MultiByteToWideChar(CP_ACP, 0, szStr1, strlen(szStr1) + 1, wszClassName1, sizeof(wszClassName1) / sizeof(wszClassName1[0]));
	dlg.m_ofn.lpstrTitle = wszClassName1;
	dlg.DoModal();
}