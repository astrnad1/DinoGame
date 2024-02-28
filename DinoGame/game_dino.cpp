#ifndef GAME_DINO_H
#define GAME_DINO_H

#include <raylib.h>

class GameDino
{

private:
	const int app_count = 1;
	Texture2D texApp[1];
	Vector2 position;
	float speed = 5.0f;

public:
	GameDino()
	{
		texApp[0] = LoadTexture("images/dino1.png");
		position = { 100, 300 }; // Start position
	}

	~GameDino()
	{
		for (int i = 0; i < app_count; i++)
		{
			UnloadTexture(texApp[i]);
		}
	}

	void Draw(const int windowWidth, const int windowHeight/*, float speed*/)
	{
		DrawTexture(texApp[0], position.x, position.y, WHITE);
	}

	void Update()
	{
		if (IsKeyDown(KEY_D))
			position.x += speed;
		if (IsKeyDown(KEY_A))
			position.x -= speed;
		if (IsKeyDown(KEY_S))
			position.y += speed;
		if (IsKeyDown(KEY_W))
			position.y -= speed;
	}
};

#endif