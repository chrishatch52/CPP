#pragma once
#include "stdafx.h"
#include <map>

#include "LTimer.h"
#include "Tools.h"
#include "SoundManager.h"
#include "ObjectManager.h"
#include "ParticleManager.h"
#include "PhysicsManager.h"
#include "World.h"

#include <memory>

class CGame 
{

public:	
	static CGame* getInstance(SDL_Renderer* renderer);
	
	void playGame(SDL_Renderer* renderer);

	CGame(const CGame& objMan) = delete;//copy
	CGame& operator=(const CGame& objMan) = delete;//assignment

	CGame(CGame&& other) = delete;//move constructor

private:
	int m_Level;
	int m_Score;
	CGame(SDL_Renderer* renderer);
	
	CObjectManager objectManager;
	CParticleManager particleManager;
	CPhysicsManager physicsManager;
	CSoundManager soundManager;
	CWorld world;
};

