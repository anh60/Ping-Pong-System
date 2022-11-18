/*
 * can_message.c
 *
 * Created: 02.11.2022 16:13:11
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */


#include "stdio.h"
#include "can_message.h"

uint8_t get_servo_message(void){
	uint8_t servo_message = msg.data[0];
	return servo_message;
}

uint8_t get_motor_message(void){
	uint8_t motor_message = msg.data[1];
	return motor_message;
}

uint8_t get_touch_btn(void){
	uint8_t btn_message = msg.data[2] & 0x1;
	return btn_message;
}