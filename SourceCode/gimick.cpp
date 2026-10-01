//#include "gimick.h"
//#include "all.h"
//#include "camera.h"
//
//Sprite* spr_gimick = nullptr;
//
//VECTOR2 gimick_pos;
//VECTOR2 gimick_screen;
//
//void gimick_init()
//{
//	spr_gimick = sprite_load(L"Data/images/gimick.jpg");
//	gimick_pos.x = 1000;
//	gimick_pos.y = 600;
//}
//
//void gimick_render()//ƒMƒ~ƒbƒN‚Ì•`‰æ
//{
//	gimick_screen.x = gimick_pos.x - camera_pos.x + SCREEN_W * 0.5f;
//	gimick_screen.y = gimick_pos.y - camera_pos.y + SCREEN_H * 0.5f;
//	sprite_render(spr_gimick,
//		gimick_screen.x, gimick_screen.y,
//		1.0f, 1.0f,
//		0.0f, 0.0f,
//		256, 256,
//		0.0f, 0.0f,
//		ToRadian(0),
//		1.0f, 1.0f, 1.0f, 1.0f);
//}
//
//void gimick_deinit()
//{
//	safe_delete(spr_gimick);
//}
