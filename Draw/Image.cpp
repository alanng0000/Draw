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


    m->Bitmap = bitmap;




    Int width;

    width = m->Bitmap->GetWidth();


    Int height;

    height = m->Bitmap->GetHeight();




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



    delete m->Bitmap;



    Size_Final(m->Size);


    Size_Delete(m->Size);



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






Object Draw_Image_GetSize(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);


    return m->Size;
}






Gdiplus::Bitmap* Draw_Image_GetBitmap(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);


    return m->Bitmap;
}







Image* Draw_Image_Pointer(Object o)
{
    Image* m;

    m = (Image*)o;


    return m;
}