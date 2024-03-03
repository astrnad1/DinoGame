#ifndef GAME_H
#define GAME_H

#include "game_dino.cpp"
#include "meteor.cpp"
#include <iostream>

class Game {

private:
	GameDino dino;
	Meteor meteor;
	Rectangle dinoBox;
	Rectangle meteorBox;

	bool CheckCollision()
	{
		dinoBox = dino.GetBoundingBox();
		meteorBox = meteor.GetBoundingBox();

		// Collisions boxes
		//DrawRectangleLines(dinoBox.x, dinoBox.y, dinoBox.width, dinoBox.height, GREEN);
		//DrawRectangleLines(meteorBox.x, meteorBox.y, meteorBox.width, meteorBox.height, RED);

		if (CheckCollisionRecs(dinoBox, meteorBox))
		{
			return true;
		}

		return false;
	}

public:
	void Draw(const int windowWidth, const int windowHeight)
	{
		dino.Draw(windowWidth, windowHeight);
		meteor.Draw(windowWidth, windowHeight);
	}

	void Update()
	{
		dino.Update();
		meteor.Update();

		if (CheckCollision())
		{
			std::cout << "Collision!" << std::endl;
		}
	}
};

#endif