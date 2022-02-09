#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"
#include "GameInstance.h"

#include <cassert>

GameController::GameController(GameModel* new_game_model, GameView* new_game_view)
    : game_model_(new_game_model)
    , game_view_(new_game_view)
{
}

void GameController::PerformLogic(sf::RenderWindow& window)
{
    timer_ = clock_.getElapsedTime();
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            window.close();
        }        
    }

    if (!game_model_->GetIsGameover())
    {
        Gamefield* gamefield = game_model_->GetGamefield();
        Figure*    current_figure = game_model_->GetCurrentFigure();

        assert(gamefield != nullptr);
        assert(current_figure != nullptr);

        PerformEvent(window, event, gamefield, current_figure);

        const float current_speed = game_model_->GetCurrentSpeed();

        if (timer_.asSeconds() > current_speed)
        {
            const bool has_collision = current_figure->MoveDown(gamefield);

            if (has_collision)
            {
                gamefield->PlaceFigure(current_figure);
                const int32_t removed = gamefield->RemoveLines();
                game_model_->GenerateNextFigures();
                game_model_->UpdateScore(removed);

                game_view_->UpdateUIGamedata(game_model_->GetGamedata());

                game_model_->CheckEndGame();
            }

            clock_.restart();
        }
    }
    else
    {
        clock_.restart();
    }

    game_view_->Render(window);
}

void GameController::PerformEvent(sf::RenderWindow& window, const sf::Event& event, Gamefield* gamefield, Figure* figure)
{
    if (event.type == sf::Event::KeyPressed)
    {
#ifdef _DEBUG
        if (event.key.code == sf::Keyboard::RAlt)
        {
            game_model_->GenerateNextFigures();
            game_view_->UpdateUIGamedata(game_model_->GetGamedata());
        }
#endif

        if (event.key.code == sf::Keyboard::Left)
        {
            figure->MoveLeft(gamefield);
        }
        if (event.key.code == sf::Keyboard::Right)
        {
            figure->MoveRight(gamefield);
        }        
        if (event.key.code == sf::Keyboard::Up)
        {
            figure->Rotate(gamefield);
        }
        if (event.key.code == sf::Keyboard::Down)
        {
            timer_ *= 50.0f;
        }
    }    
}