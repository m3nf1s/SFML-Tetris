#pragma once

#include <cstdint>

#include "Gamefield.h"
#include "Figure.h"

struct Gamedata
{
    explicit Gamedata(const Gamefield* new_gamefield,
        const Figure* new_current_figure, const Figure* new_next_figure,
        const int32_t new_current_level, const int32_t new_current_score);

    const Gamefield* gamefield;
    const Figure*    current_figure;
    const Figure*    next_figure;

    int32_t    current_level;
    int32_t    current_score;
};