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



    Object constants;
    
    

    constants = Constants_New();



    Constants_Init(constants);



    m->Constants = constants;



    return true;
}





Bool Global_Final(Object this)
{
    Global* m = CastPointer(this);



    Object constants = m->Constants;



    Constants_Final(constants);



    Constants_Delete(constants);



    return true;
}





Object Global_Constants(Object this)
{
    Global* m = CastPointer(this);


    return m->Constants;
}





Object Draw_Global_Data;




Object Draw_Global()
{
    return Draw_Global_Data;
}