#pragma once




#include <Infra.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif





ObjectApi(Draw, Draw);





Draw_Api
Int Draw_Draw_GetHandle(Object o);




Draw_Api
Bool Draw_Draw_SetHandle(Object o, Int value);





Draw_Api
Object Draw_Draw_GetSize(Object o);




Draw_Api
Bool Draw_Draw_SetSize(Object o, Object value);






Draw_Api
Bool Draw_Draw_Clear(Object o, Int color);





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