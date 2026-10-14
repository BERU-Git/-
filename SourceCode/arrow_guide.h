#pragma once
#include "all.h"

struct arrow_guide_data
{
	VECTOR2 pos;
	VECTOR2 screen;
	float angle;

	float speed = 0.05f;
};

void arrow_guide_init();
void arrow_guide_update();
void arrow_guide_render();
void arrow_guide_deinit();
