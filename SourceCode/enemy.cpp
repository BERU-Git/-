#include "enemy.h"
#include "all.h"
#include "camera.h"
Sprite* spr_enemy;
enemy_data enemy[ENEMY_MAX];

void enemy_init()
{
	spr_enemy = sprite_load(L"Data/Images/SAMPLE_GOB.png");
		for (int i = 0; i < ENEMY_MAX; i++)
		{
			enemy[i].pos.x = ENEMY_W + rand() % (WORLD_W - ENEMY_W );
			enemy[i].pos.y = ENEMY_H + rand() % (WORLD_H - ENEMY_H );
		}
}


void enemy_update()
{

}

void enemy_render()//“G‚Ì•`‰æ
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i].screen.x = enemy[i].pos.x - camera_pos.x + SCREEN_W * 0.5f;
		enemy[i].screen.y = enemy[i].pos.y - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_enemy, enemy[i].screen.x, enemy[i].screen.y,
		              1,1,
					  0,0,
			          ENEMY_W,ENEMY_H,
			          ENEMY_W * 0.5f,ENEMY_H * 0.5f);
	}
	
}
void enemy_deinit()
{
	safe_delete(spr_enemy);
}