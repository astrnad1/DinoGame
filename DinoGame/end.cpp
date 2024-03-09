#ifndef END_H
#define END_H

#include <raylib.h>

class EndScreen 
{
public:

	void Draw(const int windowWidth, const int windowHeight)
	{
		DrawText("Game Over", windowWidth / 2 - 100, windowHeight / 2 - 20, 40, RED);
		DrawText("Press SPACE to restart", windowWidth / 2 - 130, windowHeight / 2 + 40, 20, GRAY);
	}
};

#endif