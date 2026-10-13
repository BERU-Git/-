#pragma once
#include "all.h"
#include "enemy.h"

extern Sprite* spr_strong_enemy;
extern enemy_data strong_enemy;

void strong_enemy_init();
void strong_enemy_update();
void strong_enemy_render();
void boss_strong_enemy_init();
void boss_strong_enemy_update();
void strong_enemy_deinit();