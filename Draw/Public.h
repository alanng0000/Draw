#pragma once




#include <Infra/Public.h>
#include <Infra.Form.Infra/Public.h>



#ifdef Draw_Module
#define Draw_Api ExportApi
#else
#define Draw_Api ImportApi
#endif





ObjectApi(Draw, Draw)





Draw_Api
Int Draw_Draw_GetHandle(Object o);




Draw_Api
Bool Draw_Draw_SetHandle(Object o, Int value);





Draw_Api
Object Draw_Draw_GetSize(Object o);




Draw_Api
Bool Draw_Draw_SetSize(Object o, Object value);





Draw_Api
Int Draw_Draw_GetMethod(Object o);




Draw_Api
Bool Draw_Draw_SetMethod(Object o, Int value);






Draw_Api
Bool Draw_Draw_Clear(Object o, Int color);





Draw_Api
Bool Draw_Draw_Rect(Object o, SInt left, SInt up, Int width, Int height, Object brush);





Draw_Api
Bool Draw_Draw_Image(Object o, Object image, SInt destLeft, SInt destUp, Int destWidth, Int destHeight,
    SInt sourceLeft, SInt sourceUp, Int sourceWidth, Int sourceHeight);
    




Draw_Api
Bool Draw_Draw_Text(Object o, Int string, Int length, Object font, SInt rectLeft, SInt rectUp, Int rectWidth, Int rectHeight, Object brush);





ObjectApi(Draw, Brush)




Draw_Api
Int Draw_Brush_GetType(Object o);




Draw_Api
Bool Draw_Brush_SetType(Object o, Int value);





Draw_Api
Int Draw_Brush_GetValue(Object o);




Draw_Api
Bool Draw_Brush_SetValue(Object o, Int value);






Draw_Api
Int Draw_ColorBrush_Create();




Draw_Api
Int Draw_ColorBrush_GetColor(Object o);



Draw_Api
Bool Draw_ColorBrush_SetColor(Object o, Int value);







ObjectApi(Draw, Image)





Draw_Api
Int Draw_Image_GetStream(Object o);




Draw_Api
Bool Draw_Image_SetStream(Object o, Int value);





Draw_Api
Object Draw_Image_GetSize(Object o);






ObjectApi(Draw, FontFamily)




Draw_Api
Object Draw_FontFamily_GetName(Object o);




Draw_Api
Bool Draw_FontFamily_SetName(Object o, Object value);






ObjectApi(Draw, Font)




Draw_Api
Object Draw_Font_GetFamily(Object o);




Draw_Api
Bool Draw_Font_SetFamily(Object o, Object value);





Draw_Api
Int Draw_Font_GetSize(Object o);




Draw_Api
Bool Draw_Font_SetSize(Object o, Int value);





Draw_Api
Int Draw_Font_GetStyle(Object o);




Draw_Api
Bool Draw_Font_SetStyle(Object o, Int value);





Draw_Api
Int Draw_Constant_DefaultColor(Object o);




Draw_Api
Int Draw_Constant_ColorBrushType(Object o);




Draw_Api
Int Draw_Constant_FontStyleRegular(Object o);



Draw_Api
Int Draw_Constant_FontStyleBold(Object o);



Draw_Api
Int Draw_Constant_FontStyleItalic(Object o);



Draw_Api
Int Draw_Constant_FontStyleUnderline(Object o);







Draw_Api
Object Draw_Global_Constant(Object o);




Draw_Api
Object Draw_Global();







Draw_Api
Bool Draw_FrameDrawHandle(Object arg);






typedef Bool (*Draw_Draw_Method)(Object draw);






Draw_Api
Bool Draw_Init();




Draw_Api
Bool Draw_Final();