/*
 * IR.c
 *
 * Created: 13.11.2022 16:46:27
 *  Author: deaguiar
 */ 
#include <sam.h>
#include "ir.h"
#define TH 1650 //ADC value

// Return 0 when not blocked
uint8_t check_ir(void)       
{
	if(get_adc_value() > TH) return 0; 
	return 1; 
}

