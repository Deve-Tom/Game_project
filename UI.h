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
	/*��������*/
	static void helpMenu();
	/*��ɫѡ�����*/
	static void selectMenu(const vector<pair<string, int>>& old = vector<pair<string, int>>());
	/*�״ξ��Ӵ���*/
	static pair<vector<list<Soldier*>>, vector<list<Soldier*>>>creatGrop(vector<pair<string, int>>actorCreat, bool flag = false,
		const vector<list<Soldier*>>& oldGroupA = vector<list<Soldier*>>());
	/*�ɾ��Ӵ���*/
	static const pair<vector<list<Soldier*>>, vector<list<Soldier*>>>creatGrop();
	/*��ʽս������*/
	static void battleIterface(const pair<vector<list<Soldier*>>, vector<list<Soldier*>>>& data = pair<vector<list<Soldier*>>, vector<list<Soldier*>>>());
	/*�������*/
	static void clearIterface(bool result);
public:
	/*��ʼ����*/
	static void startMenu();
};

#endif // ! UIH