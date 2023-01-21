#pragma once




#include <Infra.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif





ObjectApi(Draw, Draw)





Draw_Api
Int Draw_Draw_GetHandle(Object o);




Draw_Api
Bool Draw_Draw_SetHandle(Object o, Int value);





Draw_Api
Object Draw_Draw_GetSize(Object o);




Draw_Api
Bool Draw_Draw_SetSize(Object o, Object value);





Draw_Api
Int Draw_Draw_GetMethod(Object o);




Draw_Api
Bool Draw_Draw_SetMethod(Object o, Int value);






Draw_Api
Bool Draw_Draw_Clear(Object o, Int color);





Draw_Api
Bool Draw_Draw_Rect(Object o, Object brush, SInt left, SInt up, Int width, Int height);







ObjectApi(Draw, ColorBrush)







Draw_Api
Int Draw_ColorBrush_GetColor(Object o);



Draw_Api
Bool Draw_ColorBrush_SetColor(Object o, Int value);





Draw_Api
Bool Draw_FrameDrawHandle(Object frame, Object arg);






typedef Bool (*Draw_Draw_Method)(Object draw);






Draw_Api
Bool Draw_Init();




Draw_Api
Bool Draw_Final();