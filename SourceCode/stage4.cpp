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
#include "sound.h"
#include "hiyoko.h"
#include "heal.h"
#include "arrow_guide.h"


extern int game_timer;
int stage4_time;

void stage4_init()
{
	field_init();
	player_init();
	camera_init();
	gimick_init();
	attack_line_init();
	enemy_init();
	strong_enemy_init();
	troll_init();
	range_enemy_init();
	timer_init();
	heart_init();
	hiyoko_init();
	heal_init();
	sound_init();
arrow_guide_init();

	music::play(FIELD_BGM, true);


}
void stage4_update()
{

	if (player_hp <= 0)
	{
		knock_check = true;
		hiyoko_check = true;
		stage4_time++;
		if (stage4_time >= 300)
		{
			knock_check = false;
			heal_check = true;
			player_hp = CONTINUE_HP;
			stage4_time = 0;
		}
	}
	if(player_hp > 0)
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
	heal_update();
	hiyoko_update();
arrow_guide_update();




	if (go_next)
	{
		nextScene = SCENE_STAGE5;
	}


}
void stage4_render()
{



	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	attack_line_render();
	player_render();
	hiyoko_render();
	heal_render();
	enemy_render();
	strong_enemy_render();
	troll_render();
	range_enemy_render();
	gimick_render();
	heart_render();
	timer_render();
arrow_guide_render();

}
void stage4_deinit()
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
	sound_deinit();
	heal_deinit();
	hiyoko_deinit();
arrow_guide_deinit();
}
