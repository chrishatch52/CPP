#pragma once
#include "Manager.h"
#include "stdafx.h"
#include "ParticleExplosion.h"
#include "SDL.h"

class CParticleManager : protected I_Manager
{
public:
	CParticleManager();
	~CParticleManager();

	CParticleManager(const CParticleManager& other) = delete; //copy
	CParticleManager& operator=(const CParticleManager& other) = delete; //assignment

	CParticleManager(CParticleManager&& other) = delete; //move constructor

	void update() override;

	void showCollision(SDL_Renderer* renderer);
	void addExplosionRect(SDL_Rect result);

private:
	void buildParticles(SDL_Rect explosionRect) {}
	std::vector<CParticleExplosion*> explosions;
};

