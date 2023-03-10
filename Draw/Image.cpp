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





    Object data;

    data = m->Data;




    Int uu;


    uu = Data_GetValue(data);




    Int* oo;


    oo = (Int*)uu;




    Int width;

    width = oo[0];



    Int height;

    height = oo[1];




    Int pixelData;

    pixelData = uu + Constant_IntByteCount * 2;




    Int stride;

    stride = 4 * width;




    int w;

    w = (int)width;


    int h;

    h = (int)height;



    int st;

    st = (int)stride;





    Byte* scan0;

    scan0 = (Byte*)pixelData;




    Gdiplus::PixelFormat format;

    format = PixelFormat32bppARGB;




    Gdiplus::Bitmap* bitmap;

    bitmap = new Gdiplus::Bitmap(w, h, st, format, scan0);


    m->Intern = bitmap;





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




    Size_Final(m->Size);


    Size_Delete(m->Size);
    



    delete m->Intern;



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







Gdiplus::Bitmap* Draw_Image_GetIntern(Object o)
{
    Image* m;

    m = Draw_Image_Pointer(o);


    return m->Intern;
}







Image* Draw_Image_Pointer(Object o)
{
    Image* m;

    m = (Image*)o;


    return m;
}