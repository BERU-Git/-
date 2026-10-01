#include "all.h"
#include "field.h"
#include "player.h"
#include "camera.h"
#include "enemy.h"
#include "hit_check.h"
#include "attack_line.h"
#include "gimick.h"


int game_state = 0;     // 状態
int game_timer = 0;     // タイマー



void game_init()
{
	player_init();
	enemy_init();
	field_init();
	camera_init();
	gimick_init();
	attack_line_init();
	game_state = 0;
	game_timer = 0;

	srand((unsigned int)time(NULL));

}

void game_update()
{
	switch (game_state)
	{
	case 0:

		game_state++;
		/*fallthrough*/
	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;
		/*fallthrough*/
	
	case 2:

		player_update();
		enemy_update();
attack_line_update();
		field_update();
		camera_update();

	
		if (game_timer >= 300)
		{
			nextScene = SCENE_RESULT;
		}

		break;
	}

}

void game_render()
{
	GameLib::clear(0.0f, 0.0f, 0.0f);
    field_render();
	attack_line_render();
    player_render();
	enemy_render();
	gimick_render();
	

}

void game_deinit()
{
	player_deinit();
	enemy_deinit();
	field_deinit();
	attack_line_delete();
	gimick_deinit();

}
