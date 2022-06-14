#include "WarSystem.h"
#include"Actor.h"
#include<graphics.h>
#include "Systemloger.h"
#pragma warning(disable:4996)

/*����Ƿ����ս��*/
bool WarSystem::isAllOver() {
	int temp = 0;
	for (auto a : pGroupA) {
		for (auto b : a) {
			if (!b->getIsLiveFlag()) {
				temp++;
			}
		}
	}

	if (temp == 4) {
		return true;
	}

	temp = 0;
	for (auto a : pGroupB) {
		for (auto b : a) {
			if (!b->getIsLiveFlag()) {
				temp++;
			}
		}
	}
	if (temp == 4) {
		return true;
	}
	return false;
}

/*���Խ���ս��*/
void WarSystem::computerBattleLogic(std::vector<std::list< Soldier*>>& pGroupA , std::vector<std::list< Soldier*>>& pGroupB) {
	/*����Ѫ����ߵ��û���ɫ*/
	outtextxy(579, 287, "���Խ���ս��");
	std::vector<Soldier*>tempSelect;
	for (auto& a : pGroupA) {
		for (auto& b : a) {
			tempSelect.push_back(b);
		}
	}
	for (int i = 0; i < tempSelect.size() - 1; i++)
		for (int j = 0; j < tempSelect.size() - 1 - i; j++)
			if (tempSelect[j]->getHP() < tempSelect[j + 1]->getHP()) {
				Soldier* temp = tempSelect[j];
				tempSelect[j] = tempSelect[j + 1];
				tempSelect[j + 1] = temp;
			}
	Soldier* highHPActor = tempSelect[0];
	if(!highHPActor->getIsLiveFlag())
		for (auto a : tempSelect) {
			if (a->getIsLiveFlag()) {
				highHPActor = a;
				break;
			}
		}
	/*���Խ�ɫ���ν��й���*/
	for (auto& a : pGroupB) {
		for (auto& b : a) {
			Sleep(100);
			if (b->getname() == "Soldier" && b->getIsLiveFlag() && highHPActor->getIsLiveFlag()) {
				highHPActor->getAttack(b->attack());
			}
			if (b->getname() == "Wizard" && b->getIsLiveFlag() && highHPActor->getIsLiveFlag()) {
				if (b->getMP() >= 25 && b->getSP() >= 10) {
				highHPActor->getAttack(b->wizardAttack());
				}
				else {
					highHPActor->getAttack(b->attack());
				}
			}
			if (b->getname() == "Master" && b->getIsLiveFlag() && highHPActor->getIsLiveFlag()) {
				if (b->getNP() >= 50) {
					highHPActor->getAttack(b->masterAttack(highHPActor));
				}
				else if (b->getMP() >= 25 && b->getSP() >= 10) {
					highHPActor->getAttack(b->wizardAttack());
				}
				else {
					highHPActor->getAttack(b->attack());
				}
			}
		}
	}
	clearrectangle(579, 287, 700, 387);
}

/*��ҽ���ս��*/
void WarSystem::userBattleLogic(Soldier*_actorA, Soldier*_actorB) {
	clearrectangle(579, 287, 700, 387);
	outtextxy(579, 287, "ѡ�򹥻�����");
	std::pair<std::string, std::string>select = _actorA->makeDecision();
	if (select.second == "normalAttack") {
		_actorB->getAttack(_actorA->attack());
	}
	if (select.second == "rest") {
		_actorA->rest();
	}
	if (select.second == "takeDrug") {
		_actorA->takingDrug();
	}
	if (select.second == "wizardAttack") {
		_actorB->getAttack(_actorA->wizardAttack());
	}
	if (select.second == "masterAttack") {
		_actorB->getAttack(_actorA->masterAttack(_actorB));
	}
	if (select.second == "null") {
		return;
	}
}

