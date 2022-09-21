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

int main(void)
{
    printf("Initializing...\n\r");
	USART_Init(MYUBRR); //Initializing UART
	xmem_init();	//Initializing Memory
	adc_init();		//Initializing ADC
	init_buttons();	//Init PB buttons
	init_oled();
	
	while (1) 
    {
		//SRAM_test();	//Testing memory
		//joystick_test();
		//volatile char *value = (char *) 0x0000;
		//value[0x1800] = 0x0A;
		//value[0x1400] = 0x00;
		//value[0x1000] = 0x00;
		write_oled_cmd(0xa5); // display on
		//OLED_print_arrow();
		//uint8_t ret_val = value[0x1800]; 
		//printf("%d\n\r",ret_val);

		_delay_ms(500);
    }
}

