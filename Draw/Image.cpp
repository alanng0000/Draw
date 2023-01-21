#include "Image.h"






Object Draw_Image_New()
{
    Image* m;

    m = new Image();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_Image_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}







Bool Draw_Image_Init(Object o)
{
    return true;
}





Bool Draw_Image_Final(Object o)
{
    return true;
}






Int Draw_Image_GetStream(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);



    Int u;

    u = CastInt(m->Stream);


    return u;
}





Bool Draw_Image_SetStream(Object o, Int value)
{
    Image* m;

    m = Draw_Image_Pointer(o);



    IStream* u;

    u = (IStream*)value;


    m->Stream = u;


    return true;
}





Image* Draw_Image_Pointer(Object o)
{
    Image* m;

    m = (Image*)o;


    return m;
}