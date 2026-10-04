#include "gimick.h"
#include "all.h"
#include "camera.h"
#include "hit_check.h"
#include "enemy.h"
#include "strong_enemy.h"


Sprite* spr_gimick = nullptr;
Sprite* spr_bonfire = nullptr;
Sprite* spr_kagari = nullptr;

gimick_data gimick[GIMICK_MAX];

void gimick_init()
{
	spr_gimick = sprite_load(L"Data/images/barrier.png");
	spr_bonfire = sprite_load(L"Data/images/bonfire.png");   //壊れたバリア用にあらかじめ作っておく
	spr_kagari = sprite_load(L"Data/images/kagari.png"); //

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
	}

}

void gimick_update()
{
	
	
	for (int g = 0; g < GIMICK_MAX; g++)//2重for文にしてあげると全gimickがそれぞれ全enemyと反応するようになる。
	{
		for (int e = 0; e < ENEMY_MAX; e++)
		{
			if (hit_check(gimick[g].pos.x, gimick[g].pos.y, gimick[g].circle * 0.5f,
						  enemy[e].pos.x, enemy[e].pos.y, NORMAL_ENEMY_HITBOX * 0.5f) &&
						  enemy[e].attack)//もし突進中の敵とギミックのバリアが当たったら
			{
				gimick[g].barrier_break_check = true;
			}
		}

		if (hit_check(gimick[g].pos.x, gimick[g].pos.y, gimick[g].circle * 0.5f,
			strong_enemy.pos.x, strong_enemy.pos.y, STRONG_ENEMY_W * 0.5f) &&
			strong_enemy.attack)//もし突進中の敵とギミックのバリアが当たったら
		{
			gimick[g].barrier_break_check = true;
		}


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
}
