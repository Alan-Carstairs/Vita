#pragma once
#include "gef.h"
#include "Projectiles.h"
#include <vector>
#include "primitive_builder.h"
#include "graphics\renderer_3d.h"
#include "Enemy.h"

namespace gef
{
	class Platform;
	class Font;
	class SpriteRenderer;
	class Renderer3D;
	class Mesh;
	class RenderTarget;
	class TextureVita;
	class InputManager;
	class Scene;
}
class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();
	void Init(std::vector<Enemy*> ep_);
	void Update(float frame_time);
	void Render(gef::Renderer3D* r3d);
	void createprojectile(PrimitiveBuilder* pb, gef::Vector4 emypos);
	void Launch_Projectiles(float delta_Time);
	void Delete_Projectiles();
	std::vector<Projectiles*> projectiles;

	int num_projectiles_launched = 0, Lauched_Projectile;
	bool launched_em_all;
	float delaytimer;
private:




};

