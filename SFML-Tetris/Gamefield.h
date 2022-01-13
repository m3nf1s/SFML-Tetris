#pragma once

#include <cstdint>
#include <vector>

class Gamefield
{
public:
    Gamefield();

    std::vector<std::vector<uint32_t>>& GetField();
    
    const std::vector<std::vector<uint32_t>>& GetField() const;

public:
    const uint32_t COLUMNS = 10;
    const uint32_t ROWS    = 20;

private:
    std::vector<std::vector<uint32_t>> field_;
};

