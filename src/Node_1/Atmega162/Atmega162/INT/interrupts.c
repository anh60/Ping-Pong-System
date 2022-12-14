/*
 * interrupts.c
 *
 * Created: 19.10.2022 13:26:00
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */ 

#include "interrupts.h"
#include "../CAN/can.h"
#include <util/delay.h>

void INT_init(void){
	GICR |= 1<<INT0;		/* Enable INT0*/
	MCUCR |= 1<<ISC01 & ~(1<<ISC00);  /* Trigger INT0 on falling edge */	
	sei();			/* Enable Global Interrupt */
}

/*Interrupt Service Routine for INT0*/
ISR(INT0_vect)
{
	printf("This is an INT0: CAN message:\n\r");
	can_message can_message_rtr = can_message_receive();
	printf("ID=%d, length=%d, data=%d, data2=%d\n\r",can_message_rtr.id, can_message_rtr.data_length, can_message_rtr.data[0],can_message_rtr.data[1]);
	_delay_ms(50);  	/* Software debouncing control delay */	
}
