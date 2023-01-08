#pragma once




#include <Infra/Public.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif




Draw_Api
void Draw_Method_Init();



Draw_Api
void Draw_Method_Color(Byte* bufferPointer, Int32 bufferStride, Int32 rectRow, Int32 rectCol, Int32 rectWidth, Int32 rectHeight, Int32 color);



Draw_Api
void Draw_Method_Image(Byte* bufferPointer, Int32 bufferStride, Int32 rectRow, Int32 rectCol, Int32 rectWidth, Int32 rectHeight, 
    Int32 posRow, Int32 posCol, Byte* pixelPointer, Int32 pixelStride);