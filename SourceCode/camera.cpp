#include "all.h"
#include "player.h"
VECTOR2 camera_pos;


void camera_init()
{
	camera_pos.x = player_pos.x;
	camera_pos.y = player_pos.y;
}

void camera_update()
{
	//カメラをプレイヤーに追従させる
	camera_pos.x = player_pos.x;
	camera_pos.y = player_pos.y;

}