#include "all.h"
#include "boss.h"
#include "player.h"
#include "camera.h"
#include "enemy.h"
#include "strong_enemy.h"
#include "range_enemy.h"
#include "troll.h"
#include "sound.h"
#include "hit_check.h"
#include "exprotion.h"

Sprite* spr_boss;
boss_data boss;

Sprite* spr_boss_right;
boss_data boss_right;

Sprite* spr_boss_left;
boss_data boss_left;

Sprite* spr_smoke;

boss_attack state;

bool boss_stage;
bool last_attack;
int boss_state_timer;

int right_timer = 0;//右手アニメーション用
int right_count = 0;
float right_tex_pos_x = 0.0f;
int left_timer = 0;//左手アニメーション用
int left_count = 0;
float left_tex_pos_x = 0.0f;
int center_timer = 0;//センターアニメーション用
int center_count = 0;
float center_tex_pos_x = 0.0f;

float clamp(float value,float min,float max)
{
	if (value < min)
	{
		return min;
	}
	if (value > max)
	{
		return max;
	}
	return value;
}



void boss_init()
{
	
	enemy_init();
	spr_boss = sprite_load(L"Data/Images/boss.png");
	spr_boss_right = sprite_load(L"Data/Images/boss_right.png");
	spr_boss_left = sprite_load(L"Data/Images/boss_left.png");
	spr_smoke = sprite_load(L"Data/Images/煙エフェクト.png");

	boss.knock_down = false;
	boss_right.knock_down = false;
	boss_left.knock_down = false;

	boss_state_timer = 0;

	boss.pos.x = player_pos.x;
	boss.pos.y = player_pos.y - SCREEN_H * 0.5f - BOSS_H * 0.5f;

	boss_right.pos.x = player_pos.x - BOSS_HAND_POS;
	boss_right.pos.y = player_pos.y - SCREEN_H * 0.5f - BOSS_H * 0.5f;

	boss_left.pos.x = player_pos.x + BOSS_HAND_POS;
	boss_left.pos.y = player_pos.y - SCREEN_H * 0.5f - BOSS_H * 0.5f;

	boss.transparent = 1.0f;
	boss_right.transparent = 1.0f;
	boss_left.transparent = 1.0f;
}


void boss_update_init()
{
	boss.pos.y += BOSS_H / 260;
	boss_right.pos.y += BOSS_H / 260;
	boss_left.pos.y += BOSS_H / 260;

}

