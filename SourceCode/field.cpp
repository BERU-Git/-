#include "all.h"
#include "camera.h"
Sprite* spr_wall_side;
VECTOR2 wall_side_pos;
VECTOR2 wall_side_screen;

Sprite* spr_wall;
VECTOR2 wall_pos;
VECTOR2 wall_screen;

Sprite* spr_field;
VECTOR2 field_pos;
VECTOR2 field_screen;

void field_init()
{
spr_field = sprite_load(L"Data/images/Field_01.png");
spr_wall = sprite_load(L"Data/images/wall_01.png");
spr_wall_side = sprite_load(L"Data/images/wallside.png");

field_pos.x = 0;
field_pos.y = 0;

wall_pos.x = 0;
wall_pos.y = -WALL_H;


wall_side_pos.x = -WALLSIDE_W;
wall_side_pos.y = WORLD_H - WALLSIDE_H;


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
	for (int x = 0; x < 9; x++)
	{
		wall_screen.x = (wall_pos.x + x * WALL_W) - camera_pos.x + SCREEN_W * 0.5f;
		wall_screen.y = wall_pos.y  - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_wall, wall_screen.x, wall_screen.y);
	}
	for (int y = 0; y < 9; y++)
	{
		wall_side_screen.x = wall_side_pos.x  - camera_pos.x + SCREEN_W * 0.5f;
		wall_side_screen.y = (wall_side_pos.y + -y * WALLSIDE_H)  - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_wall_side, wall_side_screen.x, wall_side_screen.y);
	}
	for (int y = 0; y < 9; y++)
	{
		wall_side_screen.x = (wall_side_pos.x + WORLD_W + WALLSIDE_W) - camera_pos.x + SCREEN_W * 0.5f;
		wall_side_screen.y = (wall_side_pos.y + -y * WALLSIDE_H)  - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_wall_side, wall_side_screen.x, wall_side_screen.y);
	}

}

void field_deinit()
{
	safe_delete(spr_field);
}