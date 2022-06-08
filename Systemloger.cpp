#include "Systemloger.h"
#pragma warning(disable:4996)
int Systemloger::FLAG_CLICK = Systemloger::CLICKLOG;
int Systemloger::FLAG_BATTEL = Systemloger::BATTELLOG;

std::string Systemloger::getTime() {
	time_t timep;
	time(&timep); //获取time_t类型的当前时间
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));//对日期和时间进行格式化
	return tmp;
}

bool Systemloger::logWrite(const std::string& data,int _flag) {
	std::ofstream out;
	if (_flag == Systemloger::CLICKLOG) {
		out.open("dataGameClick.log", std::ios_base::app);
		if (out.is_open()) {
			out << getTime() << " " << data << std::endl;
			out.close();
		}
		else {
			MessageBox(0, "文件打开错误！", "错误", MB_OK);
			return false;
		}
	}
	else if (_flag == Systemloger::BATTELLOG) {
		out.open("dataGameBattle.log", std::ios_base::app);
		if (out.is_open()) {
			out << data << std::endl;
			out.close();
		}
		else {
			MessageBox(0, "文件打开错误！", "错误", MB_OK);
			return false;
		}
	}
	else if (_flag == Systemloger::OLDDATA) {
		out.open("dataGameOld.log", std::ios_base::app);
		if (out.is_open()) {
			out << data << std::endl;
			out.close();
		}
		else {
			MessageBox(0, "文件打开错误！", "错误", MB_OK);
			return false;
		}
	}
	else return false;
	return true;
}

bool Systemloger::logWrite(const int& data, int _flag) {
	std::ofstream out;
	if (_flag == Systemloger::CLICKLOG) {
		out.open("dataGameClick.log", std::ios_base::app);
		if (out.is_open()) {
			out << getTime() << " " << data << std::endl;
			out.close();
		}
		else {
			MessageBox(0, "文件打开错误！", "错误", MB_OK);
			return false;
		}
	}
	else if (_flag == Systemloger::BATTELLOG) {
		out.open("dataGameBattle.log", std::ios_base::app);
		if (out.is_open()) {
			out << data << std::endl;
			out.close();
		}
		else {
			MessageBox(0, "文件打开错误！", "错误", MB_OK);
			return false;
		}
	}
	else if (_flag == Systemloger::OLDDATA) {
		out.open("dataGameOld.log", std::ios_base::app);
		if (out.is_open()) {
			out << data << std::endl;
			out.close();
		}
		else {
			MessageBox(0, "文件打开错误！", "错误", MB_OK);
			return false;
		}
	}
	else return false;
	return true;
}

std::fstream& Systemloger::logRead(std::fstream& in,int _flag) {
	if (_flag == Systemloger::BATTELLOG) {
	in.open("dataGameBattle.log", std::ios_base::in);
	if (in.is_open()) {
		return in;
	}
	else {
		return in;
	}
	}
	else if(_flag == Systemloger::OLDDATA) {
		in.open("dataGameOld.log", std::ios_base::in);
		if (in.is_open()) {
			return in;
		}
		else {
			return in;
		}
	}
	return in;
}

const char* Systemloger::fileName(int _flag) {
	if (_flag == Systemloger::OLDDATA) return "dataGameOld.log";
	if (_flag == Systemloger::BATTELLOG) return "dataGameBattle.log";
	if (_flag == Systemloger::CLICKLOG) return "dataGameClick.log";
}
