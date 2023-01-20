#include "ColorBrush.h"





Object Draw_ColorBrush_New()
{
    Graphics::SolidBrush* o;

    o = new Graphics::SolidBrush();



    Object u;

    u = Castnt(o);


    return u;
}




Bool Draw_ColorBrush_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}