#include "all.h"
#include <sstream>

int result_state = 0;     // 状態
int result_timer = 0;     // タイマー
Sprite* sprResult = nullptr;
bool retry_check = false;

void result_init()
{
	sprResult = sprite_load(L"Data/Images/result.png");
}
void result_update()
{
	switch (result_state)
	{
	case 0:

		result_state++;
		/*fallthrough*/
	case 1:
		GameLib::setBlendMode(Blender::BS_ALPHA);

		result_state++;
		/*fallthrough*/
	case 2:
		std::ostringstream oss;									// 文字列ストリーム
		POINT point;												// 位置用の変数を宣言する
		GetCursorPos(&point);										// スクリーン座標を取得する
		ScreenToClient(window::getHwnd(), &point);				// クライアント座標に変換する
		//この方法はvisualStudioでMouse.hを使わずにWindows側からマウスの座標を取得する方法
		int mouseX = point.x;
		int mouseY = point.y;
		if (mouseX >= 800 && mouseX <= 1130 && mouseY >= 500 && mouseY <= 520)
		{
			retry_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				nextScene = SCENE_TITLE;
			}
		}
		else
		{
			retry_check = false;
		}
		/*if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
		}
		break;*/
	}

	result_timer++;


}
void result_render()
{
	font::textOut(1, "YOU_DIED", 700, 200);
	if (retry_check)
	{
		font::textOut(1, "> RETRY <", 760, 400);
	}
	else
	{
		font::textOut(1, "RETRY", 800, 400, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f);
	}
	sprite_render(sprResult, 0.0f, 0.0f);

	font::textOut(1, "PRESS BackSpace KEY", 0, 0);

}
void result_deinit()
{
	sprResult;
}