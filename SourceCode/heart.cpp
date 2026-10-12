#include "heart.h"
#include "all.h"
#include "player.h"

Sprite* spr_heart = nullptr;
Sprite* spr_emptiness = nullptr;
heart_data heart;

void heart_init()
{
	player_init();
	spr_heart = sprite_load(L"Data/images/満たされているハート.png");
	spr_emptiness = sprite_load(L"Data/images/空ハート.png");
}
void heart_update()
{
	heart.check = player_hp;
}
void heart_render()
{
	if (player_hp >= 10)
	{
		sprite_render(spr_heart, 650, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 650, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 9)
	{
		sprite_render(spr_heart, 580, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 580, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 8)
	{
		sprite_render(spr_heart, 510, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 510, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 7)
	{
		sprite_render(spr_heart, 440, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 440, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 6)
	{
		sprite_render(spr_heart, 370, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 370, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 5)
	{
		sprite_render(spr_heart, 300, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 300, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 4)
	{
		sprite_render(spr_heart, 230, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 230, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 3)
	{
		sprite_render(spr_heart, 160, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 160, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 2)
	{
		sprite_render(spr_heart, 90, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 90, 10, 2.5f, 2.5f);
	}
	if (heart.check >= 1)
	{
		sprite_render(spr_heart, 20, 10, 2.5f, 2.5f);
	}
	else
	{
		sprite_render(spr_emptiness, 20, 10, 2.5f, 2.5f);
	}
	
	
	
	
	
	
	
	
	/*if (heart.check >= 0)
	{
		sprite_render(spr_heart, 200, 10);
	}*/
}
void heart_deinit()
{

}