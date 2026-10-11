#pragma once
#include "all.h"

extern Sprite* spr_exprotion_effect;


extern int effect_anime;
extern int effect_anime_timer;
extern VECTOR2 effect_tex_pos;
extern VECTOR2 effect_tex_size;
extern int effect_count;
extern bool effect_check;
extern bool jast_avoid_effect_check;

void exprotion_init();
void exprotion_update();
void exprotion_render();
void exprotion_deinit();


