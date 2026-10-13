#include "all.h"
#include "field.h"
#include "player.h"
#include "timer.h"
#include "camera.h"
#include "enemy.h"
#include "hit_check.h"
#include "attack_line.h"
#include "gimick.h"
#include "heart.h"
#include "hiyoko.h"
#include "sound.h"
#include "heal.h"

extern int game_timer;
int stage1_time;


void stage1_init()
{
	sound_init();
	player_init();
	timer_init();
	enemy_init();
	field_init();
	camera_init();
	gimick_init();
	attack_line_init();
	heart_init();
	hiyoko_init();
	player_hp = PLAYER_HP;
	game_timer = 0;

	heal_init();

	srand((unsigned int)time(NULL));
	

}

void stage1_update()
{
	if (player_hp <= 0)
	{
		hiyoko_check = true;
		stage1_time++;
		if (stage1_time >= 300)
		{
			heal_check = true;
			player_hp = CONTINUE_HP;
			stage1_time = 0;
		}
	}
	game_timer++;

	if(player_hp > 0)
	{
		player_update();
	}


		timer_update();
		enemy_update();
		GameLib::setBlendMode(Blender::BS_ALPHA);
		attack_line_update();
		field_update();
		camera_update();
		gimick_update();//gimick_updateì‚Á‚½‚©‚çŒÄ‚ñ‚¾
		heart_update();
		hiyoko_update();
		heal_update();

		

		if (go_next)
		{
			nextScene = SCENE_STAGE2;
		}

}

void stage1_render()
{
	
	GameLib::clear(0.0f, 0.0f, 0.0f);
	
    field_render();
	attack_line_render();
    player_render();
	enemy_render();
	gimick_render();
	timer_render();
	heart_render();
	hiyoko_render();
	heal_render();
	

}

void stage1_deinit()
{
	player_deinit();
	enemy_deinit();
	field_deinit();
	attack_line_delete();
	gimick_deinit();
	timer_deinit();
	heart_deinit();
	hiyoko_deinit();
	sound_deinit();
	heal_deinit();
}
