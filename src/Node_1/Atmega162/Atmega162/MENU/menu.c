/*
 * menu.c
 *
 * Created: 05.10.2022 12:43:30
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */
 
#define F_CPU 4915200

#include "menu.h"
#include "../Joystick/joystick.h"
#include "../OLED/oled.h"
#include <util/delay.h>

char * menu_main[8] = {
	"This is the main menu",
	"1 - Go to menu 1",
	"2 - Go to menu 2",
	"",
	"",
	"",
	"",
	""
};

char * menu_1[8] = {
	"This is menu 1",
	"1 - Go menu 1.1",
	"2 - Do that",
	"3 - Return to main menu",
	"",
	"",
	"",
	""
};

char * menu_2[8] = {
	"This is menu 2",
	"1 - DO this other thing",
	"2 - Do that thing",
	"3 - Return to main menu",
	"",
	"",
	"",
	""
};

uint8_t get_menu_select(uint8_t reset){
	
	static uint8_t page = 0;
	static uint8_t joy_dir = 0;
	static uint8_t selected_option=0;

	if(reset) selected_option = 0;
	
	joy_dir = get_dir();
	OLED_print_arrow(page,119);	//Print arrow on most right column
	
	
	if(joy_dir == DOWN){
		OLED_delete_arrow(page,119);	//Delete old arrow
		if (page == 7)	page = 0;
		else            page++;
		OLED_print_arrow(page,119);		//Print new arrow
	}
	if(joy_dir == UP){
		OLED_delete_arrow(page,119);
		if (page == 0)	page = 7;
		else            page--;
		OLED_print_arrow(page,119);
	}
	
	if (read_js_button()){
		selected_option = page;
	}
	
	return selected_option;	
}

void menu_display_switch(void){
	static uint8_t selected_option = 0;
	static uint8_t old_selected_option=10;
	static uint8_t menu_1_selected_option = 0;
	static uint8_t old_menu_1_selected_option = 10;
	static uint8_t menu_2_selected_option = 0;
	static uint8_t old_menu_2_selected_option = 10;
	
	printf("%s", "\0"); //Printing without printing -- DONT REMOVE EVER

	switch(selected_option){
		case 0:	//Main menu
				selected_option = get_menu_select(0);
				if (selected_option == old_selected_option) break;

				OLED_print_menu(menu_main, NORMAL_font);
				old_selected_option = selected_option;
				break;
				

		case 1: //Menu 1
				menu_1_selected_option = get_menu_select(0);
				if (menu_1_selected_option == old_menu_1_selected_option) break;
			
				OLED_print_menu(menu_1, NORMAL_font);
			
				switch(menu_1_selected_option){
					case 0: break;
					case 1: break; 
					case 2: break;
					default: selected_option = 11; //returns to main menu
							 break;
				}
					
				old_menu_1_selected_option = menu_1_selected_option;
				break;
					
		case 2: //Menu 2
				menu_2_selected_option = get_menu_select(0);
				if (menu_2_selected_option == old_menu_2_selected_option) break;
								
				OLED_print_menu(menu_2, NORMAL_font);
								
				switch(menu_2_selected_option){
					case 0: break;
					case 1: break;
					case 2: break;
					default: selected_option = 11; //returns to main menu
							break;
				}
								
				old_menu_2_selected_option = menu_2_selected_option;
				break;
			

		
		default:
				OLED_print_menu(menu_main, NORMAL_font);
				selected_option = get_menu_select(1);
				old_selected_option = 10;
				break;
	}
	_delay_ms(200);
}