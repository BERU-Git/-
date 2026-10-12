#include "all.h"
Sprite* all_time;
Sprite* colon;

int seconds_pos_1 = 0;

int seconds_pos_10 = 0;

int minutes_pos_1 = 0;

int minutes_pos_10 = 0;

VECTOR2 seconds_1;
VECTOR2 seconds_10;
VECTOR2 colon_pos;
VECTOR2 minutes_1;
VECTOR2 minutes_10;

extern int game_timer;


void timer_init()
{
	all_time = sprite_load(L"Data/Images/time.png");
	colon = sprite_load(L"Data/Images/colon.png");

	seconds_1.x = SCREEN_W * 0.5f + 64;
	seconds_1.y = 64;
	
	seconds_10.x = SCREEN_W * 0.5f;
	seconds_10.y = 64;
	
	colon_pos.x = SCREEN_W * 0.5f - 40;
	colon_pos.y = 64;

	minutes_1.x = SCREEN_W * 0.5f - 80;
	minutes_1.y = 64;
	
	minutes_10.x = SCREEN_W * 0.5f - 144;
	minutes_10.y = 64;

}
void timer_update()
{
	if (game_timer % 60 == 0)
	{
		seconds_pos_1++;
	}
	if(seconds_pos_1 > 9)
	{
		seconds_pos_1 = 0;
		seconds_pos_10++;
	}
	if (seconds_pos_10 > 5)
	{
		seconds_pos_10 = 0;
		minutes_pos_1++;
	}
	if (minutes_pos_1 > 9)
	{
		minutes_pos_1 = 0;
		minutes_pos_10++;
	}
}
void timer_render()
{
	sprite_render(all_time, seconds_1.x, seconds_1.y,
				  1,1,
				  TIMER_W * seconds_pos_1,0,
		          64,64,
		          32,32);
	sprite_render(all_time, seconds_10.x, seconds_10.y,
				  1,1,
		          TIMER_W * seconds_pos_10, 0,
		          64,64,
		          32,32);
	sprite_render(colon, colon_pos.x, colon_pos.y,
		  		  1, 1,
				  0, 0,
				  64, 64,
				  32, 32);
	sprite_render(all_time, minutes_1.x, minutes_1.y,
				  1, 1,
				  TIMER_W * minutes_pos_1, 0,
				  64, 64,
				  32, 32);
	sprite_render(all_time, minutes_10.x, minutes_10.y,
				  1, 1,
				  TIMER_W * minutes_pos_10, 0,
				  64, 64,
				  32, 32);


}
void timer_deinit()
{
	safe_delete(all_time);
	safe_delete(colon);
}
