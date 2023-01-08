#pragma once




#include <Infra/Public.h>
#include <Infra.Form.Infra/Public.h>




#ifdef Draw_Module
#define Draw_Api __declspec(dllexport)
#else
#define Draw_Api __declspec(dllimport)
#endif




ObjectApi(Draw, Draw)




Draw_Api
Int Draw_GetPixelList(Object this);


Draw_Api
Bool Draw_SetPixelList(Object this, Int value);





Draw_Api
Object Draw_GetSize(Object this);


Draw_Api
Bool Draw_SetSize(Object this, Object value);






Draw_Api
Object Draw_Color(Object this, Int color, Object rect);