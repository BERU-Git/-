#include "all.h"
#include <sstream>

int title_state = 0;     // 状態
int title_timer = 0;     // タイマー
bool start_check = false;

void title_init()
{
	/*DirectX::Mouse::Get().SetWindow(window::getHwnd());*/
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
			nextScene = SCENE_STAGE1;
		}
		
	{
		std::ostringstream oss;									// 文字列ストリーム
		POINT point;												// 位置用の変数を宣言する
		GetCursorPos(&point);										// スクリーン座標を取得する
		ScreenToClient(window::getHwnd(), &point);				// クライアント座標に変換する
        //この方法はvisualStudioでMouse.hを使わずにWindows側からマウスの座標を取得する方法
		int mouseX = point.x;
		int mouseY = point.y;
		/*DirectX::Mouse::State mouseState = DirectX::Mouse::Get().GetState();*/

		if (mouseX >= 800 && mouseX <= 1130 && mouseY >= 400 && mouseY <= 420)
		{
			start_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				nextScene = SCENE_STAGE5;
			}
		}
		else
		{
			start_check = false;
		}
		

		

		break;

	}
		
	}

	title_timer++;


}
void title_render()
{
	GameLib::clear(0.2f, 0.2f, 0.2f);

	font::textOut(1, "SAMPLE GAME TITLE", 700, 200);
	if (start_check)
	{
		font::textOut(1, "> GAME START <", 760, 400);
	}
	else
	{
		font::textOut(1, "GAME START", 800, 400, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f);
	}
	/*if((title_timer / 30) % 2 == 0)
	{ 
		font::textOut(1, "GAME START", 800, 400);
	}*/

}
void title_deinit()
{

}