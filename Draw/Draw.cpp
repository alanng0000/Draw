#include "Draw.h"





Object Draw_Draw_New()
{
    Draw* m;

    m = new Draw();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_Draw_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}




Bool Draw_Draw_Init(Object o)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    Int handle;

    handle = Draw_Draw_GetHandle(o);



    Object size;

    size = Draw_Draw_GetSize(o);




    HDC hdc;

    hdc = (HDC)handle;




    Int width;

    width = Size_GetWidth(size);



    Int height;

    height = Size_GetHeight(size);




    int w;

    w = (int)width;


    int h;

    h = (int)height;





    Gdiplus::Bitmap* bitmap;
    
    bitmap = new Gdiplus::Bitmap(w, h);


    m->Bitmap = bitmap;




    Gdiplus::Graphics* graphic;
    
    graphic = new Gdiplus::Graphics(m->Bitmap);


    m->Graphic = graphic;




    Gdiplus::Graphics* handleGraphic;
    
    handleGraphic = new Gdiplus::Graphics(hdc);
    

    m->HandleGraphic = handleGraphic;



    return true;
}





Bool Draw_Draw_Final(Object o)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);



    delete m->Graphic;


    delete m->Bitmap;


    delete m->HandleGraphic;



    return true;
}





Int Draw_Draw_GetHandle(Object o)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);


    return m->Handle;
}





Bool Draw_Draw_SetHandle(Object o, Int value)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);


    m->Handle = value;


    return true;
}







Object Draw_Draw_GetSize(Object o)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);


    return m->Size;
}





Bool Draw_Draw_SetSize(Object o, Object value)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);


    m->Size = value;


    return true;
}








Draw_Draw_Method Draw_Draw_GetMethodAddress(Object o)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);



    return m->Method;
}






Int Draw_Draw_GetMethod(Object o)
{
    Draw_Draw_Method method;

    method = Draw_Draw_GetMethodAddress(o);



    Int u;

    u = CastInt(method);


    return u;
}





Bool Draw_Draw_SetMethod(Object o, Int value)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);



    Draw_Draw_Method method;

    method = (Draw_Draw_Method)value;



    m->Method = method;


    return true;
}






Bool Draw_Draw_Result(Object o)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    m->HandleGraphic->DrawImage(m->Bitmap, 0, 0);



    return true;
}







Draw* Draw_Draw_Pointer(Object o)
{
    Draw* m;

    m = (Draw*)o;


    return m;
}







Bool Draw_FrameDrawHandle(Object arg)
{
    Object draw;

    
    draw = arg;




    Int u;

    u = Draw_Draw_GetMethod(draw);





    Draw_Draw_Method method;

    method = (Draw_Draw_Method)u;




    Draw_Draw_Clear(draw, Draw_Draw_Constant_DefaultColor);






    if (!(method == null))
    {
        method(draw);
    }




    Draw_Draw_Result(draw);

    


    return true;
}






Bool Draw_Draw_Clear(Object o, Int color)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);





    Gdiplus::ARGB argb;

    argb = (Gdiplus::ARGB)color;




    Gdiplus::Color c;

    c.SetValue(argb);
    



    m->Graphic->Clear(c);



    return true;
}






Bool Draw_Draw_Rect(Object o, Object brush, SInt left, SInt up, Int width, Int height)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    Gdiplus::Brush* oc;

    oc = (Gdiplus::Brush*)brush;




    int l;

    l = (int)left;



    int u;

    u = (int)up;



    int w;

    w = (int)width;



    int h;

    h = (int)height;




    m->Graphic->FillRectangle(oc, l, u, w, h);




    return true;
}




Bool Draw_Draw_Image(Object o, Object image, SInt destLeft, SInt destUp, Int destWidth, Int destHeight,
    SInt sourceLeft, SInt sourceUp, Int sourceWidth, Int sourceHeight)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);



    Gdiplus::Image* mm;

    mm = Draw_Image_GetBitmap(image);



    
    int destL;

    destL = (int)destLeft;


    int destU;

    destU = (int)destUp;


    int destW;

    destW = (int)destWidth;


    int destH;

    destH = (int)destHeight;





    Gdiplus::Rect destRect;

    destRect = Gdiplus::Rect(destL, destU, destW, destH);





    int sourceL;

    sourceL = (int)sourceLeft;


    int sourceU;

    sourceU = (int)sourceUp;


    int sourceW;

    sourceW = (int)sourceWidth;


    int sourceH;

    sourceH = (int)sourceHeight;




    m->Graphic->DrawImage(mm, destRect, sourceL, sourceU, sourceW, sourceH, Gdiplus::UnitPixel);



    return true;
}