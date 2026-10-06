#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "attack_line.h"
#include "hit_check.h"
#include "gimick.h"
#include "strong_enemy.h"
#include "enemy.h"
#include "range_enemy.h"


void stage3_init()
{
	player_init();
	camera_init();
	strong_enemy_init();
	enemy_init();
	attack_line_init();
	field_init();
	gimick_init();
	range_enemy_init();

}
void stage3_update()
{
	GameLib::setBlendMode(Blender::BS_ALPHA);
	camera_update();
	strong_enemy_update();
	enemy_update();
	player_update();
	field_update();
	gimick_update();
	range_enemy_update();
	debug::setString("hp%d", player_hp);

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
	gimick_render();
	range_enemy_render();

}
void stage3_deinit()
{
	field_deinit();
	player_deinit();
	gimick_deinit();
	enemy_deinit();
	strong_enemy_deinit();
	attack_line_delete();
	range_enemy_deinit();
}
