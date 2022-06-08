#include<iostream>
#include<graphics.h>
#include<mmsyscom.h>
#include<string>
#include<Windows.h>
#include<cmath>
#include<map>
#include<list>
#include"Actor.h"
#include"WarSystem.h"
#include<vector>
#include"Systemloger.h"
#include<memory>
#include<cstdlib>
#pragma comment(lib,"Winmm.lib")
#pragma warning(disable:4996)
using namespace std;

void selectMenu(const vector<pair<string, int>>& old = vector<pair<string, int>>());
pair<vector<list<Soldier*>>, vector<list<Soldier*>>> battleIterface(const pair<vector<list<Soldier*>>, vector<list<Soldier*>>>& data = pair<vector<list<Soldier*>>, vector<list<Soldier*>>>());
pair<vector<list<Soldier*>>, vector<list<Soldier*>>>creatGrop(vector<pair<string, int>>actorCreat, bool flag = false,
	const vector<list<Soldier*>>& oldGroupA = vector<list<Soldier*>>());
void helpMenu();

void startMenu() {
	flag:initgraph(1280, 768);
	loadimage(NULL, _T("otherScourse\\start.png"));
	
	TCHAR title[] = _T("�غ���ս����Ϸ");
	settextstyle(45, 0, title);
	outtextxy(485, 250, title);
	
	/*��ʼ���水ť*/
	IMAGE statrt_button, help_button, exit_button;
	loadimage(&statrt_button, _T("otherScourse\\start_button.png"), 186, 44);
	loadimage(&help_button, _T("otherScourse\\help_button.png"), 186, 44);
	loadimage(&exit_button, _T("otherScourse\\exit_button.png"), 186, 44);
	putimage(546, 398, &statrt_button);
	putimage(546, 448, &help_button);
	putimage(546, 498, &exit_button);

	mciSendString("open otherScourse\\start_1.mp3 alias start_1.mp3", 0, 0, 0);
	mciSendString("play start_1.mp3 repeat", 0, 0, 0);
	
	MOUSEMSG it;
	while (true) {
		it = GetMouseMsg();
		if (it.mkLButton) {
			if (it.y <= 442 && it.y >= 398 && it.x >= 548 && it.x <= 734) {
				mciSendString("close start_1.mp3", 0, 0, 0);
				Systemloger::logWrite("click startButton", Systemloger::CLICKLOG);
				selectMenu();
				return;
			}
			if (it.x >= 548 && it.x <= 734 && it.y >= 448 && it.y <= 492) {
				mciSendString("close start_1.mp3", 0, 0, 0);
				Systemloger::logWrite("click helpButton",Systemloger::CLICKLOG);
				helpMenu();
				goto flag;
			}
			if (it.x >= 548 && it.x <= 734 && it.y >= 498 && it.y <= 542) {
				mciSendString("close start_1.mp3", 0, 0, 0);
				Systemloger::logWrite("click start_exit_Button",Systemloger::CLICKLOG);
				exit(0);
				return;
			}
		}
	}
}

void helpMenu() {
	initgraph(1280, 768);
	/*system("PAUSE");*/
	closegraph();
	return;
}

