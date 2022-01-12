#pragma once

class GameInstance
{
public:
	static GameInstance& instance();

	static void Start();

	GameInstance(GameInstance& other) = delete;
	GameInstance& operator=(GameInstance other) = delete;

private:
	GameInstance() = default;
};

