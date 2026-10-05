#pragma once
#include "all.h"

struct boss_data
{
	VECTOR2 pos;
	VECTOR2 screen;
};

extern bool boss_stage;

void boss_init();
void boss_update();
void boss_render();
void boss_deinit();
