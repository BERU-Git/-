#include "all.h"
#include "enemy.h"
#include "player.h"
#include "camera.h"

Sprite* spr_range_enemy;
Sprite* spr_range_enemy_bullet;

enemy_data range_enemy;
enemy_data range_enemy_bullet[BULLET_MAX];

int range_attack_timer;
int range_prep_timer;
int range_teleport_timer;

int range_attack_index;//打つ球を記憶する

void range_enemy_init()
{
	spr_range_enemy = sprite_load(L"Data/images/range_enemy.png");
	spr_range_enemy_bullet = sprite_load(L"Data/images/range_enemy_bullet.png");


	range_enemy.pos.x = STRONG_ENEMY_W + rand() % WORLD_W - STRONG_ENEMY_W * 2.0f;
	range_enemy.pos.y = STRONG_ENEMY_H + rand() % WORLD_H - STRONG_ENEMY_H * 2.0f;

	range_attack_timer = 0;
	range_prep_timer = 0;
	range_teleport_timer = 0;
	range_attack_index = 0;

	for (int i = 0; i < BULLET_MAX; i++)
	{
		range_enemy_bullet[i].pos.x = range_enemy.pos.x;
		range_enemy_bullet[i].pos.y = range_enemy.pos.y;

		range_enemy_bullet[i].speed.x = RANGE_ATTACK_SPEED;
		range_enemy_bullet[i].speed.y = RANGE_ATTACK_SPEED;

	}

}
void range_enemy_update()
{
	switch(range_enemy.range_state)
	{

	case BULLET_CHASE:
			range_attack_timer++;
			//球をセット
			if(range_attack_timer % (RANGE_ATTACK_TIMER / BULLET_MAX ) == 0 )
			{
				range_enemy_bullet[range_attack_index].pos.x = range_enemy.pos.x;
				range_enemy_bullet[range_attack_index].pos.y = range_enemy.pos.y;


				enemy_chase(player_pos.x, player_pos.y,
					range_enemy_bullet[range_attack_index].pos.x, range_enemy_bullet[range_attack_index].pos.y,
					range_enemy_bullet[range_attack_index].angle, range_enemy_bullet[range_attack_index].chase.x, range_enemy_bullet[range_attack_index].chase.y);
			
				range_attack_index++;
			}

			//球を発射
			for (int i = 0; i < range_attack_index; i++)
			{
				range_enemy_bullet[i].pos.x += range_enemy_bullet[i].speed.x * range_enemy_bullet[i].chase.x;
				range_enemy_bullet[i].pos.y += range_enemy_bullet[i].speed.y * range_enemy_bullet[i].chase.y;
			}
	

			if (range_attack_timer >= RANGE_ATTACK_TIMER)
			{
				range_enemy.range_state = ENEMY_TELEPORT_PREP;
			}

			break;
		

	case ENEMY_TELEPORT_PREP:

		range_prep_timer++;

		for (int i = 0; i < BULLET_MAX; i++)
		{
			range_enemy_bullet[i].pos.x += range_enemy_bullet[i].speed.x * range_enemy_bullet[i].chase.x;
			range_enemy_bullet[i].pos.y += range_enemy_bullet[i].speed.y * range_enemy_bullet[i].chase.y;
		}

		if (range_prep_timer >= RANGE_ATTACK_TIMER)
		{
			range_enemy.range_state = ENEMY_TELEPORT;
		}

		break;

	//case ENEMY_TELEPORT:
	//	

	//	break;

	}

}
void range_enemy_render()
{
	//玉の表示
	for (int i = 0; i < BULLET_MAX; i++)
	{
		range_enemy_bullet[i].screen.x = range_enemy_bullet[i].pos.x - camera_pos.x + SCREEN_W * 0.5f;
		range_enemy_bullet[i].screen.y = range_enemy_bullet[i].pos.y - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_range_enemy_bullet, range_enemy_bullet[i].screen.x, range_enemy_bullet[i].screen.y,
			1, 1,
			0, 0,
			ENEMY_BULLET_W, ENEMY_BULLET_H,
			ENEMY_BULLET_W * 0.5f, ENEMY_BULLET_H * 0.5f);
	}

	//敵の表示
	range_enemy.screen.x = range_enemy.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	range_enemy.screen.y = range_enemy.pos.y - camera_pos.y + SCREEN_H * 0.5f;
	sprite_render(spr_range_enemy, range_enemy.screen.x, range_enemy.screen.y,
		1,1,
		0,0,
		STRONG_ENEMY_W, STRONG_ENEMY_H,
		STRONG_ENEMY_W * 0.5f, STRONG_ENEMY_H * 0.5f);





}
void range_enemy_deinit()
{

	safe_delete(spr_range_enemy);
	safe_delete(spr_range_enemy_bullet);

}

