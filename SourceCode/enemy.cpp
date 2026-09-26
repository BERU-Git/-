#include "enemy.h"
#include "obj2d.h"

#include "../GameLib/game_lib.h"
using namespace GameLib;

int enemy_state;
OBJ2D enemy[ENEMY_MAX];
Sprite* spr_enemy;

void enemy_init()
{
	spr_enemy = sprite_load(L"Data/Images/SAMPLE_GOB.png");
	enemy_state = 0;
}

void enemy_deinit()
{
	safe_delete(spr_enemy);
}

void enemy_update()
{
	switch (enemy_state)
	{
	case 0:

		for (int i = 0; i < ENEMY_MAX; i++)
		{
			enemy[i].pos.x = 100.0f + (50.0f * i);
			enemy[i].pos.y = 200.0f;
		}
		++enemy_state;

	case 1:
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			
		}
		break;
	}
}
void enemy_render()//“G‚Ì•`‰æ
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		sprite_render(enemy[i].spr, enemy[i].pos.x, enemy[i].pos.y,
			enemy[i].scale.x, enemy[i].scale.y,
			enemy[i].tex_pos.x, enemy[i].tex_pos.y,
			enemy[i].tex_size.x, enemy[i].tex_size.y,
			enemy[i].color.x, enemy[i].color.y, enemy[i].color.z, enemy[i].color.w);
	}
	
}