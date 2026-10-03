#pragma once
#include "all.h"
struct attack_line_data
{
	VECTOR2 pos;
	VECTOR2 screen;

};
extern Sprite* spr_attack_line;
extern attack_line_data attack_line[ENEMY_MAX];
extern attack_line_data strong_attack_line;



void attack_line_init();
void attack_line_update();
void attack_line_render();
void attack_line_delete();

