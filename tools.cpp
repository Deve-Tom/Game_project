#include "tools.h"

TCHAR* tools::numToTHAR(double num)
{
	std::string tempStringNum = std::to_string(num);
	const char* tempCharNum = tempStringNum.c_str();
	TCHAR tempTHAR[100];
#ifdef UNICODE
	MultiByteToWideChar(CP_ACP, 0, tempCharNum, -1, tempTHAR, 100);
#else
	strcpy(tempTHAR, tempCharNum);
#endif
	for (int i = 0; i < tempStringNum.size(); i++) {
		if (tempTHAR[i] == '.') {
			tempTHAR[i + 3] = '\0';
			break;
		}
	}
	return std::move(tempTHAR);
}

TCHAR* tools::numToTHAR(int num) {
	using std::string;
	string tempStringNum = std::to_string(num);
	const char* tempCharNum = tempStringNum.c_str();
	TCHAR tempTHAR[10];
#ifdef UNICODE
	MultiByteToWideChar(CP_ACP, 0, tempCharNum, -1, tempTHAR, 10);
#else
	strcpy(tempTHAR, tempCharNum);
#endif
	return std::move(tempTHAR);
}

TCHAR* tools::numToTHAR(std::string data,TCHAR*temp)
{
#ifdef UNICODE  
	_stprintf_s(temp, MAX_PATH, _T("%S"), src.c_str());
#else  
	_stprintf_s(temp, MAX_PATH, _T("%s"), data.c_str());
#endif
	return temp;
}
