#pragma once



#include "Local.h"






struct Image
{
    Object Size;


    Object Data;


    Gdiplus::Bitmap* Internal;    
};





Image* Draw_Image_Pointer(Object o);