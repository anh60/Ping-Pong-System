/*
 * joystick.c
 *
 * Created: 14/09/2022 4:21:41 pm
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */

#include <stdlib.h>
#include "joystick.h"
#include "../ADC/adc.h"
#define  PI 3.1415

#define TH 20

//LEFT MAX = 158
//RIGHT MAX = 100
int16_t get_X_pos(void){
	volatile uint8_t X_positive;
	volatile uint16_t sum;
	
	//Averages
	sum = 0;
	for (int i=0; i<TH ;i++){
		sum += adc_read(0);
	}
	X_positive = sum /TH;
	volatile double X_pos = X_positive - 160;
	
	//Threshold
	if(X_pos < 20 && X_pos > -20) return 0;
	
	//Map to 0-100
	if(X_pos >=0) return X_pos*1.06;
	else return X_pos*0.63;
}

int16_t get_Y_pos(void){
	volatile uint8_t Y_positive;
	volatile uint16_t sum;
	sum = 0;
	for (int i=0; i<TH ;i++){
		sum += adc_read(1);
	}
	Y_positive = sum /TH;
	volatile double Y_pos = Y_positive - 159;
	
	if(Y_pos < 20 && Y_pos > -20) return 0;
	
	if(Y_pos >=0) return Y_pos*1.05;
	else return Y_pos*0.64;
}

joystick_dir get_dir(void){
	int16_t X = get_X_pos();
	int16_t Y = get_Y_pos();
	if (X==0 && Y==0) return NEUTRAL;
	if (abs(X) > abs(Y)) {
		if(X>0)return RIGHT;
		if(X<0)return LEFT; 
	}
	else{
		if(Y>0)return UP;
		if(Y<0)return DOWN;
	}
return NEUTRAL;
}

static int16_t get_slider(uint8_t dir){
	volatile uint8_t value;
	volatile uint16_t sum=0;
	for (int i=0; i<TH ;i++){
		sum += adc_read(dir+2);
	}
	value = sum /TH;
	
	return value*100/255;
}

int16_t get_slider_r(void){
	return get_slider(1);
}

int16_t get_slider_l(void){
	return get_slider(0);
}

void init_buttons(void){
	DDRB &= ~(1 << PINB1);
	DDRB &= ~(1 << PINB2);
	DDRB &= ~(1 << PINB3);
}

uint8_t read_PB(uint8_t PIN){
	return (PINB & (1 << PIN)) >> PIN;
}

uint8_t read_js_button(void){
	uint8_t value = read_PB(PINB1);
	//Button is pulled up on open state.
	if (value == 0) return 1;
	else return 0;
}

uint8_t read_touch_button_r(void){
	//Button is pulled down on open state.
	return read_PB(PINB2);
}

uint8_t read_touch_button_l(void){
	//Button is pulled down on open state.
	return read_PB(PINB3);
}