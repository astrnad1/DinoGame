#ifndef METEOR_H
#define METEOR_H

#include <raylib.h>

class Meteor {

private:	
	Texture2D texture;
	Vector2 position;
	float scaleFactor = 0.3f;
	float speed = 5.0f;
	float meteorWidth;
	float meteorHeight;

public:
	Meteor()
	{
		texture = LoadTexture("images/meteor.png");
		position = { 800, 330 };

		// Need that for the collisions
		meteorWidth = ((float)texture.width) * scaleFactor;
		meteorHeight = ((float)texture.height) * scaleFactor;
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

	Rectangle GetBoundingBox() const
	{
		return { position.x, position.y, meteorWidth, meteorHeight };
	}

	void ResetPos()
	{
		position = { 800, 330 };
	}
};

#endif