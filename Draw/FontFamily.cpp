#include "FontFamily.h"






Object Draw_FontFamily_New()
{
    FontFamily* m;

    m = new FontFamily();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_FontFamily_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}






FontFamily* Draw_FontFamily_Pointer(Object o)
{
    FontFamily* m;

    m = (FontFamily*)o;


    return m;
}