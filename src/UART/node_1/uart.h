#ifndef UART_H_
#define UART_H_

#define FOSC 1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC / 16 / BAUD - 1

void USART_Init(unsigned int ubrr);

void USART_Transmit(unsigned char data);
unsigned char USART_Receive(void);
void USART_Flush(void);

#endif /* UART_H_ */