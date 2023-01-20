#include "Draw.h"




Object Draw_Draw_Create(Int hdc)
{
    HDC p;

    p = (HDC)hdc;



    Gdiplus::Graphics* o;

    o = new Gdiplus::Graphics(p);



    Object a;

    a = CastInt(o);


    return a;
}