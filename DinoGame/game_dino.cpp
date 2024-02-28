#include <raylib.h>

class GameDino
{

private:
	const int app_count = 1;
	Image imgApp[1];
	Texture texApp[1];

public:
	GameDino()
	{
		imgApp[0] = LoadImage("images/dino1.png");
		texApp[0] = LoadTextureFromImage(imgApp[0]);
	}

	~GameDino()
	{
		for (int i = 0; i < app_count; i++)
		{
			UnloadImage(imgApp[i]);
			UnloadTexture(texApp[i]);
		}
	}

	void Draw(const int windowWidth, const int windowHeight)
	{
		int xPos = 100;
		int yPos = windowHeight - 200;
		DrawTexture(texApp[0], xPos, yPos, WHITE);
	}

};
