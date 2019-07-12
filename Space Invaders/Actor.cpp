#include "Actor.h"


CActor::CActor(float posX_init, float posY_init, Graphics* graphic) {
	
	actorGraphic = graphic;
	setEntityRect(int(posX_init), int(posY_init), graphic->getWidth(), graphic->getHeight());
}


CActor::~CActor() {
	
	if (actorGraphic != nullptr)
		actorGraphic->~Graphics();
}


void CActor::render() {
	
	//Show the actor
	I_Input* tmp = getInput();
	if(tmp != nullptr)
		actorGraphic->render(getEntityRect().x, getEntityRect().y);
}
