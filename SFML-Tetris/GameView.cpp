#include "GameView.h"

GameView::GameView()
{
    if (game_data_.CELL_SIZE != 0)
    {
        cell_.setSize(sf::Vector2f(
            static_cast<float>(game_data_.CELL_SIZE - 1),
            static_cast<float>(game_data_.CELL_SIZE - 1)));
    }

    font_.loadFromFile("times.ttf");
}

void GameView::Render(sf::RenderWindow& window, const Gamefield* gamefield,
                      Figure* current_figure, Figure* next_figure,
                      const int32_t current_level, const int32_t current_score)
{
    window.clear();

    RenderGamefield(window, gamefield);
    RenderFigure(window, current_figure);
    RenderFigure(window, next_figure);
    RenderText(window, gamefield, next_figure, current_level, current_score);

    window.display();
}

const UIPersistenceGameData& GameView::GetUIGameData() const
{
    return game_data_;
}

void GameView::RenderFigure(sf::RenderWindow& window, Figure* figure)
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
                        static_cast<float>(game_data_.CELL_SIZE * column),
                        static_cast<float>(game_data_.CELL_SIZE * row));

                    window.draw(cell_);
                }
            }
        }
    }
}

void GameView::RenderGamefield(sf::RenderWindow& window, const Gamefield* gamefield)
{
    const int32_t number_rows    = gamefield->ROWS;
    const int32_t number_columns = gamefield->COLUMNS;

    for (int32_t row = 0; row < number_rows; ++row)
    {
        for (int32_t column = 0; column < number_columns; ++column)
        {
            cell_.setFillColor(GetNewColor(gamefield->GetCell(row, column)));

            cell_.setPosition(sf::Vector2f(
                static_cast<float>(game_data_.CELL_SIZE * column),
                static_cast<float>(game_data_.CELL_SIZE * row)));

            window.draw(cell_);
        }
    }
}

void GameView::RenderText(sf::RenderWindow & window, const Gamefield* gamefield, const Figure* figure,
                          const int32_t current_level, const int32_t current_score)
{
    const int32_t offset      = 30;
    const int32_t max_figure_size = 5;

    const float cur_lvl_pos_X = static_cast<float>(gamefield->COLUMNS * game_data_.CELL_SIZE + offset);
    const float cur_lvl_pos_Y = static_cast<float>(figure->GetCurrentPosition().Y + max_figure_size * game_data_.CELL_SIZE + offset);

    current_level_.setPosition(cur_lvl_pos_X, cur_lvl_pos_Y);
    current_score_.setPosition(cur_lvl_pos_X, cur_lvl_pos_Y + offset);
    
    UpdateText(font_, current_level_, "Level: " + std::to_string(current_level));
    UpdateText(font_, current_score_, "Score: " + std::to_string(current_score));

    window.draw(current_level_);
    window.draw(current_score_);
}

void GameView::UpdateText(const sf::Font & font, sf::Text & text, const std::string& string_text)
{
    text.setFont(font);
    text.setString(string_text);
}

sf::Color GameView::GetNewColor(const int32_t value) const
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

    //switch (value)
    //{
    //case 1:
    //    return sf::Color(255, 182, 193);
    //case 2:
    //    return sf::Color(255, 160, 122);
    //case 3:
    //    return sf::Color(255, 69, 0);
    //case 4:
    //    return sf::Color(218, 112, 214);
    //case 5:
    //    return sf::Color(75, 0, 130);
    //case 6:
    //    return sf::Color(0, 128, 128);
    //default:
    //    return sf::Color::Blue;
    //}
}
