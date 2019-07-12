#include "ComputerInput.h"


CComputerInput::CComputerInput(float posX_init, float posY_init) {

	startX = posX_init;
	startY = posY_init;
	posX = startX;
	posY = startY;
	curVel = BASE_VELOCITY;
}


CComputerInput::~CComputerInput() { }


void CComputerInput::move() {

	posX += curVel;

	if (posX > (startX + MAX_MOVEMENT))
	{
		curVel = -curVel;
		posY = posY + 10.f;
		dir = LEFT;
	}
	else if (posX < (startX - MAX_MOVEMENT))
	{
		curVel = -curVel;
		posY = posY + 10.f;
		dir = RIGHT;
	}
}

