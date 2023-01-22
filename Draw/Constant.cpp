#include "Constant.h"






Object Draw_Constant_New()
{
    Constant* m;

    m = new Constant();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_Constant_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}





Bool Draw_Constant_Init(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);




    m->DefaultColor = 0xffffffff;




    m->ColorBrushType = 1;



    m->FontStyleRegular = Gdiplus::FontStyleRegular;


    m->FontStyleBold = Gdiplus::FontStyleBold;


    m->FontStyleItalic = Gdiplus::FontStyleItalic;


    m->FontStyleUnderline = Gdiplus::FontStyleUnderline;




    return true;
}





Bool Draw_Constant_Final(Object o)
{
    return true;
}






Int Draw_Constant_DefaultColor(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);



    return m->DefaultColor;
}





Int Draw_Constant_ColorBrushType(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);



    return m->ColorBrushType;
}





Int Draw_Constant_FontStyleRegular(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);



    return m->FontStyleRegular;
}





Int Draw_Constant_FontStyleBold(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);



    return m->FontStyleBold;
}





Int Draw_Constant_FontStyleItalic(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);



    return m->FontStyleItalic;
}





Int Draw_Constant_FontStyleUnderline(Object o)
{
    Constant* m;

    m = Draw_Constant_Pointer(o);



    return m->FontStyleUnderline;
}







Constant* Draw_Constant_Pointer(Object o)
{
    Constant* m;

    m = (Constant*)o;


    return m;
}