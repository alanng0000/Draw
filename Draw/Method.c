#include "Method.h"





Int32 bufferPixelByteCount;


Int32 bitsPerByte;


Int32 alphaShift;

Int32 redShift;

Int32 greenShift;

Int32 blueShift;


Int32 alphaMax;





void Draw_Method_Init()
{
    bufferPixelByteCount = sizeof(Int32);


    bitsPerByte = 8;


    alphaShift = bitsPerByte * 3;

    redShift = bitsPerByte * 2;

    greenShift = bitsPerByte * 1;

    blueShift = bitsPerByte * 0;


    alphaMax = 255;
}





void Draw_Method_Color(Byte* bufferPointer, Int32 bufferStride, Int32 rectRow, Int32 rectCol, Int32 rectWidth, Int32 rectHeight, Int32 color)
{
    Int32 alpha;
    alpha = (Byte)(color >> alphaShift);

    Int32 red;
    red = (Byte)(color >> redShift);

    Int32 green;
    green = (Byte)(color >> greenShift);

    Int32 blue;
    blue = (Byte)(color >> blueShift);


    Int32 tAlpha;
    tAlpha = alphaMax - alpha;




    Int32 i;
    i = 0;

    while (i < rectHeight)
    {
        Int32 j;
        j = 0;

        while (j < rectWidth)
        {
            Int32 row;
            row = rectRow + i;


            Int32 col;
            col = rectCol + j;


            Byte* u;
            u = bufferPointer + row * bufferStride + col * bufferPixelByteCount;


            Int32* d;
            d = (Int32*)u;


            Int32 t;
            t = *d;


            Int32 tRed;
            tRed = (Byte)(t >> redShift);

            Int32 tGreen;
            tGreen = (Byte)(t >> greenShift);

            Int32 tBlue;
            tBlue = (Byte)(t >> blueShift);


            Int32 hRed;
            hRed = (alpha * red + tAlpha * tRed) / alphaMax;

            Int32 hGreen;
            hGreen = (alpha * green + tAlpha * tGreen) / alphaMax;

            Int32 hBlue;
            hBlue = (alpha * blue + tAlpha * tBlue) / alphaMax;


            Int32 h;
            h = (hRed << redShift) | (hGreen << greenShift) | (hBlue << blueShift);


            *d = h;


            j = j + 1;
        }


        i = i + 1;
    }
}




void Draw_Method_Image(Byte* bufferPointer, Int32 bufferStride, Int32 rectRow, Int32 rectCol, Int32 rectWidth, Int32 rectHeight, 
    Int32 posRow, Int32 posCol, Byte* pixelPointer, Int32 pixelStride)
{
    Int32 i;
    i = 0;

    while (i < rectHeight)
    {
        Int32 j;
        j = 0;

        while (j < rectWidth)
        {
            Int32 row;
            row = rectRow + i;


            Int32 col;
            col = rectCol + j;


            Byte* u;
            u = bufferPointer + row * bufferStride + col * bufferPixelByteCount;


            Int32* d;
            d = (Int32*)u;


            Int32 t;
            t = *d;


            Int32 mRow;
            mRow = posRow + i;


            Int32 mCol;
            mCol = posCol + j;


            Byte* n;
            n = pixelPointer + mRow * pixelStride + mCol * bufferPixelByteCount;


            Int32* o;
            o = (Int32*)n;


            Int32 color;
            color = *o;


            Int32 alpha;
            alpha = (Byte)(color >> alphaShift);

            Int32 red;
            red = (Byte)(color >> redShift);

            Int32 green;
            green = (Byte)(color >> greenShift);

            Int32 blue;
            blue = (Byte)(color >> blueShift);



            Int32 tAlpha;
            tAlpha = alphaMax - alpha;



            Int32 tRed;
            tRed = (Byte)(t >> redShift);

            Int32 tGreen;
            tGreen = (Byte)(t >> greenShift);

            Int32 tBlue;
            tBlue = (Byte)(t >> blueShift);


            Int32 hRed;
            hRed = (alpha * red + tAlpha * tRed) / alphaMax;

            Int32 hGreen;
            hGreen = (alpha * green + tAlpha * tGreen) / alphaMax;

            Int32 hBlue;
            hBlue = (alpha * blue + tAlpha * tBlue) / alphaMax;


            Int32 h;
            h = (hRed << redShift) | (hGreen << greenShift) | (hBlue << blueShift);


            *d = h;


            j = j + 1;
        }


        i = i + 1;
    }
}