#include "Exe.h"




Object Draw;



Object Brush;



Object Image;



Object Data;



IStream* Stream;




Byte Comp;











Bool StorageStringSet(Object string, Int charArray)
{
    Int k = String_ConstantLength(charArray);



    Int length = k + 1;



    String_SetLength(string, length);


    String_SetData(string, charArray);



    return true;
}





Bool StreamExecute()
{
    Int o;

    o = Data_GetValue(Data);



    Int size;

    size = Data_GetSize(Data);



    Int32 sizeU;

    sizeU = (Int32)size;



    void* p;

    p = CastPointer(o);




    Stream = SHCreateMemStream(p, sizeU);


    return true;
}






Bool StorageExecute()
{
    Int ca = CastInt("sun_and_cloud.jpg");





    Object name = String_New();



    String_Init(name);





    StorageStringSet(name, ca);





    Object storage = Storage_New();




    Storage_Init(storage);





    Storage_SetName(storage, name);





    Storage_Status(storage);



    Int demoFileSize;
    

    demoFileSize = Storage_GetSize(storage);





    Storage_SetMode(storage, 0);





    Storage_Open(storage);




    Int size;
    
    size = demoFileSize;




    Int o = New(size);



    Int buffer = o;




    Object data;


    data = Data_New();



    Data_Init(data);



    Data_SetSize(data, size);


    Data_SetValue(data, buffer);





    Storage_Read(storage, data);



    



    Storage_Close(storage);







    Storage_Final(storage);




    Storage_Delete(storage);





    String_Final(name);



    String_Delete(name);






    Data = data;




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
    SInt left;

    left = 100;


    SInt up;

    up = 100;


    Int width;

    width = 400;


    Int height;

    height = 400;




    Int color;


    color = 0x80000000;


    color = color | Comp;





    Draw_ColorBrush_SetColor(Brush, color);




    Draw_Draw_Rect(draw, left, up, width, height, Brush);





    Draw_Draw_Image(draw, Image, 400, 400, 800, 400, 600, 600, 800, 400);

    


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




    if (key == 'A')
    {
        Comp = Comp + 10;


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





    Draw = Draw_Draw_New();




    Draw_Draw_SetHandle(Draw, handle);



    Draw_Draw_SetSize(Draw, size);




    Draw_Draw_Init(Draw);




    Int u;

    u = CastInt(&DrawExecute);



    Draw_Draw_SetMethod(Draw, u);




    



    Brush = Draw_ColorBrush_New();



    Draw_ColorBrush_Init(Brush);






    StorageExecute();



    StreamExecute();




    Image = Draw_Image_New();




    Int streamU;

    streamU = CastInt(Stream);



    Draw_Image_SetStream(Image, streamU);



    Draw_Image_Init(Image);







    Frame_SetControlHandle(frame, controlHandle);





    Frame_SetDrawHandle(frame, drawHandle);




    Frame_SetDrawHandleArg(frame, Draw);





    Frame_SetVisible(frame, true);




    Frame_Execute(frame);






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