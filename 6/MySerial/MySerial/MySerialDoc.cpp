
// MySerialDoc.cpp : CMySerialDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MySerial.h"
#endif

#include "MySerialDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMySerialDoc

IMPLEMENT_DYNCREATE(CMySerialDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySerialDoc, CDocument)
END_MESSAGE_MAP()


// CMySerialDoc ����/����

CMySerialDoc::CMySerialDoc()
: m_strDocName(_T(""))
, m_strDocEmail(_T(""))
, m_strDocAge(_T(""))
, m_nDocGender(0)
{
	// TODO:  �ڴ����һ���Թ������

}

CMySerialDoc::~CMySerialDoc()
{
}

BOOL CMySerialDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMySerialDoc ���л�

void CMySerialDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
		ar << m_strDocName << m_strDocAge << m_nDocGender << m_strDocEmail;
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
		ar >> m_strDocName >> m_strDocAge >> m_nDocGender >> m_strDocEmail;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMySerialDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMySerialDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMySerialDoc::SetSearchContent(const CString& value)
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

// CMySerialDoc ���

#ifdef _DEBUG
void CMySerialDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySerialDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMySerialDoc ����
