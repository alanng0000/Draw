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





    m->Graphic->SetPageUnit(Gdiplus::UnitPixel);


    m->Graphic->SetTextRenderingHint(Gdiplus::TextRenderingHintClearTypeGridFit);




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





    Object global;


    global = Draw_Global();



    Object constant;


    constant = Draw_Global_Constant(global);



    Object clearColor;


    clearColor = Draw_Constant_DefaultColor(constant);




    Draw_Draw_Clear(draw, clearColor);






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






Bool Draw_Draw_Rect(Object o, SInt left, SInt up, Int width, Int height, Object brush)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    Gdiplus::Brush* oc;

    oc = Draw_Brush_GetInternal(brush);




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

    mm = Draw_Image_GetInternal(image);





    Gdiplus::Rect destRect;

    
    Draw_Draw_CreateRect(&destRect, destLeft, destUp, destWidth, destHeight);





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





Bool Draw_Draw_Text(Object o, Int string, Int length, Object font, SInt rectLeft, SInt rectUp, Int rectWidth, Int rectHeight, Object brush)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    WCHAR* stringU;

    stringU = (WCHAR*)string;



    int lengthU;

    lengthU = (int)length;




    Gdiplus::Font* fontU;

    fontU = Draw_Font_GetInternal(font);





    Gdiplus::REAL rectLeftU;

    rectLeftU = (Gdiplus::REAL)rectLeft;



    Gdiplus::REAL rectUpU;

    rectUpU = (Gdiplus::REAL)rectUp;



    Gdiplus::REAL rectWidthU;

    rectWidthU = (Gdiplus::REAL)rectWidth;



    Gdiplus::REAL rectHeightU;

    rectHeightU = (Gdiplus::REAL)rectHeight;





    Gdiplus::RectF rectF;

    rectF = Gdiplus::RectF(rectLeftU, rectUpU, rectWidthU, rectHeightU);




    Gdiplus::Brush* brushU;

    brushU = Draw_Brush_GetInternal(brush);




    Object global;

    global = Draw_Global();



    Object constant;

    constant = Draw_Global_Constant(global);



    Int stringFormat;

    stringFormat = Draw_Constant_StringFormat(constant);




    Gdiplus::StringFormat* stringFormatU;


    stringFormatU = (Gdiplus::StringFormat*)stringFormat;





    m->Graphic->DrawString(stringU, lengthU, fontU, rectF, stringFormatU, brushU);




    return true;
}






Bool Draw_Draw_Clip(Object o, SInt left, SInt up, Int width, Int height)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    Gdiplus::Rect rect;


    Draw_Draw_CreateRect(&rect, left, up, width, height);



    m->Graphic->SetClip(rect);



    return true;
}






Bool Draw_Draw_CreateRect(Gdiplus::Rect* result, SInt left, SInt up, Int width, Int height)
{
    int l;

    l = (int)left;


    int u;

    u = (int)up;


    int w;

    w = (int)width;


    int h;

    h = (int)height;





    *result = Gdiplus::Rect(l, u, w, h);



    return true;
}