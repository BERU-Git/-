#pragma once
#include "all.h"

extern Sprite* spr_player;
extern VECTOR2 screen;
extern VECTOR2 player_pos;
extern VECTOR2 player_speed;
extern int player_render_posx;
extern int player_render_posy;
extern int player_effect_timer;
extern int player_direction;
extern float length;


void player_init();
void player_update();
void player_render();
void player_deinit();