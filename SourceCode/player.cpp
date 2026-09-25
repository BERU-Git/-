#include "all.h"
Sprite* spr_player;
float player_posx;
float player_posy;

void player_init()
{
	spr_player = sprite_load(L"Data/images/player_01.png");
	player_posx = SCREEN_W * 0.5f;
	player_posy = SCREEN_H * 0.5f;
}

void player_update()
{
	if (STATE(0) & PAD_LEFT)
	{
		player_posx -= 10;
	}
	if (STATE(0) & PAD_RIGHT)
	{
		player_posx += 10;
	}
	if (STATE(0) & PAD_DOWN)
	{
		player_posy += 10;
	}
	if (STATE(0) & PAD_UP)
	{
		player_posy -= 10;
	}
}

void player_render()
{
	sprite_render(spr_player, player_posx, player_posy,
		                      1,1,
		                      0,0,
		                      PLAYER_W,PLAYER_H,
		                      PLAYER_W * 0.5f,PLAYER_H * 0.5f);
}

void player_deinit()
{
	safe_delete(spr_player);
}