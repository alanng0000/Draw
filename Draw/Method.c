typedef unsigned int Int32;

typedef unsigned char Byte;



void Color(Byte* bufferPointer, Int32 bufferStride, Int32 rectColumn, Int32 rectRow, Int32 rectWidth, Int32 rectHeight, Int32 color)
{
    Int32 bufferPixelByteCount = sizeof(Int32);


    Int32 bitsPerByte = 8;


    Int32 alphaShift = bitsPerByte * 3;

    Int32 redShift = bitsPerByte * 2;

    Int32 greenShift = bitsPerByte * 1;

    Int32 blueShift = bitsPerByte * 0;


    Int32 alphaMax = 255;


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


            Int32 column;
            column = rectColumn + j;


            Byte* u;
            u = bufferPointer + row * bufferStride + column * bufferPixelByteCount;


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




void Image(Int64 bufferPointer, Int32 bufferStride, Int32 rectColumn, Int32 rectRow, Int32 rectWidth, Int32 rectHeight, 
    Int32 posColumn, Int32 posRow, Int64 pixelsPointer, Int32 pixelsStride)
{
    const Int32 bufferPixelByteCount = sizeof(Int32);


    const Int32 bitsPerByte = 8;


    const Int32 alphaShift = bitsPerByte * 3;

    const Int32 redShift = bitsPerByte * 2;

    const Int32 greenShift = bitsPerByte * 1;

    const Int32 blueShift = bitsPerByte * 0;


    const Int32 alphaMax = 255;



    Byte* p;
    p = (Byte*)bufferPointer;


    Byte* m;
    m = (Byte*)pixelsPointer;


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


            Int32 column;
            column = rectColumn + j;


            Byte* u;
            u = p + row * bufferStride + column * bufferPixelByteCount;


            Int32* d;
            d = (Int32*)u;


            Int32 t;
            t = *d;


            Int32 mRow;
            mRow = posRow + i;


            Int32 mColumn;
            mColumn = posColumn + j;


            Byte* n;
            n = m + mRow * pixelsStride + mColumn * bufferPixelByteCount;


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