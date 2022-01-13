#include "GameView.h"

void GameView::Render(sf::RenderWindow& window)
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
