
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include "led.h"


GPIO_InitTypeDef gpioInit;
GPIO_TypeDef* gpioPort;



 int configLight(int LEDx){
 GPIO_StructInit(&gpioInit);

 gpioInit.GPIO_Mode = GPIO_Mode_Out_PP;
 gpioInit.GPIO_Speed = GPIO_Speed_2MHz;
 gpioInit.GPIO_Pin = GPIO_Pin_5;

 switch(LEDx)
{

 case LED2:
 gpioPort = GPIOE;
 break ;

 case LED3:
 gpioPort = GPIOB;
 break;
 case LEDboth:
 gpioPort = (((uint32_t)GPIOB) & ((uint32_t)GPIOE));

 break;
 }

RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
 GPIO_Init(gpioPort, &gpioInit);
dimLed(); 
 return 0;
 }
 int delightLed(){
 GPIO_WriteBit(gpioPort,	gpioInit.GPIO_Pin,	Bit_RESET);
 return 0;
 }

 int dimLed(){
 GPIO_WriteBit(gpioPort,gpioInit.GPIO_Pin,Bit_SET);
 return 0;
 } 
 int configButton(){
 GPIO_InitTypeDef buttonInit;
buttonInit.GPIO_Mode = GPIO_Mode_IN_FLOATING;
buttonInit.GPIO_Speed = GPIO_Speed_2MHz;
buttonInit.GPIO_Pin = GPIO_Pin_2;
GPIO_Init(GPIOE, &buttonInit);
return 0;
 }
 int readButtonValue(){
return GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2);
}
 
