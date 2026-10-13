#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "attack_line.h"
#include "hit_check.h"
#include "gimick.h"
#include "strong_enemy.h"
#include "troll.h"
#include "range_enemy.h"
#include"timer.h"
#include "heart.h"
#include "sound.h"
#include "hiyoko.h"
#include "heal.h"

extern int game_timer;
int stage2_time;


void stage2_init()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i].attack = false;
	}
	sound_init();
	attack_line_init();
	player_init();
	timer_init();
	camera_init();
	enemy_init();
	strong_enemy_init();
	field_init();
	gimick_init();
	heart_init();
	heal_init();
	hiyoko_init();

	music::play(FIELD_BGM, true);



}
void stage2_update()
{
	if (player_hp <= 0)
	{
		knock_check = true;
		hiyoko_check = true;
		stage2_time++;
		if (stage2_time >= 300)
		{
			knock_check = false;
			heal_check = true;
			player_hp = CONTINUE_HP;
			stage2_time = 0;
		}
	}

	game_timer++;

	if (player_hp > 0)
	{
		player_update();
	}

	GameLib::setBlendMode(Blender::BS_ALPHA);
	camera_update();
	strong_enemy_update();
	field_update();
	gimick_update();
	timer_update();
	heart_update();
	heal_update();
	enemy_update();




	if (go_next)
	{
		nextScene = SCENE_STAGE3;
	}


}
void stage2_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	attack_line_render();
	player_render();
	heal_render();
	hiyoko_render();
	strong_enemy_render();
	enemy_render();
	gimick_render();
	heart_render();
	timer_render();


}
void stage2_deinit()
{
	player_deinit();
	field_deinit();
	gimick_deinit();
	strong_enemy_deinit();
	attack_line_delete();
	timer_deinit();
	heart_deinit();
	sound_deinit();
	heal_deinit();
	enemy_deinit();
	hiyoko_deinit();

}
