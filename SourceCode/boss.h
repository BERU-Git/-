#pragma once
#include "all.h"

struct boss_data
{
	VECTOR2 pos;
	VECTOR2 screen;
};

extern bool boss_stage;
extern Sprite* spr_boss;
extern boss_data boss;


void boss_init();
void boss_update_init();
void boss_update();
void boss_render();
void boss_deinit();
