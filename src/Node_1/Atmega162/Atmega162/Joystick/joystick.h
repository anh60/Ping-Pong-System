/*
 * joystick.h
 *
 * Created: 14/09/2022 4:21:29 pm
 *  Author: Andreas, Daniel and Marcus
 */ 


#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include <stdio.h>
#include <avr/io.h>

typedef enum joystick_dir{LEFT, RIGHT, UP, DOWN, NEUTRAL} joystick_dir;
	
int16_t get_X_pos(void);
int16_t get_Y_pos(void);
joystick_dir get_dir(void);
int16_t get_slider_r(void);
int16_t get_slider_l(void);

void init_buttons(void);
uint8_t read_PB(uint8_t PIN);
uint8_t read_js_button(void);
uint8_t read_touch_button_r(void);
uint8_t read_touch_button_l(void);




#endif /* JOYSTICK_H_ */