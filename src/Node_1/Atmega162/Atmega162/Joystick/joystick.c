/*
 * joystick.c
 *
 * Created: 14/09/2022 4:21:41 pm
 *  Author: danie
 */ 

#include "joystick.h"
#include "../ADC/adc.h"
#define  PI 3.1415

#define TH 20

int16_t get_X_pos(void){
	volatile uint8_t X_positive;
	volatile uint16_t sum=0;
	for (int i=0; i<TH ;i++){
		sum += adc_read(1);
	}
	X_positive = sum /TH;
	volatile double X_pos = X_positive - 160;
	
	if(X_pos < 10 && X_pos > -10) return 0;
	
	if(X_pos >=0) return X_pos*1.06;
	else return X_pos*0.63;
}

int16_t get_Y_pos(void){
	volatile uint8_t Y_positive;
	volatile uint16_t sum=0;
	for (int i=0; i<TH ;i++){
		sum += adc_read(0);
	}
	Y_positive = sum /TH;
	volatile double Y_pos = Y_positive - 159;
	
	if(Y_pos < 10 && Y_pos > -10) return 0;
	
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