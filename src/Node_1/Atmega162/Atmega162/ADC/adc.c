/*
 * adc.c
 *
 * Created: 14/09/2022 12:17:28 pm
 *  Author: danie
 */ 

#include "adc.h"
#include <avr/io.h>
#include <util/delay.h>

#define BASE_ADDRESS_ADC 0x1400;

void adc_init (void){
	
}

uint8_t adc_read(uint8_t channel){
		volatile char *ext_mem = (char *) BASE_ADDRESS_ADC;
		ext_mem[0x0000]= 0x00;	//Write dummy data to trigger WR signal
		_delay_us(4);
		
		uint8_t ret_val = ext_mem[0x0000];
		printf("ADC: %d\n\r", ret_val);
}
