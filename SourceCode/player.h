#pragma once
#include "all.h"

extern Sprite* spr_player;
extern float player_posx;
extern float player_posy;
void player_init();
void player_update();
void player_render();
void player_deinit();