/*
 * Atmega162.c
 *
 * Created: 01.09.2022 14:34:29
 * Author : 
 *	Andreas Holleland
 *	Daniel Guarecuco 
 *	Marcus Tjomsaas
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "UART/uart.h"
#include "XMEM/xmem.h"
#include "ADC/adc.h"
#include "Joystick/joystick.h"
#include "Tests/test.h"
#include "OLED/oled.h"
#include "Menu/menu.h"
#include "MCP2515/mcp2515.h"
#include "CAN/can.h"
#include "INT/interrupts.h"

#define F_CPU 4915200UL

int main(void)
{

	USART_Init(MYUBRR); //Initializing UART
	printf("Initializing...\n\r");
	xmem_init();		//Initializing Memory
	adc_init();			//Initializing ADC
	init_buttons();		//Initializing PB buttons
	OLED_init();		//Initializing OLED
	can_init();			//Initializing CAN BUS
	INT_init();			//Initializing Interrupts

	while (1) 
    {
		//Uncomment for testing
		//SRAM_test();				//Testing memory
		//joystick_test();			//Testing joystick and buttons
		//menu_display_switch();	//Testing display

		//CAN message to be sent to node 2
		can_message can_msg;
		can_msg.id = 100;			//ID of Arduino
		can_msg.data_length = 3;	//Data Length
		can_msg.data[0] = get_X_pos();	//Joystick X Position, to control servo
		can_msg.data[1] = get_Y_pos();	//Joystick Y Position, to control motor
		can_msg.data[2] = read_js_button();	//Right touch button, to control solenoid
		
		printf("DATA POS X = %d;\n\r", can_msg.data[0]);
		printf("DATA POS Y = %d;\n\r", can_msg.data[1]);
		printf("DATA BTN = %d;\n\r", can_msg.data[2]);
		can_message_send(can_msg);
		
		_delay_ms(200);		
	}
}



