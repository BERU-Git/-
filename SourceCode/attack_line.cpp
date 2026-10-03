#include "all.h"
#include "enemy.h"
#include "strong_enemy.h"
#include "attack_line.h"
#include "camera.h"
Sprite* spr_attack_line;
Sprite* spr_strong_attack_line;
attack_line_data attack_line[ENEMY_MAX];
attack_line_data strong_attack_line;
void attack_line_init()
{
	for(int i = 0 ; i < ENEMY_MAX ; i++ )
	{
		attack_line[i] = {};
	}
spr_attack_line = sprite_load(L"Data/Images/attack_line.png");
spr_strong_attack_line = sprite_load(L"Data/Images/strong_attack_line.png");

}

void attack_line_update()
{
}

void attack_line_render()
{
	//中ボスの攻撃ライン
	strong_attack_line.screen.x = strong_attack_line.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	strong_attack_line.screen.y = strong_attack_line.pos.y - camera_pos.y + SCREEN_H * 0.5f;
	
	if (strong_enemy.attack)
	{
		sprite_render(spr_strong_attack_line, strong_attack_line.screen.x, strong_attack_line.screen.y,
					  1, 1,
					  0, 0,
					  STRONG_ATTACK_LINE_W, STRONG_ATTACK_LINE_H,
					  STRONG_ATTACK_LINE_W * 0.5f, STRONG_ATTACK_LINE_H,
					  strong_enemy.angle + ToRadian(90));
	}

	//中ボスの攻撃ライン
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
