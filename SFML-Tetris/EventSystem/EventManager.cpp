#include "EventManager.h"
int64_t EventManager::SubscribeGameViewUpdateGamedata(const Delegate<GameView, const Gamedata&>& delegate)
{
    return m_onUpdateGamedata_.Subscribe(delegate);    
}

void EventManager::BroadcastGameViewUpdateGamedata(const Gamedata& updated_gamedata)
{
    m_onUpdateGamedata_.Broadcast(updated_gamedata);
}

void EventManager::UnsubscribeGameViewUpdateGamedata(const int64_t bucket_index)
{
    m_onUpdateGamedata_.Unsubscribe(bucket_index);
}

int64_t EventManager::SubscribeGameModelGenerateNewFigures(const Delegate<GameModel>& delegate)
{
    return m_onGenerateNewFigures_.Subscribe(delegate);
}

void EventManager::BroadcastGameModelGenerateNewFigures()
{
    m_onGenerateNewFigures_.Broadcast();
}

void EventManager::UnsubscribeGameModelGenerateNewFigures(const int64_t bucket_index)
{
    m_onGenerateNewFigures_.Unsubscribe(bucket_index);
}

int64_t EventManager::SubscribeFigureMoveLeft(const Delegate<Figure, const Gamefield*>& delegate)
{
    return m_onFigureMoveLeft_.Subscribe(delegate);
}

void EventManager::BroadcastFigureMoveLeft(const Gamefield* gamefield)
{
    m_onFigureMoveLeft_.Broadcast(gamefield);
}

void EventManager::UnsubscribeFigureMoveLeft(const int64_t bucket_index)
{
    m_onFigureMoveLeft_.Unsubscribe(bucket_index);
}

int64_t EventManager::SubscribeFigureMoveRight(const Delegate<Figure, const Gamefield*>& delegate)
{
    return m_onFigureMoveRight_.Subscribe(delegate);
}

void EventManager::BroadcastFigureMoveRight(const Gamefield* gamefield)
{
    m_onFigureMoveRight_.Broadcast(gamefield);
}

void EventManager::UnsubscribeFigureMoveRight(const int64_t bucket_index)
{
    m_onFigureMoveRight_.Unsubscribe(bucket_index);
}

int64_t EventManager::SubscribeFigureMoveDown(const Delegate<Figure, const Gamefield*>& delegate)
{
    return m_onFigureMoveDown_.Subscribe(delegate);
}

void EventManager::BroadcastFigureMoveDown(Gamefield* gamefield)
{
    m_onFigureMoveDown_.Broadcast(gamefield);
}

void EventManager::UnsubscribeFigureMoveDown(const int64_t bucket_index)
{
    m_onFigureMoveDown_.Unsubscribe(bucket_index);
}

int64_t EventManager::SubscribeFigureRotate(const Delegate<Figure, const Gamefield*>& delegate)
{
    return m_onFigureRotate_.Subscribe(delegate);
}

void EventManager::BroadcastFigureRotate(const Gamefield* gamefield)
{
    m_onFigureRotate_.Broadcast(gamefield);
}

void EventManager::UnsubscribeFigureRotate(const int64_t bucket_index)
{
    m_onFigureRotate_.Unsubscribe(bucket_index);
}







