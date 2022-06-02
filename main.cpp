#include<iostream>
#include<graphics.h>
#include<mmsyscom.h>
#include<string>
#include<Windows.h>
#include<cmath>
#include<fstream>
#pragma comment(lib,"Winmm.lib")
using namespace std;

void selectMenu();
void battleIterface();
void helpMenu();

void startMenu() {
	flag:initgraph(1280, 768);
	loadimage(NULL, _T("otherScourse\\start.png"));
	
	TCHAR title[] = _T("回合制战斗游戏");
	settextstyle(45, 0, title);
	outtextxy(485, 250, title);
	
	/*开始界面按钮*/
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
				selectMenu();
				return;
			}
			if (it.x >= 548 && it.x <= 734 && it.y >= 448 && it.y <= 492) {
				mciSendString("close start_1.mp3", 0, 0, 0);
				helpMenu();
				goto flag;
			}
			if (it.x >= 548 && it.x <= 734 && it.y >= 498 && it.y <= 542) {
				mciSendString("close start_1.mp3", 0, 0, 0);
				exit(0);
				return;
			}
		}
	}
}

void helpMenu() {
	initgraph(1280, 768);
	system("PAUSE");
	closegraph();
	return;
}

void selectMenu() {
	initgraph(1280, 768);
	srand((unsigned) time(0));

	loadimage(NULL, _T("otherScourse\\start.png"));
	
	TCHAR title[] = _T("角色选择");
	settextstyle(45, 0, title);
	outtextxy(548, 76, title);
	
	TCHAR actor[] = _T("玩家方");
	settextstyle(45, 0, actor);
	outtextxy(153, 183, actor);
	
	TCHAR computer[] = _T("电脑方");
	settextstyle(45, 0, computer);
	outtextxy(1023, 183, computer);
	
	mciSendString("open otherScourse\\start_2.mp3 alias start_2.mp3", 0, 0, 0);
	mciSendString("play start_2.mp3 repeat", 0, 0, 0);

	IMAGE soldier, wizard, master;
	loadimage(&soldier, _T("otherScourse\\solder_actor.gif"), 86, 94);
	loadimage(&wizard, _T("otherScourse\\wizard_actor.gif"), 114, 114);
	loadimage(&master, _T("otherScourse\\master_actor.gif"), 266, 166);
	/*玩家方*/
	putimage(57, 303, &soldier);
	putimage(203, 303, &wizard);
	putimage(340, 238, &master);
	/*电脑方*/
	putimage(852, 238, &master);
	putimage(1018, 303, &wizard);
	putimage(1175, 303, &soldier);

	int soldierNum{}, wizardNum{}, masterNum{};

	int computerSoldierNum{}, computerWizardNum{}, computerMasterNum{};
	for (; computerSoldierNum + computerWizardNum + computerMasterNum != 4;){
		computerSoldierNum = fabs(rand() % 5);
		computerWizardNum = fabs(rand() % (5 - computerSoldierNum) % 5);
		computerMasterNum = fabs(rand() % (5 - computerWizardNum - computerSoldierNum) % 5);
	}
	/*显示电脑角色数量*/
	settextcolor(RED);
	outtextxy(923, 410, computerSoldierNum + '0');
	outtextxy(1059, 410, computerWizardNum + '0');
	outtextxy(1196, 410, computerMasterNum + '0');

	settextcolor(WHITE);

	IMAGE startButton;
	loadimage(&startButton, _T("otherScourse\\start_button2.png"), 186, 44);
	putimage(1053, 666, &startButton);

	/*角色数量选择按钮*/
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

	/*展现上局对战情况*/
	TCHAR titleSum[] = "上局数据";
	outtextxy(120, 494, titleSum);
	TCHAR tipsTitle[] = "输赢情况";
	LOGFONT tipsTitleLog;
	LOGFONT nowFront;//用以还原字体
	gettextstyle(&nowFront);
	gettextstyle(&tipsTitleLog);
	tipsTitleLog.lfHeight = 30;
	settextstyle(&tipsTitleLog);
	outtextxy(31, 569, _T("输赢情况:"));
	outtextxy(31, 609, _T("战士数量:"));
	outtextxy(31, 649, _T("巫师数量:"));
	outtextxy(31, 689, _T("大师数量:"));
	//需要文档内容
	size_t iniSolider{}, iniWizard{}, iniMaster{};
	//outtextxy(31, 569, _T("输赢情况:"));
	outtextxy(231, 609, iniSolider + '0');
	outtextxy(231, 649, iniWizard + '0');
	outtextxy(231, 689, iniMaster + '0');
	settextstyle(&nowFront);

	MOUSEMSG select;
	while (true) {
		/*显示玩家角色数量*/
		outtextxy(84, 410, soldierNum + '0');
		outtextxy(239, 410, wizardNum + '0');
		outtextxy(408, 410, masterNum + '0');

		select = GetMouseMsg();

		/*减少角色数量按钮*/
		if((soldierNum > 0 || wizardNum > 0 || masterNum > 0) && select.mkLButton)
		{
			if (select.y >= 416 && select.y <= 445 && select.x >= 27 && select.x <= 56 && select.mkLButton)
				soldierNum--;
			if (select.y >= 416 && select.y <= 445 && select.x >= 184 && select.x <= 213 && select.mkLButton)
				wizardNum--;
			if (select.y >= 416 && select.y <= 445 && select.x >= 347 && select.x <= 376 && select.mkLButton)
				masterNum--;
		}

		/*增加角色数量按钮*/
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
			battleIterface();//差传入数据
			closegraph();
			return;
		}
	}
}

void battleIterface() {
	initgraph(1280, 768);
	loadimage(NULL, "otherScourse\\start.png");
	
	getchar();
	closegraph();
	return;
}

void clearIterface(bool result) {
	initgraph(1280, 768);
	loadimage(NULL, "otherScourse\\start.png");
	IMAGE re;
	if (result) {
		mciSendString("open otherScourse\\vector.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\vector.mp3", 0, 0, 0);
		loadimage(&re, _T("otherScourse\\win_show.png"), 344, 90);
	}
	else {
		mciSendString("open otherScourse\\fail.mp3", 0, 0, 0);
		mciSendString("play otherScourse\\fail.mp3", 0, 0, 0);
		loadimage(&re, _T("otherScourse\\fail_show.png"), 344, 90);
	}
	putimage(493, 220, &re);

	/*操作按钮*/
	IMAGE contiButton, backStartButton, exitButton;
	loadimage(&contiButton, "otherScourse\\continue_button.png", 264, 76);
	loadimage(&exitButton, "otherScourse\\exit_button.png", 264, 76);
	loadimage(&backStartButton, "otherScourse\\back_startButton.png", 264, 76);
	putimage(531, 495, &contiButton);
	putimage(231, 495, &backStartButton);
	putimage(822, 495, &exitButton);

	/*按钮操作*/
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

void logWrite(string &data) {
	ofstream out;
	out.open("dataGame.log", ios::out);
	out << time(NULL) << " " << data << endl;
	out.close();
	return;
}

string& logRead(string& data) {
	ifstream in;
	in.open("dataGame.log", ios::in);
	while (!in.eof()) {
		getline(in, data);
	}
	return data;
}

int main(int argc, char* argv[]) {
	/*clearIterface(true);*/
	startMenu();
	return 0;
}