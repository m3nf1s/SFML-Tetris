#include "GameView.h"
#include <cstdint>

GameView::GameView(const Gamedata& gamedata)
    : game_data_(gamedata)
{
    if (persistence_game_data_.CELL_SIZE != 0)
    {
        cell_.setSize(sf::Vector2f(
            static_cast<float>(persistence_game_data_.CELL_SIZE - 1),
            static_cast<float>(persistence_game_data_.CELL_SIZE - 1)));
    }

    font_.loadFromFile("times.ttf");
    current_level_.setFont(font_);
    current_score_.setFont(font_);
}

void GameView::Render(sf::RenderWindow& window)
{
    window.clear();

    RenderGamefield(window);
    RenderFigure(window, game_data_.current_figure);
    RenderFigure(window, game_data_.next_figure);
    RenderText(window);

    window.display();
}

const UIPersistenceGameData& GameView::GetUIGameData() const
{
    return persistence_game_data_;
}

void GameView::RenderFigure(sf::RenderWindow& window, const Figure* figure)
{
    const int32_t current_position_y = figure->GetCurrentPosition().Y;
    const int32_t current_position_x = figure->GetCurrentPosition().X;
    
    const int32_t number_rows    = figure->GetSize();
    const int32_t number_columns = figure->GetSize();

    for (int32_t row = current_position_y; row < current_position_y + number_rows; ++row)
    {
        for (int32_t column = current_position_x; column < current_position_x + number_columns; ++column)
        {
            if (column >= 0)
            {
                const int32_t current_value = figure->Get(row - current_position_y, column - current_position_x);

                if (current_value != 0)
                {
                    cell_.setFillColor(GetNewColor(current_value));

                    cell_.setPosition(
                        static_cast<float>(persistence_game_data_.CELL_SIZE * column),
                        static_cast<float>(persistence_game_data_.CELL_SIZE * row));

                    window.draw(cell_);
                }
            }
        }
    }
}

void GameView::RenderGamefield(sf::RenderWindow& window)
{
    const int32_t number_rows    = game_data_.gamefield->ROWS;
    const int32_t number_columns = game_data_.gamefield->COLUMNS;

    for (int32_t row = 0; row < number_rows; ++row)
    {
        for (int32_t column = 0; column < number_columns; ++column)
        {
            cell_.setFillColor(GetNewColor(game_data_.gamefield->GetCell(row, column)));

            cell_.setPosition(sf::Vector2f(
                static_cast<float>(persistence_game_data_.CELL_SIZE * column),
                static_cast<float>(persistence_game_data_.CELL_SIZE * row)));

            window.draw(cell_);
        }
    }
}

void GameView::RenderText(sf::RenderWindow & window)
{
    const int32_t offset          = 30;
    const int32_t max_figure_size = 5;

    const float cur_lvl_pos_X = static_cast<float>(game_data_.gamefield->COLUMNS * persistence_game_data_.CELL_SIZE + offset);
    const float cur_lvl_pos_Y = static_cast<float>(game_data_.next_figure->GetCurrentPosition().Y + max_figure_size * persistence_game_data_.CELL_SIZE + offset);

    current_level_.setPosition(cur_lvl_pos_X, cur_lvl_pos_Y);
    current_score_.setPosition(cur_lvl_pos_X, cur_lvl_pos_Y + offset);
    
    current_level_.setString("Level: " + std::to_string(game_data_.current_level));
    current_score_.setString("Score: " + std::to_string(game_data_.current_score));

    window.draw(current_level_);
    window.draw(current_score_);
}

sf::Color GameView::GetNewColor(const int32_t value) const
{
    switch (value)
    {
    case 1:
        return sf::Color::Cyan;
    case 2:
        return sf::Color(0, 150, 250);
    case 3:
        return sf::Color(0, 36, 255);
    case 4:
        return sf::Color(255, 146, 0);
    case 5:
        return sf::Color(255, 219, 0);
    case 6:
        return sf::Color(0, 219, 0);
    case 7:
        return sf::Color(146, 0, 255);
    default:
        return sf::Color(36, 36, 85);
    }
}

void GameView::UpdateUIGamedata(const Gamedata& gamedata)
{
    game_data_ = gamedata;
}