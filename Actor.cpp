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
		else throw "创建错误";
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
		else throw "创建错误";
	}
}

IMAGE& Soldier::getImageLive()
{
	return this->liveActorImage;
}

IMAGE& Soldier::getImageDead()
{
	return this->deadActorImage;
}

IMAGE& Soldier::getImageLowBlood()
{
	return this->lowbloodImage;
}


/*WizardMethod*/

/*MasterMethod*/
