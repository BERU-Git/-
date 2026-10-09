#include "all.h"
Sprite* all_time;
Sprite* colon;

int seconds_pos_1 = 0;

int seconds_pos_10 = 0;

int minutes_pos_1 = 0;

int minutes_pos_10 = 0;
extern int game_timer;

void timer_init()
{
	all_time = sprite_load(L"Data/Images/time.png");
	colon = sprite_load(L"Data/Images/colon.png");
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
	sprite_render(all_time, SCREEN_W * 0.5f + 64, 64,
				  1,1,
				  TIMER_W * seconds_pos_1,0,
		          64,64,
		          32,32);
	sprite_render(all_time, SCREEN_W * 0.5f, 64,
				  1,1,
		          TIMER_W * seconds_pos_10, 0,
		          64,64,
		          32,32);
	sprite_render(colon, SCREEN_W * 0.5f - 40, 64,
		  		  1, 1,
				  0, 0,
				  64, 64,
				  32, 32);
	sprite_render(all_time, SCREEN_W * 0.5f - 80, 64,
				  1, 1,
				  TIMER_W * minutes_pos_1, 0,
				  64, 64,
				  32, 32);
	sprite_render(all_time, SCREEN_W * 0.5f - 144, 64,
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
