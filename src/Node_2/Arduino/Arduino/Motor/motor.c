/*
 * motor.c
 *
 * Created: 13.11.2022 21:27:00
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */ 

#include <sam.h>
#include "motor.h"
#include "../DAC/dac.h"
#include "../CAN/can_message.h"


uint32_t MAP_motor(uint32_t au32_IN, uint32_t au32_INmin, uint32_t au32_INmax, uint32_t au32_OUTmin, uint32_t au32_OUTmax)
{
	return ((((au32_IN - au32_INmin)*(au32_OUTmax - au32_OUTmin))/(au32_INmax - au32_INmin)) + au32_OUTmin);
}

uint16_t motor_pos(void){
	//MJ1 EN to high PD9
	PIOD->PIO_SODR |= PIO_PER_P9;

	
	
	//Speed with MJEX A0	
	uint8_t pos = get_motor_message();
	uint16_t pos_mapped = 0;
	uint16_t value = 0;
	if(pos > 127){
		pos = (~pos+1); //Invert pos if negative, so value is 0-100
		pos_mapped = MAP_motor(pos, 0, 100, 0, 580);
		value = 580-pos_mapped;
		} 
	else {
		pos_mapped = MAP_motor(pos, 0, 100, 580, 1300);
				
		value = pos_mapped;
		
	}
	
	
	//Map position on 10 bits
	return value;
	//printf("POS %d\n\r",pos_mapped);
	//int16_t encoder = read_encoder();
	//int16_t error_pos = pos_mapped - encoder/2;
	//printf("Encoder %d\n\r",encoder);
	//printf("ERROR %d\n\r",error_pos);
	//dac_convert(error_pos);
}

int16_t read_encoder(void){
	/*
	1: Set !OE low, to sample and hold the encoder value
	2: Set SEL low to output high byte
	3: Wait approx. 20 microseconds for output to settle
	4: Read MJ2 to get high byte
	5: Set SEL high to output low byte
	6: Wait approx. 20 microseconds
	7: Read MJ2 to get low byte
	8: Set !OE to high
	*/
	
	//1-Set OE low on  PD0 (PIN25)
	PIOD->PIO_CODR |= PIO_PER_P0;
	
	//2-Set SEL low on  PD2 (PIN27)
	PIOD->PIO_CODR |= PIO_PER_P2;
	
	//3-WAIT 20us
	for(int i=0; i<1000000;i++);
	//4 - Read MJ2
	//Read DO high)
	int8_t encoder_high = 0;
	encoder_high = (PIOC->PIO_PDSR) >> 1;
	
	//5 - Set SEL high PD2 (PIN27)
	PIOD->PIO_SODR |= PIO_PER_P2;
	
	//6 -WAIT 20us
	for(int i=0; i<1000000;i++);
	//7 - Read DO low
	int8_t encoder_low = 0;
	encoder_low = (PIOC->PIO_PDSR) >> 1;
	
	//8-Set OE high on  PD0 (PIN25)
	PIOD->PIO_SODR |= PIO_PER_P0;
	
	int16_t encoder = (encoder_high<<8) + encoder_low;
	return encoder;
}

void init_encoder(void){
	PMC->PMC_PCER0 |= PMC_PCER0_PID13;
	PMC->PMC_PCER0 |= PMC_PCER0_PID14;
	//PD0 (PIN25) as output
	PIOD->PIO_PER  |= PIO_PER_P0;
	PIOD->PIO_OER  |= PIO_PER_P0;
	//RST PD1 (PIN26) as output
	PIOD->PIO_PER  |= PIO_PER_P1;
	PIOD->PIO_OER  |= PIO_PER_P1;
	//PD2 (PIN27) as output
	PIOD->PIO_PER  |= PIO_PER_P2;
	PIOD->PIO_OER  |= PIO_PER_P2;
		
	//PIN DO0 -PC1(PIN33) as input
	PIOC->PIO_PER  |= PIO_PER_P1;
	PIOC->PIO_ODR  |= PIO_PER_P1;
	//PIN DO1 -PC2(PIN34) as input
	PIOC->PIO_PER  |= PIO_PER_P2;
	PIOC->PIO_ODR  |= PIO_PER_P2;
	//PIN DO2 -PC3(PIN35) as input
	PIOC->PIO_PER  |= PIO_PER_P3;
	PIOC->PIO_ODR  |= PIO_PER_P3;
	//PIN DO3 -PC4(PIN36) as input
	PIOC->PIO_PER  |= PIO_PER_P4;
	PIOC->PIO_ODR  |= PIO_PER_P4;
	//PIN DO4 -PC5(PIN37) as input
	PIOC->PIO_PER  |= PIO_PER_P5;
	PIOC->PIO_ODR  |= PIO_PER_P5;
	//PIN DO5 -PC6(PIN38) as input
	PIOC->PIO_PER  |= PIO_PER_P6;
	PIOC->PIO_ODR  |= PIO_PER_P6;
	//PIN DO6 -PC7(PIN39) as input
	PIOC->PIO_PER  |= PIO_PER_P7;
	PIOC->PIO_ODR  |= PIO_PER_P7;
	//PIN DO7 -PC8(PIN40) as input
	PIOC->PIO_PER  |= PIO_PER_P8;
	PIOC->PIO_ODR  |= PIO_PER_P8;	
	
	//MJ1 EN to PD9
	PIOD->PIO_PER  |= PIO_PER_P9;
	PIOD->PIO_OER  |= PIO_PER_P9;
	PIOD->PIO_SODR |= PIO_PER_P9;
	
	//MJ1 DIR setup PD10
	PIOD->PIO_PER  |= PIO_PER_P10;
	PIOD->PIO_OER  |= PIO_PER_P10;
	PIOD->PIO_SODR |= PIO_PER_P10; //Move right
	
	
	//Move to the right
	for(uint16_t i=0 ; i < 200; i++){
		printf("Calibrating... \n\r");
		dac_convert(2000);
	}
	//Reseting counter
	PIOD->PIO_CODR |= PIO_PER_P1;
	for(uint8_t i=0 ; i < 100; i++);
	PIOD->PIO_SODR |= PIO_PER_P1;
	
	printf("END INTIALIZTION ...............\n\r");
}


void closed_loop(void){
	const int16_t threshold = 120;
	int16_t encoder = read_encoder();
	if(encoder < 0 ) return;
	
	
	int16_t error = motor_pos() - encoder;

	static int16_t prev_error = 0;
	static int16_t prev_integrator = 0;

		if( error <= 0){
			PIOD->PIO_SODR |= PIO_PER_P10; //Direction right
		}
		if( error >= 0){
			PIOD->PIO_CODR |= PIO_PER_P10; //Direction left
		}
		
	double kp = 0.65;
	double ki = 0.015;
	int16_t proportional = kp* error; 
	int16_t integrator = prev_integrator + (ki*(error + prev_error))/2 ;

	if(proportional < 0) proportional *= -1;
	if(integrator < 0) integrator *= 1;
	
	uint16_t output = proportional + integrator + 1250;
	//printf("Output: %d, P: %d, I: %d \n\r", output, proportional, integrator);
	if (error < threshold || error > -threshold) dac_convert(0);
	if (error > threshold || error < -threshold) dac_convert(output);
		
	prev_error = error;
	prev_integrator = integrator;
	
}