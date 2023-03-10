#pragma once


extern "C"
{


#include "Public.h"





extern Object Draw_Global_Data;



}





#include <windows.h>


#include <gdiplus.h>





Gdiplus::Bitmap* Draw_Image_GetIntern(Object o);



Gdiplus::FontFamily* Draw_FontFamily_GetInternal(Object o);



Gdiplus::Font* Draw_Font_GetInternal(Object o);



Gdiplus::Brush* Draw_Brush_GetInternal(Object o);







Object Draw_Constant_New();



Bool Draw_Constant_Delete(Object o);



Bool Draw_Constant_Init(Object o);



Bool Draw_Constant_Final(Object o);







Object Draw_Global_New();



Bool Draw_Global_Delete(Object o);




Bool Draw_Global_Init(Object o);



Bool Draw_Global_Final(Object o);