#include "Actor.h"

/*SoliderMethod*/
void Soldier::setImage(bool which) {
	if (which) {
		if (what == "Soldier") {
			loadimage(&liveActorImage, "otherScourse\\solder_actor_reverse.png", 115, 119);
			loadimage(&deadActorImage, "otherScourse\\actor_solider_dead_2.png", 115, 119);
			loadimage(&lowbloodImage, "otherScourse\\actor_solider_lowblood.png", 115, 119);
}
		else if (what == "Wizard") {
			loadimage(&liveActorImage, "otherScourse\\wizard_actor_reverse.png", 115, 119);
			loadimage(&deadActorImage, "otherScourse\\actor_wizard_dead_2.png", 115, 119);
			loadimage(&lowbloodImage, "otherScourse\\actor_wizard_lowblood.png", 115, 119);
			}
		else if (what == "Master") {
			loadimage(&liveActorImage, "otherScourse\\master_actor_reverse.png", 115, 119);
			loadimage(&deadActorImage, "otherScourse\\actor_master_dead_2.png", 115, 119);
			loadimage(&lowbloodImage, "otherScourse\\actor_master_lowblood.png", 115, 119);
		}
		else throw "´´½¨´íÎó";
		}
	else {
		if (what == "Soldier") {
			loadimage(&liveActorImage, "otherScourse\\computer_Solder_live.png", 115, 119);
			loadimage(&deadActorImage, "otherScourse\\computer_Solder_dead.png", 115, 119);
			loadimage(&lowbloodImage, "otherScourse\\computer_Solder_lowblood.png", 115, 119);
	}
		else if (what == "Wizard") {
			loadimage(&liveActorImage, "otherScourse\\computer_wizard_live.png", 115, 119);
			loadimage(&deadActorImage, "otherScourse\\computer_wizard_dead.png", 115, 119);
			loadimage(&lowbloodImage, "otherScourse\\computer_wizard_lowblood.png", 115, 119);
}
		else if (what == "Master") {
			loadimage(&liveActorImage, "otherScourse\\computer_master_live.png", 115, 119);
			loadimage(&deadActorImage, "otherScourse\\computer_master_dead.png", 115, 119);
			loadimage(&lowbloodImage, "otherScourse\\computer_master_lowblood.png", 115, 119);
}
		else throw "´´½¨´íÎó";
		}

	/*¼ÓÔØ¹¥»÷°´Å¥*/
	loadimage(&normalAttack, "otherScourse\\normalAttack.png", 60, 60);
	loadimage(&restImage, "otherScourse\\rest.png", 60, 60);
	loadimage(&takeDrugImage, "otherScourse\\takingDrug.png", 60, 60);
	loadimage(&magicAttackImage, "otherScourse\\magicAttac.png", 60, 60);
	loadimage(&masterAttackImage, "otherScourse\\masterAttack.png", 60, 60);
	loadimage(&noDrugImage, "otherScourse\\NoDrug.png", 60, 60);
}

void Soldier::leveUP()
{
	if (this->exp >= this->maxExp) {
		this->exp = 0;
		this->maxExp += 20;
		this->level += 1;
		this->maxHP *= 0.2;
		this->maxSP *= 0.2;
		this->damage += 20;
		this->HP = maxHP;
	}
}

std::pair<std::string, std::string> Soldier::makeDecision()
{
	MOUSEMSG it;
	/*ÆÕÍ¨¹¥»÷Î»ÖÃ*/
	while (true) {
		it = GetMouseMsg();
		if (it.x >= 866 && it.x <= 926 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("Soldier"), std::string("normalAttack"));
		}
		/*ÐÝÏ¢Î»ÖÃ*/
		if (it.x >= 936 && it.x <= 996 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("Soldier"), std::string("rest"));
		}
		/*³ÔÒ©Î»ÖÃ*/
		if (it.x >= 1006 && it.x <= 1066 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>("Soldier", std::string("takeDrug"));
		}
	}
}

const int Soldier::attack(){
	if (this->SP > 0) {
		this->SP -= 10;
		this->exp += 5;
		leveUP();
		return damage;
	}
	else return 0;
	
}

void Soldier::rest(){
	this->HP += this->maxHP * 0.5;
	if (this->HP > this->maxHP)
		this->HP = this->maxHP;
	this->SP += this->maxSP * 0.5;
	if (this->SP > this->maxSP)
		this->SP = this->maxSP;
}

