#pragma once


extern "C"
{


#include "Public.h"





extern Int Draw_Draw_Constant_DefaultColor;



extern Object Draw_Global_Data;



}





#include <windows.h>


#include <gdiplus.h>





Gdiplus::Bitmap* Draw_Image_GetBitmap(Object o);



Gdiplus::FontFamily* Draw_FontFamily_GetInternal(Object o);