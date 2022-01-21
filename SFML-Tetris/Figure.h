#pragma once

#include <vector>
#include "Position.h"

using T_Matrix = std::vector<std::vector<int32_t>>;

class Figure
{
public:
    Figure();
    Figure(const T_Matrix& figure);

    void SetNewPosition(const int32_t new_x, const int32_t new_y);

    void MoveLeft(const class Gamefield& gamefield);
    void MoveRight(const class Gamefield& gamefield);
    void Rotate(const class Gamefield& gamefield);
    bool MoveDown(const class Gamefield& gamefield);

    int32_t& Get(const int32_t row_index, const int32_t column_index);

    const int32_t   Get(const int32_t row_index, const int32_t column_index) const;
    const int32_t   GetSize()                                                const;
    const Position& GetCurrentPosition()                                     const;

private:
    bool HasCollisionGamefield(const class Gamefield& gamefield);
    bool HasCollisionLeftWall();
    bool HasCollisionRightWall();

private:
    T_Matrix   figure_;
    Position   current_position_;
};
