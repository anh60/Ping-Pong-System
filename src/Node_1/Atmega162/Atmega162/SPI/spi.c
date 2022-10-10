/*
 * spi.c
 *
 * Created: 10/10/2022 2:11:55 pm
 *  Author: 
 */ 

#include "spi.h"

	DDRB = (1<<DDB4)|(1<<DDB5)|(1<<DDB7);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	SPCR &= ~(1<<CPOL)| ~(1<<CPHA);
void SPI_send(uint8_t data){
	PORTB &= ~(1 << PB4);
	/* Transmission starts when writing to SPDR register */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
uint8_t SPI_read(void){