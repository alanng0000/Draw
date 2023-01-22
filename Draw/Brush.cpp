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