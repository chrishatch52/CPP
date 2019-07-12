#pragma once
#include "Actor.h"
#include "PlayerInput.h"
#include <memory>

class CPlayer :
	public CActor
{
public:
	
	static std::unique_ptr<CPlayer*> makeUniquePlayer(Graphics* texture = NULL);
	~CPlayer();

	void update();

	inline I_Input* getInput() override { return playerInput; }
	inline int getLivesRemaining() { return lives; }
	inline int getScore() { return score; }

private:
	CPlayer(Graphics* texture = nullptr);
	CPlayerInput* playerInput;
	SDL_Event e;
	int lives;
	int score;

	constexpr static float posX_init = 500.f;
	constexpr static float posY_init = 900.f;
};

