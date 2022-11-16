/*
 * pwm.c
 *
 * Created: 02.11.2022 12:14:07
 *  Author: deaguiar
 */ 
#include <stdint.h>

#include "sam.h"
#include "pwm.h"
#include "../CAN/can_message.h"

#define MCK 84000000 //84 MHz
#define T_PERIOD 20 //20 ms

uint32_t MAP(uint32_t au32_IN, uint32_t au32_INmin, uint32_t au32_INmax, uint32_t au32_OUTmin, uint32_t au32_OUTmax)
{
	return ((((au32_IN - au32_INmin)*(au32_OUTmax - au32_OUTmin))/(au32_INmax - au32_INmin)) + au32_OUTmin);
}

void pwm_init()
{
	//D44 PWMH5 PC19 B

	// Disable the Parallel IO (PIO) so that the peripheral controller can use them
	PIOC->PIO_PDR |= PIO_PDR_P19;

	// Read current peripheral AB select register and set the(PWM is connected as peripheral B)
	PIOC->PIO_ABSR|= PIO_ABSR_P19;
	
	// Enable the peripheral PWM controller in Power Management Controller (PMC)
	PMC->PMC_PCER1 |= PMC_PCER1_PID36;
	// Enable the peripheral PWM controller in Power Management Controller (PMC)
	
	PWM->PWM_CH_NUM[5].PWM_CMR |= PWM_CMR_CPRE_MCK_DIV_32;
	PWM->PWM_CH_NUM[5].PWM_CPRD |=  T_PERIOD*MCK/(32*1000);  // 52500;
	PWM->PWM_ENA |= PWM_DIS_CHID5;
};

void servo_pos(void)
{
	//0-20ms where 0.9ms>duty_cycle>2.1ms and the middle is 1.5 ms
	//4.5% low end; 10.5% high end
	uint8_t pos = get_servo_message();
	int duty_cycle=0;
	int pos_mapped = 0;
	//If negative 0.9 - 1.5; else 1.5 - 2.1
	if(pos > 127){
		pos = (~pos+1); //Invert pos if negative  
		pos_mapped = MAP(pos, 0, 100, 90, 150); //times by 100
		
		duty_cycle = (150+90-pos_mapped)*10/T_PERIOD;
	} else {
		pos_mapped = MAP(pos, 0, 100, 150, 210); //times by 100
		duty_cycle = pos_mapped*10/T_PERIOD;
	}
	
	PWM->PWM_CH_NUM[5].PWM_CDTY = PWM->PWM_CH_NUM[5].PWM_CPRD*(1-((double)duty_cycle/(double)1000));
}