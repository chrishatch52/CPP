#pragma once
#include "Input.h"

class CComputerInput :
	public I_Input
{
public:

	CComputerInput() = default;
	explicit CComputerInput(float posX, float posY);
	~CComputerInput();

	CComputerInput(const CComputerInput& objMan) = delete;//copy
	CComputerInput& operator=(const CComputerInput& objMan) = delete;//assignment

	CComputerInput(CComputerInput&& other) = delete;//move constructor

	//starts enemy animation
	virtual void move();

	//get location
	inline float getPosX() { return posX; }
	inline float getPosY() { return posY; }

	//set location data init
	inline void setInitPos(float posX_init, float posY_init) { posX = posX_init; posY = posY_init; }
	
	//set location data new level
	inline void setNewPosY() { startY += 15.f; posY = startY; }
	inline void setVelo(int level) { curVel = float(BASE_VELOCITY * level); }
	inline void resetX() { posX = startX; }

private:
	//Velocity values
	constexpr static float BASE_VELOCITY = 0.008f;
	float curVel;
	
	//Positional values
	constexpr static float MAX_MOVEMENT = 100.f;
	float posX;
	float posY;
	float startX;
	float startY;
};

