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
    for (int32_t i = 0;i < figure->GetSize(); ++ i)
    {
        for (int32_t j = 0; j < figure->GetSize(); ++j)
        {
            if (figure->Get(i, j) != 0)
            {
                field_.at(i + figure->GetCurrentPosition().Y).at(j + figure->GetCurrentPosition().X) = figure->Get(i, j);
            }
        }
    }
}