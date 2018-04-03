#include "string"


class CMyConvert
{
public:
	LPCTSTR MyCharToLPCTSTR(char* szStr);//char*תLPCTSTR
	const char* MyCStringToConstChar(CString cstr);//CStringתconst char*
	LPCTSTR MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
	std::string MyCStringToString(CString cstr);//CStringתstring
	CString MyStringToCString(std::string str);//stringתCString
	double MyCStringToDouble(CString cstr);//CStringתdouble
	const char* MyDoubleToChar(double dou);//doubleתconst char*
};