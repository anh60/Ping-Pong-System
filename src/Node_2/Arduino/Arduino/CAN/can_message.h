/*
 * can_message.h
 *
 * Created: 02.11.2022 16:17:34
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */


#ifndef CAN_MESSAGE_H_
#define CAN_MESSAGE_H_
#include "can_controller.h"

CAN_MESSAGE msg; 
/* Data[0] = Servo msg
 * Data[1] = Motor msg
 * Data[2] = Right touch button msg
 */

uint8_t get_servo_message(void);
uint8_t get_motor_message(void);
uint8_t get_touch_btn(void);


#endif /* CAN_MESSAGE_H_ */