/*
 * interrupts.h
 *
 * Created: 19.10.2022 13:26:13
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void INT_init(void);
ISR(INT0_vect);


#endif /* INTERRUPTS_H_ */