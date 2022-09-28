/*
 * oled.h
 *
 * Created: 21/09/2022 3:13:44 pm
 *  Author: danie
 */ 


#ifndef OLED_H_
#define OLED_H_

void OLED_write_cmd(uint8_t cmd);
void OLED_write_data(uint8_t msg);
void OLED_init(void);
void OLED_goto_page(uint8_t line);
void OLED_goto_col(uint8_t col);
void OLED_reset(void);
void OLED_all_on(void);
void OLED_test(void);


#endif /* OLED_H_ */