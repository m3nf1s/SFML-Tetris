#include "GameInstance.h"


#include <iostream>

GameInstance& GameInstance::instance()
{
	static GameInstance* instance = new GameInstance();
	
	return *instance;
}

void GameInstance::Start()
{
	Initialization();
}

void GameInstance::Initialization()
{
	model_      = std::make_unique<GameModel>();
	view_       = std::make_unique<GameView>();
	controller_ = std::make_unique<GameController>();

	std::clog << "DONE!\n";
}
