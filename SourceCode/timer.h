#pragma once

extern VECTOR2 seconds_1;
extern VECTOR2 seconds_10;
extern VECTOR2 colon_pos;
extern VECTOR2 minutes_1;
extern VECTOR2 minutes_10;

extern int seconds_pos_1;
extern int seconds_pos_10;
extern int minutes_pos_1;
extern int minutes_pos_10;


void timer_init();
void timer_update();
void timer_render();
void timer_deinit();
