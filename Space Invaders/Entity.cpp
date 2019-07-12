#include "Entity.h"

void AEntity::updateSDLrect(int x, int y) {

	entityRect.x = x;
	entityRect.y = y;
}

void AEntity::setEntityType(int type) {

	switch (type)
	{
	case 0: et = Player;
		break;
	case 1: et = Enemy;
		break;
	case 2: et = Laser;
		break;
	case 3: et = Barricade;
		break;
	case 4: et = ExtLives;
	}
}

void AEntity::setEntityRect(int x, int y, int w, int h) {

	entityRect.x = x;
	entityRect.y = y;
	entityRect.w = w;
	entityRect.h = h;
}
