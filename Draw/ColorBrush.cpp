#include "ColorBrush.h"





Object Draw_ColorBrush_New()
{
    Gdiplus::Color color;


    Gdiplus::SolidBrush* o;

    o = new Gdiplus::SolidBrush(color);



    Object u;

    u = CastInt(o);


    return u;
}




Bool Draw_ColorBrush_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}





Int Draw_ColorBrush_GetColor(Object o)
{
    Gdiplus::SolidBrush* m;

    m = (Gdiplus::SolidBrush*)o;



    Gdiplus::Color color;


    m->GetColor(&color);



    Gdiplus::ARGB u;

    u = color.GetValue();


    return u;
}