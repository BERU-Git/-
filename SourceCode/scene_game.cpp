#include "all.h"
#include "field.h"

int game_state = 0;     // 状態
int game_timer = 0;     // タイマー




void game_init()
{
	field_init();
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
	
		field_update();

	
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


	font::textOut(2, "GAME", 100, 200, 2, 2);

}

void game_deinit()
{
	field_deinit();


}
