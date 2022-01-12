#pragma once

#include <memory>

#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"

class GameInstance
{
public:
	static GameInstance& instance();

	void Start();

	GameInstance(GameInstance& other)           = delete;
	GameInstance& operator=(GameInstance other) = delete;

private:
	GameInstance() = default;

	void Initialization();

	std::unique_ptr<GameModel>      model_;
	std::unique_ptr<GameView>       view_;
	std::unique_ptr<GameController> controller_;
};

