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
#include "heart.h"
#include "hiyoko.h"



void tutrial_init()
{
	player_init();
	
	enemy_init();
	field_init();
	camera_init();
	gimick_init();
	attack_line_init();
	hiyoko_init();
	heart_init();
}
void tutrial_update()
{
		player_update();
		enemy_update();
		GameLib::setBlendMode(Blender::BS_ALPHA);
		attack_line_update();
		field_update();
		camera_update();
		gimick_update();//gimick_updateì‚Á‚½‚©‚çŒÄ‚ñ‚¾
		hiyoko_update();
		heart_update();



		if (go_next)
		{
			nextScene = SCENE_TITLE;
		}

		
}

void tutrial_render()
{
	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	attack_line_render();
	player_render();
	enemy_render();
	gimick_render();
	hiyoko_render();
	heart_render();
}
void tutrial_deinit()
{
	player_deinit();
	enemy_deinit();
	field_deinit();
	attack_line_delete();
	gimick_deinit();
	hiyoko_deinit();
	heart_deinit();
}