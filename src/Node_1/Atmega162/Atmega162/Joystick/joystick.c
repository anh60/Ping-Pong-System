/*
 * joystick.c
 *
 * Created: 14/09/2022 4:21:41 pm
 *  Author: danie
 */ 

#include "joystick.h"
#include "../ADC/adc.h"
#define  PI 3.1415

int16_t get_X_pos(void){
	volatile uint8_t X_positive = adc_read(1); //X is channel 1. Removing offset
	volatile int16_t X_pos = X_positive - 160;
	
	if(X_pos < 5 && X_pos > -5) return 0;
	
	return X_pos;
}

int16_t get_Y_pos(void){
	volatile uint8_t Y_positive = adc_read(0); //Y is channel 0. Removing offset
	volatile int16_t Y_pos = Y_positive - 159;
	
	if(Y_pos < 5 && Y_pos > -5) return 0;
	return Y_pos;
}

int16_t get_angle(void){
	uint8_t A = 1;
	int16_t X = get_X_pos();
	int16_t Y = get_Y_pos();
	int16_t rad;
	int16_t angle;
	
	if (X != 0){
		rad = Y/X;
		angle = 180*rad/PI;
		}
	else angle = 90;
	
	
	return angle;
}