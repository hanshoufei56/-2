#include "stm32f10x.h"// ???51?????  #include <reg51.h>
#include "stm32f10x_gpio.h"
/*??????LED????
*????????,????????!!!!!
*1?LED???????K1????LED???,??K1??LED??
*2????key??LED?,??????LED?
*
*/

/*??GPIO
*step1????
*???:Speed?Mode?Pin
*???
*/
int main(void)
{
    //?????
    //step1:??
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    //???
    GPIO_InitTypeDef a;
    a.GPIO_Speed=GPIO_Speed_50MHz;
    a.GPIO_Pin=GPIO_Pin_5;
    //????
    a.GPIO_Mode=GPIO_Mode_Out_PP;
    //??GPIO?????
    GPIO_Init(GPIOB,&a);
    //??PB5????
    //GPIO_ResetBits(GPIOB,GPIO_Pin_5);
    //GPIO_SetBits(GPIOB,GPIO_Pin_5);
    
    
    
    /**************????*************/
    
    //step1:????
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    //step2:??GPIO????????
    GPIO_InitTypeDef b;
    b.GPIO_Speed=GPIO_Speed_50MHz;
    b.GPIO_Pin=GPIO_Pin_0;
    //????
    b.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    //stept3:??GPIO?????
    GPIO_Init(GPIOA,&b);
/************************1********************************/
/*
*???:???????:GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
*???????
*/

        /*LED???????K1????LED???,??K1??LED??*/
        
    while(1)//????????????
    {
            //???????????i
        int i = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
        if(i==0)//??K1??????0
        {
                //?0?,??PB5????,
            GPIO_SetBits(GPIOB,GPIO_Pin_5);
        }
        else
        {
            
                //??PB5????
            GPIO_ResetBits(GPIOB,GPIO_Pin_5);
        }
    }
    

/***************************2*********************************/
/*********???????????LED?,????LED?*********/
    int pre=0;//??????????
    while(1)
    {
        //???????
        int states = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
        if(states==0&&pre==1)//states?????????,???????????????
        {
            //????????,states????0,?????????pre?????1
            if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0)//?????????
            {
                //?GPIOB??5??????,??LED?
                GPIO_SetBits(GPIOB,GPIO_Pin_5);
            }
            else
            {
                //?GPIOB??5??????,??LED?
                    GPIO_ResetBits(GPIOB,GPIO_Pin_5);
            }
        }
        pre=states;//????????????????
    }
/*******************************************************************/    
}