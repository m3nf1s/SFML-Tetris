#pragma once

#include <SFML/Graphics.hpp>

#include "UIPersistenceGameData.h"

class GameView
{
public:
    void Render(sf::RenderWindow& window);
    const UIPersistenceGameData& GetUIGameData() const;

private:
    void RenderFigure(sf::RenderWindow& window);
    void RenderGamefield(sf::RenderWindow& window);

private:
    UIPersistenceGameData game_data_;
};

