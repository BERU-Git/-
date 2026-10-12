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
	player_hp = heart.check;
}
void heart_render()
{
	sprite_render(spr_heart, 200, 10);
	/*if (heart.check >= 0)
	{
		sprite_render(spr_heart, 200, 10);
	}*/
}
void heart_deinit()
{

}