#ifndef GAME_DINO_H
#define GAME_DINO_H

#include <raylib.h>

class GameDino
{

private:
	const int app_count = 1;
	Texture2D texApp[1];

public:
	GameDino()
	{
		texApp[0] = LoadTexture("images/dino1.png");
	}

	~GameDino()
	{
		for (int i = 0; i < app_count; i++)
		{
			UnloadTexture(texApp[i]);
		}
	}

	void Update()
	{

	}

	void Draw(const int windowWidth, const int windowHeight/*, float speed*/)
	{
		int xPos = 100;
		int yPos = windowHeight - 200;
		DrawTexture(texApp[0], xPos, yPos, WHITE);
	}

};

#endif