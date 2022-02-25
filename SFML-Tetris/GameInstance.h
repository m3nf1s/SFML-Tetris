#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class GameInstance 
{
public:
    static GameInstance* GetGameInstance();
    static class EventManager* GetEventManager();
    
    void Start();
    
    GameInstance(GameInstance& other)                  = delete;
    GameInstance(GameInstance&& other)                 = delete;
    GameInstance& operator=(const GameInstance& other) = delete;
    GameInstance& operator=(GameInstance&& other)      = delete;
    
    void ReactGameCollision();

    ~GameInstance();
private:
    GameInstance();
   
private:
    std::unique_ptr<class GameModel>      m_model_;
    std::unique_ptr<class GameView>       m_view_;
    std::unique_ptr<class GameController> m_controller_;
    sf::RenderWindow                      m_window_;
    sf::Clock                             m_clock_;
    sf::Time                              m_timer_;    
    float                                 m_current_speed_;
};