/*�ж���Ӯ*/
std::pair<bool,bool> WarSystem::whichWinFinal() {
	/*��������*/
	int userTemp{0}, computerTemp{0};
	/*�������û���ɫ������д����������*/
	for (auto a : pGroupA) {
		for (auto b : a) {
			if (b->getIsLiveFlag() == false) {
				userTemp++;
			}
		}
	}

	/*�����е��Խ�ɫ������д����������*/
	for (auto a : pGroupB) {
		for (auto b : a) {
			if (b->getIsLiveFlag() == false) {
				computerTemp++;
			}
		}
	}

	/*��*/
	if (userTemp == 4 && computerTemp<4) {
		int numSo{}, numWiz{}, numMas{};
		for (auto a : pGroupA) {
			for (auto b : a) {
				if (b->getname() == "Soldier") {
					numSo++;
				}
				if (b->getname() == "Wizard") {
					numWiz++;
				}
				if (b->getname() == "Master") {
					numMas++;
				}
			}
		}
		Systemloger::logWrite("��", Systemloger::OLDDATA);
		Systemloger::logWrite(numSo, Systemloger::OLDDATA);
		Systemloger::logWrite(numWiz, Systemloger::OLDDATA);
		Systemloger::logWrite(numMas, Systemloger::OLDDATA);
		return std::pair<bool, bool>(false, true);
	}
	/*Ӯ*/
	if (computerTemp == 4 && userTemp<4) {
		for (auto a : pGroupA) {
			for (auto b : a) {
				Systemloger::logWrite(b->getname(), Systemloger::OLDDATA);
				Systemloger::logWrite(b->getIsLiveFlag(), Systemloger::OLDDATA);
				Systemloger::logWrite(b->getLevel(), Systemloger::OLDDATA);
				Systemloger::logWrite(b->getExp(), Systemloger::OLDDATA);
			}
		}
		int numSo{}, numWiz{}, numMas{};
		for (auto a : pGroupA) {
			for (auto b : a) {
				if (b->getname() == "Soldier") {
					numSo++;
				}
				if (b->getname() == "Wizard") {
					numWiz++;
				}
				if (b->getname() == "Master") {
					numMas++;
				}
			}
		}
		Systemloger::logWrite("Ӯ", Systemloger::BATTELLOG);
		Systemloger::logWrite(numSo, Systemloger::BATTELLOG);
		Systemloger::logWrite(numWiz, Systemloger::BATTELLOG);
		Systemloger::logWrite(numMas, Systemloger::BATTELLOG);
		return std::pair<bool, bool>(true, false);
	}
	/*ƽ��*/
	return std::pair<bool, bool>(true, true);
}

/*��ʽս��*/
std::pair<bool, bool> WarSystem::War() {
	for (auto& user_a : pGroupA) {
		for (auto& user_b : user_a) {
			if (isAllOver())
				goto flag;
			if (user_b->getIsLiveFlag() == true) {
				outNature(user_b);
				computerHP();
				Soldier* it = selectComputer();
				userBattleLogic(user_b, it);
			}
		}
	}
	computerBattleLogic(this->pGroupA, this->pGroupB);
    flag:return whichWinFinal();
}

/*ѡ�񹥻�����*/
Soldier*WarSystem::selectComputer()
{
	/*�������Խ�ɫ*/
	outtextxy(579, 287, "ѡ�򹥻�����");
	std::vector<Soldier*>selectComputer;
	for (auto &a : pGroupB) {
		for (auto &b : a) {
			selectComputer.push_back(b);
		}
	}

	Soldier* ps = nullptr;
	while (true) {
		MOUSEMSG clickImage;
		clickImage = GetMouseMsg();

		if (clickImage.mkLButton) {
			if (clickImage.x >= 883 && clickImage.x <= 998 && clickImage.y >= 214 && clickImage.y <= 333)
				ps = selectComputer[0];
			if (clickImage.x >= 783 && clickImage.x <= 898 && clickImage.y >= 299 && clickImage.y <= 418)
				ps = selectComputer[1];
			if (clickImage.x >= 783 && clickImage.x <= 898 && clickImage.y >= 420 && clickImage.y <= 526)
				ps = selectComputer[2];
			if (clickImage.x >= 883 && clickImage.x <= 998 && clickImage.y >= 492 && clickImage.y <= 611)
				ps = selectComputer[3];
		}

		if (ps) {
			clearrectangle(579, 287, 700, 387);
			return ps;
		}
	}
}

