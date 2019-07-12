#pragma once
#include "SDL.h"

class CWorld
{



public:
	
	CWorld();
	~CWorld();

	CWorld(const CWorld& objMan) = delete;//copy
	CWorld& operator=(const CWorld& objMan) = delete;//assignment

	CWorld(CWorld&& other) = delete;//move constructor

	//Creates world view
	void createWorld(SDL_Renderer * renderer);
	//Renders world view
	void renderWorld(SDL_Renderer * renderer);

	inline void setDimensions(int w, int h) { width = w; height = h; }
	
private:
	int width, height;
};

