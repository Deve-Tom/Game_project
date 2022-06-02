#pragma once
#ifndef WARSYSTEM
#define WARSYSTEM
#include"Actor.h"

class WarSystem{
protected:
	Soldier** pGroupA;
	Soldier** pGroupB;
public:
	WarSystem(Soldier** _PA = nullptr, Soldier** _PB = nullptr) :pGroupA(_PA), pGroupB(_PB) {}
	virtual ~WarSystem() = default;
};

#endif