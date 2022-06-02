#pragma once
#ifndef SYSTEMLOGER
#define SYSTEMLOGER
#include<string>
#include<fstream>
#include<iostream>
#include<Windows.h>
class Systemloger
{
public:
	static enum{CLICKLOG=0,BATTELLOG=1};
	static int FLAG_CLICK;
	static int FLAG_BATTEL;
public:
	Systemloger() = default;
	virtual ~Systemloger() = default;
	static std::string getTime();
	static bool logWrite(const std::string& data, int _flag);
	static std::string& logRead(std::string& data, int _flag);
};

#endif