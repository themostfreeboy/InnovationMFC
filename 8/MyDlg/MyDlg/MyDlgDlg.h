
// MyDlgDlg.h : ͷ�ļ�
//

#pragma once


// CMyDlgDlg �Ի���
class CMyDlgDlg : public CDialogEx
{
// ����
public:
	CMyDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYDLG_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBmodal();
	afx_msg void OnBnClickedBmodalless();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	void BoxDone();
	void ChangeColor(CRect rect, int red, int blue, int green);
	CWnd* m_pParent;
};
