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