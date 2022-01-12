#include "GameInstance.h"


#include <iostream>

GameInstance* GameInstance::instance_ = nullptr;

void GameInstance::Destruction()
{
    std::clog << "Instance has been deleted\n";

    delete instance_;
}

GameInstance& GameInstance::instance()
{
	//static GameInstance* instance = new GameInstance();
    if (instance_ == nullptr)
    {
        instance_ = new GameInstance();
        std::clog << "Instance has been created\n";
    }

    
	return *instance_;
}

void GameInstance::Start()
{
	Initialization();

    Destruction();
}

void GameInstance::Initialization()
{    
	model_      = std::make_unique<GameModel>();
	view_       = std::make_unique<GameView>();
	controller_ = std::make_unique<GameController>();

	std::clog << "MVC have been created!\n";
}
