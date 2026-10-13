#include "all.h"
#include <sstream>
#include "player.h"

int title_state = 0;     // 状態
int title_timer = 0;     // タイマー
bool start_check = false;
bool tutrial_check = false;
bool end_check = false;
float start_alpha = 0.5f;
float tutrial_alpha = 0.5f;
float end_alpha = 0.5f;
Sprite* spr_title;
Sprite* spr_gameStart;
Sprite* spr_gameEnd;
Sprite* spr_tutrial;
Sprite* spr_title_letter;

void title_init()
{
	/*DirectX::Mouse::Get().SetWindow(window::getHwnd());*/
	player_hp = PLAYER_HP;
	spr_title = sprite_load(L"Data/Images/タイトル.png");
	spr_gameStart = sprite_load(L"Data/Images/ゲームスタート.png");
	spr_gameEnd = sprite_load(L"Data/Images/ゲームの終了.png");
	spr_tutrial = sprite_load(L"Data/Images/チュートリアル.png");
	spr_title_letter = sprite_load(L"Data/Images/タイトル文字.png");
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
			nextScene = SCENE_STAGE5;
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

		if (mouseX >= 1300 && mouseX <= 1660 && mouseY >= 400 && mouseY <= 520)
		{
			start_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				nextScene = SCENE_STAGE1;
			}
		}
		else
		{
			start_check = false;
		}
		if (mouseX >= 1300 && mouseX <= 1660 && mouseY >= 600 && mouseY <= 720)
		{
			tutrial_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				nextScene = SCENE_TUTRIAL;
			}
		}
		else
		{
			tutrial_check = false;
		}
		if (mouseX >= 1300 && mouseX <= 1660 && mouseY >= 800 && mouseY <= 920)
		{
			end_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				exit(0);
			}
		}
		else
		{
			end_check = false;
		}
		
		if (start_check)
		{
			start_alpha += 0.05f;
			if (start_alpha > 1.0f)
			{
				start_alpha = 1.0f;
			}
		}
		else
		{
			start_alpha -= 0.05f;
			if (start_alpha < 0.5f)
			{
				start_alpha = 0.5f;
			}
		}
		if (tutrial_check)
		{
			tutrial_alpha += 0.05f;
			if (tutrial_alpha > 1.0f)
			{
				tutrial_alpha = 1.0f;
			}
		}
		else
		{
			tutrial_alpha -= 0.05f;
			if (tutrial_alpha < 0.5f)
			{
				tutrial_alpha = 0.5f;
			}
		}
		if (end_check)
		{
			end_alpha += 0.05f;
			if (end_alpha > 1.0f)
			{
				end_alpha = 1.0f;
			}
		}
		else
		{
			end_alpha -= 0.05f;
			if (end_alpha < 0.5f)
			{
				end_alpha = 0.5f;
			}
		}
		
		break;

	}
		
	}

	title_timer++;

}
void title_render()
{
	/*GameLib::clear(0.2f, 0.2f, 0.2f);*/
	sprite_render(spr_title, 0.0f, 0.0f);

	sprite_render(spr_title_letter, 150, 90);
	GameLib::setBlendMode(Blender::BS_ALPHA);
	sprite_render(spr_gameStart,
		1305, 405,
		0.52f, 0.52f,
		0.0f, 0.0f,
		720.0f, 320.0f,
		0.0f, 0.0f,
		ToRadian(0),
		1.0f, 1.0f, 1.0f, start_alpha);
	sprite_render(spr_tutrial,
		1305, 605,
		0.52f, 0.52f,
		0.0f, 0.0f,
		720.0f, 320.0f,
		0.0f, 0.0f,
		ToRadian(0),
		1.0f, 1.0f, 1.0f, tutrial_alpha);
	sprite_render(spr_gameEnd,
		1305, 805,
		0.52f, 0.52f,
		0.0f, 0.0f,
		720.0f, 320.0f,
		0.0f, 0.0f,
		ToRadian(0),
		1.0f, 1.0f, 1.0f, end_alpha);
	if (start_check)
	{
		GameLib::setBlendMode(Blender::BS_ADD);
		sprite_render(spr_gameStart,
			1300, 400,
			0.5f, 0.5f,
			0.0f, 0.0f,
			720.0f, 320.0f,
			0.0f, 0.0f,
			ToRadian(0),
			1.0f, 1.0f, 1.0f, 0.25f);
	}
	GameLib::setBlendMode(Blender::BS_ALPHA);
	if (tutrial_check)
	{
		GameLib::setBlendMode(Blender::BS_ADD);
		sprite_render(spr_tutrial,
			1300, 600,
			0.5f, 0.5f,
			0.0f, 0.0f,
			720.0f, 320.0f,
			0.0f, 0.0f,
			ToRadian(0),
			1.0f, 1.0f, 1.0f, 0.25f);
	}
	GameLib::setBlendMode(Blender::BS_ALPHA);
	if (end_check)
	{
		GameLib::setBlendMode(Blender::BS_ADD);
		sprite_render(spr_gameEnd,
			1300, 800,
			0.5f, 0.5f,
			0.0f, 0.0f,
			720.0f, 320.0f,
			0.0f, 0.0f,
			ToRadian(0),
			1.0f, 1.0f, 1.0f, 0.25f);
	}
	GameLib::setBlendMode(Blender::BS_ALPHA);
	
	
	
	/*if((title_timer / 30) % 2 == 0)
	{ 
		font::textOut(1, "GAME START", 800, 400);
	}*/

}
void title_deinit()
{
	safe_delete(spr_title);
	safe_delete(spr_gameStart);
	safe_delete(spr_gameEnd);
	safe_delete(spr_tutrial);
	safe_delete(spr_title_letter);
}
