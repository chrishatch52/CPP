#include "stdafx.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	int w, h;
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The window renderer
	SDL_Renderer* renderer = NULL;

	//CGame object
	CGame* game;

	//Start up SDL and create window
	if (!Tools::init(window, renderer))
	{
		fprintf(stderr, "Failed to initialize!\n");
	}
	else
	{
		//Build CGame
		game = CGame::getInstance(renderer);
		//Play CGame
		game->playGame(renderer);
	}

	//Free resources and close SDL
	Tools::close(renderer, window);
	SDL_DestroyWindow(window);

	return 0;
}
