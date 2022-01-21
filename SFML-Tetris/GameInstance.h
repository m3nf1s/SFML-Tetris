#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

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
    std::unique_ptr<class GameModel>      model_;
    std::unique_ptr<class GameView>       view_;
    std::unique_ptr<class GameController> controller_;
    sf::RenderWindow                      window_;
};