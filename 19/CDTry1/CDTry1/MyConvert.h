#include "string"


class CMyConvert
{
public:
	static LPCTSTR MyCharToLPCTSTR(char* szStr);//char*תLPCTSTR
	static const char* MyCStringToConstChar(CString cstr);//CStringתconst char*
	static LPCTSTR MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
	static std::string MyCStringToString(CString cstr);//CStringתstring
	static CString MyStringToCString(std::string str);//stringתCString
	static double MyCStringToDouble(CString cstr);//CStringתdouble
	static const char* MyDoubleToChar(double dou);//doubleתconst char*
};