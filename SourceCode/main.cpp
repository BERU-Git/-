#include "all.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "scene_result.h"
#include "scene_title.h"
#include "tutrial.h"
using namespace GameLib;

int curScene = SCENE_NONE;       //現在
int nextScene = SCENE_TITLE;     //次のシーン
int game_timer = 0;

int APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)// 使用しない変数は記述しない
{
	GameLib::init(L"ゲームプログラミングⅠ", (int)SCREEN_W, (int)SCREEN_H, FALSE);

	while (GameLib::gameLoop())
	{
	debug::setString("time%d", game_timer);
		if (curScene != nextScene)
		{
			switch (curScene)
			{
			case SCENE_TITLE:
					title_deinit();
					break;
			case SCENE_STAGE1:
					stage1_deinit();
					break;
			case SCENE_STAGE2:
					stage2_deinit();
					break;
			case SCENE_STAGE3:
					stage3_deinit();
					break;
			case SCENE_STAGE4:
					stage4_deinit();
					break;
			case SCENE_STAGE5:
					stage5_deinit();
					break;
			case SCENE_RESULT:
				result_deinit();
				break;
			case SCENE_TUTRIAL:
				tutrial_deinit();
				break;
			}
			curScene = nextScene;
			switch (curScene)
			{
			case SCENE_TITLE:
					title_init();
					break;
			case SCENE_STAGE1:
				stage1_init();
					break;
			case SCENE_STAGE2:
				stage2_init();
					break;
			case SCENE_STAGE3:
				stage3_init();
					break;
			case SCENE_STAGE4:
				stage4_init();
					break;
			case SCENE_STAGE5:
				stage5_init();
					break;
			case SCENE_RESULT:
				    result_init();
				    break;
			case SCENE_TUTRIAL:
				tutrial_init();
				break;

			}


		}



		input::update();

		if (curScene == SCENE_STAGE1)
		{
			stage1_update();
			stage1_render();
		}
		else if (curScene == SCENE_STAGE2)
		{
			stage2_update();
			stage2_render();
		}
		else if (curScene == SCENE_STAGE3)
		{
			stage3_update();
			stage3_render();
		}
		else if (curScene == SCENE_STAGE4)
		{
			stage4_update();
			stage4_render();
		}
		else if (curScene == SCENE_STAGE5)
		{
			stage5_update();
			stage5_render();
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
		else if (curScene == SCENE_TUTRIAL)
		{
			tutrial_update();
			tutrial_render();
		}




		debug::display(1.0f, 1.0f, 1.0f, 1, 1);

		GameLib::present(1, 0);
	}
	if (curScene == SCENE_STAGE1)
	{
		stage1_deinit();
	}
	if (curScene == SCENE_STAGE2)
	{
		stage2_deinit();
	}
	if (curScene == SCENE_STAGE3)
	{
		stage3_deinit();
	}
	if (curScene == SCENE_STAGE4)
	{
		stage4_deinit();
	}
	if (curScene == SCENE_STAGE5)
	{
		stage5_deinit();
	}
	if (curScene == SCENE_TITLE)
	{
		title_deinit();
	}
	if (curScene == SCENE_RESULT)
	{
		result_deinit();
	}
	if (curScene == SCENE_TUTRIAL)
	{
		tutrial_deinit();
	}




	GameLib::uninit();
}
