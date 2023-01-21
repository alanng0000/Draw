#include "Local.h"





struct Global
{
    Object Constant;


};






Object Draw_Global_New();



Bool Draw_Global_Delete(Object o);




Bool Draw_Global_Init(Object o);



Bool Draw_Global_Final(Object o);








Global* Draw_Global_Pointer(Object o);