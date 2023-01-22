#pragma once




#include "Local.h"





struct Brush
{
    Int Type;


    Gdiplus::Brush* Internal;
};









Brush* Draw_Brush_Pointer(Object o);