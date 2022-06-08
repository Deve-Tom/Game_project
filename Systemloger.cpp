#include "Systemloger.h"
#pragma warning(disable:4996)
int Systemloger::FLAG_CLICK = Systemloger::CLICKLOG;
int Systemloger::FLAG_BATTEL = Systemloger::BATTELLOG;

std::string Systemloger::getTime() {
	time_t timep;
	time(&timep); //��ȡtime_t���͵ĵ�ǰʱ��
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));//�����ں�ʱ����и�ʽ��
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
			MessageBox(0, "�ļ��򿪴���", "����", MB_OK);
			return false;
		}
	}
	else if (_flag == Systemloger::BATTELLOG) {
		out.open("dataGameBattle.log", std::ios_base::app);
		if (out.is_open()) {
			out << getTime() << " " << data << std::endl;
			out.close();
		}
		else {
			MessageBox(0, "�ļ��򿪴���", "����", MB_OK);
			return false;
		}
	}
	else return false;
	return true;
}

std::string& Systemloger::logRead(std::string& data,int _flag) {
	std::ifstream in;
	if (_flag == Systemloger::BATTELLOG) {
	in.open("dataGame.log", std::ios_base::in);
	if (in.is_open()) {
	while (!in.eof()) {
		getline(in, data);
	}
	in.close();
	}
	else {
		MessageBox(0, "�ļ��򿪴���", "����", MB_OK);
	}
	}
	else {
		in.open("dataGameBattle.log", std::ios_base::in);
		if (in.is_open()) {
			while (!in.eof()) {
				getline(in, data);
			}
			in.close();
		}
		else {
			MessageBox(0, "�ļ��򿪴���", "����", MB_OK);
		}
	}
	return data;
}
