#pragma once

#include <SFML/Window/Event.hpp>

class GameController
{
public:
    GameController() = default;
    
    void ReadPlayerInput(const sf::Event& event, sf::Time& timer,
        const class Gamefield* gamefield, const struct Gamedata& gamedata);
};

