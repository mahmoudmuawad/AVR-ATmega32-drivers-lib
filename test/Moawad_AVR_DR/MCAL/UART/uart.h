#ifndef UART_H
#define UART_H

#include "../GPIO/gpio.h"

#ifndef F_CPU
#define F_CPU 8000000ul
#endif

void UART_init(U16);
void UART_write(U8);
void UART_write_string(U8 *str);
U8 UART_read();

#endif