#pragma once

#ifdef _WIN32_WCE
#error "Windows CE ��֧�� COlePropertyPage��"
#endif 

// CPropPg1 : ����ҳ�Ի���

class CPropPg1 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropPg1)
	DECLARE_OLECREATE_EX(CPropPg1)

// ���캯��
public:
	CPropPg1();

// �Ի�������
	enum { IDD = IDD_PROPPAGE1 };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};
