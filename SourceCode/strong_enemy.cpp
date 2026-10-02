#include "enemy.h"
#include "all.h"
#include "camera.h"
#include "hit_check.h"
#include "player.h"
#include "attack_line.h"

Sprite* spr_strong_enemy;
enemy_data strong_enemy;

void strong_enemy_init()
{
	spr_strong_enemy = sprite_load(L"Data/Images/strong_enemy.png");

	strong_enemy = {};

	strong_enemy.pos.x = WORLD_W / 2;
	strong_enemy.pos.y = WORLD_H / 2;
}
void strong_enemy_update()
{
}
void strong_enemy_render()
{
	strong_enemy.screen.x = strong_enemy.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	strong_enemy.screen.y = strong_enemy.pos.y - camera_pos.y + SCREEN_H * 0.5f;

	sprite_render(spr_strong_enemy, strong_enemy.screen.x, strong_enemy.screen.y,
		          2,2);

}
void strong_enemy_deinit()
{
	safe_delete(spr_strong_enemy);
}
