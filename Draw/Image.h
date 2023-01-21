#pragma once



#include "Local.h"







#include <windows.h>


#include <gdiplus.h>





struct Image
{
    IStream* Stream;
    Gdiplus::Bitmap* Bitmap;
};




Image* Draw_Image_Pointer(Object o);