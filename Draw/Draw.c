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
    Int o;
    
    o = Draw_GetPixelList(this);



    Int32* pixelList;

    pixelList = CastPointer(o);





    Object size;

    size = Draw_GetSize(this);



    Int pixelWidth;

    pixelWidth = Size_GetWidth(size);


    Int pixelHeight;

    pixelHeight = Size_GetHeight(size);
    


    Int32 c;


    c = (Int32)color;



    Object rectPos;

    rectPos = Rect_GetPos(rect);


    Object rectSize;

    rectSize = Rect_GetSize(rect);




    Int rectLeft;

    rectLeft = Pos_GetLeft(rectPos);


    Int rectUp;

    rectUp = Pos_GetUp(rectPos);




    Int rectWidth;

    rectWidth = Size_GetWidth(rectSize);
    



    Int rectHeight;

    rectHeight = Size_GetHeight(rectSize);
    




    



    return null;
}