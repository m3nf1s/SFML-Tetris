#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"
#include "GameInstance.h"

#include <cassert>
#include <numeric>
#include <cmath>
#include <iostream>

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
        PerformEvent(window, event);
    }

    Gamefield* gamefield      = game_model_->GetGamefield();
    Figure*    current_figure = game_model_->GetCurrentFigure();
    Figure*    next_figure    = game_model_->GetNextFigure();

    assert(current_figure != nullptr);
    assert(next_figure    != nullptr);

    const float current_speed = game_model_->GetCurrentSpeed();

    if (timer_.asSeconds() > current_speed)
    {
        const bool has_collision = current_figure->MoveDown(gamefield);
        
        if(has_collision)
        {
            gamefield->SetFigure(current_figure);
            int32_t removed = gamefield->RemoveLines();
            std::clog << removed << '\n';
            game_model_->GenerateNewFigure();
            game_model_->UpdateScore(removed);
        }       

        clock_.restart();
    }

    const int32_t current_level = game_model_->GetCurrentLevel();
    const int32_t current_score = game_model_->GetCurrentScore();

    game_view_->Render(window, gamefield, current_figure, next_figure, current_level, current_score);
}

void GameController::PerformEvent(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.type == sf::Event::Closed || 
       (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        window.close();
    }

    if (event.type == sf::Event::KeyPressed)
    {
        Gamefield* gamefield      = game_model_->GetGamefield();
        Figure*    current_figure = game_model_->GetCurrentFigure();

        assert(gamefield != nullptr);
        assert(current_figure != nullptr);

#ifdef _DEBUG
        if (event.key.code == sf::Keyboard::Enter)
        {
            game_model_->GenerateNewFigure();
        }
#endif

        if (event.key.code == sf::Keyboard::Left)
        {
            current_figure->MoveLeft(gamefield);
        }
        if (event.key.code == sf::Keyboard::Right)
        {
            current_figure->MoveRight(gamefield);
        }        
        if (event.key.code == sf::Keyboard::Up)
        {
            current_figure->Rotate(gamefield);
        }
        if (event.key.code == sf::Keyboard::Down)
        {
            timer_ *= 50.0f;
        }
    }    
}