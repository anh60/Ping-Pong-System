/*
 * adc.h
 *
 * Created: 14/09/2022 12:17:39 pm
 *  Author: danie
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdio.h>

void adc_init (void);
uint8_t adc_read(uint8_t channel); //volatile
void adc_calibrate();
//pos_t pos_read(void);



#endif /* ADC_H_ */