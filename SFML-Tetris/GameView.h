#pragma once

#include <SFML/Graphics.hpp>

#include "UIPersistenceGameData.h"
#include "Gamedata.h"
#include "Gamefield.h"
#include "Figure.h"

class GameView
{
public:
    GameView(const Gamedata& gamedata);

    void Render(sf::RenderWindow& window);
    void UpdateUIGamedata(const Gamedata& gamedata);

    const UIPersistenceGameData& GetUIGameData() const;

private:
    void RenderFigure(sf::RenderWindow& window, const Figure* figure);
    void RenderGamefield(sf::RenderWindow& window);
    void RenderText(sf::RenderWindow& window);
    void UpdateText(const sf::Font& font, sf::Text& text, const std::string& string_text);

    sf::Color GetNewColor(const int32_t value) const;

private:


private:
    UIPersistenceGameData persistence_game_data_;
    Gamedata              game_data_;
    sf::RectangleShape    cell_;
    sf::Font              font_;
    sf::Text              current_level_;
    sf::Text              current_score_;

};

