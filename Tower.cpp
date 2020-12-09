#include "Tower.h"
#include <math.h>
Tower::Tower()
{
	
}

Tower::~Tower()
{
}

void Tower::Init(PrimitiveBuilder *pb, std::vector<Enemy*> Enemies, ProjectileManager* projectile_manager)
{
	primbuilpointer = pb;
	towerRange = 0.4;
	delayTimer = 0.0f;
	projectileManager = projectile_manager;
}

void Tower::Update(float frametime, std::vector<Enemy*> Enemies)
{
	// set tower position
	position_ = local_transform.GetTranslation();

	delayTimer += frametime;
	
	float distance;
	for (int i = 0; i < Enemies.size(); i++)
	{
		distance = (Enemies[i]->position_ - position_).Length();
		if (delayTimer > 1.0)
		{
			if (distance < towerRange)
			{
				projectileManager->createprojectile(primbuilpointer, position_, Enemies[i]->position_);
				delayTimer = 0.0;
				break;
			}
		}
	}
}
