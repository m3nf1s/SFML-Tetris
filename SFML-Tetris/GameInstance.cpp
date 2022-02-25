#include "GameInstance.h"

#include <cassert>

#include "Model/GameModel.h"
#include "View/GameView.h"
#include "GameController/GameController.h"
#include "EventSystem/EventManager.h"

GameInstance::GameInstance()
    : m_model_(std::make_unique<GameModel>())
    , m_view_(std::make_unique<GameView>(m_model_->GetGamedata()))
    , m_controller_(std::make_unique<GameController>())
    , m_window_(sf::VideoMode(
        m_view_->GetUIGameData().WINDOW_WIDTH,
        m_view_->GetUIGameData().WINDOW_HEIGHT), "Tetris")
    , m_current_speed_(m_model_->GetCurrentSpeed())
{
    m_window_.setFramerateLimit(30);
}

void GameInstance::ReactGameCollision()
{

}

GameInstance::~GameInstance()
{
}

GameInstance* GameInstance::GetGameInstance()
{
    static GameInstance* instance = new GameInstance();
    return instance;
}

EventManager* GameInstance::GetEventManager()
{
    static std::unique_ptr<EventManager> event_manager = std::make_unique<EventManager>();
    return event_manager.get();
}

void GameInstance::Start()
{
    while (m_window_.isOpen())
    {
        sf::Event event;
        while (m_window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                m_window_.close();
            }
        }

        m_timer_ = m_clock_.getElapsedTime();

        if (!m_model_->GetIsGameover())
        {
            m_controller_->ReadPlayerInput(event, m_timer_, m_model_->GetGamefield(), m_model_->GetGamedata());

            if (m_timer_.asSeconds() > m_current_speed_)
            {
                Gamefield* gamefield = m_model_->GetGamefield();
                Figure*    current_figure = m_model_->GetCurrentFigure();
                assert(gamefield != nullptr);
                assert(current_figure != nullptr);

                const bool has_collision = current_figure->MoveDown(gamefield);

                if (has_collision)
                {
                    gamefield->PlaceFigure(current_figure);
                    int32_t removedLines = gamefield->RemoveLines();
                    m_model_->GenerateNextFigures();
                    m_model_->UpdateScore(removedLines);
                    m_view_->UpdateUIGamedata(m_model_->GetGamedata());
                    m_model_->CheckEndGame();
                    m_current_speed_ = m_model_->GetCurrentSpeed();
                }

                m_clock_.restart();
            }
        }

        m_view_->Render(m_window_);
    }
}
