//******************************************************************************
//
//
//      main
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< namespace >-----------------------------------------------------------
using namespace GameLib;

//------< 変数 >----------------------------------------------------------------
//------------------------------------------------------------------------------
// TODO:06 現在のシーンを管理する変数を作成する
//------------------------------------------------------------------------------
int curScene = SCENE_NONE;       //現在
int nextScene = SCENE_TITLE;     //次のシーン

//------------------------------------------------------------------------------
//  WinMain（エントリポイント）
//------------------------------------------------------------------------------
int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)// 使用しない変数は記述しない
{
	// ゲームライブラリの初期設定
	GameLib::init(L"ゲームプログラミングⅠ", (int)SCREEN_W, (int)SCREEN_H, FALSE);

	//// TODO_11
	//game_init();

	while (GameLib::gameLoop())
	{
		//------------------------------------------------------------------------------
		// TODO:08 シーン切り替え処理を作成する
		//------------------------------------------------------------------------------
		if (curScene != nextScene)
		{
			switch (curScene)
			{
			case SCENE_TITLE:
					title_deinit();
					break;
			case SCENE_GAME:
					game_deinit();
					break;
			case SCENE_RESULT:
				result_deinit();
				break;

			}
			//現在のシーンをnextSceneの値に変更する
			curScene = nextScene;
			//新しいシーンの開始処理を行う
			switch (curScene)
			{
			case SCENE_TITLE:
					title_init();
					break;
			case SCENE_GAME:
					game_init();
					break;
			case SCENE_RESULT:
				    result_init();
				    break;

			}


		}



		// 入力処理
		input::update();

		// 現在のシーンを更新・描画
		//------------------------------------------------------------------------------
		// TODO:09 curSceneの値に応じたシーンの更新・描画をする
		//------------------------------------------------------------------------------
		if (curScene == SCENE_GAME)
		{
			game_update();
			game_render();
		}
		else if (curScene == SCENE_TITLE)
		{
			title_update();
			title_render();
		}
		else if (curScene == SCENE_RESULT)
		{
			result_update();
			result_render();
		}




		// デバッグ文字列を描画
		debug::display(1.0f, 1.0f, 1.0f, 1, 1);

		// バックバッファの内容を表示
		GameLib::present(1, 0);
	}
	//------------------------------------------------------------------------------
	// TODO:10 ゲームループ終了後にシーンの終了処理を呼ぶ
	//------------------------------------------------------------------------------
	if (curScene == SCENE_GAME)
	{
	game_deinit();
	}
	if (curScene == SCENE_TITLE)
	{
		title_deinit();
	}
	if (curScene == SCENE_RESULT)
	{
		result_deinit();
	}




	// ゲームライブラリの終了処理
	GameLib::uninit();
}
