#include "all.h"

int title_state = 0;     // 状態
int title_timer = 0;     // タイマー

void title_init()
{

}
void title_update()
{
	switch (title_state)
	{
	case 0:
		//////// 初期設定 ////////

		title_state++;
		/*fallthrough*/
	case 1:
		//////// パラメータの設定 ////////

		// ブレンドモードの設定
		GameLib::setBlendMode(Blender::BS_ALPHA);

		title_state++;
		/*fallthrough*/
	case 2:
		//////// 通常時 ////////
		if (TRG(0) & PAD_TRG1)
		{
			nextScene = SCENE_GAME;
		}
		break;
	}

	title_timer++;


}
void title_render()
{
	GameLib::clear(0.2f, 0.2f, 0.2f);

	font::textOut(1, "GAME", 640, 200);
	if((title_timer / 30) % 2 == 0)
	{ 
		font::textOut(1, "PRESS SPACE KEY", 640, 300);
	}

}
void title_deinit()
{

}