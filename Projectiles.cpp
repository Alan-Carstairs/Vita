#include "Projectiles.h"
#include "Enemy.h"

void Projectiles::Init(gef::Vector4 start_pos, gef::Vector4 enemy_pos)
{
	p_speed_ = 0.021f;
	scale_vector = gef::Vector4(0.05, 0.05, 0.05);
	position_ = start_pos; 
	velocity_ = enemy_pos - start_pos;
	velocity_.Normalise();
	velocity_ *= p_speed_;
	alive = true;
}

void Projectiles::Update(float frame_time)
{
 	position_ += velocity_ * frame_time;
	BuildTransform();
	set_transform(local_transform );
}

void Projectiles::Cal_Velocity(gef::Vector4 enemy_pos, gef::Vector4 tower_pos)
{
	velocity_ = enemy_pos - tower_pos;
	velocity_.Normalise();
	velocity_ *= p_speed_;
}

void Projectiles::Delete_Projectile()
{

}

bool Projectiles::CheckEnemyCollisions(std::vector<Enemy*>& Enemies)
{
	const float collision_distance = 0.005f;
	for (int i = 0; i < Enemies.size(); i++)
	{
		
		// check collision between projectile and enemy
		gef::Vector4 offset = Enemies[i]->position_ - position_;
		float distance = offset.Length();

		if (distance < collision_distance)
		{
			// target hit! destroy enemy and projectiles 
		
			Has_Hit = true;
			alive = false;
			Enemies[i]->alive = false;
						
		}
	}
}
