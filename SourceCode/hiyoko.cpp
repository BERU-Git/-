#include "hiyoko.h"
#include "all.h"
#include "player.h"
#include "camera.h"


Sprite* spr_hiyoko = nullptr;
int hiyoko_timer = 0;
int hiyoko_count = 0;
int hiyoko_tex_pos_x = 0;
bool hiyoko_check = false;
VECTOR2 screen_hiyoko;

void hiyoko_init()
{
	spr_hiyoko = sprite_load(L"Data/Images/ƒqƒˆƒR.png");
}

void hiyoko_update()
{
	if (hiyoko_check == true)
	{
		hiyoko_timer++;
		if (hiyoko_timer % 6 == 0)
		{
			hiyoko_count += 1;
			hiyoko_tex_pos_x = 64 * hiyoko_count;
			hiyoko_timer = 0;
		}
		if (hiyoko_count == 4)
		{
			hiyoko_count = 0;
			hiyoko_tex_pos_x = 0;
			hiyoko_timer = 0;
			hiyoko_check = false;
		}
	}
}

void hiyoko_render()
{
	screen_hiyoko.x = player_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	screen_hiyoko.y = (player_pos.y - 70.0f) - camera_pos.y + SCREEN_H * 0.5f;

	if (hiyoko_check == true)
	{
		sprite_render(spr_hiyoko, screen_hiyoko.x, screen_hiyoko.y, 2.0f, 2.0f, hiyoko_tex_pos_x, 0.0f, 64, 64, 32, 32);
	}
}
void hiyoko_deinit()
{
	safe_delete(spr_hiyoko);
}
