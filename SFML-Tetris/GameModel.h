#pragma once

#include "Gamefield.h"

class GameModel
{
public:
    Gamefield& GetGamefield();

    const Gamefield& GetGamefield() const;

private:
    Gamefield gamefield_;
};

