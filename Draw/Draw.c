#include "Draw.h"




ClassNew(Draw, Draw)







Bool Draw_Init(Object this)
{
    return true;
}




Bool Draw_Final(Object this)
{
    return true;
}





Int Draw_GetPixelList(Object this)
{
    Draw* m;

    m = CastPointer(this);



    Int32* p;
    
    p = m->PixelList;



    Int o;

    o = CastInt(p);


    return o;
}




Bool Draw_SetPixelList(Object this, Int value)
{
    Draw* m;


    m = CastPointer(this);




    Int32* p;



    p = CastPointer(value);




    m->PixelList = p;



    return true;
}





Object Draw_GetSize(Object this)
{
    Draw* m;


    m = CastPointer(this);



    return m->Size;
}





Bool Draw_SetSize(Object this, Object value)
{
    Draw* m;


    m = CastPointer(this);



    m->Size = value;



    return true;
}





Object Draw_Color(Object this, Int color, Object rect)
{
    return null;
}