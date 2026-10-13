#include "enemy.h"
#include "all.h"
#include "camera.h"
#include "hit_check.h"
#include "player.h"
#include "attack_line.h"
#include "boss.h"

Sprite* spr_strong_enemy;
Sprite* spr_boss_strong_enemy;
enemy_data strong_enemy;
float strong_tex_pos_x;
int strong_timer;
int strong_count;
int strong_direction;
int boss_attack_loop;

void strong_enemy_init()
{
	spr_strong_enemy = sprite_load(L"Data/Images/strong_enemy.png");
	spr_boss_strong_enemy = sprite_load(L"Data/Images/boss_strong_enemy.png");

	strong_enemy = {};
	strong_tex_pos_x = 0.0f;
	strong_timer = 0;
	strong_count = 0;
	strong_direction = 0;

	strong_enemy.jast_avoid_entered = false;
	strong_enemy.jast_avoid_done = false;
	strong_enemy.jast_avoid_hit = false;

	bool can_spawn = false;

	while(!can_spawn)
	{
		strong_enemy.pos.x = STRONG_ENEMY_W + rand() % WORLD_W - STRONG_ENEMY_W * 2.0f;
		strong_enemy.pos.y = STRONG_ENEMY_H + rand() % WORLD_H - STRONG_ENEMY_H * 2.0f;

		can_spawn = true;

		if (hit_check(
			player_pos.x, player_pos.y, SCREEN_H * 0.5f,
			strong_enemy.pos.x, strong_enemy.pos.y, STRONG_ENEMY_W * 0.5f))
		{
			can_spawn = false;
			break;
		}
	}

	strong_enemy.speed.x = STRONG_ENEMY_SPEED;
	strong_enemy.speed.y = STRONG_ENEMY_SPEED;
	
	strong_enemy.attack = false;
	strong_enemy.charge = false;


	strong_enemy.state = ENEMY_CHASE;
}
void strong_enemy_update()
{
	if (player_pos.x > strong_enemy.pos.x)
	{
		strong_direction = 1;
	}
	else
	{
		strong_direction = -1;
	}
	strong_timer++;
	if (strong_timer % 6 == 0)
	{
		strong_timer = 0;
		strong_tex_pos_x = strong_count *256;
		strong_count += 1;
	}
	if (strong_count == 4)
	{
		strong_count = 0;
		strong_tex_pos_x = 0;
	}
	switch (strong_enemy.state)
	{
		//通常追跡
	case ENEMY_CHASE:
	if(!jast_avoid_check)
	{
		enemy_chase(player_pos.x, player_pos.y, strong_enemy.pos.x, strong_enemy.pos.y,
			strong_enemy.angle, strong_enemy.chase.x, strong_enemy.chase.y);
	}
	else
	{
		enemy_chase(decoy_totem_pos.x, decoy_totem_pos.y, strong_enemy.pos.x, strong_enemy.pos.y,
			strong_enemy.angle, strong_enemy.chase.x, strong_enemy.chase.y);

	}
	strong_enemy.pos.x += strong_enemy.speed.x * strong_enemy.chase.x;
	strong_enemy.pos.y += strong_enemy.speed.y * strong_enemy.chase.y;


	if (hit_check(player_pos.x, player_pos.y, CHARGE_CHECK_W * 0.5f,
			strong_enemy.pos.x, strong_enemy.pos.y, STRONG_ENEMY_W * 0.5f) && !jast_avoid_check)
		{
			strong_enemy.state = ENEMY_CHARGE_PREP;
		}

		break;	

		//突撃準備
	case ENEMY_CHARGE_PREP:
		strong_enemy.charge = true;
		strong_enemy.charge_prep_timer++;

		enemy_chase(player_pos.x, player_pos.y, strong_enemy.pos.x, strong_enemy.pos.y,
			strong_enemy.angle, strong_enemy.chase.x, strong_enemy.chase.y);

		strong_attack_line.pos.x = strong_enemy.pos.x;
		strong_attack_line.pos.y = strong_enemy.pos.y;

		if (strong_enemy.charge_prep_timer >= CHARGE_PREP_TIME)
		{
			strong_enemy.charge_prep_timer = 0.0f;
			strong_enemy.state = ENEMY_CHARGE;
		}
		break;
		//突進
	case ENEMY_CHARGE:
		strong_enemy.attack = true;
		strong_enemy.charge_timer++;

		strong_enemy.pos.x += strong_enemy.chase.x * STRONG_CHARGE_SPEED;
		strong_enemy.pos.y += strong_enemy.chase.y * STRONG_CHARGE_SPEED;

		//ジャスト回避判定に入って出るまでの検知
		if (!strong_enemy.jast_avoid_done)
		{
			if (hit_check(player_pos.x, player_pos.y, PLAYER_W * 0.5f,
				strong_enemy.pos.x, strong_enemy.pos.y, 320 * 0.5f))
			{
				strong_enemy.jast_avoid_entered = true;
			}
			else if (strong_enemy.jast_avoid_entered)
			{
				strong_enemy.jast_avoid_done = true;
			}
		}
		//ジャスト回避中に攻撃を食らったかどうか
		if (strong_enemy.jast_avoid_entered && player_hit)
		{
			strong_enemy.jast_avoid_hit = true;
		}


		//state遷移
		if (strong_enemy.charge_timer >= STRONG_CHARGE_TIME || 
			strong_enemy.pos.x <= STRONG_ENEMY_W * 0.5f ||
			strong_enemy.pos.x >= WORLD_W - STRONG_ENEMY_W * 0.5f ||
			strong_enemy.pos.y <= STRONG_ENEMY_H * 0.5f ||
			strong_enemy.pos.y >= WORLD_H - STRONG_ENEMY_H * 0.5f)
		{
			strong_enemy.charge = false;
			strong_enemy.attack = false;

			strong_enemy.jast_avoid_entered = false;
			strong_enemy.jast_avoid_done = false;
			strong_enemy.jast_avoid_hit = false;

			strong_enemy.charge_timer = 0.0f;
			strong_enemy.state = ENEMY_CHASE;
		}

		break;
	}

}

