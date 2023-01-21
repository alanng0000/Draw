#include "Global.h"







Object Draw_Global_New()
{
    Global* m;

    m = new Global();


    Object o;

    o = CastInt(m);


    return o;
}




Bool Draw_Global_Delete(Object o)
{
    void* p;

    p = CastPointer(o);


    delete p;


    return true;
}






Bool Draw_Global_Init(Object o)
{
    Global* m;
    
    m = Draw_Global_Pointer(o);



    Object constant;
    
    

    constant = Draw_Constant_New();



    Draw_Constant_Init(constant);



    m->Constant = constant;



    return true;
}





Bool Draw_Global_Final(Object o)
{
    Global* m;
    

    m = Draw_Global_Pointer(o);





    Object constant;
    


    constant = m->Constant;



    Draw_Constant_Final(constant);



    Draw_Constant_Delete(constant);



    return true;
}





Object Draw_Global_Constant(Object o)
{
    Global* m;
    

    m = Draw_Global_Pointer(o);




    return m->Constant;
}






Object Draw_Global_Data;




Object Draw_Global()
{
    return Draw_Global_Data;
}