void boss_update()
{
	
	if (boss_right.knock_down == true)//右手アニメーション管理
	{
		right_timer++;
		if (right_timer % 6 == 0)
		{
			right_count += 1;
			right_tex_pos_x = right_count * 340;
			right_timer = 0;
		}
		if (right_count == 4)
		{
			right_timer = 0;
			right_count = 0;
			right_tex_pos_x = 0.0f;
		}
	}
	if (boss_left.knock_down == true)//左手アニメーション管理
	{
		left_timer++;
		if (left_timer % 6 == 0)
		{
			left_count += 1;
			left_tex_pos_x = right_count * 340;
			left_timer = 0;
		}
		if (left_count == 4)
		{
			left_timer = 0;
			left_count = 0;
			left_tex_pos_x = 0.0f;
		}
	}
	if (boss.knock_down == true)//センターアニメーション管理
	{
		center_timer++;
		if (center_timer % 6 == 0)
		{
			center_count += 1;
			center_tex_pos_x = right_count * 340;
			center_timer = 0;
		}
		if (center_count == 4)
		{
			center_timer = 0;
			center_count = 0;
			center_tex_pos_x = 0.0f;
		}
	}
	//ボスの移動
	boss.pos.x += (player_pos.x - boss.pos.x) * 0.05f;

	boss.screen_center = player_pos.y - BOSS_CENTER_H; 
	boss.pos.y += (boss.screen_center - boss.pos.y) * 0.1f;

	//ボスの右手の移動
	boss_right.pos.x += ((boss.pos.x - BOSS_HAND_POS) - boss_right.pos.x) * 0.05f;

	boss_right.screen_center = player_pos.y - BOSS_CENTER_H;
	boss_right.pos.y += (boss_right.screen_center - boss_right.pos.y) * 0.1f;

	//ボスの左手の移動
	boss_left.pos.x += ((boss.pos.x + BOSS_HAND_POS) - boss_left.pos.x) * 0.05f;

	boss_left.screen_center = player_pos.y - BOSS_CENTER_H;
	boss_left.pos.y += (boss_left.screen_center - boss_left.pos.y) * 0.1f;

	//ボスの行動範囲制限
	boss.pos.x = clamp(boss.pos.x,
	    	           player_pos.x - SCREEN_W * 0.5f,
	    	           player_pos.x + SCREEN_W * 0.5f);

	boss.pos.y = clamp(boss.pos.y,
		               player_pos.y - SCREEN_H * 0.5f, 
		               (player_pos.y - SCREEN_H * 0.5f) + BOSS_H * 0.5f);

	//ボスの右手の行動範囲制限
	boss_right.pos.x = clamp(boss_right.pos.x,
		                    (boss.pos.x - BOSS_HAND_POS) - 100,
		                    (boss.pos.x - BOSS_HAND_POS) + 100);

	boss_right.pos.y = clamp(boss_right.pos.y,
		                     player_pos.y - SCREEN_H * 0.5f,
		                    (player_pos.y - SCREEN_H * 0.5f) + BOSS_H * 0.5f);

	//ボスの左手の行動範囲制限
	boss_left.pos.x = clamp(boss_left.pos.x,
		                   (boss.pos.x + BOSS_HAND_POS) - 100,
		                   (boss.pos.x + BOSS_HAND_POS) + 100);

	boss_left.pos.y = clamp(boss_left.pos.y,
	 	                    player_pos.y - SCREEN_H * 0.5f,
	 	                    (player_pos.y - SCREEN_H * 0.5f) + BOSS_H * 0.5f);
	
	//デコイの当たり判定
	if (hit_check(boss.pos.x, boss.pos.y, BOSS_HITBOX * 0.5f ,
		decoy_totem_pos.x, decoy_totem_pos.y, DECOY_TOTEM_EXPLOSION * 0.5f) && jast_avoid_effect_check
		&& !boss.knock_down && state != NORMAL_ENEMY)
	{
		boss.knock_down = true;
	}
	else if (hit_check(boss_right.pos.x, boss_right.pos.y, BOSS_HAND_HITBOX * 0.5f,
		decoy_totem_pos.x, decoy_totem_pos.y, DECOY_TOTEM_EXPLOSION * 0.5f) && jast_avoid_effect_check && !boss_right.knock_down)
	{
		boss_right.knock_down = true;
	}
	else if (hit_check(boss_left.pos.x, boss_left.pos.y, BOSS_HAND_HITBOX * 0.5f,
		decoy_totem_pos.x, decoy_totem_pos.y, DECOY_TOTEM_EXPLOSION * 0.5f) && jast_avoid_effect_check && !boss_left.knock_down)
	{
		boss_left.knock_down = true;
	}

	//ボスの当たり判定
	if (hit_check(boss.pos.x, boss.pos.y, BOSS_HITBOX * 0.5f ,
		strong_enemy.pos.x, strong_enemy.pos.y, STRONG_ENEMY_W * 0.5f) && strong_enemy.attack)
	{
		boss.knock_down = true;
	}
	for(int i = 0; i < ENEMY_MAX ; i++ )
	{
		if (hit_check(boss_right.pos.x, boss_right.pos.y, BOSS_HAND_HITBOX * 0.5f,
			enemy[i].pos.x, enemy[i].pos.y, NORMAL_ENEMY_HITBOX * 0.5f) && enemy[i].attack)
		{
			boss_right.knock_down = true;
			
		}

		if (hit_check(boss_left.pos.x, boss_left.pos.y, BOSS_HAND_HITBOX * 0.5f,
			enemy[i].pos.x, enemy[i].pos.y, NORMAL_ENEMY_HITBOX * 0.5f) && enemy[i].attack)
		{
			boss_left.knock_down = true;
		}

	}




	//攻撃ウェーブ処理
	switch (state)
	{
	case NORMAL_ENEMY:
		//state = LAST_ATTACK_INIT;
		enemy_update();
		if (boss_right.knock_down && boss_left.knock_down)
		{
			music::play(BOSS_ROAR);
			state = STRONG_ENEMY_INIT;
			enemy_deinit();
			screen_shake_init(240);
		}
		break;

	case STRONG_ENEMY_INIT:
		boss_state_timer++;
		screen_shake(15);
		if (boss_state_timer >= 180)
		{
			troll_init();
			range_enemy_init();
			strong_enemy_init();
			state = STRONG_ENEMY;
			boss_state_timer = 0;
		}
		break;

	case STRONG_ENEMY:
		troll_update();
		strong_enemy_update();
		range_enemy_update();
		if (boss.knock_down)
		{
			music::play(BOSS_ROAR);
			troll_deinit();
			strong_enemy_deinit();
			range_enemy_deinit();

			screen_shake_init(240);
			state = MIX_ENEMY_INIT;
			boss_right.knock_down = false;
			boss_left.knock_down = false;
			boss.knock_down = false;
		}
		break;

	case MIX_ENEMY_INIT:
		boss_state_timer++;
		screen_shake(15);
		if (boss_state_timer >= 180)
		{
			troll_init();
			range_enemy_init();
			strong_enemy_init();
			enemy_init();
			state = MIX_ENEMY;
			boss_state_timer = 0;
		}
		break;

	case MIX_ENEMY:
		enemy_update();
		troll_update();
		strong_enemy_update();
		range_enemy_update();

		if (boss_right.knock_down && boss_left.knock_down && boss.knock_down)
		{
			music::play(BOSS_ROAR);
			screen_shake_init(240);
			state = LAST_ATTACK_INIT;
			troll_deinit();
			enemy_deinit();
			strong_enemy_deinit();
			range_enemy_deinit();
		}
		break;

	case LAST_ATTACK_INIT:
		boss_state_timer++;
		screen_shake(15);

		strong_enemy.charge = false;

		for (int i = 0; i < ENEMY_MAX; i++)
		{
			enemy[i].charge = false;
		}

		if (boss_state_timer >= 180)
		{
			last_attack = true;
			boss_enemy_init();
			boss_strong_enemy_init();
			state = LAST_ATTACK;
			boss_state_timer = 0;
		}
		break;

	case LAST_ATTACK:

			boss_enemy_update();
			boss_strong_enemy_update();
			break;
	case BOSS_END:

		screen_shake(25);
		boss.transparent -= 0.00333f;
		boss_right.transparent -= 0.00333f;
		boss_left.transparent -= 0.00333f;
		if (boss.transparent <= 0)
		{
			nextScene = SCENE_RESULT;
		}
		break;

	}

}


