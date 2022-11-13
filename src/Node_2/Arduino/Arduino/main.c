/*
 * Arduino.c
 *
 * Created: 19.10.2022 14:33:10
 * Author : deaguiar
 */ 


#include "sam.h"
#include "uart_and_printf/uart.h"
#include "uart_and_printf/printf-stdarg.h"
#include "CAN/can_controller.h"
#include "PWM/pwm.h"
#include "ADC/adc.h"
#include "ADC/ir.h"

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
	WDT->WDT_MR = WDT_MR_WDDIS;
	configure_uart();
	/* 125kbit/s at 84MHz 
	BRP = 42 (41+1), SJW=1 (0+1) , PROPAG=5(4+1), PHASE1=6(5+1) PHASE2=4(3+1)
	*/
	can_init_def_tx_rx_mb(0x00290453);
	pwm_init();
	adc_init();
	dac_init();
	uint8_t goals = 0;
    uint8_t temp_count_blocked=0;
	uint8_t temp_count_non_blocked=0;
	uint16_t i=0;
	while (1) 
    {
		motor_pos();	
		//servo_pos();
		printf("Goals = %d \n\r", goals);
		
		if (check_ir() == 1){
			temp_count_blocked++;
		}
		
		if (temp_count_blocked > 1){
			if (check_ir() == 0){
				temp_count_non_blocked++;
			}
		}
		if (temp_count_non_blocked > 100) {
			temp_count_blocked=0;
			temp_count_non_blocked=0;
			goals++;
		}
		
    }
}
