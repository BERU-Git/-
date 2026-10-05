#pragma once
#include "all.h"

extern VECTOR2 camera_pos;
extern int camera_shake_time;
void screen_shake(int camera_shake_power);
void screen_shake_init(int time);


void camera_init();
void camera_update();

