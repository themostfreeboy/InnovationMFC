#pragma once

#ifdef _WIN32_WCE
#error "Windows CE ��֧�� COlePropertyPage��"
#endif 

// CPropPg2 : ����ҳ�Ի���

class CPropPg2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CPropPg2)
	DECLARE_OLECREATE_EX(CPropPg2)

// ���캯��
public:
	CPropPg2();

// �Ի�������
	enum { IDD = IDD_PROPPAGE2 };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};
