#ifndef COMMON_H
#define COMMON_H

// 画面の大きさ
#define SCREEN_W        1280
#define SCREEN_H        720

//------------------------------------------------------------------------------
// TODO:05 common.hにシーン用の定数を作成する
//------------------------------------------------------------------------------
#define SCENE_NONE 0
#define SCENE_TITLE 1
#define SCENE_GAME 2
#define SCENE_RESULT 3


// マクロ
#define ToRadian( x )   DirectX::XMConvertToRadians( x )
#define ToDegree( x )   DirectX::XMConvertToDegrees( x )
#define PI              DirectX::XM_PI

//------------------------------------------------------------------------------
// TODO:07 extern宣言を追加する
//------------------------------------------------------------------------------
extern int curScene;
extern int nextScene;


#endif // !COMMON_H
