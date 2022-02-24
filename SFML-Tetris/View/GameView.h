#pragma once

#include <SFML/Graphics.hpp>

#include "UIPersistenceGameData.h"
#include "../Model/Gamedata.h"
#include "../Model/Gamefield.h"
#include "../Model/Figure.h"

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

    sf::Color GetNewColor(const int32_t value) const;

private:
    UIPersistenceGameData m_persistence_game_data_;
    Gamedata              m_game_data_;
    sf::RectangleShape    m_cell_;
    sf::Font              m_font_;
    sf::Text              m_current_level_;
    sf::Text              m_current_score_;
    int64_t               m_handle_update_gamedata_event_;
};

