#include "all.h"
#include "field.h"
#include "player.h"
#include "timer.h"
#include "camera.h"
#include "enemy.h"
#include "hit_check.h"
#include "attack_line.h"
#include "gimick.h"
#include <sstream>

int tutrial_state = 0;
int tutrial_timer = 0;


void tutrial_init()
{
	player_init();
	
	enemy_init();
	field_init();
	camera_init();
	gimick_init();
	attack_line_init();

	srand((unsigned int)time(NULL));
}
void tutrial_update()
{
	switch (tutrial_state)
	{
	case 0:
		tutrial_state++;

	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);

		tutrial_state++;

	case 2:
		player_update();
		enemy_update();
		GameLib::setBlendMode(Blender::BS_ALPHA);
		attack_line_update();
		field_update();
		camera_update();
		gimick_update();//gimick_updateì‚Á‚½‚©‚çŒÄ‚ñ‚¾



		if (go_next)
		{
			nextScene = SCENE_TITLE;
		}

		break;
	}
	tutrial_timer++;
}
void tutrial_render()
{
	GameLib::clear(0.8f, 0.2f, 0.5f);
	field_render();
	attack_line_render();
	player_render();
	enemy_render();
	gimick_render();

}
void tutrial_deinit()
{
	player_deinit();
	enemy_deinit();
	field_deinit();
	attack_line_delete();
	gimick_deinit();
	tutrial_deinit();
}