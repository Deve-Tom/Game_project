#pragma once
#ifndef WARSYSTEM
#define WARSYSTEM
#include"Actor.h"
#include<vector>
#include<list>
#include<map>
#include<ctime>

class WarSystem{
private:
	bool GroupA;
	bool GroupB;
protected:
	std::vector<std::list< Soldier*>> pGroupA;
	std::vector<std::list< Soldier*>> pGroupB;
public:
	WarSystem(std::pair< std::vector<std::list< Soldier*>>, std::vector<std::list< Soldier*>>>GroupAll 
		= std::pair< std::vector<std::list< Soldier*>>, std::vector<std::list< Soldier*>>>())
		:pGroupA(GroupAll.first), pGroupB(GroupAll.second),GroupA(false),GroupB(false) {}
	virtual ~WarSystem() = default;

	/*获得军队信息*/
	std::vector<std::list<Soldier*>> getGroupA() { return pGroupA; }
	std::vector<std::list<Soldier*>> getGroupB() { return pGroupB; }
	/*选择那个队伍优先开战*/
	void selectGroup();
	/*交战逻辑*/
	void battleLogic();
};

#endif