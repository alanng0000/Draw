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
    Image* m;

    m = Draw_Image_Pointer(o);



    Gdiplus::Bitmap* bitmap;

    bitmap = new Gdiplus::Bitmap(m->Stream);


    m->Internal = bitmap;




    Int width;

    width = m->Internal->GetWidth();


    Int height;

    height = m->Internal->GetHeight();




    Object size;


    size = Size_New();


    Size_Init(size);


    Size_SetWidth(size, width);


    Size_SetHeight(size, height);



    m->Size = size;



    return true;
}





Bool Draw_Image_Final(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);



    delete m->Internal;



    Size_Final(m->Size);


    Size_Delete(m->Size);



    return true;
}






Object Draw_Image_GetData(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);



    return m->Data;
}





Bool Draw_Image_SetData(Object o, Object value)
{
    Image* m;

    m = Draw_Image_Pointer(o);



    m->Data = value;


    return true;
}






Object Draw_Image_GetSize(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);


    return m->Size;
}




Bool Draw_Image_SetSize(Object o, Object value)
{
    Image* m;

    m = Draw_Image_Pointer(o);


    m->Size = value;


    return true;
}






Gdiplus::Bitmap* Draw_Image_GetInternal(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);


    return m->Internal;
}







Image* Draw_Image_Pointer(Object o)
{
    Image* m;

    m = (Image*)o;


    return m;
}