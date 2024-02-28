#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include "game_dino.cpp"

class Game {

private:
	GameDino dino;
	float speed = 5.0f;

public:
	void Draw(const int windowWidth, const int windowHeight)
	{
		dino.Draw(windowWidth, windowHeight);
	}

	void Update()
	{
		dino.Update();
	}
};

#endif