#include "UI.h"

/*��������*/
void UI::helpMenu()
{
	initgraph(1280, 768);
	/*system("PAUSE");*/
	closegraph();
	return;
}

/*��ɫѡ�����*/
void UI::selectMenu(const vector<pair<string, int>>& old)
{
	/*��¼ѡ������*/
	vector<pair<string, int>>actorNums;

	initgraph(1280, 768);
	srand((unsigned)time(0));

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

	for (; computerSoldierNum + computerWizardNum + computerMasterNum != 4;) {
		computerSoldierNum = abs(rand() % 5);
		computerWizardNum = abs(rand() % (5 - computerSoldierNum) % 5);
		computerMasterNum = abs(rand() % (5 - computerWizardNum - computerSoldierNum) % 5);
	}

	/*��ʾ���Խ�ɫ����*/
	settextcolor(RED);
	outtextxy(923, 410, computerMasterNum + '0');
	outtextxy(1059, 410, computerWizardNum + '0');
	outtextxy(1196, 410, computerSoldierNum + '0');

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
	LOGFONT nowFront;
	gettextstyle(&nowFront);
	gettextstyle(&tipsTitleLog);
	tipsTitleLog.lfHeight = 30;
	settextstyle(&tipsTitleLog);
	outtextxy(31, 569, _T("��Ӯ���:"));
	outtextxy(31, 609, _T("սʿ����:"));
	outtextxy(31, 649, _T("��ʦ����:"));
	outtextxy(31, 689, _T("��ʦ����:"));
	fstream it;
	Systemloger::logRead(it, Systemloger::BATTELLOG);
	if (it.is_open()) {
		while (!it.eof()) {
			string temp;
			getline(it, temp);
			TCHAR TEMP[100];
			outtextxy(231, 569, tools::numToTHAR(temp,TEMP));
			getline(it, temp);
			outtextxy(231, 609, tools::numToTHAR(temp, TEMP));
			getline(it, temp);
			outtextxy(231, 649, tools::numToTHAR(temp, TEMP));
			getline(it, temp);
			outtextxy(231, 689, tools::numToTHAR(temp, TEMP));
		}
		it.close();
		remove(Systemloger::fileName(Systemloger::BATTELLOG));
	}
	else{
		outtextxy(231, 569, "**");
		outtextxy(231, 609, "**");
		outtextxy(231, 649, "**");
		outtextxy(231, 689, "**");
	}
	settextstyle(&nowFront);

	MOUSEMSG select;
	while (true) {
		/*��ʾ��ҽ�ɫ����*/
		outtextxy(84, 410, soldierNum + '0');
		outtextxy(239, 410, wizardNum + '0');
		outtextxy(408, 410, masterNum + '0');

		select = GetMouseMsg();

		/*���ٽ�ɫ������ť*/
		if ((soldierNum > 0 || wizardNum > 0 || masterNum > 0) && select.mkLButton)
		{
			if (select.y >= 416 && select.y <= 445 && select.x >= 27 && select.x <= 56 && select.mkLButton) {
				Systemloger::logWrite("Soldier sub click OK", Systemloger::CLICKLOG);
				if(soldierNum > 0)
				soldierNum--;
				else
				{
					Systemloger::logWrite("Soldier sub click OK but can't sub", Systemloger::CLICKLOG);
				}
			}
			if (select.y >= 416 && select.y <= 445 && select.x >= 184 && select.x <= 213 && select.mkLButton) {
				Systemloger::logWrite("Wizard sub click OK", Systemloger::CLICKLOG);
				if (wizardNum > 0)
				wizardNum--;
				else
				{
					Systemloger::logWrite("Wizard sub click OK but can't sub", Systemloger::CLICKLOG);
				}
			}
			if (select.y >= 416 && select.y <= 445 && select.x >= 347 && select.x <= 376 && select.mkLButton) {
				Systemloger::logWrite("Master sub click OK", Systemloger::CLICKLOG);
				if (masterNum > 0)
				masterNum--;
				else
				{
					Systemloger::logWrite("Master sub click OK but can't sub", Systemloger::CLICKLOG);
				}
			}
		}

		/*���ӽ�ɫ������ť*/
		if (soldierNum + wizardNum + masterNum <= 3 && select.mkLButton) {
			if (select.y >= 416 && select.y <= 445 && select.x >= 129 && select.x <= 158 && select.mkLButton) {
				Systemloger::logWrite("Soldier add click OK", Systemloger::CLICKLOG);
				soldierNum++;
			}
			if (select.y >= 416 && select.y <= 445 && select.x >= 285 && select.x <= 314 && select.mkLButton) {
				Systemloger::logWrite("Wizard add click OK", Systemloger::CLICKLOG);
				wizardNum++;
			}
			if (select.y >= 416 && select.y <= 445 && select.x >= 468 && select.x <= 497 && select.mkLButton) {
				Systemloger::logWrite("Master add click OK", Systemloger::CLICKLOG);
				masterNum++;
			}
		}

		if (soldierNum + wizardNum + masterNum == 4)
			if (select.x >= 1053.0 && select.x <= 1265.0 && select.y >= 672.0 && select.y <= 720.0 && select.mkLButton) {
				Systemloger::logWrite("SelectActor continue to play Game click OK", Systemloger::CLICKLOG);
				mciSendString("close start_2.mp3", 0, 0, 0);
				/*���Խ�ɫ����*/
				actorNums.push_back(pair<string, int>("computerSolider", computerSoldierNum));
				actorNums.push_back(pair<string, int>("computerWizard", computerWizardNum));
				actorNums.push_back(pair<string, int>("computerMaster", computerMasterNum));
				/*�û���ɫ����*/
				actorNums.push_back(pair<string, int>("userSolider", soldierNum));
				actorNums.push_back(pair<string, int>("userWizard", wizardNum));
				actorNums.push_back(pair<string, int>("userMaster", masterNum));
				battleIterface(creatGrop(actorNums));
			}
	}
}

