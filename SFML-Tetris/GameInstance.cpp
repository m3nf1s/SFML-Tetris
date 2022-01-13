#include "GameInstance.h"


#include <iostream>

GameInstance& GameInstance::instance()
{
    //static GameInstance* instance = new GameInstance();
    if (instance_ == nullptr)
    {
        instance_ = new GameInstance();

        std::clog << "Game Instance has been created\n";
    }


    return *instance_;
}

void GameInstance::Start()
{
    Initialization();

    Update(window_);

    Destruction();
}

GameInstance::GameInstance()
    : window_(sf::VideoMode(800, 600), "Tetris")
{
}

void GameInstance::Initialization()
{
    model_ = std::make_unique<GameModel>();
    std::clog << "Model have been created!\n";

    view_ = std::make_unique<GameView>();
    std::clog << "View have been created!\n";

    controller_ = std::make_unique<GameController>();
    std::clog << "Controller have been created!\n";
}

void GameInstance::Update(sf::RenderWindow & window)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}

void GameInstance::Destruction()
{
    delete instance_;
    std::clog << "Game Instance has been deleted\n";
}
