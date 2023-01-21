#pragma once



#include "Local.h"











struct Image
{
    IStream* Stream;

    Gdiplus::Bitmap* Bitmap;
    
    Object Size;
};




Image* Draw_Image_Pointer(Object o);