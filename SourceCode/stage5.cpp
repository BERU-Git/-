#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "gimick.h"
#include "boss.h"
#include "attack_line.h"
#include"timer.h"
#include"sound.h"
#include "hiyoko.h"
#include "heal.h"
#include "heart.h"



int stage5_timer;
int stage5_time;
int stage5_state;
extern int game_timer;

void stage5_init()
{
	boss_stage = true;
	stage5_timer = 0;
	stage5_state = 0;
	sound_init();
	player_init();
	camera_init();
	field_init();
	boss_init();
	timer_init();
	attack_line_init();
	heal_init();
	heart_init();
	hiyoko_init();


}
void stage5_update()
{
	game_timer++;

	if (player_hp <= 0)
	{
		knock_check = true;
		hiyoko_check = true;
		stage5_time++;
		if (stage5_time >= 300)
		{
			knock_check = false;
			heal_check = true;
			if (last_attack == true)
			{
				state = LAST_ATTACK_INIT;
			}
			player_hp = CONTINUE_HP;
			stage5_time = 0;
		}
	}


	GameLib::setBlendMode(Blender::BS_ALPHA);
	stage5_timer++;
	
	camera_update();
	field_update();
	timer_update();
	heal_update();
	heart_update();
	hiyoko_update();
	screen_shake(15);
	
	if (stage5_timer >= 119 && stage5_timer <= 121)
	{
		music::play(BOSS_ROAR);
		music::play(BOSS_RUMBLE);
		
	}


	if (stage5_timer >= 120 && stage5_timer <= 420)
	{
		screen_shake_init(120);
		boss_update_init();
	music::play(BOSS_BGM,true);
	}
	
		
	if (stage5_timer >= 420)
	{
		if(player_hp > 0)
		{
			player_update();
		}

		boss_update();
	}



}
void stage5_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	attack_line_render();
	player_render();
	hiyoko_render();
	heal_render();
	boss_render();
	timer_render();
	heart_render();


}
void stage5_deinit()
{
	boss_stage = false;
	player_deinit();
	field_deinit();
	boss_deinit();
	attack_line_delete();
	timer_deinit();
	sound_deinit();
	heal_deinit();
	heart_deinit();
	hiyoko_deinit();

}
