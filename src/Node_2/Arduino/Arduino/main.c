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
#include "Game/game.h"
#include "Solenoid/solenoid.h"


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
	init_encoder();
	init_solenoid();
	uint8_t new_goals = 0;
	uint8_t goals = 0;
	while (1) 
    {
		activate_solenoid();	
		servo_pos();
		
		closed_loop();
		
		new_goals = count_goals(goals);
		if (new_goals != goals){
			printf("Goals = %d \n\r", goals);
			goals=new_goals;
		}
			
    }
}
