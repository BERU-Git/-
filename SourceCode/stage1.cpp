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
	heal_init();
	player_hp = PLAYER_HP;
	game_timer = 0;

	music::play(FIELD_BGM,true);

	srand((unsigned int)time(NULL));
	

}

void stage1_update()
{
	if (player_hp <= 0)
	{
		knock_check = true;
		hiyoko_check = true;
		stage1_time++;
		if (stage1_time >= 300)
		{
			music::play(RESURRECTION);
			knock_check = false;
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
		gimick_update();//gimick_updateçÏÇ¡ÇΩÇ©ÇÁåƒÇÒÇæ
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
	hiyoko_render();
	heal_render();
	enemy_render();
	gimick_render();
	heart_render();
	timer_render();
	

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
	hiyoko_deinit();
}
