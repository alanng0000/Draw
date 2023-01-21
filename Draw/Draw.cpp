#include "Draw.h"




Object Draw_Draw_Create(Int handle)
{
    HDC hdc;

    hdc = (HDC)handle;



    Gdiplus::Graphics* o;

    o = new Gdiplus::Graphics(hdc);



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





Bool Draw_Draw_Rect(Object o, Object brush, int left, int up, int width, int height)
{
    Gdiplus::Graphics* m;

    m = (Gdiplus::Graphics*)o;



    Gdiplus::Brush* oc;

    oc = (Gdiplus::Brush*)brush;





    m->FillRectangle(oc, left, up, width, height);




    return true;
}