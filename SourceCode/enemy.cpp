#include "enemy.h"
#include "all.h"
#include "camera.h"
#include "hit_check.h"
#include "player.h"
#include "attack_line.h"
Sprite* spr_enemy;
enemy_data enemy[ENEMY_MAX];

void enemy_separate(float pos1_x, float pos1_y,
                    float pos2_x ,float pos2_y,
                    float separate_distance,
                    float& separate_x, float& separate_y)
{
    float away_x = pos1_x - pos2_x;
    float away_y = pos1_y - pos2_y;

    float distance_sq = (away_x * away_x)
        + (away_y * away_y);

    if (distance_sq < separate_distance * separate_distance && distance_sq > 0.0f)
    {
        float distance = sqrtf(distance_sq);

        // 離れる方向を長さ1にして足し合わせる
        separate_x += away_x / distance;
        separate_y += away_y / distance;
    }

}

void enemy_chase(float pos1_x,float pos1_y,
                 float pos2_x,float pos2_y,
                 float& angle,float& chase_x,float& chase_y)
{
    float dx = pos1_x - pos2_x;
    float dy = pos1_y - pos2_y;

    angle = atan2f(dy, dx);

    chase_x = cosf(angle);
    chase_y = sinf(angle);
}


void enemy_init()
{
	spr_enemy = sprite_load(L"Data/Images/enemy01.png");

    for (int i = 0; i < ENEMY_MAX; i++)
    {
        enemy[i] = {};
    }

    for (int i = 0; i < ENEMY_MAX; i++)
    {
        enemy[i].attack = false;
        bool can_spawn = false;
        enemy[i].speed.x = ENEMY_SPEED;
        enemy[i].speed.y = ENEMY_SPEED;

        enemy[i].state = ENEMY_CHASE;
        enemy[i].charge_timer = 0.0f;
        enemy[i].charge_prep_timer = 0.0f;               
        enemy[i].cooldown_timer = 0.0f;



        while (!can_spawn)
        {
            // 新しい場所を決める
            enemy[i].pos.x = (float)(ENEMY_W + rand() % (WORLD_W - ENEMY_W * 2));
            enemy[i].pos.y = (float)(ENEMY_H + rand() % (WORLD_H - ENEMY_H * 2));

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
        switch (enemy[i].state)
        {
        //通常追跡
        case ENEMY_CHASE:
            enemy[i].attack = false;
            //プレイヤーの近くに敵が入ると追跡する
            if (hit_check(enemy[i].pos.x, enemy[i].pos.y, ENEMY_W * 0.5f,
                player_pos.x, player_pos.y, SCREEN_W * 0.5f))
            {

                enemy_chase(player_pos.x, player_pos.y, enemy[i].pos.x, enemy[i].pos.y,
                    enemy[i].angle, enemy[i].chase.x, enemy[i].chase.y);

                enemy[i].separate.x = 0.0f;
                enemy[i].separate.y = 0.0f;

                //敵と敵が反発して重ならないようにする
                for (int j = 0; j < ENEMY_MAX; j++)
                {
                    if (i == j)
                        continue;
                    enemy_separate(enemy[i].pos.x, enemy[i].pos.y,
                        enemy[j].pos.x, enemy[j].pos.y,
                        NORMAL_ENEMY_DISTANCE,
                        enemy[i].separate.x, enemy[i].separate.y);

                }

                enemy[i].move.x = enemy[i].chase.x + enemy[i].separate.x * 0.5f;
                enemy[i].move.y = enemy[i].chase.y + enemy[i].separate.y * 0.5f;

                enemy[i].pos.x += enemy[i].move.x * enemy[i].speed.x;
                enemy[i].pos.y += enemy[i].move.y * enemy[i].speed.y;

                if (hit_check(
                    player_pos.x, player_pos.y, CHARGE_CHECK_W * 0.5f,
                    enemy[i].pos.x, enemy[i].pos.y, ENEMY_W * 0.5f))
                {

            enemy[i].charge_prep_timer = 0.0f;
                    enemy[i].state = ENEMY_CHARGE_PREP;
                }
            }
                break;
         //突進待機
        case ENEMY_CHARGE_PREP:
            enemy[i].attack = true;
            enemy[i].charge_prep_timer++;
            enemy_chase(player_pos.x, player_pos.y,
                enemy[i].pos.x, enemy[i].pos.y,
                enemy[i].angle, enemy[i].chase.x, enemy[i].chase.y);

            enemy[i].charge_direction.x = enemy[i].chase.x;
            enemy[i].charge_direction.y = enemy[i].chase.y;

            attack_line[i].pos.x = enemy[i].pos.x;
            attack_line[i].pos.y = enemy[i].pos.y;



            if (enemy[i].charge_prep_timer >= CHARGE_PREP_TIME)
            {
                enemy[i].state = ENEMY_CHARGE;
            }

            break;
        //突進
        case ENEMY_CHARGE:
            enemy[i].charge_timer += 1.0f;

            enemy[i].pos.x += enemy[i].charge_direction.x * CHARGE_SPEED;
            enemy[i].pos.y += enemy[i].charge_direction.y * CHARGE_SPEED;

            for (int j = 0; j < ENEMY_MAX; j++)
            {
                if (i == j)
                    continue;

                if (hit_check(
                    enemy[i].pos.x, enemy[i].pos.y, NORMAL_ENEMY_HITBOX * 0.5f,
                    enemy[j].pos.x, enemy[j].pos.y, NORMAL_ENEMY_HITBOX * 0.5f))
                {
                    enemy[j].pos.x = (float)(ENEMY_W + rand() % (WORLD_W - ENEMY_W * 2));
                    enemy[j].pos.y = (float)(ENEMY_H + rand() % (WORLD_H - ENEMY_H * 2));
                    enemy[j].attack = false;
                }
            }

            if (enemy[i].charge_timer >= CHARGE_TIME || 
                enemy[i].pos.x >= WORLD_W - ENEMY_W * 0.7f || enemy[i].pos.x <= ENEMY_W * 0.7f ||
                enemy[i].pos.y >= WORLD_H - ENEMY_H * 0.7f || enemy[i].pos.y <= -ENEMY_H * 0.1f)
            {
                enemy[i].charge_timer = 0.0f;
                enemy[i].state = ENEMY_COOLDOWN;
            }

            break;
        //クールダウン
        case  ENEMY_COOLDOWN:
            enemy[i].attack = false;
            enemy[i].cooldown_timer += 1.0f;

            if (enemy[i].cooldown_timer >= COOLDOWN_TIME)
            {
                enemy[i].cooldown_timer = 0.0f;
                enemy[i].state = ENEMY_CHASE;
            }


            break;
            
        }

        //移動範囲制限
        clamp_position(enemy[i].pos.x, enemy[i].pos.y, ENEMY_W, ENEMY_H,
            enemy[i].speed.x, enemy[i].speed.y);
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