#pragma once
#include "all.h"

extern Sprite* spr_player;
extern VECTOR2 player_pos;
void player_init();
void player_update();
void player_render();
void player_deinit();