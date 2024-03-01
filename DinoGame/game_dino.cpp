#ifndef GAME_DINO_H
#define GAME_DINO_H

#include <raylib.h>

class GameDino
{

private:
	const int app_count = 1;
	Texture2D texture[1];
	Vector2 position;
	float speed = 5.0f;
	bool isJumping;
	float scaleFactor = 0.8f;
	float jumpSpeed = 10.0f;
	float gravity = 0.5f;

public:
	GameDino()
	{
		texture[0] = LoadTexture("images/dino1.png");
		position = { 100, 300 }; // Start position
		isJumping = false;
	}

	~GameDino()
	{
		for (int i = 0; i < app_count; i++)
		{
			UnloadTexture(texture[i]);
		}
	}

	void Draw(const int windowWidth, const int windowHeight)
	{
		DrawTextureEx(texture[0], position, 0.0f, scaleFactor, WHITE);
	}

	void Update()
	{
		if (isJumping)
		{
			position.y -= jumpSpeed;
			jumpSpeed -= gravity;

			if (position.y >= 300.0f)
			{
				position.y = 300.0f;
				isJumping = false;
				jumpSpeed = 10.0f;
			}
		}
		else {
			if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
				isJumping = true;
		}
	}
};

#endif