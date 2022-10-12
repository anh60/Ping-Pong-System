/*
 * can.h
 *
 * Created: 12.10.2022 16:14:58
 *  Author: deaguiar
 */ 


#ifndef CAN_H_
#define CAN_H_

#define TXB0SIDH 0x31
#define TXB0SIDL 0x32
#define TXB0DLC  0x35
#define TXB0D0   0x36

#define RXB0SIDH 0x61
#define RXB0SIDL 0x62
#define RXB0DLC  0x65
#define RXB0D0   0x66

#include <stdio.h>

struct can_message {
	uint16_t id ;
	char data_length ;
	char data [8];
} typedef can_message;
void can_message_send(can_message can_msg);
can_message can_message_receive(void);


#endif /* CAN_H_ */