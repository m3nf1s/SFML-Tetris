#include "Gamefield.h"
#include "Figure.h"

Gamefield::Gamefield()
    : field_(std::vector<std::vector<int32_t>>(ROWS, std::vector<int32_t>(COLUMNS, 0)))
{
}

const int32_t Gamefield::GetCell(size_t row_index, size_t column_index) const
{
    return field_.at(row_index).at(column_index);
}

void Gamefield::SetFigure(const Figure* figure)
{
    const int32_t figure_cur_pos_Y = figure->GetCurrentPosition().Y;
    const int32_t figure_cur_pos_X = figure->GetCurrentPosition().X;
    const int32_t figure_size      = figure->GetSize();
    
    for (int32_t i = 0; i < figure_size; ++i)
    {
        for (int32_t j = 0; j < figure_size; ++j)
        {
            if (figure->Get(i, j) != 0)
            {
                field_.at(i + figure_cur_pos_Y).at(j + figure_cur_pos_X) = figure->Get(i, j);
            }
        }
    }
}