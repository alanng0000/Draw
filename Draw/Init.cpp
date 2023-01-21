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


    return true;
}





Bool Draw_Final()
{
    Gdiplus::GdiplusShutdown(Draw::Private::gdiplusToken);


    return true;
}