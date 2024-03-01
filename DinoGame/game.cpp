#ifndef GAME_H
#define GAME_H

#include "game_dino.cpp"
#include "meteor.cpp"

class Game {

private:
	GameDino dino;
	Meteor meteor;

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
	}
};

#endif