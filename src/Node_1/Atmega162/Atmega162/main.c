/*
 * Atmega162.c
 *
 * Created: 01.09.2022 14:34:29
 * Author : Andreas, Daniel and Marcus
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
//#include "SPI/spi.h"
#include "MCP2515/mcp2515.h"
#include "CAN/can.h"

#define F_CPU 4915200UL

int main(void)
{

	USART_Init(MYUBRR); //Initializing UART
	printf("Initializing...\n\r");
	xmem_init();		//Initializing Memory
	adc_init();			//Initializing ADC
	init_buttons();		//Init PB buttons
	OLED_init();		//Init OLED
	can_init();
	INT_init();

	while (1) 
    {
		//SRAM_test();	//Testing memory
		//joystick_test();
		//menu_display_switch();

		
		can_message can_msg;
		can_msg.id = 100; //ID of Arduino
		can_msg.data_length = 3; //Data Length
		can_msg.data[0] = get_X_pos();
		can_msg.data[1] = get_Y_pos();
		can_msg.data[2] = read_touch_button_r();
		
		printf("DATA POS X = %d;\n\r", can_msg.data[0]);
		printf("DATA POS Y = %d;\n\r", can_msg.data[1]);
		printf("DATA BTN = %d;\n\r", can_msg.data[2]);
		can_message_send(can_msg);
		
		_delay_ms(200);
			
	}
}



