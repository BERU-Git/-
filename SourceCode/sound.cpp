#include "all.h"
#include "sound.h"



void sound_init()
{
	music::load(TITLE_SELECT, L"./Data/Sounds/タイトル選択音.wav");   // メニューなどのSE
	music::load(TITLE_DECISION, L"./Data/Sounds/タイトル決定音.wav");   // メニューなどのSE


}

void sound_deinit()
{
	music::clear();

}