void selectMenu(const vector<pair<string, int>>&old) {
	/*��¼ѡ������*/
	vector<pair<string, int>>actorNums;

	initgraph(1280, 768);
	srand((unsigned) time(0));

	loadimage(NULL, _T("otherScourse\\start.png"));
	
	TCHAR title[] = _T("��ɫѡ��");
	settextstyle(45, 0, title);
	outtextxy(548, 76, title);
	
	TCHAR actor[] = _T("��ҷ�");
	settextstyle(45, 0, actor);
	outtextxy(153, 183, actor);
	
	TCHAR computer[] = _T("���Է�");
	settextstyle(45, 0, computer);
	outtextxy(1023, 183, computer);
	
	mciSendString("open otherScourse\\start_2.mp3 alias start_2.mp3", 0, 0, 0);
	mciSendString("play start_2.mp3 repeat", 0, 0, 0);

	IMAGE soldier, wizard, master;
	loadimage(&soldier, _T("otherScourse\\solder_actor.gif"), 86, 94);
	loadimage(&wizard, _T("otherScourse\\wizard_actor.gif"), 114, 114);
	loadimage(&master, _T("otherScourse\\master_actor.gif"), 266, 166);
	/*��ҷ�*/
	putimage(57, 303, &soldier);
	putimage(203, 303, &wizard);
	putimage(340, 238, &master);
	/*���Է�*/
	putimage(852, 238, &master);
	putimage(1018, 303, &wizard);
	putimage(1175, 303, &soldier);

	int soldierNum{}, wizardNum{}, masterNum{};
	int computerSoldierNum{}, computerWizardNum{}, computerMasterNum{};

	for (; computerSoldierNum + computerWizardNum + computerMasterNum != 4;){
		computerSoldierNum = abs(rand() % 5);
		computerWizardNum = abs(rand() % (5 - computerSoldierNum) % 5);
		computerMasterNum = abs(rand() % (5 - computerWizardNum - computerSoldierNum) % 5);
	}
	
	/*��ʾ���Խ�ɫ����*/
	settextcolor(RED);
	outtextxy(923, 410, computerSoldierNum + '0');
	outtextxy(1059, 410, computerWizardNum + '0');
	outtextxy(1196, 410, computerMasterNum + '0');

	settextcolor(WHITE);

	IMAGE startButton;
	loadimage(&startButton, _T("otherScourse\\start_button2.png"), 186, 44);
	putimage(1053, 666, &startButton);

	/*��ɫ����ѡ��ť*/
	IMAGE buttonRight, buttonLeft;
	loadimage(&buttonRight, _T("otherScourse\\button_right.png"), 35, 37);
	loadimage(&buttonLeft, _T("otherScourse\\button_left.png"), 35, 37);
	/*soldir button*/
	putimage(129, 416, &buttonRight);
	putimage(27, 416, &buttonLeft);
	/*wizard button*/
	putimage(285, 416, &buttonRight);
	putimage(184, 416, &buttonLeft);
	/*master button*/
	putimage(468, 416, &buttonRight);
	putimage(347, 416, &buttonLeft);

	/*չ���Ͼֶ�ս���*/
	TCHAR titleSum[] = "�Ͼ�����";
	outtextxy(120, 494, titleSum);
	TCHAR tipsTitle[] = "��Ӯ���";
	LOGFONT tipsTitleLog;
	LOGFONT nowFront;//���Ի�ԭ����
	gettextstyle(&nowFront);
	gettextstyle(&tipsTitleLog);
	tipsTitleLog.lfHeight = 30;
	settextstyle(&tipsTitleLog);
	outtextxy(31, 569, _T("��Ӯ���:"));
	outtextxy(31, 609, _T("սʿ����:"));
	outtextxy(31, 649, _T("��ʦ����:"));
	outtextxy(31, 689, _T("��ʦ����:"));
	//��Ҫ�ĵ�����
	int iniSolider{}, iniWizard{}, iniMaster{};
	//outtextxy(31, 569, _T("��Ӯ���:"));
	outtextxy(231, 609, iniSolider + '0');
	outtextxy(231, 649, iniWizard + '0');
	outtextxy(231, 689, iniMaster + '0');
	settextstyle(&nowFront);

	MOUSEMSG select;
	while (true) {
		/*��ʾ��ҽ�ɫ����*/
		outtextxy(84, 410, soldierNum + '0');
		outtextxy(239, 410, wizardNum + '0');
		outtextxy(408, 410, masterNum + '0');

		select = GetMouseMsg();

		/*���ٽ�ɫ������ť*/
		if((soldierNum > 0 || wizardNum > 0 || masterNum > 0) && select.mkLButton)
		{
			if (select.y >= 416 && select.y <= 445 && select.x >= 27 && select.x <= 56 && select.mkLButton)
				soldierNum--;
			if (select.y >= 416 && select.y <= 445 && select.x >= 184 && select.x <= 213 && select.mkLButton)
				wizardNum--;
			if (select.y >= 416 && select.y <= 445 && select.x >= 347 && select.x <= 376 && select.mkLButton)
				masterNum--;
		}

		/*���ӽ�ɫ������ť*/
		if (soldierNum + wizardNum + masterNum <= 3 && select.mkLButton) {
			if (select.y >= 416 && select.y <= 445 && select.x >= 129 && select.x <= 158 && select.mkLButton)
				soldierNum++;
			if (select.y >= 416 && select.y <= 445 && select.x >= 285 && select.x <= 314 && select.mkLButton)
				wizardNum++;
			if (select.y >= 416 && select.y <= 445 && select.x >= 468 && select.x <= 497 && select.mkLButton)
				masterNum++;
		}

		if(soldierNum + wizardNum + masterNum == 4)
		if (select.x >= 1053.0 && select.x <= 1265.0 && select.y >= 672.0 && select.y <= 720.0 && select.mkLButton) {
			mciSendString("close start_2.mp3", 0, 0, 0);
			/*���Խ�ɫ����*/
			actorNums.push_back(pair<string, int>("computerSolider", computerSoldierNum));
			actorNums.push_back(pair<string, int>("computerWizard", computerWizardNum));
			actorNums.push_back(pair<string, int>("computerMaster", computerMasterNum));
			/*�û���ɫ����*/
			actorNums.push_back(pair<string, int>("userSolider", soldierNum));
			actorNums.push_back(pair<string, int>("userWizard", wizardNum));
			actorNums.push_back(pair<string, int>("userMaster", masterNum));
			battleIterface(creatGrop(actorNums));//�������
			closegraph();
			return;
		}
	}
}

