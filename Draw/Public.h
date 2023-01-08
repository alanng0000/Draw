#pragma once




#include <Infra/Public.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif





void Draw_Method_Init();




void Draw_Method_Color(DByte* bufferPointer, DInt32 bufferStride, DInt32 rectRow, DInt32 rectCol, DInt32 rectWidth, DInt32 rectHeight, DInt32 color);




void Draw_Method_Image(DByte* bufferPointer, DInt32 bufferStride, DInt32 rectRow, DInt32 rectCol, DInt32 rectWidth, DInt32 rectHeight, 
    DInt32 posRow, DInt32 posCol, DByte* pixelPointer, DInt32 pixelStride);