#include "Brush.h"




Object Draw_Brush_New()
{
    Brush* m;

    m = new Brush();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_Brush_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}







Bool Draw_Brush_Init(Object o)
{
    return true;
}





Bool Draw_Brush_Final(Object o)
{
    Brush* m;

    m = Draw_Brush_Pointer(o);



    delete m->Internal;



    return true;
}








Int Draw_Brush_GetType(Object o)
{
    Brush* m;

    m = Draw_Brush_Pointer(o);


    return m->Type;
}





Bool Draw_Brush_SetType(Object o, Int value)
{
    Brush* m;

    m = Draw_Brush_Pointer(o);


    m->Type = value;


    return true;
}







Int Draw_Brush_GetValue(Object o)
{
    Brush* m;

    m = Draw_Brush_Pointer(o);



    Int u;

    u = CastInt(m->Internal);


    return u;
}





Bool Draw_Brush_SetValue(Object o, Int value)
{
    Brush* m;

    m = Draw_Brush_Pointer(o);



    Gdiplus::Brush* u;

    u = (Gdiplus::Brush*)value;



    m->Internal = u;


    return true;
}







Gdiplus::Brush* Draw_Brush_GetInternal(Object o)
{
    Brush* m;

    m = Draw_Brush_Pointer(o);



    return m->Internal;
}






Brush* Draw_Brush_Pointer(Object o)
{
    Brush* m;

    m = (Brush*)o;


    return m;
}