#pragma once
#ifndef  UIH
#define UIH
#include<iostream>
#include<graphics.h>
#include<mmsyscom.h>
#include<string>
#include<Windows.h>
#include<cmath>
#include<map>
#include<list>
#include"Actor.h"
#include"WarSystem.h"
#include<vector>
#include"Systemloger.h"
#include<memory>
#include<cstdlib>
#pragma comment(lib,"Winmm.lib")
#include"tools.h"
#pragma warning(disable:4996)
using namespace std;
class UI
{
private:
	/*帮助界面*/
	static void helpMenu();
	/*角色选择界面*/
	static void selectMenu(const vector<pair<string, int>>& old = vector<pair<string, int>>());
	/*首次军队创建*/
	static pair<vector<list<Soldier*>>, vector<list<Soldier*>>>creatGrop(vector<pair<string, int>>actorCreat, bool flag = false,
		const vector<list<Soldier*>>& oldGroupA = vector<list<Soldier*>>());
	/*旧军队创建*/
	static const pair<vector<list<Soldier*>>, vector<list<Soldier*>>>creatGrop();
	/*正式战斗界面*/
	static void battleIterface(const pair<vector<list<Soldier*>>, vector<list<Soldier*>>>& data = pair<vector<list<Soldier*>>, vector<list<Soldier*>>>());
	/*结算界面*/
	static void clearIterface(bool result);
public:
	/*开始界面*/
	static void startMenu();
};

#endif // ! UIH