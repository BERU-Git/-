#include "all.h"
#include "timer.h"
#include "player.h"
#include "scene_title.h"
#include "sound.h"
#include <sstream>

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
	timer_init();

	seconds_1.x = 649;
	seconds_1.y = 600;

	seconds_10.x = 585;
	seconds_10.y = 600;

	colon_pos.x = 545;
	colon_pos.y = 600;

	minutes_1.x = 505;
	minutes_1.y = 600;

	minutes_10.x = 441;
	minutes_10.y = 600;


	sprResult = sprite_load(L"Data/Images/タイトル.png");
	spr_result_crear = sprite_load(L"Data/Images/ダンジョン制覇.png");
	spr_result_timer = sprite_load(L"Data/Images/クリアタイム.png");
	spr_result_return_title = sprite_load(L"Data/Images/タイトルに戻る.png");
	spr_result_retry = sprite_load(L"Data/Images/リトライ.png");

	sound_init();

	music::play(RESLUT_BGM, true);


	sound_check = false;
}
void result_update()
{
	timer_update();
		GameLib::setBlendMode(Blender::BS_ALPHA);

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
			if (GetAsyncKeyState(VK_LBUTTON) & 1)
			{
				music::play(TITLE_DECISION);
				game_timer = 0;
				player_hp = PLAYER_HP;
				seconds_pos_1 = 0;
				seconds_pos_10 = 0;
				minutes_pos_1 = 0;
				minutes_pos_10 = 0;


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
			if (GetAsyncKeyState(VK_LBUTTON) & 1)
			{
				music::play(TITLE_DECISION);
				game_timer = 0;
				player_hp = PLAYER_HP;
				nextScene = SCENE_TITLE;
			}
		}
		else
		{
			return_check = false;
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

	//タイトルの選択SE
	if ((retry_check || return_check)
		&& !sound_check)
	{
		music::play(TITLE_SELECT);
		sound_check = true;
	}

	if (!retry_check && !return_check)
	{
		sound_check = false;
	}


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
timer_render();

}
void result_deinit()
{
	timer_deinit();
	safe_delete(sprResult);
	safe_delete(spr_result_crear);
	safe_delete(spr_result_timer);
	safe_delete(spr_result_return_title);
	safe_delete(spr_result_retry);
	sound_deinit();

}