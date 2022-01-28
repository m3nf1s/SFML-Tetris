#pragma once

#include <SFML/Graphics.hpp>

#include "UIPersistenceGameData.h"
#include "Gamefield.h"
#include "Figure.h"

class GameView
{
public:
    GameView();

    void Render(sf::RenderWindow& window, const Gamefield* gamefield,
               Figure* current_figure, Figure* next_figure,
               const int32_t current_level, const int32_t current_score);

    const UIPersistenceGameData& GetUIGameData() const;

private:
    void RenderFigure(sf::RenderWindow& window, Figure* figure);
    void RenderGamefield(sf::RenderWindow& window, const Gamefield* gamefield);
    void RenderText(sf::RenderWindow& window, const Gamefield* gamefield, const Figure* figure,
                    const int32_t current_level, const int32_t current_score);
    void UpdateText(const sf::Font& font, sf::Text& text, const std::string& string_text);

    sf::Color GetNewColor(const int32_t value) const;

private:
    UIPersistenceGameData   game_data_;
    sf::RectangleShape      cell_;

    sf::Font                font_;
    sf::Text                current_level_;
    sf::Text                current_score_;
};

