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




    Int length;

    length = String_GetLength(name);




    Int bufferLength;

    bufferLength = length + 1;


    

    WCHAR* u;

    u = new WCHAR[bufferLength]();




    Draw_FontFamily_CopyString(u, name);




    m->NameWChar = u;



    m->Internal = new Gdiplus::FontFamily(m->NameWChar);




    return true;
}





Bool Draw_FontFamily_Final(Object o)
{
    FontFamily* m;

    m = Draw_FontFamily_Pointer(o);



    delete m->Internal;


    delete[] m->NameWChar;



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







Bool Draw_FontFamily_CopyString(WCHAR* result, Object string)
{
    Int count;
    
    count = String_GetLength(string);



    Int w;
    
    w = 0;



    WCHAR o;
    
    o = L'\0';



    Int i;
    
    i = 0;


    while (i < count)
    {
        w = String_Char(string, i);


        o = (WCHAR)w;


        result[i] = o;



        i = i + 1;
    }



    result[count] = L'\0';



    return true;
}