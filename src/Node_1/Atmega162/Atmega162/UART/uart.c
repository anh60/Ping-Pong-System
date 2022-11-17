/*
 * uart.c
 *
 * Created: 9/7/2022 11:32:10 AM
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */

/* This is taken from ATMEGA162 datasheet*/

#include <avr/io.h>
#include "uart.h"

void USART_Init(unsigned int ubrr)
{
    /* Set baud rate */
    UBRR0H |= (unsigned char)(ubrr >> 8);
    UBRR0L |= (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C |= (1 << URSEL0) | (1 << USBS0) | (3 << UCSZ00);
	
	fdevopen(USART_Transmit, USART_Receive);
}

void USART_Transmit(unsigned char data)
{
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

unsigned char USART_Receive(void)
{
    /* Wait for data to be received */
    while (!(UCSR0A & (1 << RXC0)))
        ;
    /* Get and return received data from buffer */
    return UDR0;
}

void USART_Flush(void)
{
    unsigned char dummy;
    while (UCSR0A & (1 << RXC0))
        dummy = UDR0;
}