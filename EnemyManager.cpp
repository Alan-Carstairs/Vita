#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	Enemies = std::vector<Enemy*>();
	
}

EnemyManager::~EnemyManager()
{

}

void EnemyManager::Init(PrimitiveBuilder* pb, std::vector<gef::Vector4> wp)
{
	for (int i = 0; i < 5;i++) 
	{
		Enemy* enemy = new Enemy();
		enemy->set_mesh(pb->CreateBoxMesh(gef::Vector4(0.5, 0.5, 0.5), gef::Vector4(0.f, 0.f, 0.f)));
		//enemy->Init();
		enemy->position_ = gef::Vector4(0, 0, 0);
		enemy->init_Waypoints(wp);
		enemy->setup_Waypoints(wp[0], wp[1]);
		//Moving_enemy.setup_Waypoints(waypoints_[Moving_enemy.currentWP_], waypoints_[Moving_enemy.nextWP_]);
		enemy->reCal_Velocity();


		Enemies.push_back(enemy);
	}
}

void EnemyManager::Update(float frame_time)
{
	for (int i = 0; i < Enemies.size(); i++) {
		if (Enemies[i]->alive)
		{
			Enemies[i]->Update(frame_time);
		}//Enemies[i]->set_transform(enemy->local_transform * marker_transform1);
	}
}


void EnemyManager::Render(gef::Renderer3D* r3d)
{
	for (int i = 0; i < Enemies.size(); i++) {
		if (Enemies[i]->alive)
		{
			r3d->DrawMesh(*Enemies[i]);
			//Enemies[i]->set_transform(enemy->local_transform * marker_transform1);
		}
	}
}

void EnemyManager::Launch_Enemy(float delta_Time)
{
	delaytimer += delta_Time;
	if (!launched_em_all) {
		if (delaytimer > 5.0)
		{
			Enemies[num_enemy_launched]->HasBegun = true;

		 num_enemy_launched++;
		 delaytimer = 0.0;
		}
		if (num_enemy_launched == Enemies.size() - 1)
		{
			launched_em_all = true;
		}
	}
}

void EnemyManager::Delete_Enemy()
{

}
 
