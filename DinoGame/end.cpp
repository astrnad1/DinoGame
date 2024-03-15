#ifndef END_H
#define END_H

#include <raylib.h>
#include <iostream>
#include <string>
#include "game.cpp"

class EndScreen 
{
private:
	Game game;

public:

	void Draw(const int windowWidth, const int windowHeight, float score)
	{
		DrawText("Game Over", windowWidth / 2 - 100, windowHeight / 2 - 60, 40, RED);
		DrawText("Press SPACE to restart", windowWidth / 2 - 130, windowHeight / 2 + 20, 20, GRAY);
		DrawText(("Your score was: " + std::to_string((int)score)).c_str(), windowWidth / 2 - 90, windowHeight / 2 + 60, 20, GRAY);
	}
};

#endif