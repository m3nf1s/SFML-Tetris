#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"
#include "GameInstance.h"

GameController::GameController(GameModel* new_game_model, GameView* new_game_view)
    : game_model_(new_game_model)
    , game_view_(new_game_view)
{
}

void GameController::PerformLogic(sf::RenderWindow& window)
{
    sf::Event event;
    if (window.pollEvent(event))
    {
        PerformEvent(window, event);
    }
    if (timer_.asSeconds() > delay_)
    {
        game_model_->GetCurrentFigure()->SetNewPosition(
            game_model_->GetCurrentFigure()->GetCurrentPosition().row + 1,
            game_model_->GetCurrentFigure()->GetCurrentPosition().column);

        timer_ = clock_.restart();
    }
    else
    {
        timer_ += clock_.getElapsedTime();
    }
    game_view_->Render(window, game_model_->GetGamefield(), game_model_->GetCurrentFigure());
}

void GameController::PerformEvent(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }

    if (event.type == sf::Event::KeyPressed)
    {
        uint32_t current_row    = game_model_->GetCurrentFigure()->GetCurrentPosition().row;
        uint32_t current_column = game_model_->GetCurrentFigure()->GetCurrentPosition().column;

        if (event.key.code == sf::Keyboard::Enter)
        {
            game_model_->SetNewFigure();
        }
        if (event.key.code == sf::Keyboard::Left)
        {
            if (current_column > 0)
            {
                current_column -= 1;
                game_model_->GetCurrentFigure()->SetNewPosition(current_row, current_column);
            }
        }
        if (event.key.code == sf::Keyboard::Right)
        {
            if (current_column < game_model_->GetGamefield().COLUMNS - game_model_->GetCurrentFigure()->number_columns)
            {
                current_column += 1;
                game_model_->GetCurrentFigure()->SetNewPosition(current_row, current_column);
            }
        }        
        if (event.key.code == sf::Keyboard::Down)
        {
            current_row += 1;
            game_model_->GetCurrentFigure()->SetNewPosition(current_row, current_column);
        }
    }    
}