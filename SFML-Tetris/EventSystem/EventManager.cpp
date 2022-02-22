#include "EventManager.h"

EventManager* EventManager::GetInstance()
{
    static EventManager* event_manager = new EventManager();
    return event_manager;
}

int64_t EventManager::SubscribeToUpdateGamedata(Delegate<GameView, Gamedata> delegate)
{
    return m_onUpdateGamedata_.Subscribe(delegate);    
}

int64_t EventManager::SubscribeToGenerateNewFigures(Delegate<GameModel> delegate)
{
    return m_OnGenerateNewFigure_.Subscribe(delegate);
}

void EventManager::BroadcastUpdateGamedata(const Gamedata& updated_gamedata)
{
    m_onUpdateGamedata_.Broadcast(updated_gamedata);
}

void EventManager::BroadcastGenerateNewFigres()
{
    m_OnGenerateNewFigure_.Broadcast();
}
