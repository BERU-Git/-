#pragma once
#include "all.h"

struct enemy_data
{
	VECTOR2 pos;
	VECTOR2 speed;
	VECTOR2 chase;
	VECTOR2 move;
	VECTOR2 screen;
	VECTOR2 away;
	VECTOR2 separate;
	float distance_sq;
	float distance;
	int render_posx;
	int render_posy;
	int effect_timer;
	int direction;
	float angle;

};

extern enemy_data enemy[ENEMY_MAX];
extern Sprite* spr_enemy;



void enemy_init();
void enemy_deinit();
void enemy_update();
void enemy_render();


