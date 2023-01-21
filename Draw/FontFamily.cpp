#include "FontFamily.h"






Object Draw_FontFamily_New()
{
    FontFamily* m;

    m = new FontFamily();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_FontFamily_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}





Bool Draw_FontFamily_Init(Object o)
{
    FontFamily* m;

    m = Draw_FontFamily_Pointer(o);




    Object name;

    name = m->Name;



    Int data;

    data = String_GetData(name);



    Int length;

    length = String_GetLength(name);




    Int bufferLength;

    bufferLength = length + 1;


    
    
    WCHAR* o;

    o = new WCHAR[bufferLength]();





    m->NameWChar = o;




    m->FontFmaily = new Gdiplus::FontFamily(m->NameWChar);




    return true;
}





Object Draw_FontFamily_GetName(Object o)
{
    FontFamily* m;

    m = Draw_FontFamily_Pointer(o);



    return m->Name;
}




Bool Draw_FontFamily_SetName(Object o, Object value)
{
    FontFamily* m;

    m = Draw_FontFamily_Pointer(o);



    m->Name = value;


    return true;
}





FontFamily* Draw_FontFamily_Pointer(Object o)
{
    FontFamily* m;

    m = (FontFamily*)o;


    return m;
}