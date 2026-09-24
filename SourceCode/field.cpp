#include "all.h"
Sprite* spr_field;


void field_init()
{

spr_field = sprite_load(L"Data/images/Field_01.png");

}

void field_update()
{

}

void field_render()
{
	sprite_render(spr_field, 0, 0);
}

void field_deinit()
{
	safe_delete(spr_field);
}