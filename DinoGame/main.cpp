#include <raylib.h>
#include "controller.cpp"

using namespace std;

int main()
{
	// Score na end screen ne dela!!

	const int windowWidth = 1000;
	const int windowHeight = 500;
	const int FPS = 60;

	InitWindow(windowWidth, windowHeight, "Dino game");
	InitAudioDevice();

	SetTargetFPS(FPS);

	Controller controller;

	while (!WindowShouldClose())
	{
		controller.Update();
		BeginDrawing();
		ClearBackground(RAYWHITE);
		controller.Draw(windowWidth, windowHeight);
		EndDrawing();
	}

	CloseWindow();
	CloseAudioDevice();

	return 0;
}