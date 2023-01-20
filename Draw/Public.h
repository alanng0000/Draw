#pragma once




#include <Infra/Public.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif





Draw_Api
Object Draw_Draw_Create(Int hdc);



Draw_Api
Bool Draw_Draw_Delete(Object o);




Draw_Api
Bool Draw_Draw_Rect(Object o, Object brush, Int left, Int up, Int width, Int height);





Draw_Api
Object Draw_ColorBrush_New();



Draw_Api
Bool Draw_ColorBrush_Delete(Object o);



Draw_Api
Int Draw_ColorBrush_GetColor(Object o);



Draw_Api
Bool Draw_ColorBrush_SetColor(Object o, Int value);