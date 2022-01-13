#include "Figure.h"

Figure::Figure()
    : figure_(std::vector<std::vector<uint32_t>>(number_rows, std::vector<uint32_t>(number_columns)))
{
}

Figure::Figure(const std::vector<std::vector<uint32_t>>& figure)
    : figure_(figure)
{
}

std::vector<std::vector<uint32_t>>& Figure::GetFigure()
{
    return figure_;
}

void Figure::SetNewPosition(uint32_t new_row, uint32_t new_column)
{
    current_position_.row    = new_row;
    current_position_.column = new_column;
}

const std::vector<std::vector<uint32_t>>& Figure::GetFigure() const
{
    return figure_;
}

const Position& Figure::GetCurrentPosition() const
{
    return current_position_;
}

