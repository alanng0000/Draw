#pragma once



#include "Local.h"







#include <windows.h>


#include <gdiplus.h>





struct Image
{
    IStream* Stream;
    Gdiplus::Bitmap* Bitmap;
};




Draw* Draw_Draw_Pointer(Object o);