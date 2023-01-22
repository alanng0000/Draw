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








Object Draw_Font_GetFamily(Object o)
{
    Font* m;

    m = Draw_Font_Pointer(o);


    return m->Family;
}





Bool Draw_Font_SetFamily(Object o, Object value)
{
    Font* m;

    m = Draw_Font_Pointer(o);


    m->Family = value;


    return true;
}






Int Draw_Font_GetSize(Object o)
{
    Font* m;

    m = Draw_Font_Pointer(o);


    return m->Size;
}





Bool Draw_Font_SetSize(Object o, Int value)
{
    Font* m;

    m = Draw_Font_Pointer(o);


    m->Size = value;


    return true;
}





Int Draw_Font_GetStyle(Object o)
{
    Font* m;

    m = Draw_Font_Pointer(o);


    return m->Style;
}





Bool Draw_Font_SetStyle(Object o, Int value)
{
    Font* m;

    m = Draw_Font_Pointer(o);


    m->Style = value;


    return true;
}






Font* Draw_Font_Pointer(Object o)
{
    Font* m;

    m = (Font*)o;


    return m;
}