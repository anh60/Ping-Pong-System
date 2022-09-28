/*
 * Atmega162.c
 *
 * Created: 01.09.2022 14:34:29
 * Author : Andreas, Daniel and Marcus
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART/uart.h"
#include "XMEM/xmem.h"
#include "ADC/adc.h"
#include "Joystick/joystick.h"
#include "Tests/test.h"
#include "OLED/oled.h"
#define BASE_ADDRESS_OLED_CMD 0x1000


int main(void)
{

	USART_Init(MYUBRR); //Initializing UART
	printf("Initializing...\n\r");
	xmem_init();	//Initializing Memory
	adc_init();		//Initializing ADC
	init_buttons();	//Init PB buttons
	OLED_init();
	

	while (1) 
    {
		//SRAM_test();	//Testing memory
		//joystick_test();
		OLED_reset();
		OLED_print_string();
		_delay_ms(5000);
		//OLED_clear_page(4);
		//OLED_test();
		_delay_ms(5000);
    }
}



