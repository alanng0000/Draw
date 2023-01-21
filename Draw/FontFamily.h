#pragma once




#include "Local.h"







struct FontFamily
{
    Object Name;
    
    WCHAR* NameWChar;

    Gdiplus::FontFamily* FontFamily;
};





FontFamily* Draw_FontFamily_Pointer(Object o);