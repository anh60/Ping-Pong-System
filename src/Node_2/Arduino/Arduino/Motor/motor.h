/*
 * motor.h
 *
 * Created: 13.11.2022 21:38:37
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */

#ifndef MOTOR_H_
#define MOTOR_H_

void motor_init(void);
uint16_t motor_pos(void);
int16_t read_encoder(void);
void init_encoder(void);
void closed_loop(void);


#endif /* MOTOR_H_ */