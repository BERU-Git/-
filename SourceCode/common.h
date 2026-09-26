#ifndef COMMON_H
#define COMMON_H

#define SCREEN_W        1920
#define SCREEN_H        1080

#define PLAYER_W        128
#define PLAYER_H        128

#define FIELD_W         1920
#define FIELD_H         1080

#define MIN_SPEED       -9
#define MAX_SPEED        9

#define SCENE_NONE 0
#define SCENE_TITLE 1
#define SCENE_GAME 2
#define SCENE_RESULT 3

#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI

extern int curScene;
extern int nextScene;


#endif // !COMMON_H
