#include "Draw.h"




Bool Draw_Handle(Object frame, Int handle, Object arg)
{
    HDC hdc;

    hdc = (HDC)handle;


    Gdiplus::Graphics g(hdc);




    Gdiplus::Graphics* p;

    p = &g;



    Object o;

    o = CastInt(p);







    return true;
}







Bool Draw_Draw_Rect(Object o, Object brush, int left, int up, int width, int height)
{
    Gdiplus::Graphics* m;

    m = (Gdiplus::Graphics*)o;



    Gdiplus::Brush* oc;

    oc = (Gdiplus::Brush*)brush;





    m->FillRectangle(oc, left, up, width, height);




    return true;
}