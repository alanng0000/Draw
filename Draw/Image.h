#pragma once



#include "Local.h"











struct Image
{
    IStream* Stream;

    Gdiplus::Bitmap* Internal;
    
    Object Size;
};




Image* Draw_Image_Pointer(Object o);