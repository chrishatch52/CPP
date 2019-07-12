#include "stdafx.h"
#include "Player.h"
#include <iostream>

CPlayer::CPlayer(Graphics* texture) : CActor(posX_init, posY_init, texture),
									playerInput(new CPlayerInput(posX_init, posY_init)) {

	lives = 4;
	score = 0;
	activate();
}


CPlayer::~CPlayer() {	}


std::unique_ptr<CPlayer*> CPlayer::makeUniquePlayer(Graphics* texture) {

	return std::make_unique<CPlayer*>(new CPlayer(texture));
}


void CPlayer::update() {
	
	bool processInput = true;
	//clear input buffer
	std::cin.sync();

	while (SDL_PollEvent(&e) != 0)
	{
		playerInput->handleEvent(e);
		break;
	}
	updateSDLrect(int(playerInput->getPosX()), int(playerInput->getPosY()));
}
