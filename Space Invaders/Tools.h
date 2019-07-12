#pragma once
#include "SDL.h"
#include "SDL_image.h"

#include "ObjectManager.h"
#include "Graphics.h"
#include "PlayerInput.h"

#include "pugixml.hpp"



class Tools
{

public:
	
	//CActor factory
	static bool buildActors(CObjectManager* objMan);
	//static void buildCActors(const std::map<int, Graphics*> &textures, std::vector<CActor*> &actors);

	//Shuts down SDL
	static void close(SDL_Renderer* renderer, SDL_Window* window);
		
	//Starts up SDL and creates window
	static bool init(SDL_Window*& window, SDL_Renderer*& renderer);

	//Loads media
	static bool loadMedia(std::map<int, Graphics*> &textures, const std::vector<std::string> &paths, SDL_Renderer* renderer);
};

