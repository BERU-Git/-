#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "hit_check.h"
#include "gimick.h"
#include "troll.h"
#include "attack_line.h"


void stage4_init()
{
	camera_init();
	player_init();
	field_init();
	gimick_init();
	troll_init();
	attack_line_init();
}
void stage4_update()
{
	GameLib::setBlendMode(Blender::BS_ALPHA);
	camera_update();
	player_update();
	field_update();
	gimick_update();
	troll_update();
	attack_line_update()
		;

	if (go_next)
	{
		nextScene = SCENE_STAGE5;
	}


}
void stage4_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	player_render();
	gimick_render();
	troll_render();
	attack_line_render();
	debug::setString("hp%d", player_hp);

}
void stage4_deinit()
{
	player_deinit();
	field_deinit();
	gimick_deinit();
	troll_deinit();
	attack_line_delete();
}