void WarSystem::computerHP(){
	using std::vector;
	using std::pair;
	/*���Խ�ɫ����*/
	vector<Soldier*>selectComputer;
	{
		int i{};
		for (auto a : pGroupB) {
			for (auto b : a) {
				selectComputer.push_back(b);
				i++;
			}
		}
	}
	/*��ҽ�ɫ����*/
	vector<Soldier*>selectUser;
	{
		int i{};
		for (auto a : pGroupA) {
			for (auto b : a) {
				selectUser.push_back(b);
				i++;
			}
		}
	}
	/*����HPλ��*/
	vector<pair<int, int>>place = {
		pair<int,int>(1008,274),
		pair<int,int>(908,359),
		pair<int,int>(908,467),
		pair<int,int>(1008,552)
	};
	/*���HPλ��*/
	vector<pair<int, int>>placeUser = {
		pair<int,int>(182,274),
		pair<int,int>(282,359),
		pair<int,int>(282,467),
		pair<int,int>(182,552)
	};

	int temp{};
	for (auto a : selectComputer) {
		clearrectangle(place[temp].first, place[temp].second, place[temp].first + 60, place[temp].second + 20);
		outtextxy(place[temp].first, place[temp].second, "HP:");
		outtextxy(place[temp].first+30, place[temp].second, tools::numToTHAR(a->getHP()));
		temp++;
	}

	temp = 0;
	for (auto a : selectUser) {
		clearrectangle(placeUser[temp].first, placeUser[temp].second, placeUser[temp].first + 60, placeUser[temp].second + 20);
		outtextxy(placeUser[temp].first, placeUser[temp].second, "HP:");
		outtextxy(placeUser[temp].first + 30, placeUser[temp].second, tools::numToTHAR(a->getHP()));
		temp++;
	}
}

