#pragma once



#include "Local.h"





struct Font
{
    Object Family;


    Int Size;


    Int Style;


    Gdiplus::Font* Internal;
};