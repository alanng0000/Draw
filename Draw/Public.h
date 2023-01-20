#pragma once




#include <Infra/Public.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif





Draw_Api
Object Draw_Draw_Create(Int hdc);



Draw_Api
Bool Draw_Draw_Delete(Object o);