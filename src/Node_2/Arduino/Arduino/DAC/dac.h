/*
 * adc.h
 *
 * Created: 13.11.2022 17:20:34
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */


#ifndef DAC_H_
#define DAC_H_


void dac_init(void);
void dac_convert(uint16_t dig_val);


#endif /* ADC_H_ */