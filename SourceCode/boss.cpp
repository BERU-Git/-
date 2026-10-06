#include "all.h"
#include "boss.h"
#include "player.h"
#include "camera.h"
Sprite* spr_boss;
boss_data boss;

bool boss_stage;




void boss_init()
{
	spr_boss = sprite_load(L"Data/Images/boss.png");
	boss.pos.x = player_pos.x;
	boss.pos.y = player_pos.y - SCREEN_H * 0.5f - BOSS_H * 0.5f;
}


void boss_update_init()
{
	boss.pos.y += (BOSS_H / 300) * 2;

}

void boss_update()
{



}


void boss_render()
{
	boss.screen.x = boss.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	boss.screen.y = boss.pos.y - camera_pos.y + SCREEN_H * 0.5f;


	sprite_render(spr_boss, boss.screen.x, boss.screen.y,
		1,1,
		0,0,
		BOSS_W,BOSS_H,
		BOSS_W * 0.5f,BOSS_H * 0.5f);
}


void boss_deinit()
{

	safe_delete(spr_boss);

}

