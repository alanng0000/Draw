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





Bool Draw_Draw_Rect(Object o, Object brush, Int left, Int up, Int width, Int height)
{
    Gdiplus::Graphics* m;

    m = (Gdiplus::Graphics*)o;



    Gdiplus::Brush* oc;

    oc = (Gdiplus::Brush*)brush;




    INT l;

    l = (INT)left;


    INT u;

    u = (INT)up;


    INT w;
    
    w = (INT)width;


    INT h;

    h = (INT)height;




    m->FillRectangle(oc, l, u, w, h);




    return true;
}