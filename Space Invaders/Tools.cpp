#include "stdafx.h"
#include "Tools.h"
#include <iostream>
#include <fstream>
// source LazyFoo tutorials for init(), close()

bool Tools::buildActors(CObjectManager* objMan) {
	bool success = true;

	int barricadeHitCount = 4;

	const std::map<int, Graphics*> textures = objMan->getGraphics();

	objMan->setUser(CPlayer::makeUniquePlayer(textures.at(0)));
	objMan->addObject(objMan->getUser(), CActor::Player);

	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("SpaceInvaders.xml");

	pugi::xml_node root = doc.document_element();

	for (pugi::xml_node_iterator it = root.begin(); it != root.end(); ++it)
	{
		pugi::xml_attribute imgAtt = it->attribute("image");
		pugi::xml_attribute typeAtt = it->attribute("type");
		pugi::xml_attribute xLocAtt = it->attribute("xLoc");
		pugi::xml_attribute yLocAtt = it->attribute("yLoc");
		pugi::xml_attribute rowAtt = it->attribute("row");

		int img = imgAtt.as_int();
		int type = typeAtt.as_int();
		int xLoc = xLocAtt.as_float();
		int yLoc = yLocAtt.as_float();
		int row = rowAtt.as_int();

		switch (type)
		{
		case 0:
			objMan->addObject(new CNPCActor(xLoc, yLoc, textures.at(img)), AEntity::ExtLives);
			break;
		case 1:
			objMan->addObject(new CNPCActor(xLoc, yLoc, textures.at(img)), AEntity::Barricade);
			break;
		case 2:
			objMan->addObject(new CAlienActor(xLoc, yLoc, textures.at(img), row), AEntity::Enemy);
		}
	}
	
	return success;
}


void Tools::close(SDL_Renderer* renderer, SDL_Window* window)
{
	//Destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems*/
	IMG_Quit();
	SDL_Quit();
}


bool Tools::init(SDL_Window*& window, SDL_Renderer*& renderer)
{
	//Initialization flag
	bool success = true;

	//Screen dimension constants
	constexpr int SCREEN_WIDTH = 1024;
	constexpr int SCREEN_HEIGHT = 1024;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Set Logical Size
				SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				
			}
		}
	}

	return success;
}


bool Tools::loadMedia(std::map<int, Graphics*> &textures, const std::vector<std::string> &paths, SDL_Renderer * renderer)
{
	bool success = true;
	int j = 0;
	int laserWidth = 5;
	int laserHeight = 20;
	Graphics* tmp;

	for (auto& i : paths)
	{
		tmp = new Graphics(renderer);
		if (!tmp->loadFromFile(i))
		{
			success = false;
			printf("bad file path!\n");
			break;
		}
		else
		{
			textures.insert(std::pair<int, Graphics*>(j++, tmp));
		}
	}

	return success;
}
