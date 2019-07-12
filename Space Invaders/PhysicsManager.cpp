#include "PhysicsManager.h"



CPhysicsManager::CPhysicsManager() {
}


CPhysicsManager::~CPhysicsManager() {	}


void CPhysicsManager::update() {
}

void CPhysicsManager::checkCollisions(CObjectManager* objMan) {

	for (auto& i : *(objMan->getLasers()))
	{
		if (!i->isActive())
			continue;
		else
		{
			CLaser* tmpLaser = static_cast<CLaser*> (i);
			for (auto& j : *(objMan->getObjects()))
			{
				if (!j->isActive())
					continue;
				else if (collisionOccurred(i, j))
				{
					if (j->getEntityType() == AEntity::Barricade)
					{
						CNPCActor* tmp = static_cast<CNPCActor*>(j);
						
						if (!tmp->hasHitsLeft())
							j->deactivate();

						tmp->takeHit();
						i->deactivate();
					}
					else if(j->getEntityType() == AEntity::Enemy && tmpLaser->getDirection() != CLaser::LASER_DOWN)
					{
						i->deactivate();
						j->deactivate();
					}
					else if (j->getEntityType() == AEntity::Player && tmpLaser->getDirection() == CLaser::LASER_DOWN)
					{
						i->deactivate();
						j->deactivate();
					}

					return;
				}
			}
		}

	}
}

bool CPhysicsManager::collisionOccurred(AEntity * laser, AEntity * actor) {
	
	if (SDL_IntersectRect(&laser->getEntityRect(), &actor->getEntityRect(), &result))
	{

		return true;
	}
	return false;
}
