#include "Exe.h"




int main(int argc, char* argv[])
{
    Draw_Method_Init();




    Int32 a;

    a = 0;



    Int32* p;

    p = &a;



    Byte* bufferPointer;

    bufferPointer = (Byte*)p;



    Int32 bufferStride;

    bufferStride = 4;



    Int32 color;

    color = 0xffffff00;



    Draw_Method_Color(bufferPointer, bufferStride, 0, 0, 1, 1, color);



    
    Int u;


    u = CastInt("DEMO SUCCESS\n");




    Bool b;


    b = (a == 0x00ffff00);


    if (!b)
    {
        u = CastInt("DEMO ERROR\n");
    }





    



    Int length;

    length = String_ConstantLength(u);



    Object s;


    s = String_New();


    String_Init(s);


    String_SetLength(s, length);


    String_SetData(s, u);

    





    Object console;

    console = Console_New();



    Console_Init(console);



    Console_Write(console, s);



    Console_Final(console);



    Console_Delete(console);






    String_Final(s);


    String_Delete(s);






    int ret;

    ret = 0;


    return ret;
}