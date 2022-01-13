#pragma once

#include <vector>

#include "Position.h"
#include "Gamefield.h"

class Figure
{
public:
    Figure();
    Figure(const std::vector<std::vector<uint32_t>>& figure);

    std::vector<std::vector<uint32_t>>& GetFigure();
    void                                SetNewPosition(uint32_t new_row, uint32_t new_column);

    const std::vector<std::vector<uint32_t>>& GetFigure()          const;
    const Position&                           GetCurrentPosition() const;

public:
    const uint32_t number_rows    = 4;
    const uint32_t number_columns = 2;

private:
    std::vector<std::vector<uint32_t>> figure_;
    Position                           current_position_;
};