/*���Ŵ����ӿ�*/
pair<vector<list<Soldier*>>, vector<list<Soldier*>>>creatGrop(vector<pair<string, int>>actorCreat, bool flag,
	const vector<list<Soldier*>>&oldGroupA) {
	vector<list<Soldier*>>groupA;
	vector<list<Soldier*>>groupB;
	
	/*�״ν�����Ϸ*/
	/*Ԥ�ƻ����ӵȼ�����*/
	if(flag==false)
	for (auto index : actorCreat) {
		list<Soldier*>temp;

		/*�״δ������Զ���*/
		if (index.first == "computerSolider") {
			for (int i = 0; i < index.second; i++) {
				temp.push_back(new Soldier(false));
			}
			groupB.push_back(temp);
		}
		if (index.first == "computerWizard") {
			for (int i = 0; i < index.second; i++) {
				temp.push_back(new Wizard(false));
			}
			groupB.push_back(temp);
		}
		if (index.first == "computerMaster") {
			for (int i = 0; i < index.second; i++) {
				temp.push_back(new Master(false));
			}
			groupB.push_back(temp);
		}

		/*�״δ����û���ɫ����*/
		if (index.first == "userSolider") {
			for (int i = 0; i < index.second; i++) {
				temp.push_back(new Soldier(true));
			}
			groupA.push_back(temp);
		}
		if (index.first == "userWizard") {
			for (int i = 0; i < index.second; i++) {
				temp.push_back(new Wizard(true));
			}
			groupA.push_back(temp);
		}
		if (index.first == "userMaster") {
			for (int i = 0; i < index.second; i++) {
				temp.push_back(new Master(true));
			}
			groupA.push_back(temp);
		}
	}
	else {
		/*���·�����Խ�ɫ����*/
		int computerSoldierNum{}, computerWizardNum{}, computerMasterNum{};
		for (; computerSoldierNum + computerWizardNum + computerMasterNum != 4;) {
			computerSoldierNum = abs(rand() % 5);
			computerWizardNum = abs(rand() % (5 - computerSoldierNum) % 5);
			computerMasterNum = abs(rand() % (5 - computerWizardNum - computerSoldierNum) % 5);
		}
		/*Soldier*/
		list<Soldier*>computerSoli,computerWiza,computerMast;
		for (int i = 0; i < computerSoldierNum; i++) {
			computerSoli.push_back(new Soldier(false));
		}
		groupB.push_back(computerSoli);
		/*Wizard*/
		for (int i = 0; i < computerWizardNum; i++) {
			computerWiza.push_back(new Wizard(false));
		}
		groupB.push_back(computerWiza);
		/*Master*/
		for (int i = 0; i < computerMasterNum; i++) {
			computerMast.push_back(new Master(false));
		}
		groupB.push_back(computerMast);

		/*����ʹ���Ͼ��û���ɫ*/
		groupA = oldGroupA;
	}
	return pair< vector<list<Soldier*>>, vector<list<Soldier*>>>(groupA, groupB);
}

/*����ת��TCHAR*/
TCHAR* numToTHAR(double num) {
	string tempStringNum = to_string(num);
	const char* tempCharNum = tempStringNum.c_str();
	TCHAR tempTHAR[100];
#ifdef UNICODE
	MultiByteToWideChar(CP_ACP, 0, tempCharNum, -1, tempTHAR, 100);
#else
	strcpy(tempTHAR, tempCharNum);
#endif
	for (int i = 0; i < tempStringNum.size(); i++) {
		if (tempTHAR[i] == '.') {
			tempTHAR[i + 3] = '\0';
			break;
		}
	}
	return move(tempTHAR);
}

