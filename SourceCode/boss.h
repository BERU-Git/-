#pragma once
#include "all.h"

enum boss_attack
{
	NORMAL_ENEMY,
	STRONG_ENEMY,
	MIX_ENEMY,
	LAST_ATTACK
};

struct boss_data
{
	VECTOR2 pos;
	VECTOR2 screen;
	float screen_center;
};

extern bool boss_stage;
extern Sprite* spr_boss;
extern boss_data boss;


void boss_init();
void boss_update_init();
void boss_update();
void boss_render();
void boss_deinit();
