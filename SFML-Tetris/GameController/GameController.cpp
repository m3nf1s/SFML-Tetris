#include "GameController.h"

#include <cassert>

#include "../GameInstance.h"
#include "../EventSystem/EventManager.h"

void GameController::ReadPlayerInput(const sf::Event& event, sf::Time& timer, const Gamefield* gamefield, const Gamedata& gamedata)
{
    EventManager* ptrEventManager = GameInstance::GetEventManager();

    assert(ptrEventManager != nullptr);

    if (event.type == sf::Event::KeyPressed)
    {
        const float magic_number_accelerate = 50.0f;

        switch (event.key.code)
        {
#ifdef _DEBUG
        case sf::Keyboard::LAlt:
            GameInstance::GetEventManager()->BroadcastGameModelGenerateNewFigures();
            GameInstance::GetEventManager()->BroadcastGameViewUpdateGamedata(gamedata);
            break;
#endif
        case sf::Keyboard::Left:
            GameInstance::GetEventManager()->BroadcastFigureMoveLeft(gamefield);
            break;

        case sf::Keyboard::Right:
            GameInstance::GetEventManager()->BroadcastFigureMoveRight(gamefield);
            break;

        case sf::Keyboard::Up:
            GameInstance::GetEventManager()->BroadcastFigureRotate(gamefield);
            break;

        case sf::Keyboard::Down:
            timer *= timer.asSeconds() * magic_number_accelerate;
            break;

        default:
            break;
        }
    }
}