/*������Ŵ���*/
pair<vector<list<Soldier*>>, vector<list<Soldier*>>> UI::creatGrop(vector<pair<string, int>> actorCreat, bool flag, const vector<list<Soldier*>>& oldGroupA)
{
	srand(unsigned(time(NULL)));
	vector<list<Soldier*>>groupA;
	vector<list<Soldier*>>groupB;

	/*�״ν�����Ϸ*/
	/*Ԥ�ƻ����ӵȼ�����*/
	if (flag == false)
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
	return pair< vector<list<Soldier*>>, vector<list<Soldier*>>>(groupA, groupB);
}

/*�ɾ��Ŵ���*/
const pair<vector<list<Soldier*>>, vector<list<Soldier*>>> UI::creatGrop()
{
	cleardevice();
	srand(unsigned(time(NULL)));
	vector<list<Soldier*>>groupA;
	vector<list<Soldier*>>groupB;

	/*��ȡ�ļ����н�ɫ����*/
	fstream in;
	Systemloger::logRead(in, Systemloger::OLDDATA);
	list<Soldier*>tempgroup;
	while (!in.eof()) {
		string tempName;
		getline(in, tempName);
		if (tempName == "Soldier") {
			string temp;
			getline(in, temp);
			if (temp == "0") {
				tempgroup.push_back(new Soldier(true));
				getline(in, temp);
				getline(in, temp);
			}
			else {
				Soldier* ptem = new Soldier(true);
				getline(in, temp);
				const char* p = temp.c_str();
				for (int i = 1; i < atoi(p); i++)
					ptem->getLevel();
				getline(in, temp);
				const char* pe = temp.c_str();
				ptem->setExp(atoi(pe));
				tempgroup.push_back(ptem);
			}
		}
		if (tempName == "Wizard") {
			string temp;
			getline(in, temp);
			if (temp == "0") {
				tempgroup.push_back(new Wizard(true));
				getline(in, temp);
				getline(in, temp);
			}
			else {
				Soldier* ptem = new Wizard(true);
				getline(in, temp);
				const char* p = temp.c_str();
				for (int i = 1; i < atoi(p); i++)
					ptem->getLevel();
				getline(in, temp);
				const char* pe = temp.c_str();
				ptem->setExp(atoi(pe));
				tempgroup.push_back(ptem);
			}
		}
		if (tempName == "Master") {
			string temp;
			getline(in, temp);
			if (temp == "0") {
				tempgroup.push_back(new Master(true));
				getline(in, temp);
				getline(in, temp);
			}
			else {
				Soldier* ptem = new Master(true);
				getline(in, temp);
				const char* p = temp.c_str();
				for (int i = 1; i < atoi(p); i++)
					ptem->getLevel();
				getline(in, temp);
				const char* pe = temp.c_str();
				ptem->setExp(atoi(pe));
				tempgroup.push_back(ptem);
			}
		}
	}
	in.close();
	remove(Systemloger::fileName(Systemloger::OLDDATA));
	groupA.push_back(tempgroup);

	/*���·�����Խ�ɫ����*/
	int computerSoldierNum{}, computerWizardNum{}, computerMasterNum{};
	for (; computerSoldierNum + computerWizardNum + computerMasterNum != 4;) {
		computerSoldierNum = abs(rand() % 5);
		computerWizardNum = abs(rand() % (5 - computerSoldierNum) % 5);
		computerMasterNum = abs(rand() % (5 - computerWizardNum - computerSoldierNum) % 5);
	}
	/*Soldier*/
	list<Soldier*>computerSoli, computerWiza, computerMast;
	for (int i = 0; i < computerSoldierNum; i++) {
		computerSoli.push_back(new Soldier(false));
	}
	if (computerSoli.size() != 0)
		groupB.push_back(computerSoli);
	/*Wizard*/
	for (int i = 0; i < computerWizardNum; i++) {
		computerWiza.push_back(new Wizard(false));
	}
	if (computerWiza.size() != 0)
		groupB.push_back(computerWiza);
	/*Master*/
	for (int i = 0; i < computerMasterNum; i++) {
		computerMast.push_back(new Master(false));
	}
	if (computerMast.size() != 0)
		groupB.push_back(computerMast);

	return pair< vector<list<Soldier*>>, vector<list<Soldier*>>>(groupA, groupB);
}

