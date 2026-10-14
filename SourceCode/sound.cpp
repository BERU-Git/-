#include "all.h"
#include "sound.h"



void sound_init()
{
	music::load(TITLE_SELECT, L"./Data/Sounds/タイトル選択音.wav");   
	music::load(TITLE_DECISION, L"./Data/Sounds/タイトル決定音.wav");   
	music::load(ENEMY_DEFEAT, L"./Data/Sounds/ゴブリン消える音.wav");
	music::load(JAST_AVOID, L"./Data/Sounds/jast_avoid.wav");
	music::load(STRONG_ENEMY_PREP, L"./Data/Sounds/ナイト_動き始め.wav");
	music::load(BARRIER_BREAK, L"./Data/Sounds/barrier_break.wav");
	music::load(BOSS_RUMBLE, L"./Data/Sounds/boss_rumble.wav");
	music::load(BOSS_RUMBLE, L"./Data/Sounds/boss_rumble.wav");
	music::load(BOSS_ROAR, L"./Data/Sounds/ラスボス咆哮.wav");
	music::load(CHARGE, L"./Data/Sounds/突進.wav");
	music::load(DAMAGE, L"./Data/Sounds/damage.wav");
	music::load(RESURRECTION, L"./Data/Sounds/resurrection.wav");
	music::load(DECOY_EXPLOSION, L"./Data/Sounds/Explosion.wav");
	music::load(TROLL_EXPLOSION, L"./Data/Sounds/troll_attack.wav");
	music::load(TITLE_BGM, L"./Data/Sounds/title_bgm.wav");
	music::load(FIELD_BGM, L"./Data/Sounds/field_bgm.wav");
	music::load(BOSS_BGM, L"./Data/Sounds/boss_bgm.wav");
	music::load(RESLUT_BGM, L"./Data/Sounds/result_bgm.wav");
	music::load(HEAL, L"./Data/Sounds/heal.wav");
	music::load(BOSS_DAMAGE_RUMBLE, L"./Data/Sounds/boss_damage_rumble.wav");




}

void sound_deinit()
{
	music::clear();

}