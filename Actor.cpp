#include "Actor.h"

/*SoliderMethod*/

/*WizardMethod*/

/*MasterMethod*/
const int Master::makeDecision(Soldier& enemy){
	int i;
	//cout << "选择你的行动，输入0：大师攻击  1：休息   2：攻击   3：吃药     4：魔法攻击";

	std::cin >> i;

	if (HP > 0 && i == 0)
		masterAttack(enemy);
	if (HP > 0 && i == 1)
		rest();
	else if (HP > 0 && i == 2)
		attack(enemy);
	else if (HP > 0 && i == 3)
		takingDrug(enemy);
	else if (HP > 0 && i == 4)
		wizardAttack(enemy);
	return 0;
}

const double Master::masterAttack(Soldier& enemy){
	if (HP > 0){

		if (NP >= 50 && SP >= 30){
			NP -= 50;
			SP -= 30;
			enemy.underattack(maxHP * 0.5);
			//cout << enemy->getname() << "被" << name << "终结" << endl;
			//cout << enemy->getname() << "的生命值当前为" << enemy->getHP() << endl;
			exp += 5;
			if (exp >= 20){
				double BHP = HP / maxHP;
				double BSP = SP / maxSP;
				double BMP = MP / maxMP;
				double BNP = NP / maxNP;
				exp -= 20;
				level++;
				damage += 20;
				maxHP += 20;
				maxSP += 20;
				maxMP += 20;
				HP = maxHP * BHP;
				if (HP > maxHP)
					HP = maxHP;
				SP = maxSP * BSP;
				if (SP > maxSP)
					SP = maxSP;
				MP = maxMP * BMP;
				if (MP > maxMP)
					MP = maxMP;
				NP = maxNP * BNP;
				if (NP > maxNP)
					NP = maxNP;
				//cout << name << "升级至等级" << level << endl;
				//cout << name << "各项属性提升至：生命" << HP << "体力" << SP << "魔法值" << MP << "内力" << NP << endl << endl;
			}
		}
		else if (NP < 50 && SP < 30){
			//cout << name << "内力或体力不足无法继续发动终结技" << endl;
			return makeDecision(enemy);
		}
	}

}
const double Master::rest(){

	//cout << name << "***开始休息***" << endl;
	HP += maxHP * 0.5;
	if (HP > maxHP)
		HP = maxHP;
	SP += maxSP * 0.5;
	if (SP > maxSP)
		SP = maxSP;
	MP += maxMP * 0.3;
	if (MP > maxMP)
		MP = maxMP;
	NP += maxNP * 0.3;
	if (NP > maxNP)
		NP = maxNP;
	//cout << "***休息结束***" << endl << "当前生命值：" << HP << '\t' << "体力" << SP << "魔法值" << MP << "内力" << NP << endl;
	return 0;
}
const double Master::attack(Soldier& enemy){

	if (HP > 0 && SP >= 10){
		//cout << name << "攻击了" << enemy->getname() << endl;
		enemy.underattack(damage);
		SP -= 10;
		exp += 5;
		//cout << name << "的体力值下降至" << SP << '\t' << "经验+5（" << exp << ")" << endl;
		if (exp >= 20){
			double BHP = HP / maxHP;
			double BSP = SP / maxSP;
			double BMP = MP / maxMP;
			double BNP = NP / maxNP;
			exp -= 20;
			level++;
			damage += 20;
			maxHP += 20;
			maxSP += 20;
			maxMP += 20;
			HP = maxHP * BHP;
			if (HP > maxHP)
				HP = maxHP;
			SP = maxSP * BSP;
			if (SP > maxSP)
				SP = maxSP;
			MP = maxMP * BMP;
			if (MP > maxMP)
				MP = maxMP;
			NP = maxNP * BNP;
			if (NP > maxNP)
				NP = maxNP;
			//cout << name << "升级至等级" << level << endl;
			//cout << name << "各项属性提升至：生命" << HP << "体力" << SP << "魔法值" << MP << "内力" << NP << endl << endl;
		}
		if (enemy.getHP() <= 0){

			drugNum += enemy.getdrugNum();
			//cout << enemy->getname() << "死亡,生命值为" << HP << "\t" << name << "获得药瓶数量" << enemy->getdrugNum() << endl;
		}
		//cout << enemy->getname() << "受到" << damage << "伤害 当前生命值为" << enemy->getHP() << endl << endl;
	}
	else return makeDecision(enemy);

}
const double  Master::wizardAttack(Soldier& enemy){
	if (HP > 0){
		int enemynum = 1;
		for (int i = 0; i < enemynum; i++){
			if (enemy.getHP() > 0){
				if (MP > 25 && SP > 10){
					MP -= 25;
					SP -= 10;
					//cout << endl << name << "对" << enemy->getname() << "发动魔法攻击" << endl;
					enemy.underattack(damage);
					//cout << enemy->getname() << "的生命值下降至" << enemy->getHP() << endl;
					exp += 5;
					//cout << name << "的体力值/魔法值下降为：" << SP << "/" << MP << "经验+5(" << exp << ")" << endl;
					if (enemy.getHP() <= 0){

						drugNum += enemy.getdrugNum();
						//cout << enemy->getname() << "死亡" << "\t" << name << "获得药瓶数量" << enemy->getdrugNum() << endl;
					}
					if (exp >= 20){
						double BHP = HP / maxHP;
						double BSP = SP / maxSP;
						double BMP = MP / maxMP;
						double BNP = NP / maxNP;
						exp -= 20;
						level++;
						damage += 20;
						maxHP += 20;
						maxSP += 20;
						maxMP += 20;
						HP = maxHP * BHP;
						if (HP > maxHP)
							HP = maxHP;
						SP = maxSP * BSP;
						if (SP > maxSP)
							SP = maxSP;
						MP = maxMP * BMP;
						if (MP > maxMP)
							MP = maxMP;
						NP = maxNP * BNP;
						if (NP > maxNP)
							NP = maxNP;
						//cout << name << "升级至等级" << level << endl;
						//cout << name << "各项属性提升至：生命" << HP << "体力" << SP << "魔法值" << MP << "内力" << NP << endl << endl;
					}
				}
				else{
					//cout << "魔法值或者体力值不足无法继续魔法攻击" << endl;
					return makeDecision(enemy);
				}
			}
		}
	}
}

const double Master::takingDrug(Soldier& enemy)
{
	//cout << name << "***开始吃药***" << endl;
	if (drugNum == 0)
	{
		//cout << "很遗憾," << name << "没有药瓶了" << endl;
		return makeDecision(enemy);
	}
	else {
		drugNum--;
		HP += maxHP * 0.8;
		if (HP > maxHP)
			HP = maxHP;
		MP += maxMP * 0.5;
		if (MP > maxMP)
			MP = maxMP;
		NP += maxNP * 0.5;
		if (NP > maxNP)
			NP = maxNP;
	}
	//cout << "***结束吃药***" << endl << "当前生命值：" << HP << '\t' << "体力" << SP << endl;
}