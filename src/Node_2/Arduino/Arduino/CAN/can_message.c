/*
 * can_message.c
 *
 * Created: 02.11.2022 16:13:11
 *  Author: deaguiar
 */ 


#include "stdio.h"
#include "can_message.h"

uint8_t get_servo_message(void){
	uint8_t servo_message = msg.data[0];
	return servo_message;
}