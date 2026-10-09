#include "all.h"
#include "enemy.h"
#include "strong_enemy.h"
#include "attack_line.h"
#include "camera.h"
#include "troll.h"
Sprite* spr_attack_line;
Sprite* spr_strong_attack_line;
attack_line_data attack_line[ENEMY_MAX];
attack_line_data strong_attack_line;
Sprite* spr_danger_circle = nullptr;

void attack_line_init()
{
	for(int i = 0 ; i < ENEMY_MAX ; i++ )
	{
		attack_line[i] = {};
	}
spr_attack_line = sprite_load(L"Data/Images/attack_line.png");
spr_strong_attack_line = sprite_load(L"Data/Images/strong_attack_line.png");
spr_danger_circle = sprite_load(L"Data/images/”ÍˆÍUŒ‚_—\‘ªü.png");

}

void attack_line_update()
{
}

void attack_line_render()
{
	//’†ƒ{ƒX‚ÌUŒ‚ƒ‰ƒCƒ“
	strong_attack_line.screen.x = strong_attack_line.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	strong_attack_line.screen.y = strong_attack_line.pos.y - camera_pos.y + SCREEN_H * 0.5f;
	
	if (strong_enemy.charge)
	{
		sprite_render(spr_strong_attack_line, strong_attack_line.screen.x, strong_attack_line.screen.y,
					  1, 1,
					  0, 0,
					  STRONG_ATTACK_LINE_W, STRONG_ATTACK_LINE_H,
					  STRONG_ATTACK_LINE_W * 0.5f, STRONG_ATTACK_LINE_H,
					  strong_enemy.angle + ToRadian(90));
	}

	//ƒSƒuƒŠƒ“UŒ‚ƒ‰ƒCƒ“
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		attack_line[i].screen.x = attack_line[i].pos.x - camera_pos.x + SCREEN_W * 0.5f;
		attack_line[i].screen.y = attack_line[i].pos.y - camera_pos.y + SCREEN_H * 0.5f;
		if(enemy[i].charge)
		{
			sprite_render(spr_attack_line, attack_line[i].screen.x, attack_line[i].screen.y,
				1, 1,
				0, 0,
				ATTACK_LINE_W, ATTACK_LINE_H,
				ATTACK_LINE_W * 0.5f, ATTACK_LINE_H,
				enemy[i].angle + ToRadian(90));
		}
	}

	if (danger_circle)
	{
		VECTOR2 danger_screen;
		danger_screen.x = troll.pos.x - camera_pos.x + SCREEN_W * 0.5f;
		danger_screen.y = troll.pos.y - camera_pos.y + SCREEN_H * 0.5f;
		sprite_render(spr_danger_circle, danger_screen.x, danger_screen.y, 2.0f, 2.0f, 0.0f, 0.0f, 512, 512, 256, 256);
	}

}

void attack_line_delete()
{
safe_delete(spr_attack_line);
safe_delete(spr_strong_attack_line);
safe_delete(spr_danger_circle);
}
