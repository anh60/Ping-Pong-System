/*
 * solenoid.c
 *
 * Created: 16.11.2022 16:16:24
 *  Author: deaguiar
 */ 

#include <sam.h>
#include "solenoid.h"
#include "../CAN/can_message.h"

void init_solenoid(void){
	//PIN PC9(PIN41) as output
	PIOC->PIO_PER  |= PIO_PER_P9;
	PIOC->PIO_OER  |= PIO_PER_P9;
}

void activate_solenoid(void){
	uint8_t btn = get_touch_btn();
	//PIN PC9(PIN41) as output
	PIOC->PIO_SODR |= PIO_PER_P9;
	if (btn ==1)
	{
		PIOC->PIO_CODR |= PIO_PER_P9;
	}
	btn = 0;
	
}