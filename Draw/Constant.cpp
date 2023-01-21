#include "Constant.h"






Object Draw_Constant_New()
{
    Global* m;

    m = new Global();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_Constant_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}





Bool Draw_Constant_Init(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);



    return true;
}








Constant* Draw_Constant_Pointer(Object o)
{
    Constant* m;

    m = (Constant*)o;


    return m;
}