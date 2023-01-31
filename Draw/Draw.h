#pragma once



#include "Local.h"





struct Draw
{
    Gdiplus::Graphics* Graphic;


    Gdiplus::Graphics* HandleGraphic;


    Gdiplus::Bitmap* Bitmap;



    Draw_Draw_Method Method;



    Int Handle;


    Object Size;
};




Draw* Draw_Draw_Pointer(Object o);



Draw_Draw_Method Draw_Draw_GetMethodAddress(Object o);






Bool Draw_Draw_CreateRect(Gdiplus::Rect* result, Int left, Int up, Int width, Int height);