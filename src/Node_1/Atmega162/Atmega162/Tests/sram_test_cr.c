#include <stdlib.h>
#include <avr/io.h>

void SRAM_test(void)
{
	volatile char *ext_ram = (char *) 0x1800; // Start address for the SRAM
	uint16_t ext_ram_size = 0x800;
	uint16_t write_errors = 0;
	uint16_t write_success = 0;
	uint16_t retrieval_errors = 0;
	uint16_t retrieval_success = 0;
	printf("Starting SRAM test...\r\n");
	// rand() stores some internal state, so calling this function in a loop will
	// yield different seeds each time (unless srand() is called before this function)
	uint16_t seed = rand();
	// Write phase: Immediately check that the correct value was stored
	srand(seed);
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		ext_ram[i] = some_value;
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Write phase error: ext_ram[%4d] = %02X (should be %02X)\r\n", i, retreived_value, some_value);
			write_errors++;
		}
		else{
			//printf("SUCCESS ext_ram[%4d] = %02X (should be %02X)\r\n", i, retreived_value, some_value);
			write_success++;
		}
	}
	// Retrieval phase: Check that no values were changed during or after the write phase
	srand(seed);
	// reset the PRNG to the state it had before the write phase
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Retrieval phase error: ext_ram[%4d] = %02X (should be %02X)\r\n", i, retreived_value, some_value);
			retrieval_errors++;
		}
		else{
			retrieval_success++;
		}
	}
	printf("SRAM test completed \r\n");
	printf("WRITE: total: %4d, success: %4d, errors: %4d\r\n", write_errors+write_success, write_success, write_errors);
	printf("READ: total: %4d, success: %4d, errors: %4d\r\n", retrieval_errors+retrieval_success, retrieval_success, retrieval_errors);
}