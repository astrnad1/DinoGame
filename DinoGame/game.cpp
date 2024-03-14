#ifndef GAME_H
#define GAME_H

#include "game_objects.cpp"
#include <iostream>
#include <string>

class Game {

private:
	Rectangle dinoBox;
	Rectangle meteorBox;

public:
	GameDino dino;
	Meteor meteor;
	float score = 0;

	bool CheckCollision()
	{
		dinoBox = dino.GetBoundingBox();
		meteorBox = meteor.GetBoundingBox();

		// Collisions boxes
		//DrawRectangleLines(dinoBox.x, dinoBox.y, dinoBox.width, dinoBox.height, GREEN);
		//DrawRectangleLines(meteorBox.x, meteorBox.y, meteorBox.width, meteorBox.height, RED);

		if (CheckCollisionRecs(dinoBox, meteorBox))
		{
			dino.ResetPos();
			meteor.ResetPos();
			return true;
		}
		else {
			score += 0.5f;
		}

		return false;
	}

	void Draw(const int windowWidth, const int windowHeight)
	{
		dino.Draw(windowWidth, windowHeight);
		meteor.Draw(windowWidth, windowHeight);
		DrawText(("SCORE: " + std::to_string((int)score)).c_str(), 800, 50, 20, GRAY);
	}

	void Update()
	{
		dino.Update();
		meteor.Update();
	}
};

#endif