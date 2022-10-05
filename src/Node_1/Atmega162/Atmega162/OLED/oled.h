/*
 * oled.h
 *
 * Created: 21/09/2022 3:13:44 pm
 *  Author: danie
 */ 


#ifndef OLED_H_
#define OLED_H_

#define SMALL_font 4
#define NORMAL_font 5
#define BIG_font 8

void OLED_write_cmd(uint8_t cmd);
void OLED_write_data(uint8_t msg);
void OLED_init(void);
void OLED_goto_page(uint8_t line);
void OLED_goto_col(uint8_t col);
void OLED_reset(void);
void OLED_all_on(void);
void OLED_clear_page(uint8_t page);
void OLED_get_char_from_font(char character);
void OLED_print_string(char * string, uint8_t page, uint8_t font_size);
void OLED_print(char*);
void OLED_test(void);
void OLED_print_menu(char * string[8], uint8_t font_size);
void OLED_print_arrow(uint8_t row , uint8_t col);
void OLED_delete_arrow(uint8_t row , uint8_t col);

#endif /* OLED_H_ */