/*ս������*/
void UI::battleIterface(const pair<vector<list<Soldier*>>, vector<list<Soldier*>>>& data)
{
	/*��ʼ������*/
	/*ѡ��*/
	initgraph(1280, 768);
	vector<Soldier*>selectComputer;
	vector<Soldier*>selectUser;
	/*ȥ��const*/
	pair < vector <list<Soldier*>>, vector<list<Soldier*>>> dataIt = const_cast<pair<vector<list<Soldier*>>, vector<list<Soldier*>>>&>(data);
	WarSystem* round = new WarSystem(dataIt);

	srand(unsigned(time(NULL)));
	int whichMusic = rand() % 4 + 1;
	if (whichMusic == 1) {
		mciSendString("open otherScourse\\battle1.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\battle1.mp3 repeat", 0, 0, 0);
	}
	else if (whichMusic == 2) {
		mciSendString("open otherScourse\\battle2.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\battle2.mp3 repeat", 0, 0, 0);
	}
	else if (whichMusic == 3) {
		mciSendString("open otherScourse\\battle3.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\battle3.mp3 repeat", 0, 0, 0);
	}
	else {
		mciSendString("open otherScourse\\battle4.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\battle4.mp3 repeat", 0, 0, 0);
	}

	/*���Լ�¼�غ���*/
	static int timesCount = 1;
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

	/*���Խ�ɫ��־�ֲ�*/
	vector<pair<int, int>>computerPlace = {
		pair<int,int>(883,214),
		pair<int,int>(783,299),
		pair<int,int>(783,407),
		pair<int,int>(883,492)
	};

	{
		int i{};
		for (auto& a : round->getGroupB()) {
			for (auto& b : a) {
				if (b->getIsLiveFlag()) {
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
		for (auto& a : round->getGroupA()) {
			for (auto& b : a) {
				if (b->getIsLiveFlag()) {
					putimage(userPlace[i].first, userPlace[i].second, &b->getImageLive());
				}
				else putimage(userPlace[i].first, userPlace[i].second, &b->getImageDead());
				selectUser.push_back(b);
				i++;
			}
		}
	}

	/*���������ⲿ�ֽ������ƶ��͸���*/
	while (true) {
		/*����*/
		pair<bool, bool>finalWin = round->War();
		/*Ӯ*/
		if (finalWin.first == true && finalWin.second == false) {
			timesCount++;
			if (whichMusic == 1) {
				mciSendString("close otherScourse\\battle1.mp3", 0, 0, 0);
			}
			else if (whichMusic == 2) {
				mciSendString("close otherScourse\\battle2.mp3", 0, 0, 0);
			}
			else if (whichMusic == 3) {
				mciSendString("close otherScourse\\battle3.mp3", 0, 0, 0);
			}
			else {
				mciSendString("close otherScourse\\battle4.mp3", 0, 0, 0);
			}
			delete round;
			clearIterface(finalWin.first);
			break;
		}
		/*��*/
		if (finalWin.first == false && finalWin.second == true) {
			timesCount++;
			if (whichMusic == 1) {
				mciSendString("close otherScourse\\battle1.mp3", 0, 0, 0);
			}
			else if (whichMusic == 2) {
				mciSendString("close otherScourse\\battle2.mp3", 0, 0, 0);
			}
			else if (whichMusic == 3) {
				mciSendString("close otherScourse\\battle3.mp3", 0, 0, 0);
			}
			else {
				mciSendString("close otherScourse\\battle4.mp3", 0, 0, 0);
			}
			delete round;
			clearIterface(finalWin.first);
			break;
		}
	}
}

/*�������*/
void UI::clearIterface(bool result)
{
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
				closegraph();
				startMenu();
				return;
			}
			if (clickit.x >= 527 && clickit.x <= 789 && clickit.y >= 496 && clickit.y <= 569) {
				if (result)
					mciSendString("close otherScourse\\vector.mp3", 0, 0, 0);
				else
					mciSendString("close otherScourse\\fail.mp3", 0, 0, 0);
				if (result)
					battleIterface(creatGrop());
				else startMenu();
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

/*��ʼ����*/
void UI::startMenu()
{
flag:initgraph(1280, 768);
	remove(Systemloger::fileName(Systemloger::OLDDATA));
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
				Systemloger::logWrite("click helpButton", Systemloger::CLICKLOG);
				helpMenu();
				goto flag;
			}
			if (it.x >= 548 && it.x <= 734 && it.y >= 498 && it.y <= 542) {
				mciSendString("close start_1.mp3", 0, 0, 0);
				Systemloger::logWrite("click start_exit_Button", Systemloger::CLICKLOG);
				exit(0);
				return;
			}
		}
	}
}
