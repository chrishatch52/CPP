#pragma once
#include "stdafx.h"
#include "Manager.h"

class CObjectManager : protected I_Manager
{
public:
	CObjectManager();
	~CObjectManager();

	CObjectManager(const CObjectManager& other) = delete;//copy
	CObjectManager& operator=(const CObjectManager& other) = delete;//assignment

	CObjectManager(CObjectManager&& other) = delete;//move constructor

	//build and add objects to entity vectors
	void addObject(CActor* actor, int type);
	bool buildAssets(SDL_Renderer* renderer);

	//wrapper to avoid nasty code
	inline CPlayer* getUser() { return *(user.get()); }

	//return entity vectors
	std::vector<AEntity*> *getCAlienActors() { return &alienActors; }
	std::vector<AEntity*> *getCNPCActors() { return &npcActors; }
	std::vector<AEntity*> *getObjects() { return &objPool; }
	std::vector<AEntity*> *getLasers() { return &lasers; }

	std::map<int, Graphics*> getGraphics() { return assets; }

	void renderObjects();

	int countDownedEnemies(int oldScore);

	inline void setUser(std::unique_ptr<CPlayer*> newUser) {
		user = std::move(newUser);
	}
	
	inline void setGameLevel(int level) { gameLvl = level; }

	void update() override;

	bool quitGame();
	
private:
	void reset();
	void updateAttackerGrid();
	void checkPlayerAttack(CPlayerInput* playerInput);
	void checkEnemyAttack(int who);
	void renderHelper(std::vector<AEntity*> toRender);
	void updateHelper(std::vector<AEntity*> toUpdate);

	std::map<int, Graphics*> assets;

	std::unique_ptr<CPlayer*> user;
	std::vector<AEntity*> objPool;
	std::vector<AEntity*> npcActors;
	std::vector<AEntity*> alienActors;
	std::vector<AEntity*> attackerGrid;
	std::vector<AEntity*> lasers;

	int gameLvl;

	constexpr static size_t atkGridSize = 11;
};

