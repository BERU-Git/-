#include "all.h"
#include "camera.h"
Sprite* spr_player;
VECTOR2 player_pos;


void player_init()
{
	spr_player = sprite_load(L"Data/images/player_01.png");
	player_pos.x = SCREEN_W * 0.5f;
	player_pos.y = SCREEN_H * 0.5f;
}

void player_update()
{
	if (STATE(0) & PAD_LEFT)
	{
		player_pos.x -= 8;
	}
	if (STATE(0) & PAD_RIGHT)
	{
		player_pos.x += 8;
	}
	if (STATE(0) & PAD_DOWN)
	{
		player_pos.y += 8;
	}
	if (STATE(0) & PAD_UP)
	{
		player_pos.y -= 8;
	}

	debug::setString("player_x\r,player_y\r", player_pos.x, player_pos.y);

}

void player_render()
{
	sprite_render(spr_player, screen.x, screen.y,
		                      1,1,
		                      0,0,
		                      PLAYER_W,PLAYER_H,
		                      PLAYER_W * 0.5f,PLAYER_H * 0.5f);
}

void player_deinit()
{
	safe_delete(spr_player);
}