void boss_render()
{
	boss.screen.x = boss.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	boss.screen.y = boss.pos.y - camera_pos.y + SCREEN_H * 0.5f;

	boss_right.screen.x = boss_right.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	boss_right.screen.y = boss_right.pos.y - camera_pos.y + SCREEN_H * 0.5f;

	boss_left.screen.x = boss_left.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	boss_left.screen.y = boss_left.pos.y - camera_pos.y + SCREEN_H * 0.5f;

	switch (state)
	{
	case NORMAL_ENEMY:
		enemy_render();
		break;

	case STRONG_ENEMY:
		troll_render();
		strong_enemy_render();
		range_enemy_render();
		break;


	case MIX_ENEMY:
		enemy_render();
		troll_render();
		strong_enemy_render();
		range_enemy_render();

		break;

	case LAST_ATTACK:
		enemy_render();
		strong_enemy_render();

		break;

	}

	sprite_render(spr_boss, boss.screen.x, boss.screen.y,
		1,1,
		0,0,
		BOSS_W,BOSS_H,
		BOSS_W * 0.5f,BOSS_H * 0.5f,
		0,
		1.0f, 1.0f, 1.0f, boss.transparent);
	if (boss.knock_down == true)
	{
		sprite_render(spr_smoke,
			boss.screen.x, boss.screen.y,
			1.0f, 1.0f,
			center_tex_pos_x, 0.0f,
			340.0f, 340.0f,
			170.0f, 170.0f,
			0,
			1.0f,1.0f,1.0f,boss.transparent
		);
	}


	sprite_render(spr_boss_left, boss_left.screen.x, boss_left.screen.y,
		1,1,
		0,0,
		BOSS_HAND_W, BOSS_HAND_H,
		BOSS_HAND_W * 0.5f, BOSS_HAND_H * 0.5f,
		0,
		1.0f, 1.0f, 1.0f, boss_left.transparent);
	if (boss_left.knock_down == true)//左手がknockDownしたら煙の描画
	{
		sprite_render(spr_smoke,
			boss_left.screen.x, boss_left.screen.y, 
			1.0f, 1.0f,
			left_tex_pos_x, 0.0f,
			340.0f, 340.0f,
			170.0f, 170.0f,
			0,
			1.0f, 1.0f, 1.0f, boss_left.transparent

		);
	}


	sprite_render(spr_boss_right, boss_right.screen.x, boss_right.screen.y,
		1,1,
		0,0,
		BOSS_HAND_W, BOSS_HAND_H,
		BOSS_HAND_W * 0.5f, BOSS_HAND_H * 0.5f,
		0,
		1.0f,1.0f,1.0f, boss_right.transparent);
	if (boss_right.knock_down == true)//右手がknockDownしたら煙の描画
	{
		sprite_render(spr_smoke,
			boss_right.screen.x, boss_right.screen.y, 
			1.0f, 1.0f,
			right_tex_pos_x, 0.0f,
			340.0f, 340.0f,
			170.0f, 170.0f,
			0,
			1.0f, 1.0f, 1.0f, boss_right.transparent
			);
	}
	
}


void boss_deinit()
{
	enemy_deinit();
	strong_enemy_deinit();
	range_enemy_deinit();
	safe_delete(spr_boss);
	safe_delete(spr_boss_right);
	safe_delete(spr_boss_left);

}

