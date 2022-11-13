/*
 * motor.c
 *
 * Created: 13.11.2022 21:27:00
 *  Author: deaguiar
 */ 

#include <sam.h>
#include "motor.h"
#include "../DAC/dac.h"
#include "../CAN/can_message.h"

void motor_pos(void){
	//MJ1 EN to high PD9
	PIOD->PIO_PER  |= PIO_PER_P9;
	PIOD->PIO_OER  |= PIO_PER_P9;
	PIOD->PIO_SODR |= PIO_PER_P9;
	//MJI DIR right
	PIOD->PIO_PER  |= PIO_PER_P10;
	PIOD->PIO_OER  |= PIO_PER_P10;
	PIOD->PIO_SODR |= PIO_PER_P10;
	//PIOD->PIO_CODR |= PIO_PER_P10;
	//Speed with MJEX A0
	
	uint8_t pos = get_servo_message();
	dac_convert(2000);
}