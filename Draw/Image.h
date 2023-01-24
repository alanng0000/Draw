#pragma once



#include "Local.h"






struct Image
{
    Object Data;


    Object Size;



    Gdiplus::Bitmap* Intern;    
};





Image* Draw_Image_Pointer(Object o);