#pragma once
#include <SFML/Graphics.hpp>

class GameController
{
public:
    GameController(class GameModel* new_game_model, class GameView* new_game_view);
    void PerformLogic(sf::RenderWindow& window);
    void PerformEvent(sf::RenderWindow& window, const sf::Event& event);
private:
    class GameModel*  game_model_;
    class GameView*   game_view_;

    float       delay_ = 5000.0f;
    sf::Clock   clock_;
    sf::Time    timer_ = clock_.restart();
};

