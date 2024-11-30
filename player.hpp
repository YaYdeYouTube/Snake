#pragma once
#include "raylib.h"
#include <deque>

enum Direction;

class Player
{
public:
	Player();
	void Draw();
	void Update();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void GetLonger();
	void Init();
	Rectangle GetRect();
	std::deque<Vector2> body;
	bool active;
private:
	Direction direction;
	Vector2 headPosition;
	float delay;
	float time;
};