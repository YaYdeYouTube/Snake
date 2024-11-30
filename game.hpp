#pragma once
#include "food.hpp"
#include "player.hpp"

class Game
{
public:
	Game();
	void Draw();
	void Update();
	void HandleInput();
	void CheckForCollision();
	void Init();
	bool run;
	int score;
private:
	Food food;
	Player player;
};