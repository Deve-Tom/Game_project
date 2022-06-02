#pragma once
#ifndef Actor
#define Actor
#include<iostream>
#include<string>
#include<iostream>
class Soldier
{
private:
	size_t numSolider;
protected:
	double maxHP;
	double HP;
	double maxSP;
	double SP;
	double damage;
	int exp;
	int level;
	int drugNum;
	std::string name;
public:
	Soldier(double _maxHP=100.0, 
		double _HP=100.0, double _maxSP=100.0, double _SP=100.0, 
		double _damage=20.0, int _exp=0, int _level=1,int _drugNum=5, size_t _numSolider = 1)
		:numSolider(_numSolider),maxHP(_maxHP),HP(_HP),maxSP(_maxSP),
		SP(_SP),damage(_damage),exp(_exp),level(_level),drugNum(_drugNum){}
	virtual ~Soldier() = default;

	//相应动作
	virtual const int makeDecision()const;
	virtual const double attack();
	virtual const double rest();
	virtual const double takingDrug();
	virtual void underattack(double hurt)final{this->HP -= hurt;}
	virtual const double getHP()final{return HP;}
	virtual const double getname()final{return HP;}
	virtual const int getdrugNum()final{return drugNum;}
};

class Wizard :public virtual Soldier {
private:
	size_t numWizard;
protected:
	double maxMP;
	double MP;
public:
	Wizard(double _maxHP = 100.0,
		double _HP = 100.0, double _maxSP = 100.0, double _SP = 100.0,
		double _damage = 20.0, int _exp = 0, int _level = 1, int _drugNum = 5,
		double _maxMP = 100.0, double _MP = 100.0, size_t _numWizard = 1, 
		size_t _numSolider = 0) :Soldier(_maxHP, _HP, _maxSP, _SP, _damage, _exp, _level,_drugNum,_numSolider)
		,maxMP(_maxMP),MP(_MP),numWizard(_numWizard){}
	virtual ~Wizard() = default;
	virtual const int makeDecision()const;
	virtual const double attack();
	virtual const double wizardAttack()const;
	virtual const double rest();
	virtual const double takingDrug();
};

class Master :public virtual Wizard{
private:
	size_t numMaster;
protected:
	double maxNP;
	double NP;
public:
	Master(double _maxHP = 100.0,
		double _HP = 100.0, double _maxSP = 100.0, double _SP = 100.0,
		double _damage = 20.0, int _exp = 0, int _level = 1, int _drugNum = 5,
		double _maxMP = 100.0, double _MP = 100.0,double _maxNP=100.0,
		double _NP=100.0,size_t _numMaster = 1, size_t _numWizard = 0,
		size_t _numSolider = 0) :Soldier(_maxHP, _HP, _maxSP, _SP, _damage, _exp, _level, _drugNum, _numSolider),
		Wizard(_maxHP, _HP, _maxSP, _SP, _damage, _exp, _level, _drugNum,_maxMP,_MP, _numWizard), maxNP(_maxNP), 
		NP(_NP), numMaster(_numMaster) {}
	virtual ~Master() = default;
	virtual const int makeDecision(Soldier&);
	virtual const double attack(Soldier&);
	virtual const double wizardAttack(Soldier&);
	virtual const double masterAttack(Soldier&);
	virtual const double rest();
	virtual const double takingDrug(Soldier&);
};
#endif