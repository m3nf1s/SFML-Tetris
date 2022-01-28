#pragma once

#include <vector>
#include "Position.h"



class Figure
{
    using Matrix_t = std::vector<std::vector<int32_t>>;

public:
    Figure();
    Figure(const Matrix_t& figure);

    void SetNewPosition(const int32_t new_x, const int32_t new_y);

    void MoveLeft(const class Gamefield* gamefield);
    void MoveRight(const class Gamefield* gamefield);
    void Rotate(const class Gamefield* gamefield);
    bool MoveDown(const class Gamefield* gamefield);

    int32_t& Get(const int32_t row_index, const int32_t column_index);

    const int32_t   Get(const int32_t row_index, const int32_t column_index) const;
    const int32_t   GetSize()                                                const;
    const Position& GetCurrentPosition()                                     const;

private:
    bool HasCollisionGamefield(const class Gamefield* gamefield);
    bool HasCollisionLeftWall();
    bool HasCollisionRightWall();

private:
    Matrix_t   figure_;
    Position   current_position_;
};
