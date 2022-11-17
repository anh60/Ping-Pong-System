/*
 * spi.c
 *
 * Created: 10/10/2022 2:11:55 pm
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */

#include "spi.h"/* Init procedure. Partially taken from datasheet */void SPI_init(void){
	/* Set SSn, MOSI and SCK as output, all others input */
	DDRB = (1<<DDB4)|(1<<DDB5)|(1<<DDB7);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	/* Set SPI Mode = 0 (CPOL=0, CPHA=0) */
	SPCR &= ~(1<<CPOL)| ~(1<<CPHA);}
void SPI_send(uint8_t data){
	/* Transmission starts when writing to SPDR register */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;}
uint8_t SPI_read(void){	SPI_send(0xAA); //Send dummy data	//Read data left in the SPI data register	return SPDR;}
