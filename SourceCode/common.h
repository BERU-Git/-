#ifndef COMMON_H
#define COMMON_H

#define SCREEN_W        1920
#define SCREEN_H        1080

#define WORLD_W         5760
#define WORLD_H         3240

#define PLAYER_W        128
#define PLAYER_H        128

#define ENEMY_W         128
#define ENEMY_H         128
#define NORMAL_ENEMY_HITBOX    100

#define CHARGE_CHECK_W  520

#define WALL_W         256
#define WALL_H         1180

#define WALLSIDE_W     128
#define WALLSIDE_H     488

#define WALLDOWN_W     576
#define WALLDOWN_H     128

#define FIELD_W         1920
#define FIELD_H         1080

#define ACCELERATION    0.5f
#define DECELERATION    0.78f

#define ENEMY_SPEED     4.5f
#define MIN_SPEED      -10.0f
#define MAX_SPEED       10.0f
#define CHARGE_SPEED    20.0f

#define CHARGE_TIME     60.0f
#define CHARGE_PREP_TIME     90.0f
#define COOLDOWN_TIME     180.0f

#define ENEMY_MAX       50
#define NORMAL_ENEMY_DISTANCE   80.0f 

#define SCENE_NONE 0
#define SCENE_TITLE 1
#define SCENE_GAME 2
#define SCENE_RESULT 3

#define MOUSE_LIMIT_X_RIGHT 800
#define MOUSE_LIMIT_X_LEFT 1130
#define MOUSE_LIMIT_Y_LEFT 400
#define MOUSE_LIMIT_Y_LEFT 420
#define TEXT_START_X_CHECK_TRUE 760
#define TEXT_START_Y_CHECK_TRUE 400
#define TEXT_START_X_CHECK_FALSE 800
#define TEXT_START_Y_CHECK_FALSE 400

#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI



extern int curScene;
extern int nextScene;


#endif // !COMMON_H