void WarSystem::outNature( Soldier* ps) {
	using std::vector;
	LOGFONT itWill;
	LOGFONT itBefore;
	gettextstyle(&itWill);
	gettextstyle(&itBefore);
	itWill.lfHeight = 60;
	settextstyle(&itWill);
	settextstyle(&itBefore);
	if (ps) {
		/*����ͼƬ����*/
		IMAGE actorBelow;
		if (ps->getname() == "Soldier") {
			if (ps->getIsLiveFlag())
				loadimage(&actorBelow, "otherScourse\\actor_solider_live.png", 155, 155);
			else
				loadimage(&actorBelow, "otherScourse\\actor_solider_dead.png", 155, 155);
			putimage(0, 613, &actorBelow);
		}
		if (ps->getname() == "Wizard") {
			if (ps->getIsLiveFlag())
				loadimage(&actorBelow, "otherScourse\\actor_wizard_live.png", 155, 155);
			else
				loadimage(&actorBelow, "otherScourse\\actor_wizard_dead.png", 155, 155);
			putimage(0, 613, &actorBelow);
		}

		if (ps->getname() == "Master") {
			if (ps->getIsLiveFlag())
				loadimage(&actorBelow, "otherScourse\\actor_master_live.png", 155, 155);
			else
				loadimage(&actorBelow, "otherScourse\\actor_master_dead.png", 155, 155);
			putimage(0, 613, &actorBelow);
		}
		
		/*Master Solider Wizard ��ʾ��������*/
		itWill.lfHeight = 30;
		settextstyle(&itWill);
		/*clearrectangle(160, 600, 850, 800);*/
		clearrectangle(590, 733, 680, 783);
		clearrectangle(500, 693, 780, 783);
		outtextxy(160, 613, _T("�ȼ�:"));
		clearrectangle(250, 613, 300, 653);
		outtextxy(250, 613, tools::numToTHAR(ps->getLevel()));

		outtextxy(160, 653, _T("����:"));
		clearrectangle(250, 653, 360, 693);
		outtextxy(250, 653, tools::numToTHAR(ps->getHP()));
		outtextxy(370, 653, _T("/"));
		outtextxy(390, 653, tools::numToTHAR(ps->getMaxHP()));

		outtextxy(160, 693, _T("����:"));
		clearrectangle(250, 693, 460, 733);
		outtextxy(250, 693, tools::numToTHAR(ps->getSP()));
		outtextxy(370, 693, _T("/"));
		outtextxy(390, 693, tools::numToTHAR(ps->getMaxSP()));

		outtextxy(160, 733, _T("����:"));
		clearrectangle(250, 733, 460, 783);
		outtextxy(250, 733, tools::numToTHAR(ps->getExp()));
		outtextxy(370, 733, _T("/"));
		outtextxy(390, 733, tools::numToTHAR(ps->getMaxExp()));

		/*Wizard and Masterħ��ֵ*/
		if (ps->getname() == "Wizard" || ps->getname() == "Master") {
			clearrectangle(590, 733, 680, 783);
			clearrectangle(500, 693, 830, 733);
			outtextxy(500, 733, _T("ħ��:"));
			outtextxy(590, 733, tools::numToTHAR(ps->getMP()));
			outtextxy(710, 733, _T("/"));
			outtextxy(730, 733, tools::numToTHAR(ps->getMaxMP()));
		}
		/*Master����*/
		if (ps->getname() == "Master") {
			clearrectangle(590, 693, 680, 733);
			outtextxy(500, 693, _T("����:"));
			outtextxy(590, 693, tools::numToTHAR(ps->getNP()));
			outtextxy(710, 693, _T("/"));
			outtextxy(730, 693, tools::numToTHAR(ps->getMaxNP()));
		}

		/*�ָ���������*/
		settextstyle(&itBefore);

		if (ps->getname() == "Soldier") {
			putimage(866, 706, &ps->getImageNormalAttack());
			putimage(936, 706, &ps->getImageRest());
			if (ps->getdrugNum() > 0)
				putimage(1006, 706, &ps->getImageTakeDrug());
			else {
				putimage(1006, 706, &ps->getImageNoDrug());
			}
			IMAGE NONE;
			loadimage(&NONE, "otherScourse\\none.png", 60, 60);
			putimage(1076, 706, &NONE);
			putimage(1146, 706, &NONE);
		}

		if (ps->getname() == "Wizard") {
			putimage(866, 706, &ps->getImageNormalAttack());
			putimage(936, 706, &ps->getImageMagicAttack());
			putimage(1006, 706, &ps->getImageRest());
			if (ps->getdrugNum() > 0)
				putimage(1076, 706, &ps->getImageTakeDrug());
			else {
				putimage(1076, 706, &ps->getImageNoDrug());
			}
			IMAGE NONE;
			loadimage(&NONE, "otherScourse\\none.png", 60, 60);
			putimage(1146, 706, &NONE);
		}

		if (ps->getname() == "Master") {
			putimage(866, 706, &ps->getImageNormalAttack());
			putimage(936, 706, &ps->getImageMagicAttack());
			putimage(1006, 706, &ps->getImageRest());
			putimage(1146, 706, &ps->getImageMasterAttack());
			if (ps->getdrugNum() > 0)
				putimage(1076, 706, &ps->getImageTakeDrug());
			else {
				putimage(1076, 706, &ps->getImageNoDrug());
			}
		}
	}
}
