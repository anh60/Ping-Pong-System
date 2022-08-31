#include <stdio.h>
#include "system.h"
#include "sys/alt_timestamp.h"
#include "altera_avalon_pio_regs.h"

#define project5

#define NIOS_OSCDIVISOR_BASE 0x800100a0
#define UART_0_BASE 0x8001060				// Base address of the UART registers

#define baud 1000000						// Desired baud rate
#define clkfreq 50000000					// Desired Clock frequency

int *uart_ba = (int*)UART_0_BASE;			// Casting base address to integer

const int rxdataoffs = 0;
const int txdataoffs = 1;
const int statusoffs = 2;
const int ctrloffs = 3;
const int divisoroffs = 4;

#ifdef project1
int main(){
	// Printing the base address of the UART registers
	printf("Base address: 0x%08x %d\n", (int)uart_ba, (int)uart_ba);

	// Printing address and value of the RXDATA register
	printf("RXDATA address: 0x%08x %d\n", (int)(uart_ba + rxdataoffs), (int)(uart_ba + rxdataoffs));
	printf("value = %d\n", *(uart_ba + rxdataoffs));

	// Printing address and value of the TXDATA register
	printf("TXDATA address: 0x%08x %d\n", (int)(uart_ba + txdataoffs), (int)(uart_ba + txdataoffs));
	printf("value = %d\n", *(uart_ba + txdataoffs));

	// Printing address and value of the STATUS register
	printf("STATUS address: 0x%08x %d\n", (int)(uart_ba + statusoffs), (int)(uart_ba + statusoffs));
	printf("value = %d\n", *(uart_ba + statusoffs));

	// Printing address and value of the CONTROL register
	printf("CONTROL address: 0x%08x %d\n", (int)(uart_ba + ctrloffs), (int)(uart_ba + ctrloffs));
	printf("value = %d\n", *(uart_ba + ctrloffs));

	// Printing address and value of the DIVISOR register
	printf("DIVISOR address: 0x%08x %d\n", (int)(uart_ba + divisoroffs), (int)(uart_ba + divisoroffs));
	printf("value = %d\n", *(uart_ba + divisoroffs));

	return 0;
}
#endif

#ifdef project2
int main(){
	int divisor = (int)(clkfreq/baud)-1;
	printf("%d\n", divisor);
	*(uart_ba + divisoroffs) = divisor;
	return 0;
}
#endif

#ifdef project3
int main(){
	const int data1 = 49;
	const int data2 = 50;
	const int data3 = 51;

	const int clearStatusErrors = 224;
	*(uart_ba + statusoffs) = (*(uart_ba + statusoffs) & clearStatusErrors);

	int sv1 = *(uart_ba + statusoffs);
	int trdy1 = (sv1 & (1 << 6)) >> 6;

	*(uart_ba + txdataoffs) = data1;
	*(uart_ba + txdataoffs) = data2;
	*(uart_ba + txdataoffs) = data3;

	int sv2 = *(uart_ba + statusoffs);
	int trdy2 = (sv2 & (1 << 6)) >> 6;

	printf("%d %d\n", sv1, sv2);
	printf("%d %d\n", trdy1, trdy2);

	int sv3 = *(uart_ba + statusoffs);
	int trdy3 = (sv3 & (1 << 6)) >> 6;
	printf("%d\n", trdy3);
	return 0;
}
#endif

#ifdef project4
int main(){
	int divisor = (int)(clkfreq/baud)-1;
	printf("%d\n", divisor);
	*(uart_ba + divisoroffs) = divisor;

	int sv = 0;
	int trdy = 0;

	char string[] = "aasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int size = sizeof(string) / sizeof(string[0]);
	int counter = 0;

	while(counter < size){
		sv = *(uart_ba + statusoffs);
		trdy = (sv & (1 << 5)) >> 5;

		if(trdy){
			*(uart_ba + txdataoffs) = string[counter];
		    counter++;
		}
	}
	return 0;
}
#endif

#ifdef project5
int main(){
	*(uart_ba + ctrloffs) = 0;
	int rrdy = 0;
	int sv = 0;
	int sv1 = 0;
	int sv2 = 0;
	char rx;

	const int clearStatusErrors = 224;
	*(uart_ba + statusoffs) = (*(uart_ba + statusoffs) & clearStatusErrors);
	while(1){
		sv = *(uart_ba + statusoffs);
		//rrdy = (sv & (1 << 7)) >> 7;
		rrdy = 1;

		if(rrdy){
			sv1 = *(uart_ba + statusoffs);
			rx = *(uart_ba + rxdataoffs);
			sv2 = *(uart_ba + statusoffs);
			printf("%d %d %c\n", sv1, sv2, rx);
		}
	}
	return 0;
}
#endif
