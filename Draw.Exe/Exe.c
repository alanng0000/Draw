#include "Exe.h"




int main(int argc, char* argv[])
{
    Infra_Form_Init();


    Draw_Init();




    Object draw;

    draw = Draw_Draw_New();



    Draw_Draw_Init(draw);



    Draw_Draw_Final(draw);
    



    Draw_Draw_Delete(draw);





    Infra_Form_Final();



    int ret;

    ret = 0;


    return ret;
}