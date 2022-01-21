#pragma once

#include <SFML/Graphics.hpp>

#include "UIPersistenceGameData.h"
#include "Gamefield.h"
#include "Figure.h"

class GameView
{
public:
    GameView();

    void Render(sf::RenderWindow& window, const Gamefield& gamefield, Figure* figure);

    const UIPersistenceGameData& GetUIGameData() const;

private:
    void RenderFigure(sf::RenderWindow& window, Figure* figure);
    void RenderGamefield(sf::RenderWindow& window, const Gamefield& gamefield);

    sf::Color GetNewColor(const int32_t value) const;

private:
    UIPersistenceGameData   game_data_;
    sf::RectangleShape      cell_;
};

