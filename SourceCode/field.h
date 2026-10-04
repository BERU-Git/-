#pragma once
#include "all.h"

extern Sprite* spr_field;
extern VECTOR2 field_pos;
extern VECTOR2 field_screen;

extern Sprite* spr_wall_side;
extern VECTOR2 wall_side_pos;
extern VECTOR2 wall_side_screen;

extern Sprite* spr_wall;
extern VECTOR2 wall_pos;
extern VECTOR2 wall_screen;

extern Sprite* spr_wall_down;
extern VECTOR2 wall_down_pos;
extern VECTOR2 wall_down_screen;

extern Sprite* spr_magic_circle;
extern VECTOR2 magic_circle_pos;
extern VECTOR2 magic_circle_screen;

extern Sprite* spr_stairs;
extern VECTOR2 stairs_pos;
extern VECTOR2 stairs_screen;


void field_init();
void field_update();
void field_render();
void field_deinit();