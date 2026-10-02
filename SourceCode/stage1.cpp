#include "all.h"
#include "field.h"
#include "player.h"
#include "camera.h"
#include "enemy.h"
#include "hit_check.h"
#include "attack_line.h"
#include "gimick.h"


int stage1_state = 0;     // 状態
int stage1_timer = 0;     // タイマー



void stage1_init()
{
	player_init();
	enemy_init();
	field_init();
	camera_init();
	gimick_init();
	attack_line_init();

	srand((unsigned int)time(NULL));

}

void stage1_update()
{
		GameLib::setBlendMode(Blender::BS_ALPHA);

		player_update();
		enemy_update();
		attack_line_update();
		field_update();
		camera_update();

		debug::setString("hp%d", player_hp);

		if (stage1_timer >= 300)
		{
			nextScene = SCENE_RESULT;
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
	

}

void stage1_deinit()
{
	player_deinit();
	enemy_deinit();
	field_deinit();
	attack_line_delete();
	gimick_deinit();

}
