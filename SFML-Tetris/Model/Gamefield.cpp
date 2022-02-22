#include "Gamefield.h"
#include "Figure.h"

Gamefield::Gamefield()
    : field_(std::vector<std::vector<int32_t>>(ROWS, std::vector<int32_t>(COLUMNS, 0)))
{
}

int32_t Gamefield::GetCell(const size_t row_index, const size_t column_index) const
{
    return field_.at(row_index).at(column_index);
}

void Gamefield::PlaceFigure(const Figure* figure)
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

int32_t Gamefield::RemoveLines()
{
    int32_t removed = 0;

    for (int32_t i = ROWS - 1; i > 0; --i)
    {
        bool is_delete = true;
        for (int32_t j = 0; j < COLUMNS; ++j)
        {
            if (field_.at(i).at(j) == 0)
            {
                is_delete = false;
                break;
            }
        }

        if (is_delete)
        {
            ++removed;
            for (int32_t y = i; y > 0; --y)
            {
                for (int32_t x = 0; x < COLUMNS; ++x)
                {
                    field_.at(y).at(x) = field_.at(y - 1).at(x);
                }
            }
            ++i;
        }
    }

    return removed;
}