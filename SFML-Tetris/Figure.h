#pragma once

#include <array>
#include <cstdint>

class IFigure
{
public:
	virtual const std::array<std::array<int32_t, 4>, 4>& GetFigure() const = 0;
protected:
	const std::array<std::array<int32_t, 4>, 4> _figure;
};

