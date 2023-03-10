#include "Exe.h"




Object Draw;



Object Brush;



Object Image;



Object ImageData;





Object FontFamily;



Object Font;





Byte Comp;




Int Text;


Int TextLength;





SInt Left;


SInt Up;




SInt ClipLeft;


SInt ClipUp;





Object FrameSize;






Bool StorageStringSet(Object string, Int charArray)
{
    Int k = String_ConstantLength(charArray);



    Int length = k + 1;



    String_SetLength(string, length);


    String_SetData(string, charArray);



    return true;
}




Int StorageGetSize(Object storage)
{
    Storage_Status(storage);



    Int size;
    

    size = Storage_GetSize(storage);



    return size;
}





Bool StorageExecute(Object storage, Object data)
{
    Storage_SetMode(storage, 0);




    Storage_Open(storage);





    Storage_Read(storage, data);

    



    Storage_Close(storage);





    return true;
}








Bool SetFormatArg(Object format, Int arg, Int index, Int type, Int value)
{
    Object o;


    o = Format_Arg(format, arg);





    FormatArg_SetIndex(o, index);



    FormatArg_SetType(o, type);



    FormatArg_SetValue(o, value);




    return true;
}





Bool ControlHandleConsoleWriteKeyValue(Int controlKey, Int controlValue)
{
    Object format;



    format = Format_New();



    Format_Init(format);





    Int o = CastInt(", \n");



    Int baseLength = String_ConstantLength(o);




    Object base;
    


    base = String_New();



    String_Init(base);




    String_SetLength(base, baseLength);


    String_SetData(base, o);







    Object result = String_New();



    String_Init(result);





    Int arg = 0;


    Int index = 0;


    Int type = 0;


    Int value = 0;



    Int argCount = 2;




    Format_SetBase(format, base);




    Format_SetArgCount(format, argCount);




    Format_Open(format);







    arg = 0;


    index = 0;


    type = 1;


    value = controlKey;




    SetFormatArg(format, arg, index, type, value);






    arg = 1;


    index = 2;


    type = 1;

    
    value = controlValue;




    SetFormatArg(format, arg, index, type, value);







    Int resultLength = Format_Length(format);




    Int resultBuffer = New(resultLength);




    String_SetLength(result, resultLength);



    String_SetData(result, resultBuffer);




    Format_SetString(format, result);






    Format_Result(format);





    Format_Close(format);








    Object console;
    
    

    console = Console_New();



    Console_Init(console);



    Console_Write(console, result);



    Console_Final(console);



    Console_Delete(console);








    Delete(resultBuffer);





    String_Final(result);



    String_Delete(result);






    String_Final(base);



    String_Delete(base);





    Format_Final(format);



    Format_Delete(format);




    return true;
}





Bool DrawExecute(Object draw)
{
    Int clipWidth;

    clipWidth = 800;


    Int clipHeight;

    clipHeight = 600;



    Int clipLeftInt;

    clipLeftInt = (Int)ClipLeft;


    Int clipUpInt;

    clipUpInt = (Int)ClipUp;




    Draw_Draw_Clip(draw, clipLeftInt, clipUpInt, clipWidth, clipHeight);






    SInt left;

    left = 100;


    SInt up;

    up = 100;



    Int leftInt;

    leftInt = (Int)left;



    Int upInt;

    upInt = (Int)up;




    Int width;

    width = 400;


    Int height;

    height = 400;




    Int color;


    color = 0x80000000;


    color = color | Comp;





    Draw_ColorBrush_SetColor(Brush, color);




    Draw_Draw_Rect(draw, leftInt, upInt, width, height, Brush);





    Draw_Draw_Image(draw, Image, 400, 400, 800, 400, 600, 600, 800, 400);





    color = 0x8000ff00;



    Draw_ColorBrush_SetColor(Brush, color);
    




    SInt l;

    l = Left + 600;
    


    SInt u;

    u = Up + 850;



    Int leftI;

    leftI = (Int)l;


    Int upI;

    upI = (Int)u;



    Draw_Draw_Text(draw, Text, TextLength, leftI, upI, 400, 200, Font, Brush);




    return true;
}






Bool ControlHandle(Object frame, Int key, Int value)
{
    if (value == 0)
    {
        return true;
    }




    if (key == 0x20)
    {
        Frame_Close(frame);


        return true;
    }




    if (key == 'B')
    {
        Comp = Comp + 10;


        Frame_Update(frame);
    }



    if (key == 'A')
    {
        Left = Left - 10;


        Frame_Update(frame);
    }



    if (key == 'D')
    {
        Left = Left + 10;


        Frame_Update(frame);
    }



    if (key == 'W')
    {
        Up = Up - 10;


        Frame_Update(frame);
    }
    


    if (key == 'S')
    {
        Up = Up + 10;


        Frame_Update(frame);
    }






    if (key == 'J')
    {
        ClipLeft = ClipLeft - 10;


        Frame_Update(frame);
    }



    if (key == 'L')
    {
        ClipLeft = ClipLeft + 10;


        Frame_Update(frame);
    }



    if (key == 'I')
    {
        ClipUp = ClipUp - 10;


        Frame_Update(frame);
    }
    


    if (key == 'K')
    {
        ClipUp = ClipUp + 10;


        Frame_Update(frame);
    }







    return true;
}





