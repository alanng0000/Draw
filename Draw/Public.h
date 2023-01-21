#pragma once




#include <Infra/Public.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif








Draw_Api
Bool Draw_Draw_Create(Int result, Int handle);






Draw_Api
Bool Draw_Draw_Rect(Object o, Object brush, int left, int up, int width, int height);





Draw_Api
Object Draw_ColorBrush_New();



Draw_Api
Bool Draw_ColorBrush_Delete(Object o);



Draw_Api
Int Draw_ColorBrush_GetColor(Object o);



Draw_Api
Bool Draw_ColorBrush_SetColor(Object o, Int value);





Draw_Api
Bool Draw_FrameDrawHandle(Object frame, Int handle, Object arg);






typedef Bool (*Draw_DrawHandle_Method)(Object draw);






Draw_Api
Bool Draw_Init();




Draw_Api
Bool Draw_Final();