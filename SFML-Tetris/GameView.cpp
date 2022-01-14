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
void GameView::Render(sf::RenderWindow& window, const Gamefield& gamefield, Figure* figure)
{
    window.clear();

    RenderGamefield(window, gamefield);
    RenderFigure(window, figure);

    window.display();
}

const UIPersistenceGameData& GameView::GetUIGameData() const
{
    return game_data_;
}

void GameView::RenderFigure(sf::RenderWindow& window, Figure* figure)
{
    uint32_t current_position_row    = figure->GetCurrentPosition().row;
    uint32_t current_position_column = figure->GetCurrentPosition().column;

    uint32_t number_rows             = figure->number_rows;
    uint32_t number_columns          = figure->number_columns;

    for (uint32_t row = current_position_row; row < current_position_row + number_rows; ++row)
    {
        for (uint32_t column = current_position_column; column < current_position_column + number_columns; ++column)
        {
            uint32_t current_value = figure->GetFigure()[row - current_position_row][column - current_position_column];
            
            if (current_value != 0)
            {
                cell_.setFillColor(GetNewColor(current_value));

                cell_.setPosition(
                    static_cast<float>(game_data_.CELL_SIZE * column),
                    static_cast<float>(game_data_.CELL_SIZE * row));

                window.draw(cell_);
            }
        }
    }
}

void GameView::RenderGamefield(sf::RenderWindow& window, const Gamefield& gamefield)
{
    uint32_t number_rows    = gamefield.ROWS;
    uint32_t number_columns = gamefield.COLUMNS;

    for (uint32_t row = 0; row < number_rows; ++row)
    {
        for (uint32_t column = 0; column < number_columns; ++column)
        {
            //uint32_t current_value = gamefield.GetField()[row][column];
            //cell_.setFillColor(GetNewColor(current_value));

            cell_.setFillColor(GetNewColor(gamefield.GetField()[row][column]));

            cell_.setPosition(sf::Vector2f(
                static_cast<float>(game_data_.CELL_SIZE * column),
                static_cast<float>(game_data_.CELL_SIZE * row)));

            window.draw(cell_);
        }
    }
}

sf::Color GameView::GetNewColor(uint32_t value) const
{
    switch (value)
    {
    case 1:
        return sf::Color::Cyan;
    case 2:
        return sf::Color::Green;
    case 3:
        return sf::Color::Magenta;
    case 4:
        return sf::Color::Red;
    case 5:
        return sf::Color::White;
    case 6:
        return sf::Color::Yellow;
    default:
        return sf::Color::Blue;
    }
}
