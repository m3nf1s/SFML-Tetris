#include "GameInstance.h"

#include "GameModel.h"
#include "GameView.h"
#include "GameController.h"

GameInstance* GameInstance::GetGameInstance()
{
    static GameInstance* instance = new GameInstance();
    return instance;
}

void GameInstance::Start()
{
    Update(window_);
}

GameInstance::~GameInstance()
{
}

GameInstance::GameInstance()
    : model_      (std::make_unique<GameModel>())
    , view_       (std::make_unique<GameView>())
    , controller_ (std::make_unique<GameController>(model_.get(), view_.get()))
    , window_     (sf::VideoMode(
                    view_->GetUIGameData().WINDOW_WIDTH,
                    view_->GetUIGameData().WINDOW_HEIGHT), "Tetris")
{
}

void GameInstance::Update(sf::RenderWindow& window)
{
    while (window.isOpen())
    {
        controller_->PerformLogic(window);
    }
}
