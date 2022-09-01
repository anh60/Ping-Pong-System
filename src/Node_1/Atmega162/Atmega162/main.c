/*
 * Atmega162.c
 *
 * Created: 01.09.2022 14:34:29
 * Author : 
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART/uart.h"

int main(void)
{
    USART_Init(MYUBRR); //Initializing UART

	char myChar;
	while (1) 
    {
		//myChar = USART_Receive();
		//USART_Transmit(myChar+1);

		printf("Hello world\n");
		_delay_ms(500);
    }
}

