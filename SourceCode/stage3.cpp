#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "attack_line.h"
#include "hit_check.h"
#include "gimick.h"
#include "strong_enemy.h"
#include "enemy.h"
#include "troll.h"
#include "range_enemy.h"
#include"timer.h"
#include "heart.h"


extern int game_timer;
int stage3_time;
void stage3_init()
{
	field_init();
	player_init();
	camera_init();
	gimick_init();
	attack_line_init();
	enemy_init();
timer_init();
	strong_enemy_init();
	troll_init();
	range_enemy_init();
	heart_init();
}



void stage3_update()
{
	if (player_hp <= 0)
	{
		stage3_time++;
		if (stage3_time >= 300)
		{
			player_hp = CONTINUE_HP;
			stage3_time = 0;
		}
	}
	if(player_hp)
	{
		player_update();
	}

	game_timer++;
	GameLib::setBlendMode(Blender::BS_ALPHA);
	field_update();
	camera_update();
	enemy_update();
	gimick_update();
	strong_enemy_update();
	troll_update();
	range_enemy_update();
	timer_update();
	heart_update();


	if (go_next)
	{
		nextScene = SCENE_STAGE4;
	}


}
void stage3_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	attack_line_render();
	player_render();
	enemy_render();
	strong_enemy_render();
	troll_render();
	range_enemy_render();
	gimick_render();
timer_render();
heart_render();

}
void stage3_deinit()
{
	field_deinit();
	player_deinit();
	gimick_deinit();
	enemy_deinit();
	strong_enemy_deinit();
	troll_deinit();
	attack_line_delete();
	range_enemy_deinit();
timer_deinit();
heart_deinit();
}
