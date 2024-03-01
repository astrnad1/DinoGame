#ifndef METEOR_H
#define METEOR_H

#include <raylib.h>

class Meteor {

private:	
	Texture2D texture;
	Vector2 position;
	float scaleFactor = 0.3f;
	float speed = 5.0f;

public:
	Meteor()
	{
		texture = LoadTexture("images/meteor.png");
		position = { 800, 300 };
	}

	~Meteor()
	{
		UnloadTexture(texture);
	}

	void Draw(const int windowWidth, const int windowHeight)
	{
		DrawTextureEx(texture, position, 0.0f, scaleFactor, WHITE);
	}

	void Update()
	{
		if (position.x < -100)
			position.x = 1050;
		else
			position.x -= speed;

	}
};

#endif