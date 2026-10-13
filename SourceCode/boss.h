#pragma once
#include "all.h"

enum boss_attack
{
	NORMAL_ENEMY,
	STRONG_ENEMY_INIT,
	STRONG_ENEMY,
	MIX_ENEMY_INIT,
	MIX_ENEMY,
	LAST_ATTACK_INIT,
	LAST_ATTACK,
	BOSS_END
};

struct boss_data
{
	VECTOR2 pos;
	VECTOR2 screen;
	float transparent;
	float screen_center;
	bool knock_down;
};

extern bool boss_stage;
extern bool last_attack;
extern Sprite* spr_boss;
extern boss_data boss;
extern boss_attack state;



void boss_init();
void boss_update_init();
void boss_update();
void boss_render();
void boss_deinit();
