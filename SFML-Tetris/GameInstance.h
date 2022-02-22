#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "EventSystem/Event.h"
#include "Model/Gamedata.h"

class GameInstance 
{
public:
    static GameInstance* GetGameInstance();
   
    void Start();
    
    GameInstance(GameInstance& other)                  = delete;
    GameInstance(GameInstance&& other)                 = delete;
    GameInstance& operator=(const GameInstance& other) = delete;
    GameInstance& operator=(GameInstance&& other)      = delete;

    ~GameInstance();
private:
    GameInstance();

    void Update(sf::RenderWindow& window);
    
private:
    std::unique_ptr<class EventManager>   m_event_manager_;
    std::unique_ptr<class GameModel>      m_model_;
    std::unique_ptr<class GameView>       m_view_;
    std::unique_ptr<class GameController> m_controller_;
    sf::RenderWindow                      m_window_;
    sf::Clock                             m_clock_;
};
