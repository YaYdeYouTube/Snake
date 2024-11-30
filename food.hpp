#pragma once
#include "raylib.h"

class Food
{
public:
	Food();
	void Draw();
	void Update();
	void Spawn();
	void Init();
	Rectangle GetRect();
	bool active;
private:
	Vector2 position;
};