void Soldier::takingDrug(){
	if (this->drugNum == 0){
		return;
	}
	else {
		this->drugNum--;
		this->HP += this->maxHP * 0.8;
		if (this->HP > this->maxHP)
			this->HP = this->maxHP;
	}
}

IMAGE& Soldier::getImageLive(){
	return this->liveActorImage;
}

IMAGE& Soldier::getImageDead(){
	return this->deadActorImage;
}

IMAGE& Soldier::getImageLowBlood(){
	return this->lowbloodImage;
}

IMAGE& Soldier::getImageNormalAttack()
{
	return this->normalAttack;
}

IMAGE& Soldier::getImageRest()
{
	return this->restImage;
}

IMAGE& Soldier::getImageTakeDrug()
{
	return this->takeDrugImage;
}

IMAGE& Soldier::getImageMagicAttack()
{
	return this->magicAttackImage;
}

IMAGE& Soldier::getImageMasterAttack()
{
	return this->masterAttackImage;
}

IMAGE& Soldier::getImageNoDrug()
{
	return this->noDrugImage;
}


/*WizardMethod*/

std::pair<std::string, std::string> Wizard::makeDecision()
{
	MOUSEMSG it;
	while (true) {
		it = GetMouseMsg();
		/*ÆÕÍ¨¹¥»÷Î»ÖÃ*/
		if (it.x >= 866 && it.x <= 926 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("Wizard"), std::string("normalAttack"));
		}
		/*Ä§·¨¹¥»÷Î»ÖÃ*/
		if (it.x >= 936 && it.x <= 996 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("Wizard"), std::string("wizardAttack"));
		}
		/*ÐÝÏ¢Î»ÖÃ*/
		if (it.x >= 1006 && it.x <= 1066 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("Wizard"), std::string("rest"));
		}
		/*³ÔÒ©Î»ÖÃ*/
		if (it.x >= 1076 && it.x <= 1136 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("Wizard"), std::string("takeDrug"));
		}
	}
}

const int Wizard::attack()
{
	return Soldier::attack();
}

const int Wizard::wizardAttack()
{
	if(this->MP<25||this->SP<10)
	return 0;
	else {
		this->SP -= 10;
		this->MP -= 25;
		this->exp += 5;
		leveUP();
		return this->damage;
	}
}

void Wizard::rest()
{
	HP += maxHP * 0.5;
	if (HP > maxHP)
		HP = maxHP;
	SP += maxSP * 0.5;
	if (SP > maxSP)
		SP = maxSP;
	MP += maxMP * 0.3;
	if (MP > maxMP)
		MP = maxMP;
}

void Wizard::takingDrug()
{
	Soldier::takingDrug();
}

/*MasterMethod*/

std::pair<std::string, std::string> Master::makeDecision()
{
	MOUSEMSG it;
	while (true) {
		it = GetMouseMsg();
		/*ÆÕÍ¨¹¥»÷Î»ÖÃ*/
		if (it.x >= 866 && it.x <= 926 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("master"), std::string("normalAttack"));
		}
		/*Ä§·¨¹¥»÷Î»ÖÃ*/
		if (it.x >= 936 && it.x <= 996 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("master"), std::string("wizardAttack"));
		}
		/*ÐÝÏ¢Î»ÖÃ*/
		if (it.x >= 1006 && it.x <= 1066 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("master"), std::string("rest"));
		}
		/*³ÔÒ©Î»ÖÃ*/
		if (it.x >= 1076 && it.x <= 1136 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("master"), std::string("takeDrug"));
		}
		/*´óÊ¦¹¥»÷Î»ÖÃ*/
		if (it.x >= 1146 && it.x <= 1206 && it.y >= 706 && it.y <= 766 && it.mkLButton) {
			return std::pair<std::string, std::string>(std::string("master"), std::string("masterAttack"));
		}
	}
}

const int Master::attack()
{
	return Soldier::attack();
}

const int Master::wizardAttack()
{
	return Wizard::wizardAttack();
}

const int Master::masterAttack(const Soldier&willAtack)
{
	if (this->NP > 50) {
		this->NP -= 50;
		this->SP -= 30;
		this->exp += 5;
		leveUP();
		return willAtack.getMaxHP();
	}
	return 0;
}

void Master::rest()
{
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
}

void Master::takingDrug()
{
	Soldier::takingDrug();
}
