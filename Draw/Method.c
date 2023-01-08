#include "Method.h"





DInt32 bufferPixelByteCount;


DInt32 bitsPerByte;


DInt32 alphaShift;

DInt32 redShift;

DInt32 greenShift;

DInt32 blueShift;


DInt32 alphaMax;





void Draw_Method_Init()
{
    bufferPixelByteCount = sizeof(DInt32);


    bitsPerByte = 8;


    alphaShift = bitsPerByte * 3;

    redShift = bitsPerByte * 2;

    greenShift = bitsPerByte * 1;

    blueShift = bitsPerByte * 0;


    alphaMax = 255;
}





void Draw_Method_Color(DByte* bufferPointer, DInt32 bufferStride, DInt32 rectRow, DInt32 rectCol, DInt32 rectWidth, DInt32 rectHeight, DInt32 color)
{
    DInt32 alpha;
    alpha = (DByte)(color >> alphaShift);

    DInt32 red;
    red = (DByte)(color >> redShift);

    DInt32 green;
    green = (DByte)(color >> greenShift);

    DInt32 blue;
    blue = (DByte)(color >> blueShift);


    DInt32 tAlpha;
    tAlpha = alphaMax - alpha;




    DInt32 i;
    i = 0;

    while (i < rectHeight)
    {
        DInt32 j;
        j = 0;

        while (j < rectWidth)
        {
            DInt32 row;
            row = rectRow + i;


            DInt32 col;
            col = rectCol + j;


            DByte* u;
            u = bufferPointer + row * bufferStride + col * bufferPixelByteCount;


            DInt32* d;
            d = (DInt32*)u;


            DInt32 t;
            t = *d;


            DInt32 tRed;
            tRed = (DByte)(t >> redShift);

            DInt32 tGreen;
            tGreen = (DByte)(t >> greenShift);

            DInt32 tBlue;
            tBlue = (DByte)(t >> blueShift);


            DInt32 hRed;
            hRed = (alpha * red + tAlpha * tRed) / alphaMax;

            DInt32 hGreen;
            hGreen = (alpha * green + tAlpha * tGreen) / alphaMax;

            DInt32 hBlue;
            hBlue = (alpha * blue + tAlpha * tBlue) / alphaMax;


            DInt32 h;
            h = (hRed << redShift) | (hGreen << greenShift) | (hBlue << blueShift);


            *d = h;


            j = j + 1;
        }


        i = i + 1;
    }
}




void Draw_Method_Image(DByte* bufferPointer, DInt32 bufferStride, DInt32 rectRow, DInt32 rectCol, DInt32 rectWidth, DInt32 rectHeight, 
    DInt32 posRow, DInt32 posCol, DByte* pixelPointer, DInt32 pixelStride)
{
    DInt32 i;
    i = 0;

    while (i < rectHeight)
    {
        DInt32 j;
        j = 0;

        while (j < rectWidth)
        {
            DInt32 row;
            row = rectRow + i;


            DInt32 col;
            col = rectCol + j;


            DByte* u;
            u = bufferPointer + row * bufferStride + col * bufferPixelByteCount;


            DInt32* d;
            d = (DInt32*)u;


            DInt32 t;
            t = *d;


            DInt32 mRow;
            mRow = posRow + i;


            DInt32 mCol;
            mCol = posCol + j;


            DByte* n;
            n = pixelPointer + mRow * pixelStride + mCol * bufferPixelByteCount;


            DInt32* o;
            o = (DInt32*)n;


            DInt32 color;
            color = *o;


            DInt32 alpha;
            alpha = (DByte)(color >> alphaShift);

            DInt32 red;
            red = (DByte)(color >> redShift);

            DInt32 green;
            green = (DByte)(color >> greenShift);

            DInt32 blue;
            blue = (DByte)(color >> blueShift);



            DInt32 tAlpha;
            tAlpha = alphaMax - alpha;



            DInt32 tRed;
            tRed = (DByte)(t >> redShift);

            DInt32 tGreen;
            tGreen = (DByte)(t >> greenShift);

            DInt32 tBlue;
            tBlue = (DByte)(t >> blueShift);


            DInt32 hRed;
            hRed = (alpha * red + tAlpha * tRed) / alphaMax;

            DInt32 hGreen;
            hGreen = (alpha * green + tAlpha * tGreen) / alphaMax;

            DInt32 hBlue;
            hBlue = (alpha * blue + tAlpha * tBlue) / alphaMax;


            DInt32 h;
            h = (hRed << redShift) | (hGreen << greenShift) | (hBlue << blueShift);


            *d = h;


            j = j + 1;
        }


        i = i + 1;
    }
}