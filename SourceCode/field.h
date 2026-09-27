#pragma once
#include "all.h"

extern Sprite* spr_field;
extern VECTOR2 field_pos;
extern VECTOR2 field_screen;

void field_init();
void field_update();
void field_render();
void field_deinit();