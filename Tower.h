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

	float disBetweenEnemy;
	float towerRange;
	float delayTimer;

	void Init(PrimitiveBuilder *pb, std::vector<Enemy*> Enemies, ProjectileManager* projectile_manager);
	void Update(float, std::vector<Enemy*> Enemies);

	PrimitiveBuilder* primbuilpointer;
	ProjectileManager* projectileManager;
};