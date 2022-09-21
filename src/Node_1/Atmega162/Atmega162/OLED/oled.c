/*
 * oled.c
 *
 * Created: 21/09/2022 3:07:37 pm
 *  Author: danie
 */ 

#include "../XMEM/xmem.h"
#include <util/delay.h>
#define BASE_ADDRESS_OLED_CMD 0x1000;
#define BASE_ADDRESS_OLED_DATA 0x1200;

void write_oled_cmd(uint8_t cmd){
	volatile char *command = (char *) BASE_ADDRESS_OLED_CMD;
	command[0x0000] = cmd;
}

void write_oled_data(uint8_t msg){
	volatile char *data = (char *) BASE_ADDRESS_OLED_DATA;
	data[0x0000] = msg;
}

void init_oled(void){
	 write_oled_cmd(0xae); // display off
	 write_oled_cmd(0xa1); //segment remap
	 write_oled_cmd(0xda); //common pads hardware: alternative
	 write_oled_cmd(0x12);
	 write_oled_cmd(0xc8); //common output scan direction:com63~com0
	 write_oled_cmd(0xa8); //multiplex ration mode:63
	 write_oled_cmd(0x3f);
	 write_oled_cmd(0xd5); //display divide ratio/osc. freq. mode
	 write_oled_cmd(0x80);
	 write_oled_cmd(0x81); //contrast control
	 write_oled_cmd(0x50);
	 write_oled_cmd(0xd9); //set pre-charge period
	 write_oled_cmd(0x21);
	 write_oled_cmd(0x20); //Set Memory Addressing Mode
	 write_oled_cmd(0x02);
	 write_oled_cmd(0xdb); //VCOM deselect level mode
	 write_oled_cmd(0x30);
	 write_oled_cmd(0xad); //master configuration
	 write_oled_cmd(0x00);
	 write_oled_cmd(0xa4); //out follows RAM content
	 write_oled_cmd(0xa6); //set normal display
	 write_oled_cmd(0xaf); // display on
	 
	
}


void OLED_print_arrow (void )
{
	write_oled_data (0b00011000 );
	write_oled_data (0b00011000 );
	write_oled_data (0b01111110 );
	write_oled_data (0b00111100 );
	write_oled_data (0b00011000 );
}