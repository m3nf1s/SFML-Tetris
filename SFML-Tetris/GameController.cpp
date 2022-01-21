#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"
#include "GameInstance.h"

#include <cassert>
#include <numeric>
#include <cmath>

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

    Gamefield& gamefield   = game_model_->GetGamefield();
    Figure* current_figure = game_model_->GetCurrentFigure();
    assert(current_figure != nullptr);

    if (timer_.asSeconds() > delay_)
    {
        const bool has_collision = current_figure->MoveDown(gamefield);
        
        if(has_collision)
        {
            gamefield.SetFigure(current_figure);
            game_model_->SetNewFigure();
        }       

        timer_ = clock_.restart();
    }

    game_view_->Render(window, gamefield, current_figure);
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
        Gamefield& gamefield = game_model_->GetGamefield();
        Figure* current_figure = game_model_->GetCurrentFigure();
        assert(current_figure != nullptr);

        if (event.key.code == sf::Keyboard::Enter)
        {
            game_model_->SetNewFigure();
        }
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