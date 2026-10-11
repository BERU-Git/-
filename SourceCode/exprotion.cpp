#include "all.h"
#include "player.h"
#include "troll.h"

Sprite* spr_exprotion_effect;

int effect_anime;
int effect_anime_timer;
VECTOR2 effect_tex_pos;
VECTOR2 effect_tex_size;
int effect_count;
bool effect_check;
bool jast_avoid_effect_check;

void exprotion_init()
{

	spr_exprotion_effect = sprite_load(L"Data/images/爆破エフェクト.png");
	
	effect_anime = 0;
	effect_anime_timer = 0;
	effect_tex_pos.x = 0.0f;
	effect_tex_pos.y = 0.0f;
	effect_tex_size.x = 512.0f;
	effect_tex_size.y = 512.0f;
	effect_check = false;
	effect_count = 0;

}
void exprotion_update()
{
	if (effect_check || jast_avoid_effect_check)
	{
		effect_anime_timer++;
		if ((effect_anime_timer) % 4 == 0)
		{
			effect_count++;
			effect_tex_pos.x = (512.0f * effect_count);
		}
		if (effect_count == 8)
		{
			effect_tex_pos.y = effect_tex_size.y;
		}
		if (effect_count > 16)
		{
			effect_count = 0;
			jast_avoid_effect_check = false;
			effect_check = false;
		}
	}

}
void exprotion_render()
{
	if (effect_check)
	{
		sprite_render(spr_exprotion_effect,
			troll_screen.x, troll_screen.y,
			2.7f, 2.7f,
			effect_tex_pos.x, effect_tex_pos.y,
			effect_tex_size.x, effect_tex_size.y,
			256, 256);
	}

		if (jast_avoid_effect_check)
		{
			sprite_render(spr_exprotion_effect,
				decoy_screen.x, decoy_screen.y,
				2.7f, 2.7f,
				effect_tex_pos.x, effect_tex_pos.y,
				effect_tex_size.x, effect_tex_size.y,
				256, 256);
		}

}
void exprotion_deinit()
{
	safe_delete(spr_exprotion_effect);

}
