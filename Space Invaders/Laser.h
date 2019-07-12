#pragma once
#include "SDL.h"
#include "Graphics.h"
#include "Entity.h"

class CLaser : public AEntity
{
public:
	enum LaserDirection {
		LASER_UP = 0,
		LASER_DOWN,
		LASER_45R,
		LASER_45L
	};

public:

	CLaser(float posX_init, float posY_init, Graphics* graphic);
	~CLaser();

	//update CLaser position
	void update();

	//Shows the CLaser on the screen
	void render();

	void setDirection(int direction);

	inline LaserDirection getDirection() { return direction; }

private:

	//Characteristics
	constexpr static int height = 20;
	constexpr static int width = 5;
	constexpr static float velocity = 0.05f;
	LaserDirection direction;

	//Current position
	float laserX;
	float laserY;

	//texture
	Graphics* laserGraphic;
};

