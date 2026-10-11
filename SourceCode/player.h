#pragma once
#include "all.h"

extern Sprite* spr_player;
extern VECTOR2 screen;
extern VECTOR2 player_pos;
extern VECTOR2 player_speed;
extern VECTOR2 decoy_totem_pos;
extern VECTOR2 decoy_screen;

extern int player_hp;
extern float player_alpha;
extern int player_render_posx;
extern int player_render_posy;
extern int player_effect_timer;
extern int player_direction;
extern float length;
extern bool player_hit;
extern bool go_next;
extern bool jast_avoid_check;

void clamp_position(float& pos_x, float& pos_y, float texsize_x, float texsize_y,
	float& speed_x, float& speed_y);


void player_init();
void player_update();
void player_render();
void player_deinit();