#include "Draw.h"




Bool Draw_FrameDrawHandle(Object frame, Int handle, Object arg)
{
    HDC hdc;

    hdc = (HDC)handle;



    Object size;

    size = Frame_GetSize(frame);



    Int width;

    width = Size_GetWidth(size);



    Int height;

    height = Size_GetHeight(size);



    int w;

    w = (int)width;


    int h;

    h = (int)height;





    Gdiplus::Bitmap bmp(w, h);


    Gdiplus::Graphics graphics(&bmp);




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



    Gdiplus::Graphics g(hdc);

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