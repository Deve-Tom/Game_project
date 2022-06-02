#pragma once
#ifndef ACTOR
#define ACTOR
#include<iostream>
#include<string>
#include<graphics.h>

class Soldier
{
private:
	size_t numSolider;
	bool liveFlag;
protected:
	const std::string what;
	int maxHP;
	int HP;
	int maxSP;
	int SP;
	int damage;
	int exp;
	int maxExp;
	int level;
	int drugNum;
	std::string name;

	/*角色对应图像*/
	IMAGE liveActorImage;
	IMAGE deadActorImage;
	IMAGE lowbloodImage;
	void setImage(bool which=true);
public:
	Soldier(bool _whitch,int _maxHP=100, 
		int _HP=100, int _maxSP=100, int _SP=100, 
		int _damage=20, int _exp=0, int _level=1,int _drugNum=5,std::string _what="Soldier" ,size_t _numSolider = 1)
		:numSolider(_numSolider),maxHP(_maxHP),HP(_HP),maxSP(_maxSP),
		SP(_SP),damage(_damage),exp(_exp),level(_level),drugNum(_drugNum),liveFlag(true),what(_what),name(_what),maxExp(150) {
	/*增加角色存活图画*/
		setImage(_whitch);
	}
	virtual ~Soldier() = default;

	/*相应动作*/
	/*virtual const int makeDecision();
	virtual const int attack();
	virtual const int rest();
	virtual const int takingDrug();*/
	void setLiveOrDead() { liveFlag = !liveFlag; }

	/*受到伤害*/
	virtual void getAttack(int hurt)final{this->HP -= hurt;}
	/*获得角色属性*/
	virtual const int getHP()const{return HP; }
	virtual const int getMaxHP()const { return maxHP; }
	virtual const int getSP()const { return SP; }
	virtual const int getMaxSP()const { return maxSP; }
	virtual const int getExp()const { return exp; }
	virtual const int getMaxExp() const { return maxExp; }
	virtual const std::string getname(){return name;}
	virtual const int getdrugNum(){return drugNum;}
	virtual const int getLiveOrDead()const { return liveFlag; }
	virtual const int getLevel(){ return level; }
	virtual const int getMaxMP()const { return 0; }
	virtual const int getMP()const { return 0; }
	virtual const int getMaxNP()const { return 0; }
	virtual const int getNP()const { return 0; }

	/*获得角色图像信息*/
	IMAGE& getImageLive();
	IMAGE& getImageDead();
	IMAGE& getImageLowBlood();
};

class Wizard :public virtual Soldier {
private:
	size_t numWizard;
protected:
	int maxMP;
	int MP;
public:
	Wizard(bool _whitch,int _maxHP = 100,
		int _HP = 100, int _maxSP = 100, int _SP = 100,
		int _damage = 20, int _exp = 0, int _level = 1, int _drugNum = 5,
		int _maxMP = 100, int _MP = 100, std::string _what = "Wizard",size_t _numWizard = 1,
		size_t _numSolider = 0) :Soldier(_whitch,_maxHP, _HP, _maxSP, _SP, _damage, _exp, _level,_drugNum,_what,_numSolider)
		,maxMP(_maxMP),MP(_MP),numWizard(_numWizard){}
	virtual ~Wizard() = default;

	/*获得角色属性*/
	virtual const int getMaxMP()const { return maxMP; }
	virtual const int getMP()const { return MP; }

	/*virtual const int makeDecision()const;
	virtual const int attack();
	virtual const int wizardAttack()const;
	virtual const int rest();
	virtual const int takingDrug();*/
};

class Master :public virtual Wizard{
private:
	size_t numMaster;
protected:
	int maxNP;
	int NP;
public:
	Master(bool _whitch,int _maxHP = 100,
		int _HP = 100, int _maxSP = 100, int _SP = 100,
		int _damage = 20, int _exp = 0, int _level = 1, int _drugNum = 5,
		int _maxMP = 100, int _MP = 100,int _maxNP=100,
		int _NP=100,std::string _what = "Master",size_t _numMaster = 1, size_t _numWizard = 0,
		size_t _numSolider = 0) :Soldier(_whitch,_maxHP, _HP, _maxSP, _SP, _damage, _exp, _level, _drugNum, _what, _numSolider),
		Wizard(_whitch,_maxHP, _HP, _maxSP, _SP, _damage, _exp, _level, _drugNum,_maxMP,_MP, _what,_numWizard), maxNP(_maxNP), 
		NP(_NP), numMaster(_numMaster) {}
	virtual ~Master() = default;

	/*获得角色属性*/
	virtual const int getMaxNP()const { return maxNP; }
	virtual const int getNP()const { return NP; }

	/*virtual const int makeDecision()const;
	virtual const int attack();
	virtual const int wizardAttack();
	virtual const int masterAttack();
	virtual const int rest();
	virtual const int takingDrug();*/
};

#endif