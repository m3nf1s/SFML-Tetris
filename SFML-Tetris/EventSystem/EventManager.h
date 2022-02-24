#pragma once

#include "Event.h"
#include "Delegate.h"
#include "../Model/GameModel.h"
#include "../Model/Gamedata.h"
#include "../View/GameView.h"

class EventManager
{
public:
    EventManager() = default;
    ~EventManager() = default;
    
    int64_t SubscribeGameViewUpdateGamedata(const Delegate<GameView, const Gamedata&>& delegate);
    void    BroadcastGameViewUpdateGamedata(const Gamedata& updated_gamedata);
    void    UnsubscribeGameViewUpdateGamedata(const int64_t bucket_index);

    int64_t SubscribeGameModelGenerateNewFigures(const Delegate<GameModel>& delegate);
    void    BroadcastGameModelGenerateNewFigures();
    void    UnsubscribeGameModelGenerateNewFigures(const int64_t bucket_index);

    int64_t SubscribeFigureMoveLeft(const Delegate<Figure, const Gamefield*>& delegate);
    void    BroadcastFigureMoveLeft(const Gamefield* gamefield);
    void    UnsubscribeFigureMoveLeft(const int64_t bucket_index);

    int64_t SubscribeFigureMoveRight(const Delegate<Figure, const Gamefield*>& delegate);
    void    BroadcastFigureMoveRight(const Gamefield* gamefield);
    void    UnsubscribeFigureMoveRight(const int64_t bucket_index);

    int64_t SubscribeFigureMoveDown(const Delegate<Figure, const Gamefield*>& delegate);
    void    BroadcastFigureMoveDown(Gamefield* gamefield);
    void    UnsubscribeFigureMoveDown(const int64_t bucket_index);

    int64_t SubscribeFigureRotate(const Delegate<Figure, const Gamefield*>& delegate);
    void    BroadcastFigureRotate(const Gamefield* gamefield);
    void    UnsubscribeFigureRotate(const int64_t bucket_index);
    
private:


    Event<GameView, const Gamedata&> m_onUpdateGamedata_;
    Event<GameModel>                 m_onGenerateNewFigures_;
    Event<Figure, const Gamefield*>  m_onFigureMoveLeft_;
    Event<Figure, const Gamefield*>  m_onFigureMoveRight_;
    Event<Figure, const Gamefield*>  m_onFigureMoveDown_;
    Event<Figure, const Gamefield*>  m_onFigureRotate_;
};
