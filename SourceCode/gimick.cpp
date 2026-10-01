#include "gimick.h"
#include "all.h"
#include "camera.h"

Sprite* spr_gimick = nullptr;

VECTOR2 gimick_pos_1;
VECTOR2 gimick_screen_1;
VECTOR2 gimick_pos_2;
VECTOR2 gimick_screen_2;
VECTOR2 gimick_pos_3;
VECTOR2 gimick_screen_3;
VECTOR2 gimick_pos_4;
VECTOR2 gimick_screen_4;

void gimick_init()
{
	spr_gimick = sprite_load(L"Data/images/barrier.png");
	gimick_pos_1.x = 512;
	gimick_pos_1.y = 512;

	gimick_pos_2.x = 512;
	gimick_pos_2.y = 2726;

	gimick_pos_3.x = 5248;
	gimick_pos_3.y = 512;

	gimick_pos_4.x = 5248;
	gimick_pos_4.y = 2726;
}

void gimick_render()//ƒMƒ~ƒbƒN‚Ì•`‰æ
{
	gimick_screen_1.x = gimick_pos_1.x - camera_pos.x + SCREEN_W * 0.5f;
	gimick_screen_1.y = gimick_pos_1.y - camera_pos.y + SCREEN_H * 0.5f;
	sprite_render(spr_gimick,
		gimick_screen_1.x, gimick_screen_1.y, 1.0f, 1.0f, 0, 0, 256, 256, 128, 128);
	gimick_screen_2.x = gimick_pos_2.x - camera_pos.x + SCREEN_W * 0.5f;
	gimick_screen_2.y = gimick_pos_2.y - camera_pos.y + SCREEN_H * 0.5f;
	sprite_render(spr_gimick,
		gimick_screen_2.x, gimick_screen_2.y, 1.0f, 1.0f, 0, 0, 256, 256, 128, 128);
	gimick_screen_3.x = gimick_pos_3.x - camera_pos.x + SCREEN_W * 0.5f;
	gimick_screen_3.y = gimick_pos_3.y - camera_pos.y + SCREEN_H * 0.5f;
	sprite_render(spr_gimick,
		gimick_screen_3.x, gimick_screen_3.y, 1.0f, 1.0f, 0, 0, 256, 256, 128, 128);
	gimick_screen_4.x = gimick_pos_4.x - camera_pos.x + SCREEN_W * 0.5f;
	gimick_screen_4.y = gimick_pos_4.y - camera_pos.y + SCREEN_H * 0.5f;
	sprite_render(spr_gimick,
		gimick_screen_4.x, gimick_screen_4.y, 1.0f, 1.0f, 0, 0, 256, 256, 128, 128);
}

void gimick_deinit()
{
	safe_delete(spr_gimick);
}
