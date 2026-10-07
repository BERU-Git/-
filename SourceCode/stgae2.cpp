#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "attack_line.h"
#include "hit_check.h"
#include "gimick.h"
#include "strong_enemy.h"
#include "range_enemy.h"

void stage2_init()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i].attack = false;
	}

	attack_line_init();
	player_init();
	camera_init();
	strong_enemy_init();
	field_init();
	gimick_init();
	range_enemy_init();

}
void stage2_update()
{
	GameLib::setBlendMode(Blender::BS_ALPHA);
	camera_update();
	strong_enemy_update();
	player_update();
	field_update();
	gimick_update();
	range_enemy_update();


	debug::setString("hp%d", player_hp);

	if (player_hp <= 0)
	{
		nextScene = SCENE_RESULT;
	}

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
	strong_enemy_render();
	gimick_render();
	range_enemy_render();

}
void stage2_deinit()
{
	player_deinit();
	field_deinit();
	gimick_deinit();
	strong_enemy_deinit();
	attack_line_delete();
	range_enemy_deinit();

}
