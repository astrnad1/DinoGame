#ifndef DINO_H
#define DINO_H

#include <raylib.h>

class Dino {

private:
	const unsigned int app_count = 2; // Appearance count
	Image imgApp[2];
	Texture texApp[2];
	float timer = 1.0f;
	int cur_app_count = 0; // Current Dino appearance count

public:
	Dino() {
		// Figure images
		imgApp[0] = LoadImage("images/dino0.png");
		imgApp[1] = LoadImage("images/dino1.png");
		// Figure textures
		texApp[0] = LoadTextureFromImage(imgApp[0]);
		texApp[1] = LoadTextureFromImage(imgApp[1]);
	}

	~Dino()
	{
		for (unsigned int i = 0; i < app_count; i++)
		{
			UnloadImage(imgApp[i]);
			UnloadTexture(texApp[i]);
		}
	}

	void draw_start_dino(const int windowWidth, const int windowHeight)
	{
		timer -= GetFrameTime();

		if (timer <= 0)
		{
			cur_app_count = (cur_app_count < app_count - 1) ? ++cur_app_count : 0;
			timer = 1.0f;
		}

		int xPos = (windowWidth - texApp[0].width) / 2;
		int yPos = (windowHeight - texApp[0].height) / 2;
		DrawTexture(texApp[cur_app_count], xPos, yPos, WHITE);
	}

	void draw_game_dino(const int windowWidth, const int windowHeight)
	{
		int xPos = 100;
		int yPos = windowHeight - 200;
		DrawTexture(texApp[1], xPos, yPos, WHITE);
	}
};

#endif