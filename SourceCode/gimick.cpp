#include "gimick.h"
#include "all.h"
#include "camera.h"
#include "hit_check.h"
#include "enemy.h"
#include "player.h"
#include "strong_enemy.h"
#include "heal.h"
#include "sound.h"


Sprite* spr_gimick = nullptr;
Sprite* spr_bonfire = nullptr;
Sprite* spr_kagari = nullptr;
Sprite* spr_break = nullptr;

bool stage_clear;
bool barrier_clack;
int clack_timer;
int clack_count;


gimick_data gimick[GIMICK_MAX];

void gimick_init()
{
	spr_gimick = sprite_load(L"Data/images/barrier.png");
	spr_bonfire = sprite_load(L"Data/images/bonfire.png");   //壊れたバリア用にあらかじめ作っておく
	spr_kagari = sprite_load(L"Data/images/kagari.png"); //
	spr_break = sprite_load(L"Data/images/バリアブレイクエフェクト.png"); 

	VECTOR2 gimick_start_pos[GIMICK_MAX]//座標がそれぞれ違うから0～3番目までをここで管理してみた
		//これfor文なのに座標のかぶりがないぞ！すげえ
	{
		{GIMICK_POS_X_1, GIMICK_POS_Y_1},
		{GIMICK_POS_X_2, GIMICK_POS_Y_2},
		{GIMICK_POS_X_3, GIMICK_POS_Y_3},
		{GIMICK_POS_X_4, GIMICK_POS_Y_4}
	};
	for (int i = 0; i < GIMICK_MAX; i++)
	{
		gimick[i].pos = gimick_start_pos[i];
		gimick[i].screen = { 0.0f, 0.0f };
		gimick[i].circle = 128.0f;
		gimick[i].barrier_break_check = false;
		gimick[i].anime_frame = 0;
		gimick[i].anime_timer = 0;
		gimick[i].clack_check = false;
	}
	    stage_clear = false;
}

void gimick_update()
{	
	for (int g = 0; g < GIMICK_MAX; g++)//2重for文にしてあげると全gimickがそれぞれ全enemyと反応するようになる。
	{
		if (gimick[g].barrier_break_check == true && gimick[g].clack_check == false)
		{
			clack_timer++;
			if (clack_timer % 6 == 0)//6か20
			{
				clack_timer = 0;
				clack_count += 1;
				gimick[g].clack_tex_pos_x = clack_count * 256;
			}
			if (clack_count == 6)
			{
				clack_count = 0;
				clack_timer = 0;
				gimick[g].clack_check = true;
			}

		}
		for (int e = 0; e < ENEMY_MAX; e++)
		{
			if (hit_check(gimick[g].pos.x, gimick[g].pos.y, gimick[g].circle * 0.5f,
						  enemy[e].pos.x, enemy[e].pos.y, NORMAL_ENEMY_HITBOX * 0.5f) &&
						  enemy[e].attack && !gimick[g].barrier_break_check)//もし突進中の敵とギミックのバリアが当たったら
			{
				heal_check = true;
				music::play(BARRIER_BREAK);
				gimick[g].barrier_break_check = true;
				if(player_hp > 0)
				{
					music::play(HEAL);
					player_hp += PLAYER_HEEL;
				}
			}
		}

		if (hit_check(gimick[g].pos.x, gimick[g].pos.y, gimick[g].circle * 0.5f,
			strong_enemy.pos.x, strong_enemy.pos.y, STRONG_ENEMY_W * 0.5f) &&
			strong_enemy.attack && !gimick[g].barrier_break_check)//もし突進中の敵とギミックのバリアが当たったら
		{
			heal_check = true;
			music::play(BARRIER_BREAK);
			gimick[g].barrier_break_check = true;
			if (player_hp > 0)
			{
				music::play(HEAL);
				player_hp += PLAYER_HEEL;
			}
		}


	}
	
		if (gimick[0].barrier_break_check &&
			gimick[1].barrier_break_check &&
			gimick[2].barrier_break_check &&
			gimick[3].barrier_break_check)
		{
			stage_clear = true;
		}
	
}

void gimick_render()//ギミックの描画
{
	for (int i = 0; i < GIMICK_MAX; i++)
	{
		gimick[i].screen.x = gimick[i].pos.x - camera_pos.x + SCREEN_W * 0.5f;
		gimick[i].screen.y = gimick[i].pos.y - camera_pos.y + SCREEN_H * 0.5f;
		if (gimick[i].barrier_break_check)
		{
			sprite_render(spr_bonfire,
				gimick[i].screen.x, gimick[i].screen.y, 1.0f, 1.0f, 0, 0, 256, 256, 128, 128);
			sprite_render(spr_break, gimick[i].screen.x, gimick[i].screen.y, 1.0f, 1.0f, gimick[i].clack_tex_pos_x, 0.0f, 256, 256, 128, 128);
		}
		else
		{
			sprite_render(spr_kagari,
				gimick[i].screen.x, gimick[i].screen.y, 1.0f, 1.0f, 0, 0, 256, 256, 128, 128);

			sprite_render(spr_gimick,
				gimick[i].screen.x, gimick[i].screen.y, 1.0f, 1.0f, 0, 0, 256, 256, 128, 128);
		}
		
	}
	
}

void gimick_deinit()
{
	safe_delete(spr_gimick);
	safe_delete(spr_bonfire);
	safe_delete(spr_kagari);
	safe_delete(spr_break);
}
