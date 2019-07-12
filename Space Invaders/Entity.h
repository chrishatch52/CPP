#pragma once
#include "SDL.h"

class AEntity
{
public:
	enum EntityType {
		Player = 0,
		Enemy,
		Laser,
		Barricade,
		ExtLives
	};

public:
	inline void activate() { active = true; }
	inline void deactivate() { active = false; }
	virtual bool isActive() { return active; }

	//Shows the Entity on the screen
	virtual void render() = 0;

	//Updates the entity position and current action
	virtual void update() = 0;

	//bounding box position for rendering and collision testing
	void updateSDLrect(int x, int y);

	inline SDL_Rect getEntityRect() { return entityRect; }

	//Used for type checking
	inline EntityType getEntityType() { return et; }

	void setEntityType(int type);

	void setEntityRect(int x, int y, int w, int h);

private:
	bool active;
	EntityType et;
	SDL_Rect entityRect;
};

