#pragma once



#include "Local.h"





struct Font
{
    Object Family;


    Int Size;


    Int Style;


    Gdiplus::Font* Internal;
};






Font* Draw_Font_Pointer(Object o);