#include "food.hpp"

Food::Food()
{
	Init();
}

void Food::Draw()
{
	DrawRectangleRounded({ position.x, position.y, 15, 15 }, 8, 8, WHITE);
}

void Food::Update()
{
	if (active == false)
	{
		Spawn();
		active = true;
	}
}

void Food::Spawn()
{
	position = {float(GetRandomValue(0, 38) * 15 + 30), float(GetRandomValue(0, 37) * 15 + 30) };
}

void Food::Init()
{
	active = true;
	Spawn();
}

Rectangle Food::GetRect()
{
	return { position.x, position.y, 30, 30 };
}
