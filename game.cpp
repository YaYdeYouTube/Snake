#include "game.hpp"

Game::Game()
{
	Init();
}

void Game::Draw()
{
	food.Draw();
	player.Draw();
}

void Game::Update()
{
	if (!player.active)
		run = false;

	if (run)
	{
		food.Update();
		player.Update();

		HandleInput();
		CheckForCollision();
	}
	else {
		if (IsKeyDown(KEY_ENTER))
		{
			player.Init();
			food.Init();
			Init();
		}
	}
}

void Game::HandleInput()
{
	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
	{
		player.MoveUp();
	}
	else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
	{
		player.MoveDown();
	}
	else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
	{
		player.MoveLeft();
	}
	else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
	{
		player.MoveRight();
	}
}

void Game::CheckForCollision()
{
	if (CheckCollisionRecs(player.GetRect(), food.GetRect()))
	{
		food.active = false;
		player.GetLonger();
		score += 1;
	}
}

void Game::Init()
{
	score = 0;
	run = true;
}
