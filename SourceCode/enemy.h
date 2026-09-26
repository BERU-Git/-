#pragma once
#include "all.h"

struct enemy_data
{
	VECTOR2 pos;
	VECTOR2 speed;
	VECTOR2 screen;
};

extern enemy_data enemy[ENEMY_MAX];
extern Sprite* spr_enemy;



void enemy_init();
void enemy_deinit();
void enemy_update();
void enemy_render();


