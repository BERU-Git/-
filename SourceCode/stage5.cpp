#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "hit_check.h"
#include "gimick.h"
#include "boss.h"
int stage5_timer;
int stage5_state;


void stage5_init()
{
	boss_stage = true;
	stage5_timer = 0;
	stage5_state = 0;
	camera_init();
	player_init();
	field_init();
	boss_init();


}
void stage5_update()
{
	GameLib::setBlendMode(Blender::BS_ALPHA);
	stage5_timer++;
	
	camera_update();
	player_update();
	field_update();
	screen_shake(15);
	
	if (stage5_timer >= 120 && stage5_timer <= 420)
	{
		screen_shake_init(300);
		boss_update_init();

	}
	
		
		if (stage5_timer >= 420)
	{
		boss_update();
	}


}
void stage5_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	player_render();

	if (stage5_timer >= 120)
	{
	boss_render();
	}

}
void stage5_deinit()
{
	player_deinit();
	field_deinit();
	boss_deinit();

}
