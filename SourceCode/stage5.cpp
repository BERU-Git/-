#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "gimick.h"
#include "boss.h"
#include "attack_line.h"
int stage5_timer;
int stage5_time;
int stage5_state;
extern int game_timer;

void stage5_init()
{
	boss_stage = true;
	stage5_timer = 0;
	stage5_state = 0;
	player_init();
	camera_init();
	field_init();
	boss_init();
	attack_line_init();



}
void stage5_update()
{
	game_timer++;

	if (player_hp <= 0)
	{
		stage5_time++;
		if (stage5_time >= 300)
		{
			player_hp = CONTINUE_HP;
			stage5_time = 0;
		}
	}


	GameLib::setBlendMode(Blender::BS_ALPHA);
	stage5_timer++;
	
	camera_update();
	field_update();
	screen_shake(15);
	
	if (stage5_timer >= 120 && stage5_timer <= 420)
	{
		screen_shake_init(120);
		boss_update_init();
	}
	
		
		if (stage5_timer >= 420)
	{
		if(player_hp)
		{
			player_update();
		}

		boss_update();
	}



}
void stage5_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	attack_line_render();
	player_render();
	boss_render();

}
void stage5_deinit()
{
	player_deinit();
	field_deinit();
	boss_deinit();
	attack_line_delete();
}
