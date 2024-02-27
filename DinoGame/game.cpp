#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include "dino.cpp"

class Game {

private:
	Dino dino;

public:
	void Draw(const int windowWidth, const int windowHeight)
	{
		dino.draw_game_dino(windowWidth, windowHeight);
	}

	void Update()
	{
		//
	}
};

#endif