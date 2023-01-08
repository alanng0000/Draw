#pragma once




typedef unsigned int Int32;

typedef unsigned char Byte;




void Draw_Method_Init();




void Draw_Method_Color(Byte* bufferPointer, Int32 bufferStride, Int32 rectRow, Int32 rectCol, Int32 rectWidth, Int32 rectHeight, Int32 color);




void Draw_Method_Image(Byte* bufferPointer, Int32 bufferStride, Int32 rectRow, Int32 rectCol, Int32 rectWidth, Int32 rectHeight, 
    Int32 posRow, Int32 posCol, Byte* pixelPointer, Int32 pixelStride);