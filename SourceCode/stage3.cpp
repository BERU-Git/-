#include "all.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "hit_check.h"
#include "gimick.h"


void stage3_init()
{
	camera_init();
	player_init();
	field_init();
	gimick_init();

}
void stage3_update()
{
	GameLib::setBlendMode(Blender::BS_ALPHA);
	camera_update();
	player_update();
	field_update();
	gimick_update();
}
void stage3_render()
{

	GameLib::clear(0.0f, 0.0f, 0.0f);
	field_render();
	player_render();
	gimick_render();

}
void stage3_deinit()
{
	player_deinit();
	field_deinit();
	gimick_deinit();

}
