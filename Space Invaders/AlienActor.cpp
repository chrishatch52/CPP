#include "AlienActor.h"
#include "ComputerInput.h"


CAlienActor::CAlienActor(float posX_init, float posY_init, Graphics *graphic, int newRow) : CActor(posX_init, posY_init, graphic), 
																							alienInput(new CComputerInput(posX_init, posY_init)),
																							row(row){

	activate();
}


CAlienActor::~CAlienActor() {	}

void CAlienActor::update() {

	alienInput->move();

	updateSDLrect(int(alienInput->getPosX()), int(alienInput->getPosY()));
}


