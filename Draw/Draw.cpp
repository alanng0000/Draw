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





    m->Graphic->Flush(Gdiplus::FlushIntentionSync);




    m->HandleGraphic->DrawImage(m->Bitmap, 0, 0);



    m->HandleGraphic->Flush(Gdiplus::FlushIntentionSync);



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






Bool Draw_Draw_Rect(Object o, Int left, Int up, Int width, Int height, Object brush)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    Gdiplus::Brush* oc;

    oc = Draw_Brush_GetInternal(brush);




    SInt leftSInt;

    leftSInt = (SInt)left;



    SInt upSInt;

    upSInt = (SInt)up;




    int l;

    l = (int)leftSInt;



    int u;

    u = (int)upSInt;



    int w;

    w = (int)width;



    int h;

    h = (int)height;




    m->Graphic->FillRectangle(oc, l, u, w, h);




    return true;
}




Bool Draw_Draw_Image(Object o, Object image, Int destLeft, Int destUp, Int destWidth, Int destHeight,
    Int sourceLeft, Int sourceUp, Int sourceWidth, Int sourceHeight)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    Gdiplus::Bitmap* uu;

    uu = Draw_Image_GetIntern(image);



    Gdiplus::Image* mm;

    mm = uu;





    Gdiplus::Rect destRect;

    
    Draw_Draw_CreateRect(&destRect, destLeft, destUp, destWidth, destHeight);




    SInt sourceLeftSInt;

    sourceLeftSInt = (SInt)sourceLeft;



    SInt sourceUpSInt;

    sourceUpSInt = (SInt)sourceUp;




    int sourceL;

    sourceL = (int)sourceLeftSInt;


    int sourceU;

    sourceU = (int)sourceUpSInt;


    int sourceW;

    sourceW = (int)sourceWidth;


    int sourceH;

    sourceH = (int)sourceHeight;




    m->Graphic->DrawImage(mm, destRect, sourceL, sourceU, sourceW, sourceH, Gdiplus::UnitPixel);



    return true;
}





Bool Draw_Draw_Text(Object o, Int text, Int length, Int destLeft, Int destUp, Int destWidth, Int destHeight, Object font, Object brush)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    WCHAR* stringU;

    stringU = (WCHAR*)text;



    int lengthU;

    lengthU = (int)length;




    Gdiplus::Font* fontU;

    fontU = Draw_Font_GetInternal(font);





    SInt destLeftSInt;

    destLeftSInt = (SInt)destLeft;



    SInt destUpSInt;

    destUpSInt = (SInt)destUp;




    Gdiplus::REAL destLeftU;

    destLeftU = (Gdiplus::REAL)destLeftSInt;



    Gdiplus::REAL destUpU;

    destUpU = (Gdiplus::REAL)destUpSInt;



    Gdiplus::REAL destWidthU;

    destWidthU = (Gdiplus::REAL)destWidth;



    Gdiplus::REAL destHeightU;

    destHeightU = (Gdiplus::REAL)destHeight;





    Gdiplus::RectF destRectF;

    destRectF = Gdiplus::RectF(destLeftU, destUpU, destWidthU, destHeightU);




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





    m->Graphic->DrawString(stringU, lengthU, fontU, destRectF, stringFormatU, brushU);




    return true;
}






Bool Draw_Draw_Clip(Object o, Int left, Int up, Int width, Int height)
{
    Draw* m;

    m = Draw_Draw_Pointer(o);




    Gdiplus::Rect rect;


    Draw_Draw_CreateRect(&rect, left, up, width, height);



    m->Graphic->SetClip(rect);



    return true;
}






Bool Draw_Draw_CreateRect(Gdiplus::Rect* result, Int left, Int up, Int width, Int height)
{
    SInt leftSInt;

    leftSInt = (SInt)left;



    SInt upSInt;

    upSInt = (SInt)up;




    int l;

    l = (int)leftSInt;


    int u;

    u = (int)upSInt;


    int w;

    w = (int)width;


    int h;

    h = (int)height;





    *result = Gdiplus::Rect(l, u, w, h);



    return true;
}