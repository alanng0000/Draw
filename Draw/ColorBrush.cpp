#include "ColorBrush.h"





Int Draw_ColorBrush_Create()
{
    Gdiplus::Color color;

    color = Gdiplus::Color();


    Gdiplus::SolidBrush* o;

    o = new Gdiplus::SolidBrush(color);



    Int u;

    u = CastInt(o);


    return u;
}






Int Draw_ColorBrush_GetColor(Object o)
{
    Gdiplus::Brush* a;

    a = Draw_Brush_GetInternal(o);




    Gdiplus::SolidBrush* m;

    m = (Gdiplus::SolidBrush*)a;



    Gdiplus::Color color;


    m->GetColor(&color);



    Gdiplus::ARGB u;

    u = color.GetValue();


    return u;
}





Bool Draw_ColorBrush_SetColor(Object o, Int value)
{
    Gdiplus::Brush* a;

    a = Draw_Brush_GetInternal(o);




    Gdiplus::SolidBrush* m;

    m = (Gdiplus::SolidBrush*)a;



    Gdiplus::ARGB argb;

    argb = (Gdiplus::ARGB)value;



    Gdiplus::Color color;

    color.SetValue(argb);



    m->SetColor(color);


    return true;
}