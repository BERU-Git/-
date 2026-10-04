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

Sprite* spr_wall_down;
VECTOR2 wall_down_pos;
VECTOR2 wall_down_screen;

Sprite* spr_magic_circle;
VECTOR2 magic_circle_pos;
VECTOR2 magic_circle_screen;

Sprite* spr_stairs;
VECTOR2 stairs_pos;
VECTOR2 stairs_screen;




void field_init()
{
spr_field = sprite_load(L"Data/images/Field_01.png");
spr_wall = sprite_load(L"Data/images/wall_01.png");
spr_wall_side = sprite_load(L"Data/images/wallside.png");
spr_wall_down = sprite_load(L"Data/images/wall_down.png");
spr_magic_circle = sprite_load(L"Data/images/magic_circrs.png");
spr_stairs = sprite_load(L"Data/images/stairs.png");


field_pos.x = 0;
field_pos.y = 0;

wall_pos.x = 0;
wall_pos.y = -WALL_H;


wall_side_pos.x = -WALLSIDE_W;
wall_side_pos.y = WORLD_H - WALLSIDE_H;

wall_down_pos.x = 0;
wall_down_pos.y = WORLD_H;

stairs_pos.x = WORLD_W * 0.5f;
stairs_pos.y = WORLD_H * 0.5f;

magic_circle_pos.x = WORLD_W * 0.5f;
magic_circle_pos.y = WORLD_H * 0.5f;

}


void field_update()
{
}

void field_render()
{

	//3x3Ç≈ÉtÉBÅ[ÉãÉhÇê∂ê¨Ç∑ÇÈ
	for(int x = 0; x < 3; x++ )
	{
	field_screen.x = (field_pos.x + x * FIELD_W) - camera_pos.x + SCREEN_W * 0.5f;
		for (int y = 0; y < 3; y++)
		{
			field_screen.y = (field_pos.y + y * FIELD_H) - camera_pos.y + SCREEN_H * 0.5f;
			sprite_render(spr_field, field_screen.x, field_screen.y);
		}
	}
	//è„ÇÃï«
	for (int x = 0; x <23; x++)
	{
		wall_screen.x = (wall_pos.x + x * WALL_W) - camera_pos.x + SCREEN_W * 0.5f;
		wall_screen.y = wall_pos.y  - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_wall, wall_screen.x, wall_screen.y);
	}
	//ç∂ÇÃï«
	for (int y = 0; y < 9; y++)
	{
		wall_side_screen.x = wall_side_pos.x  - camera_pos.x + SCREEN_W * 0.5f;
		wall_side_screen.y = (wall_side_pos.y + -y * WALLSIDE_H)  - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_wall_side, wall_side_screen.x, wall_side_screen.y);
	}
	//âEÇÃï«
	for (int y = 0; y < 9; y++)
	{
		wall_side_screen.x = (wall_side_pos.x + WORLD_W + WALLSIDE_W) - camera_pos.x + SCREEN_W * 0.5f;
		wall_side_screen.y = (wall_side_pos.y + -y * WALLSIDE_H)  - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_wall_side, wall_side_screen.x, wall_side_screen.y);
	}
	//â∫ÇÃï«
	for (int x = 0; x < 10; x++)
	{
		wall_down_screen.x = (wall_down_pos.x + x * WALLDOWN_W) - camera_pos.x + SCREEN_W * 0.5f;
		wall_down_screen.y = wall_down_pos.y  - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_wall_down, wall_down_screen.x, wall_down_screen.y);
	}


	//äKíiÇï`âÊÇ∑ÇÈ
	stairs_screen.x = stairs_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	stairs_screen.y = stairs_pos.y - camera_pos.y + SCREEN_H * 0.5f;

	sprite_render(spr_stairs, stairs_screen.x, stairs_screen.y,
		          1,1,
		          0,0,
		          STAIRS_W,STAIRS_H,
		          STAIRS_W * 0.5f, STAIRS_H * 0.5f);

	//ñÇñ@êwÇï`âÊÇ∑ÇÈ
	magic_circle_screen.x = magic_circle_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	magic_circle_screen.y = magic_circle_pos.y - camera_pos.y + SCREEN_H * 0.5f;

	sprite_render(spr_magic_circle, magic_circle_screen.x, magic_circle_screen.y,
		          1,1,
		          0,0,
		          MAGIC_CIRCLE_W,MAGIC_CIRCLE_H,
		          MAGIC_CIRCLE_W * 0.5f, MAGIC_CIRCLE_H * 0.5f);





}

void field_deinit()
{
	safe_delete(spr_field);
	safe_delete(spr_wall);
	safe_delete(spr_wall_side);
	safe_delete(spr_wall_down);
	safe_delete(spr_stairs);
	safe_delete(spr_magic_circle);
}