#pragma once
#include "afx.h"
class CMyCompute:public CObject
{
public:
	CMyCompute(void);
	CMyCompute(double data);
	~CMyCompute(void);
public:
	double m_data;
public:
	double MyLog(void);
	double MyLog(double data);
	double MyCube(void);
	double MyCube(double data);
	double MySquare(void);
	double MySquare(double data);
	double MySqrt(void);
	double MySqrt(double data);
};