Bool DemoExecute()
{
    Int os = CastInt("Draw Demo");



    Int osLength = String_ConstantLength(os);




    Object windowTitle = String_New();



    String_Init(windowTitle);




    String_SetLength(windowTitle, osLength);



    String_SetData(windowTitle, os);






    Int controlHandle;
    
    
    controlHandle = CastInt(&ControlHandle);




    Int drawHandle;


    drawHandle = CastInt(&Draw_FrameDrawHandle);






    Object frame;
    
    

    frame = Frame_New();
    
    
    
    Frame_SetTitle(frame, windowTitle);



    Frame_Init(frame);







    Int handle;

    handle = Frame_GetHandle(frame);




    Object size;

    size = Frame_GetSize(frame);




    FrameSize = size;




    Draw = Draw_Draw_New();




    Draw_Draw_SetHandle(Draw, handle);



    Draw_Draw_SetSize(Draw, size);




    Draw_Draw_Init(Draw);




    Int u;

    u = CastInt(&DrawExecute);



    Draw_Draw_SetMethod(Draw, u);




    



    Brush = Draw_Brush_New();



    Draw_Brush_Init(Brush);




    Int brushU;

    brushU = Draw_ColorBrush_Create();



    Object global;


    global = Draw_Global();



    Object constant;

    constant = Draw_Global_Constant(global);



    Int typeU;

    typeU = Draw_Constant_ColorBrushType(constant);




    Draw_Brush_SetType(Brush, typeU);



    Draw_Brush_SetValue(Brush, brushU);







    Int ca = CastInt("image.img");





    Object name = String_New();



    String_Init(name);





    StorageStringSet(name, ca);





    Object storage = Storage_New();




    Storage_Init(storage);




    Storage_SetName(storage, name);




    Int sizeSt;

    sizeSt = StorageGetSize(storage);




    Int o;
    
    o = New(sizeSt);



    Int buffer;
    
    buffer = o;






    Object data;


    data = Data_New();



    Data_Init(data);



    Data_SetSize(data, sizeSt);


    Data_SetValue(data, buffer);





    StorageExecute(storage, data);






    Storage_Final(storage);




    Storage_Delete(storage);





    String_Final(name);



    String_Delete(name);




    ImageData = data;





    Image = Draw_Image_New();



    Draw_Image_SetData(Image, ImageData);



    Draw_Image_Init(Image);








    Int oss;

    oss = CastInt("Segoe UI Variable Display");


    Int ossLength;

    ossLength = String_ConstantLength(oss);




    Object fontName;


    fontName = String_New();


    String_Init(fontName);


    String_SetLength(fontName, ossLength);


    String_SetData(fontName, oss);





    FontFamily = Draw_FontFamily_New();


    Draw_FontFamily_SetName(FontFamily, fontName);


    Draw_FontFamily_Init(FontFamily);




    Int fontStyle;

    fontStyle = Draw_Constant_FontStyleBold(constant);




    Font = Draw_Font_New();


    Draw_Font_SetFamily(Font, FontFamily);


    Draw_Font_SetSize(Font, 30);


    Draw_Font_SetStyle(Font, fontStyle);



    Draw_Font_Init(Font);





    TextLength = 14;



    void* wos;

    wos = L"DEMO Draw Text";



    Text = CastInt(wos);





    Frame_SetControlHandle(frame, controlHandle);





    Frame_SetDrawHandle(frame, drawHandle);




    Frame_SetDrawHandleArg(frame, Draw);






    Frame_Execute(frame);







    Draw_Font_Final(Font);



    Draw_Font_Delete(Font);





    Draw_FontFamily_Final(FontFamily);



    Draw_FontFamily_Delete(FontFamily);





    String_Final(fontName);



    String_Delete(fontName);





    Draw_Image_Final(Image);



    Draw_Image_Delete(Image);







    Data_Final(ImageData);



    Data_Delete(ImageData);




    Delete(buffer);







    Draw_Brush_Final(Brush);



    Draw_Brush_Delete(Brush);





    Draw_Draw_Final(Draw);




    Draw_Draw_Delete(Draw);







    Frame_Final(frame);



    Frame_Delete(frame);
    




    String_Final(windowTitle);



    String_Delete(windowTitle);




    return true;
}







int main()
{
    Infra_Form_Init();



    Draw_Init();




    DemoExecute();




    Draw_Final();

    

    Infra_Form_Final();


    return 0;
}