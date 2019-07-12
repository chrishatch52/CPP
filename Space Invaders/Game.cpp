#include "Game.h"

static CGame* game;

CGame::CGame(SDL_Renderer* renderer) {

	m_Level = 1;
	m_Score = 0;
}

//Singleton to prevent more than one CGame object from being created
CGame* CGame::getInstance(SDL_Renderer* renderer) {

	if (game == nullptr)
		return new CGame(renderer);
	
	return game;
}

void CGame::playGame(SDL_Renderer * renderer) {

	//Main loop flag
	bool quit = false;
	//Keeps track of time between steps
	LTimer stepTimer;

	stepTimer.start();

	world.createWorld(renderer);
	
	if (!objectManager.buildAssets(renderer))
	{
		quit = true;
	}

	//While application is running
	while (!quit)
	{
		//Handle input for the player
		objectManager.update();

		quit = objectManager.quitGame();

		//physicsManager.update();

		//soundManager.update();

		//check collisions
		physicsManager.checkCollisions(&objectManager);
			
		//Render world
		world.renderWorld(renderer);

		//Render Objects
		objectManager.renderObjects();

		//Render Particles
		//physicsManager.renderPhysics();

		//Update screen
		SDL_RenderPresent(renderer);
	}
}

