/*
 * can.c
 *
 * Created: 12.10.2022 16:14:48
 *  Author: deaguiar
 */ 

#include "can.h"

void can_message_send(can_message can_msg){
	mcp2515_write(TXB0SIDH,can_msg.id >> 3); //ID High
	//printf("HIGH %d ",can_msg.id >> 3);
	mcp2515_write(TXB0SIDL,(can_msg.id & 0b00000111) << 5); //Id Low
	//printf("LOW %d ",(can_msg.id & 0b00000111) << 5);
	mcp2515_write(TXB0DLC,can_msg.data_length); //Data Length
	for(uint8_t reg=0; reg<can_msg.data_length; reg++){
			mcp2515_write(TXB0D0+reg,can_msg.data[reg]); //Data
	}
	mcp2515_request_to_send(0); //Send buffer 	
}

can_message can_message_receive(void){
	can_message can_msg;

	uint8_t high = mcp2515_read(RXB0SIDH); //ID High
	can_msg.id = (high << 3) | ((mcp2515_read(RXB0SIDL) >> 5) & 0b00000111) ; //ID high + low
		
	can_msg.data_length = mcp2515_read(RXB0DLC); //Data Length
	
	for(uint8_t reg=0; reg<can_msg.data_length; reg++){
		can_msg.data[reg] = mcp2515_read(RXB0D0+reg); //Data
	}
	return can_msg;
}
