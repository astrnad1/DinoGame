#ifndef START_H
#define START_H

#include <raylib.h>
#include "start_dino.cpp"

class Start {

private:
	Music music;
	const char* text = "Press SPACE to Start";
	Dino dino;
	float musicVolume = 0.15f;

public:
	Start() {
		music = LoadMusicStream("sounds/background_start.mp3");
		PlayMusicStream(music);
	}

	~Start()
	{
		UnloadMusicStream(music);
	}

	void Draw(const int windowWidth, const int windowHeight)
	{
		// Drawing the text
		const int fontSize = 20;
		int textWidth = MeasureText(text, fontSize);
		int xPos = (windowWidth - textWidth) / 2;
		int yPos = (windowHeight - fontSize) / 2 + 70;
		DrawText(text, xPos, yPos, 20, GRAY);

		// Drawing the Dino
		dino.draw_start_dino(windowWidth, windowHeight);
	}

	void Update()
	{
		SetMusicVolume(music, musicVolume);
		UpdateMusicStream(music);
	}
};

#endif