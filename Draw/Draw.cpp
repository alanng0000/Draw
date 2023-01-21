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





    Gdiplus::Bitmap* bmp;
    
    bmp = new Gdiplus::Bitmap(w, h);


    m->Bitmap = bmp;




    Gdiplus::Graphics* graphic;
    
    graphic = new Gdiplus::Graphics(&bmp);


    m->Graphic = graphic;




    Gdiplus::Graphics* handleGraphic;
    
    handleGraphic = new Gdiplus::Graphics(hdc);
    

    m->HandleGraphic = handleGraphic;



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








Draw_Draw_Method Draw_Draw_GetMethod(Object this)
{
    Frame* m;
    
    m = CastPointer(this);



    return m->DrawHandle;
}






Int Frame_GetDrawHandle(Object this)
{
    Frame_DrawHandle_Method method;

    method = Frame_GetDrawHandleMethod(this);


    Int o;

    o = CastInt(method);


    return o;
}





Bool Frame_SetDrawHandle(Object this, Int value)
{
    Frame* m;
    
    m = CastPointer(this);



    Frame_DrawHandle_Method method;

    method = CastPointer(value);



    m->DrawHandle = method;


    return true;
}









Draw* Draw_Draw_Pointer(Object o)
{
    Draw* m;

    m = (Draw*)o;


    return m;
}












Bool Draw_FrameDrawHandle(Object frame, Object arg)
{





    Gdiplus::Graphics* p;

    p = &graphics;




    Object o;

    o = CastInt(p);





    Draw_DrawHandle_Method method;

    method = (Draw_DrawHandle_Method)arg;



    if (!(method == null))
    {
        method(o);
    }




    g.DrawImage(&bmp, 0, 0);


    return true;
}






Bool Draw_Draw_Clear(Object o, Int color)
{
    Gdiplus::Graphics* m;

    m = (Gdiplus::Graphics*)o;




    Gdiplus::ARGB argb;

    argb = (Gdiplus::ARGB)color;




    Gdiplus::Color c;

    c.SetValue(argb);
    



    m->Clear(c);



    return true;
}






Bool Draw_Draw_Rect(Object o, Object brush, int left, int up, int width, int height)
{
    Gdiplus::Graphics* m;

    m = (Gdiplus::Graphics*)o;



    Gdiplus::Brush* oc;

    oc = (Gdiplus::Brush*)brush;





    m->FillRectangle(oc, left, up, width, height);




    return true;
}