TCHAR* numToTHAR(int num) {
	string tempStringNum = to_string(num);
	const char* tempCharNum = tempStringNum.c_str();
	TCHAR tempTHAR[10];
#ifdef UNICODE
	MultiByteToWideChar(CP_ACP, 0, tempCharNum, -1, tempTHAR, 10);
#else
	strcpy(tempTHAR, tempCharNum);
#endif
	return move(tempTHAR);
}

/*ս������*/
pair<vector<list<Soldier*>>, vector<list<Soldier*>>> battleIterface(const pair<vector<list<Soldier*>>, vector<list<Soldier*>>>&data) {
	/*��ʼ������*/
	/*ѡ��*/
	vector<Soldier*>selectComputer;
	vector<Soldier*>selectUser;
	Soldier* ps = nullptr;
	/*ȥ��const*/
	pair < vector <list<Soldier*>>,vector<list<Soldier*>>> dataIt= const_cast<pair<vector<list<Soldier*>>, vector<list<Soldier*>>>&>(data);
	WarSystem round(dataIt);
	
	/*���Լ�¼�غ���*/
	static int timesCount = 1;
	initgraph(1280, 768);
	loadimage(NULL, "otherScourse\\start.png");
	
	/*��������*/
	TCHAR title_1[] = "��";
	TCHAR title_2[] = "�غ�";
	LOGFONT itWill;
	LOGFONT itBefore;
	gettextstyle(&itWill);
	gettextstyle(&itBefore);
	itWill.lfHeight = 60;
	settextstyle(&itWill);
	outtextxy(543, 62, title_1);
	outtextxy(613, 62, timesCount + '0');
	outtextxy(643, 62, title_2);
	settextstyle(&itBefore);

	/*����*/
	while (true) {
		MOUSEMSG clickImage;
		clickImage = GetMouseMsg();
		/*���Խ�ɫ��־�ֲ�*/
		vector<pair<int, int>>computerPlace = {
			pair<int,int>(883,214),
			pair<int,int>(783,299),
			pair<int,int>(783,407),
			pair<int,int>(883,492)
		};

		{
			int i{};
			for (auto a : round.getGroupB()) {
				for (auto b : a) {
					if (b->getLiveOrDead()) {
						putimage(computerPlace[i].first, computerPlace[i].second, &b->getImageLive());
					}
					else putimage(computerPlace[i].first, computerPlace[i].second, &b->getImageDead());
					selectComputer.push_back(b);
					i++;
				}
			}
		}

		/*�û���ɫ��־�ֲ�*/
		vector<pair<int, int>>userPlace = {
			pair<int,int>(307,214),
			pair<int,int>(407,299),
			pair<int,int>(407,407),
			pair<int,int>(307,492)
		};

		{
			int i{};
			for (auto a : round.getGroupA()) {
				for (auto b : a) {
					if (b->getLiveOrDead()) {
						putimage(userPlace[i].first, userPlace[i].second, &b->getImageLive());
					}
					else putimage(userPlace[i].first, userPlace[i].second, &b->getImageDead());
					selectUser.push_back(b);
					i++;
				}
			}
		}

		/*ѡ����ʾ����*/
		/*��ö���*/
		if (clickImage.mkLButton) {
			if (clickImage.x >= 307 && clickImage.x <= 422 && clickImage.y >= 214 && clickImage.y <= 333)
				ps = selectUser[1];
		}

		if (ps) {
			/*����ͼƬ����*/
			IMAGE actorBelow;
			if (ps->getname() == "Soldier") {
				if (ps->getLiveOrDead())
					loadimage(&actorBelow, "otherScourse\\actor_solider_live.png", 155, 155);
				else
					loadimage(&actorBelow, "otherScourse\\actor_solider_dead.png", 155, 155);
				putimage(0, 613, &actorBelow);
			}
			if (ps->getname() == "Wizard") {
				if (ps->getLiveOrDead())
					loadimage(&actorBelow, "otherScourse\\actor_wizard_live.png", 155, 155);
				else
					loadimage(&actorBelow, "otherScourse\\actor_wizard_dead.png", 155, 155);
				putimage(0, 613, &actorBelow);
			}

			if (ps->getname() == "Master") {
				if (ps->getLiveOrDead())
					loadimage(&actorBelow, "otherScourse\\actor_master_live.png", 155, 155);
				else
					loadimage(&actorBelow, "otherScourse\\actor_master_dead.png", 155, 155);
				putimage(0, 613, &actorBelow);
			}

			/*Master Solider Wizard ��ʾ��������*/
			itWill.lfHeight = 30;
			settextstyle(&itWill);
			outtextxy(160, 613, _T("�ȼ�:"));
			outtextxy(250, 613, numToTHAR(ps->getLevel()));

			outtextxy(160, 653, _T("����:"));
			outtextxy(250, 653, numToTHAR(ps->getHP()));
			outtextxy(370, 653, _T("/"));
			outtextxy(390, 653, numToTHAR(ps->getMaxHP()));

			outtextxy(160, 693, _T("����:"));
			outtextxy(250, 693, numToTHAR(ps->getSP()));
			outtextxy(370, 693, _T("/"));
			outtextxy(390, 693, numToTHAR(ps->getMaxSP()));

			outtextxy(160, 733, _T("����:"));
			outtextxy(250, 733, numToTHAR(ps->getExp()));
			outtextxy(370, 733, _T("/"));
			outtextxy(390, 733, numToTHAR(ps->getMaxExp()));

			/*Wizard and Masterħ��ֵ*/
			if (ps->getname() == "Wizard" || ps->getname() == "Master") {
				outtextxy(500, 733, _T("ħ��:"));
				outtextxy(590, 733, numToTHAR(ps->getMP()));
				outtextxy(710, 733, _T("/"));
				outtextxy(730, 733, numToTHAR(ps->getMaxMP()));
			}
			/*Master����*/
			if (ps->getname() == "Master") {
				outtextxy(500, 693, _T("����:"));
				outtextxy(590, 693, numToTHAR(ps->getNP()));
				outtextxy(710, 693, _T("/"));
				outtextxy(730, 693, numToTHAR(ps->getMaxNP()));
			}
			/*�ָ���������*/
			settextstyle(&itBefore);
		}
	}
	/*�غϼ�һ*/
	timesCount++;
	getchar();
	closegraph();
	return data;
}

