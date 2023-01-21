#include "Exe.h"









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




Bool DrawHandle(Object frame)
{

}




Bool ControlHandle(Object frame, Int key, Int value)
{
    //ControlHandleConsoleWriteKeyValue(key, value);




    if (key == 0x20)
    {
        if (value == 1)
        {
            Frame_Close(frame);


            return true;
        }
    }




    if (value == 0)
    {
        return true;
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





    Int handle;
    
    
    handle = CastInt(&ControlHandle);




    Int u;


    u = CastInt(&DrawHandle);





    Object frame;
    
    

    frame = Frame_New();
    
    
    
    Frame_SetTitle(frame, windowTitle);



    Frame_Init(frame);



    Frame_SetControlHandle(frame, handle);



    Frame_SetDrawHandle(frame, u);



    Frame_SetVisible(frame, true);




    Frame_Execute(frame);




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