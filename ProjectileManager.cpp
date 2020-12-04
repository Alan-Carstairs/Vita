#include "ProjectileManager.h"

ProjectileManager::ProjectileManager()
{
	projectiles = std::vector<Projectiles*>();

}

ProjectileManager::~ProjectileManager()
{

}

void ProjectileManager::Init(std::vector<Enemy*> ep)
{
		
	
}

void ProjectileManager::Update(float frame_time)
{
	for (int i = 0; i < projectiles.size(); i++) {
		projectiles[i]->Update(frame_time);
		//Projectiles[i]->set_transform(_projectiles->local_transform * marker_transform1);
	}
}


void ProjectileManager::Render(gef::Renderer3D* r3d)
{
	for (int i = 0; i < projectiles.size(); i++) {
		r3d->DrawMesh(*projectiles[i]);
		//Projectiles[i]->set_transform(_projectiles->local_transform * marker_transform1);
	}
}

void ProjectileManager::createprojectile(PrimitiveBuilder* pb, gef::Vector4 emypos)
{
	Projectiles* projectile = new Projectiles;
	projectile->set_mesh(pb->CreateBoxMesh(gef::Vector4(0.05, 0.05, 0.05), gef::Vector4(0.f, 0.f, 0.f)));
	projectile->position_ = gef::Vector4(0, 0, 0);
	//projectile.velocity_ = emypos - Startpos;
	projectile->Init(emypos);
	projectiles.push_back(projectile);
}

void ProjectileManager::Launch_Projectiles(float delta_Time)
{
	/*delaytimer += delta_Time;
	if (!launched_em_all) {
		if (delaytimer > 0.15)
		{
			projectiles[num_projectiles_launched]->Has_Hit = true;

			num_projectiles_launched++;
			delaytimer = 0.0;
		}
		if (num_projectiles_launched == projectiles.size() - 1)
		{
			launched_em_all = true;
		}
	}*/
}

void ProjectileManager::Delete_Projectiles()
{

}

