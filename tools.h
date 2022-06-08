#pragma once
#ifndef TOOLS
#define TOOLS
#include<graphics.h>
#include<string>
#pragma warning(disable:4996)
class tools
{
public:
	/*数字转化为TCHAR工具*/
	static TCHAR* numToTHAR(double num);
	static TCHAR* numToTHAR(int num);
	static TCHAR* numToTHAR(std::string data, TCHAR* temp);
};
#endif
