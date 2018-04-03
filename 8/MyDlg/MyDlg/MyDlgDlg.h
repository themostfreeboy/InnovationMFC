
// MyDlgDlg.h : 头文件
//

#pragma once


// CMyDlgDlg 对话框
class CMyDlgDlg : public CDialogEx
{
// 构造
public:
	CMyDlgDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
