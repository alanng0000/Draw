#pragma once



#include "Local.h"







#include <windows.h>


#include <gdiplus.h>





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