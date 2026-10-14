#include "all.h"
#include "arrow_guide.h"
#include "enemy.h"
#include "player.h"
#include "gimick.h"
#include "camera.h"


Sprite* spr_arrow_guide;
arrow_guide_data arrow_guide[GIMICK_MAX];

void arrow_guide_init()
{
	spr_arrow_guide = sprite_load(L"Data/images/arrow_guide.png");
	
}
void arrow_guide_update()
{
	for (int i = 0; i < GIMICK_MAX; i++)
	{

		float dx = gimick[i].pos.x-player_pos.x;
		float dy = gimick[i].pos.y-player_pos.y;

		arrow_guide[i].angle = atan2f(dy, dx);

		arrow_guide[i].pos.x = player_pos.x + cosf(arrow_guide[i].angle) * ARROW_GUIDE_RADIUS;
		arrow_guide[i].pos.y = player_pos.y + sinf(arrow_guide[i].angle) * ARROW_GUIDE_RADIUS;
	}
}
void arrow_guide_render()
{
	
		for(int i = 0 ; i < GIMICK_MAX ; i++ )
	{
		arrow_guide[i].screen.x = arrow_guide[i].pos.x - camera_pos.x + SCREEN_W * 0.5f;
		arrow_guide[i].screen.y = arrow_guide[i].pos.y - camera_pos.y + SCREEN_H * 0.5f;

		sprite_render(spr_arrow_guide,
			arrow_guide[i].screen.x, arrow_guide[i].screen.y,
			0.5f, 0.5f,
			0, 0,
			128, 128,
			64, 64,
			arrow_guide[i].angle + ToRadian(90)
			);
	}
}
void arrow_guide_deinit()
{
	safe_delete(spr_arrow_guide);
}

