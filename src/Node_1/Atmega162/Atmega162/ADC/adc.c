/*
 * adc.c
 *
 * Created: 14/09/2022 12:17:28 pm
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */

#include "adc.h"
#include <avr/io.h>
#include <util/delay.h>

#define BASE_ADDRESS_ADC 0x1400;

void adc_init (void){
	MCUCR |= (1 << SRE );  // enable XMEM
	SFIOR |= (1 << XMM2 ); // mask unused bits (PC7-PC4 used for JTAG)	
}

uint8_t adc_read(uint8_t channel){
		if (channel > 3 && channel < 0) {
			printf("ERROR: Channel must be between 0 and 3");
			return 0;
		}
		volatile char *ext_mem_adc = (char *) BASE_ADDRESS_ADC;
		ext_mem_adc[0x0000]= 0x00;	//Write dummy data to trigger WR signal
		_delay_us(15);				//Delay to match timing graph
		volatile uint8_t ret_val[4];
		ret_val[0] = ext_mem_adc[0x0000];
		ret_val[1] = ext_mem_adc[0x0000];
		ret_val[2] = ext_mem_adc[0x0000];
		ret_val[3] = ext_mem_adc[0x0000];
		return ret_val[channel];
}