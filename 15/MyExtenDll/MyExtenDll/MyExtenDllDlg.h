
// MyExtenDllDlg.h : ͷ�ļ�
//

#pragma once
extern "C" _declspec(dllimport) double MyLog(double);
extern "C" _declspec(dllimport) double MySquare(double);
extern "C" _declspec(dllimport) double MyCube(double);
extern "C" _declspec(dllimport) double MySqrt(double);

// CMyExtenDllDlg �Ի���
class CMyExtenDllDlg : public CDialogEx
{
// ����
public:
	CMyExtenDllDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYEXTENDLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNumber(UINT nID);
	afx_msg void OnBnClickedOperator(UINT nID);
	CString m_strInput;
	CString m_strOutput;
	double m_nData = 0;
	double m_nResult = 0;
};
