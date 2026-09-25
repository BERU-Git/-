#include "all.h"
#include "camera.h"
Sprite* spr_field;
VECTOR2 field_pos;
VECTOR2 field_screen;

void field_init()
{
spr_field = sprite_load(L"Data/images/Field_01.png");

field_pos.x = 0;
field_pos.y = 0;

}

void field_update()
{
	field_screen.x = field_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	field_screen.y = field_pos.y - camera_pos.y + SCREEN_H * 0.5f;
}

void field_render()
{
	sprite_render(spr_field, field_screen.x,field_screen.y);
}

void field_deinit()
{
	safe_delete(spr_field);
}