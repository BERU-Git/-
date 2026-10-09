#include "troll.h"
#include "all.h"
#include "hit_check.h"
#include "player.h"
#include "camera.h"

Sprite* spr_troll = nullptr;
Sprite* spr_exprotion_effect = nullptr;

int troll_attack_anime_timer;
int troll_attack_anime;
int troll_direction;
bool troll_attack_hit;
float troll_speed = 0;
VECTOR2 troll_tex_pos;
VECTOR2 troll_tex_size;
VECTOR2 troll_screen;
bool check;
bool danger_circle;

int effect_anime;
int effect_anime_timer;
VECTOR2 effect_tex_pos;
VECTOR2 effect_tex_size;
int effect_count;
bool effect_judge;
bool effect_check;



troll_data troll;


void troll_init()
{
	troll = {};
	spr_troll = sprite_load(L"Data/images/troll.png");
	spr_exprotion_effect = sprite_load(L"Data/images/爆破エフェクト.png");
	
	troll.act = TROLL_IDLE;
	troll.attack_state = TROLL_ATTACK_START;
	troll_attack_anime = 0;
	troll_attack_anime_timer = 0;
	troll_tex_pos.x = 0.0f;
	troll_tex_pos.y = 0.0f;
	troll_tex_size.x = STRONG_ENEMY_W;
	troll_tex_size.y = STRONG_ENEMY_H;
	troll_attack_anime_timer = 0;
	effect_anime = 0;
	effect_anime_timer = 0;
	effect_tex_pos.x = 0.0f;
	effect_tex_pos.y = 0.0f;
	effect_tex_size.x = 512.0f;
	effect_tex_size.y = 512.0f;
	effect_check = false;
	effect_count = 0;
	effect_judge = false;

	bool can_spawn = false;

	while(!can_spawn)
	{
		troll.pos.x = STRONG_ENEMY_W + rand() % WORLD_W - STRONG_ENEMY_W * 2.0f; //実際にtrollがいるposition
		troll.pos.y = STRONG_ENEMY_H + rand() % WORLD_H - STRONG_ENEMY_H * 2.0f;

		can_spawn = true;

		if (hit_check(
			player_pos.x, player_pos.y, SCREEN_H * 0.5f,
			troll.pos.x, troll.pos.y, STRONG_ENEMY_W * 0.5f))
		{
			can_spawn = false ;
			break;
		}
	}


	troll.radius = 500.0f;
	troll_direction = 0;
	troll_speed = 3.0f;
	troll_attack_hit = false;
	check = false;
	danger_circle = false;

}

//bool effect_animation(int startFrame, int endFrame, int frameSpeed)
//{
//	int total = endFrame - startFrame + 1;
//	effect_anime = effect_anime_timer / frameSpeed;
//	int check_frame = startFrame + effect_anime;
//	if (check_frame < 8)
//	{
//		effect_tex_pos.x = check_frame * effect_tex_size.x;
//		effect_tex_pos.y = 0.0f;
//	}
//	else
//	{
//		effect_tex_pos.x = (check_frame - 8);
//		effect_tex_pos.y = effect_tex_size.y;
//	}
//	effect_anime_timer++;
//	return false;
//}

