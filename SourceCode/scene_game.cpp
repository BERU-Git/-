#include "all.h"
#include "field.h"
#include "player.h"
#include "camera.h"
#include "enemy.h"

int game_state = 0;     // 状態
int game_timer = 0;     // タイマー




void game_init()
{
	player_init();
	field_init();
	camera_init();
	game_state = 0;
	game_timer = 0;

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
	GameLib::clear(0.2f, 0.0f, 0.75f);
    field_render();

    player_render();


	

}

void game_deinit()
{
	field_deinit();
	player_deinit();


}
