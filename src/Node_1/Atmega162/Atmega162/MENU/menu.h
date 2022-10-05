/*
 * menu.h
 *
 * Created: 05.10.2022 12:43:42
 *  Author: deaguiar
 */ 


#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <avr/io.h>

uint8_t get_menu_select(uint8_t reset);
void menu_display_switch(void);





#endif /* MENU_H_ */