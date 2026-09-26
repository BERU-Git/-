#include "all.h"
#include "camera.h"
Sprite* spr_player;
VECTOR2 screen;
VECTOR2 player_pos;
VECTOR2 player_speed;
int player_render_posx;
int player_render_posy;
int player_effect_timer;
int player_direction;


void player_init()
{
	spr_player = sprite_load(L"Data/images/player.png");
	
	player_pos.x = SCREEN_W * 0.5f;
	player_pos.y = SCREEN_H * 0.5f;
	
	player_speed.x = 0;
	player_speed.y = 0;

	player_render_posx = 0;
	player_render_posy = 0;

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
	//プレイヤーの移動
	player_pos.x += player_speed.x;
	player_pos.y += player_speed.y;

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