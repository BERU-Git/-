#pragma once
#include "all.h"
#include "enemy.h"

extern Sprite* spr_range_enemy;
extern Sprite* spr_range_enemy_bullet;

extern int range_attack_timer;
extern int range_prep_timer;
extern int range_teleport_timer;


extern int range_attack_index;

extern enemy_data range_enemy;
extern enemy_data range_enemy_bullet[BULLET_MAX];


void range_enemy_init();
void range_enemy_update();
void range_enemy_render();
void range_enemy_deinit();