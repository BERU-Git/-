#pragma once
#include "../GameLib/game_lib.h"

struct OBJ2D
{
	
	VECTOR2 scale;
	VECTOR2 tex_pos;
	VECTOR2 tex_size;
	VECTOR4 color;
	float speed;
	GameLib::Sprite* spr;
};
