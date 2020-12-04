#pragma once
#include "gef.h"
#include "Enemy.h"
#include <vector>
#include "primitive_builder.h"
#include "graphics\renderer_3d.h"

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
class EnemyManager
{
	public:
		EnemyManager();
		~EnemyManager();
		void Init(PrimitiveBuilder* pb, std::vector<gef::Vector4> wp);
		void Update(float frame_time);
		void Render(gef::Renderer3D* r3d );
		void Launch_Enemy(float delta_Time);
		void Delete_Enemy();
		std::vector<Enemy*> Enemies;
		
		int num_enemy_launched = 0, Lauched_enemy;
		bool launched_em_all;
		float delaytimer;
	private:




};

