#include "all.h"
#include "enemy.h"
#include "player.h"
#include "camera.h"

Sprite* spr_range_enemy;
Sprite* spr_range_enemy_bullet;

enemy_data range_enemy;
enemy_data range_enemy_bullet[BULLET_MAX];

void range_enemy_init()
{
	spr_range_enemy = sprite_load(L"Data/images/range_enemy.png");
	spr_range_enemy_bullet = sprite_load(L"Data/images/range_enemy_bullet.png");

	for (int i = 0; i < BULLET_MAX; i++)
	{
		range_enemy_bullet[i].pos.x = 0;
		range_enemy_bullet[i].pos.y = 0;
	}

	range_enemy.pos.x = STRONG_ENEMY_W + rand() % WORLD_W - STRONG_ENEMY_W * 2.0f;
	range_enemy.pos.y = STRONG_ENEMY_H + rand() % WORLD_H - STRONG_ENEMY_H * 2.0f;
}
void range_enemy_update()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		range_enemy_bullet[i].pos.x = range_enemy.pos.x;
		range_enemy_bullet[i].pos.y = range_enemy.pos.y;
	}
	//for(int i = 0; i < BULLET_MAX ; i++ )
	//{
	//	enemy_chase(player_pos.x, player_pos.y,
	//		range_enemy_bullet[i].pos.x,range_enemy_bullet[i].pos.y,

	//}

}
void range_enemy_render()
{
	range_enemy.screen.x = range_enemy.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	range_enemy.screen.y = range_enemy.pos.y - camera_pos.y + SCREEN_H * 0.5f;
	sprite_render(spr_range_enemy, range_enemy.screen.x, range_enemy.screen.y);


}
void range_enemy_deinit()
{

	safe_delete(spr_range_enemy);
	safe_delete(spr_range_enemy_bullet);

}

