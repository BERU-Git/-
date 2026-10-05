#pragma once
#include "all.h"

	enum enemy_state
	{
		ENEMY_CHASE,       // 普通に追跡
		ENEMY_CHARGE_PREP, // 突進準備
		ENEMY_CHARGE,      // 突進中
		ENEMY_COOLDOWN     // 突進後の待機
	};

	enum range_enemy_state
	{
		BULLET_CHASE,       // 玉が普通に追跡
		ENEMY_TELEPORT_PREP,     // 攻撃後の待機
		ENEMY_TELEPORT,     // クールタイム
	};
struct enemy_data
{
	VECTOR2 pos = {};
	VECTOR2 speed = {};
	VECTOR2 chase = {};
	VECTOR2 move = {};
	VECTOR2 screen = {};
	VECTOR2 separate = {};
	VECTOR2 charge_direction = {};
	enemy_state state = {};
	range_enemy_state range_state = {};
	int render_posx = 0;
	int render_posy = 0;
	int effect_timer = 0;
	int direction = 0;
	float angle = 0;
	float charge_prep_timer = 0;
	float charge_timer = 0;
	float cooldown_timer = 0;
	bool attack = 0;
};

extern enemy_data enemy[ENEMY_MAX];
extern Sprite* spr_enemy;


void enemy_chase(float pos1_x, float pos1_y, 
	             float pos2_x, float pos2_y,
	             float& angle,float& chase_x, float& chase_y);

void enemy_separate(float pos1_x, float pos1_y,
					float pos2_x, float pos2_y,
					float separate_distance,
					float& separate_x, float& separate_y);


void enemy_init();
void enemy_deinit();
void enemy_update();
void enemy_render();


