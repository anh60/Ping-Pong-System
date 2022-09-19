/*
 * Atmega162.c
 *
 * Created: 01.09.2022 14:34:29
 * Author : 
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART/uart.h"
#include "XMEM/xmem.h"
#include "ADC/adc.h"
#include "Joystick/joystick.h"
#include "Tests/sram_test_cr.h"

int main(void)
{
    USART_Init(MYUBRR); //Initializing UART
	printf("Initializing");
	xmem_init();	//Initializing Memory
	adc_init();		//Initializing ADC
	while (1) 
    {
		//SRAM_test();	//Testing memory
		volatile char *ext_mem;
		//xmem_write(20, 0x0000);
		int16_t X = get_X_pos();
		int16_t Y = get_Y_pos();
		int16_t slider_r = get_slider_r();
		int16_t slider_l = get_slider_l();
		joystick_dir direction = get_dir();
		printf("X = %d\n\r", X);
		printf("Y = %d\n\r", Y);
		printf("DIR =%d\n\r", direction);
		printf("Slider RIGHT = %d\n\r", slider_r);
		printf("Slider LEFT = %d\n\r", slider_l);
		//printf("%d\n\r",xmem_read(0x0000));
		_delay_ms(500);
    }
}

