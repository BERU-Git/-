#include "all.h"
#include "player.h"
#include "camera.h"
#include "heal.h"

Sprite* spr_heal = nullptr;
int heal_timer = 0;
int heal_count = 0;
bool heal_check = false;
float heal_tex_pos_x = 0.0f;
VECTOR2 heal_screen = { 0.0f, 0.0f };

void heal_init()
{
	spr_heal = sprite_load(L"Data/Images/heal.png");
}
void heal_update()
{
	if (heal_check == true)
	{
		heal_timer++;
		if (heal_timer % 6 == 0)
		{
			heal_count += 1;
			heal_tex_pos_x = 32 * heal_count;
			heal_timer = 0;
		}
		if (heal_count == 7)
		{
			heal_count = 0;
			heal_tex_pos_x = 0.0f;
			heal_timer = 0;
			heal_check = false;
		}
	}
	
}
void heal_render()
{
	heal_screen.x = player_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	heal_screen.y = player_pos.y - camera_pos.y + SCREEN_H * 0.5f;
	if (heal_check == true)
	{
		/*GameLib::setBlendMode(Blender::BS_ADD);*/
		sprite_render(spr_heal, heal_screen.x, heal_screen.y, 5.0f, 5.0f, heal_tex_pos_x, 0.0f, 32.0f, 32.0f, 16.0f, 16.0f);
	}
	/*GameLib::setBlendMode(Blender::BS_ALPHA);*/
	
}
void heal_deinit()
{
	safe_delete(spr_heal);
}