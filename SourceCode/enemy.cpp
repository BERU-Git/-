#include "enemy.h"
#include "all.h"
#include "camera.h"
#include "hit_check.h"
#include "player.h"
Sprite* spr_enemy;
enemy_data enemy[ENEMY_MAX];

void enemy_init()
{
	spr_enemy = sprite_load(L"Data/Images/enemy01.png");

    for (int i = 0; i < ENEMY_MAX; i++)
    {
        bool can_spawn = false;
        enemy[i].speed.x = ENEMY_SPEED;
        enemy[i].speed.y = ENEMY_SPEED;


        while (!can_spawn)
        {
            // 新しい場所を決める
            enemy[i].pos.x = ENEMY_W + rand() % (WORLD_W - ENEMY_W * 2);
            enemy[i].pos.y = ENEMY_H + rand() % (WORLD_H - ENEMY_H * 2);

            can_spawn = true;

            // すでに配置した敵全員とチェック
            for (int j = 0; j < i; j++)
            {
                if (hit_check(
                    enemy[i].pos.x, enemy[i].pos.y, NORMAL_ENEMY_HITBOX * 0.5f,
                    enemy[j].pos.x, enemy[j].pos.y, NORMAL_ENEMY_HITBOX * 0.5f) ||
                    hit_check(
                    player_pos.x, player_pos.y,    SCREEN_H * 0.5f,
                    enemy[i].pos.x, enemy[i].pos.y, ENEMY_W * 0.5f))
                {
                    can_spawn = false;
                    break;
                }
            }
        }
    }
}


void enemy_update()
{
    for (int i = 0; i < ENEMY_MAX; i++)
    {
        if (hit_check(enemy[i].pos.x, enemy[i].pos.y, ENEMY_W * 0.5f,
            player_pos.x, player_pos.y, SCREEN_H * 0.5f))
        {
           float dx = player_pos.x - enemy[i].pos.x;
           float dy = player_pos.y - enemy[i].pos.y;

           enemy[i].angle = atan2f(dy, dx);

           enemy[i].move.x = cosf(enemy[i].angle);
           enemy[i].move.y = sinf(enemy[i].angle);

           enemy[i].pos.x += enemy[i].move.x * enemy[i].speed.x;
           enemy[i].pos.y += enemy[i].move.y * enemy[i].speed.y;

        }
    }



    //エネミーのモーション
    for (int i = 0; i < ENEMY_MAX; i++)
    {
        enemy[i].effect_timer++;

        if (enemy[i].effect_timer % 6 == 0)
        {
            enemy[i].render_posx++;
            enemy[i].render_posx %= 8;
        }

        //エネミーの向き更新
        if (enemy[i].pos.x <= player_pos.x)
        {
            enemy[i].direction = 1;
        }
        else
        {
            enemy[i].direction = -1;
        }
    }

}

void enemy_render()//敵の描画
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i].screen.x = enemy[i].pos.x - camera_pos.x + SCREEN_W * 0.5f;
		enemy[i].screen.y = enemy[i].pos.y - camera_pos.y + SCREEN_H * 0.5f;

		sprite_render(spr_enemy, enemy[i].screen.x, enemy[i].screen.y,
                      enemy[i].direction,1,
					  ENEMY_W * enemy[i].render_posx,0,
			          ENEMY_W,ENEMY_H,
			          ENEMY_W * 0.5f,ENEMY_H * 0.5f);
	}
	
}
void enemy_deinit()
{
	safe_delete(spr_enemy);
}