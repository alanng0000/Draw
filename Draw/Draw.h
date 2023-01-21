#pragma once



#include "Local.h"







#include <windows.h>


#include <gdiplus.h>





struct Draw
{
    Gdiplus::Graphics* graphic;


    Gdiplus::Graphics* handleGraphic;


    Gdiplus::Bitmap* bitmap;


    Int Handle;


    Object Size;
};




Draw* Draw_Draw_Pointer(Object o);