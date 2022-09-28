/*
 * oled.c
 *
 * Created: 21/09/2022 3:07:37 pm
 *  Author: danie
 */ 

#include "../XMEM/xmem.h"
#include <util/delay.h>
#include "fonts.h"

#define BASE_ADDRESS_OLED_CMD 0x1000;
#define BASE_ADDRESS_OLED_DATA 0x1200;


void OLED_write_cmd(uint8_t cmd){
	volatile char *OLED_CMD = (char *) BASE_ADDRESS_OLED_CMD;
	OLED_CMD[0x0000] = cmd;
}

void OLED_write_data(uint8_t msg){
	volatile char *data = (char *) BASE_ADDRESS_OLED_DATA;
	data[0x0000] = msg;
}

void OLED_init(void){
	 printf("Initializing OLED\n\r");
	 OLED_write_cmd(0xae); //display off
	 OLED_write_cmd(0xa1); //segment remap
	 OLED_write_cmd(0xda); //common pads hardware: alternative
	 OLED_write_cmd(0x12);
	 OLED_write_cmd(0xc8); //common output scan direction:com63~com0
	 OLED_write_cmd(0xa8); //multiplex ration mode:63
	 OLED_write_cmd(0x3f);
	 OLED_write_cmd(0xd5); //display divide ratio/osc. freq. mode
	 OLED_write_cmd(0x80);
	 OLED_write_cmd(0x81); //contrast control
	 OLED_write_cmd(0x50);
	 OLED_write_cmd(0xd9); //set pre-charge period
	 OLED_write_cmd(0x21); //Set Column Address
	 OLED_write_cmd(0x20); //Set Memory Addressing Mode
	 OLED_write_cmd(0x02);
	 OLED_write_cmd(0xdb); //VCOM deselect level mode
	 OLED_write_cmd(0x30);
	 OLED_write_cmd(0xad); //master configuration
	 OLED_write_cmd(0x00);
	 OLED_write_cmd(0xa4); //out follows RAM content
	 OLED_write_cmd(0xa6); //set normal display
	 OLED_write_cmd(0xaf); //display on
}


//Set page address for page addressing mode
void OLED_goto_page(uint8_t page){	//Range 0xb0 - 0xb7	OLED_write_cmd(0xb0 + page);}//Set column address for page addressing modevoid OLED_goto_col(uint8_t col){	//Set Lower Column Start Address	//Range 0x00 - 0x0F	uint8_t lower = col & 0x0F;
	OLED_write_cmd(0x00 + lower);
	
	//Set Higher Column Start Address
	//Range 0x10 - 0x1F
	uint8_t higher = (col >> 4 )& 0x0F ;
	OLED_write_cmd(0x10 + higher);}//Set all pixels to OFF
void OLED_reset(void){
	//Loop through pages
		for (uint8_t page = 0; page < 8; page++) {
			OLED_goto_page(page);
			OLED_goto_col(0);
			//Loop through columns and write 0
			for (uint8_t col = 0; col < 128; col++){
				OLED_write_data(0x00);
				//_delay_ms(1);
			}
		}
}//Set all pixels to ONvoid OLED_all_on(void){
	//Loop through pages
	for (uint8_t page = 0; page < 8; page++) {
		OLED_goto_page(page);
		OLED_goto_col(0);
		//Loop through columns and write 0
		for (uint8_t col = 0; col < 128; col++){
			OLED_write_data(0xFF);
		}
	}
}void OLED_clear_page(uint8_t page){	OLED_goto_page(page);	for (uint8_t col = 0; col < 128; col++){
		OLED_write_data(0x00);
	}}void OLED_get_char_from_font(char character){	unsigned char printable_char[8];	for (uint8_t i=0; i<8; i++){		 printable_char[i] = pgm_read_byte(&(font8[character-32][i]));	//read from PROGMEM		 OLED_write_data(printable_char[i]);	//print	}}void OLED_print_string(void){	char * string = "This is a a waaaay longer test.";	uint8_t string_length;		for (string_length = 0; string[string_length] !='\0'; ++string_length);	//Getting length	
	uint8_t page = 0;
	uint8_t col = 0;
	
	OLED_goto_page(0);
	OLED_goto_col(0);		for (uint8_t i=0; i<string_length; i++){		if(col > 127){			 OLED_goto_page(++page);			 OLED_goto_col(0);			 col = 0;		}		OLED_get_char_from_font(string[i]);		col += 8;	}	}