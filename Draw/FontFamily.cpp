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





Bool Draw_FontFamily_Init(Object o)
{
    FontFamily* m;

    m = Draw_FontFamily_Pointer(o);








    return true;
}





Int Draw_FontFamily_GetName(Object o)
{
    FontFamily* m;

    m = Draw_FontFamily_Pointer(o);



    return m->Name;
}




Bool Draw_FontFamily_SetName(Object o, Int value)
{
    FontFamily* m;

    m = Draw_FontFamily_Pointer(o);



    m->Name = value;


    return true;
}





FontFamily* Draw_FontFamily_Pointer(Object o)
{
    FontFamily* m;

    m = (FontFamily*)o;


    return m;
}