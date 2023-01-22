#include "Font.h"







Object Draw_Font_New()
{
    Font* m;

    m = new Font();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_Font_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}





Bool Draw_Font_Init(Object o)
{
    Font* m;

    m = Draw_Font_Pointer(o);


    return true;
}





Bool Draw_Font_Final(Object o)
{
    return true;
}














Font* Draw_Font_Pointer(Object o)
{
    Font* m;

    m = (Font*)o;


    return m;
}