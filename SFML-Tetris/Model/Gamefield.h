#pragma once

#include <cstdint>
#include <vector>

class Gamefield
{
public:
    Gamefield();

    int32_t GetCell(size_t row_index, size_t column_index) const;

    void    PlaceFigure(const class Figure* figure);
    int32_t RemoveLines();

public:
    static const int32_t COLUMNS = 10;
    static const int32_t ROWS    = 20;
    
private:
    using Matrix_t = std::vector<std::vector<int32_t>>;
    Matrix_t field_;
};
