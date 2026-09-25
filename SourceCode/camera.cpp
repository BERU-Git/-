#include "all.h"
#include "player.h"
VECTOR2 camera_pos;
VECTOR2 screen;

void camera_init()
{
	camera_pos.x = player_pos.x;
	camera_pos.y = player_pos.y;
}

void camera_update()
{
	camera_pos.x = player_pos.x;
	camera_pos.y = player_pos.y;

	screen.x = player_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	screen.y = player_pos.y - camera_pos.y + SCREEN_H * 0.5f;

}