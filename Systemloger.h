#pragma once
#ifndef SYSTEMLOGER
#define SYSTEMLOGER
#include<string>
#include<fstream>
#include<iostream>
#include<Windows.h>
#include"tools.h"
class Systemloger
{
public:
	static enum { CLICKLOG = 0, BATTELLOG = 1, OLDDATA = 2 };
	static int FLAG_CLICK;
	static int FLAG_BATTEL;
public:
	Systemloger() = default;
	virtual ~Systemloger() = default;
	/*��ȡ��־ʱ��*/
	static std::string getTime();
	/*��־߬д*/
	static bool logWrite(const std::string& data, int _flag);
	static bool logWrite(const int& data, int _flag);
	/*��־��ȡ*/
	static std::fstream& logRead(std::fstream&in ,int _flag);
	/*��ȡ��־�ļ���*/
	static const char* fileName(int _flag);
};

#endif