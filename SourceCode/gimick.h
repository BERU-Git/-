#pragma once
#include "all.h"
extern Sprite* spr_gimick;



struct gimick_data
{
	VECTOR2 pos;
	VECTOR2 screen;
	float circle;
	bool barrier_break_check;
	int anime_frame;//アニメーション用のフレームの保存変数
	int anime_timer;//アニメーション用のタイマー
};
extern Sprite* spr_gimick;
extern Sprite* spr_barrier_break;
extern gimick_data gimick[GIMICK_MAX];

void gimick_init();
void gimick_render();
void gimick_deinit();
void gimick_update();


