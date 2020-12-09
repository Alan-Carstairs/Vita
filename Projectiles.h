#pragma once
#include "GameObject.h"
#include <vector>

class Enemy;

class Projectiles : public GameObject
{
public:

	void Init(gef::Vector4 start_pos, gef::Vector4 enemy_pos);

	void Update(float frame_time);
	void Cal_Velocity(gef::Vector4, gef::Vector4);
	bool CheckEnemyCollisions(std::vector<Enemy*>& Enemies);
	void Delete_Projectile();
	float p_speed_;
	//float DisToEnemy;
	
	float dist_to_enemy;

	bool is_Enemy_in_Range;
	bool Has_Hit;

	bool alive;

	std::vector<gef::Vector4> Projectile_Pos;

};