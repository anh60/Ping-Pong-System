/*
 * can_message.h
 *
 * Created: 02.11.2022 16:17:34
 *  Author: deaguiar
 */ 


#ifndef CAN_MESSAGE_H_
#define CAN_MESSAGE_H_
#include "can_controller.h"

CAN_MESSAGE msg; 
/* Data[0] = Servo msg
 * Data[1) = ....
 *
 */

uint8_t get_servo_message(void);




#endif /* CAN_MESSAGE_H_ */