#pragma once
#ifndef WARSYSTEM
#define WARSYSTEM
#include"Actor.h"
#include<vector>
#include<list>
#include<map>
#include<ctime>

class WarSystem{

protected:
	std::vector<std::list< Soldier*>> pGroupA;
	std::vector<std::list< Soldier*>> pGroupB;

public:
	WarSystem(std::pair< std::vector<std::list< Soldier*>>, std::vector<std::list< Soldier*>>>GroupAll 
		= std::pair< std::vector<std::list< Soldier*>>, std::vector<std::list< Soldier*>>>())
		:pGroupA(GroupAll.first), pGroupB(GroupAll.second){
	}
	virtual ~WarSystem() {
		for (auto& a : pGroupB) {
			for (auto& b : a) {
				delete b;
			}
		}
		for (auto& a : pGroupA) {
			for (auto& b : a) {
				delete b;
			}
		}
	}

	/*��þ�����Ϣ*/
	std::vector<std::list<Soldier*>> getGroupA() { return pGroupA; }
	std::vector<std::list<Soldier*>> getGroupB() { return pGroupB; }
	/*��ҽ�ս�߼�*/
	void userBattleLogic(Soldier*, Soldier*);
	/*���Խ�ս�߼�*/
	void computerBattleLogic(std::vector<std::list< Soldier*>>& pGroupA, std::vector<std::list< Soldier*>>& pGroupB);
	/*�ж���Ӯ*/
	std::pair<bool,bool> whichWinFinal();
	/*��ʽ��ս*/
	std::pair<bool, bool> War();
	/*ѡ�����*/
	Soldier* selectComputer();
	/*չ������*/
	void outNature(Soldier* ps);
	/*Ѫ��չʾ*/
	void computerHP();
	bool isAllOver();
};
#endif