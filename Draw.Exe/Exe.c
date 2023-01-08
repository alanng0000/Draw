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

    color = 0x00ffff00;



    Draw_Method_Color(bufferPointer, bufferStride, 0, 0, 1, 1, color);




    if (!(a == color))
    {
        return 1;
    }




    Object u;

    u = CastInt("DEMO SUCCESS");



    Int length;

    length = String_ConstantLength(u);



    Object s;

    s = String_New();


    String_Init(s);



    String_SetData(s, u);

    String_SetLength(s, length);





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