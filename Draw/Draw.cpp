#include "Draw.h"




Object Draw_Draw_Create(Int hdc)
{
    void* p;

    p = CastPointer(hdc);



    Graphics* o;

    o = new Graphics(p);
    


    Object a;

    a = CastInt(o);


    return a;
}