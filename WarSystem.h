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

	/*获得军队信息*/
	std::vector<std::list<Soldier*>> getGroupA() { return pGroupA; }
	std::vector<std::list<Soldier*>> getGroupB() { return pGroupB; }
	/*玩家交战逻辑*/
	void userBattleLogic(Soldier*, Soldier*);
	/*电脑交战逻辑*/
	void computerBattleLogic(std::vector<std::list< Soldier*>>& pGroupA, std::vector<std::list< Soldier*>>& pGroupB);
	/*判断输赢*/
	std::pair<bool,bool> whichWinFinal();
	/*正式交战*/
	std::pair<bool, bool> War();
	/*选择敌人*/
	Soldier* selectComputer();
	/*展现属性*/
	void outNature(Soldier* ps);
	/*血量展示*/
	void computerHP();
	bool isAllOver();
};
#endif