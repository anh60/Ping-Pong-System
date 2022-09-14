/*
 * xmem.h
 *
 * Created: 9/7/2022 11:32:24 AM
 *  Author:
 */ 


#ifndef XMEM_H_
#define XMEM_H_

#include <stdio.h>

void xmem_init(void);
void xmem_write(uint8_t data , uint16_t addr);
uint8_t xmem_read(uint16_t addr);



#endif /* XMEM_H_ */