/*�������*/
void clearIterface(bool result) {
	initgraph(1280, 768);
	loadimage(NULL, "otherScourse\\start.png");
	IMAGE resultImage;
	if (result) {
		mciSendString("open otherScourse\\vector.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\vector.mp3", 0, 0, 0);
		loadimage(&resultImage, _T("otherScourse\\win_show.png"), 344, 90);
	}
	else {
		mciSendString("open otherScourse\\fail.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\fail.mp3", 0, 0, 0);
		loadimage(&resultImage, _T("otherScourse\\fail_show.png"), 344, 90);
	}
	putimage(493, 220, &resultImage);

	/*������ť*/
	IMAGE contiButton, backStartButton, exitButton;
	loadimage(&contiButton, "otherScourse\\continue_button.png", 264, 76);
	loadimage(&exitButton, "otherScourse\\exit_button.png", 264, 76);
	loadimage(&backStartButton, "otherScourse\\back_startButton.png", 264, 76);
	putimage(531, 495, &contiButton);
	putimage(231, 495, &backStartButton);
	putimage(822, 495, &exitButton);

	/*��ť����*/
	MOUSEMSG clickit;
	while (true) {
		clickit = GetMouseMsg();
		if (clickit.mkLButton) {
			if (clickit.x >= 231 && clickit.x <= 493 && clickit.y >= 496 && clickit.y <= 569) {
				if (result)
					mciSendString("close otherScourse\\vector.mp3", 0, 0, 0);
				else
					mciSendString("close otherScourse\\fail.mp3", 0, 0, 0);
				startMenu();
				return;
			}
			if (clickit.x >= 527 && clickit.x <= 789 && clickit.y >= 496 && clickit.y <= 569) {
				if (result)
					mciSendString("close otherScourse\\vector.mp3", 0, 0, 0);
				else
					mciSendString("close otherScourse\\fail.mp3", 0, 0, 0);
				selectMenu();
				return;
			}
			if (clickit.x >= 822 && clickit.x <= 1084 && clickit.y >= 496 && clickit.y <= 569) {
				if (result)
					mciSendString("close otherScourse\\vector.mp3", 0, 0, 0);
				else
					mciSendString("close otherScourse\\fail.mp3", 0, 0, 0);
				closegraph();
				exit(0);
			}
		}
	}
	return;
}

int main(int argc, char* argv[]) {
	/*clearIterface(true);*/
	/*battleIterface();*/
	startMenu();
	return 0;
}