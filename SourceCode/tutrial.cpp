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
#include "sound.h"
#include "heal.h"

int tutrial_time;
Sprite* spr_tutrial_guide_1;
Sprite* spr_tutrial_guide_2;

VECTOR2 guide1_pos;
VECTOR2 guide2_pos;

VECTOR2 guide1_screen;
VECTOR2 guide2_screen;

void tutrial_init()
{
	spr_tutrial_guide_1 = sprite_load(L"Data/Images/tutrial_guide_1.png");
	spr_tutrial_guide_2 = sprite_load(L"Data/Images/tutrial_guide_2.png");

	player_init();
	sound_init();
	enemy_init();
	field_init();
	camera_init();
	gimick_init();
	attack_line_init();
	hiyoko_init();
	heal_init();
	heart_init();

	tutrial_time = 0;
}
void tutrial_update()
{
	if (player_hp <= 0)
	{
		knock_check = true;
		hiyoko_check = true;
		tutrial_time++;
		if (tutrial_time >= 300)
		{
			music::play(RESURRECTION);
			knock_check = false;
			heal_check = true;
			player_hp = CONTINUE_HP;
			tutrial_time = 0;
		}
	}
	

	if (player_hp > 0)
	{
		player_update();
	}

	enemy_update();
		GameLib::setBlendMode(Blender::BS_ALPHA);
		attack_line_update();
		field_update();
		camera_update();
		gimick_update();
		hiyoko_update();
		heart_update();
		heal_update();




		if (go_next)
		{
			nextScene = SCENE_TITLE;
		}

		
}

void tutrial_render()
{
	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();

	guide1_pos.x = WORLD_W * 0.5f;
	guide1_pos.y = WORLD_H * 0.5f + 512;

	guide1_screen.x = guide1_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	guide1_screen.y = guide1_pos.y - camera_pos.y + SCREEN_H * 0.5f;

	guide2_pos.x = WORLD_W * 0.5f;
	guide2_pos.y = WORLD_H * 0.5f - 512;

	guide2_screen.x = guide2_pos.x - camera_pos.x + SCREEN_W * 0.5f;
	guide2_screen.y = guide2_pos.y - camera_pos.y + SCREEN_H * 0.5f;


	sprite_render(spr_tutrial_guide_1,
				  guide1_screen.x, guide1_screen.y,
				  1, 1,
				  0, 0,
				  GUIDE_W, GUIDE_H,
				  GUIDE_W * 0.5f, GUIDE_H * 0.5f);


	sprite_render(spr_tutrial_guide_2,
				   guide2_screen.x, guide2_screen.y,
		           1,1,
		           0,0,
		           GUIDE_W,GUIDE_H,
		           GUIDE_W * 0.5f, GUIDE_H * 0.5f);


	attack_line_render();
	player_render();
	hiyoko_render();
	heal_render();
	enemy_render();
	gimick_render();
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
	heal_deinit();
	sound_deinit();
	safe_delete(spr_tutrial_guide_1);
	safe_delete(spr_tutrial_guide_2);
}