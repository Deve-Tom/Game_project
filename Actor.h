#pragma once
#ifndef ACTOR
#define ACTOR
#include<iostream>
#include<string>
#include<graphics.h>
#include<map>

class Soldier
{
private:
	size_t numSolider;
	/*注意写一个改变死活状态的函数*/
	bool liveFlag;
protected:
	bool whitch;
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
	
	/*button*/
	IMAGE normalAttack;
	IMAGE restImage;
	IMAGE takeDrugImage;
	IMAGE noDrugImage;
	IMAGE magicAttackImage;
	IMAGE masterAttackImage;
	void setImage(bool which=true);
	void leveUP();
public:
	Soldier(bool _whitch,int _maxHP=100, 
		int _HP=100, int _maxSP=100, int _SP=100, 
		int _damage=20, int _exp=0, int _level=1,int _drugNum=5,std::string _what="Soldier" ,size_t _numSolider = 1)
		:numSolider(_numSolider),maxHP(_maxHP),HP(_HP),maxSP(_maxSP),whitch(_whitch),
		SP(_SP),damage(_damage),exp(_exp),level(_level),drugNum(_drugNum),liveFlag(true),what(_what),name(_what),maxExp(150) {
	/*增加角色存活图画*/
		setImage(this->whitch);
	}
	virtual ~Soldier() = default;

	/*相应动作*/
	/*用于对攻击对象的选择*/
	virtual std::pair<std::string,std::string> makeDecision();
	virtual const int attack();
	virtual void rest();
	virtual void takingDrug();
	virtual const int wizardAttack() { return 0; }
	virtual const int masterAttack(const Soldier& it) { return 0; }
	/*受到伤害*/
	void getAttack(int hurt) { 
		this->HP -= hurt; 
		if (this->HP <= 0) 
			this->liveFlag = false;
	}
	/*获得角色属性*/
	virtual const int getHP()const{return HP; }
	virtual const int getMaxHP()const { return maxHP; }
	virtual const int getSP()const { return SP; }
	virtual const int getMaxSP()const { return maxSP; }
	virtual const int getExp()const { return exp; }
	virtual const int getMaxExp() const { return maxExp; }
	virtual const std::string getname(){return name;}
	virtual const int getdrugNum(){return drugNum;}
	//virtual const int getLiveOrDead()const { return liveFlag; }
	virtual const int getLevel(){ return level; }
	virtual const int getMaxMP()const { return 0; }
	virtual const int getMP()const { return 0; }
	virtual const int getMaxNP()const { return 0; }
	virtual const int getNP()const { return 0; }
	virtual bool getIsLiveFlag() { return this->liveFlag; }
	void resetHP() { this->HP = this->maxHP; }
	void setExp(int _Exp) { this->exp = _Exp; }

	/*获得角色图像信息*/
	IMAGE& getImageLive();
	IMAGE& getImageDead();
	IMAGE& getImageLowBlood();
	/*获得攻击方式图像*/
	IMAGE& getImageNormalAttack();
	IMAGE& getImageRest();
	IMAGE& getImageTakeDrug();
	IMAGE& getImageMagicAttack();
	IMAGE& getImageMasterAttack();
	IMAGE& getImageNoDrug();
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

	virtual std::pair<std::string, std::string> makeDecision();
	virtual const int attack();
	virtual const int wizardAttack();
	virtual void rest();
	virtual void takingDrug();
	virtual const int masterAttack(const Soldier& it) { return 0; }
	bool getIsLiveFlag() { return Soldier::getIsLiveFlag(); }
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

	virtual std::pair<std::string, std::string> makeDecision();
	virtual const int attack();
	virtual const int wizardAttack();
	virtual const int masterAttack(const Soldier&);
	virtual void rest();
	virtual void takingDrug();
	bool getIsLiveFlag() { return Soldier::getIsLiveFlag(); }
};

#endif