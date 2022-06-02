#include "WarSystem.h"

void WarSystem::selectGroup()
{
	srand(unsigned(time(NULL)));
	GroupA = bool( rand() % 1);
	if (!GroupA)
		GroupB = true;
}

void WarSystem::battleLogic() {

}