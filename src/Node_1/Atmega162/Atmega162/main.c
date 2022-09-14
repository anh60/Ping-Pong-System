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
#include "Tests/sram_test_cr.h"

int main(void)
{
    USART_Init(MYUBRR); //Initializing UART
	printf("Initializing");
	xmem_init();	//Initializing Memory
	while (1) 
    {
		SRAM_test();	//Testing memory
		//volatile char *ext_mem;
		//uint8_t ret_val = ext_mem[0x1400];
		//adc_read(1);
		_delay_ms(500);
    }
}

