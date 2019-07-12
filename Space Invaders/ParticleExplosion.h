#pragma once
#include "SDL.h"

class CParticleExplosion
{
public:
	CParticleExplosion();
	~CParticleExplosion();

	CParticleExplosion(const CParticleExplosion& other) = delete; //copy
	CParticleExplosion& operator=(const CParticleExplosion& other) = delete; //assignment

	CParticleExplosion(CParticleExplosion&& other) = delete; //move constructor
};

