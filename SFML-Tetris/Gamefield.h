#pragma once

#include <cstdint>
#include <vector>

//using Matrix = std::vector<std::vector<int32_t>>;
typedef std::vector<std::vector<int32_t>> Matrix;

class Gamefield
{
public:
    Gamefield();
    
    const int32_t GetCell(size_t row_index, size_t column_index) const;
    void SetFigure(const class Figure* figure);

public:
    static const int32_t COLUMNS = 10;
    static const int32_t ROWS    = 20;

private:
    Matrix field_;
};

