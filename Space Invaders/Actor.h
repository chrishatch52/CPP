#pragma once
#include "SDL.h"
#include "SDL_image.h"

#include "Graphics.h"
#include "Input.h"
#include "Entity.h"
#include "InputState.h"

class CActor : public AEntity
{

public:
	CActor(float posX_init, float posY_init, Graphics* graphic = nullptr);
	~CActor();

	CActor(const CActor& objMan) = delete;//copy
	CActor& operator=(const CActor& objMan) = delete;//assignment

	CActor(CActor&& other) = delete;//move constructor

	void render() override;

	//Get CInput
	virtual I_Input* getInput() = 0;

	//Get graphic
	inline Graphics* getGraphic() const { return actorGraphic; }

private:
	Graphics* actorGraphic;
};

