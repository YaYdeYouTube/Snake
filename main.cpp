#include "raylib.h"
#include "game.hpp"
#include <string>

int sellSize = 15;
int sellCount = 40;

int main()
{
	InitWindow(sellSize*sellCount + 60, sellSize*sellCount + 60, "Snake");
	SetTargetFPS(60);

	Font font = LoadFont("Font\monogram.ttf");
	Game game;

	while (!WindowShouldClose())
	{
		game.Update();

		BeginDrawing();

		ClearBackground(BLACK);
		DrawRectangleLines(30, 30, 600, 600, WHITE);

		if (game.run)
		{
			std::string scoretext = "SCORE : " + std::to_string(game.score);
			DrawTextEx(font, scoretext.c_str(), { 30, 10 }, 20, 2, WHITE);
		}
		else {
			DrawTextEx(font, "GAME OVER ! TAP ENTER TO RESTART", {30, 10}, 20, 2, WHITE);
		}

		game.Draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}