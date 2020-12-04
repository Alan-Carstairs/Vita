#include "Tower.h"
#include <math.h>
Tower::Tower()
{
	
}

Tower::~Tower()
{
}

void Tower::Init(PrimitiveBuilder *pb, std::vector<Enemy*> Enemies)
{
	primbuilpointer = pb;
	ep_ = Enemies;
	projectile_Manager.Init( ep_);
	towerRange = 0.4;
	delayTimer = 0.0f;
}

void Tower::Update(float frametime)
{
	delayTimer += frametime;
	
	float distance;
	for (int i = 0; i < ep_.size(); i++)
	{
		distance = (ep_[i]->position_ - position_).Length();
		if (delayTimer > 1.0)
		{
			if (distance < towerRange)
			{
				projectile_Manager.createprojectile(primbuilpointer, ep_[i]->position_);
				delayTimer = 0.0;
			}
		}
	}
	projectile_Manager.Update(frametime);
}
