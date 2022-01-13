#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"

class GameInstance 
{
public:
    static GameInstance& instance();
    
    void Start();
    
    GameInstance(GameInstance& other)           = delete;
    GameInstance& operator=(GameInstance other) = delete;
    
private:
    GameInstance();
    
    void Initialization();
    void Update(sf::RenderWindow& window);
    void Destruction();
    
private:    
    inline static GameInstance*     instance_   = nullptr;
    
    std::unique_ptr<GameModel>      model_;
    std::unique_ptr<GameView>       view_;
    std::unique_ptr<GameController> controller_;
    sf::RenderWindow                window_;
};