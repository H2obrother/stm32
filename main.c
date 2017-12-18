

#include <stm32f10x.h>
#include <stm32f10x_usart.h>
#include "uart.h"
#include "led.h"
void Delay( uint32_t nTime );

void main(void){
	uart_open(USART1,115200);
	configLight(LED2);	
	char input;
	if( SysTick_Config ( SystemCoreClock / 1000))
		while(1);

	while(1){
		char c;
	if(c = uart_getc(USART1))
		delightLed();
	Delay(250);
}
}

/*int uart_puts(char* string){
	int i;
	for ( i = 0; string[i] != '\0'; i++) {
		uart_putc(string[i],USART1);
	}
	return i;
}
*/
static __IO uint32_t TimingDelay ;
void Delay( uint32_t nTime ){
	TimingDelay = nTime ;
	while ( TimingDelay != 0);
}
void SysTick_Handler (void){
	if ( TimingDelay != 0x00)
	TimingDelay --;
}


void assert_failed(uint8_t* file,uint32_t line){
	while(1);
}
