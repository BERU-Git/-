#include "all.h"
#include "boss.h"
#include "player.h"
#include "camera.h"
#include "enemy.h"
Sprite* spr_boss;
boss_data boss;
boss_attack state;
bool boss_stage;




void boss_init()
{
	enemy_init();
	spr_boss = sprite_load(L"Data/Images/boss.png");
	boss.pos.x = player_pos.x;
	boss.pos.y = player_pos.y - SCREEN_H * 0.5f - BOSS_H * 0.5f;
}


void boss_update_init()
{
	boss.pos.y += BOSS_H / 260;


}

void boss_update()
{

	boss.pos.x += (player_pos.x - boss.pos.x) * 0.05f;

	boss.screen_center = player_pos.y - BOSS_CENTER_H;
	 
	boss.pos.y += (boss.screen_center - boss.pos.y) * 0.1f;

	//ボスの行動範囲制限
	if (boss.pos.x <= player_pos.x - SCREEN_W * 0.5f)
	{
		boss.pos.x = player_pos.x - SCREEN_W * 0.5f;
	}
	else if (boss.pos.x >= player_pos.x + SCREEN_W * 0.5f)
	{
		boss.pos.x = player_pos.x + SCREEN_W * 0.5f;
	}
	if (boss.pos.y <= player_pos.y - SCREEN_H * 0.5f)
	{
		boss.pos.y = player_pos.y - SCREEN_H * 0.5f;
	}
	else if (boss.pos.y >= (player_pos.y - SCREEN_H * 0.5f) + BOSS_H * 0.5f)
	{
		boss.pos.y = (player_pos.y - SCREEN_H * 0.5f) + BOSS_H * 0.5f;
	}

	//攻撃ウェーブ処理

	switch (state)
	{
	case NORMAL_ENEMY:
		enemy_update();
	}

}


void boss_render()
{
	boss.screen.x = boss.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	boss.screen.y = boss.pos.y - camera_pos.y + SCREEN_H * 0.5f;

	switch (state)
	{
	case NORMAL_ENEMY:
		enemy_render();
	}





	sprite_render(spr_boss, boss.screen.x, boss.screen.y,
		1,1,
		0,0,
		BOSS_W,BOSS_H,
		BOSS_W * 0.5f,BOSS_H * 0.5f);
}


void boss_deinit()
{
	enemy_deinit();
	safe_delete(spr_boss);

}

