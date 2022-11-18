/*
 * ADC.c
 *
 * Created: 13.11.2022 16:51:13
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */
#include <sam.h>
#include "dac.h"

void dac_init(void)
{
	PMC -> PMC_PCER1 |= PMC_PCER1_PID38;
	DACC->DACC_CR = DACC_CR_SWRST;
	//Only DAC1 is connected to the logic level convertor
	DACC->DACC_CHER |= ADC_CHER_CH1;
	DACC->DACC_MR |= DACC_MR_USER_SEL_CHANNEL1;
}

void dac_convert(uint16_t dig_val)
{
	DACC -> DACC_CDR = dig_val;
}