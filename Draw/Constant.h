#pragma once



#include "Local.h"




struct Constant
{
    Int DefaultColor;



    Int ColorBrushType;



    Int FontStyleRegular;

    Int FontStyleBold;

    Int FontStyleItalic;

    Int FontStyleUnderline;


    Gdiplus::StringFormat* StringFormat;
};



Constant* Draw_Constant_Pointer(Object o);