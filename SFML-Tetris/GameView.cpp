#include "GameView.h"

GameView::GameView()
{
    if (game_data_.CELL_SIZE != 0)
    {
        cell_.setSize(sf::Vector2f(
            static_cast<float>(game_data_.CELL_SIZE - 1),
            static_cast<float>(game_data_.CELL_SIZE - 1)));
    }

}
void GameView::Render(sf::RenderWindow& window, const Gamefield& gamefield)
{
    window.clear();
    
    RenderGamefield(window, gamefield);
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

void GameView::RenderGamefield(sf::RenderWindow& window, const Gamefield& gamefield)
{    
    for (size_t i = 0; i < gamefield.ROWS; ++i)
    {
        for (size_t j = 0; j < gamefield.COLUMNS; ++j)
        {
            switch (gamefield.GetField()[i][j])
            {
            case 1:
                cell_.setFillColor(sf::Color::Cyan);
                break;
            case 2:
                cell_.setFillColor(sf::Color::Green);
                break;
            case 3:
                cell_.setFillColor(sf::Color::Magenta);
                break;
            case 4:
                cell_.setFillColor(sf::Color::Red);
                break;
            case 5:
                cell_.setFillColor(sf::Color::White);
                break;
            case 6:
                cell_.setFillColor(sf::Color::Yellow);
                break;
            case 7:
                cell_.setFillColor(sf::Color::Black);
                break;
            default:
                cell_.setFillColor(sf::Color::Blue);
                break;
            }

            cell_.setPosition(sf::Vector2f(
                (game_data_.CELL_SIZE * j),
                (game_data_.CELL_SIZE * i)));
            window.draw(cell_);
        }
    }
}
