#pragma once




#include "Local.h"







struct FontFamily
{
    Object Name;
    
    WCHAR* NameWChar;

    Gdiplus::FontFamily* FontFamily;
};





FontFamily* Draw_FontFamily_Pointer(Object o);




Bool Draw_FontFamily_CopyString(WCHAR* result, Object string);