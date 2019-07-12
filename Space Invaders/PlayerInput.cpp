#include "stdafx.h"
#include "PlayerInput.h"

CPlayerInput::CPlayerInput(float posX_init, float posY_init)
{
	posX = posX_init;
	posY = posY_init;
	velX = 0.f;
}


void CPlayerInput::move() {

	//Move the player left or right
	posX += velX;

	//If the player went too far to the left or right 
	if (posX < LEFT_BOUND)
	{
		posX = LEFT_BOUND;
	}
	else if (posX > RIGHT_BOUND)
	{
		posX = (float)(RIGHT_BOUND);
	}


}


void CPlayerInput::handleEvent(SDL_Event & e) {

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//process input
		switch (e.key.keysym.sym)
		{
			case SDLK_SPACE: 
				playerInputState.setState(CInputState::ATTACK);
				break;
			/**case SDLK_UP: 
				//setInputState(CInputState::SPECIAL_ATK); 
				break;*/
			/**case SDLK_DOWN: 
				//setInputState(CInputState::SPECIAL_DEF);
				break;*/
			case SDLK_LEFT:
				playerInputState.setState(CInputState::MOVE);
				velX += minVel; 
				dir = LEFT;
				break;
			case SDLK_RIGHT:
				playerInputState.setState(CInputState::MOVE);
				velX += maxVel;
				dir = RIGHT;
				break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
			case SDLK_LEFT:
				velX -= minVel;
				break;
			case SDLK_RIGHT: 
				velX -= maxVel;
				break;
			case SDLK_q:
				playerInputState.setState(CInputState::QUIT);
				break;
		}
	}
}
