/*
 * Arduino.c
 *
 * Created: 19.10.2022 14:33:10
 * Author : deaguiar
 */ 


#include "sam.h"
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"
#include "CAN/can_controller.h"

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
	configure_uart();
	can_init_def_tx_rx_mb(0xA0777);
	
    /* Replace with your application code */
	CAN_MESSAGE* msg_1;
	msg_1->id=10;
	msg_1->data_length=1;
	msg_1->data[0]=0;
	
    while (1) 
    {
		printf("Sending Message %d %d %d\n\r",msg_1->id,msg_1->data_length, msg_1->data[0]);
		can_send(msg_1, 0);
		msg_1->data[0]++;
    }
}
