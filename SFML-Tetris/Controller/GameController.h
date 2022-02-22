#pragma once
#include <SFML/Graphics.hpp>

class GameController
{
public:
    GameController() = default;
    void ReadInputEvent(const sf::Event& event);
};

