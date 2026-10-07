#pragma once
#include "all.h"

enum TROLL_STATE
{
	TROLL_IDLE,
	TROLL_WALK,
	TROLL_ATTACK
};

enum TROLL_ATTACK_STATE
{
	TROLL_ATTACK_START,//‚±‚±‚Í=3‚ÅŽw’è‚µ‚È‚­‚Ä‚à“ü‚Á‚Ä‚¢‚é‰½ŒÌ‚È‚çŠO‘¤‚Ìswitch‚Ì’†‚É“ü‚ê‚éenum‚¾‚©‚ç”í‚ç‚È‚¢
	TROLL_ATTACK_WAIT,
	TROLL_ATTACK_SWING,
	TROLL_ATTACK_END
};
struct troll_data
{
	int act;
	int act_timer;
	int attack_state;
	int attack_timer;
	bool attack_hit;
	VECTOR2 pos;
	float radius;

};

extern bool danger_circle;
extern VECTOR2 troll_screen;
extern troll_data troll;
extern bool danger_circle;

void troll_init();
void troll_update();
void troll_render();
void troll_deinit();
