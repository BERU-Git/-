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

	strong_enemy.pos.x = STRONG_ENEMY_W + rand() % WORLD_W - STRONG_ENEMY_W * 2.0f;
	strong_enemy.pos.y = STRONG_ENEMY_H + rand() % WORLD_H - STRONG_ENEMY_H * 2.0f;

	strong_enemy.speed.x = STRONG_ENEMY_SPEED;
	strong_enemy.speed.y = STRONG_ENEMY_SPEED;
}
void strong_enemy_update()
{
	enemy_chase(player_pos.x, player_pos.y, strong_enemy.pos.x, strong_enemy.pos.y,
		strong_enemy.angle, strong_enemy.chase.x, strong_enemy.chase.y);

	strong_enemy.pos.x += strong_enemy.speed.x * strong_enemy.chase.x;
	strong_enemy.pos.y += strong_enemy.speed.y * strong_enemy.chase.y;
}
void strong_enemy_render()
{
	strong_enemy.screen.x = strong_enemy.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	strong_enemy.screen.y = strong_enemy.pos.y - camera_pos.y + SCREEN_H * 0.5f;

	sprite_render(spr_strong_enemy, strong_enemy.screen.x, strong_enemy.screen.y,
		          2,2,
		          0,0,
		          STRONG_ENEMY_W, STRONG_ENEMY_H,
		          STRONG_ENEMY_W * 0.5f, STRONG_ENEMY_H * 0.5f);

}
void strong_enemy_deinit()
{
	safe_delete(spr_strong_enemy);
}
