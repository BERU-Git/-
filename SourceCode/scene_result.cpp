#include "all.h"
#include <sstream>

int result_state = 0;     // 状態
int result_timer = 0;     // タイマー
Sprite* sprResult = nullptr;
Sprite* spr_result_crear = nullptr;
Sprite* spr_result_timer = nullptr;
Sprite* spr_result_return_title = nullptr;
Sprite* spr_result_retry = nullptr;
float return_title_alpha = 0.0f;
float retry_alpha = 0.0f;
float return_alpha = 0.0f;
bool return_check = false;
bool retry_check = false;
extern int game_timer;

void result_init()
{
	sprResult = sprite_load(L"Data/Images/タイトル.png");
	spr_result_crear = sprite_load(L"Data/Images/ダンジョン制覇.png");
	spr_result_timer = sprite_load(L"Data/Images/クリアタイム.png");
	spr_result_return_title = sprite_load(L"Data/Images/タイトルに戻る.png");
	spr_result_retry = sprite_load(L"Data/Images/リトライ.png");
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
		if (mouseX >= 1200 && mouseX <= 1700 && mouseY >= 360 && mouseY <= 540)
		{
			retry_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				nextScene = SCENE_STAGE1;
			}
		}
		else
		{
			retry_check = false;
		}
		if (mouseX >= 1050 && mouseX <= 1850 && mouseY >= 660 && mouseY <= 840)
		{
			return_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				nextScene = SCENE_TITLE;
			}
		}
		else
		{
			return_check = false;
		}
		/*if (TRG(0) & PAD_SELECT)
		{
			nextScene = SCENE_TITLE;
		}
		break;*/
	}

	if (retry_check)
	{
		retry_alpha += 0.05f;
		if (retry_alpha > 1.0f)
		{
			retry_alpha = 1.0f;
		}
	}
	else
	{
		retry_alpha -= 0.05f;
		if (retry_alpha < 0.5f)
		{
			retry_alpha = 0.5f;
		}
	}
	if (return_check)
	{
		return_alpha += 0.05f;
		if (return_alpha > 1.0f)
		{
			return_alpha = 1.0f;
		}
	}
	else
	{
		return_alpha -= 0.05f;
		if (return_alpha < 0.5f)
		{
			return_alpha = 0.5f;
		}
	}
	result_timer++;


}
void result_render()
{
	sprite_render(sprResult, 0.0f, 0.0f);
	sprite_render(spr_result_crear, 300, 60);
	sprite_render(spr_result_timer, 100, 350);
	GameLib::setBlendMode(Blender::BS_ALPHA);
	sprite_render(spr_result_retry, 1205, 365, 1.0f, 1.0f, 0.0f, 0.0f, 496, 185, 0.0f, 0.0f, ToRadian(0), 1.0f, 1.0f, 1.0f, retry_alpha);
	sprite_render(spr_result_return_title, 1055, 665, 1.0f, 1.0f, 0.0f, 0.0f, 812, 185, 0.0f, 0.0f, ToRadian(0), 1.0f, 1.0f, 1.0f, return_alpha);
	if (retry_check)
	{
		GameLib::setBlendMode(Blender::BS_ADD);
		sprite_render(spr_result_retry, 1200, 360, 1.0f, 1.0f, 0.0f, 0.0f, 496, 185, 0.0f, 0.0f, ToRadian(0), 1.0f, 1.0f, 1.0f, 0.25f);
	}
	GameLib::setBlendMode(Blender::BS_ALPHA);
	if (return_check)
	{
		GameLib::setBlendMode(Blender::BS_ADD);
		sprite_render(spr_result_return_title, 1050, 660, 1.0f, 1.0f, 0.0f, 0.0f, 812, 185, 0.0f, 0.0f, ToRadian(0), 1.0f, 1.0f, 1.0f, 0.25f);
	}
	GameLib::setBlendMode(Blender::BS_ALPHA);

}
void result_deinit()
{
	safe_delete(sprResult);
	safe_delete(spr_result_crear);
	safe_delete(spr_result_timer);
	safe_delete(spr_result_return_title);
	safe_delete(spr_result_retry);
}