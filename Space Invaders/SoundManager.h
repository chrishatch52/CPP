#pragma once
#include "stdafx.h"
#include "Manager.h"
#include "SDL_audio.h"

class CSoundManager : protected I_Manager
{
public:
	enum SoundType {
		BUTTON_CLICK = 0,
		GAME_MUSIC,
		LASER_FIRE,
		EXPLOSION,
		NEW_LEVEL,
		MOTHERSHIP,
		GAME_OVER,
		MULTI_SHOT,
		FORCEFIELD
	};

public:
	CSoundManager();
	~CSoundManager();

	CSoundManager(const CSoundManager& other) = delete; //copy
	CSoundManager& operator=(const CSoundManager& other) = delete; //assignment

	CSoundManager(CSoundManager&& other) = delete; //move constructor

	void playSound(SoundType sound, float duration);
	void update() override;
	
private:
	void loadSounds();
	void stopSound();
	void unloadSounds();

	std::vector<SDL_AudioSpec*> gameSounds;
};

