#pragma once




#include <Infra/Public.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif




ObjectApi(Draw, Draw)




Draw_Api
Object Draw_Color(Object this, Int color, Object rect);