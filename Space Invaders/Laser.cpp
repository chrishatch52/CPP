#include "stdafx.h"
#include "Laser.h"


CLaser::CLaser(float posX_init, float posY_init, Graphics *graphic) :
	laserGraphic(graphic),
	laserX(posX_init),
	laserY(posY_init){

	setEntityRect(int(posX_init), int(posY_init), graphic->getWidth(), graphic->getHeight());
}


CLaser::~CLaser() { }


void CLaser::update() {

	//update laser position based on speed of laser
	if (direction == LASER_UP && laserY > 100.f)
	{
		laserY -= velocity;
	}
	else if (direction == LASER_DOWN 
		&& (laserY + getEntityRect().h) < 950.f)
	{
		laserY += velocity;
	}
	else
	{
		deactivate();
	}
	updateSDLrect(laserX, laserY);
}

void CLaser::render() {

	if (laserGraphic != nullptr)
		laserGraphic->render(getEntityRect().x, getEntityRect().y);
}

void CLaser::setDirection(int dir) {

	switch (dir)
	{
		case 0:
			direction = LASER_UP;
			break;
		case 1:
			direction = LASER_DOWN;
			break;
	}
	activate();
}
