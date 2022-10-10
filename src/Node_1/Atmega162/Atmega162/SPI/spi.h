/*
 * spi.h
 *
 * Created: 10/10/2022 2:12:05 pm
 *  Author: danie
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdio.h>
#include <avr/io.h>

void SPI_init(void);
void SPI_send(uint8_t data);
uint8_t SPI_read(void);


#endif /* SPI_H_ */