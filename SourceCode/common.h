#ifndef COMMON_H
#define COMMON_H

#define SCREEN_W        1920           //画面のサイズ
#define SCREEN_H        1080		   //

#define WORLD_W         5760           //フィールドのサイズ
#define WORLD_H         3240		   //

#define PLAYER_W        128            //プレイヤーの画像サイズ
#define PLAYER_H        128	           //

#define ENEMY_W         128            //ゴブリンの画像サイズ
#define ENEMY_H         128			   //

#define STRONG_ENEMY_W  256            //中ボスの画像サイズ
#define STRONG_ENEMY_H  256	           //

#define ENEMY_BULLET_W  64             //玉のサイズ
#define ENEMY_BULLET_H  64             //

#define TIMER_W         64             //タイマー

#define STAIRS_W        256            //階段の画像サイズ
#define STAIRS_H        384            //

#define MAGIC_CIRCLE_W  512            //魔法陣の画像サイズ
#define MAGIC_CIRCLE_H  512            //

#define BOSS_W          672            //ボスのサイズ
#define BOSS_H          512            //

#define BOSS_HAND_W          338       //ボスのサイズ
#define BOSS_HAND_H          512       //

#define NORMAL_ENEMY_HITBOX    100     //ゴブリンのヒットボックス

#define PLAYER_HITBOX         64       //プレイヤーのヒットボックス

#define BOSS_HAND_HITBOX      96       //プレイヤーのヒットボックス

#define BOSS_HITBOX           256       //プレイヤーのヒットボックス

#define DECOY_TOTEM_EXPLOSION 512       //デコイの爆発の直径

#define CHARGE_CHECK_W  520            //突進を認識する範囲

#define WALL_W         256             //壁のサイズ
#define WALL_H         1180			   //

#define WALLSIDE_W     128             //両サイドの壁のサイズ
#define WALLSIDE_H     488			   //

#define WALLDOWN_W     576             //下の壁のサイズ
#define WALLDOWN_H     128			　　//

#define FIELD_W         1920           //フィールドのサイズ
#define FIELD_H         1080		   //

#define BULLET_MAX     20              //エネミーが出す最大の球数

#define RANGE_ATTACK_TIMER    600      //遠距離攻撃の敵の攻撃時間
#define RANGE_PREP_TIMER      180      //遠距離攻撃の敵の攻撃時間
#define RANGE_TELEPORT_TIMER  120      //遠距離攻撃の敵の攻撃時間

#define RANGE_ATTACK_SPEED    10.0f    //エネミー攻撃スピード

#define GIMICK_POS_X_1 512
#define GIMICK_POS_Y_1 512

#define GIMICK_POS_X_2 512
#define GIMICK_POS_Y_2 2726

#define GIMICK_POS_X_3 5248
#define GIMICK_POS_Y_3 512

#define GIMICK_POS_X_4 5248
#define GIMICK_POS_Y_4 2726

#define GIMICK_MAX 4

#define BOSS_CENTER_H   412            //ボスのセンター位置

#define BOSS_HAND_POS    480            //ボスの手の初期値


#define ACCELERATION    0.78f           //プレイヤーの加速度
#define DECELERATION    0.78f          //プレイヤーの減速度

#define ENEMY_SPEED     4.5f           //敵のスピード
#define CHARGE_SPEED    20.0f          //敵の突進のスピード

#define STRONG_ENEMY_SPEED     15.0f    //中ボスのスピード
#define STRONG_CHARGE_SPEED    30.0f   //中ボスの突進のスピード

#define MIN_SPEED      -10.0f          //スピードの最大速度
#define MAX_SPEED       10.0f

#define PLAYER_HP        10            //プレイヤーのHP

#define CONTINUE_HP        5           //コンテニューのHP

#define PLAYER_HEEL       1            //プレイヤー回復量

#define DAMAGE_SHAKE_TIME     30       //ダメージを受けたときの画面シェイクの時間

#define CHARGE_TIME     60.0f          //突進の時間
#define STRONG_CHARGE_TIME     90.0f   //中ボスの突進の時間
#define CHARGE_PREP_TIME     90.0f     //突進準備の時間
#define COOLDOWN_TIME     180.0f       //突進後のクールタイム

#define ENEMY_MAX       25             //敵の最大数
#define NORMAL_ENEMY_DISTANCE   80.0f  //敵同士の間隔

#define ATTACK_LINE_W        100       //攻撃の予兆線
#define ATTACK_LINE_H       1200       //

#define STRONG_ATTACK_LINE_W        256       //中ボスの攻撃の予兆線
#define STRONG_ATTACK_LINE_H       2700       //


#define SCENE_NONE 0
#define SCENE_TITLE 1
#define SCENE_STAGE1 2
#define SCENE_STAGE2 3
#define SCENE_STAGE3 4
#define SCENE_STAGE4 5
#define SCENE_STAGE5 6
#define SCENE_RESULT 7
#define SCENE_TUTRIAL 8


#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI



extern int curScene;
extern int nextScene;


#endif // !COMMON_H
