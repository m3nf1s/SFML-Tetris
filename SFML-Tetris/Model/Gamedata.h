#pragma once

#include <cstdint>

#include "Gamefield.h"
#include "Figure.h"

struct Gamedata
{
    const Gamefield* gamefield;
    const Figure*    current_figure;
    const Figure*    next_figure;

    size_t current_level;
    size_t current_score;
};