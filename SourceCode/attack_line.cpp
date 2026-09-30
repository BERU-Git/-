#include "all.h"
#include "enemy.h"
#include "attack_line.h"
#include "camera.h"
Sprite* spr_attack_line;
attack_line_data attack_line[ENEMY_MAX];
void attack_line_init()
{
	for(int i = 0 ; i < ENEMY_MAX ; i++ )
	{
		attack_line[i] = {};
	}
spr_attack_line = sprite_load(L"Data/Images/attack_line.png");

}
void attack_line_update()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		attack_line[i].pos.x = enemy[i].pos.x;
		attack_line[i].pos.y = enemy[i].pos.y;
	}
}
void attack_line_render()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		attack_line[i].screen.x = attack_line[i].pos.x - camera_pos.x + SCREEN_W * 0.5f;
		attack_line[i].screen.y = attack_line[i].pos.y - camera_pos.y + SCREEN_H * 0.5f;
		if(enemy[i].attack)
		{
			sprite_render(spr_attack_line, attack_line[i].screen.x, attack_line[i].screen.y,
				1, 1,
				0, 0,
				ATTACK_LINE_W, ATTACK_LINE_H,
				ATTACK_LINE_W * 0.5f, ATTACK_LINE_H,
				enemy[i].angle + ToRadian(90));
		}
	}

}
void attack_line_delete()
{
safe_delete(spr_attack_line);
}