bool troll_animation_variation(int startFrame, int endFrame, int frameSpeed, bool loop)//アニメーションの?コマから?コマまでを再生する関数
//startFrameは始まりのコマ。endFrameが終わりのフレーム。frameSpeedは1コマ？フレームか。loopはループするかどうか
//テストしながらコード足しまくってるから無駄多いかも
{
	int total = endFrame - startFrame + 1;
	troll_attack_anime = troll_attack_anime_timer / frameSpeed;
	if (loop)
	{
		if (troll_attack_anime >= total)
		{
			troll_attack_anime = 0;
			troll_attack_anime_timer = 0;
		}
	}
	else
	{
		troll_attack_anime = total - 1;//最後の1コマで止めておく
	}
	int check_frame = startFrame + troll_attack_anime;
		
		if (check_frame < 5)//一段目かどうかのチェック
		{
			troll_tex_pos.x = check_frame * troll_tex_size.x;
			troll_tex_pos.y = 0.0f;
		}
		else//2段目にも対応できるように5を超えたら2段目に移行させる
		{
				troll_tex_pos.x = (check_frame - 5)/*WALKが5までしかないから*/ * troll_tex_size.x;
				troll_tex_pos.y = troll_tex_size.y;//読み込んでる座標分丸々下げる
		}
		if (!loop && troll_attack_anime_timer / frameSpeed >= total)//troll_anime_timerは増え続けてframeSpeedで割ってあげるとその合計がtotal,つまり読み込む合計の画像枚数と一致より上でかつループじゃない、つまり
		//非ループかつ最後までアニメーションを行っている場合のみtrueを返す
		//何故こんなめんどくさいことをしている？←アニメーションのバグが多すぎたから処理できてる場合のみに絞ると処理の行えているかの
		// 有無がわかりやすい＋今後アニメーションをいじってもバグの原因を突き止めやすいからこのままにしている。
		{
			return true;
		}
	++troll_attack_anime_timer;
	return false;
}
void troll_update()//ボスのアクション
{
	if (effect_judge)
	{
		effect_anime_timer++;
		if ((effect_anime_timer) % 4 == 0)
		{
			effect_count++;
			effect_tex_pos.x = (512.0f * effect_count);
		}
		if (effect_count == 8)
		{
			effect_tex_pos.y = effect_tex_size.y;
		}
		if (effect_count > 16)
		{
			effect_count = 0;
			effect_judge = false;
		}
	}
	if (player_pos.x < troll.pos.x)
	{
		troll_direction = -1;
		
	}
	else
	{
		troll_direction = 1;
	}
	switch (troll.act)
	{
	case TROLL_IDLE:
	{
		troll.act_timer++;
		if (hit_check(troll.pos.x, troll.pos.y, 500.0f, player_pos.x, player_pos.y, player_direction))//もしplayerとtrollとの距離が400を切ったらTROLL_ATTACKに移行それ以外ならTROLL_WALK
		{
			troll.act = TROLL_ATTACK;
			troll.attack_state = TROLL_ATTACK_START;
			troll.attack_timer = 0;
			troll_attack_anime_timer = 0;
			troll_attack_anime = 0;
			danger_circle = true;
		}
		else
		{
			troll.act = TROLL_WALK;//ここに処理書いてもよかったけどわかりやすいように分けておきます
			troll_attack_anime_timer = 0;
		}

		break;
	}
	case TROLL_WALK:
	{
		float tentative_x = player_pos.x - troll.pos.x;
		float tentative_y = player_pos.y - troll.pos.y;
		float distance = sqrtf(tentative_x * tentative_x + tentative_y * tentative_y);//この中だけで一時的に使う

		if (distance > 0.0f)//playerを追従するコード
		{
			tentative_x /= distance;
			tentative_y /= distance;

			troll.pos.x += tentative_x * troll_speed;//これでtroll_speedを変更するだけで速度を変えやすい
			troll.pos.y += tentative_y * troll_speed;
		}
		troll_animation_variation(0, 3, 20, true);//ループするからtrue

		if (hit_check(troll.pos.x, troll.pos.y, 300.0f,
			player_pos.x, player_pos.y, player_direction))
		{
			troll.act = TROLL_ATTACK;
			troll.attack_state = TROLL_ATTACK_START;
			troll.attack_timer = 0;
			troll_attack_anime_timer = 0;
			troll_attack_anime = 0;
			danger_circle = true;
			//到達できてる
		}
		break;
	}
	case TROLL_ATTACK:
	{
		switch (troll.attack_state)//ATTACKだけにして中に書いてもよかったけど複雑になりそうだから小分けにする
		{
		case TROLL_ATTACK_START:
			if (troll_animation_variation(5, 6, 6, false))
			{
				troll.attack_state = TROLL_ATTACK_WAIT;
				troll.attack_timer = 0;
			

			}
			break;



		case TROLL_ATTACK_WAIT:
		{
			troll.attack_timer++;
			troll_tex_pos.x = 1 * troll_tex_size.x;//7番目でtroll.attack_timerが30、つまり0.5秒間停止
			//ここの１は内部的には(6 - 1)ちなみに上の7番目はフレーム番号では6番目
			troll_tex_pos.y = troll_tex_size.y;

			if (troll.attack_timer >= 30)
			{
				troll.attack_state = TROLL_ATTACK_SWING;
				troll_attack_anime = 0;
				troll_attack_anime_timer = 0;
				//到達
			}
			break;
		}
		case TROLL_ATTACK_SWING:
		{
			check = true;
			bool anime_end = troll_animation_variation(7, 8, 4, false);//end状態に移行してあげて一回まっさらにしてからIDLEに戻す
			

			if (!troll_attack_hit)
			{
				
				if (hit_check(player_pos.x, player_pos.y, PLAYER_HITBOX * 0.5,
					troll.pos.x, troll.pos.y, troll.radius))
				{
					troll_attack_hit = true;
					player_hp -= 5;

					effect_check = true;
					effect_judge = true;
					
					
					
				}
			}
			if (anime_end)
			{

				troll.attack_state = TROLL_ATTACK_END;
				troll.attack_timer = 0;
			}
			break;
		}
		case TROLL_ATTACK_END:
		{
			troll.attack_timer++;
			if (troll.attack_timer >= 180)
			{
				troll.act = TROLL_IDLE;
				troll.act_timer = 0;
				troll.attack_timer = 0;
				troll_attack_anime_timer = 0;
				troll_attack_anime = 0;
				troll_attack_hit = false;
				danger_circle = false;
				effect_check = false;
			}
			break;
		}
		}

	break;
	}
}

			/*debug::setString("anime_end%d", check);
			debug::setString(
				"act = %d  attack_state = %d  attack_timer = %d  anime = %d",
				troll.act,
				troll.attack_state,
				troll.attack_timer,
				troll_attack_anime
			);*/

}
void troll_render()
{
	troll_screen.x = troll.pos.x - camera_pos.x + SCREEN_W * 0.5f;
	troll_screen.y = troll.pos.y - camera_pos.y + SCREEN_H * 0.5f;
	sprite_render(spr_troll,
		troll_screen.x, troll_screen.y,
		2.0f * troll_direction, 2.0f,
		troll_tex_pos.x, troll_tex_pos.y,
		troll_tex_size.x, troll_tex_size.y,
		128 , 128);

	if (effect_check)
	{
		sprite_render(spr_exprotion_effect, troll_screen.x, troll_screen.y, 2.7f, 2.7f, effect_tex_pos.x, effect_tex_pos.y, effect_tex_size.x, effect_tex_size.y, 256, 256);
	}
	

	


}
void troll_deinit()
{
	troll = {};
	safe_delete(spr_troll);
	
}

	