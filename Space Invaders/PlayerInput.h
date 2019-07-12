#pragma once
#include "Input.h"
#include "InputState.h"
#include "SDL.h"
/**
 * Filename: Input
 * Author: Chris Hatch
 * Created: 10/13/2017
 * Revision: 3
 * Rev. Date: 10/24/2017
 * Rev. Author: Chris Hatch
 * */

class CPlayerInput :
	public I_Input
{
public:

	CPlayerInput() = default;
	explicit CPlayerInput(float posX_init, float posY_init);
	~CPlayerInput() = default;

	CPlayerInput(const CPlayerInput& objMan) = delete;//copy
	CPlayerInput& operator=(const CPlayerInput& objMan) = delete;//assignment

	CPlayerInput(CPlayerInput&& other) = delete;//move constructor

	//Handles CActor Events (key press)
	void handleEvent(SDL_Event& e);

	//Moves the CActor 
	void move();

	//get location
	inline float getPosX() { return posX; }
	inline float getPosY() { return posY; }

	inline CInputState::State getPlayerInputState() { return playerInputState.getState(); }
	inline void setPlayerInputState(CInputState::State newState) { playerInputState.setState(newState); }
private:
	CInputState playerInputState;
	//Minimum axis velocity of the Player
	constexpr static float minVel = -.1f;
	//Maximum axis velocity of the Player
	constexpr static float maxVel = .1f;
	//Current X,Y of player for collision detection
	float posX, posY;
	//Current Velocity
	float velX;
	
	//Bounds
	constexpr static float LEFT_BOUND = 65.f;
	constexpr static float RIGHT_BOUND = 925.f;
};

