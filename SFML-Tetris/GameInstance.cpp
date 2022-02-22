#include "GameInstance.h"

#include "Model/GameModel.h"
#include "View/GameView.h"
#include "Controller/GameController.h"
#include "EventSystem/EventManager.h"

GameInstance* GameInstance::GetGameInstance()
{
    static GameInstance* instance = new GameInstance();
    return instance;
}

void GameInstance::Start()
{
    Update(m_window_);
}

GameInstance::~GameInstance()
{
}

GameInstance::GameInstance()
    : m_event_manager_(EventManager::GetInstance())
    , m_model_      (std::make_unique<GameModel>())
    , m_view_       (std::make_unique<GameView>(m_model_->GetGamedata()))
    , m_controller_ (std::make_unique<GameController>())
    , m_window_     (sf::VideoMode(
                    m_view_->GetUIGameData().WINDOW_WIDTH,
                    m_view_->GetUIGameData().WINDOW_HEIGHT), "Tetris", sf::Style::Titlebar | sf::Style::Close)
{
}

void GameInstance::Update(sf::RenderWindow& window)
{
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        if(!m_model_->GetIsGameover())
        {
            m_event_manager_->BroadcastGenerateNewFigres();
            //m_event_manager_->BroadcastUpdateGamedata(m_model_->GetGamedata());
            
            m_view_->Render(window);
        }
    }
}
