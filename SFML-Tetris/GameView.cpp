#include "GameView.h"

GameView::GameView()
    : cell_(sf::Vector2f(game_data_.CELL_SIZE - 1, game_data_.CELL_SIZE - 1))
{
}
{
    window.clear();

    RenderGamefield(window);
    RenderFigure(window);

    window.display();
}

const UIPersistenceGameData& GameView::GetUIGameData() const
{
    return game_data_;
}

void GameView::RenderFigure(sf::RenderWindow& window)
{
}

void GameView::RenderGamefield(sf::RenderWindow& window)
{
}
