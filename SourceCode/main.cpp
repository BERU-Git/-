#include "all.h"

using namespace GameLib;

int curScene = SCENE_NONE;       //現在
int nextScene = SCENE_TITLE;     //次のシーン

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)// 使用しない変数は記述しない
{
	GameLib::init(L"ゲームプログラミングⅠ", (int)SCREEN_W, (int)SCREEN_H, FALSE);

	while (GameLib::gameLoop())
	{
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
			curScene = nextScene;
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



		input::update();

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




		debug::display(1.0f, 1.0f, 1.0f, 1, 1);

		GameLib::present(1, 0);
	}
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




	GameLib::uninit();
}
