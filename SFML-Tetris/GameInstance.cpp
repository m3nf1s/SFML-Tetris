#include "GameInstance.h"


#include <iostream>

GameInstance& GameInstance::instance()
{
	static GameInstance* instance = new GameInstance();

	return *instance;
}

void GameInstance::Start()
{

}
