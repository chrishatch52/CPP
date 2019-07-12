#include "ObjectManager.h"
#include "ComputerInput.h"
#include "Tools.h"
#include <memory>

CObjectManager::CObjectManager() {
	
	gameLvl = 0;
	attackerGrid.reserve(atkGridSize);
}


CObjectManager::~CObjectManager() {	}


void CObjectManager::update() {

	CPlayerInput* tmpInput = static_cast<CPlayerInput*>(getUser()->getInput());
	
	//update user
	getUser()->update();
	checkPlayerAttack(tmpInput);
	tmpInput->move();
	//update enemies and npcs
	updateHelper(alienActors);
	updateHelper(lasers);

	countDownedEnemies(getUser()->getScore());
}


void CObjectManager::addObject(CActor* actor, int type) {

	actor->setEntityType(type);
	objPool.push_back(actor);
	switch (type)
	{
		case 0:
			break;
		case 1:
			alienActors.push_back(static_cast<CAlienActor*>(actor));
			break;
		default:
			npcActors.push_back(static_cast<CNPCActor*>(actor));
			break;
	}
}

bool CObjectManager::buildAssets(SDL_Renderer* renderer) {

	bool success = true;

	//Build Actors
	std::vector<std::string> paths;
	//replace with read file
	paths.push_back("ship.jpg");
	paths.push_back("bunker.jpg");
	paths.push_back("alienLrg.jpg");
	paths.push_back("alienMedA.jpg");
	paths.push_back("alienMedB.jpg");
	paths.push_back("alienSml.jpg");
	paths.push_back("laserImg.jpg");

	//Load media
	if (!Tools::loadMedia(assets, paths, renderer))
	{
		fprintf(stderr, "Failed to load media!\n");
		success = false;
	}

	if (!Tools::buildActors(this))
	{
		fprintf(stderr, "Failed to build actors!\n");
		success = false;
	}

	for (size_t i = 0; i < atkGridSize; i++)
	{
		attackerGrid.push_back(alienActors.at(i));
	}

	return success;
}

void CObjectManager::renderObjects() {

	//Render CActors
	
	renderHelper(npcActors);
	renderHelper(alienActors);

	if(getUser()->isActive())
		getUser()->render();

	renderHelper(lasers);
}

//Count downed enemies and tabulate current score
int CObjectManager::countDownedEnemies(int oldScore) {

	int inactiveCount = 0;
	int newScore = 0;

	for (auto&i : alienActors)
	{
		if (!i->isActive())
		{
			inactiveCount++;
		}
	}

	if (inactiveCount == alienActors.size())
	{
		gameLvl++;
		reset();
	}

	return (newScore - oldScore);
}


void CObjectManager::updateAttackerGrid()
{
	for (size_t i = 0; i < atkGridSize; i++)
	{
		if (!attackerGrid.at(i)->isActive())
		{
			attackerGrid.erase(attackerGrid.begin() + i);
		}

		for (size_t j = atkGridSize - 1; j < alienActors.size(); j++)
		{
			if (objPool.at(j)->isActive())
			{
				attackerGrid.emplace(attackerGrid.begin() + i, alienActors.at(j));
			}
		}
	}
}

void CObjectManager::checkPlayerAttack(CPlayerInput * playerInput)
{
	if (playerInput->getPlayerInputState() == CInputState::ATTACK)
	{
		Graphics* tmpGraphic = getUser()->getGraphic();

		float tmpX = float(playerInput->getPosX() + ((tmpGraphic->getWidth() / 2)) - assets.at(6)->getWidth() / 2);
		float tmpY = playerInput->getPosY() - assets.at(6)->getHeight() * 2;

		CLaser* tmp = new CLaser(tmpX, tmpY, assets.at(6));
		tmp->setDirection(0);

		lasers.push_back(tmp);
		playerInput->setPlayerInputState(CInputState::DEFAULT);
	}
}

void CObjectManager::checkEnemyAttack(int who)
{
	CAlienActor* tmpAlien = static_cast<CAlienActor*> (attackerGrid.at(who));
	Graphics* tmpGraphic = tmpAlien->getGraphic();
	CComputerInput* playerInput = static_cast<CComputerInput*>(tmpAlien->getInput());

	float tmpX = float(playerInput->getPosX() + ((tmpGraphic->getWidth() / 2)) - assets.at(6)->getWidth() / 2);
	float tmpY = playerInput->getPosY() + tmpGraphic->getHeight();

	CLaser* tmp = new CLaser(tmpX, tmpY, assets.at(6));
	tmp->setDirection(1);

	lasers.push_back(tmp);
}

void CObjectManager::renderHelper(std::vector<AEntity*> toRender) {

	for (auto& i : toRender)
	{
		if (i->isActive())
			i->render();
	}
}

void CObjectManager::updateHelper(std::vector<AEntity*> toUpdate) {

	for (auto& i : toUpdate)
	{
		i->update();
	}
}

bool CObjectManager::quitGame()
{
	CPlayerInput* tmpInput = static_cast<CPlayerInput*>((*(user.get()))->getInput());

	return ((tmpInput->getPlayerInputState() == CInputState::QUIT) ? true : false);
}

void CObjectManager::reset() {
	
	for (auto& i : npcActors)
	{

		if (!i->isActive() && i->getEntityType() == CActor::Barricade)
			i->activate();
	}

	for (auto& i : alienActors)
	{
		CAlienActor* tmpAlien = static_cast<CAlienActor*>(i);
		CComputerInput* tmpInput = static_cast<CComputerInput*>(tmpAlien->getInput());

		tmpInput->resetX();
		tmpInput->setNewPosY();
		tmpInput->setVelo(gameLvl);

		i->activate();
	}

	for (auto& i : lasers)
	{
		if (i->isActive())
			i->deactivate();
	}
}