void boss_strong_enemy_init()
{
	spr_boss_strong_enemy = sprite_load(L"Data/Images/boss_strong_enemy.png");

	strong_enemy = {};

	strong_enemy.pos.x = player_pos.x;
	strong_enemy.pos.y = player_pos.y - SCREEN_W;

	strong_tex_pos_x = 0.0f;
	strong_timer = 0;
	strong_count = 0;
	strong_direction = 1;

	boss_attack_loop = 0;

	strong_enemy.charge_timer = 0;

	strong_enemy.charge = true;

	strong_enemy.speed.x = STRONG_CHARGE_SPEED;
	strong_enemy.speed.y = STRONG_CHARGE_SPEED;

	enemy_chase(player_pos.x, player_pos.y, strong_enemy.pos.x, strong_enemy.pos.y,
		strong_enemy.angle, strong_enemy.chase.x, strong_enemy.chase.y);

	strong_attack_line.pos.x = strong_enemy.pos.x;
	strong_attack_line.pos.y = strong_enemy.pos.y;

	
}

void boss_strong_enemy_update()
{
	strong_enemy.charge_timer++;

	strong_enemy.pos.x += strong_enemy.chase.x * STRONG_CHARGE_SPEED;
	strong_enemy.pos.y += strong_enemy.chase.y * STRONG_CHARGE_SPEED;

	if (strong_enemy.charge_timer >= STRONG_CHARGE_TIME)
	{
		boss_attack_loop++;
		if(boss_attack_loop % 2 == 0)
		{

			strong_enemy.charge_timer = 0;

			strong_enemy.pos.x = player_pos.x;
			strong_enemy.pos.y = player_pos.y - SCREEN_H ;

			enemy_chase(player_pos.x, player_pos.y, strong_enemy.pos.x, strong_enemy.pos.y,
				strong_enemy.angle, strong_enemy.chase.x, strong_enemy.chase.y);

			strong_attack_line.pos.x = strong_enemy.pos.x;
			strong_attack_line.pos.y = strong_enemy.pos.y;

		}
		else
		{

			strong_enemy.charge_timer = 0;

			strong_enemy.pos.x = player_pos.x + SCREEN_W;
			strong_enemy.pos.y = player_pos.y;

			enemy_chase(player_pos.x, player_pos.y, strong_enemy.pos.x, strong_enemy.pos.y,
				strong_enemy.angle, strong_enemy.chase.x, strong_enemy.chase.y);

			strong_attack_line.pos.x = strong_enemy.pos.x;
			strong_attack_line.pos.y = strong_enemy.pos.y;

		}
	}


	//アニメーション
	if (player_pos.x > strong_enemy.pos.x)
	{
		strong_direction = 1;
	}
	else
	{
		strong_direction = -1;
	}
	strong_timer++;
	if (strong_timer % 6 == 0)
	{
		strong_timer = 0;
		strong_tex_pos_x = strong_count * 256;
		strong_count += 1;
	}
	if (strong_count == 4)
	{
		strong_count = 0;
		strong_tex_pos_x = 0;
	}


}




void strong_enemy_render()
{
	strong_enemy.screen.x = strong_enemy.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	strong_enemy.screen.y = strong_enemy.pos.y - camera_pos.y + SCREEN_H * 0.5f;
	if(!boss_stage)
	{
		sprite_render(spr_strong_enemy, strong_enemy.screen.x, strong_enemy.screen.y,
			2 * strong_direction, 2,
			strong_tex_pos_x, 0,
			STRONG_ENEMY_W, STRONG_ENEMY_H,
			STRONG_ENEMY_W * 0.5f, STRONG_ENEMY_H * 0.5f);
	}
	if(boss_stage)
	{
		sprite_render(spr_boss_strong_enemy, strong_enemy.screen.x, strong_enemy.screen.y,
			2 * strong_direction, 2,
			strong_tex_pos_x, 0,
			STRONG_ENEMY_W, STRONG_ENEMY_H,
			STRONG_ENEMY_W * 0.5f, STRONG_ENEMY_H * 0.5f);
	}

}
void strong_enemy_deinit()
{
	strong_enemy = {};
	safe_delete(spr_strong_enemy);
	safe_delete(spr_boss_strong_enemy);
}
