/*
 * adc.h
 *
 * Created: 14/09/2022 12:17:39 pm
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdio.h>

void adc_init (void);
uint8_t adc_read(uint8_t channel); //volatile



#endif /* ADC_H_ */