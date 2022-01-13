#include "GameModel.h"

Gamefield& GameModel::GetGamefield()
{
    return gamefield_;
}

const Gamefield& GameModel::GetGamefield() const
{
    return gamefield_;
}
