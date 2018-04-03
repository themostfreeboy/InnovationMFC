#pragma once

#ifdef _WIN32_WCE
#error "Windows CE 不支持 COlePropertyPage。"
#endif 

// CPropPg1 : 属性页对话框

class CPropPg1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropPg1)
	DECLARE_OLECREATE_EX(CPropPg1)

// 构造函数
public:
	CPropPg1();

// 对话框数据
	enum { IDD = IDD_PROPPAGE1 };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};
