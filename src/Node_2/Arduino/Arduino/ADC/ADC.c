/*
 * ADC.c
 *
 * Created: 13.11.2022 16:51:13
 *  Author: deaguiar
 */ 

#include <sam.h>
#include "adc.h"

void adc_init(void)
{
	PMC -> PMC_PCER1 |= PMC_PCER1_PID37;
	ADC->ADC_CR = ADC_CR_SWRST;
	ADC->ADC_MR |= ADC_MR_FREERUN_ON;
	ADC->ADC_CHER |= ADC_CHER_CH7;
	ADC->ADC_CR |= ADC_CR_START;
	ADC->ADC_COR = 0;

}

uint16_t get_adc_value(void)
{	
	return ADC->ADC_CDR[7];
}