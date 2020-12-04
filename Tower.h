#pragma once
#include "GameObject.h"
#include "ProjectileManager.h"
#include "primitive_builder.h"
#include "Enemy.h"
#include <vector>
class Tower : public GameObject
{
public:
	Tower();
	~Tower();
	ProjectileManager projectile_Manager;

	float disBetweenEnemy;
	float towerRange;
	float delayTimer;

	void Init(PrimitiveBuilder *pb, std::vector<Enemy*> Enemies);
	void Update(float);
	PrimitiveBuilder* primbuilpointer;
};