#include "all.h"
#include "boss.h"
Sprite* spr_boss;
boss_data boss;

bool boss_stage;




void boss_init()
{
	spr_boss = sprite_load(L"Data/Images/boss.png");

}


void boss_update()
{


}


void boss_render()
{
	sprite_render(spr_boss, SCREEN_W * 0.5f, BOSS_H * 0.5f,
		1,1,
		0,0,
		BOSS_W,BOSS_H,
		BOSS_W * 0.5f,BOSS_H * 0.5f);
}


void boss_deinit()
{

	safe_delete(spr_boss);

}

