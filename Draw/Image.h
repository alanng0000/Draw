#pragma once



#include "Local.h"







#include <windows.h>


#include <gdiplus.h>





struct Image
{
    IStream* Stream;
    Gdiplus::Bitmap* Bitmap;
    Object Size;
};




Image* Draw_Image_Pointer(Object o);