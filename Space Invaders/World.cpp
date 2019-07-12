#include "stdafx.h"
#include "World.h"


CWorld::CWorld() { }


CWorld::~CWorld() { }


void CWorld::renderWorld(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_Rect bar = SDL_Rect();
	bar.h = 10;
	bar.w = 1024;
	bar.x = 0;
	bar.y = 950;
	//Draw lines
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 57, 255, 20, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &bar);
}


void CWorld::createWorld(SDL_Renderer * renderer)
{
	int w, h;

	//retrieve window dimensions
	SDL_RenderGetLogicalSize(renderer, &w, &h);

	setDimensions(w, h);
}
