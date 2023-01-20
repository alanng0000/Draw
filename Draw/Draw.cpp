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




Bool Draw_Draw_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}