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

};



Constant* Draw_Constant_Pointer(Object o);