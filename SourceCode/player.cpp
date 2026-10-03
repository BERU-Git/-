#include "all.h"
#include "camera.h"
#include "hit_check.h"
#include "enemy.h"
#include "strong_enemy.h"
Sprite* spr_player;
VECTOR2 screen;
VECTOR2 player_pos;
VECTOR2 player_speed;
int player_hp;
int player_invincible_time;
int player_render_posx;
int player_render_posy;
int player_effect_timer;
int player_direction;
float length;
bool player_hit;


void clamp_position(float& pos_x,float& pos_y,float texsize_x, float texsize_y,
	                float& speed_x,float& speed_y)
{
	if (pos_x <= texsize_x * 0.5f)
	{
		pos_x = texsize_x * 0.5f;
		speed_x = 0;
	}
	else if (pos_x >= WORLD_W - texsize_x * 0.5f)
	{
		pos_x = WORLD_W - texsize_x * 0.5f;
		speed_x = 0;
	}

	if (pos_y <= -texsize_y * 0.3f)
	{
		pos_y = -texsize_y * 0.3f;
		speed_y = 0;
	}
	else if (pos_y >= WORLD_H - texsize_y * 0.5f)
	{
		pos_y = WORLD_H - texsize_y * 0.5f;
		speed_y = 0;
	}
}
void player_init()
{
	spr_player = sprite_load(L"Data/images/player.png");
	
	player_pos.x = WORLD_W * 0.5f;
	player_pos.y = WORLD_H * 0.5f;
	
	player_speed.x = 0;
	player_speed.y = 0;

	player_render_posx = 0;
	player_render_posy = 0;

	player_hp = PLAYER_HP;

	player_hit = false;

	player_invincible_time = 0;

	player_direction = 0;
}

void player_update()
{
	
	//プレイヤー操作
	//左
	if (STATE(0) & PAD_LEFT)
	{
		player_speed.x -= ACCELERATION;
	}
	//右
	else if (STATE(0) & PAD_RIGHT)
	{
		player_speed.x += ACCELERATION;
	}
	else
	{
		player_speed.x *= DECELERATION;
		if (fabs(player_speed.x) <= 0.01)
		{
			player_speed.x = 0;
		}

	}

	//下
	if (STATE(0) & PAD_DOWN)
	{
		player_speed.y += ACCELERATION;
	}
	//上
	else if (STATE(0) & PAD_UP)
	{
		player_speed.y -= ACCELERATION;
	}	
	else
	{
		player_speed.y *= DECELERATION;
		if (fabs(player_speed.y) <= 0.01)
		{
			player_speed.y = 0;
		}
	}

	//速度上限
	if (player_speed.x >= MAX_SPEED)
	{
		player_speed.x = MAX_SPEED;
	}
	if (player_speed.y >= MAX_SPEED)
	{
		player_speed.y = MAX_SPEED;
	}
	//速度下限
	if (player_speed.x <= MIN_SPEED)
	{
		player_speed.x = MIN_SPEED;
	}
	if (player_speed.y <= MIN_SPEED)
	{
		player_speed.y = MIN_SPEED;
	}

	//最高速度制限
	length = sqrtf(
		player_speed.x * player_speed.x +
		player_speed.y * player_speed.y
	);

	if (length > MAX_SPEED)
	{
		// 正規化
		player_speed.x /= length;
		player_speed.y /= length;

		// 最大速度を掛ける
		player_speed.x *= MAX_SPEED;
		player_speed.y *= MAX_SPEED;
	}

	//プレイヤーの移動
	player_pos.x += player_speed.x;
	player_pos.y += player_speed.y;

	//移動範囲制限
	clamp_position(player_pos.x, player_pos.y, PLAYER_W, PLAYER_H,
		player_speed.x, player_speed.y);

	//プレイヤーのHP処理
	for(int i = 0; i < ENEMY_MAX ; i++ )
	{
		if (hit_check(player_pos.x, player_pos.y, PLAYER_W,
			enemy[i].pos.x, enemy[i].pos.y, NORMAL_ENEMY_HITBOX) && !player_hit)
		{
			player_hit = true;
			player_hp -= 1;
		}
	}

	if (hit_check(player_pos.x, player_pos.y, PLAYER_W,
		strong_enemy.pos.x, strong_enemy.pos.y, STRONG_ENEMY_W) && !player_hit)
	{
		player_hit = true;
		player_hp -= 2;

	}

	//無敵時間
	if (player_hit)
	{
		player_invincible_time += 1;
		if (player_invincible_time >= 120)
		{
			player_hit = false;
			player_invincible_time = 0;
		}
	}


	//向きを更新
	if (player_speed.x < 0)
	{
		player_render_posy = 2;
		player_direction = 1;
	}
	else if (player_speed.x > 0)
	{
		player_render_posy = 1;
		player_direction = 0;
	}

	if (player_speed.y < 0)
	{
		if (player_direction == 1)
		{
			player_render_posy = 2;
		}
		else
		{
			player_render_posy = 1;
		}
	}
	else if (player_speed.y > 0)
	{
		if (player_direction == 0)
		{
			player_render_posy = 1;
		}
		else
		{
			player_render_posy = 2;
		}

	}


	//プレイヤーのエフェクト
	if (player_speed.x != 0 || player_speed.y != 0)
	{
	    player_effect_timer++;

		if(player_effect_timer % 6 == 0)
		{
			player_render_posx++;
			player_render_posx %= 6;
		}
	}
	else
	{
		player_render_posx = player_direction;
		player_render_posy = 0;
	}



}

void player_render()
{
	//プレイヤーのワールド座標をスクリーン座標に変換
	screen.x = player_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	screen.y = player_pos.y - camera_pos.y + SCREEN_H * 0.5f;

	sprite_render(spr_player, screen.x, screen.y,
		                      1,1,
						      PLAYER_W * player_render_posx, PLAYER_H * player_render_posy,
		                      PLAYER_W,PLAYER_H,
		                      PLAYER_W * 0.5f,PLAYER_H * 0.5f);
}

void player_deinit()
{
	safe_delete(spr_player);
}