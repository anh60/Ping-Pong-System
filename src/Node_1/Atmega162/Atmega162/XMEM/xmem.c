/*
 * xmem.c
 *
 * Created: 9/7/2022 11:32:10 AM
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */

#include "xmem.h"
#include <avr/io.h>

#define BASE_ADDRESS 0x1800;	//SRAM base address

/*Initializing external memory driver
Basic code taken from slides
*/
void xmem_init(void){
	MCUCR |= (1 << SRE );  // enable XMEM
	SFIOR |= (1 << XMM2 ); // mask unused bits (PC7-PC4 used for JTAG)
	SFIOR &= ~(1 << XMM1 );
	SFIOR &= ~(1 << XMM0 );
}

// Write to external SRAM
void xmem_write(uint8_t data , uint16_t addr){
	volatile char *ext_mem = (char *) BASE_ADDRESS;
	ext_mem[addr]= data;
}

// Read from external SRAM
uint8_t xmem_read(uint16_t addr){
	volatile char *ext_mem = (char *) BASE_ADDRESS;
	uint8_t ret_val = ext_mem[addr];
	return ret_val ;
}
