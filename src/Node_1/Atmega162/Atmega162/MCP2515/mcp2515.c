/*
 * mcp2515.c
 *
 * Created: 12.10.2022 13:55:25
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */

#include "mcp2515.h"
#include "../SPI/spi.h"

void mcp2515_reset(void){
	SPI_send(MCP_RESET);
};

uint8_t mcp2515_read (uint8_t address ){
	uint8_t result ;
	PORTB &= ~(1 << PB4); // Select CAN - controller
	SPI_send ( MCP_READ ); // Send read instruction
	SPI_send ( address ); // Send address
	result = SPI_read () ; // Read result
	PORTB |= (1 << PB4 ); // Deselect CAN - controller
	return result ;
}

void mcp2515_write(uint8_t address, uint8_t data){
	PORTB &= ~(1 << PB4); // Select CAN - controller
	SPI_send ( MCP_WRITE ); // Send write instruction
	SPI_send ( address ); // Send address
	SPI_send ( data ); // Send data
	PORTB |= (1 << PB4 ); // Deselect CAN - controller

}

void mcp2515_request_to_send(uint8_t buffer){
	PORTB &= ~(1 << PB4); // Select CAN - controller
	switch(buffer){
		case 0:
			SPI_send ( MCP_RTS_TX0 ); // Send Request to send Buffer 0
			break;
		case 1:
			SPI_send ( MCP_RTS_TX1 ); // Send Request to send Buffer 1
			break;
		case 2:
			SPI_send ( MCP_RTS_TX2 ); // Send Request to send Buffer 2
			break;
		default:
			SPI_send ( MCP_RTS_ALL ); // Send Request to send Buffer all
			break;
	}
	PORTB |= (1 << PB4 ); // Deselect CAN - controller

}

void mcp2515_bit_modify(uint8_t address, uint8_t data, uint8_t mask){
	PORTB &= ~(1 << PB4); // Select CAN - controller
	SPI_send ( MCP_BITMOD ); // Send write instruction
	SPI_send ( address ); // Send address
	SPI_send ( mask ); // Send mask
	SPI_send ( data ); // Send data
	PORTB |= (1 << PB4 ); // Deselect CAN - controller
}


uint8_t mcp2515_read_status(){
	PORTB &= ~(1 << PB4); // Select CAN - controller
	SPI_send( MCP_READ_STATUS ); // Send read status instruction
	uint8_t value = SPI_read();
	PORTB |= (1 << PB4 ); // Deselect CAN - controller
	return value;
}


uint8_t mcp2515_init (void){
	uint8_t value ;
	SPI_init() ; // Initialize SPI
	mcp2515_reset() ; // Send reset - command
	// Self - test
	value = mcp2515_read (MCP_CANSTAT);
	if (( value & MODE_MASK ) != MODE_CONFIG ) {
		printf (" MCP2515 is NOT in configuration mode after reset !\n");
		return 1;
	}
	// More initialization
	//125Kbit/s at 16Mhz
	mcp2515_write(MCP_CNF1,0x03); //SJW=1 (0+1), BRP Baud Rate Prescaler = 4 (3+1)
	mcp2515_write(MCP_CNF2,0xAC); //BTLMODE=1, SAM=0, PS1=6 (5+1), PRSEG=5 (4+1)
	mcp2515_write(MCP_CNF3,0x03); //PS2=4 (3+1)
	
	//mcp2515_write(MCP_CANCTRL,0b01000000); //Set to Loopback mode
	mcp2515_write(MCP_CANCTRL,0b00000000); //Set to Normal mode
	mcp2515_write(MCP_CANINTE,0b00000011); //Enable interrupts on RX buffers
	return 0;
}
