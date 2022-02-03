#include "Gamedata.h"

Gamedata::Gamedata(const Gamefield* new_gamefield,
    const Figure* new_current_figure, const Figure* new_next_figure,
    const int32_t new_current_level, const int32_t new_current_score)
    : gamefield      (new_gamefield)   
    , current_figure (new_current_figure)
    , next_figure    (new_next_figure)
    , current_level  (new_current_level)
    , current_score  (new_current_score)
{
}