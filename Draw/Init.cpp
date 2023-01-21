#include "Init.h"




namespace Draw
{

namespace Private
{

Gdiplus::GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR           gdiplusToken;

}

}





Bool Draw_Init()
{
    Gdiplus::GdiplusStartup(& Draw::Private::gdiplusToken, & Draw::Private::gdiplusStartupInput, NULL);



    Draw_Draw_Constant_DefaultColor = 0xffffffff;



    return true;
}





Bool Draw_Final()
{
    Gdiplus::GdiplusShutdown(Draw::Private::gdiplusToken);


    return true;
}