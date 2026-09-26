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
}

void field_render()
{
	//3x3でフィールドを生成する
	for(int x = 0; x < 3; x++ )
	{
	field_screen.x = (field_pos.x + x * FIELD_W) - camera_pos.x + SCREEN_W * 0.5f;
		for (int y = 0; y < 3; y++)
		{
			field_screen.y = (field_pos.y + y * FIELD_H) - camera_pos.y + SCREEN_H * 0.5f;
			sprite_render(spr_field, field_screen.x, field_screen.y);
		}
	}
}

void field_deinit()
{
	safe_delete(spr_field);
}