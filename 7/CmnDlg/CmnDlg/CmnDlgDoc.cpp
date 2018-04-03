
// CmnDlgDoc.cpp : CCmnDlgDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CCmnDlgDoc ����/����

CCmnDlgDoc::CCmnDlgDoc()
{
	// TODO:  �ڴ����һ���Թ������

}

CCmnDlgDoc::~CCmnDlgDoc()
{
}

BOOL CCmnDlgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CCmnDlgDoc ���л�

void CCmnDlgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CCmnDlgDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CCmnDlgDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CCmnDlgDoc ���

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


// CCmnDlgDoc ����
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