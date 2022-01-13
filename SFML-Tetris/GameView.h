#pragma once

#include <SFML/Graphics.hpp>

#include "UIPersistenceGameData.h"
#include "Gamefield.h"

class GameView
{
public:
    GameView();
    void Render(sf::RenderWindow& window, const Gamefield& gamefield);
    const UIPersistenceGameData& GetUIGameData() const;

private:
    void RenderFigure(sf::RenderWindow& window);
    void RenderGamefield(sf::RenderWindow& window, const Gamefield& gamefield);

private:
    UIPersistenceGameData game_data_;
    sf::RectangleShape    cell_;
};

