#pragma once
#include "all.h"

extern Sprite* spr_player;
extern VECTOR2 screen;
extern VECTOR2 player_pos;
extern VECTOR2 player_speed;
void player_init();
void player_update();
void player_render();
void player_deinit();