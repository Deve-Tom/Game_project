#include "Actor.h"

/*SoliderMethod*/

/*WizardMethod*/

/*MasterMethod*/
const int Master::makeDecision(Soldier& enemy){
	int i;
	//cout << "ѡ������ж�������0����ʦ����  1����Ϣ   2������   3����ҩ     4��ħ������";

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
			//cout << enemy->getname() << "��" << name << "�ս�" << endl;
			//cout << enemy->getname() << "������ֵ��ǰΪ" << enemy->getHP() << endl;
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
				//cout << name << "�������ȼ�" << level << endl;
				//cout << name << "��������������������" << HP << "����" << SP << "ħ��ֵ" << MP << "����" << NP << endl << endl;
			}
		}
		else if (NP < 50 && SP < 30){
			//cout << name << "���������������޷����������սἼ" << endl;
			return makeDecision(enemy);
		}
	}

}
const double Master::rest(){

	//cout << name << "***��ʼ��Ϣ***" << endl;
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
	//cout << "***��Ϣ����***" << endl << "��ǰ����ֵ��" << HP << '\t' << "����" << SP << "ħ��ֵ" << MP << "����" << NP << endl;
	return 0;
}
const double Master::attack(Soldier& enemy){

	if (HP > 0 && SP >= 10){
		//cout << name << "������" << enemy->getname() << endl;
		enemy.underattack(damage);
		SP -= 10;
		exp += 5;
		//cout << name << "������ֵ�½���" << SP << '\t' << "����+5��" << exp << ")" << endl;
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
			//cout << name << "�������ȼ�" << level << endl;
			//cout << name << "��������������������" << HP << "����" << SP << "ħ��ֵ" << MP << "����" << NP << endl << endl;
		}
		if (enemy.getHP() <= 0){

			drugNum += enemy.getdrugNum();
			//cout << enemy->getname() << "����,����ֵΪ" << HP << "\t" << name << "���ҩƿ����" << enemy->getdrugNum() << endl;
		}
		//cout << enemy->getname() << "�ܵ�" << damage << "�˺� ��ǰ����ֵΪ" << enemy->getHP() << endl << endl;
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
					//cout << endl << name << "��" << enemy->getname() << "����ħ������" << endl;
					enemy.underattack(damage);
					//cout << enemy->getname() << "������ֵ�½���" << enemy->getHP() << endl;
					exp += 5;
					//cout << name << "������ֵ/ħ��ֵ�½�Ϊ��" << SP << "/" << MP << "����+5(" << exp << ")" << endl;
					if (enemy.getHP() <= 0){

						drugNum += enemy.getdrugNum();
						//cout << enemy->getname() << "����" << "\t" << name << "���ҩƿ����" << enemy->getdrugNum() << endl;
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
						//cout << name << "�������ȼ�" << level << endl;
						//cout << name << "��������������������" << HP << "����" << SP << "ħ��ֵ" << MP << "����" << NP << endl << endl;
					}
				}
				else{
					//cout << "ħ��ֵ��������ֵ�����޷�����ħ������" << endl;
					return makeDecision(enemy);
				}
			}
		}
	}
}

const double Master::takingDrug(Soldier& enemy)
{
	//cout << name << "***��ʼ��ҩ***" << endl;
	if (drugNum == 0)
	{
		//cout << "���ź�," << name << "û��ҩƿ��" << endl;
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
	//cout << "***������ҩ***" << endl << "��ǰ����ֵ��" << HP << '\t' << "����" << SP << endl;
}