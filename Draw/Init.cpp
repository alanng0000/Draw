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







    Object global;
    
    
    
    global = Draw_Global_New();



    Draw_Global_Init(global);
    



    Draw_Global_Data = global;




    return true;
}





Bool Draw_Final()
{
    Object global;
    

    global = Draw_Global_Data;



    Draw_Global_Final(global);



    Draw_Global_Delete(global);



    Draw_Global_Data = null;






    Gdiplus::GdiplusShutdown(Draw::Private::gdiplusToken);




    return true;
}