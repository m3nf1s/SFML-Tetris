#include <SFML/Graphics.hpp>
#include <string>
#include <cstdint>
#include <iostream>
#include <functional>

#include "GameInstance.h"

int main()
{
	GameInstance::instance().Start();

	return 0;
}
