#pragma once
#include "Event.h"
#include "Delegate.h"
#include "../Model/GameModel.h"
#include "../Model/Gamedata.h"
#include "../View/GameView.h"

class EventManager
{
public:
    static EventManager* GetInstance();
    EventManager(EventManager&  other)                 = delete;
    EventManager(EventManager&& other)                 = delete;
    EventManager& operator=(const EventManager& other) = delete;
    EventManager& operator=(EventManager&& other)      = delete;
    
    int64_t SubscribeToUpdateGamedata(Delegate<GameView, Gamedata> delegate);
    int64_t SubscribeToGenerateNewFigures(Delegate<GameModel> delegate);

    void BroadcastUpdateGamedata(const Gamedata& updated_gamedata);
    void BroadcastGenerateNewFigres();
    
private:
    EventManager() = default;
    
    Event<GameView, Gamedata> m_onUpdateGamedata_;
    Event<GameModel>          m_OnGenerateNewFigure_;
};
