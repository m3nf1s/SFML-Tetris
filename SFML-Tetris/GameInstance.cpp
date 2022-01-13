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
    : model_      (std::make_unique<GameModel>())
    , view_       (std::make_unique<GameView>())
    , controller_ (std::make_unique<GameController>())
    , window_     (sf::VideoMode(
                    view_->GetUIGameData().WINDOW_WIDTH,
                    view_->GetUIGameData().WINDOW_HEIGHT), "Tetris")
{
}

void GameInstance::Initialization()
{
    std::clog << "Game Instance have been initialization!\n";
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

        view_->Render(window);
    }
}

void GameInstance::Destruction()
{
    delete instance_;
    std::clog << "Game Instance has been deleted\n";
}
