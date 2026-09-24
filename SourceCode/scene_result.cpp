#include "all.h"

int result_state = 0;     // 状態
int result_timer = 0;     // タイマー

void result_init()
{

}
void result_update()
{
	switch (result_state)
	{
	case 0:
		//////// 初期設定 ////////

		result_state++;
		/*fallthrough*/
	case 1:
		//////// パラメータの設定 ////////

		// ブレンドモードの設定
		GameLib::setBlendMode(Blender::BS_ALPHA);

		result_state++;
		/*fallthrough*/
	case 2:
		//////// 通常時 ////////
		if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
		}
		break;
	}

	result_timer++;


}
void result_render()
{
	GameLib::clear(0.2f, 1.0f, 0.2f);

	font::textOut(1, "PRESS BackSpace KEY", 0, 0);

}
void result_deinit()
{

}