/*
 * can.c
 *
 * Created: 12.10.2022 16:14:48
 *  Author: deaguiar
 */ 

#include "can.h"
#include "../MCP2515/mcp2515.h"

void can_init(void){
	mcp2515_init();
}

void can_message_send(can_message can_msg){
	//Setup
	mcp2515_write(TXB0SIDH,can_msg.id >> 3); //ID High
	mcp2515_write(TXB0SIDL,(can_msg.id & 0b00000111) << 5); //Id Low
	mcp2515_write(TXB0DLC,can_msg.data_length); //Data Length
	for(uint8_t reg=0; reg<can_msg.data_length; reg++){
			mcp2515_write(TXB0D0+reg,can_msg.data[reg]); //Data
	}
	//Request-to-send
	mcp2515_request_to_send(0); //Send buffer 	
}

can_message can_message_receive(void){
	//Wait for interrupt
	can_message can_msg;
	//Read status register
	 uint8_t int_flags = mcp2515_read (MCP_CANINTF); //We need it to know if it is RX0 or 1
	 if(int_flags & 0b00000001 == 1){	//RX0 Interrupt
		//Read message
		uint8_t high = mcp2515_read(RXB0SIDH); //ID High
		can_msg.id = (high << 3) | ((mcp2515_read(RXB0SIDL) >> 5) & 0b00000111) ; //ID high + low
		can_msg.data_length = mcp2515_read(RXB0DLC); //Data Length
		for(uint8_t reg=0; reg<can_msg.data_length; reg++){
			can_msg.data[reg] = mcp2515_read(RXB0D0+reg); //Data
		}
		//Filter and masks
			
		//Reset interrupt
		mcp2515_bit_modify(MCP_CANINTF, 0, 0b00000001);
		int_flags = mcp2515_read (MCP_CANINTF);
		return can_msg; 
	 }
}
