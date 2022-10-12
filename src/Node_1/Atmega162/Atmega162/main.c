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


int main(void)
{

	USART_Init(MYUBRR); //Initializing UART
	printf("Initializing...\n\r");
	xmem_init();		//Initializing Memory
	adc_init();			//Initializing ADC
	init_buttons();		//Init PB buttons
	OLED_init();		//Init OLED
	//SPI_init();			//Iinit SPI
	mcp2515_init();

	while (1) 
    {
		//SRAM_test();	//Testing memory
		//joystick_test();
		//menu_display_switch();

		can_message can_msg;
		can_msg.id = 2;
		can_msg.data_length = 2;
		can_msg.data[0] = 6;
		can_msg.data[1] = 7;
		can_message_send(can_msg);
		can_message can_message_rtr = can_message_receive();
		printf("ID=%d, length=%d, data=%d, data2=%d\n\r",can_message_rtr.id, can_message_rtr.data_length, can_message_rtr.data[0],can_message_rtr.data[1]);
		_delay_ms(500);	
	}
}



