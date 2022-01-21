#pragma once
#include <SFML/Graphics.hpp>

class GameController
{
public:
    GameController(class GameModel* new_game_model, class GameView* new_game_view);
    void PerformLogic(sf::RenderWindow& window);
    void PerformEvent(sf::RenderWindow& window, const sf::Event& event);
private:
    class GameModel*  game_model_ = nullptr;
    class GameView*   game_view_  = nullptr; 

    sf::Clock   clock_;
    float       delay_ = 2.0f;
    sf::Time    timer_ = clock_.restart();
};

