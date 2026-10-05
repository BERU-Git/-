#include "all.h"
#include "player.h"
VECTOR2 camera_pos;
VECTOR2 camera_shake;

int camera_shake_time = 0;
int camera_shake_time_max;

void screen_shake_init(int time)
{
	camera_shake_time = time;
	camera_shake_time_max = time;
}

void screen_shake(int camera_shake_power)
{
	int current_shake_power;

	if(camera_shake_time > 0 )
	{
		current_shake_power = camera_shake_power * camera_shake_time / camera_shake_time_max;

		camera_shake.x = rand() % (current_shake_power * 2 + 1) - current_shake_power;
		camera_shake.y = rand() % (current_shake_power * 2 + 1) - current_shake_power;


		camera_shake_time--;
	}
	else
	{
		camera_shake.x = 0;
		camera_shake.y = 0;
	}
	
}

void camera_init()
{
	camera_pos.x = player_pos.x + camera_shake.x;
	camera_pos.y = player_pos.y + camera_shake.y;
}

void camera_update()
{
	
	//カメラをプレイヤーに追従させる
	camera_pos.x = player_pos.x + camera_shake.x;
	camera_pos.y = player_pos.y + camera_shake.y;

}