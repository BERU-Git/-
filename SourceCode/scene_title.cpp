#include "all.h"
#include <sstream>
#include "player.h"
#include "sound.h"

int title_enter_timer = 0;
bool start_check = false;
bool tutrial_check = false;
bool end_check = false;
bool sound_check = false;
bool title_enter = false;
bool stage1_enter = false;
bool totrial_enter = false;
float start_alpha = 0.5f;
float tutrial_alpha = 0.5f;
float end_alpha = 0.5f;
float title_zoom = 1.0f;
float title_fade = 0.0f;
Sprite* spr_title;
Sprite* spr_gameStart;
Sprite* spr_gameEnd;
Sprite* spr_tutrial;
Sprite* spr_title_letter;



void title_init()
{
	spr_title = sprite_load(L"Data/Images/タイトル.png");
	spr_gameStart = sprite_load(L"Data/Images/ゲームスタート.png");
	spr_gameEnd = sprite_load(L"Data/Images/ゲームの終了.png");
	spr_tutrial = sprite_load(L"Data/Images/チュートリアル.png");
	spr_title_letter = sprite_load(L"Data/Images/タイトル文字.png");
	player_hp = PLAYER_HP;
	title_enter_timer = 0;
	title_enter = false;
	stage1_enter = false;
	totrial_enter = false;
	title_zoom = 1.0f;
	title_fade = 0.0f;

	sound_init();
	music::play(TITLE_BGM,true);

}
void title_update()
{
	
		if (TRG(0) & PAD_TRG1)
		{
			nextScene = SCENE_STAGE4;
		}

			if (title_enter)
			{
				title_enter_timer++;

				// 背景を拡大
				title_zoom += 0.025f;

				// 90フレーム経過したら暗転開始
				if (title_enter_timer >= 90)
				{
					title_fade += 0.03f;

					if (title_fade >= 1.0f)
					{
						title_fade = 1.0f;
						if (totrial_enter)
						{
						nextScene = SCENE_TUTRIAL;
						}
						else if (stage1_enter)
						{
						nextScene = SCENE_STAGE1;
						}
					}
				}

				return;
				
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
			if (GetAsyncKeyState(VK_LBUTTON) & 1)
			{
				music::play(TITLE_DECISION);
				stage1_enter = true;
				title_enter = true;
				title_enter_timer = 0;
			}
		}
		else
		{
			start_check = false;
		}
		if (mouseX >= 1300 && mouseX <= 1660 && mouseY >= 600 && mouseY <= 720)
		{
			tutrial_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 1)
			{
				music::play(TITLE_DECISION);
				totrial_enter = true;
				title_enter = true;
				title_enter_timer = 0;
			}
		}
		else
		{
			tutrial_check = false;
		}
		if (mouseX >= 1300 && mouseX <= 1660 && mouseY >= 800 && mouseY <= 920)
		{
			end_check = true;
			if (GetAsyncKeyState(VK_LBUTTON) & 1)
			{
				exit(0);
			}
		}
		else
		{
			end_check = false;
		}
		//ゲームスタートの文字をでかくする
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
		//チュートリアルの文字をでかくする
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
		//ゲーム終了の文字をでかくする
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
		//タイトルの選択SE
		if ((start_check || tutrial_check || end_check )
			&& !sound_check)
		{
			music::play(TITLE_SELECT);
			sound_check = true;
		}

		if(!start_check && !tutrial_check && !end_check)
		{
			sound_check = false;
		}
	

	}
		
	



}
void title_render()
{
	// 画面の中心
	float center_x = SCREEN_W * 0.5f;
	float center_y = SCREEN_H * 0.5f;

	// 入口の中心
	float entrance_x = 400.0f;
	float entrance_y = 630.0f;



	// 背景を描画
	sprite_render(spr_title,
		entrance_x, entrance_y,
		          title_zoom, title_zoom,
		          0,0,
		          SCREEN_W,SCREEN_H,
		          entrance_x, entrance_y);


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
	
	
	

}
void title_deinit()
{
	safe_delete(spr_title);
	safe_delete(spr_gameStart);
	safe_delete(spr_gameEnd);
	safe_delete(spr_tutrial);
	safe_delete(spr_title_letter);
	sound_deinit();
}
