/*
 * joystick.h
 *
 * Created: 14/09/2022 4:21:29 pm
 *  Author: danie
 */ 


#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include <stdio.h>

typedef enum joystick_dir{LEFT, RIGHT, UP, DOWN, NEUTRAL} joystick_dir;
	
int16_t get_X_pos(void);
int16_t get_Y_pos(void);
joystick_dir get_dir(void);

int16_t get_slider_r(void);




#endif /* JOYSTICK_H_ */