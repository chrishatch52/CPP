#pragma once
#include "Manager.h"
#include "ObjectManager.h"
#include "ParticleManager.h"

class CPhysicsManager : protected I_Manager
{
public:
	CPhysicsManager();
	~CPhysicsManager();

	CPhysicsManager(const CPhysicsManager& other) = delete; //copy
	CPhysicsManager& operator=(const CPhysicsManager& other) = delete; //assignment

	CPhysicsManager(CPhysicsManager&& other) = delete; //move constructor

	void update() override;

	void showCollisions(SDL_Renderer* renderer) {}
	void checkCollisions(CObjectManager* objMan);

private:
	bool collisionOccurred(AEntity * laser, AEntity * actor);
	CParticleManager particleManager;
	SDL_Rect result;

};

